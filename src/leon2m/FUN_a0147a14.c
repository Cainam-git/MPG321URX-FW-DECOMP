/* leon2m FUN_a0147a14 @ 0xa0147a14-0xa0147a7c (26 words).
 * Computes v = (unsigned short)((x * 1023 + 50) / 100) (unsigned division) and tail-calls
 * FUN_a01386ac(0, v * 20914 / 1023 + 1) (signed division, truncated to unsigned short).
 * Called from FUN_a0086ae8, FUN_a00d4970 and FUN_a00d93c8.
 */
extern void FUN_a01386ac(unsigned char a, unsigned short b);

void FUN_a0147a14(unsigned char x)
{
    unsigned short v = (unsigned int)(x * 1023 + 50) / 100;

    FUN_a01386ac(0, v * 20914 / 1023 + 1);
}
