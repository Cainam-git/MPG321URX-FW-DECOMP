/* leon2m FUN_a0099244 @ 0xa0099244-0xa009934c (66 words), flags -mcpu=v8 -O3 -g.
 * Code facts: record DAT_a802d290: bit 20 of word +0xac is toggled (srl 20 / xnor / and 1 / andn / or / st) as
 * a 1-bit bit-field written 'f20 = 1 - f20'; FUN_a00a5420(6, new bit). If byte +0x1f != 0: clear it,
 * FUN_a00d91fc(0), FUN_a0148268(0, 1), FUN_a0148268(1, 1), FUN_a00da254(). Then if FUN_a01445fc(byte +0x1e)
 * returns 0 (u8): FUN_a00d91fc(0), FUN_a01439d8(0x10, 1) when byte +0x1e == 5, FUN_a0148268(0, 1) and (1, 1).
 * Always byte 0xa802b08e |= 2. void(void). Fix vs the autoc draft: BEHAVIOUR: d91fc(0) runs before the two
 * 148268 calls in the +0x1f arm; real base DAT_a802d290 (draft d2ae/d2af/d33c mid-record names); uninitialised
 * draft temp replaced by the bit. '~f20' / '!f20' / '^= 1' give and 1 / xor 1 (96.97). Aids: none.
 */
struct R290 {
  unsigned char pad[0x1e]; unsigned char b1e; unsigned char b1f;
  unsigned char pad2[0xac - 0x20]; unsigned int hi : 11, f20 : 1, lo : 20;
};
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern void FUN_a00a5420(int, unsigned char);
extern void FUN_a00d91fc(int);
extern void FUN_a00da254(void);
extern void FUN_a01439d8(int, int);
extern unsigned char FUN_a01445fc(unsigned char);
extern void FUN_a0148268(int, int);

void FUN_a0099244(void)
{
  struct R290 *p = &DAT_a802d290;

  p->f20 = 1 - p->f20;
  FUN_a00a5420(6, p->f20);
  if (p->b1f != 0) {
    p->b1f = 0;
    FUN_a00d91fc(0);
    FUN_a0148268(0, 1);
    FUN_a0148268(1, 1);
    FUN_a00da254();
  }
  if (FUN_a01445fc(p->b1e) == 0) {
    FUN_a00d91fc(0);
    if (p->b1e == 5)
      FUN_a01439d8(0x10, 1);
    FUN_a0148268(0, 1);
    FUN_a0148268(1, 1);
  }
  DAT_a802b08e |= 2;
}
