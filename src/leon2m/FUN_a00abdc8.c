/* leon2m FUN_a00abdc8 @ 0xa00abdc8 (-mcpu=v8 -O3 -g)
 * v = byte 0xA802D2A3 (0xA802D290 + 0x13) + 1. When v > 100 stores 100; otherwise stores v and calls
 * FUN_a00ab5f0(0x2c, 8, v, 7, 1), FUN_a0146a80(0x28, 8, 3, 0x742, 0), FUN_a0146a80(0x2b, 8, 1, 0x742, 0),
 * FUN_a0146a80(0x32, 8, 1, 0x742, 0), FUN_a0146b50(0xe8, 0), FUN_a00b6ec8(0x29, 8, byte 0xA802D2A3) and
 * FUN_a00d462c(). Sets bit 1 of byte 0xA802B08E. Same code as FUN_a00abb98 with other constants.
 * See FUN_a00abb98 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802b08e;
extern void FUN_a00ab5f0(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(int, int, int, int, int);
extern void FUN_a0146b50(int, int);
extern void FUN_a00b6ec8(unsigned char, unsigned char, unsigned char);
extern void FUN_a00d462c(void);

void FUN_a00abdc8(void)
{
    unsigned char v = DAT_a802d290[0x13] + 1;
    
    if (v > 100) {
        DAT_a802d290[0x13] = 100;
    } else {
        DAT_a802d290[0x13] = v;
        FUN_a00ab5f0(0x2c, 0x8, v, 7, 1);
        FUN_a0146a80(0x28, 0x8, 3, 0x742, 0);
        FUN_a0146a80(0x2b, 0x8, 1, 0x742, 0);
        FUN_a0146a80(0x32, 0x8, 1, 0x742, 0);
        FUN_a0146b50(0xe8, 0);
        FUN_a00b6ec8(0x29, 0x8, DAT_a802d290[0x13]);
        FUN_a00d462c();
    }
    
    DAT_a802b08e |= 2;
}
