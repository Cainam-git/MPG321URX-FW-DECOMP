/* leon2m FUN_a014bc58 @ 0xa014bc58 (-mcpu=v8 -O2 -g)
 * Stores p in word 0xA802E408, then p 0 -> FUN_a0150120(0, 0), 1 -> FUN_a0150120(1, 0), 2 or 3 -> FUN_a0150120(1, 1);
 * other values make no call.
 */
/* FUN_a014bc58 at 0xa014bc58 */
extern unsigned int _DAT_a802e408;      /* 0xa802e408 */
extern int FUN_a0150120(int, int);      /* 0xa0150120 */

void FUN_a014bc58(unsigned int param_1)
{
    _DAT_a802e408 = param_1;

    if (param_1 == 0) {
        FUN_a0150120(0, 0);
    } else if (param_1 == 1) {
        FUN_a0150120(1, 0);
    } else {
        if (param_1 == 2) {
            FUN_a0150120(1, 1);
        } else if (param_1 == 3) {
            FUN_a0150120(1, 1);
        }
    }
}
