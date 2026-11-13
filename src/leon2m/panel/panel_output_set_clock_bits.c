/* panel_output_set_clock_bits  (FUN_a010b884)
 *
 * Set clock bits of the output stage by a selector.
 * Name basis: descriptive - registers 0xCF00B844 and 0xCF00B870; unused
 *
 * Matching notes
 * --------------
 * FUN_a010b884, flags -mcpu=v8 -O3 -g. Leaf. Nothing in the image calls or points to it.
 */
#define CLOCK_REG_B844 (*(volatile unsigned int *)0xcf00b844)
#define CLOCK_REG_B870 (*(volatile unsigned int *)0xcf00b870)

/*
 * selector 1: clear bit 7 and set bit 6 of 0xCF00B844, set bit 7 of 0xCF00B870.
 * Any other selector: set bits 6 and 7 of 0xCF00B844, clear bit 7 of 0xCF00B870.
 */
void panel_output_set_clock_bits(unsigned char selector)
{
    if (selector == 1) {
        CLOCK_REG_B844 &= ~0x80u;
        CLOCK_REG_B844 |= 0x40;
        CLOCK_REG_B870 |= 0x80;
    } else {
        CLOCK_REG_B844 |= 0xc0;
        CLOCK_REG_B870 &= ~0x80u;
    }
}
