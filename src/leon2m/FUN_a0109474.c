/* leon2m FUN_a0109474 @ 0xa0109474-0xa0109514 (40 words).
 * Sets (on != 0) or clears (on == 0) bit 7 of one hardware register chosen by sel: 1 = 0xcf011aa4,
 * 2 = 0xcf011aa8, 3 = 0xcf011aac; other sel values do nothing. A switch over three cases (compiled as a compare
 * chain). Called from FUN_a0096858, FUN_a012fcf4, FUN_a01302e0, FUN_a0130438, FUN_a0149e8c, FUN_a0149fb8, FUN_a014d474.
 */
#define REG_cf011aa4 (*(volatile unsigned int *)0xcf011aa4)
#define REG_cf011aa8 (*(volatile unsigned int *)0xcf011aa8)
#define REG_cf011aac (*(volatile unsigned int *)0xcf011aac)

void FUN_a0109474(unsigned char sel, unsigned char on)
{
    switch (sel) {
    case 1:
        if (on)
            REG_cf011aa4 |= 0x80;
        else
            REG_cf011aa4 &= ~0x80;
        break;
    case 2:
        if (on)
            REG_cf011aa8 |= 0x80;
        else
            REG_cf011aa8 &= ~0x80;
        break;
    case 3:
        if (on)
            REG_cf011aac |= 0x80;
        else
            REG_cf011aac &= ~0x80;
        break;
    }
}
