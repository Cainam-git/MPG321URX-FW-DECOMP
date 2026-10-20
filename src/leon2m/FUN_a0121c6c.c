/* leon2m FUN_a0121c6c @ 0xa0121c6c-0xa0121cf4 (34 words).
 * Waits for bit 7 of FUN_a00f1f9c(p, 0x20) to become set, then for it to become clear again; each wait reads the
 * value at most 0x61a9 times (16-bit counter, compared with 0x61a7 after each read). Callers: FUN_a00f04f8 (twice),
 * FUN_a00f0b58 (three times), FUN_a00f8f78 (twice).
 */
extern unsigned char FUN_a00f1f9c(unsigned char a, unsigned char b);

void FUN_a0121c6c(unsigned char p)
{
    unsigned short i;

    for (i = 0; !(FUN_a00f1f9c(p, 0x20) & 0x80) && i <= 0x61a7; i++)
        ;
    for (i = 0; (FUN_a00f1f9c(p, 0x20) & 0x80) && i <= 0x61a7; i++)
        ;
}
