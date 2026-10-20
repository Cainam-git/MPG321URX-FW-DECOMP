/* leon2m FUN_a0102680 @ 0xa0102680..0xa01026e8 (26 words)  start-up step 2, call 1 of FUN_a015266c: two fixed PLL
 * values for the chip's own clocks.
 * What it does at power-on (code facts): sets bit 6 of 0xCF014780, writes the 24-bit value 0x320000 into the three
 * byte registers 0xCF014184.. (FUN_a00f30f0, then its 10-nop settle), sets bit 7 of 0xCF014194 and bit 4 of
 * 0xCF012440, then writes 0x29AAAA into 0xCF012A44.. (tail call of FUN_a00f30f0). Using FUN_a01026e8's formula
 * (value = f * 2^17 / 12 MHz crystal), 0x320000 = 300 MHz and 0x29AAAA = 250 MHz (arithmetic; these registers
 * are not among the GPLL_DISPx/FRC registers FUN_a01026e8 names).
 * Can it fail or wait? No: no read-back, no loop, no timeout, only the fixed 10-nop settle in FUN_a00f30f0.
 * Start-up order: runs before FUN_a0106d64.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern void FUN_a00f30f0(unsigned int, unsigned int);

void FUN_a0102680(void)
{
    R(0xcf014780) |= 0x40;
    FUN_a00f30f0(0xcf014184, 0x320000);
    R(0xcf014194) |= 0x80;
    R(0xcf012440) |= 0x10;
    FUN_a00f30f0(0xcf012a44, 0x29aaaa);
}
