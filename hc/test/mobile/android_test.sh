#!/usr/bin/env bash
set -uo pipefail
R=$(cd "$(dirname "$0")/../../.." && pwd); SDK="${ANDROID_HOME:-$HOME/Android/Sdk}"; ADB="$SDK/platform-tools/adb"; PORT="${EMU_PORT:-5584}"; D="emulator-$PORT"; AVD="${AVD:-amni-test}"
W=$(mktemp -d); OUT="${MOBILE_OUT:-$W}"; PKG=org.amniscient.heliummobile
"$ADB" devices | grep -q "^$D" && { echo "M2: $D is already in use; set EMU_PORT"; exit 1; }
APK=$("$R/tools/mobile/android.sh" "$R/hc/apps/mobile/mobile.amni" --name "Helium Mobile" --id $PKG --abis x86_64 --out "$OUT" | tail -1) || { echo "M2: packaging failed"; exit 1; }
"$SDK/emulator/emulator" -avd "$AVD" -port "$PORT" -no-window -gpu host -cores 4 -memory 4096 -no-snapshot -no-boot-anim -no-audio >"$W/emu.log" 2>&1 &
EMU=$!
fin() { "$ADB" -s "$D" emu kill >/dev/null 2>&1; sleep 3; kill "$EMU" 2>/dev/null; wait "$EMU" 2>/dev/null; rm -rf "$W"; }
trap fin EXIT
timeout 180 "$ADB" -s "$D" wait-for-device || { echo "M2: emulator did not come up"; tail -5 "$W/emu.log"; exit 1; }
for i in $(seq 120); do [ "$("$ADB" -s "$D" shell getprop sys.boot_completed 2>/dev/null | tr -d '\r')" = 1 ] && break; sleep 2; done
"$ADB" -s "$D" install -r "$APK" >/dev/null || { echo "M2: install failed"; exit 1; }
"$ADB" -s "$D" logcat -c
"$ADB" -s "$D" shell am start -n $PKG/org.amniscient.helium.HeliumActivity >/dev/null
READY=""; for i in $(seq 60); do READY=$("$ADB" -s "$D" logcat -d -s helium:I | grep -o 'ready .*' | tail -1); [ -n "$READY" ] && break; sleep 1; done
[ -n "$READY" ] || { echo "M2: app never logged ready"; "$ADB" -s "$D" logcat -d | grep -iE "helium|SDL|FATAL|crash" | tail -20; exit 1; }
echo "M2 $READY"
sleep 3
read -r PX PY BX BY <<<"$(echo "$READY" | sed -E 's/.*panel ([0-9]+),([0-9]+) button ([0-9]+),([0-9]+).*/\1 \2 \3 \4/')"
"$ADB" -s "$D" exec-out screencap -p >"$W/shot.png"; cp "$W/shot.png" "${MOBILE_SHOT:-$W/keep.png}" 2>/dev/null
PIX=$(python3 -c "
import zlib,struct,sys
d=open(sys.argv[1],'rb').read(); i=8; w=h=0; idat=b''
while i<len(d):
    n=struct.unpack('>I',d[i:i+4])[0]; t=d[i+4:i+8]; c=d[i+8:i+8+n]; i+=12+n
    if t==b'IHDR': w,h,bd,ct=struct.unpack('>IIBB',c[:10])
    if t==b'IDAT': idat+=c
raw=zlib.decompress(idat); bpp=4 if ct==6 else 3; st=w*bpp; rows=[]; prev=bytearray(st); p=0
for y in range(h):
    f=raw[p]; p+=1; cur=bytearray(raw[p:p+st]); p+=st
    for x in range(st):
        a=cur[x-bpp] if x>=bpp else 0; b=prev[x]; cc=prev[x-bpp] if x>=bpp else 0
        if f==1: cur[x]=(cur[x]+a)&255
        elif f==2: cur[x]=(cur[x]+b)&255
        elif f==3: cur[x]=(cur[x]+(a+b)//2)&255
        elif f==4:
            pp=a+b-cc; pa=abs(pp-a); pb=abs(pp-b); pc=abs(pp-cc); cur[x]=(cur[x]+(a if pa<=pb and pa<=pc else b if pb<=pc else cc))&255
    rows.append(cur); prev=cur
x,y=int(sys.argv[2]),int(sys.argv[3]); print(w,h,*rows[y][x*bpp:x*bpp+3])
" "$W/shot.png" "$PX" "$PY")
echo "M2 screen and panel pixel: $PIX (want 26 140 153)"
read -r SWW SHH PR PG PB <<<"$PIX"
POK=$([ $(( (PR-26)*(PR-26) <= 9 && (PG-140)*(PG-140) <= 9 && (PB-153)*(PB-153) <= 9 )) = 1 ] && echo 1 || echo 0)
"$ADB" -s "$D" logcat -c
"$ADB" -s "$D" shell input tap "$BX" "$BY"
FD=0; TP=0; for i in $(seq 10); do L=$("$ADB" -s "$D" logcat -d -s helium:I); echo "$L" | grep -q "finger down" && FD=1; echo "$L" | grep -q "tapped play" && TP=1; [ $FD = 1 ] && [ $TP = 1 ] && break; sleep 0.5; done
echo "M2 tap: finger down $FD, tapped play $TP"
[ "$POK" = 1 ] && [ $FD = 1 ] && [ $TP = 1 ] && { echo "PASS M2 Android"; exit 0; }
echo "FAIL M2 Android"; exit 1
