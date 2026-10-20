/* leon2m FUN_a01061c0 @ 0xa01061c0-0xa0106228 (11 words).
 * Writes one value to hardware register 0xcf00ed80, selected by sel: 0 writes 0, 1 writes 1, 2 writes 2, 3 writes 4
 * and 4 writes 0x10 (a jump table over the five cases). Any other sel leaves the register unchanged.
 * Called from FUN_a01518c8.
 */
#define REG_cf00ed80 (*(volatile unsigned int *)0xcf00ed80)

void FUN_a01061c0(unsigned char sel)
{
    switch (sel) {
    case 0:
        REG_cf00ed80 = 0;
        break;
    case 1:
        REG_cf00ed80 = 1;
        break;
    case 2:
        REG_cf00ed80 = 2;
        break;
    case 3:
        REG_cf00ed80 = 4;
        break;
    case 4:
        REG_cf00ed80 = 0x10;
        break;
    }
}
