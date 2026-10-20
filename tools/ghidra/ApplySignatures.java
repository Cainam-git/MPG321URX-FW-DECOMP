// Post-script: apply exact signatures of matched functions (symbols/<core>.sigs.json, written by
// tools/sigs.py) so the decompiler's C for their callers improves: right argument counts,
// call results kept or dropped correctly.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.symbol.SourceType;
import com.google.gson.*;
import java.io.*;
import java.util.*;

public class ApplySignatures extends GhidraScript {
    DataType type(String t) {
        t = t.trim();
        if (t.endsWith("*")) return new PointerDataType(type(t.substring(0, t.length() - 1)));
        t = t.replace("volatile ", "").replace("const ", "").trim();
        switch (t) {
            case "void": return VoidDataType.dataType;
            case "int": case "long": case "signed int": return IntegerDataType.dataType;
            case "unsigned int": case "uint": case "undefined4": case "dword": case "ulong": case "unsigned long": case "code": return UnsignedIntegerDataType.dataType;
            case "unsigned char": case "uchar": case "byte": case "undefined1": case "undefined": case "bool": return ByteDataType.dataType;
            case "char": return CharDataType.dataType;
            case "signed char": case "sbyte": return SignedByteDataType.dataType;
            case "unsigned short": case "ushort": case "undefined2": case "word": return UnsignedShortDataType.dataType;
            case "short": return ShortDataType.dataType;
            case "undefined8": case "ulonglong": case "unsigned long long": return UnsignedLongLongDataType.dataType;
            case "longlong": case "long long": return LongLongDataType.dataType;
            default: return null;
        }
    }
    @Override
    public void run() throws Exception {
        for (String path : getScriptArgs()) {
            File f = new File(path);
            if (!f.exists()) { println("skip (missing) " + path); continue; }
            JsonObject sigs = JsonParser.parseReader(new FileReader(f)).getAsJsonObject().getAsJsonObject("signatures");
            int n = 0, bad = 0;
            for (Map.Entry<String, JsonElement> e : sigs.entrySet()) {
                Address addr = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(e.getKey().replaceFirst("^[A-Za-z]+:", ""));
                Function fn = addr == null ? null : getFunctionAt(addr);
                if (fn == null) { bad++; continue; }
                JsonObject s = e.getValue().getAsJsonObject();
                DataType rt = type(s.get("return").getAsString());
                List<Variable> ps = new ArrayList<>();
                boolean ok = rt != null;
                for (JsonElement pe : s.getAsJsonArray("params")) {
                    JsonObject p = pe.getAsJsonObject();
                    DataType dt = type(p.get("type").getAsString());
                    if (dt == null) { ok = false; break; }
                    ps.add(new ParameterImpl(p.get("name").getAsString(), dt, currentProgram));
                }
                if (!ok) { bad++; continue; }
                try {
                    fn.updateFunction(null, new ReturnParameterImpl(rt, currentProgram), ps,
                                      FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
                    fn.setVarArgs(s.get("varargs").getAsBoolean());
                    n++;
                } catch (Exception ex) { bad++; }
            }
            println("ApplySignatures: " + n + " applied, " + bad + " skipped from " + path);
        }
    }
}
