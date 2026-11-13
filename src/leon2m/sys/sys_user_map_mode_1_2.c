/* sys_user_map_mode_1_2  (FUN_a00d493c)
 *
 * Map 1 to 0, 2 to 1 and other values to 5.
 * Returns: mapped value
 * Name basis: descriptive - small mapping
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d493c @ 0xa00d493c-0xa00d4970 (13 words), flags -mcpu=v8 -O3 -g.
 * Leaf, u8 in / u8 out.
 * Code facts: maps the u8 parameter: 1 -> 0, 2 -> 1, every other value -> 5. The fw is a switch case tree with
 * SIGNED compares (cmp 2/be, cmp 2/ble, cmp 1/bne), one shared 'r = 5' block (reached from the > 2 test and from
 * != 1), and the u8 return extension 'and 0xff' reduced to 'and 5' by combine (nonzero bits of {0,1,5}).
 * Source form: a switch with cases 1, 2 and an explicit 'case 3: r = 5' (same value as the default; it makes 2 the
 * tree root, and its block is crossjumped into the default). Plain if chains and two-case switches are
 * if-converted to store-flag code (xor/addx).
 */
/*
 * Map the value 1 to 0, 2 to 1 and every other value to 5.
 *
 * The explicit 'case 3' has the same result as the default; it makes the compiler build the firmware's
 * case tree.
 */
unsigned char sys_user_map_mode_1_2(unsigned char value)
{
  unsigned char result;

  switch (value) {
  case 1:
    result = 0;
    break;
  case 2:
    result = 1;
    break;
  case 3:
    result = 5;
    break;
  default:
    result = 5;
    break;
  }
  return result;
}
