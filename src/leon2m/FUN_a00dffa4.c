/* leon2m FUN_a00dffa4 @ 0xa00dffa4-0xa00dffb0 (3 words), flags -mcpu=v8 -Os -g.
 * Passes its argument n on to FUN_a00de53c(n) as a tail call (FUN_a00de53c runs n rounds of a fixed nop loop).
 * Callers: FUN_a00e0090 (n = 1), FUN_a00e0788 (n = 2) and others.
 */
extern void FUN_a00de53c(unsigned int n);

void FUN_a00dffa4(unsigned int n)
{
    FUN_a00de53c(n);
}
