/* leon2s FUN_a00b1434 @ 0xa00b1434  MATCH (-mcpu=v8 -Os -g)
 * The function masks its first argument to a byte, calls the register-read helper with that byte and the constant 0x2a9, and returns bit 2 (value 4) of the result. The original Ghidra output had a spurious 64-bit CONCAT44 return and an unused second parameter; the actual function is a simple int-returning call with a bit test.
 */
extern unsigned int FUN_a00a6bb8(unsigned int param_1, unsigned short param_2);

unsigned int FUN_a00b1434(unsigned int param_1)
{
    return FUN_a00a6bb8(param_1 & 0xff, 0x2a9) & 0x4;
}
