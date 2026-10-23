/* leon2m FUN_a00d58d8 @ 0xa00d58d8-0xa00d58f8 (8 words).
 * FUN_a0149064(1, bits 16..19 of word DAT_a802d2c4) as a tail call.
 * Source form: the 4-bit value is a bit-field of the word (GCC reads it with lduh); the range ends with the nop
 * that -g leaves after the final call.
 */
struct W2c4 {
    unsigned int hi : 12;
    unsigned int f16 : 4;
    unsigned int f12 : 4;
    unsigned int lo : 12;
};
extern struct W2c4 DAT_a802d2c4;
extern void FUN_a0149064(unsigned char, unsigned char);

void FUN_a00d58d8(void)
{
    FUN_a0149064(1, DAT_a802d2c4.f16);
}
