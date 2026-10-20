/* FUN_a011e028: sets (en != 0) or clears bit 7 of one register selected by ch: ch 1..6 -> 0xcf016120, 0xcf016138,
 * 0xcf016150, 0xcf016168, 0xcf016180, 0xcf016198; ch 16..24 and 31 -> 0xcf016400; ch 25 -> 0xcf016494;
 * ch 26 -> 0xcf0164c0; any other ch -> all six registers 0xcf016120..0xcf016198 (bits 0-6 are kept, the
 * upper bits cleared by the 0x7f mask). Callers: FUN_a00fd558, FUN_a011d194, FUN_a014fb84.
 * Exact form: the bit value starts as a copy of en ('b = en; if (b) b = 0x80;'), which keeps the firmware's
 * branch instead of an if-converted flag; the switch lists cases 1..6, 16..24/31, 25, 26 and then default.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a011e028(unsigned char ch, unsigned char en)
{
    unsigned int b = en;

    if (b)
        b = 0x80;
    switch (ch) {
    case 1:
        R(0xcf016120) = (R(0xcf016120) & 0x7f) | b;
        break;
    case 2:
        R(0xcf016138) = (R(0xcf016138) & 0x7f) | b;
        break;
    case 3:
        R(0xcf016150) = (R(0xcf016150) & 0x7f) | b;
        break;
    case 4:
        R(0xcf016168) = (R(0xcf016168) & 0x7f) | b;
        break;
    case 5:
        R(0xcf016180) = (R(0xcf016180) & 0x7f) | b;
        break;
    case 6:
        R(0xcf016198) = (R(0xcf016198) & 0x7f) | b;
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
        R(0xcf016400) = (R(0xcf016400) & 0x7f) | b;
        break;
    case 25:
        R(0xcf016494) = (R(0xcf016494) & 0x7f) | b;
        break;
    case 26:
        R(0xcf0164c0) = (R(0xcf0164c0) & 0x7f) | b;
        break;
    default:
        R(0xcf016120) = (R(0xcf016120) & 0x7f) | b;
        R(0xcf016138) = (R(0xcf016138) & 0x7f) | b;
        R(0xcf016150) = (R(0xcf016150) & 0x7f) | b;
        R(0xcf016168) = (R(0xcf016168) & 0x7f) | b;
        R(0xcf016180) = (R(0xcf016180) & 0x7f) | b;
        R(0xcf016198) = (R(0xcf016198) & 0x7f) | b;
        break;
    }
}
