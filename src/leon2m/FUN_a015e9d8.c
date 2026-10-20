/* leon2m FUN_a015e9d8 @ 0xa015e9d8  MATCH (-mcpu=v8 -O2 -g)
 * Calls the function pointer stored at 0xA802CFEC with param_1 and returns its result; returns 0 when the pointer
 * is NULL.
 */
/* Global function pointer at 0xa802cfec (DRAM) */
typedef int (*code)(int);
extern code _DAT_a802cfec;

int FUN_a015e9d8(int param_1)
{
    int result;
    result = 0;
    if (_DAT_a802cfec != 0) {
        result = _DAT_a802cfec(param_1);
    }
    return result;
}
