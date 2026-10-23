/* leon2m FUN_a00dd5e0 @ 0xa00dd5e0-0xa00dd614 (13 words).
 * Sets (third argument non-zero) or clears (third argument 0) the bits of the first argument in the word
 * DAT_a802b0b0. The second argument is not used.
 */
extern unsigned int DAT_a802b0b0;

void FUN_a00dd5e0(unsigned int mask, unsigned int unused, unsigned int on)
{
    if (on)
        DAT_a802b0b0 |= mask;
    else
        DAT_a802b0b0 &= ~mask;
}
