/* FUN_a011e148: masks one register selected by ch with 0x7c (clears bits 0, 1 and 7 and everything above
 * bit 7): ch 1..6 -> 0xcf016120, 0xcf016138, 0xcf016150, 0xcf016168, 0xcf016180, 0xcf016198; ch 16..24 and 31
 * -> 0xcf016400; ch 25 -> 0xcf016494; ch 26 -> 0xcf0164c0; any other ch -> the four registers
 * 0xcf016120..0xcf016168. Same register selection as FUN_a011e028. Callers: FUN_a014fb84, FUN_a0150120.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a011e148(unsigned char ch)
{
    switch (ch) {
    case 1:
        R(0xcf016120) &= 0x7c;
        break;
    case 2:
        R(0xcf016138) &= 0x7c;
        break;
    case 3:
        R(0xcf016150) &= 0x7c;
        break;
    case 4:
        R(0xcf016168) &= 0x7c;
        break;
    case 5:
        R(0xcf016180) &= 0x7c;
        break;
    case 6:
        R(0xcf016198) &= 0x7c;
        break;
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 31:
        R(0xcf016400) &= 0x7c;
        break;
    case 25:
        R(0xcf016494) &= 0x7c;
        break;
    case 26:
        R(0xcf0164c0) &= 0x7c;
        break;
    default:
        R(0xcf016120) &= 0x7c;
        R(0xcf016138) &= 0x7c;
        R(0xcf016150) &= 0x7c;
        R(0xcf016168) &= 0x7c;
        break;
    }
}
