/* leon2s FUN_a0084c74 @ 0xa0084c74  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern int FUN_a0083ed0();
extern int FUN_a00a7614();

int FUN_a0084c74(unsigned char param_1, unsigned char param_2)
{
    unsigned char t = FUN_a0083ed0(param_1) & 0xff;
    return FUN_a00a7614(t, 0xab, param_2);
}
