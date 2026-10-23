/* leon2s FUN_a00aa45c @ 0xa00aa45c (-mcpu=v8 -Os -g)
 * Calls FUN_a00a7bf8(p1, 9, 8, 1) when p2 == 1, otherwise FUN_a00a7bf8(p1, 9, 8, 0).
 * Source form: Ghidra's type and symbol names are kept.
 */
extern int FUN_a00a7bf8();

void FUN_a00aa45c(unsigned char param_1, unsigned char param_2)
{
    if (param_2 == 1) {
        FUN_a00a7bf8(param_1, 9, 8, 1);
    } else {
        FUN_a00a7bf8(param_1, 9, 8, 0);
    }
}
