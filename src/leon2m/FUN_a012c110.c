/* FUN_a012c110 (leon2m 0xa012c110-0xa012c118, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns 4. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a012c108 and FUN_a012c118. Source form: a constant return; the value is set in the retl delay slot.
 */
int FUN_a012c110(void)
{
    return 4;
}
