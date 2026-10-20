/* leon2m FUN_a0093464 @ 0xa0093464-0xa00934dc (30 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/30 mismatches.
 * Code facts: b = bit 12 of the word at DAT_a802d290 + 0xa8 (0xa802d338; srl 12, and 1; re-read
 * from memory before each use). FUN_a00a813c(1, b + 1, 0); byte DAT_a8025c56 = b;
 * FUN_a00a900c((u8)(word DAT_a802afec - 14), 2); DAT_a802afec = b + 0x54; tail call
 * FUN_a00a9650(b + 1, 1). void, no params.
 * Fixes vs the autoc draft (83.33): the word is a 1-bit BIT-FIELD of the record DAT_a802d290
 * (struct: pad[0xa8], hi:19, b12:1, lo:12; big-endian = first field MSB). Mask/shift forms on
 * the word fold the 0xa8 offset into %lo(sym+0xa8); the bit-field keeps 'or %lo(base)' + [base +
 * 0xa8] like the fw. The tail call takes 2 args (draft passed 6). Aids: none.
 */
extern unsigned char DAT_a8025c56;
extern unsigned int DAT_a802afec;
struct Rec290 {
    unsigned char pad[0xa8];
    unsigned int hi : 19;
    unsigned int b12 : 1;
    unsigned int lo : 12;
};
extern struct Rec290 DAT_a802d290;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a0093464(void)
{
    FUN_a00a813c(1, DAT_a802d290.b12 + 1, 0);
    DAT_a8025c56 = DAT_a802d290.b12;
    FUN_a00a900c(DAT_a802afec - 14, 2);
    DAT_a802afec = DAT_a802d290.b12 + 0x54;
    FUN_a00a9650(DAT_a802d290.b12 + 1, 1);
}
