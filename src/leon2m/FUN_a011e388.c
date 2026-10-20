/* FUN_a011e388: writes bit 6 of one register selected by ch with b & 1 (bits 0-5 and 7 kept, everything above
 * bit 7 cleared by the 0xbf mask): ch 1..6 -> 0xcf016120, 0xcf016138, 0xcf016150, 0xcf016168, 0xcf016180,
 * 0xcf016198; ch 16..24 and 31 -> 0xcf016400; ch 25 -> 0xcf016494; ch 26 -> 0xcf0164c0; other ch: nothing.
 * Same register selection as FUN_a011e028. Caller: FUN_a0150120.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a011e388(unsigned char ch, unsigned char b)
{
    b &= 1;
    switch (ch) {
    case 1:
        R(0xcf016120) = (R(0xcf016120) & 0xbf) | (b << 6);
        break;
    case 2:
        R(0xcf016138) = (R(0xcf016138) & 0xbf) | (b << 6);
        break;
    case 3:
        R(0xcf016150) = (R(0xcf016150) & 0xbf) | (b << 6);
        break;
    case 4:
        R(0xcf016168) = (R(0xcf016168) & 0xbf) | (b << 6);
        break;
    case 5:
        R(0xcf016180) = (R(0xcf016180) & 0xbf) | (b << 6);
        break;
    case 6:
        R(0xcf016198) = (R(0xcf016198) & 0xbf) | (b << 6);
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
        R(0xcf016400) = (R(0xcf016400) & 0xbf) | (b << 6);
        break;
    case 25:
        R(0xcf016494) = (R(0xcf016494) & 0xbf) | (b << 6);
        break;
    case 26:
        R(0xcf0164c0) = (R(0xcf0164c0) & 0xbf) | (b << 6);
        break;
    }
}
