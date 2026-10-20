/* leon2s FUN_a0061534 @ 0xa0061534  MATCH (-mcpu=v8 -Os -g)
 * Stores param_2 to *param_1. The volatile pointer keeps the st ahead of retl / nop; without it GCC 3.4 -Os places
 * the st in the retl delay slot.
 */
void FUN_a0061534(volatile unsigned int *param_1, unsigned int param_2)
{
    *param_1 = param_2;
}
