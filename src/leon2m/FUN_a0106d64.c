/* leon2m FUN_a0106d64 @ 0xa0106d64  output path setup, variant B
 * Flags: -mcpu=v8 -O3 -g.
 *
 * Called by FUN_a015373c (one call site, a0153954, after DispModeTransform) with a 36-byte output configuration,
 * which it copies word by word to 0xA802D680 (the same record FUN_a0105150 writes; FUN_a01023f4 reads +0x08 there,
 * the display mode). Row = *DAT_a802d6a4 (the transformed panel row).
 *   0xCF00ED58 = config byte +0x0C (zero-extended, unconditional; byte +0x0D is not read here);
 *   0xCF00ED5C = 0x20 when (row word0 & 0x700000) == 0x200000 and (unsigned char)(row byte +6 - 8) <= 2
 *   (display mode 8..10), else 0x40; 0xCF00EDA8 = config byte +0x14; with that same condition also
 *   FUN_a00f2298(0, 0x8D, 8).
 *   FUN_a01023f4(0): output timing registers from the row.
 *   x = row word +0x34 / 10 * row halfword +0x22; FUN_a01026e8(0, x), (1, x/2), (2, x/2), (3, x/4).
 *   If config byte +0 and halfword +0x10 are non-zero: f = +0x10 (25..500, else 100), a = +0x12 (5..5000, else
 *   150); 0xCF012898 and 0xCF012998 = 1500 / f (then bit 7 set), 0xCF01289C and 0xCF01299C =
 *   (a * f * 32768, 32-bit) / 15000000 (the original divides by 15,000,000: gcc pre-shifts by 6 and multiplies,
 *   which is why the code shows >> 6 and a 234375 reciprocal); bit 0 of 0xCF012890 / 0xCF012990 = row word0 bit 26.
 *   Otherwise bit 0 of 0xCF012890 / 0xCF012990 is cleared. (0xCF012884.. and 0xCF012984.. are the clock meters 0
 *   and 4 of FUN_a0102fd0, so these are the two output clock paths.)
 *   0xCF00B81C.. via FUN_a00f308c (16-bit register pair writes): row +0x30, +0x26, +0x26 + +0x28, +0x30 + +0x32.
 * Display modes 5 (FW.021 60 Hz row) and 11 (FW.012) behave the same here (neither is 8..10).
 * keys (the f/a clamp, found with RTL dumps):
 *   - h12 is read into its own unsigned short (a0) together with h10 into an unsigned int (t) BETWEEN the b0 test
 *     and the h10 != 0 test: that puts 'lduh +0x12' in the bne delay slot and keeps a0 (%o5) apart from a (%o4).
 *   - f is RE-READ from the record (f = DAT_a802d680.h10, not f = t): the second load keeps the record pointer live
 *     past the h12 load (so a0 cannot take its register) and postreload turns it into 'mov %g1,%o3'.
 *   - 'a = a0;' comes BEFORE the f range check (written in its natural form f < 25 || f > 500, folded by gcc into
 *     (u16)(f - 25) > 475); with 'a = a0' after the f check the f = 100 block stays inline (bgu,a) instead of out
 *     of line.
 *   - the three bit-0 clears (no b0, no h10, row bit 26 clear) are separate source copies; gcc merges two of them.
 *   - no inline function is needed for f - 25.
 */

struct OutCfg
{
  unsigned char b0;
  unsigned char b1;
  unsigned char b2;
  unsigned char b3;
  unsigned int w4;
  unsigned int w8;
  unsigned char bc;
  unsigned char bd;
  unsigned char be;
  unsigned char bf;
  unsigned short h10;
  unsigned short h12;
  unsigned char b14;
  unsigned char b15;
  unsigned char b16;
  unsigned char b17;
  unsigned int w18;
  unsigned int w1c;
  unsigned int w20;
};
struct PanelParam
{
  unsigned int w0;
  unsigned short h4;
  unsigned char b6;
  unsigned char b7;
  unsigned char b08[0x1a];
  unsigned short h22;
  unsigned char b24[2];
  unsigned short h26;
  unsigned short h28;
  unsigned char b2a[6];
  unsigned short h30;
  unsigned short h32;
  unsigned int w34;
};
extern struct OutCfg DAT_a802d680;
extern struct PanelParam *DAT_a802d6a4;
extern void FUN_a00f2298(int, int, int);
extern void FUN_a01023f4(int);
extern void FUN_a01026e8(int, unsigned int);
extern void FUN_a00f308c(unsigned int, unsigned int);
void FUN_a0106d64(struct OutCfg *cfg)
{
  unsigned int x;
  unsigned short f;
  unsigned short a;
  unsigned int t;
  unsigned short a0;
  DAT_a802d680 = *cfg;
  *((volatile unsigned int *) 0xcf00ed58) = DAT_a802d680.bc;
  if (((DAT_a802d6a4->w0 & 0x700000) == 0x200000) && (((unsigned char) (DAT_a802d6a4->b6 - 8)) <= 2))
  {
    *((volatile unsigned int *) 0xcf00ed5c) = 0x20;
  }
  else
  {
    *((volatile unsigned int *) 0xcf00ed5c) = 0x40;
  }
  *((volatile unsigned int *) 0xcf00eda8) = DAT_a802d680.b14;
  if (((DAT_a802d6a4->w0 & 0x700000) == 0x200000) && (((unsigned char) (DAT_a802d6a4->b6 - 8)) <= 2))
  {
    FUN_a00f2298(0, 0x8d, 8);
  }
  FUN_a01023f4(0);
  x = (DAT_a802d6a4->w34 / 10) * DAT_a802d6a4->h22;
  FUN_a01026e8(0, x);
  FUN_a01026e8(1, x >> 1);
  FUN_a01026e8(2, x >> 1);
  FUN_a01026e8(3, x >> 2);
  if (DAT_a802d680.b0 != 0)
  {
    t = DAT_a802d680.h10;
    a0 = DAT_a802d680.h12;
    if (t != 0)
    {
    f = DAT_a802d680.h10;
    a = a0;
    if ((f < 25) || (f > 500)) f = 100;
    if ((a < 5) || (a > 5000)) a = 150;
    *((volatile unsigned int *) 0xcf012898) = (unsigned char) (1500 / f);
    *((volatile unsigned int *) 0xcf01289c) = (unsigned char) (((((unsigned int) a) * f) << 15) / 15000000);
    *((volatile unsigned int *) 0xcf012898) = (*((volatile unsigned int *) 0xcf012898)) | 0x80;
    *((volatile unsigned int *) 0xcf012998) = (unsigned char) (1500 / f);
    *((volatile unsigned int *) 0xcf01299c) = (unsigned char) (((((unsigned int) a) * f) << 15) / 15000000);
    *((volatile unsigned int *) 0xcf012998) = (*((volatile unsigned int *) 0xcf012998)) | 0x80;
    if (DAT_a802d6a4->w0 & 0x4000000)
    {
      *((volatile unsigned int *) 0xcf012890) = (*((volatile unsigned int *) 0xcf012890)) | 1;
      *((volatile unsigned int *) 0xcf012990) = (*((volatile unsigned int *) 0xcf012990)) | 1;
    }
    else
    {
      *((volatile unsigned int *) 0xcf012890) = (*((volatile unsigned int *) 0xcf012890)) & (~1);
      *((volatile unsigned int *) 0xcf012990) = (*((volatile unsigned int *) 0xcf012990)) & (~1);
    }
    }
    else
    {
    *((volatile unsigned int *) 0xcf012890) = (*((volatile unsigned int *) 0xcf012890)) & (~1);
    *((volatile unsigned int *) 0xcf012990) = (*((volatile unsigned int *) 0xcf012990)) & (~1);
    }
  }
  else
  {
    *((volatile unsigned int *) 0xcf012890) = (*((volatile unsigned int *) 0xcf012890)) & (~1);
    *((volatile unsigned int *) 0xcf012990) = (*((volatile unsigned int *) 0xcf012990)) & (~1);
  }
  FUN_a00f308c(0xcf00b81c, DAT_a802d6a4->h30);
  FUN_a00f308c(0xcf00b824, DAT_a802d6a4->h26);
  FUN_a00f308c(0xcf00b82c, DAT_a802d6a4->h26 + DAT_a802d6a4->h28);
  FUN_a00f308c(0xcf00b834, DAT_a802d6a4->h30 + DAT_a802d6a4->h32);
}
