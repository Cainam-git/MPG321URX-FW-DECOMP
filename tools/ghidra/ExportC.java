// Ghidra post-script: write the decompiled C of the whole program to args[0]
// and a disassembly listing to args[1].
import ghidra.app.script.GhidraScript;
import ghidra.app.util.exporter.CppExporter;
import ghidra.app.util.exporter.AsciiExporter;
import java.io.File;

public class ExportC extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        CppExporter c = new CppExporter();
        c.export(new File(a[0]), currentProgram, null, monitor);
        println("wrote " + a[0]);
        if (a.length > 1) {
            AsciiExporter asc = new AsciiExporter();
            asc.export(new File(a[1]), currentProgram, null, monitor);
            println("wrote " + a[1]);
        }
    }
}
