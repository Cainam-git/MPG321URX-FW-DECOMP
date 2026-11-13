/* pq_window_clear_ee40_bits  (FUN_a00f6ab4)
 *
 * Clear bit 6 or 7 of register 0xCF00EE40 or 0xCF00EE68 by a selector.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6ab4 @ 0xa00f6ab4-0xa00f6b34 (128 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: a switch with a jump table (run-time 0x963a8, image 0xa00f63a8).
 */
#define REG_EE40 (*(volatile unsigned int *)0xcf00ee40)
#define REG_EE68 (*(volatile unsigned int *)0xcf00ee68)
#define BIT6 0x40
#define BIT7 0x80

/*
 * Clear bit 6 or 7 of one of two registers, selected by the selector.
 * selector 0 or 4: clear bit 6 of 0xCF00EE40.
 * selector 1: clear bit 7 of 0xCF00EE40.
 * selector 2: clear bit 6 of 0xCF00EE68.
 * selector 3: clear bit 7 of 0xCF00EE68.
 * Other selector values do nothing.
 */
void pq_window_clear_ee40_bits(unsigned int selector)
{
    switch (selector) {
    case 0:
    case 4:
        REG_EE40 &= ~BIT6;
        break;
    case 1:
        REG_EE40 &= ~BIT7;
        break;
    case 2:
        REG_EE68 &= ~BIT6;
        break;
    case 3:
        REG_EE68 &= ~BIT7;
        break;
    }
}
