/* leon2m FUN_a00d5918 @ 0xa00d5918-0xa00d5938 (8 words).
 * FUN_a0148d98(bit 9 of word DAT_a802d290) as a tail call.
 * Source form: bit 9 is a 1-bit bit-field of the word; the range ends with the nop that -g leaves after the
 * final call.
 */
struct W290 {
    unsigned int hi : 22;
    unsigned int b9 : 1;
    unsigned int lo : 9;
};
extern struct W290 DAT_a802d290;
extern void FUN_a0148d98(unsigned char);

void FUN_a00d5918(void)
{
    FUN_a0148d98(DAT_a802d290.b9);
}
