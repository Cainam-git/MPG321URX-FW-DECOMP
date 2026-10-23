/* leon2m FUN_a00939b0 @ 0xa00939b0-0xa0093b04 (85 words).
 * FUN_a00a93bc(byte 0xa8025c56 + 1); sets bit 14 of halfword 0xa802cff4; FUN_a0146c40(0, 0, 0); word
 * 0xa802afec = byte DAT_a802d290+0x1a3 + 0x58; FUN_a00a813c(1, byte 0xa8025c56 + 1, 0); byte 0xa802afea and byte
 * +0x1a0 = afec - 0x57; FUN_a00a813c(1, afec - 0x56, 1). When i = byte +0x1a0 is non-zero: byte +0x1a1 =
 * t198[i - 1] and +0x1a2 = t19c[i - 1] (both loads before both stores). Then FUN_a00ac388(1),
 * FUN_a00a9650(afec - 0x56, 0), FUN_a00a813c(1, i + 1, 1), afec = 0x12, FUN_a00a900c(4, 1),
 * FUN_a00a9468(2, 5), (0, 0), (1, 2), FUN_a00b344c(7), FUN_a00b34d4(0, 1), DAT_a802b08e |= 2 and clears
 * byte +0x1a3.
 * Source form: byte +0x1a0 is assigned first and then copied to 0xa802afea (the other order gives other
 * registers in the |= sequences).
 */
struct R290 {
    unsigned char pad[0x198];
    unsigned char t198[4];
    unsigned char t19c[4];
    unsigned char b1a0, b1a1, b1a2, b1a3;
};
extern struct R290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802afea;
extern unsigned short DAT_a802cff4;
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00ac388(int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9468(int, int);
extern void FUN_a00b344c(int);
extern void FUN_a00b34d4(int, int);

void FUN_a00939b0(void)
{
    FUN_a00a93bc(DAT_a8025c56 + 1);
    DAT_a802cff4 |= 0x4000;
    FUN_a0146c40(0, 0, 0);
    _DAT_a802afec = DAT_a802d290.b1a3 + 0x58;
    FUN_a00a813c(1, DAT_a8025c56 + 1, 0);
    DAT_a802d290.b1a0 = _DAT_a802afec - 0x57;
    DAT_a802afea = DAT_a802d290.b1a0;
    FUN_a00a813c(1, _DAT_a802afec - 0x56, 1);
    if (DAT_a802d290.b1a0 != 0) {
        DAT_a802d290.b1a1 = DAT_a802d290.t198[DAT_a802d290.b1a0 - 1];
        DAT_a802d290.b1a2 = DAT_a802d290.t19c[DAT_a802d290.b1a0 - 1];
    }
    FUN_a00ac388(1);
    FUN_a00a9650(_DAT_a802afec - 0x56, 0);
    FUN_a00a813c(1, DAT_a802d290.b1a0 + 1, 1);
    _DAT_a802afec = 0x12;
    FUN_a00a900c(4, 1);
    FUN_a00a9468(2, 5);
    FUN_a00a9468(0, 0);
    FUN_a00a9468(1, 2);
    FUN_a00b344c(7);
    FUN_a00b34d4(0, 1);
    DAT_a802b08e |= 2;
    DAT_a802d290.b1a3 = 0;
}
