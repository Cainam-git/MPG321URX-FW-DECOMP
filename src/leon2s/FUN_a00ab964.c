/* leon2s FUN_a00ab964 @ 0xa00ab964-0xa00aba14, flags -mcpu=v8 -Os -g.
 * Leaf wrapper; switch on the low byte of param_2 (jump table 0xa00ab93c, cases 0..9):
 * 0 -> FUN_a00a6fc0(p1, 5, 8), 1 and 2 -> (p1, 5, 0x10), 3 -> (p1, 5, 0x40), 9 -> (p1, 5, 4);
 * 6 -> FUN_a00a6c00(p1, 0x4e1, 4), 7 -> (p1, 0x4e0, 8), 8 -> (p1, 0x4e1, 1); 4, 5 and others return.
 * Each case masks p1 to its low byte for the call; the calls are tail calls (mov %o7,%g1 / call / mov %g1,%o7).
 * Source form: case 0 is written after case 6 (the firmware places its block there).
 */
extern void FUN_a00a6fc0(unsigned char, unsigned short, unsigned int);
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned int);

void FUN_a00ab964(unsigned int param_1, unsigned char param_2)
{
    switch (param_2) {
    case 1:
    case 2:
        FUN_a00a6fc0(param_1, 5, 0x10);
        break;
    case 3:
        FUN_a00a6fc0(param_1, 5, 0x40);
        break;
    case 6:
        FUN_a00a6c00(param_1, 0x4e1, 4);
        break;
    case 0:
        FUN_a00a6fc0(param_1, 5, 8);
        break;
    case 7:
        FUN_a00a6c00(param_1, 0x4e0, 8);
        break;
    case 8:
        FUN_a00a6c00(param_1, 0x4e1, 1);
        break;
    case 9:
        FUN_a00a6fc0(param_1, 5, 4);
        break;
    }
}
