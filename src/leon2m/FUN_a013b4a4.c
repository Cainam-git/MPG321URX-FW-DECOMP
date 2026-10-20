/* leon2m FUN_a013b4a4 @ 0xa013b4a4-0xa013b4cc (10 words), flags -mcpu=v8 -O3 -g.
 * Code facts: leaf sibcall wrapper. Stores the three u16 args into the record at 0xa802a46c (+0, +2, +4; the fw
 * emits +0 through %lo(sym), then +4, then +2), then tail-calls FUN_a013ae00(byte 0xa802a460) through the
 * 'mov %o7,%g1; call; mov %g1,%o7' form. Returns nothing.
 * Source form: the record DAT_a802a46c is one {u16 a, b, c} struct; stores in ascending source order. Aids: none.
 */
struct R46c { unsigned short a, b, c; };
extern struct R46c DAT_a802a46c;
extern unsigned char DAT_a802a460;
extern void FUN_a013ae00(unsigned char);
void FUN_a013b4a4(unsigned short a, unsigned short b, unsigned short c)
{
  DAT_a802a46c.a = a;
  DAT_a802a46c.b = b;
  DAT_a802a46c.c = c;
  FUN_a013ae00(DAT_a802a460);
}
