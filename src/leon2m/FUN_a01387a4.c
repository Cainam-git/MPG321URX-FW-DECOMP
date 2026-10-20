/*
 * FUN_a01387a4 - mailbox reader (Big chip, leon2m). '-mcpu=v8 -O3 -g -msoft-float'
 * (jf 100.00 % match=True; rawcmp a01387a4..a0138ae8: 209 words, 0 mismatches).
 *
 * What it does: calls FUN_a01350dc and FUN_a0134de0, reads 4 header words from mailbox portal 1 offset 0
 * (func_0x4008c4d0) and sets the type nibble of the 7 template slots DAT_a802dec0[0..6]; reads the word at
 * offset 0xC (byte 2 = mask "ma"); then for each of 7 record ids reads 4 words at offset id << 4, checks the record
 * number against DAT_a802a450[i] (1..9) and copies flags/fields into template slot rec[0]-1. Type 5 records get the
 * full field copy (and are set to type 2 when their bit is set in ma); others just set their bit in 'mask'.
 * The first time (DAT_a802cb98 == 0) it debug-prints the 4 record words. At the end, if ma and mask are nonzero
 * and (mask & ma) & 0xff is nonzero, it debug-prints that value and sends a 12-byte message {value, 0...} via
 * FUN_a01370dc(0x81, 0xc, m, 0).
 * Inputs: none. Output: none. Globals: DAT_a802dec0[] (templates, written), DAT_a802a450[] (read),
 * DAT_a802cb98 (print-once flag, written).
 *
 * Matching notes:
 * - The debug-level test is a small static function dbg_on() ("if (FUN_a00dd614(l)) return 1; return 0;"),
 *   inlined. Its inlined return paths leave labels that stop gcc's cse1 from skipping around the debug-print
 *   block (-fcse-skip-blocks), so the stored byte y keeps its own register (firmware 'mov %i4,%l1' + 'stb %l1').
 *   With a plain 'if (FUN_a00dd614(0x20))' cse1 replaces y by the and result (97.61 %). dbg_on() is used for
 *   all three prints (also matches with it used only for the last one).
 * - End value: uint x = (unsigned char)(n & mb2) for the test and the print, u8 y = n & mb2 for m[0]
 *   (n = mask first gives the firmware's and operand order).
 */
extern void *memset(void *, int, unsigned int);
struct Tmpl
{
  unsigned char type;
  unsigned char b1;
  unsigned short w2;
  unsigned short w4;
  unsigned short w6;
  unsigned short w8;
  unsigned short wa;
  unsigned char flags;
  unsigned char bd;
  unsigned char be;
  unsigned char bf;
};
extern struct Tmpl DAT_a802dec0[];
extern unsigned char DAT_a802a450[];
extern unsigned char DAT_a802cb98;
extern char s_001a5630[];
extern char s_001a5640[];
extern char s_001a5658[];
extern void func_0x4008c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern unsigned char FUN_a00dd614(unsigned int level);
extern int FUN_a00df170();
extern void FUN_a01370dc();
extern void FUN_a01350dc(void);
extern void FUN_a0134de0(void);
static int dbg_on(unsigned int l)
{
  if (FUN_a00dd614(l))
    return 1;
  return 0;
}
void FUN_a01387a4(void)
{
  unsigned short ids[7];
  unsigned int buf2[4];
  unsigned int rec[4];
  unsigned int hdr[4];
  unsigned char m[12];
  unsigned int mbw;
  unsigned short mask = 0;
  unsigned short ma;
  unsigned char mb2;
  unsigned char i;
  unsigned char j;
  unsigned int x;
  unsigned char k;
  unsigned char y;
  unsigned char n = 7;
  struct Tmpl *t;
  FUN_a01350dc();
  FUN_a0134de0();
  ids[0] = 1;
  ids[1] = 2;
  ids[2] = 3;
  ids[3] = 4;
  ids[4] = 5;
  ids[5] = 6;
  ids[6] = 7;
  for (i = 0; i < 4; i++)
  {
    buf2[i] = 0;
    rec[i] = 0;
  }

  func_0x4008c4d0(1, 0, hdr, 4);
  for (i = 0; i < n; i++)
  {
    DAT_a802dec0[i].type = ((hdr[0] >> 4) >> (i * 4)) & 0xf;
  }

  func_0x4008c4d0(1, 0xc, &mbw, 1);
  ma = (unsigned char) (mbw >> 16);
  mb2 = ma;
  for (i = 0; i < 7; i++)
  {
    func_0x4008c4d0(1, (unsigned char) (ids[i] << 4), rec, 4);
    if ((((unsigned char) rec[0]) != DAT_a802a450[i]) || ((DAT_a802a450[i] - 1U) > 8))
    {
      continue;
    }
    k = rec[0] - 1;
    t = &DAT_a802dec0[k];
    t->flags = rec[0] >> 8;
    t->bd = rec[0] >> 16;
    if (DAT_a802dec0[k].type == 5)
    {
      t->b1 = rec[1];
      t->be = (rec[1] >> 8) & 0x1f;
      t->w2 = rec[1] >> 16;
      t->w4 = rec[2];
      t->w6 = rec[2] >> 16;
      t->w8 = rec[3];
      t->wa = rec[3] >> 16;
      if ((ma >> i) & 1)
      {
        DAT_a802dec0[k].type = 2;
        mask |= 1 << i;
      }
      if (DAT_a802cb98 == 0)
      {
        DAT_a802cb98 = 1;
        for (j = 0; j < 4; j++)
        {
          if (dbg_on(0x20))
            {
              FUN_a00df170(s_001a5640, j);
            }
          if (dbg_on(0x20))
            {
              FUN_a00df170(s_001a5630, rec[j]);
            }
        }

      }
    }
    else
    {
      mask |= 1 << i;
    }
  }

  if (ma != 0)
  {
    if (mask != 0)
    {
      n = mask;
      x = (unsigned char) (n & mb2);
      y = n & mb2;
      if (x != 0)
      {
        if (dbg_on(0x20))
          FUN_a00df170(s_001a5658, x);
        memset(m, 0, 12);
        m[0] = y;
        FUN_a01370dc(0x81, 0xc, m, 0);
      }
    }
  }
}
