/* leon2m FUN_a0080490 @ 0xA0080490..0xA00808AC (263 words) "APPSetPowerOff".
 * Flags -mcpu=v8 -O3 -g (-msoft-float gives the same code).
 * Where: App_Initialize FUN_a0086ae8 calls it as FUN_a0080490(1) for power-on type 4 only (start-up step 3, after
 * step 2). Strings: "APPSetPowerOff" (ROM 0xFED10), "----> %d(%d)" (0xFED28), "OFFSENSING" (0xFED38),
 * "---> return" (0xFED48), "POWEROFF" (0xFED58).
 * What it does (code facts): FUN_a0147724(); t = FUN_a0148868() (the power-on type, as in FUN_a0087020); u16
 * 0xA802D000 = 0, byte 0xA802D033 = 0.
 * 1. "Off sensing" (only when t != 4, u16 0xA802D486 != 0x55AA, byte 0xA802D8A8 == 0 or 0xA802D8A7 == 0, and byte
 *    0xA802D8A6 == 0): returns at once if byte 0xA802D896 or 0xA802D897 is set; else FUN_a0090fd8, FUN_a01243bc(1),
 *    FUN_a0124ab0, FUN_a0124b40, FUN_a00db174, FUN_a01279d0(0), FUN_a01278e4(1), FUN_a01278f0(1), FUN_a0127914(2),
 *    FUN_a0127c78, prints both bytes; if one of them is now set: 0xA802D896 == 4 -> "POWEROFF" + FUN_a014512c(0, 0)
 *    (panel off, no wait), else "OFFSENSING" + FUN_a0143d98 + FUN_a012f1ec(0/1/3, 0); prints "---> return", returns.
 * 2. Power off (all other cases): bit 15 of u16 0xA802D032 = 0; prints "APPSetPowerOff"; FUN_a0124a08; if bit 20 of
 *    0xA802D33C and byte 0xA802D2AF == 0: bytes 0xA8024010..13 = 0xFF, else (bit 15 of 0xA802D338 clear)
 *    FUN_a0147760; if byte 0xA802D288 != 0: clear it and save the 0x1C-byte block 0xA802D274 (FUN_a014aed0(0x30,
 *    0xA802D274, 0x2E0, 0x1C)); FUN_a01243bc(1), FUN_a0124ab0, FUN_a0124b40, FUN_a00db174, FUN_a014bd0c(0);
 *    bit 15 of 0xA802D338 clear: FUN_a012596c (port 7 bit 2 = 0), FUN_a01259c0(0) (PORT 7 BIT 7 = 1, the
 *    UsbModeSelectRoutine pin), FUN_a01259a4 (port 5 bit 7 = 0), FUN_a0125be0 (0xFF/0x20 = 0); FUN_a0125ac8
 *    (port 2 bit 2 = 0), FUN_a0125c18 (0xFF/0x02 = 0), FUN_a008ee6c(0x40, 0), FUN_a0148aa8(0), FUN_a014a820(1).
 *    Bit 15 of 0xA802D338 set: FUN_a01479ec(1), FUN_a014512c(0, 1) (panel off, waits), 0xA802CFF8 bits 14..13 = 01,
 *    (word 0xA802D340 != 0 and arg == 0) FUN_a014bc58(0), FUN_a0143d98, tail FUN_a00fe44c(FUN_a00fe47c() & 0xFEDF).
 *    Clear: FUN_a014512c(0, 1), FUN_a01439d8(2, 0), 10-tick delay, FUN_a0125cb4(3), FUN_a01258b4 (port 6 bit 2 = 0),
 *    FUN_a01258ec (port 7 bit 1 = 0), FUN_a0125934, FUN_a0125a24, FUN_a0125de4 (port 0xC bit 0 = 0); arg == 0:
 *    FUN_a008767c(1); tail call func_0x4008f8d8.
 * Can it wait or fail? No loop of its own. FUN_a014512c(0, 1) waits for the panel-off state with no limit but calls
 * FUN_a002ced8 (8051 F204 -> F208 copy) each round (decomp of FUN_a014512c, see FUN_a008ef48.c); the 10-tick delay needs the timer IRQ.
 * Pins named "0xFF/..." go to FUN_a002c86c with port 0xFF, which does nothing (ports > 17, see FUN_a002c86c).
 * Source form: the two printed bytes are int locals (the firmware masks them at the call), the 'w0b0 != 0' and
 * 'arg == 0' tests are nested ifs (an '&&' becomes set-flag code), the byte 0xA802D033 store comes before the
 * u16 0xA802D000 store, and the four 0xFF stores are written 3, 2, 1, 0.
 */
struct T290
{
  unsigned int w000;
  unsigned char p004[0x1b];
  unsigned char b01f;
  unsigned char p020[0x88];
  unsigned int w0a8;
  unsigned int w0ac;
  unsigned int w0b0;
  unsigned char p0b4[0x142];
  unsigned short h1f6;
};
struct S274
{
  unsigned char p00[0x14];
  unsigned char b14;
};
struct Scff4
{
  unsigned short h000;
  unsigned short h002;
  struct
  {
    unsigned short b15 : 1;
    unsigned short f13 : 2;
    unsigned short rest : 13;
  } s004;
  unsigned char p006[6];
  unsigned short h00c;
  unsigned char p00e[0x30];
  union
  {
    unsigned short h03e;
    struct
    {
      unsigned char b03e;
      unsigned char b03f;
    } c03e;
  };
};
extern struct T290 DAT_a802d290;
extern struct S274 DAT_a802d274;
extern struct Scff4 DAT_a802cff4;
extern unsigned char DAT_a8024010[4];
extern char s_000fed10[], s_000fed28[], s_000fed38[], s_000fed48[], s_000fed58[];
extern int FUN_a00df170(const char *, ...);
extern void FUN_a0147724(void);
extern unsigned char FUN_a0148868(void);
extern unsigned char FUN_a01279dc(void);
extern unsigned char FUN_a01279c4(void);
extern unsigned char FUN_a01279ac(void);
extern unsigned char FUN_a012792c(void);
extern unsigned char FUN_a0127944(void);
extern void FUN_a0090fd8(void);
extern void FUN_a01243bc(int);
extern void FUN_a0124ab0(void);
extern void FUN_a0124b40(void);
extern void FUN_a00db174(void);
extern void FUN_a01279d0(int);
extern void FUN_a01278e4(int);
extern void FUN_a01278f0(int);
extern void FUN_a0127914(int);
extern void FUN_a0127c78(void);
extern void FUN_a014512c(int, int);
extern void FUN_a0143d98(void);
extern void FUN_a012f1ec(int, int);
extern void FUN_a0124a08(void);
extern void FUN_a0147760(void);
extern int FUN_a014aed0(int, void *, int, int);
extern void FUN_a014bd0c(int);
extern void FUN_a012596c(void);
extern void FUN_a01259c0(unsigned char);
extern void FUN_a01259a4(void);
extern void FUN_a0125be0(void);
extern void FUN_a0125ac8(void);
extern void FUN_a0125c18(void);
extern void FUN_a008ee6c(int, int);
extern void FUN_a0148aa8(int);
extern void FUN_a014a820(int);
extern void FUN_a01479ec(int);
extern void FUN_a014bc58(int);
extern unsigned int FUN_a00fe47c(void);
extern void FUN_a00fe44c(unsigned int);
extern void FUN_a01439d8(int, int);
extern void func_0x4008d1a0(int);
extern void FUN_a0125cb4(int);
extern void FUN_a01258b4(void);
extern void FUN_a01258ec(void);
extern void FUN_a0125934(void);
extern void FUN_a0125a24(void);
extern void FUN_a0125de4(void);
extern void FUN_a008767c(int);
extern void func_0x4008f8d8(void);

void FUN_a0080490(unsigned char arg)
{
  unsigned char t;

  FUN_a0147724();
  t = FUN_a0148868();
  DAT_a802cff4.c03e.b03f = 0;
  DAT_a802cff4.h00c = 0;
  if (t != 4 && DAT_a802d290.h1f6 != 0x55aa
      && (FUN_a01279dc() == 0 || FUN_a01279c4() == 0) && FUN_a01279ac() == 0)
    {
      int a, b;
      if (FUN_a012792c() != 0 || FUN_a0127944() != 0)
        return;
      FUN_a0090fd8();
      FUN_a01243bc(1);
      FUN_a0124ab0();
      FUN_a0124b40();
      FUN_a00db174();
      FUN_a01279d0(0);
      FUN_a01278e4(1);
      FUN_a01278f0(1);
      FUN_a0127914(2);
      FUN_a0127c78();
      a = FUN_a012792c();
      b = FUN_a0127944();
      FUN_a00df170(s_000fed28, a, b);
      if (FUN_a012792c() != 0 || FUN_a0127944() != 0)
        {
          if (FUN_a012792c() == 4)
            {
              FUN_a00df170(s_000fed58);
              FUN_a014512c(0, 0);
            }
          else
            {
              FUN_a00df170(s_000fed38);
              FUN_a0143d98();
              FUN_a012f1ec(0, 0);
              FUN_a012f1ec(1, 0);
              FUN_a012f1ec(3, 0);
            }
          FUN_a00df170(s_000fed48);
          return;
        }
    }
  DAT_a802cff4.h03e &= 0x7fff;
  FUN_a00df170(s_000fed10);
  FUN_a0124a08();
  if ((DAT_a802d290.w0ac & 0x100000) && DAT_a802d290.b01f == 0)
    {
      DAT_a8024010[3] = 0xff;
      DAT_a8024010[2] = 0xff;
      DAT_a8024010[1] = 0xff;
      DAT_a8024010[0] = 0xff;
    }
  else if (!(DAT_a802d290.w0a8 & 0x8000))
    FUN_a0147760();
  if (DAT_a802d274.b14 != 0)
    {
      DAT_a802d274.b14 = 0;
      FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c);
    }
  FUN_a01243bc(1);
  FUN_a0124ab0();
  FUN_a0124b40();
  FUN_a00db174();
  FUN_a014bd0c(0);
  if (!(DAT_a802d290.w0a8 & 0x8000))
    {
      FUN_a012596c();
      FUN_a01259c0(0);
      FUN_a01259a4();
      FUN_a0125be0();
    }
  FUN_a0125ac8();
  FUN_a0125c18();
  FUN_a008ee6c(0x40, 0);
  FUN_a0148aa8(0);
  FUN_a014a820(1);
  if (DAT_a802d290.w0a8 & 0x8000)
    {
      FUN_a01479ec(1);
      FUN_a014512c(0, 1);
      DAT_a802cff4.s004.f13 = 1;
      if (DAT_a802d290.w0b0 != 0)
        if (arg == 0)
          FUN_a014bc58(0);
      FUN_a0143d98();
      FUN_a00fe44c(FUN_a00fe47c() & 0xfedf);
      return;
    }
  FUN_a014512c(0, 1);
  FUN_a01439d8(2, 0);
  func_0x4008d1a0(10);
  FUN_a0125cb4(3);
  FUN_a01258b4();
  FUN_a01258ec();
  FUN_a0125934();
  FUN_a0125a24();
  FUN_a0125de4();
  if (arg == 0)
    FUN_a008767c(1);
  func_0x4008f8d8();
}
