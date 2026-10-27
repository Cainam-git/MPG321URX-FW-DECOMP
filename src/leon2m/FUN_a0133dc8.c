/* FUN_a0133dc8 (leon2m 0xa0133dc8-0xa0133dec, 36 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Calls func_0x4008f3f4(0x22, 0, c, 0, 1) as a tail call (the RAM copy of FUN_a002f3f4); the nop after it is the -g
 * line nop. Called by gap. It lies between FUN_a0133da0 and FUN_a0133dec.
 */
extern void func_0x4008f3f4(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);

void FUN_a0133dc8(unsigned char c)
{
    func_0x4008f3f4(0x22, 0, c, 0, 1);
}
