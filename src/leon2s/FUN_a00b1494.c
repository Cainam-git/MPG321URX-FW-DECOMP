/* FUN_a00b1494 (leon2s 0xa00b1494-0xa00b14b0, 28 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Returns byte +0x117 of the 300-byte port record ARR_a807dc18[port]. Called by FUN_a00d8d20.
 * Leaf routine without a register window (no save).
 */
struct port300 { unsigned char _000[0x117]; unsigned char b117; unsigned char _118[0x14]; };
extern struct port300 ARR_a807dc18[];

unsigned char FUN_a00b1494(unsigned char port)
{
    return ARR_a807dc18[port].b117;
}
