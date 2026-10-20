/* leon2m FUN_a015eac8 @ 0xa015eac8  MATCH (-mcpu=v8 -O2 -g, twin)
 * Twin of FUN_a015e9d8: same code, constants swapped; byte-exact.
 */
/* Global function pointer at 0xa802cfd8 (DRAM) */
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
