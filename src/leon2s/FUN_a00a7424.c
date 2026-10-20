/* FUN_a00a7424 (leon2s 0xa00a7424-0xa00a7468, 68 bytes incl. the trailing pad nop), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0 mismatches of 17 words.
 * Code facts: void, 4 params (int mode, u32 bit, u8 reg, u16 val). Both arms call FUN_a00a7368(reg, val),
 * which returns a word (retl add %o4,%o0,%o0), and pass that RETURN VALUE as the 2nd argument of a tail call
 * (restore %g0,%o0,%o1): mode == 1 -> FUN_a00a73ac(bit, r), else FUN_a00a73d4(bit, r).
 * BEHAVIOUR fix: the draft passed reg (param_3) as the 2nd argument of a73ac/a73d4 and dropped the return value.
 * Aids: none.
 */
extern unsigned int FUN_a00a7368(unsigned int, unsigned short);
extern void FUN_a00a73ac(unsigned int, unsigned int);
extern void FUN_a00a73d4(unsigned int, unsigned int);

void FUN_a00a7424(int mode, unsigned int bit, unsigned char reg, unsigned short val)
{
  if (mode == 1)
    FUN_a00a73ac(bit, FUN_a00a7368(reg, val));
  else
    FUN_a00a73d4(bit, FUN_a00a7368(reg, val));
}
