/* leon2m FUN_a0095fb0 @ 0xa0095fb0-0xa00961a4 (125 words), flags -mcpu=v8 -O3 -g.
 * upd = 1 when byte DAT_a802d290+0x181 differs from byte 0xa8025c56 or byte 0xa8025c55 differs from bit 11 of word
 * +0xa8, unless bits 8..23 of word +0x180 are 0x0001 and bit 0xa8025c55 differs. Copies 0xa8025c55 to bit 11 of
 * word +0xa8, 0xa8025c54 to byte +0x11 and 0xa8025c56 to byte +0x181; m = FUN_a00b6b88(that byte, 0);
 * FUN_a00a93bc((word 0xa802afec - 0x5c) % 7); FUN_a00b6bec(m / 7) when (afec - 0x5c) / 7 differs from m / 7;
 * FUN_a00a9650(m % 7, 0), FUN_a00a813c(1, m % 7, 1); afec = 0x15; FUN_a00a900c(0, 1). When upd: FUN_a00db738()
 * if bit 11 is set, else FUN_a00dbcf0(). Ends with FUN_a00aacb4(2, 1) and FUN_a00acc40() (tail call).
 * Counterpart of FUN_a00a01fc. Source form: the (afec - 0x5c) / 7 test is written inline in the if, without a
 * variable.
 */
struct D290 {
    unsigned char p000[0x11];
    unsigned char b011;
    unsigned char p012[0xa8 - 0x12];
    union {
        unsigned int w;
        struct {
            unsigned int hi : 20;
            unsigned int b11 : 1;
            unsigned int lo : 11;
        } f;
    } w0a8;
    unsigned char p0ac[0x180 - 0xac];
    union { unsigned int w; unsigned char b[4]; } u180;
};
extern struct D290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a8025c54, DAT_a8025c55, DAT_a8025c56;
extern unsigned char FUN_a00b6b88(unsigned char, unsigned char);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00b6bec(unsigned char page);
extern void FUN_a00a813c(unsigned char, unsigned char, unsigned char);
extern void FUN_a00a9650(unsigned char, unsigned char);
extern void FUN_a00a900c(unsigned char, unsigned char);
extern void FUN_a00db738(void);
extern void FUN_a00dbcf0(void);
extern void FUN_a00aacb4(unsigned char, unsigned char);
extern void FUN_a00acc40(void);

void FUN_a0095fb0(void)
{
    unsigned char upd;
    unsigned char m;
    unsigned char k;

    if (DAT_a802d290.u180.b[1] != DAT_a8025c56 || DAT_a8025c55 != ((DAT_a802d290.w0a8.w >> 11) & 1)) {
        if ((DAT_a802d290.u180.w & 0xffff00) == 0x100 && DAT_a8025c55 != ((DAT_a802d290.w0a8.w >> 11) & 1))
            upd = 0;
        else
            upd = 1;
    } else
        upd = 0;
    DAT_a802d290.w0a8.f.b11 = DAT_a8025c55;
    DAT_a802d290.b011 = DAT_a8025c54;
    DAT_a802d290.u180.b[1] = DAT_a8025c56;
    m = FUN_a00b6b88(DAT_a8025c56, 0);
    FUN_a00a93bc((_DAT_a802afec - 0x5c) % 7);
    if ((_DAT_a802afec - 0x5c) / 7 != (unsigned char)(m / 7))
        FUN_a00b6bec(m / 7);
    FUN_a00a9650(m % 7, 0);
    FUN_a00a813c(1, m % 7, 1);
    _DAT_a802afec = 0x15;
    FUN_a00a900c(0, 1);
    if (upd) {
        if (!(DAT_a802d290.w0a8.w & 0x800))
            FUN_a00dbcf0();
        else
            FUN_a00db738();
    }
    FUN_a00aacb4(2, 1);
    FUN_a00acc40();
}
