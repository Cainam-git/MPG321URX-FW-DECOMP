/* FUN_a0133da0 (leon2m 0xa0133da0-0xa0133dc8, 40 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Calls func_0x4008f3f4(0x23, a, b, 0, 1) as a tail call (the RAM copy of FUN_a002f3f4); the nop after it is the -g
 * line nop. It lies between FUN_a0133d78 and FUN_a0133dc8.
 */
extern void func_0x4008f3f4(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);

void FUN_a0133da0(unsigned char a, unsigned char b)
{
    func_0x4008f3f4(0x23, a, b, 0, 1);
}
