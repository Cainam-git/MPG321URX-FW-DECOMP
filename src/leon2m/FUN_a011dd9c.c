/* leon2m FUN_a011dd9c @ 0xa011dd9c-0xa011e028 (-mcpu=v8 -O3 -g). Called by FUN_a00da714, FUN_a014382c, FUN_a0148d34,
 * FUN_a014f998, FUN_a014fb84, FUN_a014fe78, FUN_a0150120 and FUN_a0150248.
 * Parameters (ch, v). Writes v & 3 and (unsigned short)v >> 2 to a register pair selected by ch (jump table):
 * ch 1..6: v & 3 to 0xcf016130 / 148 / 160 / 178 / 190 / 1a8 and v >> 2 to the word 4 bytes below;
 * ch 16..23: v & 3 to 0xcf016410 + 8 * (ch - 16) and v >> 2 to the word 4 bytes above;
 * ch 24, 25, 26: v & 3 to 0xcf016474, 0xcf0164a0, 0xcf0164cc and v >> 2 to the word 4 bytes above.
 * Other ch values write nothing.
 * Source form: the case order 1, 17..22, 26, 24, 2..6, 25, 23, 16 gives the firmware's block order and register names.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a011dd9c(unsigned char ch, unsigned int v)
{
    switch (ch) {
    case 1:
        R(0xcf016130) = v & 3;
        R(0xcf01612c) = (unsigned short)v >> 2;
        break;
    case 17:
        R(0xcf016418) = v & 3;
        R(0xcf01641c) = (unsigned short)v >> 2;
        break;
    case 18:
        R(0xcf016420) = v & 3;
        R(0xcf016424) = (unsigned short)v >> 2;
        break;
    case 19:
        R(0xcf016428) = v & 3;
        R(0xcf01642c) = (unsigned short)v >> 2;
        break;
    case 20:
        R(0xcf016430) = v & 3;
        R(0xcf016434) = (unsigned short)v >> 2;
        break;
    case 21:
        R(0xcf016438) = v & 3;
        R(0xcf01643c) = (unsigned short)v >> 2;
        break;
    case 22:
        R(0xcf016440) = v & 3;
        R(0xcf016444) = (unsigned short)v >> 2;
        break;
    case 26:
        R(0xcf0164cc) = v & 3;
        R(0xcf0164d0) = (unsigned short)v >> 2;
        break;
    case 24:
        R(0xcf016474) = v & 3;
        R(0xcf016478) = (unsigned short)v >> 2;
        break;
    case 2:
        R(0xcf016148) = v & 3;
        R(0xcf016144) = (unsigned short)v >> 2;
        break;
    case 3:
        R(0xcf016160) = v & 3;
        R(0xcf01615c) = (unsigned short)v >> 2;
        break;
    case 4:
        R(0xcf016178) = v & 3;
        R(0xcf016174) = (unsigned short)v >> 2;
        break;
    case 5:
        R(0xcf016190) = v & 3;
        R(0xcf01618c) = (unsigned short)v >> 2;
        break;
    case 6:
        R(0xcf0161a8) = v & 3;
        R(0xcf0161a4) = (unsigned short)v >> 2;
        break;
    case 25:
        R(0xcf0164a0) = v & 3;
        R(0xcf0164a4) = (unsigned short)v >> 2;
        break;
    case 23:
        R(0xcf016448) = v & 3;
        R(0xcf01644c) = (unsigned short)v >> 2;
        break;
    case 16:
        R(0xcf016410) = v & 3;
        R(0xcf016414) = (unsigned short)v >> 2;
        break;
    }
}
