/* leon2m FUN_a008a568 @ 0xa008a568-0xa008a778 (132 words), flags -mcpu=v8 -O3 -g.
 * void(u8 id, u16 v); called from FUN_a008b83c, FUN_a008c25c, FUN_a008d2f8 and FUN_a008abe0. Draws v as digits at
 * the 3-byte record {col, row, len} id of the ROM table 0x100242:
 *   id 1..12: "%3d" (0x100480), FUN_a0146af4(0, col + 1, row, 3, buf, 0);
 *   id 15, 16: "%1d" (0x100478), FUN_a0146af4(0, col + len, row, 1, buf, 0);
 *   other ids: "%3d", FUN_a0146af4(0, col + len, row, 3, buf, 0).
 * Text is formatted with FUN_a01577f4, then each character is mapped: space -> 0, otherwise character - 47.
 * The position bytes are read before the formatting call. Source form: the last case uses its own loop counter j
 * (with the shared counter i the delay slot of the loop entry jump holds a different instruction).
 */
struct Pos { unsigned char col, row, len; };

extern const struct Pos DAT_00100242[];
extern const char s_00100478[], s_00100480[];

extern void FUN_a01577f4(unsigned char *, const char *, unsigned short);
extern void FUN_a0146af4(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char *, unsigned char);

void FUN_a008a568(unsigned char id, unsigned short v)
{
  unsigned char i, x, y, j;


  if ((unsigned char)(id - 1) < 12) {
    unsigned char c[8];

    x = DAT_00100242[id].col + 1;
    y = DAT_00100242[id].row;
    FUN_a01577f4(c, s_00100480, v);
    for (i = 0; i < 3; i++) {
      if (c[i] == ' ')
        c[i] = 0;
      else
        c[i] -= 47;
    }
    FUN_a0146af4(0, x, y, 3, c, 0);
  } else if ((unsigned char)(id - 15) < 2) {
    unsigned char a[1];

    x = DAT_00100242[id].col + DAT_00100242[id].len;
    y = DAT_00100242[id].row;
    FUN_a01577f4(a, s_00100478, v);
    for (i = 0; i < 1; i++) {
      if (a[i] == ' ')
        a[i] = 0;
      else
        a[i] -= 47;
    }
    FUN_a0146af4(0, x, y, 1, a, 0);
  } else {
    unsigned char b[8];

    x = DAT_00100242[id].col + DAT_00100242[id].len;
    y = DAT_00100242[id].row;
    FUN_a01577f4(b, s_00100480, v);
    for (j = 0; j < 3; j++) {
      if (b[j] == ' ')
        b[j] = 0;
      else
        b[j] -= 47;
    }
    FUN_a0146af4(0, x, y, 3, b, 0);
  }
}
