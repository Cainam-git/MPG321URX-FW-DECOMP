/* leon2m FUN_a00d5da4 @ 0xa00d5da4-0xa00d5e0c (26 words).
 * Calls FUN_a0124a08() when FUN_a0082c4c() returns 0, then FUN_a0148f4c(m) (tail call) with m = 1, 2 or 0 for
 * byte 0xa802d295 equal to 1, 2 or anything else.
 */
extern unsigned char FUN_a0082c4c(void);
extern void FUN_a0124a08(void);
extern void FUN_a0148f4c(unsigned char);
extern unsigned char DAT_a802d295;

void FUN_a00d5da4(void)
{
    unsigned char m;

    if (!FUN_a0082c4c())
        FUN_a0124a08();
    switch (DAT_a802d295) {
    case 1: m = 1; break;
    case 2: m = 2; break;
    default: m = 0; break;
    }
    FUN_a0148f4c(m & 3);
}
