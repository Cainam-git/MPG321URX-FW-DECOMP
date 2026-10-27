/* FUN_a0133dec (leon2m 0xa0133dec-0xa0133e10, 36 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Calls func_0x4008f3f4(0x21, 0, 0, 0, 1) as a tail call (the RAM copy of FUN_a002f3f4); the nop after it is the -g
 * line nop. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a0133dc8 and FUN_a0133e10.
 */
extern void func_0x4008f3f4(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);

void FUN_a0133dec(void)
{
    func_0x4008f3f4(0x21, 0, 0, 0, 1);
}
