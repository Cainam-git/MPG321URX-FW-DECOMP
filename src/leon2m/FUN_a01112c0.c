/* leon2m FUN_a01112c0 @ 0xa01112c0-0xa011149c (119 words, leaf with a stack frame), flags -mcpu=v8 -O3 -g.
 * No direct callers. Parameters (c, k). A local 13-byte table t = {1..8, 10..14}; v = t[k] is written to six
 * registers per group: c 0 -> 0xcf01cd30..0xcf01cd44, c 1 -> 0xcf01cd48, 0xcf01cd4c, 0xcf01cdbc..0xcf01cdc8,
 * c 2 -> 0xcf01ce58..0xcf01ce64, 0xcf01ced4, 0xcf01ced8, c 3 -> 0xcf01cedc..0xcf01cef0; c 4 writes all four groups.
 * Source form: each group reads t[k] once into the unsigned char v and then writes the six registers.
 */
#define REG(a) (*(volatile unsigned int *)(a))

void FUN_a01112c0(unsigned int c, unsigned char k)
{
    unsigned char t[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14 };
    unsigned char v;

    if (c == 0 || c == 4) {
        v = t[k];
        REG(0xcf01cd30) = v;
        REG(0xcf01cd34) = v;
        REG(0xcf01cd38) = v;
        REG(0xcf01cd3c) = v;
        REG(0xcf01cd40) = v;
        REG(0xcf01cd44) = v;
    }
    if (c == 1 || c == 4) {
        v = t[k];
        REG(0xcf01cd48) = v;
        REG(0xcf01cd4c) = v;
        REG(0xcf01cdbc) = v;
        REG(0xcf01cdc0) = v;
        REG(0xcf01cdc4) = v;
        REG(0xcf01cdc8) = v;
    }
    if (c == 2 || c == 4) {
        v = t[k];
        REG(0xcf01ce58) = v;
        REG(0xcf01ce5c) = v;
        REG(0xcf01ce60) = v;
        REG(0xcf01ce64) = v;
        REG(0xcf01ced4) = v;
        REG(0xcf01ced8) = v;
    }
    if (c == 3 || c == 4) {
        v = t[k];
        REG(0xcf01cedc) = v;
        REG(0xcf01cee0) = v;
        REG(0xcf01cee4) = v;
        REG(0xcf01cee8) = v;
        REG(0xcf01ceec) = v;
        REG(0xcf01cef0) = v;
    }
}
