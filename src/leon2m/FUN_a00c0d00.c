/* FUN_a00c0d00 (leon2m 0xa00c0d00-0xa00c0d08, 8 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 0. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a00c0cf8 and FUN_a00c0d08. Source form: a constant return; the value is set in the retl delay slot.
 */
int FUN_a00c0d00(void)
{
    return 0;
}
