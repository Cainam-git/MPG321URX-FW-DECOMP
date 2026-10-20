/* leon2m FUN_a00eec44 @ 0xa00eec44  MATCH (-mcpu=v8 -O2 -g)
 * Calls FUN_a00ee1e8(param_1, param_2, param_3, param_4, param_9, 4, param_5, param_6); param_5 and param_6 are
 * the 7th and 8th arguments and go on the stack ('st %i5, [%sp+0x60]'). Returns 0 when that result is >= 0 and
 * either param_4 != 3 or FUN_a00ee964(param_1, param_2, param_3, param_9, param_5, param_7, param_8) returns 0;
 * otherwise returns -1.
 */
extern int FUN_a00ee1e8(); /* 0xa00ee1e8 */
extern int FUN_a00ee964(); /* 0xa00ee964 */

unsigned int FUN_a00eec44(int param_1, unsigned int param_2, unsigned int param_3,
                          int param_4, unsigned int param_5, unsigned int param_6,
                          unsigned int param_7, unsigned int param_8, unsigned int param_9)
{
    unsigned int uVar1;
    unsigned int uVar2;

    uVar1 = FUN_a00ee1e8(param_1, param_2, param_3, param_4, param_9, 4, param_5, param_6);
    uVar2 = 0xffffffff;
    if (-1 < (int)uVar1) {
        if (param_4 == 3) {
            uVar1 = FUN_a00ee964(param_1, param_2, param_3, param_9, param_5, param_7, param_8);
            if (uVar1 == 0) {
                uVar2 = 0;
            }
        } else {
            uVar2 = 0;
        }
    }
    return uVar2;
}
