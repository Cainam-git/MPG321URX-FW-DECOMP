/* leon2s FUN_a008d980 @ 0xa008d980  MATCH (-mcpu=v8 -Os -g)
 * Reads FUN_a00a7fd8(param_1 & 0xFF, 1, 5), sets bits 2..3 to 10b (param_2 == 1), 11b (param_2 == 2) or 01b (other
 * values) and writes the byte back with FUN_a00a8054(param_1 & 0xFF, 1, 5, value). The switch gives the target's
 * be for case 1 and be,a for case 2.
 */
extern unsigned int FUN_a00a7fd8(unsigned int, unsigned short, unsigned short);
extern void FUN_a00a8054(unsigned int, unsigned int, unsigned short, unsigned int);

void FUN_a008d980(unsigned int param_1, unsigned char param_2)
{
    unsigned char uVar1;

    param_1 = param_1 & 0xff;
    uVar1 = FUN_a00a7fd8(param_1, 1, 5);
    uVar1 = uVar1 & 0xfffffff3;

    switch (param_2) {
    case 1:
        uVar1 = uVar1 | 8;
        break;
    case 2:
        uVar1 = uVar1 | 0xc;
        break;
    default:
        uVar1 = uVar1 | 4;
        break;
    }

    FUN_a00a8054(param_1, 1, 5, uVar1 & 0xff);
}
