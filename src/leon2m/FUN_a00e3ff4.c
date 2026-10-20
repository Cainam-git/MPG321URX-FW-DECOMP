/* leon2m FUN_a00e3ff4 @ 0xa00e3ff4  MATCH (-mcpu=v8 -O2 -g)
 * Returns (FUN_a00e0754(param_1, 0x18, 0xFF, 0) << 8) | FUN_a00e0754(param_1, 0x17, 0xFF, 0): a 16-bit value with
 * the 0x18 byte high and the 0x17 byte low.
 */
extern unsigned int FUN_a00e0754(unsigned int, unsigned int, unsigned int, unsigned int); /* 0xa00e0754 */

unsigned int FUN_a00e3ff4(unsigned int param_1)
{
    unsigned int uVar1;

    uVar1 = FUN_a00e0754(param_1, 0x18, 0xff, 0);
    return (uVar1 << 8) | FUN_a00e0754(param_1, 0x17, 0xff, 0);
}
