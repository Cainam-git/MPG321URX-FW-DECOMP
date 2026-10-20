/* leon2m FUN_a01215e8 @ 0xa01215e8-0xa01216f8 (68 words). -mcpu=v8 -O3 -g.
 * What it does (mode-table match FUN_a013f370 callee), for port (u8):
 *   RMW(port, 0x56, 1, 0) (FUN_a00f1b5c: clear bit 0 of reg 0x56);
 *   if (reg 4 & 3) != 3 and bit 6 of reg 0 is set: clear bit 6 of reg 0, then the delay func_0x4008d1a0(0x78);
 *   then the link test (the inlined body of FUN_a01211d4): reg 4 & 3 == 3 -> b = bit 2 of
 *   FUN_a00f1690(reg 3 & 1, 0x8f); else bit 5 of reg 3 set -> b = 0; else b = bit 2 of FUN_a00f1f9c(port, 0x11);
 *   last: RMW(port, 0, 4, b) (set or clear bit 2 of reg 0) as two tail calls.
 * (reg n = FUN_a00f1a90(port, n), the block register read.) Not rate-dependent.
 * Lever: b is an unsigned int flag (0 or 1) tested as 'if (b & 1)', which gives the fw
 * word test 'cmp %g1,0'; with a u8 b gcc emits 'btst 0xff' (1 word off) and a plain 'if (b)' on a
 * wider b lets jump threading skip the test. Same kind as the accepted 'return r & 1' flag lever: '& 1' is a
 * no-op on a 0/1 value. volatile: none. Aids: the '& 1' (see above).
 */
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);
extern unsigned char FUN_a00f1f9c(unsigned char a, unsigned char b);
extern unsigned char FUN_a00f1690(unsigned char a, unsigned char b);
extern void FUN_a00f1b5c(unsigned char, unsigned char, unsigned char, unsigned char);
extern void func_0x4008d1a0(unsigned int);

void FUN_a01215e8(unsigned char port)
{
    unsigned int x;
    unsigned int b;

    FUN_a00f1b5c(port, 0x56, 1, 0);
    if ((FUN_a00f1a90(port, 4) & 3) != 3) {
        if ((FUN_a00f1a90(port, 0) & 0x40) != 0) {
            FUN_a00f1b5c(port, 0, 0x40, 0);
            func_0x4008d1a0(0x78);
        }
    }
    if ((FUN_a00f1a90(port, 4) & 3) == 3) {
        x = FUN_a00f1690(FUN_a00f1a90(port, 3) & 1, 0x8f) & 4;
        b = x != 0;
    } else if (FUN_a00f1a90(port, 3) & 0x20) {
        b = 0;
    } else {
        x = FUN_a00f1f9c(port, 0x11) & 4;
        b = x != 0;
    }
    if (b & 1)
        FUN_a00f1b5c(port, 0, 4, 1);
    else
        FUN_a00f1b5c(port, 0, 4, 0);
}
