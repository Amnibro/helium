plugins { id("com.android.application") }
val pkg = providers.gradleProperty("he.pkg").get()
val sdlJava = providers.gradleProperty("he.sdl").get()
android {
    namespace = pkg
    compileSdk = 36
    defaultConfig {
        applicationId = pkg
        minSdk = 26
        targetSdk = 36
        versionCode = (providers.gradleProperty("he.code").orNull ?: "1").toInt()
        versionName = providers.gradleProperty("he.ver").orNull ?: "dev"
        ndk { abiFilters += (providers.gradleProperty("he.abis").orNull ?: "arm64-v8a").split(",") }
        manifestPlaceholders["label"] = providers.gradleProperty("he.name").get()
        manifestPlaceholders["orient"] = providers.gradleProperty("he.orient").orNull ?: "sensorLandscape"
    }
    sourceSets { getByName("main") { java.srcDir(sdlJava); java.srcDir("build/gen-java"); assets.srcDir("build/gen-assets") } }
    packaging { jniLibs { useLegacyPackaging = true } }
    compileOptions { sourceCompatibility = JavaVersion.VERSION_17; targetCompatibility = JavaVersion.VERSION_17 }
}
