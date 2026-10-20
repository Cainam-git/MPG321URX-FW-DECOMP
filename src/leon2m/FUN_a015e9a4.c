/* leon2m FUN_a015e9a4 @ 0xa015e9a4 (-mcpu=v8 -O2 -g)
 * Calls the function pointer at 0xa802cff0 with (a, b) and returns its result when the pointer is non-null;
 * returns 0 otherwise.
 */
/* 0xa802cff0: function pointer in DRAM */
extern int (*DAT_a802cff0)(unsigned int, unsigned int);

int FUN_a015e9a4(unsigned int a, unsigned int b)
{
    if (DAT_a802cff0 != 0)
        return DAT_a802cff0(a, b);
    return 0;
}
