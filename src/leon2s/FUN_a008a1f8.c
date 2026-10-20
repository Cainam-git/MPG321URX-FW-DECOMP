/* leon2s FUN_a008a1f8 @ 0xa008a1f8  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
#define _DAT_cf011024 (*(volatile unsigned int *)0xcf011024)

void FUN_a008a1f8(unsigned char param_1)
{
    if (param_1 == 0) {
        return;
    }
    if (param_1 != 1) {
        return;
    }
    _DAT_cf011024 = 0x40;
}
