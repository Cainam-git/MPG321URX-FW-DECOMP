/* leon2m FUN_a00f88cc @ 0xa00f88cc  MATCH (-mcpu=v8 -O2 -g)
 * Returns FUN_a00f1ce4(param_1 & 0xFF, 0xC) & 0x7FF (11 bits). The function takes one argument; as a non-leaf
 * function it has the save %sp,-104,%sp frame.
 */
/* FUN_a00f1ce4 at 0xa00f1ce4 */
extern int FUN_a00f1ce4(int, int);

unsigned int FUN_a00f88cc(unsigned int param_1)
{
    unsigned int v = param_1 & 0xff;
    v = FUN_a00f1ce4(v, 0xc);
    return v & 0x7ff;
}
