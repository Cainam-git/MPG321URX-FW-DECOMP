/* leon2s FUN_a0091918 @ 0xa0091918  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern unsigned char ARR_a807d580[];

void FUN_a0091918(unsigned int param_1, unsigned char param_2)
{
    ARR_a807d580[(param_1 & 0xff) * 28 + 0x15] = param_2;
}
