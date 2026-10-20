/* FUN_a0149018: calls FUN_a0151aa4(0x10, 1) and FUN_a0151aa4(0x20, 1), stores bit 0 of on into bit 25 of the
 * word DAT_a802e1a0 and tail-calls FUN_a0153970(&DAT_a802e1a0, 0). No direct callers were found.
 * Bit 25 is a 1-bit bit-field of the word (the mask form gives the same bytes).
 */
struct W { unsigned int b31_26 : 6, b25 : 1, rest : 25; };
extern struct W DAT_a802e1a0;
extern void FUN_a0151aa4(unsigned int, unsigned int);
extern void FUN_a0153970(void *, unsigned int);

void FUN_a0149018(unsigned int on)
{
    FUN_a0151aa4(0x10, 1);
    FUN_a0151aa4(0x20, 1);
    DAT_a802e1a0.b25 = on;
    FUN_a0153970(&DAT_a802e1a0, 0);
}
