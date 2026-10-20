/* leon2m FUN_a014e0a4 @ 0xa014e0a4-0xa014e0d4 (12 words).
 * Tail-calls FUN_a0105d04(2) for v == 2, FUN_a0105d04(1) for v == 1 and FUN_a0105d04(0) for any other v. Routine
 * directly after FUN_a014e050 (separated from it in the function table).
 */
extern void FUN_a0105d04(unsigned char);

void FUN_a014e0a4(unsigned char v)
{
    if (v == 2)
        FUN_a0105d04(2);
    else if (v == 1)
        FUN_a0105d04(1);
    else
        FUN_a0105d04(0);
}
