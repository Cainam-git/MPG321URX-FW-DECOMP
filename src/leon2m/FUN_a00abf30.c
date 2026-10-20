/* leon2m FUN_a00abf30 @ 0xa00abf30-0xa00abff8 (50 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/50 mismatches.
 * Code facts: step DOWN twin of FUN_a00abff8: b = (u8)(byte DAT_a802d290[0x12] - 1); b > 100
 * (also the wrap from 0) stores 0; else stores b and redraws: FUN_a00ab5f0(0x2c, 6, b, 7, 1),
 * FUN_a0146a80(0x28/0x2b/0x32, 6, 3/1/1, 0x742, 0), FUN_a0146b50(0xe6, 0),
 * FUN_a00b6ec8(0x29, 6, DAT_a802d290[0x12]) (reloaded), FUN_a00d45f8(). Always sets bit 1 of
 * DAT_a802b08e. void, no params.
 * Fixes vs the autoc draft (82.00): real base DAT_a802d290[0x12] (draft used a u16 at d2a2); the
 * reset arm FIRST ('if (b > 100) ... else {calls}', the abff8 lever: the calls-first arm ends
 * in a jump that makes sched1 set o3/o4 before o2 of the 3rd a80 call, 98.00); the
 * prototypes (ab5f0 u8 x5, b6ec8 void u8 x3, a80 (u16, u16, u8, u16, u8), b50 (u16, u8)).
 * Aids: none.
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
