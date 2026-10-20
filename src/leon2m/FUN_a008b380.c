/* leon2m FUN_a008b380 @ 0xa008b380-0xa008b58c (131 words), flags -mcpu=v8 -O3 -g.
 * Called by FUN_a008b83c, FUN_a008c25c and FUN_a008d2f8. Picks a halfword v from the local table
 * {234, 468, 937, 1875, 3750, 7500, 15000, 30000} by the byte 0xa802afb8, clears 9 bytes of a buffer and
 * formats v with FUN_a01577f4: v < 1000 with "n%2d.%dKHz" (0x1004a8) as v / 10, v % 10; v <= 10000 with
 * "n%3d.%dKHz" (0x100498) as v / 10, v % 10; otherwise "n%d.%dMHz" (0x100488) as v / 10000, (v % 10000) / 1000.
 * The first character 'n' is then replaced by the index of the first zero byte minus 1 (index 9 when none).
 * Then FUN_a0146b6c(0, 0), FUN_a0146b50(0xd9, 0) and FUN_a00a31a4(0, col + len, row, buf[0], buf, 0) with the
 * 3-byte record 15 {col, row, len} of the ROM table 0x100242.
 * Source form: the v < 1000 test first, then v > 10000 (the other two orders change the block layout).
 */
struct Pos { unsigned char col, row, len; };

extern unsigned char DAT_a802afb8;
extern const struct Pos DAT_00100242[];
extern const char s_00100488[], s_00100498[], s_001004a8[];

extern void FUN_a01577f4(unsigned char *, const char *, unsigned short, unsigned short);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, const char *, unsigned char);

void FUN_a008b380(void)
{
  unsigned short tab[8] = { 234, 468, 937, 1875, 3750, 7500, 15000, 30000 };
  unsigned char buf[16];
  unsigned short v;
  unsigned char i;

  v = tab[DAT_a802afb8];
  for (i = 0; i < 9; i++)
    buf[i] = 0;
  if (v < 1000)
    FUN_a01577f4(buf, s_001004a8, v / 10, v % 10);
  else if (v > 10000)
    FUN_a01577f4(buf, s_00100488, v / 10000, (v % 10000) / 1000);
  else
    FUN_a01577f4(buf, s_00100498, v / 10, v % 10);
  for (i = 0; i < 9; i++)
    if (buf[i] == 0)
      break;
  buf[0] = i - 1;
  FUN_a0146b6c(0, 0);
  FUN_a0146b50(0xd9, 0);
  FUN_a00a31a4(0, DAT_00100242[15].col + DAT_00100242[15].len, DAT_00100242[15].row, buf[0], buf, 0);
}
