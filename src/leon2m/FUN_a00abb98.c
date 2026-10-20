/* leon2m FUN_a00abb98 @ 0xa00abb98-0xa00abc64 (51 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0 mismatches.
 * Code facts: v = byte 0xa802d290[0x14] + 1 (u8); v > 100 -> byte = 100; else byte = v,
 * FUN_a00ab5f0(0x2c, 0xa, v, 7, 1), FUN_a0146a80(0x28/0x2b/0x32, 0xa, 3/1/1, 0x742, 0),
 * FUN_a0146b50(0xea, 0), FUN_a00b6ec8(0x29, 0xa, byte re-read), FUN_a00d972c(). Always: flag byte
 * 0xa802b08e |= 2. Clamp arm first, as in its twins FUN_a00abff8 / FUN_a00abd00.
 * Required forms: real callee prototypes: FUN_a00b6ec8 is void (u8 x3)
 * (int return reorders %o0/%o1 around the call); FUN_a00ab5f0 (u8 x5). Aids: none.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802b08e;
extern void FUN_a00ab5f0(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(int, int, int, int, int);
extern void FUN_a0146b50(int, int);
extern void FUN_a00b6ec8(unsigned char, unsigned char, unsigned char);
extern void FUN_a00d972c(void);

void FUN_a00abb98(void)
{
    unsigned char v = DAT_a802d290[0x14] + 1;
    
    if (v > 100) {
        DAT_a802d290[0x14] = 100;
    } else {
        DAT_a802d290[0x14] = v;
        FUN_a00ab5f0(0x2c, 0xa, v, 7, 1);
        FUN_a0146a80(0x28, 0xa, 3, 0x742, 0);
        FUN_a0146a80(0x2b, 0xa, 1, 0x742, 0);
        FUN_a0146a80(0x32, 0xa, 1, 0x742, 0);
        FUN_a0146b50(0xea, 0);
        FUN_a00b6ec8(0x29, 0xa, DAT_a802d290[0x14]);
        FUN_a00d972c();
    }
    
    DAT_a802b08e |= 2;
}
