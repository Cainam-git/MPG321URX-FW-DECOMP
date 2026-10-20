/* leon2m FUN_a015eaf8 @ 0xa015eaf8 (-mcpu=v8 -O2 -g)
 * Calls the function pointer at 0xa802cfd4 with (param_1, param_2) and returns its result when the pointer is
 * non-null; returns 0 otherwise. `int r = 0`, overwritten only on the call path, gives the single ret; restore
 * with clr %i0 in the branch delay slot and mov %o0, %i0 after the call.
 */
/* Function pointer global at 0xa802cfd4 */
extern int (*_DAT_a802cfd4)(int, int);

int FUN_a015eaf8(int param_1, int param_2)
{
    int r = 0;
    if (_DAT_a802cfd4 != 0) {
        r = _DAT_a802cfd4(param_1, param_2);
    }
    return r;
}
