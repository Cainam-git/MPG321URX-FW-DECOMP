/* FUN_a00f66a4 (leon2m 0xa00f66a4-0xa00f67d0, 300 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * For each bit set in m: bits 0..4 clear bit 6, 5, 4, 3, 2 of the word register 0xcf00ef00; bits 5, 6, 7 clear bit
 * 7, 6, 4 of the word register 0xcf00ef30; finally clears bit 0 of 0xcf00ef30 when its bits 5..7 are all clear.
 * Called by FUN_a012d554. It lies between FUN_a00f65d8 and FUN_a00f67d0. Source form: the counterpart of
 * FUN_a00f6b34 (unsigned int parameter).
 */
#define R300 (*(volatile unsigned int *)0xcf00ef00)
#define R330 (*(volatile unsigned int *)0xcf00ef30)

void FUN_a00f66a4(unsigned int m)
{
    if (m & 1)
        R300 &= ~0x40u;
    if (m & 2)
        R300 &= ~0x20u;
    if (m & 4)
        R300 &= ~0x10u;
    if (m & 8)
        R300 &= ~8u;
    if (m & 0x10)
        R300 &= ~4u;
    if (m & 0x20)
        R330 &= ~0x80u;
    if (m & 0x40)
        R330 &= ~0x40u;
    if (m & 0x80)
        R330 &= ~0x10u;
    if ((R330 & 0xe0) == 0)
        R330 &= ~1u;
}
