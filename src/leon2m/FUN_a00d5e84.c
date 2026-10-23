/* leon2m FUN_a00d5e84 @ 0xa00d5e84-0xa00d5ea4 (8 words).
 * FUN_a0148ef4(bit 30 of word DAT_a802d294) as a tail call. Called from FUN_a0086ae8.
 * Source form: bit 30 is a 1-bit bit-field; the range ends with the nop that -g leaves after the final call.
 */
struct W294 {
    unsigned int b31 : 1;
    unsigned int b30 : 1;
    unsigned int rest : 30;
};
extern struct W294 DAT_a802d294;
extern void FUN_a0148ef4(unsigned char);

void FUN_a00d5e84(void)
{
    FUN_a0148ef4(DAT_a802d294.b30);
}
