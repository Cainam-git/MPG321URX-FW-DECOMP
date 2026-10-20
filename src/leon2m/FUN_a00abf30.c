/* leon2m FUN_a00abf30 @ 0xa00abf30-0xa00abff8 (50 words), flags -mcpu=v8 -O3 -g.
 * Code facts: step-down twin of FUN_a00abff8: b = (u8)(byte DAT_a802d290[0x12] - 1); b > 100 (also the wrap from
 * 0) stores 0; else stores b and redraws: FUN_a00ab5f0(0x2c, 6, b, 7, 1), FUN_a0146a80(0x28/0x2b/0x32, 6, 3/1/1,
 * 0x742, 0), FUN_a0146b50(0xe6, 0), FUN_a00b6ec8(0x29, 6, DAT_a802d290[0x12]) (reloaded), FUN_a00d45f8(). Always
 * sets bit 1 of DAT_a802b08e. void, no params.
 * Source form: the record base DAT_a802d290[0x12]; the reset arm first ('if (b > 100) ... else {calls}', as in
 * FUN_a00abff8: with the calls arm first it ends in a jump that makes sched1 set o3/o4 before o2 of the 3rd
 * FUN_a0146a80 call); the prototypes (ab5f0 u8 x5, b6ec8 void u8 x3, a80 (u16, u16, u8, u16, u8), b50 (u16, u8)).
 * Compiler aids: none.
 */
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a802d290[];
extern void FUN_a00ab5f0(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern void FUN_a00b6ec8(unsigned char, unsigned char, unsigned char);
extern void FUN_a00d45f8(void);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b50(unsigned short, unsigned char);

void FUN_a00abf30(void)
{
    unsigned char b = DAT_a802d290[0x12] - 1;

    if (b > 100) {
        DAT_a802d290[0x12] = 0;
    } else {
        DAT_a802d290[0x12] = b;
        FUN_a00ab5f0(0x2c, 6, b, 7, 1);
        FUN_a0146a80(0x28, 6, 3, 0x742, 0);
        FUN_a0146a80(0x2b, 6, 1, 0x742, 0);
        FUN_a0146a80(0x32, 6, 1, 0x742, 0);
        FUN_a0146b50(0xe6, 0);
        FUN_a00b6ec8(0x29, 6, DAT_a802d290[0x12]);
        FUN_a00d45f8();
    }
    DAT_a802b08e |= 2;
}
