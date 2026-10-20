/* FUN_a00a3788 (leon2s, 0xa00a3788-0xa00a3810, 136 bytes, 34 words).
 * Flags: -mcpu=v8 -Os -g.
 * Code facts: port = (u8)param_1; if word DAT_a807db6c[port] != DAT_a807873c[port]: print the
 * dashes line (FUN_a00734c4(DAT_a006ba90), ONE arg: the string has no format), print
 * DAT_a006bac0 ("[HDMI_TX_FRL_Training]: Port%d : DRV_HDMI21_TXDetect_FSM_Init...") with port,
 * and copy db6c[port] into 873c[port]. Then FUN_a0091cf4(port, 0x31, 0); db6c[port] = 1;
 * byte DAT_a8079208[port] = 0; byte DAT_a80791aa = 0; returns 0.
 * Fixes vs draft: table name DAT_a807873c (fw sethi 0xa8078400 | 0x33c; the draft had DAT_a8078400),
 * the dashes string is the symbol DAT_a006ba90 (its address is set in the be delay slot) and
 * FUN_a00734c4 takes 1 arg (the draft passed 0xFFFF). Aids: none.
 */

extern unsigned int DAT_a807db6c[];
extern unsigned int DAT_a807873c[];
extern unsigned char DAT_a80791aa;
extern unsigned char DAT_a8079208[];
extern int FUN_a0073044(const char *, ...);
extern unsigned int FUN_a00734c4(const char *);
extern const char DAT_a006ba90[];
extern void FUN_a0091cf4(unsigned int, unsigned int, unsigned int);
extern const char DAT_a006bac0[];
unsigned int FUN_a00a3788(unsigned char param_1)
{
  unsigned int idx;
  param_1 &= 0xff;
  idx = param_1;
  if (DAT_a807db6c[idx] != DAT_a807873c[idx])
  {
    FUN_a00734c4(DAT_a006ba90);
    FUN_a0073044(DAT_a006bac0, param_1);
    DAT_a807873c[idx] = DAT_a807db6c[idx];
  }
  FUN_a0091cf4(param_1, 0x31, 0);
  DAT_a807db6c[idx] = 1;
  DAT_a8079208[param_1] = 0;
  DAT_a80791aa = 0;
  return 0;
}
