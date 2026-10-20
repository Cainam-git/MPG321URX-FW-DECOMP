/* FUN_a014bd0c: sel 0: FUN_a0139968(0); sel 1: FUN_a0139968(1) then FUN_a013aa38(1); sel 2: FUN_a0139968(3) then
 * FUN_a013aa38(1); sel 3: FUN_a0139968(2); other sel values do nothing. Callers include FUN_a0080490,
 * FUN_a00d8034, FUN_a00d9120. Written as an if/else chain (the firmware tests 0, 1, 2, 3 in order).
 */
extern void FUN_a0139968(unsigned int mode);
extern void FUN_a013aa38(unsigned char on);

void FUN_a014bd0c(unsigned char sel)
{
    if (sel == 0) {
        FUN_a0139968(0);
    } else if (sel == 1) {
        FUN_a0139968(1);
        FUN_a013aa38(1);
    } else if (sel == 2) {
        FUN_a0139968(3);
        FUN_a013aa38(1);
    } else if (sel == 3) {
        FUN_a0139968(2);
    }
}
