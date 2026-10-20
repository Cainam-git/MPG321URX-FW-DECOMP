/* leon2m FUN_a015ea08 @ 0xa015ea08  MATCH (-mcpu=v8 -O2 -g)
 * Calls the function pointer _DAT_a802cfe4 with param_1 and returns its result when the pointer is non-null,
 * otherwise returns 0 (the branch skips directly to the return).
 */
extern int (*_DAT_a802cfe4)(int);

int FUN_a015ea08(int param_1)
{
    if (_DAT_a802cfe4 != 0) {
        return _DAT_a802cfe4(param_1);
    }
    return 0;
}
