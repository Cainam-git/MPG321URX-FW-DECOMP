/* FUN_a00fbfd4 (leon2m, 0xa00fbfd4-0xa00fc044, 112 bytes, 28 words).
 * Flags: -mcpu=v8 -O3 -g. Judge: jf 100.00 match=True, rawcmp 0/28 mismatches.
 * Code facts: FUN_a00fbdcc(0, 1, 0); halfword _DAT_a802b7ea = 1; FUN_a00fbdcc(0, 4, 0);
 * the word at 0xd0040000 |= 0x80000000 (fw: ld [%o4] reg+%g0 form = a plain constant address,
 * a symbol gives ld [%o4+%lo]); func_0x4008a880(0xc, 0x100, 0x9a814); func_0x40089820(0xc, 0x100);
 * %i0 is never written, so the function returns its first parameter unchanged.
 * Fixes vs draft: FUN_a00fbdcc takes THREE args (fw sets %o0..%o2; callee reads %i1), constant address.
 * Aids: none.
 */
extern unsigned short _DAT_a802b7ea;
extern int FUN_a00fbdcc();
extern int func_0x40089820();
extern void func_0x4008a880();

unsigned int FUN_a00fbfd4(unsigned int param_1, unsigned int param_2)

{
  FUN_a00fbdcc(0,1,0);
  _DAT_a802b7ea = 1;
  FUN_a00fbdcc(0,4,0);
  *(volatile unsigned int *)0xd0040000 = *(volatile unsigned int *)0xd0040000 | 0x80000000;
  func_0x4008a880(0xc,0x100,0x9a814);
  func_0x40089820(0xc,0x100);
  return param_1;
}
