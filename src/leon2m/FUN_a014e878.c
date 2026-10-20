/* FUN_a014e878: mode 0: FUN_a00fc15c(0) then FUN_a00fbf5c(0); mode 1: FUN_a00fbf5c(1) then FUN_a00fc15c(0);
 * mode 2: FUN_a00fbf5c(1) then FUN_a00fc15c(1); other modes do nothing. Callers include FUN_a00db690,
 * FUN_a00db738, FUN_a00dbcf0, FUN_a00dc3dc. Written as an if/else chain.
 */
extern void FUN_a00fc15c(unsigned char on);
extern void FUN_a00fbf5c(unsigned char on);

void FUN_a014e878(unsigned char mode)
{
    if (mode == 0) {
        FUN_a00fc15c(0);
        FUN_a00fbf5c(0);
    } else if (mode == 1) {
        FUN_a00fbf5c(1);
        FUN_a00fc15c(0);
    } else if (mode == 2) {
        FUN_a00fbf5c(1);
        FUN_a00fc15c(1);
    }
}
