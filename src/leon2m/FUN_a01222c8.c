/* leon2m FUN_a01222c8 @ 0xa01222c8-0xa01223b0 (58 words), flags -mcpu=v8 -O3 -g, leaf.
 * From the active row DAT_a802d6a4 (byte +7, byte +6) writes the registers 0xcf00eb40..0xcf00eb60:
 * 0xcf00eb40 = 2 for byte +7 == 10, 1 for 8, else 3; 0xcf00eb44 = 0, eb48 = 4, eb4c = 0, eb50 = 0;
 * 0xcf00eb54 = 5 for byte +6 9 or 10, 1 for 5..8, else 7 (jump table 0xa0121f28); 0xcf00eb58 = 7;
 * 0xcf00eb60 &= 0xfc; 0xcf00eb5c = 0. volatile: hardware registers only.
 * Source form: the same statements as the register block in the middle of FUN_a01227f0 (two-level if for
 * 0xcf00eb40, one case per value of byte +6 in the order 10, 9, 8, 7, 6, 5, default).
 */
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned char *DAT_a802d6a4;

void FUN_a01222c8(void)
{
    if (DAT_a802d6a4[7] == 10)
        R(0xcf00eb40) = 2;
    else if (DAT_a802d6a4[7] == 8)
        R(0xcf00eb40) = 1;
    else
        R(0xcf00eb40) = 3;
    R(0xcf00eb44) = 0;
    R(0xcf00eb48) = 4;
    R(0xcf00eb4c) = 0;
    R(0xcf00eb50) = 0;
    switch (DAT_a802d6a4[6]) {
    case 10:
        R(0xcf00eb54) = 5;
        break;
    case 9:
        R(0xcf00eb54) = 5;
        break;
    case 8:
        R(0xcf00eb54) = 1;
        break;
    case 7:
        R(0xcf00eb54) = 1;
        break;
    case 6:
        R(0xcf00eb54) = 1;
        break;
    case 5:
        R(0xcf00eb54) = 1;
        break;
    default:
        R(0xcf00eb54) = 7;
        break;
    }
    R(0xcf00eb58) = 7;
    R(0xcf00eb60) = R(0xcf00eb60) & 0xfc;
    R(0xcf00eb5c) = 0;
}
