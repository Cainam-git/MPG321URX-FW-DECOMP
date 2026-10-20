/* leon2m FUN_a014b900 @ 0xa014b900 (-mcpu=v8 -O2 -g)
 * The function checks a mode parameter (0 or 1), reads a corresponding status byte from a global, and if that status is 1, calls a function with a mode-specific code (2 or 3) and a zero argument. The structure uses nested ifs rather than early returns to match the branch layout.
 */
extern unsigned char DAT_a802e3fa;
extern unsigned char DAT_a802e3fc;
extern int FUN_a012f1ec();

void FUN_a014b900(unsigned char param_1)
{
    if (param_1 == 0) {
        if (DAT_a802e3fa == 1) {
            FUN_a012f1ec(2, 0);
        }
    } else if (param_1 == 1) {
        if (DAT_a802e3fc == 1) {
            FUN_a012f1ec(3, 0);
        }
    }
}
