/* leon2m FUN_a0109554 @ 0xa0109554-0xa0109598 (17 words).
 * Sets (on nonzero) or clears bit n of the register at 0xcf011a00; the register is read and written back once in
 * either case (read-modify-write through a volatile pointer). A leaf routine without a register window.
 */
#define REG (*(volatile unsigned int *)0xcf011a00)

void FUN_a0109554(unsigned char n, unsigned char on)
{
    if (on)
        REG |= 1 << n;
    else
        REG &= ~(1 << n);
}
