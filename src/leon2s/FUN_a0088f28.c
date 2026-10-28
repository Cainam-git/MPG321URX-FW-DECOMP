/* leon2s FUN_a0088f28 @ 0xa0088f28 (-mcpu=v8 -Os -g)
 * Returns 1 when bit 4 of FUN_a00a78b4(p & 0xff, 0x70) is set, else 0.
 * FUN_a00a78b4 returns the low byte of a register (unsigned char); the bit test goes through the
 * unsigned int x.
 */
// FUN_a00a78b4 at 0xa00a78b4
extern unsigned char FUN_a00a78b4(unsigned int, unsigned short);

// FUN_a0088f28 at 0xa0088f28
unsigned int FUN_a0088f28(unsigned int param_1)
{
    unsigned int x = FUN_a00a78b4(param_1 & 0xff, 0x70) & 0x10;
    return x != 0;
}
