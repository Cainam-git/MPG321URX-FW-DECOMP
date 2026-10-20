// Ghidra pre-script (8051 banks): keep the "Non-Returning Functions - Discovered" analyzer off.
// It flags three routines (among them the Keil library routine ?C?LSTXDATA, which
// returns) as never returning, so 185 functions get cut off right after calling them and their
// tails are left as undefined bytes. With the analyzer off the tails are disassembled normally.
import ghidra.app.script.GhidraScript;
public class Returning extends GhidraScript {
    @Override
    public void run() throws Exception {
        setAnalysisOption(currentProgram, "Non-Returning Functions - Discovered", "false");
        println("Returning: non-returning discovery disabled");
    }
}
