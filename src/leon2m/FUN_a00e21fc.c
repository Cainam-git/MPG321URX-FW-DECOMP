/* leon2m FUN_a00e21fc @ 0xa00e21fc-0xa00e222c (12 words).
 * Returns the bit field lo..hi of the value that FUN_a00e021c(addr) reads: (FUN_a00e021c(addr) & ((1 << (hi + 1)) -
 * (1 << lo))) >> lo. The mask is computed before the call, as two shifts of 1 and a subtraction.
 */
extern unsigned int FUN_a00e021c(unsigned int);

unsigned int FUN_a00e21fc(unsigned int addr, unsigned int hi, unsigned int lo)
{
    unsigned int mask = (1 << (hi + 1)) - (1 << lo);

    return (FUN_a00e021c(addr) & mask) >> lo;
}
