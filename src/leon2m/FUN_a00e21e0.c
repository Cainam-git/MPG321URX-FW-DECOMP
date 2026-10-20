/* leon2m FUN_a00e21e0 @ 0xa00e21e0  MATCH (-mcpu=v8 -O2 -g)
 * Returns (FUN_a00e021c(param_1) & param_2) >> param_3. param_3 is unsigned int and used unmasked
 * ('srl %o0, %i2, %i0').
 */
extern int FUN_a00e021c(unsigned int); /* at 0xa00e021c */

unsigned int FUN_a00e21e0(unsigned int param_1, unsigned int param_2, unsigned int param_3)
{
    return (FUN_a00e021c(param_1) & param_2) >> param_3;
}
