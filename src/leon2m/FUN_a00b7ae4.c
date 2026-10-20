/* leon2m FUN_a00b7ae4 @ 0xa00b7ae4-0xa00b7b8c (42 words), flags -mcpu=v8 -O3 -g.
 * Called by FUN_a00954a0, FUN_a0095510, FUN_a00955a0, FUN_a0095610 and FUN_a00af44c.
 * FUN_a0146b50(0x111, 0); FUN_a0146b6c(0, 0); for i = 0..3 (u8): FUN_a00a31a4(0, 0x2a, i*2 + 6, 1,
 * FUN_a00a3844(ROM word table 0x18d578, (u16)(i*29 + byte 0xa802d290+8)), 0); then tail
 * FUN_a00a813c(1, (u8)(byte 0xa802d290+0x4a + 2), 1). Same form as FUN_a00b6e1c with another table,
 * loop count and last argument. The record is one struct DAT_a802d290 (its address is kept in %l0).
 */
struct St { unsigned char pad[8]; unsigned char b08; unsigned char pad2[0x4a - 9]; unsigned char b4a; };
extern struct St DAT_a802d290;
extern unsigned int DAT_0018d578[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);
extern void FUN_a00a813c(int, unsigned char, int);

void FUN_a00b7ae4(void)
{
  unsigned char i;

  FUN_a0146b50(0x111, 0);
  FUN_a0146b6c(0, 0);
  for (i = 0; i <= 3; i++)
    FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_0018d578, i * 29 + DAT_a802d290.b08), 0);
  FUN_a00a813c(1, DAT_a802d290.b4a + 2, 1);
}
