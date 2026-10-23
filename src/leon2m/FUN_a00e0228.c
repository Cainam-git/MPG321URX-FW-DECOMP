/* leon2m FUN_a00e0228 @ 0xa00e0228 (-mcpu=v8 -O2 -g)
 * Stores p2 in the word at address p1. Same code as FUN_a002c25c.
 * See FUN_a002c25c for the explanation; this copy's constants differ, so its comments were removed.
 */
void FUN_a00e0228(unsigned int addr, unsigned int value)
{
    *(volatile unsigned int *)addr = value;
}
