/* leon2m FUN_a00f8dd4 @ 0xa00f8dd4 (-mcpu=v8 -O2 -g)
 * Returns FUN_a00f1ce4(param_1 & 0xff, 0x14) & 0xfff (the low 12 bits of the callee's result). The second
 * parameter is unused.
 */
extern int FUN_a00f1ce4(unsigned int, unsigned int); /* 0xa00f1ce4 */

unsigned int FUN_a00f8dd4(unsigned int param_1, unsigned int param_2)
{
    return FUN_a00f1ce4(param_1 & 0xff, 0x14) & 0xfff;
}
