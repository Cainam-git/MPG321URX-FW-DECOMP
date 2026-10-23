/* leon2m FUN_a00a03e8 @ 0xa00a03e8-0xa00a0508 (72 words).
 * When byte 0xa802d290+0x1a9 is 1: if bit 15 of the halfword 0xa802cff8 (0xa802cff4 + 4) is set, sets its bit 10
 * and calls FUN_a00808ac(4, 0); clears word 0xa802afec, calls FUN_a00b5080, clears byte 0xa802cffe, calls
 * FUN_a00b0f48, stores 0x116 to word 0xa802afec, sets bit 1 of byte 0xa802b08e, clears byte 0xa802d290+0x1aa
 * and stores the return value of FUN_a002d588 to the halfword 0xa802d03c.
 * Otherwise, with b = byte 0xa802d290+0x182: FUN_a00a813c(1, b, 0), FUN_a00a900c(word 0xa802afec - 14, 2),
 * word 0xa802afec = b + 0x48, FUN_a00a9650(b, 1); copies b to byte 0xa8025c56 and bit 11 of word
 * 0xa802d290+0xa8 to byte 0xa8025c55; when that bit is set, clears it and, unless (word 0xa802d290+0x180 &
 * 0xffff00) is 0x100, tail-calls FUN_a00dbcf0.
 * The word at +0x180 and its byte +0x182 are one union.
 * Source form: bit 15 of the halfword is tested as '(short)(h4 & 0x8000)' (same as FUN_a00a0508).
 */
struct D290 {
    unsigned char p000[0xa8];
    unsigned int w0a8;
    unsigned char p0ac[0x180 - 0xac];
    union { unsigned int w; unsigned char b[4]; } u180;
    unsigned char p184[0x1a9 - 0x184];
    unsigned char b1a9;
    unsigned char b1aa;
};
struct CFF4 {
    unsigned short h0;
    unsigned short h2;
    unsigned short h4;
    unsigned char p6[4];
    unsigned char ba;
};
extern struct D290 DAT_a802d290;
extern struct CFF4 DAT_a802cff4;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a8025c56;
extern unsigned short _DAT_a802d03c;
extern void FUN_a00808ac(int, int);
extern void FUN_a00b5080(void);
extern void FUN_a00b0f48(void);
extern unsigned short func_0x4008d588(void);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00dbcf0(void);

void FUN_a00a03e8(void)
{
    if (DAT_a802d290.b1a9 == 1) {
        if ((short)(DAT_a802cff4.h4 & 0x8000)) {
            DAT_a802cff4.h4 |= 0x400;
            FUN_a00808ac(4, 0);
        }
        _DAT_a802afec = 0;
        FUN_a00b5080();
        DAT_a802cff4.ba = 0;
        FUN_a00b0f48();
        _DAT_a802afec = 0x116;
        DAT_a802b08e |= 2;
        DAT_a802d290.b1aa = 0;
        _DAT_a802d03c = func_0x4008d588();
        return;
    }
    FUN_a00a813c(1, DAT_a802d290.u180.b[2], 0);
    FUN_a00a900c(_DAT_a802afec - 14, 2);
    _DAT_a802afec = DAT_a802d290.u180.b[2] + 0x48;
    FUN_a00a9650(DAT_a802d290.u180.b[2], 1);
    DAT_a8025c56 = DAT_a802d290.u180.b[2];
    DAT_a8025c55 = (DAT_a802d290.w0a8 >> 11) & 1;
    if (DAT_a802d290.w0a8 & 0x800) {
        DAT_a802d290.w0a8 &= ~0x800;
        if ((DAT_a802d290.u180.w & 0xffff00) != 0x100)
            FUN_a00dbcf0();
    }
}
