/* FUN_a008d920 (leon2s 0xa008d920-0xa008d980, 96 bytes), flags -mcpu=v8 -Os -g.
 * Reads FUN_a00a7fd8(param_1 & 0xff, 1, 6), clears bits 2..3, sets bit 2 (param_2 == 10) or bit 3
 * (param_2 == 12); other values leave both clear. Writes the byte back with
 * FUN_a00a8054(param_1 & 0xff, 1, 6, value). Same source form as FUN_a008d980 (switch on param_2).
 */
extern unsigned int FUN_a00a7fd8(unsigned int, unsigned short, unsigned short);
extern void FUN_a00a8054(unsigned int, unsigned int, unsigned short, unsigned int);

void FUN_a008d920(unsigned int param_1, unsigned char param_2)
{
    unsigned char uVar1;

    param_1 = param_1 & 0xff;
    uVar1 = FUN_a00a7fd8(param_1, 1, 6);
    uVar1 = uVar1 & 0xfffffff3;

    switch (param_2) {
    case 10:
        uVar1 = uVar1 | 4;
        break;
    case 12:
        uVar1 = uVar1 | 8;
        break;
    }

    FUN_a00a8054(param_1, 1, 6, uVar1 & 0xff);
}
