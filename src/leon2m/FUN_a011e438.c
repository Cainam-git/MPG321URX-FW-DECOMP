/* FUN_a011e438: writes bit 3 of one register selected by ch with b & 1 (bits 0-2 and 4-7 kept, everything above
 * bit 7 cleared by the 0xf7 mask): ch 1..6 -> 0xcf016120, 0xcf016138, 0xcf016150, 0xcf016168, 0xcf016180,
 * 0xcf016198; other ch: nothing. Caller: FUN_a0129edc.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a011e438(unsigned char ch, unsigned char b)
{
    b &= 1;
    switch (ch) {
    case 1:
        R(0xcf016120) = (R(0xcf016120) & 0xf7) | (b << 3);
        break;
    case 2:
        R(0xcf016138) = (R(0xcf016138) & 0xf7) | (b << 3);
        break;
    case 3:
        R(0xcf016150) = (R(0xcf016150) & 0xf7) | (b << 3);
        break;
    case 4:
        R(0xcf016168) = (R(0xcf016168) & 0xf7) | (b << 3);
        break;
    case 5:
        R(0xcf016180) = (R(0xcf016180) & 0xf7) | (b << 3);
        break;
    case 6:
        R(0xcf016198) = (R(0xcf016198) & 0xf7) | (b << 3);
        break;
    }
}
