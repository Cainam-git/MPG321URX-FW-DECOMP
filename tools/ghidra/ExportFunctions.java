// Post-script: write the function table (name, start, end) to JSON (args[0]).
// dump_asm.py uses it to cut the objdump output into one file per function.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import com.google.gson.*;
import java.io.FileWriter;

public class ExportFunctions extends GhidraScript {
    @Override
    public void run() throws Exception {
        JsonArray arr = new JsonArray();
        for (Function f : currentProgram.getListing().getFunctions(true)) {
            AddressSetView body = f.getBody();
            JsonObject o = new JsonObject();
            o.addProperty("name", f.getName());
            o.addProperty("start", f.getEntryPoint().getOffset());
            o.addProperty("end", body.getMaxAddress().getOffset() + 1);
            o.addProperty("size", body.getNumAddresses());
            arr.add(o);
        }
        JsonObject root = new JsonObject(); root.add("functions", arr);
        try (FileWriter w = new FileWriter(getScriptArgs()[0])) { new GsonBuilder().create().toJson(root, w); }
        println("ExportFunctions: " + arr.size() + " -> " + getScriptArgs()[0]);
    }
}
