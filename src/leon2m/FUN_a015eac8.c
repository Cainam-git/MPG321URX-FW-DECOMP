/* leon2m FUN_a015eac8 @ 0xa015eac8 (-mcpu=v8 -O2 -g)
 * Calls the function pointer in word 0xA802CFD8 with p1 and returns its result when the pointer is not null;
 * otherwise returns 0. Same code as FUN_a015e9d8 with other constants.
 */
/* Global function pointer at 0xa802cfd8 */
typedef int (*code)(int);
extern code _DAT_a802cfd8;

int FUN_a015eac8(int param_1)
{
    int result;
    result = 0;
    if (_DAT_a802cfd8 != 0) {
        result = _DAT_a802cfd8(param_1);
    }
    return result;
}
