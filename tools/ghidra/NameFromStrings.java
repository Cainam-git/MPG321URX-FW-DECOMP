// Post-script: propose a name and a comment for every function from the debug
// strings it references. Writes a JSON file (args[0]) that ImportSymbols.java
// can apply. Names found this way are marked "auto" so a human name wins later.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.data.StringDataInstance;
import com.google.gson.*;
import java.io.FileWriter;
import java.util.*;
import java.util.regex.*;

public class NameFromStrings extends GhidraScript {
    static final Pattern IDENT = Pattern.compile("[A-Za-z][A-Za-z0-9]*(?:_[A-Za-z0-9]+)+");
    static final Pattern TAG = Pattern.compile("\\[([A-Za-z0-9_]+)\\]");

    @Override
    public void run() throws Exception {
        Listing listing = currentProgram.getListing();
        ReferenceManager refs = currentProgram.getReferenceManager();
        JsonObject root = new JsonObject();
        JsonObject funcs = new JsonObject();
        Set<String> used = new HashSet<>();
        int named = 0;
        for (Function f : listing.getFunctions(true)) {
            List<String> strs = new ArrayList<>();
            for (Instruction ins : listing.getInstructions(f.getBody(), true)) {
                for (Reference r : refs.getReferencesFrom(ins.getAddress())) {
                    Data d = listing.getDataAt(r.getToAddress());
                    if (d == null) d = listing.getDataContaining(r.getToAddress());
                    if (d == null) continue;
                    StringDataInstance sdi = StringDataInstance.getStringDataInstance(d);
                    String s = sdi.getStringValue();
                    if (s == null || s.isEmpty()) continue;
                    s = s.replaceAll("\u001b\\[[0-9;]*m", "").trim();   // strip colour codes
                    if (!strs.contains(s)) strs.add(s);
                }
            }
            if (strs.isEmpty()) continue;
            // pick a name: longest underscore identifier, else a [TAG], else nothing
            String best = null;
            for (String s : strs) {
                Matcher m = IDENT.matcher(s);
                while (m.find()) {
                    String t = m.group();
                    if (t.matches("[A-Z0-9_]+") && t.length() < 6) continue; // skip shouty short tokens
                    if (best == null || t.length() > best.length()) best = t;
                }
            }
            if (best == null) {
                for (String s : strs) { Matcher m = TAG.matcher(s); if (m.find()) { best = m.group(1) + "_handler"; break; } }
            }
            JsonObject fo = new JsonObject();
            if (best != null) {
                String name = best;
                int k = 2;
                while (used.contains(name)) name = best + "_" + (k++);
                used.add(name);
                fo.addProperty("name", name);
                fo.addProperty("source", "auto");
                named++;
            }
            StringBuilder c = new StringBuilder("Strings used by this function:\n");
            for (int i = 0; i < Math.min(strs.size(), 8); i++) c.append("  \"").append(strs.get(i)).append("\"\n");
            if (strs.size() > 8) c.append("  ... ").append(strs.size() - 8).append(" more\n");
            fo.addProperty("comment", c.toString());
            funcs.add(f.getEntryPoint().toString(), fo);
        }
        root.add("functions", funcs);
        try (FileWriter w = new FileWriter(getScriptArgs()[0])) {
            new GsonBuilder().setPrettyPrinting().create().toJson(root, w);
        }
        println("NameFromStrings: " + named + " names proposed, " + funcs.size() + " functions commented -> " + getScriptArgs()[0]);
    }
}
