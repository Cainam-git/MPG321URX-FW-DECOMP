/* leon2m FUN_a0107e44 @ 0xa0107e44  FRCConfigPostFRC
 * Flags -mcpu=v8 -O3 -g -msoft-float (the image has no FPU instructions, float maths goes through libgcc
 * soft-float).
 *
 * Programs the output (post-FRC) timing for refresh value 'rate' (tenths of Hz). Prints "FRCConfigPostFRC %d".
 * Returns at once when rate equals the cached value at 0xA802C986 and force == 0; otherwise caches it.
 * From the active row (DAT_a802d6a4): vt1 = vtotal_min (+0x2A) + 1, ht starts at htotal_min (+0x20).
 *   clock (Hz) = (float)ht * vt1 * rate / 10.0  (single precision: __floatsisf, __mulsf3, __divsf3, __fixunssfsi;
 *   10.0 is the float constant at 0x198760). While ht < htotal_max (+0x24): stop at the first ht whose clock
 *   exceeds the row's clk_min (+0x10, 64-bit), else ht += 8. FUN_a01026e8(4, clock) = program the GPLL_FRC
 *   clock (see FUN_a01026e8: post-divider by range, n = f * 2^17 / 12 MHz, skipped when unchanged).
 *   d = (vt1 - row+0x0A - row+0x32 - row+0x30) & 0xFFF (at least 1, also stored at 0xA802D702);
 *   hblank = (ht - x - row+0x28 - row+0x26) & 0xFFF with x = row+0x0A when cls == 1, else row+0x08;
 *   s = row+0x2E - row+0x0A - row+0x32 - row+0x30 selects a shift: >= 0x4000 -> 3 (codes >= 0x84),
 *   0x2000..0x3FFF -> 2 (codes >= 0x84), 0x1000..0x1FFF -> 1 (codes > 0x82), else 0; written to bits 1-3 of
 *   0xCF011E40; row+0x30, row+0x32, d and row+0x0A are shifted right by it (each at least 1).
 *   Writes 0xCF011AC0..AF8 and 0xCF011C10..C58 (16-bit register pairs), bit 7 of 0xCF011AA0, bit 7 of 0xCF011A80
 *   when row+0x0A <= 0xFFF, bit 1 of 0xCF011A80, 0xCF011C00 = 0, 0xCF011C04 = 0x60, FUN_a011919c(0/1, 0x44, d'),
 *   FUN_a01191fc(0/1, 0xA5, 8, 1), 0xCF01340C = 0.
 * These 0xCF011Axx registers are the ones FUN_a010a884 / FUN_a010a9e8 read back as FRC-on htotal / vtotal.
 * Callers: FUN_a00dac38 (forced / class fallback rows, rate = halfword 0xA802E3CA), FUN_a013dc6c, FUN_a0148500, ...
 * In this path the output clock follows the input refresh rate (clock ~ htotal * vtotal * rate).
 * Source form:
 *   hx is not 8-bit and the first clock product has no 8-bit cast (both would change the meaning).
 *   The firmware updates 0xCF011E40 with TWO separate read-modify-writes in each branch (clear bits, then set one:
 *   ld/and/st, ld/or/st), not one combined write. cls is unsigned char (and 0xff in the firmware).
 *   The clock search loop is 'for (ht = DAT_a802d6a4->h20; ht < ->h24; ht += 8)' (the original re-reads h20 for
 *   the loop start after the first clock estimate). The opening field reads go through a local copy of the
 *   table pointer (p = DAT_a802d6a4), the loop start re-reads the global.
 *   Structure: both cls arms load h20, hx, h28, h26 in that order (p dies at the h26 load, sched1 emits it first ->
 *   fw arm order h26, h20, hx|h08, h28); the post-reload crossjump merges the two identical 'lduh h28 / sth [fp-10]'
 *   tails into the join -> join = 'lduh h28, sll %l0 -> %o1, sra' as fw.
 *   Locals declared vt1 h0a h30 h32 h26 hx h28 h2e ht (declaration order = allocno index = tie-break: h28 and hx
 *   both int 29, hx must win). Loads h0a, h30, h32, h2e (h2e last = delay slot).
 *   The three shift arms are written alike: a range test of s, then 'if (FUN_a011cf88() < code)' with the shift 0
 *   write (clear bits 1-3, shift = 0) in its then-arm and the arm's own write in the else-arm; GCC cross-jumps the
 *   three shift 0 writes and the final else into the one block at 0xa0107ff8, and the code tests sit out of line
 *   at 0xa0108308 / 0xa0108358 / 0xa01083b4. The 0x2000 and 0x1000 ranges are 's >= lo && s <= hi' (folded to the
 *   subtract-and-compare at 0xa0107fc4 / 0xa0107fe0).
 */

struct PanelParam
{
  unsigned int w0;
  unsigned short h4;
  unsigned char b6;
  unsigned char b7;
  unsigned short h08;
  unsigned short h0a;
  unsigned char b0c[4];
  unsigned long long clk_min;
  unsigned long long clk_max;
  unsigned short h20;
  unsigned short h22;
  unsigned short h24;
  unsigned short h26;
  unsigned short h28;
  unsigned short h2a;
  unsigned short h2c;
  unsigned short h2e;
  unsigned short h30;
  unsigned short h32;
};
extern struct PanelParam *DAT_a802d6a4;
extern unsigned short DAT_a802c986;
extern unsigned short DAT_a802d702;
extern int FUN_a00df170();
extern char s_0019aba8[];
extern void FUN_a01026e8(int, unsigned int);
extern unsigned char FUN_a011cf88(void);
extern void FUN_a00f308c(unsigned int, unsigned int);
extern void FUN_a011919c(int, int, unsigned int);
extern void FUN_a01191fc(int, int, int, int);
void FUN_a0107e44(unsigned char cls, unsigned short rate, unsigned char force)
{
  struct PanelParam *p;
  unsigned short vt1;
  unsigned short h0a;
  unsigned short h30;
  unsigned short h32;
  unsigned short h26;
  unsigned short hx;
  unsigned short h28;
  unsigned short h2e;
  unsigned short ht;
  unsigned short sh_v;
  unsigned short sh_h;
  unsigned short d;
  unsigned short a;
  unsigned short b;
  unsigned short c;
  unsigned short e;
  unsigned int clk;
  unsigned char shift;
  if (DAT_a802c986 == rate && force == 0)
  {
    return;
  }
  DAT_a802c986 = rate;
  FUN_a00df170(s_0019aba8, rate);
  p = DAT_a802d6a4;
  h0a = p->h0a;
  h30 = p->h30;
  h32 = p->h32;
  h2e = p->h2e;
  vt1 = p->h2a + 1;
  if (cls == 1)
  {
    ht = p->h20; hx = h0a; h28 = p->h28; h26 = p->h26;
  }
  else { ht = p->h20; hx = p->h08; h28 = p->h28; h26 = p->h26; }
  clk = (float) ht * vt1 * rate / 10.0f;
  for (ht = DAT_a802d6a4->h20; ht < DAT_a802d6a4->h24; ht += 8)
  {
    clk = (float) ht * vt1 * rate / 10.0f;
    if (clk > DAT_a802d6a4->clk_min)
    {
      break;
    }
  }
  FUN_a01026e8(4, clk);
  sh_h = (ht - hx - h28 - h26) & 0xfff;
  d = (vt1 - h0a - h32 - h30) & 0xfff;
  sh_v = h2e - h0a - h32 - h30;
  if (d == 0)
  {
    d = 1;
  }
  if (sh_v > 0x3fff)
  {
    if (FUN_a011cf88() < 0x84)
    {
      *((volatile unsigned int *) 0xcf011e40) = (*((volatile unsigned int *) 0xcf011e40)) & (~0xe);
      shift = 0;
    }
    else
    {
      *((volatile unsigned int *) 0xcf011e40) = (*((volatile unsigned int *) 0xcf011e40)) & (~0xc);
      *((volatile unsigned int *) 0xcf011e40) = (*((volatile unsigned int *) 0xcf011e40)) | 2;
      shift = 3;
    }
  }
  else if (sh_v >= 0x2000 && sh_v <= 0x3fff)
  {
    if (FUN_a011cf88() < 0x84)
    {
      *((volatile unsigned int *) 0xcf011e40) = (*((volatile unsigned int *) 0xcf011e40)) & (~0xe);
      shift = 0;
    }
    else
    {
      *((volatile unsigned int *) 0xcf011e40) = (*((volatile unsigned int *) 0xcf011e40)) & (~0xa);
      *((volatile unsigned int *) 0xcf011e40) = (*((volatile unsigned int *) 0xcf011e40)) | 4;
      shift = 2;
    }
  }
  else if (sh_v >= 0x1000 && sh_v <= 0x1fff)
  {
    if (FUN_a011cf88() < 0x83)
    {
      *((volatile unsigned int *) 0xcf011e40) = (*((volatile unsigned int *) 0xcf011e40)) & (~0xe);
      shift = 0;
    }
    else
    {
      *((volatile unsigned int *) 0xcf011e40) = (*((volatile unsigned int *) 0xcf011e40)) & (~0x6);
      *((volatile unsigned int *) 0xcf011e40) = (*((volatile unsigned int *) 0xcf011e40)) | 8;
      shift = 1;
    }
  }
  else
  {
    *((volatile unsigned int *) 0xcf011e40) = (*((volatile unsigned int *) 0xcf011e40)) & (~0xe);
    shift = 0;
  }
  DAT_a802d702 = d;
  a = h30 >> (shift & 3);
  if (a == 0)
  {
    a = 1;
  }
  b = h32 >> (shift & 3);
  if (b == 0)
  {
    b = 1;
  }
  c = (d & 0xfff) >> (shift & 3);
  if (c == 0)
  {
    c = 1;
  }
  e = h0a >> (shift & 3);
  if (e == 0)
  {
    e = 1;
  }
  FUN_a00f308c(0xcf011ac0, h26);
  FUN_a00f308c(0xcf011ac8, sh_h & 0xfff);
  FUN_a00f308c(0xcf011ad0, h28);
  FUN_a00f308c(0xcf011ad8, hx);
  FUN_a00f308c(0xcf011ae0, a);
  FUN_a00f308c(0xcf011ae8, c);
  FUN_a00f308c(0xcf011af0, b);
  FUN_a00f308c(0xcf011af8, e);
  *((volatile unsigned int *) 0xcf011aa0) = (*((volatile unsigned int *) 0xcf011aa0)) | 0x80;
  FUN_a00f308c(0xcf011c10, sh_h & 0xfff);
  FUN_a00f308c(0xcf011c18, hx);
  FUN_a00f308c(0xcf011c20, ht);
  FUN_a00f308c(0xcf011c28, c);
  FUN_a00f308c(0xcf011c30, e);
  FUN_a00f308c(0xcf011c38, vt1);
  FUN_a00f308c(0xcf011c40, 0);
  FUN_a00f308c(0xcf011c48, vt1 >> 1);
  FUN_a00f308c(0xcf011c50, 0);
  FUN_a00f308c(0xcf011c58, 0);
  if (DAT_a802d6a4->h0a <= 0xfff)
  {
    *((volatile unsigned int *) 0xcf011a80) = (*((volatile unsigned int *) 0xcf011a80)) | 0x80;
  }
  *((volatile unsigned int *) 0xcf011a80) = (*((volatile unsigned int *) 0xcf011a80)) | 2;
  *((volatile unsigned int *) 0xcf011c00) = 0;
  *((volatile unsigned int *) 0xcf011c04) = 0x60;
  FUN_a011919c(0, 0x44, c);
  FUN_a011919c(1, 0x44, c);
  FUN_a01191fc(0, 0xa5, 8, 1);
  FUN_a01191fc(1, 0xa5, 8, 1);
  *((volatile unsigned int *) 0xcf01340c) = 0;
}
