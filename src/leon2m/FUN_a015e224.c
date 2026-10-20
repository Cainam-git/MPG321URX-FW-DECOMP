/* leon2m FUN_a015e224 @ 0xa015e224 (-mcpu=v8 -O2 -g)
 * Clears the word _DAT_a802e40c, calls FUN_a015e7d8(param_2), and if that returns -1 (0xFFFFFFFF) while
 * _DAT_a802e40c has become non-zero, stores _DAT_a802e40c to *param_1. Returns the result of FUN_a015e7d8.
 */
extern unsigned int _DAT_a802e40c; /* 0xa802e40c */
extern int FUN_a015e7d8(int param); /* 0xa015e7d8 */

int FUN_a015e224(unsigned int *param_1, int param_2)
{
    int uVar1;

    _DAT_a802e40c = 0;
    uVar1 = FUN_a015e7d8(param_2);
    if ((uVar1 == 0xffffffff) && (_DAT_a802e40c != 0)) {
        *param_1 = _DAT_a802e40c;
    }
    return uVar1;
}
