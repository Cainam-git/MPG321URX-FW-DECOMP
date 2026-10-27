/* FUN_a0113020 (leon2m 0xa0113020-0xa0113064, 68 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Sets (on non-zero) or clears (on 0) bit 'bit' of the word register 0xcf011a00. Nothing in the image refers to it:
 * no call, branch, sethi/or constant or address word. It lies between FUN_a0112fe0 and FUN_a0113064.
 */
#define REG (*(volatile unsigned int *)0xcf011a00)

void FUN_a0113020(unsigned int bit, unsigned char on)
{
    if (on)
        REG |= 1 << bit;
    else
        REG &= ~(1 << bit);
}
