/* FUN_a010ace4 (leon2m 0xa010ace4-0xa010ad28, 68 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Sets (on non-zero) or clears (on 0) bit 'bit' of the word register 0xcf011dc8. Nothing in the image refers to it:
 * no call, branch, sethi/or constant or address word. It lies between FUN_a010ac68 and FUN_a010ad28.
 */
#define REG (*(volatile unsigned int *)0xcf011dc8)

void FUN_a010ace4(unsigned int bit, unsigned char on)
{
    if (on)
        REG |= 1 << bit;
    else
        REG &= ~(1 << bit);
}
