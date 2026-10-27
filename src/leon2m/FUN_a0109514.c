/* FUN_a0109514 (leon2m 0xa0109514-0xa0109554, 64 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Sets (on non-zero) or clears (on 0) bit 'bit' of the word register 0xcf011800. Nothing in the image refers to it:
 * no call, branch, sethi/or constant or address word. It lies between FUN_a0109474 and FUN_a0109554.
 */
#define REG (*(volatile unsigned int *)0xcf011800)

void FUN_a0109514(unsigned int bit, unsigned char on)
{
    if (on)
        REG |= 1 << bit;
    else
        REG &= ~(1 << bit);
}
