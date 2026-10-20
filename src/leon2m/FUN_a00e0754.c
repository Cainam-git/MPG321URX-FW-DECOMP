/* leon2m FUN_a00e0754 @ 0xa00e0754  MATCH (-mcpu=v8 -O2 -g)
 * Returns FUN_a00e0514(param_1, param_2, param_3) shifted right logically by param_4. The unsigned int types of the
 * parameters, the local and the return value make GCC emit srl rather than sra.
 */
extern unsigned int FUN_a00e0514(unsigned int, unsigned int, unsigned int);

unsigned int FUN_a00e0754(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4)
{
    unsigned int result = FUN_a00e0514(param_1, param_2, param_3);
    return result >> param_4;
}
