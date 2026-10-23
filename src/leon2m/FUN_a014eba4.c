/* leon2m FUN_a014eba4 @ 0xa014eba4..0xa014ebf8 (84 bytes, 21 words)
 * Flags: -mcpu=v8 -O3 -g (also exact with -msoft-float).
 * What it does (code facts): walks the 9-byte table DAT_a802a480[0..8]; for every slot i whose
 * byte equals a (a & 0xff), it calls FUN_a013863c(a, i, b & 0xff, 1), i.e. a 4-byte message
 * {a, i, b, 1} sent by FUN_a013863c through FUN_a01370dc(0x92, 4, buf, 0). No return value.
 * Callers: no direct 'call 0xa014eba4' in asm/leon2m (reached indirectly / via a table).
 * Aids: ONE - the table read goes through 'static inline get(n)' (an inlined accessor, no code
 * of its own). Why: with a direct 'a == DAT_a802a480[i]' gcc emits 'cmp %o0, %i0' (operands
 * swapped vs the fw 'cmp %i0, %o0') and the loop shape shifts. The accessor's
 * return conversion gives the fw operand order. Callee prototype = its real one
 * (src/leon2m/FUN_a013863c.c: void, four unsigned char parameters).
 */
extern unsigned char DAT_a802a480[];
extern void FUN_a013863c(unsigned char, unsigned char, unsigned char, unsigned char);
static inline unsigned char get(unsigned char n) { return DAT_a802a480[n]; }
void FUN_a014eba4(unsigned char a, unsigned char b)
{
  unsigned char i;
  for (i = 0; i <= 8; i++)
    if (a == get(i))
      FUN_a013863c(a, i, b, 1);
}
