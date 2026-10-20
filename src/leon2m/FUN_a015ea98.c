/* leon2m FUN_a015ea98 @ 0xa015ea98  MATCH (-mcpu=v8 -O2 -g, twin)
 * Twin of FUN_a015e9d8: same code, constants swapped; byte-exact.
 */
/* Global function pointer at 0xa802cfdc (DRAM) */
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
