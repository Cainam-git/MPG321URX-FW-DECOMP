/* FUN_a00703b8 (leon2s 0xa00703b8-0xa00703d4, 28 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Returns (DAT_a80788d8 & (1 << n)) as a byte. Called by FUN_a00d17a8.
 * Leaf routine without a register window (no save).
 */
extern unsigned int DAT_a80788d8;

unsigned char FUN_a00703b8(unsigned int n)
{
    return DAT_a80788d8 & (1 << n);
}
