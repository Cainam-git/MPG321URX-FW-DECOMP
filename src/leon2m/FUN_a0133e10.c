/* FUN_a0133e10 (leon2m 0xa0133e10-0xa0133e34, 36 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Calls func_0x4008f3f4(0x17, 0, 0, 0, 3) as a tail call (the RAM copy of FUN_a002f3f4); the nop after it is the -g
 * line nop. Called by FUN_a002f8d8. It lies between FUN_a0133dec and FUN_a0133e34.
 */
extern void func_0x4008f3f4(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);

void FUN_a0133e10(void)
{
    func_0x4008f3f4(0x17, 0, 0, 0, 3);
}
