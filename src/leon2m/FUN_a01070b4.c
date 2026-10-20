/* -mcpu=v8 -O3 -g (hand, finished with a short computer search; jf 100, ).
 * leon2m FUN_a01070b4 @ 0xa01070b4  drv_PanelLimitation (hand)
 *
 * ADVISORY check of the current timing against the active panel row (DAT_a802d6a4, the transformed copy):
 * it only prints warnings and returns a bitmask, and its only caller FUN_a014e8d8 discards the result.
 *   input vfreq   = FUN_a0120b38(0) (tenths of Hz)  vs row +0x4E/+0x50 -> bits 0x10 (<min) / 0x20 (>max)
 *   FRC off (FUN_a010a864() == 0, prints "[drv_PanelLimitation] FRC OFF"): clock = FUN_a0102fd0(0) MHz,
 *       display htotal = FUN_a00f25f8(0, 0x5E), display vtotal = FUN_a00f25f8(0, 0x5B)
 *   FRC on ("... FRC ON"): clock = FUN_a0102fd0(4), htotal = FUN_a010a884(), vtotal = FUN_a010a9e8(), and when
 *       0xCF011EC0 bit 6 is set vtotal = clock * 10000 / htotal * 1000 / vfreq
 *   display hfreq = clock * 10000 / htotal  vs row +0x4A/+0x4C -> bits 1 / 2
 *   clock (MHz)  vs row clk_min/clk_max (+0x10/+0x18, Hz, / 10^6) -> bits 4 / 8 ("display out of range")
 *   htotal       vs row +0x20/+0x24 -> bits 0x40 / 0x80;  vtotal vs row +0x2A/+0x2E -> warning only
 * On the <62 Hz row an input vfreq of 601 (above 600) sets bit 0x20 and prints
 * "input vfreq(601) > PANEL_MAX_VFREQ(600)" on FW.012 and FW.021 alike; nothing acts on the result.
 * Source facts: the callees return unsigned short. The autoc draft has an extra FUN_a010a9e8 call in the FRC-off
 *   path; the firmware calls it once, at 0xa010723c, FRC-on path only. The firmware zero-extends FUN_a0102fd0's
 *   result (sll/srl 16); 'short clk' sign-extends and is the wrong type.
 * Types read from where the firmware narrows to 16 bits: clk = unsigned int
 *   (FUN_a0102fd0 u16: narrowed right after the call); htot/vtot = unsigned int, FUN_a010a9e8 declared
 *   int-returning (FUN_a010a884 may keep its real u16, same code) (FRC-on: raw 'mov %o0', no narrowing after the call) and FUN_a00f25f8 u16 (FRC-off: narrowed after
 *   the call); htot narrowed again at the division = an inline helper calc_hf(unsigned int clk, unsigned short htot)
 *   (same code as a cast); vtot narrowed at its compares/prints ((unsigned short)vtot).
 */

struct PanelParam
{
  unsigned char b00[0x10];
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
  unsigned short f48;
  unsigned short hf_min;
  unsigned short hf_max;
  unsigned short vf_min;
  unsigned short vf_max;
  unsigned char b52[6];
};
extern struct PanelParam *DAT_a802d6a4;
extern int FUN_a0120b38(int);
extern unsigned char FUN_a010a864(void);
extern unsigned short FUN_a0102fd0(int);
extern unsigned short FUN_a00f25f8(int, int);
extern int FUN_a010a884(void);
extern int FUN_a010a9e8(void);
extern int FUN_a00df170();
extern unsigned long long FUN_a0155208(unsigned long long, unsigned long long);
extern char s_0019a900[];
extern char s_0019a938[];
extern char s_0019a958[];
extern char s_0019a998[];
extern char s_0019a9d0[];
extern char s_0019aa10[];
extern char s_0019aa50[];
extern char s_0019aa90[];
extern char s_0019aad0[];
extern char s_0019aaf0[];
extern char s_0019ab28[];
extern char s_0019ab68[];
static unsigned int calc_hf(unsigned int clk, unsigned short htot)
{
  return (clk * 10000) / htot;
}

unsigned char FUN_a01070b4(void)
{
  unsigned short vfreq;
  unsigned short hf;
  unsigned int clk;
  unsigned int htot;
  unsigned int vtot;
  unsigned int lim;
  unsigned short h;
  unsigned char ret = 0;
  vfreq = FUN_a0120b38(0);
  if (vfreq < DAT_a802d6a4->vf_min)
  {
    FUN_a00df170(s_0019ab68, vfreq, DAT_a802d6a4->vf_min);
    ret = 0x10;
  }
  if (DAT_a802d6a4->vf_max < vfreq)
  {
    ret |= 0x20;
    FUN_a00df170(s_0019a900, vfreq, DAT_a802d6a4->vf_max);
  }
  if (FUN_a010a864() == 0)
  {
    clk = FUN_a0102fd0(0);
    htot = FUN_a00f25f8(0, 0x5e);
    vtot = FUN_a00f25f8(0, 0x5b);
    FUN_a00df170(s_0019a938);
    htot++;   /* behaviour-neutral: stands in for an unknown original construct that makes gcc forget */
    htot--;   /* htot's 16-bit range here (the firmware re-narrows it at the join below) */
  }
  else
  {
    clk = FUN_a0102fd0(4);
    htot = FUN_a010a884();
    vtot = FUN_a010a9e8();
    if ((*((volatile unsigned int *) 0xcf011ec0)) & 0x40)
    {
      vtot = (calc_hf(clk, htot) * 1000) / vfreq;
    }
    FUN_a00df170(s_0019aad0);
  }
  h = htot;
  hf = calc_hf(clk, h);
  if (hf < DAT_a802d6a4->hf_min)
  {
    FUN_a00df170(s_0019ab28, hf, DAT_a802d6a4->hf_min);
    ret |= 1;
  }
  if (DAT_a802d6a4->hf_max < hf)
  {
    FUN_a00df170(s_0019a958, hf, DAT_a802d6a4->hf_max);
    ret |= 2;
  }
  lim = DAT_a802d6a4->clk_min / 1000000;
  if (clk < lim)
  {
    FUN_a00df170(s_0019a998, clk, lim);
    ret |= 4;
  }
  lim = DAT_a802d6a4->clk_max / 1000000;
  if (lim < clk)
  {
    FUN_a00df170(s_0019aaf0, clk, lim);
    ret |= 8;
  }
  if (h < DAT_a802d6a4->htot_min)
  {
    FUN_a00df170(s_0019a9d0, h, DAT_a802d6a4->htot_min);
    ret |= 0x40;
  }
  if (DAT_a802d6a4->htot_max < h)
  {
    FUN_a00df170(s_0019aa10, h, DAT_a802d6a4->htot_max);
    ret |= 0x80;
  }
  if (((unsigned short) vtot) < DAT_a802d6a4->vtot_min)
  {
    FUN_a00df170(s_0019aa50, (unsigned short) vtot, DAT_a802d6a4->vtot_min);
  }
  if (DAT_a802d6a4->vtot_max < ((unsigned short) vtot))
  {
    FUN_a00df170(s_0019aa90, (unsigned short) vtot, DAT_a802d6a4->vtot_max);
  }
  return ret;
}
