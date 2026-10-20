/* leon2m FUN_a0099cfc @ 0xa0099cfc-0xa0099d6c (28 words), flags -mcpu=v8 -O3 -g.
 * Code facts: b = bit 15 of the word at DAT_a802d290 + 0x1dc (0xa802d46c; srl 15, and 1; re-read
 * before each use). Byte DAT_a8025c56 = b; FUN_a00a900c((u8)(word DAT_a802afec - 0x34), 2);
 * DAT_a802afec = b + 0xbb; FUN_a00a9650(b, 1); tail call FUN_a00a813c(1, b, 0). void, no params.
 * Twin of FUN_a0093464 (bit 12 at +0xa8).
 * Source form: the bit is a 1-bit BIT-FIELD of the record DAT_a802d290 (pad[0x1dc], hi:16, b15:1, lo:15;
 * big-endian). The mask/shift form on the absolute word 0xa802d46c folds the offset into %lo(sym) and loses the
 * fw's [base + 0x1dc]. Aids: none.
 */
extern unsigned char DAT_a8025c56;
extern unsigned int DAT_a802afec;
struct Rec290 {
    unsigned char pad[0x1dc];
    unsigned int hi : 16;
    unsigned int b15 : 1;
    unsigned int lo : 15;
};
extern struct Rec290 DAT_a802d290;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a0099cfc(void)
{
    DAT_a8025c56 = DAT_a802d290.b15;
    FUN_a00a900c(DAT_a802afec - 0x34, 2);
    DAT_a802afec = DAT_a802d290.b15 + 0xbb;
    FUN_a00a9650(DAT_a802d290.b15, 1);
    FUN_a00a813c(1, DAT_a802d290.b15, 0);
}
