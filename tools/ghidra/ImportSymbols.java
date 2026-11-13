// Post-script: apply names and comments from one or more JSON files to the
// program. Later files win, so pass <core>.auto.json first and <core>.json
// (hand-written) last. Missing files are skipped.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import com.google.gson.*;
import java.io.File;
import java.io.FileReader;
import java.util.Map;

public class ImportSymbols extends GhidraScript {
    @Override
    public void run() throws Exception {
        for (String path : getScriptArgs()) {
            File f = new File(path);
            if (!f.exists()) { println("skip (missing) " + path); continue; }
            JsonObject root = JsonParser.parseReader(new FileReader(f)).getAsJsonObject();
            JsonObject funcs = root.getAsJsonObject("functions");
            int n = 0;
            for (Map.Entry<String, JsonElement> e : funcs.entrySet()) {
                String a = e.getKey().replaceFirst("^[A-Za-z]+:", "");
                Address addr = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(a);
                if (addr == null) addr = currentProgram.getAddressFactory().getAddress(e.getKey());
                if (addr == null) continue;
                Function fn = getFunctionAt(addr);
                if (fn == null) { disassemble(addr); fn = createFunction(addr, null); }
                if (fn == null) continue;
                JsonObject o = e.getValue().getAsJsonObject();
                if (o.has("name")) {
                    try { fn.setName(o.get("name").getAsString(), SourceType.USER_DEFINED); n++; }
                    catch (Exception ex) { println("name clash " + o.get("name") + " at " + addr); }
                }
                if (o.has("comment")) {
                    String old = fn.getComment();
                    String c = o.get("comment").getAsString();
                    fn.setComment(old == null || old.contains(c) ? c : old + "\n" + c);
                }
            }
            println("ImportSymbols: applied " + n + " names from " + path);
        }
    }
}
