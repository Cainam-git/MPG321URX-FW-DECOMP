/* leon2m FUN_a00a27a4 @ 0xa00a27a4  MATCH (-mcpu=v8 -O2 -g)
 * Copies DAT_a8025c55 to byte 0x1ED of the mode record DAT_a802d290 and sets DAT_a8025c56 = 2, then runs a fixed
 * call sequence: FUN_a00a93bc(0), FUN_a00a8c88(), _DAT_a802afec = 0xc2, FUN_a00ac718(0x3a),
 * FUN_a00a9650(DAT_a8025c56, 1), record byte 0x189 = 0xff, FUN_a00ab4bc(), FUN_a00a9468(1, 2), FUN_a00a9468(2, 5),
 * FUN_a00a9468(0, 0), FUN_a00b344c(7), FUN_a00b34d4(0, 1), FUN_a00dab90(). Finally sets bit 1 of DAT_a802b08e. The
 * 0xff store is written before the FUN_a00ab4bc call; the compiler places it in that call's delay slot.
 */
extern unsigned char DAT_a8025c55;   // 0xa8025c55
extern unsigned char DAT_a8025c56;   // 0xa8025c56
extern unsigned int _DAT_a802afec;   // 0xa802afec
extern unsigned char DAT_a802b08e;   // 0xa802b08e
extern unsigned char DAT_a802d290[]; // base 0xa802d290

extern void FUN_a00a93bc(unsigned int); // 0xa00a93bc
extern void FUN_a00a8c88(void); // 0xa00a8c88
extern void FUN_a00ac718(unsigned int); // 0xa00ac718
extern void FUN_a00a9650(unsigned int, unsigned int); // 0xa00a9650
extern void FUN_a00ab4bc(void); // 0xa00ab4bc
extern void FUN_a00a9468(unsigned int, unsigned int); // 0xa00a9468
extern void FUN_a00b344c(unsigned int); // 0xa00b344c
extern void FUN_a00b34d4(unsigned int, unsigned int); // 0xa00b34d4
extern void FUN_a00dab90(void); // 0xa00dab90

void FUN_a00a27a4(void)
{
    DAT_a802d290[0x1ed] = DAT_a8025c55;
    DAT_a8025c56 = 2;
    FUN_a00a93bc(0);
    FUN_a00a8c88();
    _DAT_a802afec = 0xc2;
    FUN_a00ac718(0x3a);
    FUN_a00a9650(DAT_a8025c56, 1);
    DAT_a802d290[0x189] = 0xff;
    FUN_a00ab4bc();
    FUN_a00a9468(1, 2);
    FUN_a00a9468(2, 5);
    FUN_a00a9468(0, 0);
    FUN_a00b344c(7);
    FUN_a00b34d4(0, 1);
    FUN_a00dab90();
    DAT_a802b08e = DAT_a802b08e | 2;
}
