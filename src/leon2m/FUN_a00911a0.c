/* leon2m FUN_a00911a0 @ 0xa00911a0-0xa0091294 (61 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Returns at once when bit 10 (0x400) of halfword 0xa802cff4 is set or FUN_a013ce6c(0) does not return 0xc.
 * Otherwise calls FUN_a00b5378. When bit 14 (0x4000) of word 0xa802d290 is set: word 0xa802afec = 1, byte
 * 0xa802b08f = 0, FUN_a0146b50(0xfe, 0), FUN_a0146b6c(0, 0), FUN_a0146a80(1, 4, 1, 0x592, 0) and
 * FUN_a00a31a4(0, 1, 4, 1, FUN_a00a3844(word table 0x197ee4, 8), 0); else word 0xa802afec = 2 and
 * FUN_a00b4144(0, 1). Ends with FUN_a00b0034(0) and the tail call FUN_a00a45a8().
 */
extern unsigned short DAT_a802cff4;
extern unsigned int DAT_a802d290;
extern unsigned int DAT_a802afec;
extern unsigned char DAT_a802b08f;
extern unsigned int DAT_00197ee4[];
extern unsigned char FUN_a013ce6c(unsigned char);
extern void FUN_a00b5378(void);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);
extern void FUN_a00b4144(unsigned char, int);
extern void FUN_a00b0034(unsigned char);
extern void FUN_a00a45a8(void);

void FUN_a00911a0(void)
{
    if (DAT_a802cff4 & 0x400)
        return;
    if (FUN_a013ce6c(0) != 0xc)
        return;
    FUN_a00b5378();
    if (DAT_a802d290 & 0x4000) {
        DAT_a802afec = 1;
        DAT_a802b08f = 0;
        FUN_a0146b50(0xfe, 0);
        FUN_a0146b6c(0, 0);
        FUN_a0146a80(1, 4, 1, 0x592, 0);
        FUN_a00a31a4(0, 1, 4, 1, FUN_a00a3844(DAT_00197ee4, 8), 0);
    } else {
        DAT_a802afec = 2;
        FUN_a00b4144(0, 1);
    }
    FUN_a00b0034(0);
    FUN_a00a45a8();
}
