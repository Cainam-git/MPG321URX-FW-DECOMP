/* leon2m FUN_a0134464 @ 0xa0134464 (-mcpu=v8 -O2 -g)
 * Calls func_0x4008f3f4(0x14, 0, bits 8..15 of param_1, bits 0..7 of param_1, 1), then
 * func_0x4008f3f4(0x13, 0, 0, 0, 2); the last argument 2 is set by 'restore %g0, 2, %o4' in the delay slot.
 * Returns void.
 */
extern int func_0x4008f3f4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int); /* 0x4008f3f4 */

void FUN_a0134464(unsigned int param_1)
{
    func_0x4008f3f4(0x14, 0, (param_1 << 16) >> 24, param_1 & 0xff, 1);
    func_0x4008f3f4(0x13, 0, 0, 0, 2);
}
