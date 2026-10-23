/* leon2m FUN_a00d4560 @ 0xa00d4560-0xa00d45f8 (38 words).
 * For n = 0..5 in turn: FUN_a014ce84(n, FUN_a0145920(n), 1); the last call is a tail call.
 * No parameters, no return value; the byte returned by FUN_a0145920 is passed on unchanged as the second argument.
 * Data used: none directly.
 */
extern unsigned char FUN_a0145920(unsigned char);
extern void FUN_a014ce84(unsigned char, unsigned char, unsigned char);

void FUN_a00d4560(void)
{
    FUN_a014ce84(0, FUN_a0145920(0), 1);
    FUN_a014ce84(1, FUN_a0145920(1), 1);
    FUN_a014ce84(2, FUN_a0145920(2), 1);
    FUN_a014ce84(3, FUN_a0145920(3), 1);
    FUN_a014ce84(4, FUN_a0145920(4), 1);
    FUN_a014ce84(5, FUN_a0145920(5), 1);
}
