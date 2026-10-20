/* leon2s FUN_a00c6760 @ 0xa00c6760..0xa00c68f8 (408 bytes, 102 words)
 * Flags: -mcpu=v8 -Os -g.
 * Register-write sequence for unit addr = param_1 & 0xff through the external routines at 0xa0fb6c98
 * (addr, reg, mask, val) and 0xa0fb6c00 (addr, reg, val) (call targets outside the leon2s image; named
 * func_0x<address>). Common shape: 0x30 bit 0x80 set, 0x2a8 = (param_2 != 0), func_0xa0f9d800() & 0xff
 * <= 0x81 -> write 0x45d, 0x30 bit 0x80 cleared, 0x400 = 3, 0x402 bit 0x80 set, then 11 writes to 0x401.
 * param_2 != 0: 0x45d = 0, 0x403 = 0, the 11 bytes of _DAT_a8078610 to 0x401. param_2 == 0: 0x45d = 0xbf
 * only when param_3 != 0, and 11 zeros to 0x401.
 * Callers: no direct 'call 0xa00c6760' in asm/leon2s (reached via a pointer/table).
 * The firmware takes the 0x2a8 = 1 / table arm when param_2 != 0 (btst 0xff, %i1; be -> the other arm).
 * void.
 */
extern int func_0xa0f9d800();
extern void func_0xa0fb6c00();
extern void func_0xa0fb6c98();
extern unsigned char _DAT_a8078610[];

void FUN_a00c6760(unsigned int param_1, unsigned int param_2, unsigned char param_3)
{
    unsigned int addr = param_1 & 0xff;
    unsigned char i;
    unsigned char result;

    if ((param_2 & 0xff) != 0) {
        func_0xa0fb6c98(addr, 0x30, 0x80, 1);
        func_0xa0fb6c00(addr, 0x2a8, 1);
        result = func_0xa0f9d800() & 0xff;
        if (result <= 0x81) {
            func_0xa0fb6c00(addr, 0x45d, 0);
        }
        func_0xa0fb6c98(addr, 0x30, 0x80, 0);
        func_0xa0fb6c00(addr, 0x400, 3);
        func_0xa0fb6c98(addr, 0x402, 0x80, 1);
        func_0xa0fb6c00(addr, 0x403, 0);
        for (i = 0; i <= 10; i++) {
            func_0xa0fb6c00(addr, 0x401, _DAT_a8078610[i]);
        }
    } else {
        func_0xa0fb6c98(addr, 0x30, 0x80, 1);
        func_0xa0fb6c00(addr, 0x2a8, 0);
        result = func_0xa0f9d800() & 0xff;
        if (result <= 0x81) {
            if (param_3 != 0) {
                func_0xa0fb6c00(addr, 0x45d, 0xbf);
            }
        }
        func_0xa0fb6c98(addr, 0x30, 0x80, 0);
        func_0xa0fb6c00(addr, 0x400, 3);
        func_0xa0fb6c98(addr, 0x402, 0x80, 1);
        for (i = 0; i <= 10; i++) {
            func_0xa0fb6c00(addr, 0x401, 0);
        }
    }
    return;
}
