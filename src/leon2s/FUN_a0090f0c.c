/* FUN_a0090f0c (leon2s 0xa0090f0c-0xa0090f28, 28 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Returns byte +0x20 of the 0xb0-byte record ARR_a807d3e4[i]. Called by FUN_a00d2e00.
 * Leaf routine without a register window (no save).
 */
struct Rec176 { unsigned char _0[0x20]; unsigned char b20; unsigned char _21[0x8f]; };
extern struct Rec176 ARR_a807d3e4[];

unsigned char FUN_a0090f0c(unsigned char i)
{
    return ARR_a807d3e4[i].b20;
}
