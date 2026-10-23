/* leon2m FUN_a00951a8 @ 0xa00951a8-0xa009530c (89 words).
 * With v = FUN_a014459c(word 0xa802afec + 0x2c) and DAT_a802d290 bytes +0x1e, +0x20, +0x1a3, +0x1a4:
 * when byte +0x1a3 is 0 and +0x1e differs from v: +0x1e = v and FUN_a00b8804(). Otherwise (byte +0x1a3 0 and
 * +0x1e equal to v: k = 3, afec value 0x82; byte +0x1a3 non-zero: +0x20 = v, FUN_a00d5938(1) when +0x20 changed,
 * k = 4, afec value 0x83): byte 0xa802b08f = 0x10, FUN_a00a8c88(), FUN_a00a9abc(), FUN_a00a9650(byte 0xa8025c54,
 * 2), FUN_a00a813c(1, byte 0xa8025c54, 1), FUN_a00a9650(k, 3), afec = the afec value, byte 0xa8025c55 = +0x1a4.
 * Always ends by clearing byte +0x1a3 and setting bit 1 of DAT_a802b08e.
 * Source form: the clear of +0x1a3 comes before the |= in the source (the build schedules the |= first).
 */
struct R290 {
    unsigned char pad0[0x1e];
    unsigned char b1e;
    unsigned char pad1f;
    unsigned char b20;
    unsigned char pad21[0x1a3 - 0x21];
    unsigned char b1a3;
    unsigned char b1a4;
};
extern struct R290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a8025c54;
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a802b08f;
extern unsigned char FUN_a014459c(unsigned char);
extern void FUN_a00b8804(void);
extern void FUN_a00d5938(unsigned char);
extern void FUN_a00a8c88(void);
extern void FUN_a00a9abc(void);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a813c(int, unsigned char, int);

void FUN_a00951a8(void)
{
    unsigned char old = DAT_a802d290.b20;

    if (DAT_a802d290.b1a3 == 0) {
        if (DAT_a802d290.b1e != FUN_a014459c(_DAT_a802afec + 0x2c)) {
            DAT_a802d290.b1e = FUN_a014459c(_DAT_a802afec + 0x2c);
            FUN_a00b8804();
        } else {
            DAT_a802b08f = 0x10;
            FUN_a00a8c88();
            FUN_a00a9abc();
            FUN_a00a9650(DAT_a8025c54, 2);
            FUN_a00a813c(1, DAT_a8025c54, 1);
            FUN_a00a9650(3, 3);
            _DAT_a802afec = 0x82;
            DAT_a8025c55 = DAT_a802d290.b1a4;
        }
    } else {
        DAT_a802d290.b20 = FUN_a014459c(_DAT_a802afec + 0x2c);
        if (DAT_a802d290.b20 != old)
            FUN_a00d5938(1);
        DAT_a802b08f = 0x10;
        FUN_a00a8c88();
        FUN_a00a9abc();
        FUN_a00a9650(DAT_a8025c54, 2);
        FUN_a00a813c(1, DAT_a8025c54, 1);
        FUN_a00a9650(4, 3);
        _DAT_a802afec = 0x83;
        DAT_a8025c55 = DAT_a802d290.b1a4;
    }
    DAT_a802d290.b1a3 = 0;
    DAT_a802b08e |= 2;
}
