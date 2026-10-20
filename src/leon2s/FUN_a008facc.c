/* FUN_a008facc (leon2s, 0xa008facc-0xa008fb5c, 144 bytes, 36 words).
 * Flags: -mcpu=v8 -Os -g.
 * port = (u8)param_1; if bit 1 of FUN_a00a657c(port, 0x134) is set: m = low nibble of
 * FUN_a00a657c(port, 0x148) (u8), v = low nibble of FUN_a00a657c(port, 8); v |= 0x50 when m == 1,
 * v |= 0xf0 when m == 3; tail call FUN_a00a65c4(port, 8, (u8)v). Otherwise tail call
 * FUN_a00a67b8(port, 8, 0xf0, 0) (its four args are set before the branch).
 * FUN_a00a65c4 takes three arguments; m is unsigned char (the firmware re-extends it with
 * 'and %l0,0xff,%l0').
 */
extern unsigned int FUN_a00a657c(unsigned int, unsigned short);
extern void FUN_a00a65c4(unsigned int, int, unsigned int);
extern void FUN_a00a67b8(unsigned int, int, unsigned int, int);

void FUN_a008facc(unsigned int param_1)
{
    unsigned char uVar1;
    unsigned int value;
    unsigned char uVar2;
    
    param_1 &= 0xff;
    
    if (FUN_a00a657c(param_1, 0x134) & 2) {
        uVar1 = (unsigned char)(FUN_a00a657c(param_1, 0x148) & 0xf);
        uVar2 = FUN_a00a657c(param_1, 8) & 0xf;
        
        value = uVar2;
        if (uVar1 == 1) {
            value = uVar2 | 0x50;
        } else if (uVar1 == 3) {
            value = uVar2 | 0xfffffff0;
        }
        
        FUN_a00a65c4(param_1, 8, value & 0xff);
    } else {
        FUN_a00a67b8(param_1, 8, 0xf0, 0);
    }
}
