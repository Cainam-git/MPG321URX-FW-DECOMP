/* FUN_a0085984 (APPTimerRoutine), byte-exact at -mcpu=v8 -O3 -g (hand).
 * Verified: jf.py 100 % and rawcmp.py 0 mismatches over 1,035 words (0xA0085984..0xA00869B0).
 * What it does (code facts): Big chip main-loop task (called from FUN_a0087430): OLED error detection, Vx1 check,
 * fake-sleep counter / escape, timers 0x13 / 1 / 0x14 / 0x15 / 0x16, PIP source / CEC dispatch (jump table at
 * 0xA0085CAC, all targets in range), the two power-saving chains (DAT_a802af42 bit 0x10 / bit 0x4000) and the
 * display / PIP tail. UART command path: it calls FUN_a00ce348 (the port-4 command task that frames MSI's tool commands).
 * asm label on DAT_a802cff4 (documented no-code aid): no code, link name = the firmware symbol; it only changes the
 * gcse hash bucket of the symbol name ("*DAT_a802cff4"), which breaks a register-priority tie the way the original
 * identifiers did (all allocno priorities are 0 here because of the hang loop).
 * FUN_a014aed0 is declared int-returning like in the matched FUN_a00d2334 / FUN_a0087020 (fixes the delay-slot fill).
 */

struct G290
{
  unsigned int w000;
  unsigned char p004[0x1a];
  unsigned char b01e;
  unsigned char b01f;
  unsigned char b020;
  unsigned char p021[0xe];
  unsigned char b02f;
  unsigned char p030[0x1a];
  unsigned char b04a;
  unsigned char p04b[0x5d];
  unsigned int w0a8;
  unsigned int w0ac;
  unsigned char p0b0[0x125];
  unsigned char b1d5;
  unsigned char p1d6[0x20];
  unsigned short h1f6;
};
struct Scff4
{
  unsigned short h000;
  unsigned short h002;
  union 
  {
    unsigned short h004;
    struct 
    {
      unsigned short b15 : 1;
      unsigned short f13 : 2;
      unsigned short rest : 13;
    } s004;
  };
  unsigned short h006;
  unsigned short h008;
  unsigned short h00a;
  unsigned char p00c[8];
  union 
  {
    unsigned short h014;
    struct 
    {
      unsigned short b15 : 1;
      unsigned short b14 : 1;
      unsigned short rest : 14;
    } s014;
  };
};
struct Log274
{
  unsigned char p00[0x11];
  unsigned char b11;
  unsigned short h12;
  unsigned char p14;
  unsigned char b15;
  unsigned short h16;
};
extern struct G290 DAT_a802d290;
extern struct Scff4 DAT_a802cff4 asm("DAT_a802cff4");
extern struct Log274 DAT_a802d274;
extern unsigned char DAT_a802af41;
extern unsigned char DAT_a802af44;
extern unsigned char DAT_a802af46;
extern unsigned char DAT_a802af47;
extern unsigned char DAT_a802af48;
extern unsigned short DAT_a802af42;
extern unsigned char DAT_a8024000;
extern unsigned char DAT_a8024001;
extern unsigned char DAT_a8024010[4];
extern unsigned char DAT_a8024018[];
struct Set1a0
{
  unsigned int b31 : 1;
  unsigned int rest : 31;
};
extern struct Set1a0 DAT_a802e1a0;
extern char s_000ff320[];
extern char s_000ff340[];
extern char s_000ff358[];
extern char s_000ff390[];
extern char s_000ff3b0[];
extern char s_000ff3d0[];
extern char s_000ff3f0[];
extern char s_000ff408[];
extern char s_000ff438[];
extern char s_000ff470[];
extern char s_000ff4a0[];
extern char s_000ff4c8[];
extern char s_000ff4d8[];
extern char s_000ff508[];
extern char s_000ff528[];
extern int FUN_a00df170();
extern unsigned char FUN_a0124828(void);
extern unsigned char FUN_a01248f0(void);
extern unsigned char FUN_a0124964(void);
extern unsigned char FUN_a013ce6c(int);
extern unsigned char FUN_a0141a98(void);
extern unsigned char FUN_a0122d40(void);
extern unsigned char FUN_a012792c(void);
extern unsigned char FUN_a0127944(void);
extern unsigned char FUN_a0127968(void);
extern unsigned char FUN_a01279dc(void);
extern unsigned char FUN_a01279c4(void);
extern unsigned char FUN_a0143c14(int);
extern unsigned char FUN_a0147790(void);
extern unsigned char FUN_a0147814(void);
extern unsigned char FUN_a01438dc(int);
extern unsigned char FUN_a014bd70(int);
extern unsigned char FUN_a014448c(int);
extern unsigned char FUN_a01445fc(int);
extern unsigned char FUN_a0124a40(void);
extern unsigned char FUN_a013cda8(int);
extern unsigned short FUN_a0086a3c(int);
extern unsigned short FUN_a01269f8(void);
extern unsigned short FUN_a0090fcc(void);
extern unsigned short FUN_a0145af8(int);
extern int FUN_a00d7d48(void);
extern unsigned int FUN_a0147770(void);
extern void FUN_a014512c(int, int);
extern int FUN_a014aed0(int, void *, int, int);
extern void FUN_a01412b8(int);
extern void FUN_a0081ea8(int);
extern void FUN_a01295e4(void);
extern void FUN_a0127c78(void);
extern void FUN_a00869b0(int, int);
extern void FUN_a0124b40(void);
extern void FUN_a0127914(int);
extern void FUN_a01278e4(int);
extern void FUN_a01278fc(int);
extern void FUN_a01279b8(int);
extern void FUN_a01279d0(int);
extern void FUN_a0143d98(void);
extern void FUN_a01268cc(int);
extern void FUN_a01278f0(int);
extern void FUN_a012795c(int);
extern void FUN_a0124a68(void);
extern void FUN_a00daa7c(void);
extern void FUN_a00d91fc(int);
extern void FUN_a0148268(int, int);
extern void FUN_a0090fd8(void);
extern void FUN_a00da254(void);
extern void FUN_a0081ea8(int);
extern void FUN_a0145360(int);
extern void FUN_a0083ff0(int);
extern void FUN_a014d474(int, int);
extern void FUN_a0125bbc(int);
extern void FUN_a008f354(void);
extern void FUN_a008ee6c(int, int);
extern void FUN_a0143da8(void);
extern void FUN_a0124ab0(void);
extern void FUN_a0124af8(void);
extern void FUN_a00d9978(void);
extern void FUN_a0082b00(void);
extern void FUN_a0143804(int);
extern void FUN_a00d4970(void);
extern void FUN_a0124f24(void);
extern void FUN_a0125950(void);
extern void FUN_a0125988(void);
extern void FUN_a0125bc4(void);
extern void FUN_a01084a8(unsigned char, int);
extern void FUN_a0109554(unsigned char, int);
extern void FUN_a0125ac8(void);
extern void FUN_a00b7f9c(int);
extern void FUN_a0090fa0(int);
extern void FUN_a00bbabc(int);
extern void FUN_a0084330(int);
extern void FUN_a00d9238(void);
extern void FUN_a0147780(void *);
extern int FUN_a0124244(int);
extern int FUN_a00ce348(int);
void FUN_a0085984(void)
{
  unsigned char c;
  unsigned char src;
  unsigned int v;
  unsigned short e;
  if (FUN_a0124828() == 1)
  {
    if (!FUN_a01248f0())
    {
      FUN_a00df170(s_000ff408);
      FUN_a014512c(0, 1);
      for (;;)
      {
        ;
      }

    }
    if ((FUN_a0124964() == 1) && (DAT_a802d290.h1f6 != 0x55aa))
    {
      FUN_a00df170(s_000ff4a0);
      e = FUN_a01269f8();
      if (DAT_a802af48 == 0)
      {
        DAT_a802af48 = 1;
        DAT_a802d274.b15++;
        DAT_a802d274.h16 = e;
        FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c);
      }
      if (e != 0)
      {
        FUN_a00df170(s_000ff4c8, e);
        FUN_a01412b8(0);
        FUN_a0081ea8(1);
      }
    }
    else
      if ((FUN_a0124964() == 1) && (DAT_a802d290.h1f6 == 0x55aa))
    {
      FUN_a00df170(s_000ff438);
      e = FUN_a01269f8();
      if (DAT_a802af48 == 0)
      {
        DAT_a802d274.h16 = e;
        DAT_a802af48 = 1;
        DAT_a802d274.b15++;
        FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c);
      }
    }
  }
  if ((((((FUN_a013ce6c(0) == 0xc) && FUN_a0141a98()) && (!FUN_a0122d40())) && (!FUN_a012792c())) && (!FUN_a0127944())) && (!FUN_a0127968()))
  {
    FUN_a00df170(s_000ff3f0, 0);
  }
  FUN_a01295e4();
  FUN_a0127c78();
  if (FUN_a01279dc() == 1)
  {
    if (FUN_a01279c4() != 2)
    {
      if (DAT_a8024001 == 0xff)
      {
        FUN_a00df170(s_000ff390);
        DAT_a8024001 = 0;
        FUN_a00869b0(0x12, 60000);
      }
      else
      {
        if ((FUN_a0086a3c(0x12) == 0) && (DAT_a8024001 <= 9))
        {
          DAT_a8024001 = DAT_a8024001 + 1;
          FUN_a00df170(s_000ff3b0, DAT_a8024001);
          FUN_a00869b0(0x12, 60000);
        }
        if ((DAT_a8024001 == 10) && (DAT_a8024000 == 0xff))
        {
          FUN_a00df170(s_000ff3d0);
          FUN_a0124b40();
          DAT_a8024000 = 0;
          FUN_a0127914(1);
          FUN_a014512c(1, 1);
          FUN_a01278e4(1);
          FUN_a01278fc(1);
          FUN_a0127c78();
          FUN_a01279b8(1);
          FUN_a01279d0(0);
          FUN_a0143d98();
        }
      }
    }
  }
  else
  {
    DAT_a8024001 = 0xff;
    DAT_a8024000 = 0xff;
  }
  if ((((FUN_a01279dc() == 1) && (FUN_a0143c14(0) > 5)) && (!FUN_a012792c())) && (!FUN_a0127944()))
  {
    FUN_a00df170(s_000ff358);
    FUN_a01268cc(0);
    FUN_a014512c(0, 1);
    FUN_a01279d0(0);
    FUN_a01278f0(0);
    FUN_a012795c(0);
    FUN_a0124b40();
    FUN_a0124a68();
  }
  if ((DAT_a802cff4.s004.f13 == 0) && (FUN_a0086a3c(0x13) == 0))
  {
    FUN_a00daa7c();
    FUN_a00869b0(0x13, 20000);
  }
  if ((DAT_a802d290.b01f != 0) && (((FUN_a0143c14(0) > 8) && (FUN_a00d7d48() != 0)) || ((FUN_a0143c14(1) > 8) && ((FUN_a01438dc(1) == 1) || (FUN_a014bd70(1) == 1)))))
  {
    DAT_a802d290.b01f = 0;
    FUN_a00d91fc(0);
    FUN_a0148268(0, 1);
    FUN_a0148268(1, 1);
    FUN_a0090fd8();
    FUN_a00df170(s_000ff340);
    FUN_a00da254();
  }
  if ((((DAT_a802d290.w0ac & 0x100000) && (DAT_a802d290.b01f == 0)) && (!FUN_a012792c())) && (!FUN_a0127944()))
  {
    c = FUN_a0147790();
    if (c != 0)
    {
      FUN_a00df170(s_000ff320, c);
    }
    switch (c)
    {
      case 1:
        if (!DAT_a802e1a0.b31)
      {
        FUN_a0081ea8(2);
      }
        break;

      case 2:
        if (DAT_a802e1a0.b31 && (!FUN_a01445fc(FUN_a014448c(0))))
      {
        FUN_a0081ea8(1);
      }
        break;

      case 3:
        FUN_a00df170(s_000ff528, FUN_a0147814(), DAT_a802d290.b01e);
        if (FUN_a0147814() == 0x10)
      {
        src = 5;
      }
      else
        if (FUN_a0147814() == 0x20)
      {
        src = 6;
      }
      else
        if (FUN_a0147814() == 0x30)
      {
        src = 7;
      }
      else
      {
        src = (FUN_a0147814() == 0x40) ? (8) : (5);
      }
        if (!DAT_a802e1a0.b31)
      {
        FUN_a0081ea8(2);
        if ((DAT_a802d290.b01e != src) && ((DAT_a802d290.b01f == 0) || (DAT_a802d290.b020 != src)))
        {
          DAT_a802d290.b01e = src;
          FUN_a00d9238();
          DAT_a802cff4.h000 |= 0x400;
        }
      }
      else
      {
        if (DAT_a802cff4.h00a & 0x40)
        {
          break;
        }
        if ((DAT_a802d290.b01e != src) && ((DAT_a802d290.b01f == 0) || (DAT_a802d290.b020 != src)))
        {
          DAT_a802d290.b01e = src;
          FUN_a00d9238();
          DAT_a802cff4.h000 |= 0x400;
        }
      }
        break;

      case 5:
        FUN_a0081ea8(1);

      case 6:
        FUN_a00df170(s_000ff508);
        DAT_a8024010[0] = FUN_a0147770();
        DAT_a8024010[1] = (FUN_a0147770() & 0xffff) >> 8;
        DAT_a8024010[2] = FUN_a0147770() >> 16;
        DAT_a8024010[3] = FUN_a0147770() >> 24;
        break;

      case 7:
        FUN_a0147780(DAT_a8024018);
        break;

    }

  }
  else
  {
    FUN_a0147790();
  }
  if (FUN_a0086a3c(1) == 0)
  {
    FUN_a00869b0(1, 1000);
    if (DAT_a802af44 & 1)
    {
      FUN_a0145360(2);
    }
    if (DAT_a802af44 & 2)
    {
      FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
    }
    if (DAT_a802af44 & 4)
    {
      FUN_a0145360(0);
    }
    if (DAT_a802af44 & 8)
    {
      FUN_a0145360(1);
    }
    DAT_a802af44 = 0;
  }
  FUN_a0083ff0(0);
  if ((FUN_a0086a3c(0x14) == 0) && (DAT_a802cff4.h00a & 0x40))
  {
    DAT_a802cff4.h00a &= ~0x40;
  }
  if (((((DAT_a802d290.b04a != 0) && (FUN_a00d7d48() == 0)) && (DAT_a802d290.b01f == 0)) && (FUN_a0143c14(0) == 10)) && (FUN_a0143c14(1) == 10))
  {
    FUN_a014d474(1, 1);
  }
  if ((FUN_a0086a3c(0x15) == 0) && FUN_a0124a40())
  {
    FUN_a00869b0(0x15, 20000);
    if (((unsigned char) (DAT_a802af47 + 1)) > 3)
    {
      DAT_a802af47 = 1;
      if (((unsigned char) (DAT_a802d274.b11 + 1)) > 0x3b)
      {
        DAT_a802d274.b11 = 0;
        if (DAT_a802d274.h12 != 0xffff)
        {
          DAT_a802d274.h12++;
          FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c);
        }
      }
      else
      {
        DAT_a802d274.b11 = DAT_a802d274.b11 + 1;
      }
    }
    else
    {
      DAT_a802af47 = DAT_a802af47 + 1;
    }
  }
  if ((FUN_a0086a3c(0x16) == 0) && (DAT_a802cff4.h004 & 0x800))
  {
    DAT_a802cff4.h004 &= ~0x800;
    FUN_a0125bbc(1);
  }
  if (DAT_a802af41 & 1)
  {
    if (FUN_a0086a3c(3) == 0)
    {
      FUN_a008f354();
      FUN_a008ee6c(0xff, 0);
      DAT_a802af41 &= ~1;
      FUN_a0143da8();
    }
  }
  else
    if (DAT_a802af42 & 0x10)
  {
    if (DAT_a802d290.b1d5 != 0)
    {
      if (FUN_a0086a3c(0xb) == 0)
      {
        FUN_a0124ab0();
        FUN_a0124af8();
        DAT_a802d290.w0a8 |= 0x40;
        FUN_a00d9978();
        FUN_a0082b00();
        FUN_a008ee6c(0xff, 0);
        if (!(DAT_a802cff4.h004 & 0x200))
        {
          FUN_a0143804(0x3ff);
          DAT_a802cff4.h004 |= 0x200;
          *((unsigned char *) (&DAT_a802cff4.h006)) = 0;
        }
        FUN_a00869b0(0xb, 1000);
      }
    }
    else
      if (FUN_a0086a3c(0xb) == 0)
    {
      if (((FUN_a0143c14(0) != 10) && (!(DAT_a802d290.w000 & 0x200))) && (FUN_a0090fcc() == 0xfe))
      {
        FUN_a00b7f9c(0x19);
        FUN_a0090fa0(0);
        FUN_a00869b0(0xb, 3000);
      }
      else
        if (DAT_a802cff4.h006 & 0x20)
      {
        DAT_a802cff4.h006 = (DAT_a802cff4.h006 & (~0x20)) | 0x10;
        FUN_a00869b0(0xb, 5000);
        FUN_a0124ab0();
        FUN_a0124af8();
        FUN_a0125ac8();
        FUN_a014512c(0, 1);
      }
      else
        if ((DAT_a802d290.w0a8 & 0x8000) || (FUN_a0145af8(2) == 1))
      {
        if (DAT_a802cff4.s004.f13 == 0)
        {
          DAT_a802cff4.s004.f13 = 2;
          FUN_a0124ab0();
          FUN_a0124af8();
          FUN_a0125ac8();
          FUN_a0090fd8();
          FUN_a014512c(0, 1);
          if ((!FUN_a012792c()) && (!FUN_a0127944()))
          {
            FUN_a01278f0(1);
            FUN_a0127914(1);
          }
          FUN_a0127c78();
        }
        FUN_a00869b0(0xb, 1000);
      }
      else
      {
        FUN_a00df170(s_000ff4d8);
        goto power_saving;
      }
    }
  }
  else
    if (DAT_a802af42 & 0x4000)
  {
    if (DAT_a802d290.b1d5 != 0)
    {
      if (((((!FUN_a012792c()) && (!FUN_a0127944())) && (!((DAT_a802d290.w0a8 & 0x8000) && (DAT_a802cff4.s004.f13 != 0)))) && (FUN_a0086a3c(0xb) == 0)) && (DAT_a802cff4.s014.b14 == 0))
      {
        FUN_a0124ab0();
        FUN_a0124af8();
        DAT_a802d290.w0a8 |= 0x40;
        FUN_a00d9978();
        if (DAT_a802d290.h1f6 == 0x55aa)
        {
          FUN_a00d4970();
          FUN_a0124f24();
          FUN_a0125950();
          FUN_a0125988();
          FUN_a0125bc4();
        }
        FUN_a01084a8(FUN_a013cda8(3), 0);
        FUN_a0109554(FUN_a013cda8(3), 0);
        FUN_a0082b00();
        if (!(DAT_a802cff4.h004 & 0x200))
        {
          DAT_a802cff4.h004 |= 0x200;
        }
        if (DAT_a802d290.b1d5 == 1)
        {
          FUN_a00869b0(0xb, 1000);
        }
        else
          if (DAT_a802d290.b1d5 == 2)
        {
          if (DAT_a802af46 > 2)
          {
            FUN_a00869b0(0xb, 100);
          }
          else
          {
            FUN_a00869b0(0xb, 1000);
          }
        }
        else
          if (DAT_a802d290.b1d5 == 3)
        {
          FUN_a00869b0(0xb, 1500);
        }
      }
    }
    else
      if (FUN_a0086a3c(0xb) == 0)
    {
      if (((FUN_a0143c14(0) != 10) && (!(DAT_a802d290.w000 & 0x200))) && (FUN_a0090fcc() == 0xfe))
      {
        FUN_a00b7f9c(0x19);
        FUN_a0090fa0(0);
        FUN_a00869b0(0xb, 3000);
      }
      else
        if ((DAT_a802cff4.h006 & 0x20))
      {
        DAT_a802cff4.h006 = (DAT_a802cff4.h006 & (~0x20)) | 0x10;
        FUN_a00869b0(0xb, 5000);
        FUN_a0124ab0();
        FUN_a0124af8();
        FUN_a0125ac8();
        FUN_a0090fd8();
        FUN_a014512c(0, 1);
      }
        else
      {
        if ((DAT_a802d290.w0a8 & 0x8000) || (FUN_a0145af8(2) == 1))
        {
          if (DAT_a802cff4.s004.f13 == 0)
          {
            DAT_a802cff4.s004.f13 = 2;
            FUN_a0124ab0();
            FUN_a0124af8();
            FUN_a0125ac8();
            FUN_a0090fd8();
            FUN_a014512c(0, 1);
            if ((!FUN_a012792c()) && (!FUN_a0127944()))
            {
              FUN_a01278f0(1);
              FUN_a0127914(1);
            }
            FUN_a0127c78();
          }
          FUN_a00869b0(0xb, 1000);
        }
        else
        {
          FUN_a00df170(s_000ff470);
          power_saving:
          FUN_a0081ea8(3);

          DAT_a802af42 &= ~0x10;
        }
      }
    }
  }
  FUN_a00bbabc(FUN_a00ce348(FUN_a0124244(0)));
  if (((((DAT_a802d290.b01f == 2) && (DAT_a802d290.b02f == 0)) && (FUN_a0143c14(1) > 7)) && (FUN_a014448c(1) == 0xd)) && (FUN_a0086a3c(0x11) == 0))
  {
    FUN_a0084330(0);
    FUN_a00869b0(0x11, 200);
  }
}
