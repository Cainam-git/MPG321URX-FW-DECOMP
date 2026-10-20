/* leon2s FUN_a00856d0 @ 0xa00856d0-0xa00856fc (11 words), flags -mcpu=v8 -Os -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp_l2s.py 0 mismatches / 11 words.
 * Code facts: x = FUN_a0083ed0(u8 param) (u8 result, re-extended 'and 0xff'); r = FUN_a00a74b8(x, 0xaf) & 2;
 * returns r != 0 (and 2 / cmp %g0 / addx). Callee facts: FUN_a0083ed0 reads %i0 (and 0xff) and returns 1 bit;
 * FUN_a00a74b8 returns its 3rd local masked with 0xff (restore %g0,%i2,%o0), so int holds it exactly.
 * Fix vs the autoc draft (72.73): the masked value is an int local tested in its own statement ('(f() & 2) != 0'
 * in one expression folds to srl 1 / and 1). Aids: none.
 */
extern unsigned char FUN_a0083ed0(unsigned char);
extern int FUN_a00a74b8(unsigned char, int);

int FUN_a00856d0(unsigned char param_1)
{
  int r = FUN_a00a74b8(FUN_a0083ed0(param_1), 0xaf) & 2;

  return r != 0;
}
