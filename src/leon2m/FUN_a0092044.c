/* leon2m FUN_a0092044 @ 0xa0092044-0xa00920f4 (44 words), flags -mcpu=v8 -O3 -g.
 * afec loop family (no loop here).
 * Code facts: FUN_a00a8ee8(word 0xa802afec - 0x18, u8). v = 0 when FUN_a00aa520(0) != 0 (u8 return, 1 arg),
 * else v = 1 if FUN_a00aa520(1) == 1, else 2 (xor 1 / cmp %g0 / addx / add 1). Then FUN_a00af44c(0x18, v),
 * FUN_a00a900c(v, 0), word afec = 5, tail FUN_a00b4144(3, 1) (the whole tail is duplicated per path by jump
 * threading). void(void). Fix vs the autoc draft: aa520 takes 1 arg, v = 0 on the first path, b4144 takes
 * 2 args. The ternary '== 1 ? 1 : 2' keeps the fw addx + add 1 ('(x != 1) + 1' folds to mov 2 / addx -1).
 * Aids: none.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a8ee8(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00af44c(unsigned char, unsigned char);
extern void FUN_a00b4144(int, int);

void FUN_a0092044(void)
{
  unsigned char v;

  FUN_a00a8ee8(_DAT_a802afec - 0x18);
  if (FUN_a00aa520(0) != 0)
    v = 0;
  else
    v = FUN_a00aa520(1) == 1 ? 1 : 2;
  FUN_a00af44c(0x18, v);
  FUN_a00a900c(v, 0);
  _DAT_a802afec = 5;
  FUN_a00b4144(3, 1);
}
