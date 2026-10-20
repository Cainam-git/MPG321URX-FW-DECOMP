/* leon2m FUN_a0095020 @ 0xa0095020-0xa00950a8 (34 words), flags -mcpu=v8 -O3 -g.
 * Code facts: byte 0xa802b08f = 0xf. When byte 0xa8025c55 differs from bits 4..7 of word DAT_a802d290 + 0x30
 * (4-bit bit-field f4), those bits get the byte (and -241 / sll 4 / or, store in the call delay slot) and
 * FUN_a00d7a70(1) runs. Then FUN_a00a8c88(), FUN_a00a86e8() (void(void)), word 0xa802afec = 0x7c,
 * FUN_a00a9650(2, 1), byte 0xa8025c55 = byte d290 + 0x1a4. void(void).
 * Required forms: real base DAT_a802d290 with a 4-bit bit-field (not a mid-record _DAT_a802d2c0 symbol); a86e8 takes no arg. Aids: none.
 */
struct R290 {
  unsigned char pad[0x30]; unsigned int hi : 24, f4 : 4, lo : 4;
  unsigned char pad2[0x1a4 - 0x34]; unsigned char b1a4;
};
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a802b08f;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a86e8(void);
extern void FUN_a00a8c88(void);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00d7a70(int);

void FUN_a0095020(void)
{
  struct R290 *p = &DAT_a802d290;

  DAT_a802b08f = 0xf;
  if (DAT_a8025c55 != p->f4) {
    p->f4 = DAT_a8025c55;
    FUN_a00d7a70(1);
  }
  FUN_a00a8c88();
  FUN_a00a86e8();
  _DAT_a802afec = 0x7c;
  FUN_a00a9650(2, 1);
  DAT_a8025c55 = p->b1a4;
}
