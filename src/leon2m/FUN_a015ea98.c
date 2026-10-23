/* leon2m FUN_a015ea98 @ 0xa015ea98 (-mcpu=v8 -O2 -g)
 * Calls the function pointer in word 0xA802CFDC with p1 and returns its result when the pointer is not null;
 * otherwise returns 0. Same code as FUN_a015e9d8 with other constants.
 */
/* Global function pointer at 0xa802cfdc */
typedef int (*code)(int);
extern code _DAT_a802cfdc;

int FUN_a015ea98(int param_1)
{
    int result;
    result = 0;
    if (_DAT_a802cfdc != 0) {
        result = _DAT_a802cfdc(param_1);
    }
    return result;
}
