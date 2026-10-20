/* FUN_a00aaaac (leon2m, 0xa00aaaac-0xa00aabf0, 324 bytes, 81 words).
 * Flags: -mcpu=v8 -O3 -g. Judge: jf 100.00 match=True, rawcmp 0/81 mismatches.
 * Code facts: FUN_4008e2a4(); for i = 5..20 (u8): FUN_a0146b20(0, 0x13, i, 0x13, 0, 0) and
 * FUN_a0146a80(0x13, i, 0x13, 0x792, 0); FUN_a0146b20(0, 0x1c, 0x15, 2, 0, 0); FUN_a0146c40(5, 0, 0);
 * FUN_a0146b50(0x92, 0); FUN_a0146b6c(0, 0); then for j = 0..2: when (u8)FUN_a00aa520(j) == 0,
 * FUN_a0146a80(0x14, j*2 + 6, 0xd, 0x292, 0); FUN_a00a31a4(0, 0x14, j*2 + 6, 1,
 * FUN_a00a3844(DAT_0018a360, j*29 + byte +8 of the record DAT_a802d290), 0).
 * Required forms: same shape as FUN_a00b3c80 / FUN_a00a8654: the record byte is
 * DAT_a802d290.b08 (struct, fw 'or %l4,0x290' inside the loop + ldub [+8]; a separate
 * DAT_a802d298 symbol lets loop.c hoist the full address), the table is the symbol DAT_0018a360,
 * and the second loop is a label + 'if (j <= 2) goto top'. Aids: none.
 */
extern void FUN_4008e2a4(void);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146c40(unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(unsigned char, unsigned char);
extern unsigned char FUN_a00aa520(unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
struct St { unsigned char pad[8]; unsigned char b08; };
extern struct St DAT_a802d290;
extern unsigned int DAT_0018a360[];

void FUN_a00aaaac(void)
{
    unsigned char i, j;
    unsigned int result;

    FUN_4008e2a4();
    for (i = 5; i <= 20; i++) {
        FUN_a0146b20(0, 0x13, i, 0x13, 0, 0);
        FUN_a0146a80(0x13, i, 0x13, 0x792, 0);
    }
    FUN_a0146b20(0, 0x1c, 0x15, 2, 0, 0);
    FUN_a0146c40(5, 0, 0);
    FUN_a0146b50(0x92, 0);
    FUN_a0146b6c(0, 0);

    j = 0;
top:
    if ((FUN_a00aa520(j) & 0xff) == 0)
        FUN_a0146a80(0x14, j * 2 + 6, 0xd, 0x292, 0);
    result = FUN_a00a3844(DAT_0018a360, j * 29 + DAT_a802d290.b08);
    FUN_a00a31a4(0, 0x14, j * 2 + 6, 1, result, 0);
    j++;
    if (j <= 2)
        goto top;
}
