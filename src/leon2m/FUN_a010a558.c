/* leon2m FUN_a010a558 @ 0xa010a558 (179 words), flags -mcpu=v8 -O3 -g. Compiler aids: none.
 * What it does: if en != 0, logs s_0019acb0, reads the transformed 0x58-byte row *DAT_a802d6a4 (h0a
 * width, h2c total, h22, h30, h32), programs the 0xCF01E4xx / 0xCF01E6xx / 0xCF01EAxx timing registers (16-bit
 * values split into low byte / high byte register pairs), and calls the inlined FUN_a010a4d0 (reads a 16-bit counter
 * via FUN_a0106274(0) or FUN_a00f3078, >> 2, into 0xCF01EAC4/0xCF01EAC0).
 * Source form: FUN_a010a4d0's FUN_a00f3078 arm goes through an early-return u16 inline function rdx() ('if (bit7)
 * return f(ad8); return f(c18);'): its return conversion gives the fw's extend-into-temp + 'mov' copy; every if/else
 * or ternary form folds the extension into v. FUN_a010a4d0 itself also matches on its own
 * (src/leon2m/FUN_a010a4d0.c).
 */
#define R(a) (*(volatile unsigned int *)(a))
struct PanelParam
{
  unsigned char p00[0x0a];
  unsigned short h0a;
  unsigned char p0c[0x16];
  unsigned short h22;
  unsigned char p24[8];
  unsigned short h2c;
  unsigned short h2e;
  unsigned short h30;
  unsigned short h32;
};
extern struct PanelParam *DAT_a802d6a4;
extern char s_0019acb0[];
extern int FUN_a00df170();
extern unsigned short FUN_a0106274(unsigned char);
extern int FUN_a00f3078(int);

#define wr16(a, v) (R(a) = (unsigned char)(v), R((a) + 4) = (unsigned short)(v) >> 8)

static unsigned short rdx(void)
{
  if (R(0xcf011a80) & 0x80)
    return FUN_a00f3078(0xcf011ad8);
  return FUN_a00f3078(0xcf011c18);
}
static void FUN_a010a4d0(void)
{
  unsigned short v;
  if (R(0xcf011a80) & 1)
    v = FUN_a0106274(0);
  else
    v = rdx();
  v >>= 2;
  R(0xcf01eac4) = v & 0xff;
  R(0xcf01eac0) = (v >> 8) | 0x80;
}

void FUN_a010a558(unsigned char en)
{
  struct PanelParam *p;
  unsigned short w, tot, h22, h30, h32, div, blank, x;
  unsigned int t, n;

  if (en == 0) return;
  FUN_a00df170(s_0019acb0);
  p = DAT_a802d6a4;
  w = p->h0a;
  R(0xcf01e404) = 0x10;
  wr16(0xcf01ea44, w);
  tot = p->h2c;
  h30 = p->h30;
  h22 = p->h22;
  h32 = p->h32;
  blank = (tot - w - h32 - h30) & 0x1fff;
  wr16(0xcf01ea4c, w);
  div = (tot - w > 0x11) ? tot : w + 0x12;
  R(0xcf01e684) |= 0x10;
  R(0xcf01e688) |= 0x10;
  t = (unsigned int)(tot * h22) / div & ~1;
  R(0xcf01e68c) &= ~0x10;
  x = t - w - 64;
  n = 0x20 - (w & 0x1f);
  FUN_a010a4d0();
  R(0xcf01ea80) = 0x20;
  R(0xcf01ea84) = 0;
  wr16(0xcf01ea88, x);
  R(0xcf01ea90) = 0x20;
  R(0xcf01ea94) = 0;
  wr16(0xcf01ea98, w);
  wr16(0xcf01eaa0, h30);
  if (R(0xcf01eac0) & 0x80) {
    R(0xcf01eaa8) = 0xff;
    R(0xcf01eaac) = 0x1f;
  } else
    wr16(0xcf01eaa8, blank);
  wr16(0xcf01eab0, h32);
  wr16(0xcf01eab8, w);
  R(0xcf01e9c8) |= 0x10;
  R(0xcf01e9dc) = n & 0xff;
  R(0xcf01e660) = 0xc0;
  R(0xcf01e664) = 0xc0;
}
