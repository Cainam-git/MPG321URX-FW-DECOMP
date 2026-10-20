// Post-script: dump every non-default function name and its comment to JSON
// (args[0]) so hand work done inside the Ghidra GUI can be committed.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import com.google.gson.*;
import java.io.FileWriter;

public class ExportSymbols extends GhidraScript {
    @Override
    public void run() throws Exception {
        JsonObject root = new JsonObject(), funcs = new JsonObject();
        for (Function f : currentProgram.getListing().getFunctions(true)) {
            boolean named = f.getSymbol().getSource() != SourceType.DEFAULT;
            String c = f.getComment();
            if (!named && c == null) continue;
            JsonObject o = new JsonObject();
            if (named) o.addProperty("name", f.getName());
            if (c != null) o.addProperty("comment", c);
            funcs.add(f.getEntryPoint().toString(), o);
        }
        root.add("functions", funcs);
        try (FileWriter w = new FileWriter(getScriptArgs()[0])) {
            new GsonBuilder().setPrettyPrinting().create().toJson(root, w);
        }
        println("ExportSymbols: " + funcs.size() + " functions -> " + getScriptArgs()[0]);
    }
}
