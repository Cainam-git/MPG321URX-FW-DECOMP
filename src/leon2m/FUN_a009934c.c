/* leon2m FUN_a009934c @ 0xa009934c-0xa00993a8 (23 words), flags -mcpu=v8 -O3 -g.
 * Same toggle form as FUN_a0099244.
 * Code facts: bit 7 of word DAT_a802d290 + 0x1ec is toggled (srl 7 / xnor / and 1 / sll 7 / and -129 / or / st),
 * 1-bit bit-field written 'f7 = 1 - f7'; FUN_a00a5420(0, new bit); FUN_a00db12c(0) (it reads its u8 %o0);
 * byte 0xa802b08e |= 2. void(void).
 * The record base is DAT_a802d290 + 0x1ec; FUN_a00db12c takes the argument 0. Aids: none.
 */
struct R290 { unsigned char pad[0x1ec]; unsigned int hi : 24, f7 : 1, lo : 7; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern void FUN_a00a5420(int, unsigned char);
extern void FUN_a00db12c(int);

void FUN_a009934c(void)
{
  struct R290 *p = &DAT_a802d290;

  p->f7 = 1 - p->f7;
  FUN_a00a5420(0, p->f7);
  FUN_a00db12c(0);
  DAT_a802b08e |= 2;
}
