/* leon2m FUN_a01483f4 @ 0xa01483f4  Flags: -mcpu=v8 -O3 -g.
 *
 * Makes src the active panel parameter row: copies the 0x58-byte row (one of the three rows of the table at
 * 0x198380, chosen by FUN_a00dac38) byte by byte to 0xA802E378, prints its clock limits, H-total and V-total
 * ("clk %ld, %ld", "Htoal %d %d %d", "Vtoal %d %d %d"), derives two fields, then:
 *   FUN_a0141840()  builds the transformed copy at 0xA802D6A8 (row byte +6 replaced by the display mode from
 *                   FUN_a0151c84, word0 bits 20-22 remapped) and points DAT_a802d6a4 at it;
 *   apply != 0 ->   FUN_a01023f4(0) programs the output timing registers from it.
 * Derived fields: +0x26 = +0x28 = (htot_min - field +0x08) / 48 * 16 (signed division), and +0x48 =
 * clk_min / htot_min / vtot_min * 10 (refresh rate at the minimum clock, tenths of Hz; 64-bit divides).
 * Row layout used here (all big-endian): +0x08 u16, +0x10 u64 clk_min (Hz), +0x18 u64 clk_max (Hz),
 * +0x20/22/24 htotal min/typ/max, +0x2A/2C/2E vtotal min/typ/max, +0x4A/4C min/max hfreq, +0x4E/50 min/max
 * vfreq (tenths of Hz; row 2 (<62 Hz) max 600).
 * Callers: FUN_a00dac38 (apply 1 when the row changes by measurement, 0 for the class fallback to row 1) and
 * FUN_a0129810.
 */
struct PanelRow
{
  unsigned char b00[8];
  unsigned short f08;
  unsigned char b0a[6];
  unsigned long long clk_min;
  unsigned long long clk_max;
  unsigned short htot_min;
  unsigned short htot_typ;
  unsigned short htot_max;
  unsigned short f26;
  unsigned short f28;
  unsigned short vtot_min;
  unsigned short vtot_typ;
  unsigned short vtot_max;
  unsigned char b30[0x18];
  unsigned short vf_at_min_clk;
  unsigned short hf_min;
  unsigned short hf_max;
  unsigned short vf_min;
  unsigned short vf_max;
  unsigned char b52[6];
};
extern struct PanelRow DAT_a802e378;
extern int FUN_a00df170();
extern char s_001a6e90[];
extern char s_001a6ea0[];
extern char s_001a6eb8[];
extern void FUN_a0141840(void);
extern void FUN_a01023f4(int);
void FUN_a01483f4(unsigned char *src, unsigned char apply)
{
  unsigned short i;
  unsigned char *new_var;
  for (i = 0; i < 0x58; i++)
  {
    ((unsigned char *) (&DAT_a802e378))[i] = (new_var = src)[i];
  }

  FUN_a00df170(s_001a6e90, DAT_a802e378.clk_min, DAT_a802e378.clk_max);
  FUN_a00df170(s_001a6ea0, DAT_a802e378.htot_min, DAT_a802e378.htot_typ, DAT_a802e378.htot_max);
  FUN_a00df170(s_001a6eb8, DAT_a802e378.vtot_min, DAT_a802e378.vtot_typ, DAT_a802e378.vtot_max);
  DAT_a802e378.f28 = (DAT_a802e378.f26 = ((DAT_a802e378.htot_min - DAT_a802e378.f08) / 48) * 16);
  DAT_a802e378.vf_at_min_clk = ((DAT_a802e378.clk_min / DAT_a802e378.htot_min) / DAT_a802e378.vtot_min) * 10;
  FUN_a0141840();
  if (apply)
  {
    FUN_a01023f4(0);
  }
}
