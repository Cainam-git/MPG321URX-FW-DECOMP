/* FUN_a0133d28 (leon2m 0xa0133d28-0xa0133d4c, 36 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Calls func_0x4008f3f4(0x2a, 0, 0, 0, 1) as a tail call (the RAM copy of FUN_a002f3f4); the nop after it is the -g
 * line nop. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a0133d04 and FUN_a0133d4c.
 */
extern void func_0x4008f3f4(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);

void FUN_a0133d28(void)
{
    func_0x4008f3f4(0x2a, 0, 0, 0, 1);
}
