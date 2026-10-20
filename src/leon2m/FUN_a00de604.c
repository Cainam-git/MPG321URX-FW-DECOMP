/* FUN_a00de604 (leon2m 0xa00de604-0xa00de65c, 88 bytes), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0 mismatches of 22 words.
 * Code facts: void, no parameters (%i0 is never read or set). Calls the RAM register-write function
 * func_0x4008c25c(0x9f0200e0, 0xc0), then 5 plain nops, then func_0x4008c25c(0x9f000014, 0x210003),
 * then a delay loop of 0x400 passes (i = 0x3ff down to 0, addcc/bpos) with one nop per pass.
 * The nops are real instructions in the fw, written as __asm__ __volatile__("nop") (same form as the
 * delay loops elsewhere). 0x9f0200e0 / 0x9f000014 are hardware register addresses passed as values.
 * Aids: none.
 */
extern void func_0x4008c25c(unsigned int addr, unsigned int val);

void FUN_a00de604(void)
{
  int i;

  func_0x4008c25c(0x9f0200e0, 0xc0);
  __asm__ __volatile__("nop");
  __asm__ __volatile__("nop");
  __asm__ __volatile__("nop");
  __asm__ __volatile__("nop");
  __asm__ __volatile__("nop");
  func_0x4008c25c(0x9f000014, 0x210003);
  for (i = 0x3ff; i >= 0; i--)
    __asm__ __volatile__("nop");
}
