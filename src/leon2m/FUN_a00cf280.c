/* FUN_a00cf280 (leon2m 0xa00cf280-0xa00cf288, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns 2. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a00cf23c and FUN_a00cf288. Source form: a constant return; the value is set in the retl delay slot.
 */
int FUN_a00cf280(void)
{
    return 2;
}
