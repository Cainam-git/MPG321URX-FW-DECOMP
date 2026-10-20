/* FUN_a008d9d4 (leon2s 0xa008d9d4-0xa008da34, 96 bytes), flags -mcpu=v8 -Os -g.
 * Reads FUN_a00a7fd8(param_1 & 0xff, 1, 0x7f), clears bits 4..5, sets bit 4 (param_2 == 10) or bit 5
 * (param_2 == 12); other values leave both clear. Writes the byte back with
 * FUN_a00a8054(param_1 & 0xff, 1, 0x7f, value). Same source form as FUN_a008d920 (switch on param_2).
 */
extern unsigned int FUN_a00a7fd8(unsigned int, unsigned short, unsigned short);
extern void FUN_a00a8054(unsigned int, unsigned int, unsigned short, unsigned int);

void FUN_a008d9d4(unsigned int param_1, unsigned char param_2)
{
    unsigned char uVar1;

    param_1 = param_1 & 0xff;
    uVar1 = FUN_a00a7fd8(param_1, 1, 0x7f);
    uVar1 = uVar1 & 0xffffffcf;

    switch (param_2) {
    case 10:
        uVar1 = uVar1 | 0x10;
        break;
    case 12:
        uVar1 = uVar1 | 0x20;
        break;
    }

    FUN_a00a8054(param_1, 1, 0x7f, uVar1 & 0xff);
}
