// Ghidra pre-script: seed entry points for raw binaries.
//   8051      -> reset vector 0x0000 and every interrupt vector 0x0003+8n that holds LJMP/RETI
//   sparc     -> 256-entry trap table at the image base, plus every aligned
//                "save %sp,-N,%sp" (0x9DE3BFxx) prologue found in memory
// Analysis then follows calls/jumps from those seeds.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.disassemble.Disassembler;
import ghidra.program.model.listing.Function;

public class Seed extends GhidraScript {
    int seeded = 0;
    void seed(Address a) {
        if (!currentProgram.getMemory().contains(a)) return;
        if (getFunctionAt(a) != null) return;
        disassemble(a);
        if (createFunction(a, null) != null) seeded++;
    }
    @Override
    public void run() throws Exception {
        String proc = currentProgram.getLanguage().getProcessor().toString().toLowerCase();
        for (MemoryBlock blk : currentProgram.getMemory().getBlocks()) {
            if (!blk.isInitialized()) continue;
            Address base = blk.getStart();
            long len = blk.getSize();
            if (proc.contains("8051")) {
                if (!blk.getName().toLowerCase().contains("code") && !base.getAddressSpace().getName().equals("CODE")) continue;
                seed(base);
                for (int n = 0; n < 16; n++) {
                    Address v = base.add(3 + 8 * n);
                    int b = blk.getByte(v) & 0xff;
                    if (b == 0x02 || b == 0x32) seed(v);
                }
                // Keil-style banked code: jump tables stop flow analysis, so also seed
                // every in-range LCALL (0x12 hi lo) target whose first byte is not 0xFF.
                byte[] buf = new byte[(int) len];
                blk.getBytes(base, buf);
                for (int i = 0; i + 3 <= buf.length; i++) {
                    if ((buf[i] & 0xff) != 0x12) continue;
                    int t = ((buf[i+1] & 0xff) << 8) | (buf[i+2] & 0xff);
                    if (t < buf.length && (buf[t] & 0xff) != 0xff) seed(base.add(t));
                }
            } else if (proc.contains("sparc")) {
                if (!blk.isExecute() && !blk.getName().contains("ram")) continue;
                for (int i = 0; i < 256; i++) seed(base.add(16L * i));   // trap table
                byte[] buf = new byte[(int) len];
                blk.getBytes(base, buf);
                for (int i = 0; i + 4 <= buf.length; i += 4) {
                    if ((buf[i] & 0xff) == 0x9d && (buf[i+1] & 0xff) == 0xe3 && (buf[i+2] & 0xff) == 0xbf) {
                        seed(base.add(i));
                    }
                }
            }
        }
        println("seeded " + seeded + " functions");
    }
}
