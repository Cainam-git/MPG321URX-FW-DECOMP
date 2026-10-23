/* leon2s FUN_a008d8e0 @ 0xa008d8e0 (-mcpu=v8 -Os -g)
 * Calls FUN_a00a8054(p1, 1, 0x7c, 0xf) when p2 == 1, otherwise FUN_a00a8054(p1, 1, 0x7c, 0).
 * Source form: Ghidra's type and symbol names are kept.
 */
extern int FUN_a00a8054();

void FUN_a008d8e0(unsigned char param_1, unsigned char param_2)
{
    if (param_2 == 1) {
        FUN_a00a8054(param_1, 1, 0x7c, 0xf);
    } else {
        FUN_a00a8054(param_1, 1, 0x7c, 0);
    }
}
