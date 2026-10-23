/* leon2s FUN_a008fb5c @ 0xa008fb5c (-mcpu=v8 -Os -g)
 * Returns bits 5..7 of FUN_a00a657c(p & 0xff, 0x144) as 0..7.
 */
extern unsigned int FUN_a00a657c(unsigned int param_1, unsigned short param_2);

unsigned int FUN_a008fb5c(unsigned int param_1)
{
    return (FUN_a00a657c(param_1 & 0xff, 0x144) & 0xe0) >> 5;
}
