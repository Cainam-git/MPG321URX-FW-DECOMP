/* FUN_a0110f44 (leon2m 0xa0110f44-0xa0110f4c, 8 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 1. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a0110d64 and FUN_a0110f4c. Source form: a constant return; the value is set in the retl delay slot.
 */
int FUN_a0110f44(void)
{
    return 1;
}
