/* leon2m FUN_a00df504 @ 0xa00df504  MATCH (-mcpu=v8 -O2 -g)
 * Returns FUN_a00e021c(param_1) & param_2. The mask applies to the call result, not to param_1, and the function
 * returns the value (Ghidra's pseudocode masks param_1 & param_2 and is void).
 */
extern int FUN_a00e021c(unsigned int); /* at 0xa00e021c */

unsigned int FUN_a00df504(unsigned int param_1, unsigned int param_2)
{
    unsigned int r;
    r = FUN_a00e021c(param_1);
    return r & param_2;
}
