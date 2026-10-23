/* FUN_a00a268c (leon2s 0xa00a268c-0xa00a26a8, 28 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Returns byte +0x158 of the 400-byte record DAT_a807d7e0[port]. Called by FUN_a00d2e00.
 * Leaf routine without a register window (no save).
 */
struct mode_rec { unsigned char _000[0x158]; unsigned char f158; unsigned char _159[0x37]; };
extern struct mode_rec DAT_a807d7e0[];

unsigned char FUN_a00a268c(unsigned char port)
{
    return DAT_a807d7e0[port].f158;
}
