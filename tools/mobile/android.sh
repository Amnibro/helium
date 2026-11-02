#!/usr/bin/env bash
set -euo pipefail
usage() { echo "usage: tools/mobile/android.sh MAIN.amni --name NAME --id com.example.app [--out DIR] [--assets DIR] [--abis arm64-v8a,x86_64] [--ver 1.0.0] [--code 1] [--release KEYSTORE.properties] [--portrait] [--c FILE.c]..."; exit 2; }
[ $# -ge 1 ] || usage
R=$(cd "$(dirname "$0")/../.." && pwd); MAIN=$(realpath "$1"); shift
NAME="" PKG="" OUT="$PWD/dist" ASSETS="" ABIS="arm64-v8a,x86_64" VER="1.0.0" CODE=1 PROPS="" ORIENT=sensorLandscape EXTRA=()
while [ $# -gt 0 ]; do case "$1" in --name) NAME=$2; shift 2;; --id) PKG=$2; shift 2;; --out) OUT=$(realpath -m "$2"); shift 2;; --assets) ASSETS=$(realpath "$2"); shift 2;; --abis) ABIS=$2; shift 2;; --ver) VER=$2; shift 2;; --code) CODE=$2; shift 2;; --release) PROPS=$(realpath "$2"); shift 2;; --portrait) ORIENT=sensorPortrait; shift;; --c) EXTRA+=("$(realpath "$2")"); shift 2;; *) usage;; esac; done
[ -n "$NAME" ] && [ -n "$PKG" ] || usage
HCN="${HCN:-$R/build/hcn}" SDK="${ANDROID_HOME:-$HOME/Android/Sdk}" NDK="${ANDROID_NDK:-$(ls -d "$SDK"/ndk/* | sort -V | tail -1)}" API="${API:-26}"
GFX="${GOOSE_GFX:-$HOME/.goose/pkg/github.com/aardappel/goose_gfx/v1}"
[ -x "$HCN" ] || { echo "no hc at $HCN (build it or set HCN)"; exit 1; }
W=$(mktemp -d); trap 'rm -rf "$W"' EXIT; P="$W/android"; mkdir -p "$OUT"
cp -r "$R/tools/mobile/android" "$P"; mkdir -p "$P/app/build/gen-java" "$P/app/build/gen-assets"; cp -r "$P/java/." "$P/app/build/gen-java/"
[ -z "$ASSETS" ] || { mkdir -p "$P/app/build/gen-assets/helium"; cp -r "$ASSETS/." "$P/app/build/gen-assets/helium/"; }
C="${XDG_CACHE_HOME:-$HOME/.cache}/helium-android/$PKG"; mkdir -p "$C/wrap"
(cd "$(dirname "$MAIN")" && HC_LIB="$R/hc/lib" "$HCN" "$(basename "$MAIN")" "$C/main.c" --static) || { echo "hc failed on $MAIN"; exit 1; }
cp "$R/hc/hrt.h" "$C/hrt.h"
SRCS="\"$C/main.c\" \"$R/tools/mobile/android/helium_android.c\""; for c in "${EXTRA[@]}"; do SRCS="$SRCS \"$c\""; done
cat > "$C/wrap/CMakeLists.txt" <<EOW
cmake_minimum_required(VERSION 3.20)
project(helium_app C CXX)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_subdirectory("$GFX" pkg EXCLUDE_FROM_ALL)
add_library(main SHARED $SRCS)
target_include_directories(main PRIVATE "$C")
target_compile_options(main PRIVATE -w -O3 -fwrapv -Dmain=SDL_main)
target_link_libraries(main PRIVATE SDL3::SDL3-static android log m dl)
EOW
IFS=, read -ra AL <<<"$ABIS"
for a in "${AL[@]}"; do
	B="$C/$a"; mkdir -p "$B" "$P/app/src/main/jniLibs/$a"
	cmake -S "$C/wrap" -B "$B" -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE="$NDK/build/cmake/android.toolchain.cmake" -DANDROID_ABI=$a -DANDROID_PLATFORM=android-$API -DANDROID_STL=c++_static >"$B/cmake.log" 2>&1 || { tail -30 "$B/cmake.log"; exit 1; }
	nice -n 10 cmake --build "$B" --target main >>"$B/cmake.log" 2>&1 || { tail -30 "$B/cmake.log"; exit 1; }
	cp "$B/libmain.so" "$P/app/src/main/jniLibs/$a/libmain.so"
	"$NDK/toolchains/llvm/prebuilt/linux-x86_64/bin/llvm-strip" "$P/app/src/main/jniLibs/$a/libmain.so"
done
echo "sdk.dir=$SDK" >"$P/local.properties"
TASK=assembleDebug; KIND=debug
if [ -n "$PROPS" ]; then TASK="assembleRelease bundleRelease"; KIND=release; printf '\nandroid { signingConfigs { create("rel") { val p = java.util.Properties().apply { file("%s").inputStream().use { load(it) } }; storeFile = file(p.getProperty("storeFile")); storePassword = p.getProperty("storePassword"); keyAlias = p.getProperty("keyAlias"); keyPassword = p.getProperty("keyPassword") } }; buildTypes { release { signingConfig = signingConfigs.getByName("rel"); isMinifyEnabled = false } } }\n' "$PROPS" >>"$P/app/build.gradle.kts"; fi
(cd "$P" && chmod +x gradlew && ./gradlew -q --no-daemon -Phe.pkg="$PKG" -Phe.name="$NAME" -Phe.sdl="$GFX/third_party/SDL/android-project/app/src/main/java" -Phe.abis="$ABIS" -Phe.ver="$VER" -Phe.code="$CODE" -Phe.orient="$ORIENT" $TASK)
SAFE=$(echo "$NAME" | tr -c 'A-Za-z0-9._-' '-' | sed 's/-*$//')
cp "$(find "$P/app/build/outputs/apk/$KIND" -name '*.apk' | head -1)" "$OUT/$SAFE-$VER.apk"
[ "$KIND" = debug ] || cp "$(find "$P/app/build/outputs/bundle/release" -name '*.aab' | head -1)" "$OUT/$SAFE-$VER.aab"
echo "$OUT/$SAFE-$VER.apk"
