/* leon2m FUN_a00874c8 @ 0xa00874c8-0xa00875ec.
 * For each bit i (0 .. 7) set in bits, in ascending order, calls FUN_a014bac4(4 + i, v); the last call is a
 * tail call. v is an unsigned char parameter, zero-extended again before each call.
 */
extern void FUN_a014bac4(unsigned int, unsigned short);

void FUN_a00874c8(unsigned char bits, unsigned char v)
{
  if (bits & 0x01)
    FUN_a014bac4(4, v);
  if (bits & 0x02)
    FUN_a014bac4(5, v);
  if (bits & 0x04)
    FUN_a014bac4(6, v);
  if (bits & 0x08)
    FUN_a014bac4(7, v);
  if (bits & 0x10)
    FUN_a014bac4(8, v);
  if (bits & 0x20)
    FUN_a014bac4(9, v);
  if (bits & 0x40)
    FUN_a014bac4(10, v);
  if (bits & 0x80)
    FUN_a014bac4(11, v);
}
