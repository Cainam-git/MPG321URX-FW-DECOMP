/* FUN_a0144484 (leon2m 0xa0144484-0xa014448c, 8 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 6. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a0144414 and FUN_a014448c. Source form: a constant return; the value is set in the retl delay slot.
 */
int FUN_a0144484(void)
{
    return 6;
}
