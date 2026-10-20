/* FUN_a0118628: sets bit 0 of register 0xcf012e44 when m == 1 and clears it otherwise, then writes the
 * low two bits of register 0xcf012e40 (the value is masked with 0xfc first): m 1 or 2 -> 1, m 3 -> 2,
 * m 4 -> 3, any other m -> 0. Called from FUN_a014110c and FUN_a0149bf0.
 * Exact form: a switch with the default arm written first and separate (identical) bodies for cases 1 and 2;
 * this case order gives the firmware's register choice and block layout.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a0118628(unsigned int m)
{
    if (m == 1)
        R(0xcf012e44) |= 1;
    else
        R(0xcf012e44) &= ~1;

    switch (m) {
    default:
        R(0xcf012e40) = R(0xcf012e40) & 0xfc;
        break;
    case 1:
        R(0xcf012e40) = (R(0xcf012e40) & 0xfc) | 1;
        break;
    case 2:
        R(0xcf012e40) = (R(0xcf012e40) & 0xfc) | 1;
        break;
    case 3:
        R(0xcf012e40) = (R(0xcf012e40) & 0xfc) | 2;
        break;
    case 4:
        R(0xcf012e40) = (R(0xcf012e40) & 0xfc) | 3;
        break;
    }
}
