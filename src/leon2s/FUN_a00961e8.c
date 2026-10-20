/* leon2s FUN_a00961e8 @ 0xa00961e8-0xa0096204 (7 words), flags -mcpu=v8 -Os -g.
 * Leaf (retl).
 * Code facts: returns ((u8 param == 1) + 2) & 7, i.e. 3 for 1 and 2 otherwise; the fw computes the compare
 * with xor/cmp/subx, adds 2 and masks with 7 in the retl delay slot.
 * Fix vs the autoc draft (71.43): a u8 local 'r = 2; r += (p == 1); return r & 7;' (every one-expression form
 * lets gcc prove r < 8 and drop the 'and 7', or turns it into a 3/2 select). Aids: none.
 */
unsigned char FUN_a00961e8(unsigned char param_1)
{
  unsigned char r = 2;

  r += (param_1 == 1);
  return r & 7;
}
