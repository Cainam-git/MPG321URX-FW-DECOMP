/* FUN_a0091c84 (leon2s 0xa0091c84-0xa0091cf4, 112 bytes = 28 words incl. the trailing pad nop),
 * flags -mcpu=v8 -Os -g.
 * void, 2 params (u8 port, u16 v). r = FUN_a00a7fd8(port, 0, 0xf7) & ~0xc (and %o0,-13 right after the
 * call; the callee returns a word masked with 0xff, so an int prototype is honest). v is clamped to 0x3ff.
 * Then FUN_a00a8054(port, 0, 0xf6, v & 0xff) and a tail call FUN_a00a8054(port, 0, 0xf7, r | (v >> 8)):
 * bits 3:2 of register 0xf7 are replaced by bits 9:8 of v, register 0xf6 gets bits 7:0. The 0xf7 byte is
 * built from the return value of FUN_a00a7fd8.
 * Source form: the mask is applied at the call ('r = f() & ~0xc') and a u8 'hi' is formed before the first
 * write (int 'r & 0xf3' forms give another schedule).
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
