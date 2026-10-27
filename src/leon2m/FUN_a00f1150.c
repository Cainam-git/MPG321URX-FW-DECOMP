/* FUN_a00f1150 (leon2m 0xa00f1150-0xa00f11ac, 92 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears the byte DAT_a802b746 and the halfword DAT_a802b744 for c = 2 or 6, the byte DAT_a802b742 and the halfword
 * DAT_a802b740 for c = 3 or 7. Called by FUN_a013dc6c (2 calls). It lies between FUN_a00f1100 and FUN_a00f11ac.
 * Source form: an if/else chain over 2, 3, 6, 7 (GCC merges the identical arms).
 */
extern unsigned char DAT_a802b746, DAT_a802b742;
extern unsigned short DAT_a802b744, DAT_a802b740;

void FUN_a00f1150(unsigned char c)
{
    if (c == 2) {
        DAT_a802b746 = 0;
        DAT_a802b744 = 0;
    } else if (c == 3) {
        DAT_a802b742 = 0;
        DAT_a802b740 = 0;
    } else if (c == 6) {
        DAT_a802b746 = 0;
        DAT_a802b744 = 0;
    } else if (c == 7) {
        DAT_a802b742 = 0;
        DAT_a802b740 = 0;
    }
}
