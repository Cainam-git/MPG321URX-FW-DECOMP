/* leon2m FUN_a00f30a8 @ 0xa00f30a8  read a 24-bit value from three consecutive byte registers (hand; 
 * byte-exact). r[0] = bits 0..7, r[1] = bits 8..15, r[2] = bits 16..23 (word-spaced hardware registers).
 * Used by the GPLL programmer FUN_a01026e8 to read a clock's current PLL value, and by FUN_a00f381c. */
unsigned int FUN_a00f30a8(volatile unsigned int *r)
{
    unsigned int lo = r[0];
    return lo | r[1] << 8 | r[2] << 16;
}
