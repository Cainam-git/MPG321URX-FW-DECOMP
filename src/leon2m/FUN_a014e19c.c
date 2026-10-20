/* leon2m FUN_a014e19c @ 0xa014e19c (-mcpu=v8 -Os -g)
 * Tests the low byte of param_1. If it is non-zero, calls FUN_a010afac and tail-calls FUN_a010b17c with the
 * incoming arguments; if it is zero, calls FUN_a010afc8 and tail-calls FUN_a010b198 with them. The non-zero path
 * is the fall-through and the zero path the branch target, as in the firmware.
 */
extern int FUN_a010afac(); /* 0xa010afac */
extern int FUN_a010afc8(); /* 0xa010afc8 */
extern int FUN_a010b17c(); /* 0xa010b17c */
extern int FUN_a010b198(); /* 0xa010b198 */

void FUN_a014e19c(unsigned int param_1, unsigned int param_2, unsigned int param_3,
                  unsigned int param_4, unsigned int param_5, unsigned int param_6)
{
    if ((param_1 & 0xff) != 0) {
        FUN_a010afac();
        FUN_a010b17c(param_1, param_2, param_3, param_4, param_5, param_6);
        return;
    }
    FUN_a010afc8();
    FUN_a010b198(param_1, param_2, param_3, param_4, param_5, param_6);
}
