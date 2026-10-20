/* FUN_a011e8fc: sets (sel == 1) or clears bit (ch - 0x10) of register 0xcf016470 for ch 0x10..0x17; other ch
 * values write nothing. Caller: FUN_a014fd34. One switch per arm (two jump tables in the firmware).
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a011e8fc(unsigned char ch, unsigned char sel)
{
    if (sel == 1) {
        switch (ch) {
        case 0x10:
            R(0xcf016470) |= 1;
            break;
        case 0x11:
            R(0xcf016470) |= 2;
            break;
        case 0x12:
            R(0xcf016470) |= 4;
            break;
        case 0x13:
            R(0xcf016470) |= 8;
            break;
        case 0x14:
            R(0xcf016470) |= 0x10;
            break;
        case 0x15:
            R(0xcf016470) |= 0x20;
            break;
        case 0x16:
            R(0xcf016470) |= 0x40;
            break;
        case 0x17:
            R(0xcf016470) |= 0x80;
            break;
        }
    } else {
        switch (ch) {
        case 0x10:
            R(0xcf016470) &= ~1;
            break;
        case 0x11:
            R(0xcf016470) &= ~2;
            break;
        case 0x12:
            R(0xcf016470) &= ~4;
            break;
        case 0x13:
            R(0xcf016470) &= ~8;
            break;
        case 0x14:
            R(0xcf016470) &= ~0x10;
            break;
        case 0x15:
            R(0xcf016470) &= ~0x20;
            break;
        case 0x16:
            R(0xcf016470) &= ~0x40;
            break;
        case 0x17:
            R(0xcf016470) &= ~0x80;
            break;
        }
    }
}
