/* leon2m FUN_a00b617c @ 0xa00b617c-0xa00b621c (40 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0 mismatches.
 * Code facts: FUN_a0146b50(0x111, 0); FUN_a0146b6c(0, 0); for i = 0..5 (u8, bleu 5):
 * FUN_a00a31a4(0, 0x2a, i*2 + 6, 1, FUN_a00a3844(table 0x195f24, (u16)(i*29 + rec.b08)), 0) with
 * rec = 0xa802d290; then tail FUN_a00a813c(1, rec byte +0x182, 1) (ldub [%l0+0x182] into %i1).
 * Twin of FUN_a00b3070/FUN_a00ab340 (those use the table at 0x18e9f8).
 * Fixes vs the autoc draft: BEHAVIOUR, the middle argument of FUN_a00a813c is rec.b182, not 1;
 * table name DAT_0018e9f8 -> DAT_00195f24 (sethi 0x195c00 | 0x324). Aids: none.
 */
struct St { unsigned char pad[8]; unsigned char b08; unsigned char pad2[0x182 - 9]; unsigned char b182; };
extern struct St DAT_a802d290;
extern unsigned int DAT_00195f24[];
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);
extern void FUN_a00a813c(int, unsigned char, int);

void FUN_a00b617c(void)
{
    unsigned char i;

    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    i = 0;
    do {
        FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_00195f24, (unsigned short)(i * 29 + DAT_a802d290.b08)), 0);
        i++;
    } while (i <= 5);
    FUN_a00a813c(1, DAT_a802d290.b182, 1);
}
