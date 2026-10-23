/* leon2m FUN_a0098618 @ 0xa0098618-0xa0098794 (95 words).
 * With b = byte 0xa8025c56 and k = byte DAT_a802d290+0x1a3: when st[k] / 7 (st = DAT_a802d290+0x18a) differs
 * from b / 7, calls FUN_a00a8c88() and FUN_a00b7b8c(0) when b / 7 is 0, FUN_a00b7b8c(1) otherwise. Then
 * st[k] = b, FUN_a00a93bc((word 0xa802afec - 0x86) % 7), FUN_a00a9650(st[k] % 7, 0), FUN_a00a813c(1, st[k] % 7,
 * 1), stores k + 0x26 to word 0xa802afec and calls FUN_a00a900c(k, 1) (tail call). Same record as FUN_a00984f0.
 */
struct D290 {
    unsigned char p000[0x18a];
    unsigned char st[0x1a3 - 0x18a];
    unsigned char b1a3;
};
extern struct D290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a8025c56;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a8c88(void);
extern void FUN_a00b7b8c(unsigned char);

void FUN_a0098618(void)
{
    if (DAT_a802d290.st[DAT_a802d290.b1a3] / 7 != DAT_a8025c56 / 7) {
        if (DAT_a8025c56 / 7 == 0) {
            FUN_a00a8c88();
            FUN_a00b7b8c(0);
        } else {
            FUN_a00a8c88();
            FUN_a00b7b8c(1);
        }
    }
    DAT_a802d290.st[DAT_a802d290.b1a3] = DAT_a8025c56;
    FUN_a00a93bc((_DAT_a802afec - 0x86) % 7);
    FUN_a00a9650(DAT_a802d290.st[DAT_a802d290.b1a3] % 7, 0);
    FUN_a00a813c(1, DAT_a802d290.st[DAT_a802d290.b1a3] % 7, 1);
    _DAT_a802afec = DAT_a802d290.b1a3 + 0x26;
    FUN_a00a900c(DAT_a802d290.b1a3, 1);
}
