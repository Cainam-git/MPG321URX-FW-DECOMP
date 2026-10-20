/* leon2m FUN_a00b05d8 @ 0xa00b05d8-0xa00b0710 (78 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a0146b50(0x4e, 0); FUN_a0146b6c(2, 0); with b = byte 0xa802d290+8, six text
 * draws FUN_a00a31a4(0, x, y, w, FUN_a00a3844(table, n), 0): (9, 1, 0x16, 0x1819cc, b), (2, 3, 0x24, 0x1814d8, b),
 * (2, 4, 0x24, 0x181058, b), (2, 5, 0x24, 0x180b60, b), (0xa, 8, 8, 0x190748, b), tail (0x16, 8, 8, 0x190748,
 * (u16)(b + 29)) (ROM word tables read by FUN_a00a3844).
 * Required forms: table symbols DAT_001819cc etc. (fw sethi|or each), one record pointer (fw %l0),
 * callee prototypes as in FUN_a00b3c80. Aids: none.
 */
struct St { unsigned char pad[8]; unsigned char b08; };
extern struct St DAT_a802d290;
extern unsigned int DAT_001819cc[], DAT_001814d8[], DAT_00181058[], DAT_00180b60[], DAT_00190748[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);

void FUN_a00b05d8(void)
{
    struct St *p;

    FUN_a0146b50(0x4e, 0);
    FUN_a0146b6c(2, 0);
    p = &DAT_a802d290;
    FUN_a00a31a4(0, 9, 1, 0x16, FUN_a00a3844(DAT_001819cc, p->b08), 0);
    FUN_a00a31a4(0, 2, 3, 0x24, FUN_a00a3844(DAT_001814d8, p->b08), 0);
    FUN_a00a31a4(0, 2, 4, 0x24, FUN_a00a3844(DAT_00181058, p->b08), 0);
    FUN_a00a31a4(0, 2, 5, 0x24, FUN_a00a3844(DAT_00180b60, p->b08), 0);
    FUN_a00a31a4(0, 0xa, 8, 8, FUN_a00a3844(DAT_00190748, p->b08), 0);
    FUN_a00a31a4(0, 0x16, 8, 8, FUN_a00a3844(DAT_00190748, p->b08 + 29), 0);
}
