/* leon2s FUN_a00858f0 @ 0xa00858f0  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern unsigned char ARR_a807a928[];

unsigned char FUN_a00858f0(unsigned int param_1)
{
    return ARR_a807a928[(param_1 & 0xff) * 40 + 1];
}
