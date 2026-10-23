/* FUN_a012e848 (leon2m 0xa012e848-0xa012e850, 8 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 7. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a012e840 and FUN_a012e850. Source form: a constant return; the value is set in the retl delay slot.
 */
int FUN_a012e848(void)
{
    return 7;
}
