/* leon2m FUN_a0146b6c @ 0xa0146b6c-0xa0146bb0 (17 words).
 * Tail-calls FUN_a011b36c(k, v) with k = 1 for c 1, 2 for c 2 and 0 otherwise.
 * The three calls stay separate in the firmware (one per selected value), each a tail call with %o7 saved in %g1.
 */
extern void FUN_a011b36c(unsigned char, unsigned char);

void FUN_a0146b6c(unsigned char c, unsigned char v)
{
    switch (c) {
    case 1: FUN_a011b36c(1, v); break;
    case 2: FUN_a011b36c(2, v); break;
    default: FUN_a011b36c(0, v); break;
    }
}
