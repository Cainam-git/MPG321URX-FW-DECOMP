/* leon2s FUN_a00a20a8 @ 0xa00a20a8 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern unsigned char DAT_a807d680[];

unsigned char FUN_a00a20a8(unsigned int param_1)
{
    return DAT_a807d680[(param_1 & 0xff) * 0xb0 + 1];
}
