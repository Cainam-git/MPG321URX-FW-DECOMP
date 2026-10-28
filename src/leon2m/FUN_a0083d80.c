/* leon2m FUN_a0083d80 @ 0xa0083d80-0xa0083ff0 (624 bytes), flags -mcpu=v8 -O3 -g.
 * Prints bytes 1..3 of DAT_a8024010 with s_000fef18. Returns 0xff when DAT_a802d2af != 0. Otherwise r is the
 * index (0..2, last match wins, 0xff for none) of the row of the local table {08 00 46, 00 09 bf, 00 03 ff} equal
 * to DAT_a8024010[1..3]. For r == 0 the four bytes DAT_a8024018[1..4] must read "Play" (flag f), else r = 0xff.
 * For r == 0xff, r becomes the index of the matching row of the local name table {"Play", "Nint", "XBOX"}
 * compared with DAT_a8024018[1..4] (0xff for none). Prints r with s_000fef28 and returns it.
 * Source form: f is set in both arms of an if/else, the r == 0 block stores 'r = 0' again before the
 * 'if (!f) r = 0xff;' test, and the name search is a separate 'if (r == 0xff)' block.
 */
extern unsigned char DAT_a8024010[], DAT_a8024018[];
extern unsigned char DAT_a802d2af;
extern char s_000fef18[], s_000fef28[];
extern int FUN_a00df170(const char *fmt, ...);

unsigned char FUN_a0083d80(void)
{
  unsigned char r = 0xff;
  unsigned char tab[3][3] = { { 0x08, 0x00, 0x46 }, { 0x00, 0x09, 0xbf }, { 0x00, 0x03, 0xff } };
  unsigned char i;
  int f;

  FUN_a00df170(s_000fef18, DAT_a8024010[1], DAT_a8024010[2], DAT_a8024010[3]);
  if (DAT_a802d2af != 0)
    return 0xff;
  for (i = 0; i < 3; i++)
    if (tab[i][0] == DAT_a8024010[1] && tab[i][1] == DAT_a8024010[2] && tab[i][2] == DAT_a8024010[3])
      r = i;
  if (r == 0) {
    if (DAT_a8024018[1] == 'P' && DAT_a8024018[2] == 'l' && DAT_a8024018[3] == 'a' && DAT_a8024018[4] == 'y')
        f = 1;
    else
        f = 0;
    r = 0;
    if (!f)
      r = 0xff;
  }
  if (r == 0xff) {
    unsigned char names[3][4] = { { 'P', 'l', 'a', 'y' }, { 'N', 'i', 'n', 't' }, { 'X', 'B', 'O', 'X' } };

    r = 0xff;
    for (i = 0; i < 3; i++)
      if (names[i][0] == DAT_a8024018[1] && names[i][1] == DAT_a8024018[2] && names[i][2] == DAT_a8024018[3]
          && names[i][3] == DAT_a8024018[4])
        r = i;
  }
  FUN_a00df170(s_000fef28, r);

  return r;
}
