/* sys_ddr_train_and_set_vref  (FUN_a00eec44)
 *
 * Train the reference voltage and apply it.
 * Name basis: derived - sys_ddr_train_vref, then sys_ddr_set_vref; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00eec44 @ 0xa00eec44, flags -mcpu=v8 -O2 -g.
 * Source form: the seventh and eighth arguments of sys_ddr_train_vref (arg5 and arg6) go on the stack; the
 * callees are declared without parameter lists.
 */
extern int sys_ddr_train_vref(); /* 0xa00ee1e8 */
extern int sys_ddr_set_vref(); /* 0xa00ee964 */

/*
 * Run sys_ddr_train_vref (with 4 as its sixth argument) and, when it succeeds and `mode` is 3, apply the result
 * with sys_ddr_set_vref. Returns 0 on success, -1 otherwise. The arguments are passed on; their meaning is
 * not shown here. Nothing in the image calls it.
 */
unsigned int sys_ddr_train_and_set_vref(int unit, unsigned int arg2, unsigned int arg3,
                          int mode, unsigned int arg5, unsigned int arg6,
                          unsigned int arg7, unsigned int arg8, unsigned int arg9)
{
    unsigned int train_result;
    unsigned int result;

    train_result = sys_ddr_train_vref(unit, arg2, arg3, mode, arg9, 4, arg5, arg6);
    result = 0xffffffff;
    if (-1 < (int)train_result) {
        if (mode == 3) {
            train_result = sys_ddr_set_vref(unit, arg2, arg3, arg9, arg5, arg7, arg8);
            if (train_result == 0) {
                result = 0;
            }
        } else {
            result = 0;
        }
    }
    return result;
}
