// Post-script: split functions where Ghidra glued a second routine onto the end
// (symbols/<core>.splits.json: {"<func start>": "<split address>"}, written by tools/splits.py).
// The first function keeps [start, split); a new function is created at the split address.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import com.google.gson.*;
import java.io.*;
import java.util.*;

public class SplitFunctions extends GhidraScript {
    @Override
    public void run() throws Exception {
        for (String path : getScriptArgs()) {
            File f = new File(path);
            if (!f.exists()) { println("skip (missing) " + path); continue; }
            JsonObject sp = JsonParser.parseReader(new FileReader(f)).getAsJsonObject();
            AddressSpace as = currentProgram.getAddressFactory().getDefaultAddressSpace();
            int n = 0, bad = 0;
            for (Map.Entry<String, JsonElement> e : sp.entrySet()) {
                Address start = as.getAddress(e.getKey()), split = as.getAddress(e.getValue().getAsString());
                Function fn = getFunctionAt(start);
                if (fn == null || fn.getBody().getMaxAddress().compareTo(split) < 0) { bad++; continue; }   // nothing beyond the split
                Address end = fn.getBody().getMaxAddress();
                try {
                    fn.setBody(new AddressSet(start, split.subtract(1)));
                    Function nf = getFunctionAt(split);
                    if (nf == null) nf = createFunction(split, null);
                    if (nf == null) { fn.setBody(new AddressSet(start, end)); bad++; continue; }
                    n++;
                } catch (Exception ex) { println("split failed at " + split + ": " + ex.getMessage()); bad++; }
            }
            println("SplitFunctions: " + n + " split, " + bad + " skipped from " + path);
        }
    }
}
