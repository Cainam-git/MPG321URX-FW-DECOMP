/* FUN_a01413d0 (panel power sequencer). Flags: -mcpu=v8 -O3 -g.
 * Source form: the panel power request FUN_a01412b8 (the function just before this one) is defined here as a static
 * copy of its body and inlined: case 5 (power-on done) calls it with 0 when a request is pending (DAT_a802cc09 == 1),
 * case 9 (power-off done) sets state 1 and calls it with 1 when a request is pending (the firmware's 'be,a ; clrb'
 * at 0xa01414b8 and the 'mov 2' arm at 0xa01417ac).
 */

struct PwrSeq
{
  unsigned char state;
  unsigned short t;
  unsigned short req : 1;
  unsigned short rest : 15;
};
extern struct PwrSeq DAT_a802e110;
struct ActiveRow
{
  unsigned int w0;
  unsigned char pad[0x34];
  unsigned short t38;
  unsigned short t3a;
  unsigned short t3c;
  unsigned short t3e;
  unsigned short t40;
};
extern struct ActiveRow DAT_a802e378;
extern unsigned char DAT_a802cc08;
extern unsigned char DAT_a802cc09;
extern unsigned int *FUN_a01241fc(void);
extern unsigned short func_0x4008d594(unsigned short);
extern unsigned short func_0x4008d588(void);
extern void FUN_a0124874(void);
extern void FUN_a0124850(void);
extern void FUN_a0124890(void);
extern void FUN_a01249b4(void);
extern void FUN_a01249d0(void);
extern void FUN_a01249ec(void);
extern void FUN_a0124a08(void);
extern void FUN_a01248ac(void);
extern unsigned char FUN_a0124828(void);
extern unsigned char FUN_a012498c(void);
extern unsigned char FUN_a0124914(void);
extern void FUN_a01111f4(void);
extern void FUN_a011149c(void);
extern void FUN_a01223b0(void);
extern void FUN_a0125c9c(void);
extern void FUN_a01227f0(void);
extern void FUN_a0125c94(void);
extern void FUN_a01381c4(int);
extern void FUN_a0106bfc(int, int, int, int);
extern int FUN_a00df170();
extern char s_001a6a90[];
extern char s_001a6ab0[];
static void FUN_a01412b8(unsigned char on)
{
    DAT_a802cc09 = 0;
    if ((on == 1 && (unsigned char)(DAT_a802e110.state - 2) <= 3) || (on == 0 && (unsigned char)(DAT_a802e110.state - 7) <= 2))
        ;
    else if ((on == 1 && DAT_a802e110.state == 6) || (on == 0 && DAT_a802e110.state == 1))
        ;
    else if ((on == 0 && (unsigned char)(DAT_a802e110.state - 2) <= 3) || (on == 1 && (unsigned char)(DAT_a802e110.state - 7) <= 2)) {
        DAT_a802cc09 = 1;
        if (on == 1)
            DAT_a802e110.req = 1;
    } else {
        if (on == 1)
            DAT_a802e110.state = 2;
        else
            DAT_a802e110.state = 7;
    }
}
void FUN_a01413d0(void)
{
  unsigned int *cfg = FUN_a01241fc();
  switch (DAT_a802e110.state)
  {
    case 1:
      if (DAT_a802e110.req)
    {
      DAT_a802e110.state = 2;
    }
      break;

    case 2:
      DAT_a802cc08 = 0;
      if (func_0x4008d594(DAT_a802e110.t) > DAT_a802e378.t40)
    {
      FUN_a0124850();
      DAT_a802e110.req = 0;
      DAT_a802e110.t = func_0x4008d588();
      DAT_a802e110.state = 3;
    }
      break;

    case 3:
      if (func_0x4008d594(DAT_a802e110.t) != 0)
    {
      if (((*cfg) & 0x700000) == 0x200000)
      {
        FUN_a01381c4(1);
      }
      DAT_a802e110.t = func_0x4008d588();
      DAT_a802e110.state = 4;
    }
      break;

    case 4:
      if (func_0x4008d594(DAT_a802e110.t) > DAT_a802e378.t38)
    {
      if (((*cfg) & 0x700000) == 0x100000)
      {
        FUN_a01227f0();
        FUN_a0125c94();
      }
      else
        if (((*cfg) & 0x700000) == 0)
      {
        FUN_a011149c();
      }
      else
        if (((*cfg) & 0x700000) == 0x200000)
      {
        if (func_0x4008d594(DAT_a802e110.t) > (DAT_a802e378.t38 + 3000))
        {
          FUN_a00df170(s_001a6ab0);
        }
      }
      DAT_a802e110.t = func_0x4008d588();
      DAT_a802e110.state = 5;
    }
      break;

    case 5:
    {
      struct PwrSeq *p;
      if (FUN_a012498c() == 1)
    {
      FUN_a01249b4();
    }
      p = &DAT_a802e110;
      if (func_0x4008d594(p->t) > DAT_a802e378.t3a)
    {
      p->state = 6;
      FUN_a0124890();
      p->t = func_0x4008d588();
      if (FUN_a0124914() != 1)
      {
        FUN_a00df170(s_001a6a90);
      }
      if (DAT_a802cc09 == 1)
      {
        FUN_a01412b8(0);
      }
      else
      {
        FUN_a01249ec();
      }
    }
      break;
    }

    case 6:
      if ((DAT_a802cc08 == 0) && (func_0x4008d594(DAT_a802e110.t) > 100))
    {
      DAT_a802cc08 = 1;
    }
      break;

    case 7:
      DAT_a802cc08 = 0;
      FUN_a0124a08();
      FUN_a01248ac();
      if (FUN_a0124828() == 1)
      {
        if (FUN_a012498c() == 0)
        {
          FUN_a01249d0();
          FUN_a0106bfc(0, 0, 0, 0);
          DAT_a802e110.state = 8;
          DAT_a802e110.t = func_0x4008d588();
        }
      }
      else
        DAT_a802e110.state = 1;
      break;

    case 8:
      if (func_0x4008d594(DAT_a802e110.t) > DAT_a802e378.t3e)
    {
      if (((*cfg) & 0x700000) == 0)
      {
        FUN_a01111f4();
      }
      if (((*cfg) & 0x700000) == 0x100000)
      {
        FUN_a01223b0();
        FUN_a0125c9c();
      }
      if (((*cfg) & 0x700000) == 0x200000)
      {
        FUN_a01381c4(0);
      }
      DAT_a802e110.state = 9;
      DAT_a802e110.t = func_0x4008d588();
    }
      break;

    case 9:
      if (func_0x4008d594(DAT_a802e110.t) > DAT_a802e378.t3c)
    {
      FUN_a0124874();
      DAT_a802e110.state = 1;
      if (DAT_a802cc09 == 1)
      {
        FUN_a01412b8(1);
      }
      DAT_a802e110.t = func_0x4008d588();
    }
      break;

  }

}
