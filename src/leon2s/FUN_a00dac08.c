/* leon2s FUN_a00dac08 @ 0xa00dac08-0xa00dae90 (162 words), flags -mcpu=v8 -Os -g.
 * void (void); k = DAT_a8078832 (re-read at every use). chg = DAT_a8078808[k] != DAT_a8078800[k]; x = 1 when
 * k == 0 and FUN_a00d9d50() != 0xff, else 0; rv = byte 0 of word 0x258 of the register block DAT_a807609c[k].
 * Returns when chg and x are both 0 and bits 3..4 of rv are clear. Bits 3..4 clear (chg or x set):
 * r = FUN_a00d9e44(); r == 2: FUN_a00da49c(); r == 4: FUN_a00daa98(); otherwise FUN_a00da49c() when chg is set
 * and x is 0, or when FUN_a00d9e5c(2) >= FUN_a00d9e5c(4), else FUN_a00daa98(). A non-zero FUN_a00da49c() sets
 * DAT_a8078850[k] = 1, DAT_a8078848[k] = 0, DAT_a8078858[k] = func_0xa0fc2064(); a non-zero FUN_a00daa98() sets
 * DAT_a8078848[k] = 1, DAT_a8078850[k] = 0, DAT_a8078860[k] = func_0xa0fc2064(). Bits 3..4 set: when
 * func_0xa0fc2064() - DAT_a8078858[k] > FUN_a00dabf8() and DAT_a8078850[k] != 0: FUN_a00da388(1),
 * DAT_a8078850[k] = 0; otherwise when func_0xa0fc2064() - DAT_a8078860[k] > FUN_a00dac00(chg, x) and
 * DAT_a8078848[k] != 0: FUN_a00da960(1), DAT_a8078848[k] = 0.
 * Declared here: FUN_a00da49c / FUN_a00daa98 with an unsigned char result (btst 0xff after the calls),
 * FUN_a00dabf8 / FUN_a00dac00 with an unsigned short result (sll/srl 16); FUN_a00dac00 receives (chg & 1, x & 1).
 * Source forms: x set by an if/else inside the k == 0 test; the two store groups as static inline helpers
 * set50() / set48(), each called after both call sites of its test function (fw call sites 0xa00dacc0 and
 * 0xa00dad3c, 0xa00dace4 and 0xa00dad80; the store tails are merged at 0xa00dad54 and 0xa00dad98); rv an
 * unsigned char; 'u = ~x;' before 't = chg != 0;' for the (t & u) test.
 */

extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8078800[];
extern unsigned char DAT_a8078808[];
extern unsigned char DAT_a8078848[];
extern unsigned char DAT_a8078850[];
extern unsigned int DAT_a8078858[];
extern unsigned int DAT_a8078860[];
extern volatile unsigned int *DAT_a807609c[];
extern unsigned char FUN_a00d9d50(void);
extern unsigned char FUN_a00d9e44(void);
extern unsigned char FUN_a00d9e5c(unsigned char);
extern unsigned char FUN_a00da49c(void);
extern unsigned char FUN_a00daa98(void);
extern unsigned short FUN_a00dabf8(void);
extern unsigned short FUN_a00dac00(unsigned int, unsigned int);
extern void FUN_a00da388(unsigned char);
extern void FUN_a00da960(unsigned char);
extern unsigned int func_0xa0fc2064(void);
static inline void set50(void)
{
  DAT_a8078850[DAT_a8078832] = 1;
  DAT_a8078848[DAT_a8078832] = 0;
  DAT_a8078858[DAT_a8078832] = func_0xa0fc2064();
}
static inline void set48(void)
{
  DAT_a8078848[DAT_a8078832] = 1;
  DAT_a8078850[DAT_a8078832] = 0;
  DAT_a8078860[DAT_a8078832] = func_0xa0fc2064();
}
void FUN_a00dac08(void)
{
  unsigned char chg;
  unsigned char x;
  unsigned char r;
  unsigned int t;
  unsigned int u;
  unsigned int now;
  unsigned char rv;
  unsigned char k;
  chg = DAT_a8078808[DAT_a8078832] != DAT_a8078800[DAT_a8078832];
  if (DAT_a8078832 == 0)
  {
    if (FUN_a00d9d50() != 0xff)
      x = 1;
    else
      x = 0;
  }
  else
    x = 0;
  rv = DAT_a807609c[DAT_a8078832][0x258 / 4];
  if ((chg | x) == 0 && !(rv & 0x18))
    return;
  if (!(rv & 0x18))
  {
    r = FUN_a00d9e44();
    if (r == 2)
    {
      if (FUN_a00da49c())
        set50();
      return;
    }
    if (r == 4)
    {
      if (FUN_a00daa98())
        set48();
      return;
    }
    u = ~x;
    t = chg != 0;
    if ((t & u) || (FUN_a00d9e5c(2) >= FUN_a00d9e5c(4)))
    {
      if (FUN_a00da49c())
        set50();
      return;
    }
    if (FUN_a00daa98())
      set48();
    return;
  }
  now = func_0xa0fc2064();
  k = DAT_a8078832;
  if (((now - DAT_a8078858[k]) > FUN_a00dabf8()) && DAT_a8078850[k])
  {
    FUN_a00da388(1);
    DAT_a8078850[DAT_a8078832] = 0;
    return;
  }
  now = func_0xa0fc2064();
  k = DAT_a8078832;
  if (((now - DAT_a8078860[k]) > FUN_a00dac00(chg, x)) && DAT_a8078848[k])
  {
    FUN_a00da960(1);
    DAT_a8078848[DAT_a8078832] = 0;
  }
}
