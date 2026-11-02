package org.amniscient.helium;
import android.content.res.AssetManager;
import android.os.Bundle;
import android.system.Os;
import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import org.libsdl.app.SDLActivity;
public class HeliumActivity extends SDLActivity {
    private static void copy(InputStream in, File to) throws Exception { try (InputStream i = in; OutputStream out = new FileOutputStream(to)) { byte[] buf = new byte[65536]; int k; while ((k = i.read(buf)) > 0) out.write(buf, 0, k); } }
    private static void tree(AssetManager am, String from, File to) throws Exception { String[] l = am.list(from); if (l == null || l.length == 0) { copy(am.open(from), to); return; } to.mkdirs(); for (String n : l) tree(am, from.isEmpty() ? n : from + "/" + n, new File(to, n)); }
    @Override protected String[] getLibraries() { return new String[] { "main" }; }
    @Override protected void onCreate(Bundle b) {
        File root = new File(getFilesDir(), "assets");
        try {
            String v = String.valueOf(getPackageManager().getPackageInfo(getPackageName(), 0).getLongVersionCode());
            File stamp = new File(getFilesDir(), "assets.v");
            String[] top = getAssets().list("helium");
            if (top != null && top.length > 0 && (!stamp.isFile() || !v.equals(new String(java.nio.file.Files.readAllBytes(stamp.toPath()))))) { tree(getAssets(), "helium", root); java.nio.file.Files.write(stamp.toPath(), v.getBytes()); }
            root.mkdirs();
            Os.setenv("HELIUM_ASSETS", root.getAbsolutePath(), true);
            Os.setenv("HELIUM_DATA", getFilesDir().getAbsolutePath(), true);
        } catch (Exception e) { e.printStackTrace(); }
        super.onCreate(b);
    }
}
