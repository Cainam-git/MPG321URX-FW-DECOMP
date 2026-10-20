/* leon2s FUN_a00d36a4 @ 0xa00d36a4 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern unsigned char DAT_a8078c35;
extern unsigned char DAT_a8078c37;
extern unsigned char DAT_a8078c38;

void FUN_a00d36a4(void)
{
    if (DAT_a8078c38 > 1) {
        DAT_a8078c35 = (unsigned char)(1 << DAT_a8078c37) | DAT_a8078c35;
    } else {
        DAT_a8078c35 = 0;
    }
}
