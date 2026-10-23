/* leon2m FUN_a0095e54 @ 0xa0095e54-0xa0095fb0 (87 words).
 * Clears byte DAT_a802d290+0x178 when it is 1 and either byte +0x181 is 4..6 or bit 4 of word +0x11c is set.
 * m = FUN_a00b6b88(byte 0xa8025c56, 0) % 7: FUN_a00a93bc(m), FUN_a00a813c(1, m, 0); with k = (word 0xa802afec -
 * 0x5c) % 7: FUN_a00a9650(k, 0), FUN_a00a813c(1, k, 1); stores 0x15 to word 0xa802afec, FUN_a00a900c(0, 1),
 * sets bit 11 of word +0xa8, calls FUN_a00b6d58() and FUN_a00acc40() and sets bit 1 of byte 0xa802b08e.
 */
struct R290 {
    unsigned char pad0[0xa8];
    unsigned int wa8;
    unsigned char pad1[0x11c - 0xac];
    unsigned int w11c;
    unsigned char pad2[0x178 - 0x120];
    unsigned char b178;
    unsigned char pad3[0x181 - 0x179];
    unsigned char b181;
};
extern struct R290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern unsigned char FUN_a00b6b88(unsigned char, unsigned char);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00b6d58(void);
extern void FUN_a00acc40(void);

void FUN_a0095e54(void)
{
    unsigned char m;

    if (((unsigned char)(DAT_a802d290.b181 - 4) <= 2 || (DAT_a802d290.w11c & 0x10))
        && DAT_a802d290.b178 == 1)
        DAT_a802d290.b178 = 0;
    m = FUN_a00b6b88(DAT_a8025c56, 0) % 7;
    FUN_a00a93bc(m);
    FUN_a00a813c(1, m, 0);
    FUN_a00a9650((_DAT_a802afec - 0x5c) % 7, 0);
    FUN_a00a813c(1, (_DAT_a802afec - 0x5c) % 7, 1);
    _DAT_a802afec = 0x15;
    FUN_a00a900c(0, 1);
    DAT_a802d290.wa8 |= 0x800;
    FUN_a00b6d58();
    FUN_a00acc40();
    DAT_a802b08e |= 2;
}
