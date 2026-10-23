/* FUN_a0144684 (leon2m 0xa0144684-0xa014468c, 8 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 5. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a014464c and FUN_a014468c. Source form: a constant return; the value is set in the retl delay slot.
 */
int FUN_a0144684(void)
{
    return 5;
}
