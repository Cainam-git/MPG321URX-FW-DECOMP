/* leon2m FUN_a0083ff0 @ 0xA0083FF0..0xA0084330 (208 words) "UsbModeSelectRoutine". (from
 * a 59.13 % draft): -mcpu=v8 -O3 -g (also -msoft-float)
 * Lever: the cable-sense test as 'int in = FUN_a0125a60() || FUN_a0125a88(); if (!in) {none} else {chosen}'. With
 * a plain 'if (a || b)' the 'chosen' block's label has one use, CSE follows the jump and keeps the struct pointer
 * of 0xA802D290 live into that block (other register allocation); with '!a && !b' the label has two uses (pointer
 * rematerialised as in the firmware) but the 'none' block falls through. The flag form gives both.
 * Where: only from the main-loop task FUN_a0085984 (APPTimerRoutine), i.e. after start-up steps 2
 * (FUN_a0106d64) and 3 (logo, App_Initialize).
 * What it does (code facts):
 * 1. Returns at once while u16 0xA802AFEE (FUN_a0090fcc) is 0x3C..0x3E or 0x104.
 * 2. Picks the USB upstream value sel (0, 1 or 0xFF = none). force == 1 first forgets the last value (byte
 *    0xA802401D = 0xFF). Start value: last value if byte 0xA802D465 == 0, else 0. By the setting byte 0xA802D40C:
 *    1 -> sel = (GPIO 7/0x08 reads 1, FUN_a0125a60) ? 0 : 0xFF; 2..255 -> sel = (GPIO 11/0x02 reads 0, FUN_a0125a88)
 *    ? 1 : 0xFF; 0 (auto) -> if neither input is active: 0xFF, except 0 when u16 0xA802D486 == 0x55AA and byte
 *    0xA802D466 == 0x55; if one is active: (FUN_a0143c14(0) == 10 or bit 9 of word 0xA802D290 clear) -> sel =
 *    (FUN_a014448c(0) == 0x0D); else if bit 15 of word 0xA802D338: input byte 0xA802D2AE 0x0D -> 1, 0x0C/5/6 -> 0.
 * 3. Only when sel changed: sel == 0xFF -> FUN_a01259c0(0) (GPIO 7 bit 7 = 1) and FUN_a0125a2c(0 / 1 for setting
 *    1 / 2); else FUN_a0125a2c(sel) (GPIO 5 bit 0 = sel) and FUN_a01259f4 (GPIO 7 bit 7: 1, 200-tick delay, 0).
 *    Prints "UsbModeSelect = %d" (ROM 0xFEF50).
 * 4. Hub power flag on = (byte 0xA802D2AF == 2) or (byte 0xA802D288 == 1 and 0xA802D486 == 0x55AA). When it or the
 *    second flag changed: on -> FUN_a00869b0(0x16, 1000) (timer 0x16) and u16 0xA802CFF8 |= 0x800, prints
 *    "[UsbModeSelectRoutine] OT2211 Power ON"; off -> FUN_a0125bbc(0) (EMPTY in FW.021), prints "... Power OFF".
 *    When timer 0x16 has expired, FUN_a0085984 clears bit 11 of 0xA802CFF8 and calls FUN_a0125bbc(1) (also empty).
 *    Stores the three values in 0xA802401D/1E/1F.
 * Can it wait or fail? No loop; the only wait is the bounded 200-tick delay in FUN_a01259f4 (needs the timer IRQ).
 * It drives GPIO lines only; it sends nothing to the 8051 or to the USB MCU (F198).
 */
struct G290
{
  unsigned int w000;
  unsigned char p004[0x1a];
  unsigned char b01e;
  unsigned char b01f;
  unsigned char p020[0x88];
  unsigned int w0a8;
  unsigned char p0ac[0xd0];
  unsigned char b17c;
  unsigned char p17d[0x58];
  unsigned char b1d5;
  unsigned char b1d6;
  unsigned char p1d7[0x1f];
  unsigned short h1f6;
};
struct Scff4
{
  unsigned short h000;
  unsigned short h002;
  unsigned short h004;
};
extern struct G290 DAT_a802d290;
extern struct Scff4 DAT_a802cff4;
extern unsigned char DAT_a802d288;
extern unsigned char DAT_a802401d;
extern unsigned char DAT_a802401e;
extern unsigned char DAT_a802401f;
extern char s_000fef50[], s_000fef68[], s_000fef98[];
extern unsigned short FUN_a0090fcc(void);
extern unsigned char FUN_a0125a60(void);
extern unsigned char FUN_a0125a88(void);
extern unsigned char FUN_a0143c14(int);
extern unsigned char FUN_a014448c(int);
extern void FUN_a01259c0(unsigned char);
extern void FUN_a0125a2c(unsigned char);
extern void FUN_a01259f4(void);
extern void FUN_a0125bbc(int);
extern void FUN_a00869b0(int, int);
extern int FUN_a00df170(const char *, ...);

void FUN_a0083ff0(unsigned char force)
{
  unsigned char sel;
  unsigned char on;
  unsigned char lock;
  unsigned char last;

  if (FUN_a0090fcc() > 0x3b && FUN_a0090fcc() < 0x3f)
    return;
  if (FUN_a0090fcc() == 0x104)
    return;
  if (force == 1)
    DAT_a802401d = 0xff;
  last = DAT_a802401d;
  {
    unsigned char m = DAT_a802d290.b1d5 != 0;
    sel = (m - 1) & last;
  }
  if (DAT_a802d290.b17c == 0)
    {
      int in = FUN_a0125a60() || FUN_a0125a88();
      if (!in)
        {
          sel = 0xff;
          if (DAT_a802d290.h1f6 == 0x55aa)
            {
              sel = 0;
              if (DAT_a802d290.b1d6 != 0x55)
                sel = 0xff;
            }
        }
      else
        {
          unsigned char r = FUN_a0143c14(0);
          if (r == 10 || !(DAT_a802d290.w000 & 0x200))
            sel = FUN_a014448c(0) == 0xd;
          else if (DAT_a802d290.w0a8 & 0x8000)
            {
              if (DAT_a802d290.b01e == 0xd)
                sel = 1;
              else if (DAT_a802d290.b01e == 0xc)
                sel = 0;
              else if (DAT_a802d290.b01e == 5)
                sel = 0;
              else if (DAT_a802d290.b01e == 6)
                sel = 0;
            }
        }
    }
  else if (DAT_a802d290.b17c == 1)
    sel = (FUN_a0125a60() != 0) - 1;
  else
    sel = ((FUN_a0125a88() != 0) - 1) | 1;
  if (sel != DAT_a802401d)
    {
      if (sel == 0xff)
        {
          FUN_a01259c0(0);
          if (DAT_a802d290.b17c == 1)
            FUN_a0125a2c(0);
          else if (DAT_a802d290.b17c == 2)
            FUN_a0125a2c(1);
        }
      else
        {
          FUN_a0125a2c(sel);
          FUN_a01259f4();
        }
      FUN_a00df170(s_000fef50, sel);
    }
  on = DAT_a802d290.b01f == 2;
  if (DAT_a802d288 != 1 || DAT_a802d290.h1f6 != 0x55aa)
    lock = 0;
  else
    lock = 1;
  if (DAT_a802401e != on || DAT_a802401f != lock)
    {
      if (on | lock)
        {
          FUN_a00869b0(0x16, 1000);
          DAT_a802cff4.h004 |= 0x800;
          FUN_a00df170(s_000fef68);
        }
      else
        {
          FUN_a0125bbc(0);
          FUN_a00df170(s_000fef98);
        }
    }
  DAT_a802401e = on;
  DAT_a802401f = lock;
  DAT_a802401d = sel;
}
