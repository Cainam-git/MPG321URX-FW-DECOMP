/* leon2m FUN_a0101e24 @ 0xa0101e24-0xa0101e68 (17 words).
 * Sets (on nonzero) or clears bit n of the register at 0xcf011360; the register is read and written back once in
 * either case (read-modify-write through a volatile pointer). A leaf routine without a register window.
 */
#define REG (*(volatile unsigned int *)0xcf011360)

void FUN_a0101e24(unsigned char n, unsigned char on)
{
    if (on)
        REG |= 1 << n;
    else
        REG &= ~(1 << n);
}
