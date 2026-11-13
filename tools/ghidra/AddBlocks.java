// Ghidra pre-script: add extra initialized memory blocks before analysis.
// Each arg is name:path:hexaddr, e.g. data:/x/leon2m_data.bin:0xA8024800
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.MemoryBlock;
import java.io.File;
import java.io.FileInputStream;

public class AddBlocks extends GhidraScript {
    @Override
    public void run() throws Exception {
        for (String spec : getScriptArgs()) {
            String[] p = spec.split(":", 3);
            File f = new File(p[1]);
            Address addr = currentProgram.getAddressFactory().getDefaultAddressSpace()
                               .getAddress(Long.parseLong(p[2].replace("0x", ""), 16));
            try (FileInputStream in = new FileInputStream(f)) {
                MemoryBlock b = currentProgram.getMemory()
                    .createInitializedBlock(p[0], addr, in, f.length(), monitor, false);
                b.setRead(true); b.setWrite(true); b.setExecute(false);
                println("added block " + p[0] + " at " + addr + " len " + f.length());
            }
        }
    }
}
