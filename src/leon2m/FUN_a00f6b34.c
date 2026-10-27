/* FUN_a00f6b34 (leon2m 0xa00f6b34-0xa00f6c38, 260 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * For each bit set in m: bits 0..4 set bit 6, 5, 4, 3, 2 of the word register 0xcf00ef00; bits 5, 6, 7 or 0x81,
 * 0x41, 0x11 into the word register 0xcf00ef30 (one read-modify-write per bit). Called by FUN_a012d554,
 * FUN_a013dc6c (3 calls). It lies between FUN_a00f6ab4 and FUN_a00f6c38. Source form: an unsigned int parameter
 * (bit tests on the raw register).
 */
#define R300 (*(volatile unsigned int *)0xcf00ef00)
#define R330 (*(volatile unsigned int *)0xcf00ef30)

void FUN_a00f6b34(unsigned int m)
{
    if (m & 1)
        R300 |= 0x40;
    if (m & 2)
        R300 |= 0x20;
    if (m & 4)
        R300 |= 0x10;
    if (m & 8)
        R300 |= 8;
    if (m & 0x10)
        R300 |= 4;
    if (m & 0x20)
        R330 |= 0x81;
    if (m & 0x40)
        R330 |= 0x41;
    if (m & 0x80)
        R330 |= 0x11;
}
