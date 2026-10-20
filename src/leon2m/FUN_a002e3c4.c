/* leon2m FUN_a002e3c4 @ 0xa002e3c4-0xa002e408 (17 words).
 * Sets (on nonzero) or clears bit n of the register at 0xcf011fc0; the mask is 1 << n cut to 8 bits.
 * The register is read and written back once in either case (read-modify-write through a volatile pointer).
 */
#define REG (*(volatile unsigned int *)0xcf011fc0)

void FUN_a002e3c4(unsigned char n, unsigned char on)
{
    unsigned char m = 1 << n;

    if (on)
        REG |= m;
    else
        REG &= ~m;
}
