/* leon2m FUN_a015e9a4 @ 0xa015e9a4 (-mcpu=v8 -O2 -g)
 * Calls the function pointer at 0xA802CFF0 with (a, b) and returns its result when the pointer is non-null;
 * returns 0 otherwise. Same shape as the one-argument pointer callers FUN_a015e9d8..FUN_a015eac8 that follow it
 * and as the two-argument FUN_a015eaf8 (pointer at 0xA802CFD4).
 */
extern int (*DAT_a802cff0)(unsigned int, unsigned int);

int FUN_a015e9a4(unsigned int a, unsigned int b)
{
    if (DAT_a802cff0 != 0)
        return DAT_a802cff0(a, b);
    return 0;
}
