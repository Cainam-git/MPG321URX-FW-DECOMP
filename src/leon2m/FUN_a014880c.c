/* FUN_a014880c (leon2m 0xa014880c-0xa0148814, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns 1. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a0148804 and FUN_a0148814. Source form: a constant return; the value is set in the retl delay slot.
 */
int FUN_a014880c(void)
{
    return 1;
}
