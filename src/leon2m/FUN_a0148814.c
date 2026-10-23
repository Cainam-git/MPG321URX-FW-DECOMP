/* FUN_a0148814 (leon2m 0xa0148814-0xa014881c, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns 1. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a014880c and FUN_a014881c. Source form: a constant return; the value is set in the retl delay slot.
 */
int FUN_a0148814(void)
{
    return 1;
}
