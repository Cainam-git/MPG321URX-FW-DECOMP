/* leon2s FUN_a00a7368 @ 0xa00a7368 (-mcpu=v8 -Os)
 * Writes the high byte of p2 to register 0xCF000000 | ((0xf401 + (p1 & 0xff)) << 2) and returns
 * ((p1 & 0xff) << 8) + (p2 & 0xff) + 0xce008100. Called by FUN_a00a7468.
 */
int FUN_a00a7368(unsigned int param_1, unsigned short param_2)
{
    unsigned int t = param_1 & 0xff;
    *(volatile unsigned int *)(0xcf000000 | ((0xf401 + t) << 2)) = (param_2 >> 8) & 0xff;
    return (t << 8) + ((unsigned char)param_2) + 0xce008100;
}
