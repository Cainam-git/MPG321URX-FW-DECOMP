/* leon2s FUN_a008f9c0 @ 0xa008f9c0  MATCH (-mcpu=v8 -Os -g)
 * 
 * This should produce:
 */
extern unsigned int FUN_a00a657c(unsigned int param_1, unsigned short param_2);

unsigned int FUN_a008f9c0(unsigned int param_1)
{
    unsigned int x = FUN_a00a657c(param_1 & 0xff, 0x134) & 2;
    return x != 0;
}
