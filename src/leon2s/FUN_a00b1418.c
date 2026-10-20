/* leon2s FUN_a00b1418 @ 0xa00b1418 (-mcpu=v8 -Os -g)
 * The function masks the first argument to a byte, calls the register-read helper with that byte and constant 0x3a, then returns only bit 0x40 of the result. The original Ghidra decompilation incorrectly introduced a fake 64-bit return and an extra unused parameter; the actual function takes one argument and returns the masked helper result directly.
 */
extern unsigned int FUN_a00a6bb8(unsigned int param_1, unsigned short param_2);

unsigned int FUN_a00b1418(unsigned int param_1)
{
    return FUN_a00a6bb8(param_1 & 0xff, 0x3a) & 0x40;
}
