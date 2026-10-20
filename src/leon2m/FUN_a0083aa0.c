/* leon2m FUN_a0083aa0 @ 0xa0083aa0  MATCH (-mcpu=v8 -O2 -g)
 * Calls FUN_a008380c() without arguments and passes its bit 0 together with param_2 to FUN_a0148e34. param_1 is
 * not used. Returns nothing.
 */
extern int FUN_a008380c(void); /* 0xa008380c */
extern int FUN_a0148e34(int param_1, unsigned int param_2); /* 0xa0148e34 */

void FUN_a0083aa0(unsigned int param_1, unsigned int param_2)
{
    int val = FUN_a008380c();
    FUN_a0148e34(val & 1, param_2);
}
