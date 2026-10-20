/* leon2s FUN_a008fb5c @ 0xa008fb5c  MATCH (-mcpu=v8 -Os -g)
 * 
 */
extern unsigned int FUN_a00a657c(unsigned int param_1, unsigned short param_2);

unsigned int FUN_a008fb5c(unsigned int param_1)
{
    return (FUN_a00a657c(param_1 & 0xff, 0x144) & 0xe0) >> 5;
}
