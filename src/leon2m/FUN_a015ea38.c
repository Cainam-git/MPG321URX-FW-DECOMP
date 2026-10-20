/* leon2m FUN_a015ea38 @ 0xa015ea38 (-mcpu=v8 -O2 -g)
 * If the function pointer _DAT_a802cfe8 is non-NULL, calls it with param_1 and returns its result; otherwise
 * returns 0. The second parameter is unused. The branch for the NULL case targets the ret at 0xa015ea60.
 */
extern int (*_DAT_a802cfe8)(int);
int FUN_a015ea38(int param_1, int param_2)
{
    if (_DAT_a802cfe8 != 0) {
        return _DAT_a802cfe8(param_1);
    }
    return 0;
}
