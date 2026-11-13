// Post-script: undo wrong splits. JSON {"<func start>": "<end (exclusive)>"}: removes any function
// starting inside (start, end) and gives the function at start the body [start, end).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import com.google.gson.*;
import java.io.*;
import java.util.*;

public class MergeFunctions extends GhidraScript {
    @Override
    public void run() throws Exception {
        JsonObject m = JsonParser.parseReader(new FileReader(getScriptArgs()[0])).getAsJsonObject();
        AddressSpace as = currentProgram.getAddressFactory().getDefaultAddressSpace();
        int n = 0;
        for (Map.Entry<String, JsonElement> e : m.entrySet()) {
            Address start = as.getAddress(e.getKey()), end = as.getAddress(e.getValue().getAsString()).subtract(1);
            Iterator<Function> it = currentProgram.getFunctionManager().getFunctionsOverlapping(new AddressSet(start.add(1), end));
            List<Function> drop = new ArrayList<>();
            while (it.hasNext()) { Function f = it.next(); if (!f.getEntryPoint().equals(start)) drop.add(f); }
            for (Function f : drop) removeFunction(f);
            Function fn = getFunctionAt(start);
            if (fn != null) { fn.setBody(new AddressSet(start, end)); n++; }
        }
        println("MergeFunctions: " + n + " restored");
    }
}
