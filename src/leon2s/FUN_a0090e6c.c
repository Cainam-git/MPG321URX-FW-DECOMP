/* leon2s FUN_a0090e6c @ 0xa0090e6c (-mcpu=v8 -Os -g)
 * Calls FUN_a00a67b8(p1, 0x126, 1, a) and FUN_a00a67b8(p1, 0x126, 4, b) with (a, b) = (0, 0) for p2 == 0, (1, 0)
 * for p2 == 2 and (1, 1) for p2 == 1; other p2 make no call. Same code as FUN_a00b1224 with other constants.
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
