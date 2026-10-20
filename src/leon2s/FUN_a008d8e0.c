/* leon2s FUN_a008d8e0 @ 0xa008d8e0  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
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
