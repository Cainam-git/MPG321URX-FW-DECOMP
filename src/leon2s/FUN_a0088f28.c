/* leon2s FUN_a0088f28 @ 0xa0088f28 (-mcpu=v8 -Os -g)
 * 
 */
// FUN_a00a78b4 at 0xa00a78b4
extern unsigned int FUN_a00a78b4(unsigned int param_1, unsigned short param_2);

// FUN_a0088f28 at 0xa0088f28
unsigned int FUN_a0088f28(unsigned int param_1)
{
    unsigned int x = FUN_a00a78b4(param_1 & 0xff, 0x70) & 0x10;
    return x != 0;
}
