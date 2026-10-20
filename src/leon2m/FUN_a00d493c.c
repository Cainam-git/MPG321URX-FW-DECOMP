/* leon2m FUN_a00d493c @ 0xa00d493c-0xa00d4970 (13 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 13 words. Leaf, u8 in / u8 out.
 * Code facts: maps the u8 parameter: 1 -> 0, 2 -> 1, every other value -> 5. The fw is a switch case tree with
 * SIGNED compares (cmp 2/be, cmp 2/ble, cmp 1/bne), one shared 'r = 5' block (reached from the > 2 test and
 * from != 1), and the u8 return extension 'and 0xff' reduced to 'and 5' by combine (nonzero bits of {0,1,5}).
 * Fix vs the autoc draft (69.23): a switch with cases 1, 2 and an explicit 'case 3: r = 5' (same value as the
 * default; it makes 2 the tree root, and its block is crossjumped into the default). Plain if chains and two-case
 * switches are if-converted to store-flag code (xor/addx). Aids: none (case 3 has the default's behaviour).
 */
unsigned char FUN_a00d493c(unsigned char param_1)
{
  unsigned char r;

  switch (param_1) {
  case 1:
    r = 0;
    break;
  case 2:
    r = 1;
    break;
  case 3:
    r = 5;
    break;
  default:
    r = 5;
    break;
  }
  return r;
}
