/* FUN_a0070704 (leon2s 0xa0070704-0xa0070728, 36 bytes), flags -mcpu=v8 -Os -g.
 * Calls FUN_a0072b04() when x is 0 (tail call). Address word at 0xa00b4f10.
 * Leaf routine without a register window (no save).
 */
extern void FUN_a0072b04(void);

void FUN_a0070704(int x)
{
    if (x == 0)
        FUN_a0072b04();
}
