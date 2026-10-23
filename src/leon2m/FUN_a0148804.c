/* FUN_a0148804 (leon2m 0xa0148804-0xa014880c, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns 1. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a01487e8 and FUN_a014880c. Source form: a constant return; the value is set in the retl delay slot.
 */
int FUN_a0148804(void)
{
    return 1;
}
