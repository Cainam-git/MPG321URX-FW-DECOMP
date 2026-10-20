/* leon2m FUN_a0132a40 @ 0xa0132a40 (-mcpu=v8 -O2 -g)
 * Calls FUN_a01398bc(1) if the parameter is 0 and FUN_a01398bc(0) if it is 1; any other value does nothing. No
 * return value; the call is a normal call inside a register window, not a tail call.
 */
extern int FUN_a01398bc();

void FUN_a0132a40(unsigned int param_1)
{
    if (param_1 == 0) {
        FUN_a01398bc(1);
    } else if (param_1 == 1) {
        FUN_a01398bc(0);
    }
}
