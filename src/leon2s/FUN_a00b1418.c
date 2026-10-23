/* leon2s FUN_a00b1418 @ 0xa00b1418 (-mcpu=v8 -Os -g)
 * Returns FUN_a00a6bb8(port & 0xff, 0x3a) & 0x40: bit 6 of register 0x3a of the port's register block (read
 * helper FUN_a00a6bb8, base table at 0xa00b4d94). One argument; the result is the masked value, not 0/1.
 */
extern unsigned int FUN_a00a6bb8(unsigned int param_1, unsigned short param_2);

unsigned int FUN_a00b1418(unsigned int param_1)
{
    return FUN_a00a6bb8(param_1 & 0xff, 0x3a) & 0x40;
}
