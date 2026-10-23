/* FUN_a00d2618 (leon2s 0xa00d2618-0xa00d264c, 52 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Sets (on != 0) or clears (on == 0) bit 'bit' of the byte DAT_a8078c36. Same form as FUN_a00ab884: the
 * expression '1 << bit' is written in each arm.
 */
extern unsigned char DAT_a8078c36;

void FUN_a00d2618(unsigned char bit, unsigned char on)
{
    if (on)
        DAT_a8078c36 |= 1 << bit;
    else
        DAT_a8078c36 &= ~(1 << bit);
}
