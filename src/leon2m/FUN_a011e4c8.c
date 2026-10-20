/* FUN_a011e4c8: writes the byte v to one register selected by ch: ch 16..23 -> 0xcf016450, 0xcf016454,
 * 0xcf016458, 0xcf01645c, 0xcf016460, 0xcf016464, 0xcf016468, 0xcf01646c; ch 24 -> 0xcf01647c; any other ch
 * writes v to all nine registers. Caller: FUN_a014faa8.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a011e4c8(unsigned char ch, unsigned char v)
{
    switch (ch) {
    case 16:
        R(0xcf016450) = v;
        break;
    case 17:
        R(0xcf016454) = v;
        break;
    case 18:
        R(0xcf016458) = v;
        break;
    case 19:
        R(0xcf01645c) = v;
        break;
    case 20:
        R(0xcf016460) = v;
        break;
    case 21:
        R(0xcf016464) = v;
        break;
    case 22:
        R(0xcf016468) = v;
        break;
    case 23:
        R(0xcf01646c) = v;
        break;
    case 24:
        R(0xcf01647c) = v;
        break;
    default:
        R(0xcf016450) = v;
        R(0xcf016454) = v;
        R(0xcf016458) = v;
        R(0xcf01645c) = v;
        R(0xcf016460) = v;
        R(0xcf016464) = v;
        R(0xcf016468) = v;
        R(0xcf01646c) = v;
        R(0xcf01647c) = v;
        break;
    }
}
