/* leon2s FUN_a0075360 @ 0xa0075360 (-mcpu=v8 -Os)
 * Sets up register block 0x3630 for one HDMI port (param_1 = port): clears/sets its bit fields
 * through FUN_a00a7488(port, reg, mask, value), with the three upper fields depending on byte 2
 * of the port table entry DAT_a807d680[port != 2] (> 5 -> 0x4000/0x10000/0x40000), then runs
 * FUN_a00a7424 for items 0x1a..0x1e on that register. Note: the index is
 * (port != 2), not (port == 2): cmp %g0,%g1 ; addx %g0,0 computes (x != K).
 */
extern void FUN_a00a7488(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00a7424(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned char DAT_a807d680[][0xb0];

void FUN_a0075360(unsigned char param_1)
{
    int idx = (param_1 != 2);
    unsigned char flag = DAT_a807d680[idx][2];

    FUN_a00a7488(param_1, 0x3630, 0xfffffff0, 2);
    FUN_a00a7488(param_1, 0x3630, 0xffffff8f, 0x10);
    FUN_a00a7488(param_1, 0x3630, 0xfffff8ff, 0);
    FUN_a00a7488(param_1, 0x3630, 0xffffc7ff, 0);
    FUN_a00a7488(param_1, 0x3630, 0xff1fffff, 0);
    FUN_a00a7488(param_1, 0x3630, 0xff1fffff, 0);

    if (flag > 5) {
        FUN_a00a7488(param_1, 0x3630, 0xffff3fff, 0x4000);
        FUN_a00a7488(param_1, 0x3630, 0xfffcffff, 0x10000);
        FUN_a00a7488(param_1, 0x3630, 0xffe3ffff, 0x40000);
    } else {
        FUN_a00a7488(param_1, 0x3630, 0xffff3fff, 0);
        FUN_a00a7488(param_1, 0x3630, 0xfffcffff, 0);
        FUN_a00a7488(param_1, 0x3630, 0xffe3ffff, 0);
    }

    FUN_a00a7424(0, 0x1a, param_1, 0x3630);
    FUN_a00a7424(0, 0x1b, param_1, 0x3630);
    FUN_a00a7424(0, 0x1c, param_1, 0x3630);
    FUN_a00a7424(0, 0x1d, param_1, 0x3630);
    FUN_a00a7424(0, 0x1e, param_1, 0x3630);
}
