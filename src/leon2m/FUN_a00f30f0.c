/* leon2m FUN_a00f30f0 @ 0xa00f30f0  write a 24-bit value to three consecutive byte registers, then a short settle
 * delay of 10 nop loop turns (hand; byte-exact). Counterpart of FUN_a00f30a8; used by the GPLL
 * programmer FUN_a01026e8 (new PLL value) and FUN_a0102680. */
void FUN_a00f30f0(volatile unsigned int *r, unsigned int v)
{
    unsigned char i;
    r[0] = v & 0xff;
    r[1] = v >> 8 & 0xff;
    r[2] = v >> 16 & 0xff;
    for (i = 0; i <= 9; i++) __asm__ volatile ("nop");     /* settle */
}
