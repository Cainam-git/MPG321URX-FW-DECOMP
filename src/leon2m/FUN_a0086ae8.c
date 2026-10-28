/* leon2m FUN_a0086ae8 @ 0xA0086AE8..0xA0087020 (334 words) "App_Initialize".
 * -mcpu=v8 -O3 -g (also -msoft-float) exact.py None.
 * Plain words: the application start-up step (start-up step 3). It calls FUN_a014a768 for ids 0xC / 0xD with one
 * settings bit, then switches the GPIO power pins on in an order that depends on the power-on type argument (type 1:
 * with extra init calls and two 50-tick delays; type 4: a short pin set and FUN_a0080490(1); other types: the type-1
 * pin order without the extras), then runs the fixed list of module init calls below, handles the 0x55AA / 0x55 /
 * 0xAA marker of record 0xA802D290 and prints a tail line. The caller App_CoolInitialize
 * FUN_a0087020 passes the type.
 * LEVER: the FUN_a014782c(4) test is written
 *   if (bit 20) { if (b01f == 0) FUN_a014782c(4); FUN_a014b4b4(0xfe, 1); } else FUN_a014b4b4(0xfe, 1);
 * Same code: the two FUN_a014b4b4 copies are merged by cross-jumping AFTER branch prediction. At prediction time
 * (-db x.c.12.bp, insn 980 bb 34) the bit-clear edge now ends in a block that holds a call, is dominated by the bit
 * test and does not post-dominate it, so predict.c's call heuristic marks it not taken: bit 20 set = 70 % (was 50 %,
 * no heuristic for a compare with 0). So the FUN_a014782c(4) block gets frequency 10000 * 0.7 * 0.3 = 2100 (was
 * 1500); that is >= the round-2 threshold 2000 and below the type-4 head (2468), so bb-reorder (-dB x.c.31.bbro)
 * makes it trace 13 in round 2, right after the type-4 head, and BEFORE the round-3 traces of the FUN_a0080490
 * block, the type-4 pin block and the type-1 block. Final order ... 6 8 36 7 1 2 4 = the firmware's (0xA0086EE0
 * type-4 head, 0xA0086F0C FUN_a0080490(1), 0xA0086F1C FUN_a014782c(4), 0xA0086F2C pins, 0xA0086F50 type 1).
 * So the firmware source gives other block frequencies, not another pin test.
 * General lever: an else arm that repeats the join's first call (a call that cross-jumping merges later) makes the
 * call heuristic predict the other arm likely; use it when the firmware layout needs a 50 % test to be 70 %.
 * Where: start-up step 3, App_CoolInitialize FUN_a0087020 calls it once with the power-on type n (after the logo for
 * type 0/1).
 * What it does (code facts, in order): FUN_a0145ee8(0, 0), FUN_a0145fac(1), prints "App_Initialize %02x" (ROM 0xFF550),
 * FUN_a014a768(0xC / 0xD, bit 7 of word 0xA802D338). Then by type:
 *   1: FUN_a0124b40, FUN_a0124a68, FUN_a0148aa8(1), FUN_a0145360(1), (bit 20 of 0xA802D33C and byte 0xA802D2AF == 0)
 *      FUN_a014782c(2) / (3); then the GPIO power pins: FUN_a0125950 (port 7 bit 2 = 1), 50-tick delay, FUN_a012587c
 *      (port 6 bit 2 = 1), FUN_a00db12c(0), FUN_a0125934 (pin 0xFF/0x40 = 0), 50-tick delay, FUN_a0125918 (0xFF/0x40
 *      = 1), FUN_a0125c74, FUN_a0125988 (port 5 bit 7 = 1), FUN_a0125bc4 (0xFF/0x20 = 1), FUN_a0125dc8 (port 0xC bit 0
 *      = 1); u16 0xA802D00E = tick now.
 *   4: FUN_a00d99f8(2), FUN_a01519d8(4 / 8); (bit 15 of 0xA802D338) the four pins 7.2 / 5.7 / 0xFF.0x20 / 6.2 = 1;
 *      FUN_a0080490(1).
 *   other: the type-1 pin sequence without the 0x148aa8 / 0x145360 / 0x14782c calls and with one delay only.
 * Then: 0xA802D434 = 2 if u16 0xA802D486 == 0x55AA; FUN_a00d4780, a00d47b0, a00d4560, a00d45f8, a00d462c, a00d972c;
 * if FUN_a0082c4c() == 0: FUN_a00d8cd4, a00d7de0, a00d9764, a00d7bc0; FUN_a00d58f8, a00d58d8, FUN_a0147a14(1);
 * type <= 1: FUN_a00d9978, FUN_a00da754(byte 0xA802D33C); the 0x55AA / 0x55 / 0xAA marker block (FUN_a0148d98,
 * FUN_a014459c -> byte 0xA802D2AE, FUN_a00d9238, bit 10 of 0xA802CFF4, FUN_a00808ac(0, 0)) or FUN_a00d5918;
 * FUN_a00d8c1c; (FUN_a0082c4c() == 0) FUN_a00d472c + FUN_a00b50d8(1); FUN_a00d5938(1); type 2: input source from
 * FUN_a0148974 (0xFF or bit 9 of 0xA802D290 clear: prints "SYSAPI_GetWakeUpPortName return _SYS_InputSource_NULL");
 * FUN_a00d9238, (FUN_a0082c4c() == 0) FUN_a00da254; FUN_a008ec48(0xFF, 0), FUN_a008ed00(0xFF, 0), FUN_a008edb8(0xFF,
 * 0), FUN_a008ef24(500), FUN_a008ef30(50), FUN_a008ef3c(2000); (bit 20 / 0xA802D2AF == 0) FUN_a014782c(4);
 * FUN_a014b4b4(0xFE, 1); type != 4: FUN_a00d9fdc(2); FUN_a0148358(0x1964); FUN_a00d5e84; FUN_a0124244(1); byte
 * 0xA802CFFE = 9, u16 0xA802CFFE bit 7 = 0; FUN_a0122d5c; tail: prints ROM 0xFF568 with 0x1FC.
 * USB side: it drives no USB-MCU register and neither USB pin of UsbModeSelectRoutine (port 5 bit 0,
 * port 7 bit 7); only type 4 reaches port 7 bit 7, through FUN_a0080490.
 * Can it wait or fail? Its own code has no loop; the two 50-tick delays (func_0x4008d1a0 = FUN_a002d1a0) need the
 * timer IRQ.
 */
struct T290
{
  unsigned int w000;
  unsigned char p004[0x1a];
  unsigned char b01e;
  unsigned char b01f;
  unsigned char p020[0x88];
  unsigned int w0a8;
  union
  {
    unsigned int w0ac;
    unsigned char b0ac;
  };
  unsigned char p0b0[0xf4];
  unsigned char b1a4;
  unsigned char p1a5[0x30];
  unsigned char b1d5;
  unsigned char b1d6;
  unsigned char p1d7[0x1f];
  unsigned short h1f6;
};
struct Scff4
{
  unsigned short h000;
  unsigned char p002[8];
  union
  {
    unsigned short h00a;
    unsigned char b00a;
  };
  unsigned char p00c[0xe];
  unsigned short h01a;
};
extern struct T290 DAT_a802d290;
extern struct Scff4 DAT_a802cff4;
extern char s_000ff550[], s_000ff568[], s_000ff578[];
extern int FUN_a00df170(const char *, ...);
extern void FUN_a0145ee8(int, int);
extern void FUN_a0145fac(int);
extern void FUN_a014a768(int, int);
extern void FUN_a0124b40(void);
extern void FUN_a0124a68(void);
extern void FUN_a0148aa8(int);
extern void FUN_a0145360(unsigned char);
extern void FUN_a014782c(int);
extern void FUN_a0125950(void);
extern void FUN_a012587c(void);
extern void FUN_a00db12c(int);
extern void FUN_a0125934(void);
extern void FUN_a0125918(void);
extern void FUN_a0125c74(void);
extern void FUN_a0125988(void);
extern void FUN_a0125bc4(void);
extern void FUN_a0125dc8(void);
extern void func_0x4008d1a0(int);
extern unsigned short func_0x4008d588(void);
extern void FUN_a00d99f8(int, int);
extern void FUN_a01519d8(int);
extern void FUN_a0080490(int);
extern void FUN_a00d4780(void);
extern void FUN_a00d47b0(void);
extern void FUN_a00d4560(void);
extern void FUN_a00d45f8(void);
extern void FUN_a00d462c(void);
extern void FUN_a00d972c(void);
extern unsigned char FUN_a0082c4c(void);
extern void FUN_a00d8cd4(void);
extern void FUN_a00d7de0(void);
extern void FUN_a00d9764(void);
extern void FUN_a00d7bc0(void);
extern void FUN_a00d58f8(void);
extern void FUN_a00d58d8(void);
extern void FUN_a0147a14(int);
extern void FUN_a00d9978(void);
extern void FUN_a00da754(unsigned char);
extern void FUN_a0148d98(int);
extern unsigned char FUN_a014459c(int);
extern void FUN_a00d9238(void);
extern void FUN_a00808ac(int, int);
extern void FUN_a00d5918(void);
extern void FUN_a00d8c1c(void);
extern void FUN_a00d472c(void);
extern void FUN_a00b50d8(int);
extern void FUN_a00d5938(int);
extern unsigned char FUN_a0148974(void);
extern void FUN_a00da254(void);
extern void FUN_a008ec48(int, int);
extern void FUN_a008ed00(int, int);
extern void FUN_a008edb8(int, int);
extern void FUN_a008ef24(int);
extern void FUN_a008ef30(int);
extern void FUN_a008ef3c(int);
extern void FUN_a014b4b4(int, int);
extern void FUN_a00d9fdc(int);
extern void FUN_a0148358(int);
extern void FUN_a00d5e84(void);
extern void FUN_a0124244(int);
extern void FUN_a0122d5c(void);

void FUN_a0086ae8(unsigned char type)
{
  FUN_a0145ee8(0, 0);
  FUN_a0145fac(1);
  FUN_a00df170(s_000ff550, type);
  FUN_a014a768(0xc, (DAT_a802d290.w0a8 >> 7) & 1);
  FUN_a014a768(0xd, (DAT_a802d290.w0a8 >> 7) & 1);
  if (type == 1)
    {
      FUN_a0124b40();
      FUN_a0124a68();
      FUN_a0148aa8(1);
      FUN_a0145360(1);
      if ((DAT_a802d290.w0ac & 0x100000) && DAT_a802d290.b01f == 0)
        {
          FUN_a014782c(2);
          FUN_a014782c(3);
        }
      FUN_a0125950();
      func_0x4008d1a0(0x32);
      FUN_a012587c();
      FUN_a00db12c(0);
      FUN_a0125934();
      func_0x4008d1a0(0x32);
      FUN_a0125918();
      FUN_a0125c74();
      FUN_a0125988();
      FUN_a0125bc4();
      FUN_a0125dc8();
      DAT_a802cff4.h01a = func_0x4008d588();
    }
  else if (type == 4)
    {
      FUN_a00d99f8(2, 0);
      FUN_a01519d8(4);
      FUN_a01519d8(8);
      if (DAT_a802d290.w0a8 & 0x8000)
        {
          FUN_a0125950();
          FUN_a0125988();
          FUN_a0125bc4();
          FUN_a012587c();
        }
      FUN_a0080490(1);
    }
  else
    {
      FUN_a0124b40();
      FUN_a0124a68();
      FUN_a0125950();
      FUN_a012587c();
      FUN_a00db12c(0);
      FUN_a0125934();
      func_0x4008d1a0(0x32);
      FUN_a0125918();
      FUN_a0125c74();
      FUN_a0125988();
      FUN_a0125bc4();
      FUN_a0125dc8();
    }
  if (DAT_a802d290.h1f6 == 0x55aa)
    DAT_a802d290.b1a4 = 2;
  FUN_a00d4780();
  FUN_a00d47b0();
  FUN_a00d4560();
  FUN_a00d45f8();
  FUN_a00d462c();
  FUN_a00d972c();
  if (FUN_a0082c4c() == 0)
    {
      FUN_a00d8cd4();
      FUN_a00d7de0();
      FUN_a00d9764();
      FUN_a00d7bc0();
    }
  FUN_a00d58f8();
  FUN_a00d58d8();
  FUN_a0147a14(1);
  if (type <= 1)
    {
      FUN_a00d9978();
      FUN_a00da754(DAT_a802d290.b0ac);
    }
  if (DAT_a802d290.h1f6 == 0x55aa && DAT_a802d290.b1d6 == 0x55)
    {
      FUN_a0148d98(0);
      if (DAT_a802d290.b1d5 != 0)
        {
          DAT_a802d290.b01e = FUN_a014459c(0);
          FUN_a00d9238();
          DAT_a802cff4.h000 |= 0x400;
          FUN_a00808ac(0, 0);
        }
    }
  else if (DAT_a802d290.h1f6 == 0x55aa && DAT_a802d290.b1d6 == 0xaa)
    {
      DAT_a802d290.b01e = FUN_a014459c(0);
      FUN_a00d9238();
      DAT_a802cff4.h000 |= 0x400;
      FUN_a00808ac(0, 0);
      FUN_a0148d98(0);
    }
  else
    FUN_a00d5918();
  FUN_a00d8c1c();
  if (FUN_a0082c4c() == 0)
    {
      FUN_a00d472c();
      FUN_a00b50d8(1);
    }
  FUN_a00d5938(1);
  if (type == 2)
    {
      if (FUN_a0148974() != 0xff)
        if (DAT_a802d290.w000 & 0x200)
          {
            DAT_a802d290.b01e = FUN_a0148974();
            goto common;
          }
      FUN_a00df170(s_000ff578);
      FUN_a00d9238();
      if (FUN_a0082c4c() == 0)
        FUN_a00da254();
      goto tail;
    }
 common:
  FUN_a00d9238();
  if (FUN_a0082c4c() == 0)
    FUN_a00da254();
 tail:
  FUN_a008ec48(0xff, 0);
  FUN_a008ed00(0xff, 0);
  FUN_a008edb8(0xff, 0);
  FUN_a008ef24(500);
  FUN_a008ef30(0x32);
  FUN_a008ef3c(2000);
  if (DAT_a802d290.w0ac & 0x100000)
    {
      if (DAT_a802d290.b01f == 0)
        FUN_a014782c(4);
      FUN_a014b4b4(0xfe, 1);
    }
  else
    FUN_a014b4b4(0xfe, 1);
  if (type != 4)
    FUN_a00d9fdc(2);
  FUN_a0148358(0x1964);
  FUN_a00d5e84();
  FUN_a0124244(1);
  DAT_a802cff4.b00a = 9;
  DAT_a802cff4.h00a &= ~0x80;
  FUN_a0122d5c();
  FUN_a00df170(s_000ff568, 0x1fc);
}
