/* leon2s FUN_a00618c0 @ 0xa00618c0  MATCH (-mcpu=v8 -Os -g)
 * Returns the word at param_1 (ld; retl; nop). The pointer is declared volatile.
 */
unsigned int FUN_a00618c0(volatile unsigned int *param_1)
{
    return *param_1;
}
