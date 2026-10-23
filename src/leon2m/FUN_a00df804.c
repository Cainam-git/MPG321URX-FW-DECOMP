/* FUN_a00df804 (leon2m 0xa00df804-0xa00df80c, 8 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 2. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * switchdataD_a00df7d0 and FUN_a00df80c. Source form: a constant return; the value is set in the retl delay slot.
 */
int FUN_a00df804(void)
{
    return 2;
}
