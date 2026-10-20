/* leon2m FUN_a0093334 @ 0xa0093334-0xa0093464 (76 words).
 * Compares byte 0xa802d290+0x182 with byte 0xa8025c56 and bit 11 of word 0xa802d290+0xa8 with byte 0xa8025c55.
 * A flag is set when either differs, except when (word 0xa802d290+0x180 & 0xffff00) is 0x100 and the bit
 * differs. Then copies byte 0xa8025c56 to +0x182 and byte 0xa8025c55 to bit 11, calls
 * FUN_a00a93bc(word 0xa802afec - 0x48), FUN_a00a9650(b, 0) and FUN_a00a813c(1, b, 1) with b = byte +0x182,
 * stores 0xe to word 0xa802afec and calls FUN_a00a900c(0, 1). With the flag set, calls FUN_a00dbcf0 when
 * bit 11 is clear and FUN_a00db738 when it is set. Finally tail-calls FUN_a00acc40.
 * Exact form: the flag is set by an if/else (an && expression gives subx flag arithmetic); the byte is copied
 * before the bit; the bit-clear arm of the last test is written first.
 */
struct D290 {
    unsigned char p000[0xa8];
    struct { unsigned int hi : 20, b11 : 1, lo : 11; } wa8;
    unsigned char p0ac[0x180 - 0xac];
    union { unsigned int w; unsigned char b[4]; } u180;
};
extern struct D290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a8025c56;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00dbcf0(void);
extern void FUN_a00db738(void);
extern void FUN_a00acc40(void);

void FUN_a0093334(void)
{
    unsigned char f;

    if (DAT_a802d290.u180.b[2] != DAT_a8025c56 || DAT_a8025c55 != DAT_a802d290.wa8.b11) {
        if ((DAT_a802d290.u180.w & 0xffff00) == 0x100 && DAT_a8025c55 != DAT_a802d290.wa8.b11)
            f = 0;
        else
            f = 1;
    } else
        f = 0;
    DAT_a802d290.u180.b[2] = DAT_a8025c56;
    DAT_a802d290.wa8.b11 = DAT_a8025c55;
    FUN_a00a93bc(_DAT_a802afec - 0x48);
    FUN_a00a9650(DAT_a802d290.u180.b[2], 0);
    FUN_a00a813c(1, DAT_a802d290.u180.b[2], 1);
    _DAT_a802afec = 0xe;
    FUN_a00a900c(0, 1);
    if (f) {
        if (!DAT_a802d290.wa8.b11)
            FUN_a00dbcf0();
        else
            FUN_a00db738();
    }
    FUN_a00acc40();
}
