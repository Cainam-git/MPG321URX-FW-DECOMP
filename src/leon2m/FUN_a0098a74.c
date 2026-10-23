/* leon2m FUN_a0098a74 @ 0xa0098a74-0xa0098c08 (101 words).
 * With b = byte 0xa8025c56 and k = byte DAT_a802d290+8: when (word 0xa802afec - 0x92) / 7 equals b / 7,
 * FUN_a00a93bc(b % 7) and FUN_a00a813c(1, b % 7, 0); otherwise FUN_a00a93bc(k % 7). Then FUN_a00a9650(k % 7, 0),
 * FUN_a00a813c(1, k % 7, 1), word 0xa802afec = 0x2a, FUN_a00a900c(0, 1) and DAT_a802b08e |= 2.
 */
struct D290 {
    unsigned char p000[8];
    unsigned char b008;
};
extern struct D290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);

void FUN_a0098a74(void)
{
    if ((_DAT_a802afec - 0x92) / 7 == (unsigned char)(DAT_a8025c56 / 7)) {
        FUN_a00a93bc(DAT_a8025c56 % 7);
        FUN_a00a813c(1, DAT_a8025c56 % 7, 0);
    } else {
        FUN_a00a93bc(DAT_a802d290.b008 % 7);
    }
    FUN_a00a9650(DAT_a802d290.b008 % 7, 0);
    FUN_a00a813c(1, DAT_a802d290.b008 % 7, 1);
    _DAT_a802afec = 0x2a;
    FUN_a00a900c(0, 1);
    DAT_a802b08e |= 2;
}
