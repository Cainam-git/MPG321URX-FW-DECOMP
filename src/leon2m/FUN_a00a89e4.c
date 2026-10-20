/* leon2m FUN_a00a89e4 @ 0xa00a89e4-0xa00a8a78 (37 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a0146b50(0x111, 0); FUN_a0146b6c(0, 0); for i = 0, 1 (u8): FUN_a00a31a4(0, 0x2a, i*2 + 6, 1,
 * FUN_a00a3844(table 0x190748, (u16)(i*29 + byte DAT_a802d290[8])), 0). The 3rd arg is not masked (no sll/srl):
 * a31a4's 3rd param is a full word; the a3844 index is u16. The table address is 0x190748 (fw sethi 0x190400 |
 * 0x348). Family of FUN_a00a8654 / FUN_a00b3c80 (same goto loop).
 * Source form: the record base DAT_a802d290[8]; the loop is a label + 'if (i <= 1) goto top' (with do/while loop.c
 * hoists the full &DAT_a802d290 address).
 * Compiler aids: none.
 */
extern unsigned char DAT_a802d290[];
extern unsigned int DAT_00190748[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);

void FUN_a00a89e4(void)
{
    unsigned char i;

    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    i = 0;
top:
    FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1,
                 FUN_a00a3844(DAT_00190748, i * 29 + DAT_a802d290[8]), 0);
    i++;
    if (i <= 1)
        goto top;
}
