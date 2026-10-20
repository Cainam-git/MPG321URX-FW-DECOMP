/* leon2m FUN_a00d4780 @ 0xa00d4780-0xa00d47ac (11 words), flags -mcpu=v8 -O3 -g.
 * Leaf frame, sibcall (mov %o7 form).
 * Code facts: v = byte 0xa802d290+0xf; if v > 5 then v = 5 (bgu,a); byte rec+0xf = v; tail call FUN_a014a388(v &
 * 0xff) (the fw re-extends after the store).
 * Source form: the record base DAT_a802d290 as a struct; the clamp variable is an unsigned short (u8 gives an
 * extra and/branch shape; unsigned int gives no re-extension; the short's conversion to the u8 parameter is the
 * 'and 0xff').
 * Compiler aids: none.
 */
struct R290 { unsigned char pad[0xf]; unsigned char b0f; };
extern struct R290 DAT_a802d290;
extern void FUN_a014a388(unsigned char);

void FUN_a00d4780(void)
{
  struct R290 *p = &DAT_a802d290;
  unsigned short v = p->b0f;

  if (v > 5)
    v = 5;
  p->b0f = v;
  FUN_a014a388(v);
}
