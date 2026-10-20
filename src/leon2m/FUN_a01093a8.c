/* leon2m FUN_a01093a8 @ 0xa01093a8-0xa0109474 (51 words).
 * Hardware register 0xcf011aa0: when on != 0, clears bit 6 and then sets bit 'bit'; when on == 0, clears bit 'bit'.
 * Then counts how many of bits 0-3 are set (a byte counter, one register read per bit) and clears bit 6 when the
 * count is non-zero, sets it when the count is zero. Called from FUN_a012fcf4.
 */
#define REG_cf011aa0 (*(volatile unsigned int *)0xcf011aa0)

void FUN_a01093a8(unsigned char bit, unsigned char on)
{
    unsigned char n = 0;

    if (on) {
        REG_cf011aa0 &= ~0x40;
        REG_cf011aa0 |= 1 << bit;
    } else {
        REG_cf011aa0 &= ~(1 << bit);
    }
    if (REG_cf011aa0 & 1)
        n = 1;
    if (REG_cf011aa0 & 2)
        n++;
    if (REG_cf011aa0 & 4)
        n++;
    if (REG_cf011aa0 & 8)
        n++;
    if (n)
        REG_cf011aa0 &= ~0x40;
    else
        REG_cf011aa0 |= 0x40;
}
