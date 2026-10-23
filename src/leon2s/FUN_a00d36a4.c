/* leon2s FUN_a00d36a4 @ 0xa00d36a4 (-mcpu=v8 -Os -g)
 * When byte 0xA8078C38 > 1, sets bit number (byte 0xA8078C37) in byte 0xA8078C35; otherwise clears byte
 * 0xA8078C35.
 * Source form: Ghidra's type and symbol names are kept.
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
