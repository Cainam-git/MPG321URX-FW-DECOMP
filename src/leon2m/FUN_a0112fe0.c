/* FUN_a0112fe0 (leon2m 0xa0112fe0-0xa0113020, 64 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Sets (on non-zero) or clears (on 0) bit 'bit' of the word register 0xcf011800. Nothing in the image refers to it:
 * no call, branch, sethi/or constant or address word. It lies between FUN_a0112fcc and FUN_a0113020.
 */
#define REG (*(volatile unsigned int *)0xcf011800)

void FUN_a0112fe0(unsigned int bit, unsigned char on)
{
    if (on)
        REG |= 1 << bit;
    else
        REG &= ~(1 << bit);
}
