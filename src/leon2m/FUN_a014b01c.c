/* leon2m FUN_a014b01c @ 0xa014b01c-0xa014b0c4 (42 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 42 words. Same family as FUN_a014b360.
 * Code facts: m = (u8)FUN_a01421c4(FUN_a0142218(FUN_a0125198(p1))) (each result passed on as u8). i = 0, 1, 2, 3
 * for m = 0x51 / 0x61 / 0x71 / 0x81, else 0 (u16 i: the fw 'and 3'). r = FUN_a0125124(byte +0x10 of the
 * 0x12-byte record DAT_a802e116[i]); FUN_a01255dc(r, p2); tail FUN_a0133e7c((u8)(1 << r), p2). void.
 * Fix vs the autoc draft: one nested call chain, the real record base DAT_a802e116 + 0x10 (draft e126), u8
 * prototypes. The explicit 'case 0x51: i = 0' (same value as the default; the case-tree root lever) gives the
 * fw tree with 0x61 at the root (without it 78.57). Aids: none.
 */
struct Ent { unsigned char b00[0x10]; unsigned char b10; unsigned char b11; };
extern struct Ent DAT_a802e116[];
extern int FUN_a0125198(unsigned char);
extern int FUN_a0142218(unsigned char);
extern int FUN_a01421c4(unsigned char);
extern unsigned char FUN_a0125124(unsigned char);
extern void FUN_a01255dc(unsigned char, unsigned char);
extern void FUN_a0133e7c(unsigned char, unsigned char);

void FUN_a014b01c(unsigned char param_1, unsigned char param_2)
{
  unsigned short i;
  unsigned char r;

  i = 0;
  switch ((unsigned char)FUN_a01421c4(FUN_a0142218(FUN_a0125198(param_1)))) {
  case 0x51: i = 0; break;
  case 0x61: i = 1; break;
  case 0x71: i = 2; break;
  case 0x81: i = 3; break;
  }
  r = FUN_a0125124(DAT_a802e116[i].b10);
  FUN_a01255dc(r, param_2);
  FUN_a0133e7c(1 << r, param_2);
}
