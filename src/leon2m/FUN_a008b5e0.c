/* leon2m FUN_a008b5e0 @ 0xa008b5e0-0xa008b83c (151 words), flags -mcpu=v8 -O3 -g.
 * Called by FUN_a008b83c, FUN_a008c25c and FUN_a008d2f8. Two text lines from the bytes 0xa802afb8 (s) and 0xa802afb9 (e):
 *  1) v = (0x4e >> (4 - e)) >> s for e < 4, else (0x4e << (e - 4)) >> s, as u16; d[0] = v / 100, d[1] = v % 100.
 *     Format: d[0] > 10: "nS%2d.%2dP" (0x1004f8); d[1] > 10: "nS%d.%2dP" (0x1004b8); else "nS%d.0%dP" (0x1004c8).
 *     Then 'S' -> '$' and 'P' -> '%' up to the first zero byte (at most 9 bytes), buf[0] = that index - 1;
 *     FUN_a0146b6c(0, 0), FUN_a0146b50(0xdf, 0), FUN_a00a31a4(0, 0x10, row of record 16, 9, buf, 0).
 *  2) n = (s << 5) | (e * 2) | 1 formatted with "nReg 0x0%x" (0x1004d8) for n <= 15, else "nReg 0x%2x" (0x1004e8);
 *     buf[0] = index of the first zero byte - 1; FUN_a00a31a4(0, 0xf, row of record 15, buf[0], buf, 0).
 * Records are the 3-byte {col, row, len} entries of the ROM table 0x100242; text by FUN_a01577f4 into a 9-byte cleared
 * buffer. Source form: the >> s shift is written in each arm of the e < 4 test (one shared shift after the if changes
 * the block order).
 */
struct Pos { unsigned char col, row, len; };

extern unsigned char DAT_a802afb8, DAT_a802afb9;
extern const struct Pos DAT_00100242[];
extern const char s_001004b8[], s_001004c8[], s_001004d8[], s_001004e8[], s_001004f8[];

extern void FUN_a01577f4(unsigned char *, const char *, ...);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, const char *, unsigned char);

void FUN_a008b5e0(void)
{
  unsigned char d[2];
  unsigned char buf[16];
  unsigned short v, n;
  unsigned char i, c, len;

  if (DAT_a802afb9 < 4)
    v = (0x4e >> (4 - DAT_a802afb9)) >> DAT_a802afb8;
  else
    v = (0x4e << (DAT_a802afb9 - 4)) >> DAT_a802afb8;

  d[0] = v / 100;
  d[1] = v % 100;
  for (i = 0; i < 9; i++)
    buf[i] = 0;
  if (d[0] > 10)
    FUN_a01577f4(buf, s_001004f8, d[0], d[1]);
  else if (d[1] > 10)
    FUN_a01577f4(buf, s_001004b8, d[0], d[1]);
  else
    FUN_a01577f4(buf, s_001004c8, d[0], d[1]);
  for (i = 0; i < 9; i++) {
    c = buf[i];
    if (c == 'S')
      buf[i] = '$';
    else if (c == 'P')
      buf[i] = '%';
    else if (c == 0)
      break;
  }
  buf[0] = i - 1;
  FUN_a0146b6c(0, 0);
  FUN_a0146b50(0xdf, 0);
  FUN_a00a31a4(0, 0x10, DAT_00100242[16].row, 9, buf, 0);

  n = (DAT_a802afb8 << 5) | (DAT_a802afb9 * 2) | 1;
  for (i = 0; i < 9; i++)
    buf[i] = 0;
  if (n <= 15)
    FUN_a01577f4(buf, s_001004d8, n);
  else
    FUN_a01577f4(buf, s_001004e8, n);
  for (i = 0; i < 9; i++)
    if (buf[i] == 0)
      break;
  len = i - 1;
  buf[0] = len;
  FUN_a00a31a4(0, 0xf, DAT_00100242[15].row, len, buf, 0);
}
