/* leon2m FUN_a008454c: (rawcmp a008454c..a0085984 1294 words / 0 mismatches.
   -mcpu=v8 -O3 -g). Source-form levers (all behaviour-neutral):
   - case 2 in the plain form; cases 60 and 62 placed just before case 2 (source order only, each ends in break):
     all 281 rnreg decisions match the firmware (rnmap 0).
   - case 17: the line-525 'ac & 0x100000' false path leaves through 'break' of a do { } while (0) that also encloses the
     second ac test, so it skips that test directly (same as gcc's own jump threading; nothing between the two
     tests writes memory). 'break' carries no branch prediction, unlike goto. The second test is
     'if (!(ac & 0x100000)) goto c17j; FUN_a014a8d4(0, 1, 1000); c17j: ;' (call 30 % + goto 70 % = 50 %).
     Effect: the threading of 76->81 happens at expand time instead of at 19.life, so its jump keeps bp's 5000:
     bbro bb85 edges are exactly 50/50 (fw), no triangle push of bb86, cold traces 78/124 in fw order, the 'be' delay
     slot is still filled from the target.
   - case 17: the nine independent 0xff stores to the non-volatile byte arrays DAT_a8024010[0..3] / DAT_a8024018[0..4]
     are written in the order that sched gives the firmware store order (same nine stores, same value, nothing between).
   - documented no-code branch-weight hints, 'do continue; while (0);' (PRED_CONTINUE 56 %, emits no instructions,
     behaviour-neutral: the continue only leaves the do-while(0)): first statement of case 60's 'w0 & 0x4000' true arm,
     of case 2's 'FUN_a012792c() == 2 || == 1' body and of case 21's 'a8u.w & 0x80' arm. In case 2 a 'goto d413;
     d413: ;' (PRED_GOTO, no instructions) comes first, in front of the 'do continue; while (0);'. Effect: cold-tail
     order 146 first (fw) and the key -6 cold traces in firmware order (204,63,186,78,124).
   - case 7 delay: 'if (C1) FUN_a0148358(8000); else { if (is55aa() && b1d5) { goto dl; dl: ; t = 100; } else t = 6500;
     FUN_a0148358(t); }' instead of three FUN_a0148358 calls (same values, same call; t is set on both paths before use;
     the goto is a no-code hint label in the new arm). This CFG shape puts the key -11 cold traces in
     firmware order (170,146,58,60,32,96,56) and keeps all 281 rename decisions (rnmap 0).
   - the four APPActionDispatcher format strings are named by their firmware addresses (contents checked in the image):
     s_APPEvent -> s_000fefc8, s_KeyEvent -> s_000feff8, s_OSDEvent -> s_000ff028, s_DDCCiEvent -> s_000ff058. */

struct B16
{
  unsigned short b15 : 1;
  unsigned short b14 : 1;
  unsigned short b13 : 1;
  unsigned short b12 : 1;
  unsigned short b11 : 1;
  unsigned short b10 : 1;
  unsigned short b9 : 1;
  unsigned short b8 : 1;
  unsigned short b7 : 1;
  unsigned short b6 : 1;
  unsigned short b5 : 1;
  unsigned short b4 : 1;
  unsigned short b3 : 1;
  unsigned short b2 : 1;
  unsigned short b1 : 1;
  unsigned short b0 : 1;
};
struct B32
{
  unsigned int b31 : 1;
  unsigned int b30 : 1;
  unsigned int b29 : 1;
  unsigned int b28 : 1;
  unsigned int b27 : 1;
  unsigned int b26 : 1;
  unsigned int b25 : 1;
  unsigned int b24 : 1;
  unsigned int b23 : 1;
  unsigned int b22 : 1;
  unsigned int b21 : 1;
  unsigned int b20 : 1;
  unsigned int b19 : 1;
  unsigned int b18 : 1;
  unsigned int b17 : 1;
  unsigned int b16 : 1;
  unsigned int b15 : 1;
  unsigned int b14 : 1;
  unsigned int b13 : 1;
  unsigned int b12 : 1;
  unsigned int b11 : 1;
  unsigned int b10 : 1;
  unsigned int b9 : 1;
  unsigned int b8 : 1;
  unsigned int b7 : 1;
  unsigned int b6 : 1;
  unsigned int b5 : 1;
  unsigned int b4 : 1;
  unsigned int b3 : 1;
  unsigned int b2 : 1;
  unsigned int b1 : 1;
  unsigned int b0 : 1;
};
struct AppS
{
  union 
  {
    unsigned short w;
    struct B16 f;
  } h0u;
  unsigned short h2;
  union 
  {
    unsigned short w;
    struct B16 f;
  } h4u;
  union 
  {
    unsigned short w;
    struct B16 f;
  } h6u;
  unsigned short h8;
  unsigned short ha;
  unsigned char p0c[0x18 - 0x0c];
  unsigned short h18;
  unsigned short h1a;
  unsigned char b1c;
  unsigned char p1d[0x3e - 0x1d];
  unsigned short h3e;
};
struct AppD
{
  unsigned int w0;
  unsigned char p04[0x1e - 0x04];
  unsigned char b1e;
  unsigned char b1f;
  unsigned char b20;
  unsigned char b21;
  unsigned char b22;
  unsigned char p23[0x4a - 0x23];
  unsigned char b4a;
  unsigned char p4b[0xa8 - 0x4b];
  union 
  {
    unsigned int w;
    struct B32 f;
  } a8u;
  union 
  {
    unsigned int w;
    unsigned char b[4];
  } ac;
  unsigned int b0;
  unsigned char pb4[0x181 - 0xb4];
  unsigned char b181;
  unsigned char b182;
  unsigned char p183[0x187 - 0x183];
  unsigned char b187;
  unsigned char b188;
  unsigned char p189[0x1a4 - 0x189];
  unsigned char b1a4;
  unsigned char p1a5[0x1b4 - 0x1a5];
  unsigned char b1b4;
  unsigned char p1b5[0x1d5 - 0x1b5];
  unsigned char b1d5;
  unsigned char p1d6[0x1ec - 0x1d6];
  unsigned int w1ec;
  unsigned char p1f0[0x1f6 - 0x1f0];
  unsigned short h1f6;
};
extern struct AppS DAT_a802cff4;
extern struct AppD DAT_a802d290;
extern unsigned char DAT_a802af40;
extern unsigned char DAT_a802af44;
extern unsigned char DAT_a802e1a7;
extern unsigned char DAT_a8025c57;
extern unsigned short DAT_a802af42;
extern unsigned char DAT_a8024010[4];
extern unsigned char DAT_a8024018[5];
extern const unsigned char DAT_000fec40[];
extern const unsigned char DAT_000fec08[];
extern const unsigned char DAT_000fece0[];
extern const unsigned char DAT_000feca8[];
extern const unsigned char DAT_000fec88[];
extern const unsigned char DAT_000fec80[];
extern const unsigned int DAT_000fecb0[];
extern const unsigned int DAT_000fec90[];
extern char s_000fefc8[];
extern char s_000feff8[];
extern char s_000ff028[];
extern char s_000ff058[];
extern char s_000ff090[];
extern char s_000ff0a8[];
extern char s_000ff0e0[];
extern char s_000ff108[];
extern char s_000ff128[];
extern char s_000ff148[];
extern char s_000ff168[];
extern char s_000ff188[];
extern char s_000ff1a8[];
extern char s_000ff1c8[];
extern char s_000ff1e0[];
extern char s_000ff1f8[];
extern char s_000ff218[];
extern char s_000ff230[];
extern char s_000ff248[];
extern char s_000ff260[];
extern char s_000ff280[];
extern char s_000ff298[];
extern char s_000ff2b8[];
extern char s_000ff2d0[];
extern char s_000ff300[];
extern unsigned char FUN_a00dd614(unsigned int);
extern int FUN_a00df170();
extern void FUN_a014a8d4(int, int, int);
extern void FUN_a0080978(void);
extern void FUN_a0081ea8(int);
extern void FUN_a00869b0(int, int);
extern void FUN_a014b4b4(int, int);
extern unsigned char FUN_a0141a98(void);
extern unsigned short FUN_a0145660(unsigned char, unsigned int);
extern int FUN_a01447bc(int);
extern int FUN_a014448c(int);
extern void FUN_a014dd98(int, int);
extern void FUN_a00dac38(unsigned int, int, unsigned char);
extern void FUN_a01295d0(void);
extern void FUN_a0084330(int);
extern unsigned char FUN_a012792c(void);
extern unsigned char FUN_a0127944(void);
extern void FUN_a0124b40(void);
extern void FUN_a0124a68(void);
extern void FUN_a0124a08(void);
extern void FUN_a00d4970(void);
extern void FUN_a00d48cc(void);
extern void FUN_a00daae8(void);
extern void FUN_a00dab08(void);
extern void FUN_a00dab20(void);
extern void FUN_a00dab90(void);
extern void FUN_a00dabc8(void);
extern void FUN_a00dac00(void);
extern void FUN_a0148358();
extern void FUN_a008b330(void);
extern void FUN_a00d9978(void);
extern void FUN_a00d99a8(void);
extern void FUN_a00da754(unsigned char);
extern void FUN_a00db12c(unsigned char);
extern void FUN_a00dbcf0(void);
extern void FUN_a00db738(void);
extern void FUN_a00d5cd8(void);
extern unsigned short FUN_a0090fcc(void);
extern void FUN_a0090fd8(void);
extern unsigned short FUN_a014837c(int);
extern void FUN_a0146e2c(int, int, int, unsigned short, unsigned short);
extern unsigned char FUN_a014489c(int);
extern void FUN_a00da4b8(void);
extern void FUN_a014e320(void);
extern int FUN_a00d7d48(void);
extern void FUN_a0148aa8(unsigned char);
extern void FUN_a0086ae8(int);
extern void FUN_a01478a8(void);
extern void FUN_a014512c(unsigned int, unsigned int);
extern void FUN_a01479ec(unsigned char);
extern void FUN_a0143fc4(int);
extern void FUN_a0127938(unsigned char);
extern void FUN_a0127950(unsigned char);
extern void FUN_a01278e4(unsigned char);
extern void FUN_a0127914(unsigned char);
extern void FUN_a014782c(int);
extern void FUN_a014bc58(unsigned int);
extern void FUN_a014d474(unsigned char, unsigned char);
extern void FUN_a0148350(int);
extern unsigned char FUN_a01445fc(unsigned char);
extern unsigned char FUN_a014459c(unsigned char);
extern void FUN_a00d9238(void);
extern void FUN_a00d8ffc(void);
extern void FUN_a0125bfc(void);
extern unsigned char FUN_a0127920(void);
extern void FUN_a00daa7c(void);
extern unsigned char FUN_a014e8d8(void);
extern void FUN_a00da254(void);
static unsigned char src_used(unsigned char i)
{
  unsigned char sel = 0;
  if (i == 0)
    sel = 1;
  else
    if (i == 1)
  {
    if (DAT_a802d290.b1f != 0)
      sel = 1;
  }
  else
    if (i == 2)
  {
    if (((unsigned char) (DAT_a802d290.b1f - 4)) <= 3)
      sel = 1;
  }
  else
    if (i == 3)
  {
    if (DAT_a802d290.b1f == 7)
      sel = 1;
  }
  return sel;
}

static unsigned char vm(unsigned short h, unsigned short v, unsigned short f, unsigned short H, unsigned short V, unsigned short hi, unsigned short lo)
{
  return (((h == H) && (v == V)) && (f < hi)) && (f > lo);
}

static unsigned char vmode(unsigned short h, unsigned short v, unsigned short f, unsigned short H, unsigned short V, unsigned short lo, unsigned short hi)
{
  return ((h == H) & (v == V)) && ((f > lo) & (f < hi));
}

static unsigned char is55aa(void)
{
  return DAT_a802d290.h1f6 == 0x55aa;
}

static int mute_delay(void)
{
  if (((DAT_a802d290.ac.w & 0x100000) && (DAT_a802d290.b1f == 0)) && (!FUN_a01445fc(FUN_a014448c(0))))
    return 8000;
  if (is55aa() && (DAT_a802d290.b1d5 != 0))
    return 100;
  return 6500;
}

void FUN_a008454c(unsigned int ev)
{
  unsigned char idx;
  unsigned int act;
  unsigned short v;
  int new_var;
  int t;
  if ((ev & 0xc0) == 0x40)
  {
    idx = DAT_000fece0[ev & 0x3f];
    if (idx == 10)
    {
      return;
    }
    act = DAT_000fecb0[idx];
    if (FUN_a00dd614(0x80))
    {
      FUN_a00df170(s_000feff8, idx, act);
    }
  }
  else
    if ((ev & 0xc0) == 0x80)
  {
    idx = DAT_000feca8[ev & 0x3f];
    if (idx == 4)
    {
      return;
    }
    act = DAT_000fec90[idx];
    if (FUN_a00dd614(0x80))
    {
      FUN_a00df170(s_000ff028, idx, act);
    }
  }
  else
    if ((ev & 0xc0) == 0xc0)
  {
    idx = DAT_000fec88[ev & 0x3f];
    if (idx == 7)
    {
      return;
    }
    act = DAT_000fec80[idx];
    if (FUN_a00dd614(0x80))
    {
      FUN_a00df170(s_000ff058, idx, act);
    }
  }
  else
    if ((ev & 0xc0) == 0)
  {
    idx = DAT_000fec40[ev & 0x3f];
    if (idx == 0x30)
    {
      return;
    }
    act = DAT_000fec08[idx];
    if (FUN_a00dd614(0x80))
    {
      FUN_a00df170(s_000fefc8, idx, act);
    }
  }
  else
  {
    return;
  }
  switch (act)
  {
    case 1:
      FUN_a00df170(s_000ff1e0);
      if (DAT_a802cff4.h6u.f.b6)
    {
      DAT_a802cff4.h6u.f.b6 = 0;
      FUN_a00df170(s_000ff1f8);
      FUN_a0124b40();
      FUN_a0124a68();
      FUN_a0148aa8(1);
      FUN_a0086ae8(2);
    }
      break;

    case 60:
      if (DAT_a802d290.w0 & 0x4000)
    {
 do continue; while (0);
      DAT_a802d290.w0 &= ~0x4000;
      FUN_a014b4b4(0xfe, 1);
    }
    else
    {
      DAT_a802d290.w0 |= 0x4000;
      FUN_a014b4b4(0xfe, 1);
    }
      FUN_a0081ea8(2);
      FUN_a00869b0(1, 1000);
      DAT_a802af44 |= 8;
      break;

    case 62:
      if (DAT_a802d290.w0 & 0x2000)
    {
      DAT_a802d290.w0 &= ~0x2000;
    }
    else
    {
      DAT_a802d290.w0 |= 0x2000;
    }
      FUN_a0081ea8(2);
      FUN_a00869b0(1, 1000);
      DAT_a802af44 |= 8;
      break;

    case 2:
      if ((DAT_a802d290.ac.w & 0x100000) && (unsigned char)FUN_a014448c(0) == 5 && DAT_a802d290.b1f == 0) FUN_a014782c(1);
      if ((FUN_a012792c() == 2) || (FUN_a012792c() == 1))
    {
 goto d413; d413: ;
 do continue; while (0);
      FUN_a0127938(3);
      FUN_a0127950(0);
      FUN_a01278e4(0);
      FUN_a0127914(2);
    }
      FUN_a0081ea8(0);
      FUN_a00869b0(1, 1000);
      DAT_a802af44 |= 2;
      break;

    case 3:
      FUN_a0081ea8(2);
      FUN_a00869b0(1, 1000);
      DAT_a802af44 |= 2;
      break;

    case 4:
      FUN_a0081ea8(1);
      FUN_a00869b0(1, 1000);
      DAT_a802af44 |= 2;
      break;

    case 5:
      FUN_a0081ea8(3);
      break;

    case 6:
      FUN_a0081ea8(4);
      break;

    case 7:
      if (DAT_a802d290.w0 & 0x200)
    {
      if (DAT_a802d290.h1f6 == 0x55aa)
      {
        FUN_a00869b0(4, 3000);
      }
      else
      {
        FUN_a00869b0(4, 12000);
      }
      if (((DAT_a802d290.ac.w & 0x100000) && (DAT_a802d290.b1f == 0)) && (!FUN_a01445fc(FUN_a014448c(0))))
        FUN_a0148358(8000);
      else
      { if (is55aa() && (DAT_a802d290.b1d5 != 0))
        { goto dl; dl: ; t = 100; }
      else
        t = 6500;
      FUN_a0148358(t); }
    }
    else
    {
      FUN_a00869b0(4, 5000);
    }
      FUN_a00df170(s_000ff260);
      if (DAT_a802d290.b1f != 0)
    {
      FUN_a0090fd8();
    }
      if (DAT_a802d290.b0 != 0)
    {
      FUN_a014bc58(0);
    }
      if ((DAT_a802d290.b1f == 0) && (DAT_a802d290.b4a != 0))
    {
      FUN_a014d474(1, 0);
    }
      if (((!(DAT_a802d290.a8u.w & 0x4000)) && (DAT_a802d290.b1f != 0)) && (DAT_a802d290.ac.w & 0x20000))
    {
      FUN_a01479ec(1);
    }
      break;

    case 8:
      FUN_a00869b0(5, 5000);
      FUN_a00df170(s_000ff248);
      if (((DAT_a802d290.a8u.w & 0x4000) && (DAT_a802d290.b1f != 0)) && (DAT_a802d290.ac.w & 0x20000))
    {
      FUN_a01479ec(1);
    }
      break;

    case 9:
      FUN_a00869b0(6, 5000);
      break;

    case 10:
      FUN_a00869b0(7, 5000);
      break;

    case 12:
      FUN_a00df170(s_000ff218);
      DAT_a802cff4.h0u.f.b8 = 0;
      FUN_a0124a08();
      FUN_a014512c(0, 1);
      FUN_a00df170(s_000ff230);
      FUN_a01479ec(1);
      FUN_a0143fc4(1);
      break;

    case 16:
      FUN_a00df170(s_000ff280);
      FUN_a0124a08();
      FUN_a014512c(0, 0);
      break;

    case 17:
      FUN_a00df170(s_000ff090);
      if ((!(DAT_a802cff4.b1c & 1)) && DAT_a802cff4.h6u.f.b6)
    {
      DAT_a802cff4.h6u.f.b6 = 0;
      FUN_a00df170(s_000ff1f8);
      FUN_a0124b40();
      FUN_a0124a68();
      FUN_a0148aa8(1);
      FUN_a0086ae8(2);
    }
    else
    {
      do
      {
      if (!(DAT_a802cff4.b1c & 1))
      {
        if (!(DAT_a802d290.ac.w & 0x100000))
          break;
        if (DAT_a802d290.b1f == 0)
        {
        if (!FUN_a01445fc(FUN_a014448c(0)))
        {
          DAT_a8024010[2] = (DAT_a8024010[3] = 0xff);
          DAT_a8024018[4] = 0xff;
          DAT_a8024018[3] = 0xff;
          DAT_a8024018[2] = 0xff;
          DAT_a8024010[1] = 0xff;
          DAT_a8024010[0] = 0xff;
          DAT_a8024018[1] = 0xff;
          DAT_a8024018[0] = 0xff;
          FUN_a014782c(5);
          FUN_a014782c(7);
        }
        }
      }
      if (!(DAT_a802d290.ac.w & 0x100000))
        goto c17j;
      FUN_a014a8d4(0, 1, 1000);
      }
      while (0);
      c17j: ;
    }
      if ((DAT_a802e1a7 == 0) || (DAT_a802e1a7 == 2))
    {
      FUN_a0124a08();
    }
      FUN_a0080978();
      break;

    case 18:
      FUN_a0084330(1);
      FUN_a0080978();
      if ((((DAT_a802d290.b1f != 0) && (!(DAT_a802d290.w0 & 0x200))) && (!FUN_a012792c())) && (!FUN_a0127944()))
    {
      FUN_a0124b40();
      FUN_a0124a68();
    }
      break;

    case 19:
      FUN_a0080978();
      break;

    case 20:
      FUN_a0080978();
      break;

    case 21:
    {
      unsigned short a;
      unsigned short b;
      unsigned short c;
      unsigned char d;
      unsigned char e;
      FUN_a00df170(s_000ff0a8, DAT_a802d290.b1f, (DAT_a802cff4.h18 >> 13) & 1, FUN_a0141a98());
      if (!(DAT_a802cff4.b1c & 1))
      {
        if (((((unsigned short) FUN_a0145660(0, 7)) == FUN_a014837c(0)) && (((unsigned short) FUN_a0145660(0, 8)) == FUN_a014837c(1))) && (DAT_a802d290.b1a4 == 4))
        {
          DAT_a802d290.b1a4 = 0;
          FUN_a00da254();
          DAT_a802af44 |= 2;
        }
      }
      a = FUN_a0145660(0, 7);
      b = FUN_a0145660(0, 8);
      c = FUN_a0145660(0, 1);
      d = FUN_a01447bc(0);
      e = FUN_a014448c(0);
      if ((((a == 1920) && (b == 1080)) && (c < 2450)) && (c > 2350))
      {
        FUN_a014dd98(0, 1);
      }
      else
        if ((((a == 3840) && (b == 2160)) && (c < 1250)) && (c > 1150))
      {
        FUN_a014dd98(0, 1);
      }
      else
        if ((((((a == 2560) && (b == 1600)) && (c < 1490)) && (c > 1390)) && (d == 6)) && ((e == 12) || (e == 13)))
      {
        FUN_a014dd98(0, 1);
      }
      else
        if (DAT_a802d290.a8u.w & 0x80)
      {
 do continue; while (0);
        if (c)
        {
          FUN_a014dd98(0, 1);
        }
        else
        {
          FUN_a014dd98(0, 1);
        }
      }
      else
      {
        FUN_a014dd98(0, 0);
      }
      FUN_a00dac38(1, 1, 0);
      FUN_a01295d0();
      break;
    }

    case 22:
      FUN_a00dac38(1, 1, 0);
      FUN_a01295d0();
      break;

    case 25:
    {
      int x;
      int y;
      struct AppD *p;
      FUN_a00df170(s_000ff188);
      x = FUN_a014837c(0);
      y = FUN_a014837c(1);
      FUN_a0146e2c(0, 0, 0, x, y);
      p = &DAT_a802d290;
      if (DAT_a802cff4.b1c & 1)
      {
        break;
      }
      FUN_a00df170(s_000ff1a8);
      DAT_a8025c57 = FUN_a014489c(0);
      FUN_a00df170(s_000ff1c8);
      FUN_a00da4b8();
      DAT_a802af40 = p->b1b4;
      FUN_a014e320();
      if ((FUN_a00d7d48() != 0) && (!(DAT_a802cff4.ha & 0x80)))
      {
        p->a8u.f.b11 = p->a8u.f.b8;
        p->b182 = p->b188;
        p->b181 = p->b187;
      }
      if (!(DAT_a802d290.a8u.w & 0x800))
      {
        FUN_a00dbcf0();
      }
      else
      {
        FUN_a00db738();
      }
      if ((!(DAT_a802d290.a8u.w & 0x4000)) || (DAT_a802d290.b1f == 0))
      {
        FUN_a00d5cd8();
      }
      FUN_a00db12c(0);
      break;
    }

    case 26:
      FUN_a00df170(s_000ff168);
      if (DAT_a802cff4.b1c & 2)
    {
      break;
    }
      if (DAT_a802d290.b1f == 0)
    {
      break;
    }
      if (!(DAT_a802d290.w0 & 0x200))
    {
      if (!(DAT_a802d290.a8u.w & 0x800))
      {
        FUN_a00dbcf0();
      }
      else
      {
        FUN_a00db738();
      }
    }
      if (DAT_a802d290.a8u.w & 0x4000)
    {
      FUN_a00d5cd8();
    }
      if (FUN_a0090fcc() == 0x10d)
    {
      FUN_a0090fd8();
    }
      break;

    case 29:
      if (DAT_a802cff4.b1c != 0)
    {
      break;
    }
      FUN_a00df170(s_000ff148);
      FUN_a008b330();
      DAT_a802cff4.h4u.f.b9 = 0;
      if (DAT_a802d290.b1d5 != 0)
    {
      FUN_a0124b40();
      FUN_a0124a68();
      DAT_a802d290.ac.w |= 0x20000;
    }
      FUN_a00d9978();
      FUN_a00d99a8();
      FUN_a00da754(DAT_a802d290.ac.b[0]);
      if (DAT_a802d290.h1f6 == 0x55aa)
    {
      DAT_a802d290.w1ec |= 0x80;
    }
      FUN_a00db12c(0);
      break;

    case 30:
      FUN_a00df170(s_000ff128);
      break;

    case 31:
      FUN_a00df170(s_000ff108);
      if (!(DAT_a802cff4.b1c & 1))
    {
      DAT_a802d290.b1e = FUN_a014448c(0);
      FUN_a00df170(s_000ff300);
      if ((!(DAT_a802d290.a8u.w & 0x4000)) || (DAT_a802d290.b1f == 0))
      {
        FUN_a00d48cc();
      }
      FUN_a00869b0(1, 1000);
      DAT_a802af44 |= 2;
    }
      FUN_a014a8d4(0, 0, 0);
      new_var = ((DAT_a802d290.ac.w & 0x100000) && (DAT_a802d290.b1f == 0)) && (!FUN_a01445fc(FUN_a014448c(0)));
      if (new_var)
    {
      FUN_a0148358(8000);
    }
    else
    {
      FUN_a0148358(6500);
    }
      break;

    case 32:
      if ((!(DAT_a802cff4.b1c & 2)) && (DAT_a802d290.b1f != 0))
    {
      DAT_a802d290.b20 = FUN_a014448c(1);
      FUN_a00df170(s_000ff298);
      if ((DAT_a802d290.a8u.w & 0x4000) && (DAT_a802d290.b1f != 0))
      {
        FUN_a00d48cc();
      }
      FUN_a00869b0(1, 1000);
      DAT_a802af44 |= 2;
    }
      FUN_a014a8d4(1, 0, 0);
      break;

    case 33:
      if (!(DAT_a802cff4.b1c & 4))
    {
      DAT_a802d290.b21 = FUN_a014448c(2);
      FUN_a00869b0(1, 1000);
      DAT_a802af44 |= 2;
    }
      FUN_a014a8d4(2, 0, 0);
      break;

    case 34:
      if (!(DAT_a802cff4.b1c & 8))
    {
      DAT_a802d290.b22 = FUN_a014448c(3);
      FUN_a00869b0(1, 1000);
      DAT_a802af44 |= 2;
    }
      FUN_a014a8d4(3, 0, 0);
      break;

    case 35:
      DAT_a802cff4.h0u.f.b8 = 1;
      if (DAT_a802cff4.b1c == 0)
    {
      FUN_a00df170(s_000ff2b8);
      FUN_a00d4970();
      FUN_a00d8ffc();
      FUN_a0125bfc();
      if (FUN_a0127920() == 1)
      {
        if ((FUN_a012792c() == 2) || (FUN_a012792c() == 1))
        {
          FUN_a0127914(0);
        }
      }
      FUN_a00daae8();
      FUN_a00dab08();
      FUN_a00dab20();
      FUN_a00dab90();
      FUN_a00dabc8();
      FUN_a00dac00();
      FUN_a00daa7c();
      if (FUN_a014e8d8() == 1)
      {
        FUN_a00df170(s_000ff2d0);
        FUN_a00df170(s_000ff2d0);
        FUN_a00df170(s_000ff2d0);
      }
    }
    else
    {
      FUN_a00df170(s_000ff0e0);
      FUN_a00d4970();
      FUN_a00d48cc();
      FUN_a00daae8();
      FUN_a00dab08();
      FUN_a00dab20();
      FUN_a00dab90();
      FUN_a00dabc8();
      FUN_a00dac00();
    }
      break;

    case 36:
      DAT_a802af42 |= 1;
      break;

    case 37:
      DAT_a802af42 |= 2;
      break;

    case 38:
      DAT_a802af42 |= 4;
      break;

    case 39:
      DAT_a802af42 |= 8;
      break;

    case 40:
      if (!((DAT_a802af42 & 1) | ((DAT_a802af42 >> 10) & 1)))
    {
      break;
    }
      if ((src_used(1) == 1) && (!(((DAT_a802af42 >> 1) & 1) | ((DAT_a802af42 >> 11) & 1))))
    {
      break;
    }
      if ((src_used(2) == 1) && (!(((DAT_a802af42 >> 2) & 1) | ((DAT_a802af42 >> 12) & 1))))
    {
      break;
    }
      if ((src_used(3) == 1) && (!(((DAT_a802af42 >> 3) & 1) | ((DAT_a802af42 >> 13) & 1))))
    {
      break;
    }
      DAT_a802af42 |= 0x10;
    {
      unsigned short t = DAT_a802cff4.h3e & 0x8000;
      if (t)
      {
        break;
      }
    }
      FUN_a00869b0(0xb, 5000);
      break;

    case 42:
      DAT_a802af42 |= 0x400;
      break;

    case 43:
      DAT_a802af42 |= 0x800;
      break;

    case 44:
      DAT_a802af42 |= 0x1000;
      break;

    case 45:
      DAT_a802af42 |= 0x2000;
      break;

    case 46:
      if (!(DAT_a802af42 & 0x400))
    {
      break;
    }
      if ((src_used(1) == 1) && (!(DAT_a802af42 & 0x800)))
    {
      break;
    }
      if ((src_used(2) == 1) && (!(DAT_a802af42 & 0x1000)))
    {
      break;
    }
      if ((src_used(3) == 1) && (!(DAT_a802af42 & 0x2000)))
    {
      break;
    }
      DAT_a802af42 |= 0x4000;
    {
      unsigned short t = DAT_a802cff4.h3e & 0x8000;
      if (t)
      {
        break;
      }
    }
      FUN_a00869b0(0xb, 5000);
      break;

    case 47:
      FUN_a0148350(0);
      DAT_a802af42 |= 0x20;
      break;

    case 48:
      FUN_a0148350(1);
      DAT_a802af42 |= 0x40;
      break;

    case 49:
      FUN_a0148350(2);
      DAT_a802af42 |= 0x80;
      break;

    case 50:
      FUN_a0148350(3);
      DAT_a802af42 |= 0x100;
      break;

    case 51:
      DAT_a802af42 |= 0x200;
      FUN_a00869b0(0xb, 60000);
      break;

    case 53:
      FUN_a0081ea8(5);
      break;

    case 54:
      if (FUN_a014459c(FUN_a01445fc(DAT_a802d290.b1e) + 1) > 20)
    {
      DAT_a802d290.b1e = FUN_a014459c(0);
    }
    else
    {
      DAT_a802d290.b1e = FUN_a014459c(FUN_a01445fc(DAT_a802d290.b1e) + 1);
    }
      FUN_a00d9238();
      break;

    case 56:
      FUN_a00869b0(1, 1000);
      DAT_a802af44 |= 2;
      break;

    case 57:
      FUN_a00869b0(1, 1000);
      DAT_a802af44 |= 8;
      break;

    case 58:
      FUN_a00869b0(1, 1000);
      DAT_a802af44 |= 1;
      break;

    case 59:
      FUN_a00869b0(1, 1000);
      DAT_a802af44 |= 4;
      break;

    case 61:
      FUN_a01478a8();
      break;

    case 0:
      act = 0;
      break;

    case 11:
      act = 0;
      break;

    case 13:
      act = 0;
      break;

  }

  end:
  ;

  ;
  ;
  ;
  ;
}
