/* FUN_a0091c84 (leon2s 0xa0091c84-0xa0091cf4, 112 bytes incl. the trailing pad nop), flags -mcpu=v8 -Os -g.
 * of 28 words.
 * Code facts: void, 2 params (u8 port, u16 v). r = FUN_a00a7fd8(port, 0, 0xf7) & ~0xc (and %o0,-13 right
 * after the call; the callee returns a word masked with 0xff, so an int prototype is honest). v is clamped
 * to 0x3ff. Then FUN_a00a8054(port, 0, 0xf6, v & 0xff) and a tail call FUN_a00a8054(port, 0, 0xf7,
 * r | (v >> 8)): bits 3:2 of register 0xf7 are replaced by bits 9:8 of v, register 0xf6 gets bits 7:0.
 * BEHAVIOUR fix: the draft used param_1 (the port) instead of FUN_a00a7fd8's return value for the 0xf7
 * byte. Lever: the mask is applied at the call ('r = f() & ~0xc') and 'hi' is formed before the first
 * write (u8 'hi'; int 'r & 0xf3' forms give 82.14). Aids: none.
 */
extern int FUN_a00a7fd8(unsigned char, unsigned char, unsigned short);
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);

void FUN_a0091c84(unsigned char port, unsigned short v)
{
  int r;
  int hi;

  r = FUN_a00a7fd8(port, 0, 0xf7) & ~0xc;
  if (v > 0x3ff)
    v = 0x3ff;
  hi = r | (v >> 8);
  FUN_a00a8054(port, 0, 0xf6, v & 0xff);
  FUN_a00a8054(port, 0, 0xf7, hi);
}
