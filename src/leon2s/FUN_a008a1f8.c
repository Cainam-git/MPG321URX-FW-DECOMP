/* leon2s FUN_a008a1f8 @ 0xa008a1f8 (-mcpu=v8 -Os -g)
 * Writes 0x40 to register 0xCF011024 when p1 == 1; any other p1 returns without a write.
 * Source form: Ghidra's type and symbol names are kept.
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
