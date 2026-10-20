/* leon2s FUN_a0090e6c @ 0xa0090e6c  MATCH (-mcpu=v8 -Os -g, twin)
 * Twin of FUN_a00b1224: same code, constants swapped; byte-exact.
 * See FUN_a00b1224 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern void FUN_a00a67b8(unsigned int, unsigned short, unsigned int, unsigned int);

void FUN_a0090e6c(unsigned char param_1, unsigned char param_2)
{
    switch (param_2) {
    case 0:
        FUN_a00a67b8(param_1, 0x126, 0x1, 0);
        FUN_a00a67b8(param_1, 0x126, 0x4, 0);
        break;
    case 2:
        FUN_a00a67b8(param_1, 0x126, 0x1, 1);
        FUN_a00a67b8(param_1, 0x126, 0x4, 0);
        break;
    case 1:
        FUN_a00a67b8(param_1, 0x126, 0x1, 1);
        FUN_a00a67b8(param_1, 0x126, 0x4, 1);
        break;
    }
}
