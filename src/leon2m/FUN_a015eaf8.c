/* leon2m FUN_a015eaf8 @ 0xa015eaf8 (-mcpu=v8 -O2 -g)
 * Calls the function pointer at 0xA802CFD4 with (param_1, param_2) and returns its result when the pointer is
 * non-null; returns 0 otherwise. Same shape as FUN_a015e9a4 (pointer at 0xA802CFF0) and the one-argument pointer
 * callers FUN_a015e9d8..FUN_a015eac8 between them.
 */
extern int (*_DAT_a802cfd4)(int, int);

int FUN_a015eaf8(int param_1, int param_2)
{
    int r = 0;
    if (_DAT_a802cfd4 != 0) {
        r = _DAT_a802cfd4(param_1, param_2);
    }
    return r;
}
