/* leon2m FUN_a00e4030 @ 0xa00e4030  MATCH (-mcpu=v8 -O2 -g)
 * Reads registers 0x1C and 0x1B with FUN_a00e0754(param_1, reg, 0xFF, 0) and returns
 * them packed as a 16-bit value: register 0x1C in the high byte, 0x1B in the low byte. The function takes one
 * argument; the first result is held in %l0 across the second call.
 */
extern unsigned int FUN_a00e0754(unsigned int, unsigned int, unsigned int, unsigned int); /* 0xa00e0754 */

unsigned int FUN_a00e4030(unsigned int param_1)
{
    unsigned int uVar1;

    uVar1 = FUN_a00e0754(param_1, 0x1c, 0xff, 0);
    return (uVar1 << 8) | FUN_a00e0754(param_1, 0x1b, 0xff, 0);
}
