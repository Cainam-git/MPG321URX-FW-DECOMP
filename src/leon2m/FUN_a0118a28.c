/* leon2m FUN_a0118a28 @ 0xa0118a28 (-mcpu=v8 -O2 -g)
 * v = FUN_a00f2b48(p1 & 0xff, 0x10); p2 != 0 -> FUN_a00f2b8c(p1, 0x10, v | 1); else FUN_a00f2b8c(p1, 0x10, v & 0xfe)
 * (sets or clears bit 0 of register 0x10 of block p1; both arms tail calls).
 */
extern int FUN_a00f2b48();
extern int FUN_a00f2b8c();

void FUN_a0118a28(unsigned char param_1, unsigned char param_2)
{
    unsigned char uVar;
    
    param_1 &= 0xff;
    if (param_2 != 0) {
        uVar = FUN_a00f2b48(param_1, 0x10);
        FUN_a00f2b8c(param_1, 0x10, (uVar | 1) & 0xff);
    } else {
        uVar = FUN_a00f2b48(param_1, 0x10);
        FUN_a00f2b8c(param_1, 0x10, uVar & 0xfe);
    }
}
