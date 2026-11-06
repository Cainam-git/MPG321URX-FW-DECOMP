/* leon2m FUN_a008e7b0 @ 0xa008e7b0-0xa008ec48 (294 words), flags -mcpu=v8 -O3 -g.
 * a = FUN_a012621c(), k = FUN_a012621c(); the k part is the code of FUN_a008e650. idx = index (0..15) of the first
 * of the 16 two-byte entries at 0x10051f whose first byte is a (0 when none). When byte 0xa802afe2 differs from
 * idx: for idx 0 with word 0xa802afe4 == 3, 0xa802afe2 and 0xa802afe4 are cleared and the old 0xa802afe2 is the
 * key, else 0xa802afe2 = idx; for idx != 0, 0xa802afe2 = idx, 0xa802afe4 = 1 / 2 / 3 / 4 from bit idx of the
 * halfwords 0xa802afdc / afda / afd8 / afc0 (the last set one), 0xa802afde = FUN_a0147724(), 0xa802afe0 = halfword
 * 0xa8024048 for state 1, 0xa8024044 for states 2 and 3 (key 0 then), state 4 clears 0xa802afe2 and the key. When
 * they are equal: states 2 / 3 / 1 with idx != 0 test FUN_a0147740(0xa802afde) > 0xa802afe0 (key 0 otherwise):
 * state 2 clears 0xa802afe4, state 3 clears it and looks up byte 0xa802afc8[idx] in the second bytes of the table
 * (the key = that index), state 1 restarts the timer with 0xa8024046; any other case restarts the timer, clears
 * 0xa802afe4 and the key. v = second byte of table entry key (0x4f for 0x40 when FUN_a0147740(halfword
 * 0xa802d00e) < 1000), FUN_a008a184(v); when bit 15 of halfword 0xa802cff4 is set, FUN_a008a184(0x41) and the
 * bit is cleared.
 * Source form: the three searches as unsigned char for loops (FUN_a008e650 style) with 'idx = j & 0xf' into the
 * unsigned int idx; key and the saved key i are unsigned char locals assigned from idx ('key = idx; i = idx;'):
 * their zero extensions stay 'and 0xff' (0xa008e8ac, 0xa008e9f8, 0xa008eb58, 0xa008eb7c); the same-key tests
 * are 'key != 0'; the state 4 arm clears 0xa802afe2 and key and jumps past 'key = i;' (goto).
 */

struct Ent
{
  unsigned char mask;
  unsigned char val;
};
struct R290
{
  unsigned int w000;
  unsigned char p004[0x1d1];
  unsigned char b1d5;
  unsigned char p1d6[0x20];
  unsigned short h1f6;
};
struct F4
{
  union 
  {
    unsigned short h;
    struct 
    {
      unsigned short b15 : 1;
      unsigned short : 15;
    } f;
  } u0;
  unsigned char p2[4];
  unsigned char b6;
  unsigned char p7[0x13];
  unsigned short h1a;
};
extern const struct Ent DAT_0010053f[6];
extern unsigned char DAT_0010051f[];
extern struct R290 DAT_a802d290;
extern struct F4 DAT_a802cff4;
extern unsigned char DAT_a802d274[];
extern unsigned char DAT_a802afe2;
extern unsigned int DAT_a802afe4;
extern unsigned short DAT_a802afde;
extern unsigned short DAT_a802afe0;
extern unsigned short DAT_a802afc0;
extern unsigned short DAT_a802afd8;
extern unsigned short DAT_a802afda;
extern unsigned short DAT_a802afdc;
extern unsigned char DAT_a802afc8[];
extern unsigned short DAT_a8024044;
extern unsigned short DAT_a8024046;
extern unsigned short DAT_a8024048;
extern unsigned char FUN_a012621c(void);
extern int FUN_a014aed0(unsigned char, void *, unsigned short, unsigned short);
extern unsigned short FUN_a0147724(void);
extern unsigned short FUN_a0147740(unsigned short);
extern void FUN_a008a184(unsigned char);
void FUN_a008e7b0(void)
{
  unsigned char a;
  unsigned char k;
  unsigned char v = 0;
  unsigned char i;
  unsigned char j;
  unsigned int idx;
  unsigned char key;
  a = FUN_a012621c();
  k = FUN_a012621c();
  if (k != 0)
  {
    for (j = 0; j < 6; j++)
    {
      if (DAT_0010053f[j].mask & k)
      {
        v = DAT_0010053f[j].val;
        break;
      }
    }
    DAT_a802cff4.b6 = v;
    if (((DAT_a802d290.h1f6 == 0x55aa) && (!(DAT_a802d274[0x10] & DAT_a802cff4.b6))) && (DAT_a802d290.b1d5 == 0))
    {
      DAT_a802d274[0x10] |= DAT_a802cff4.b6;
      FUN_a014aed0(0x30, DAT_a802d274, 0x2e0, 0x1c);
    }
  }
  if (DAT_a802cff4.u0.h & 0x800)
  {
    if (k == 2)
    {
      DAT_a802d290.w000 |= 0x4000;
    }
    else
    {
      DAT_a802d290.w000 &= ~0x4000;
    }
  }
  DAT_a802cff4.u0.h &= ~0x800;
  for (j = 0; j < 16; j++)
    if (DAT_0010051f[j * 2] == a)
      break;
  idx = j & 0xf;
  key = idx;
  i = idx;
  if (DAT_a802afe2 != key)
  {
    if (key == 0)
    {
      if (DAT_a802afe4 == 3)
      {
        key = DAT_a802afe2;
        DAT_a802afe2 = 0;
        DAT_a802afe4 = 0;
      }
      else
      {
        DAT_a802afe2 = idx;
      }
    }
    else
    {
      DAT_a802afe2 = idx;
      DAT_a802afe4 = (DAT_a802afdc >> key) & 1;
      DAT_a802afe4 = ((DAT_a802afda >> key) & 1) ? (2) : (DAT_a802afe4);
      DAT_a802afe4 = ((DAT_a802afd8 >> key) & 1) ? (3) : (DAT_a802afe4);
      DAT_a802afe4 = ((DAT_a802afc0 >> key) & 1) ? (4) : (DAT_a802afe4);
      DAT_a802afde = FUN_a0147724();
      if (DAT_a802afe4 == 1)
      {
        DAT_a802afe0 = DAT_a8024048;
      }
      else
        if (DAT_a802afe4 == 2)
      {
        DAT_a802afe0 = DAT_a8024044;
        i = 0;
      }
      else
        if (DAT_a802afe4 == 3)
      {
        DAT_a802afe0 = DAT_a8024044;
        i = 0;
      }
      else
        if (DAT_a802afe4 == 4)
      {
        DAT_a802afe2 = 0;
        key = 0;
        goto done;
      }
      key = i;
      done:;
    }
  }
  else
    if ((key != 0) && (DAT_a802afe4 == 2))
  {
    if (FUN_a0147740(DAT_a802afde) > DAT_a802afe0)
    {
      DAT_a802afe4 = 0;
    }
    else
    {
      key = 0;
    }
  }
  else
    if ((key != 0) && (DAT_a802afe4 == 3))
  {
    if (FUN_a0147740(DAT_a802afde) > DAT_a802afe0)
    {
      DAT_a802afe4 = 0;
      for (j = 0; j < 16; j++)
        if (DAT_0010051f[j * 2 + 1] == DAT_a802afc8[key])
          break;
      idx = j & 0xf;
      key = idx;
    }
    else
    {
      key = 0;
    }
  }
  else
    if ((key != 0) && (DAT_a802afe4 == 1))
  {
    if (FUN_a0147740(DAT_a802afde) > DAT_a802afe0)
    {
      DAT_a802afde = FUN_a0147724();
      DAT_a802afe0 = DAT_a8024046;
    }
    else
    {
      key = 0;
    }
  }
  else
  {
    DAT_a802afde = FUN_a0147724();
    DAT_a802afe4 = 0;
    key = 0;
  }
  v = DAT_0010051f[(key * 2) + 1];
  if ((FUN_a0147740(DAT_a802cff4.h1a) < 1000) && (v == 0x40))
  {
    v = 0x4f;
  }
  FUN_a008a184(v);
  if (DAT_a802cff4.u0.f.b15)
  {
    FUN_a008a184(0x41);
    DAT_a802cff4.u0.f.b15 = 0;
  }
}
