/* leon2m FUN_a013d1b4 @ 0xa013d1b4-0xa013d670 (1212 bytes)  input capture window -> port record
 * Flags: -mcpu=v8 -O3 -g (303 words).
 *
 * void FUN_a013d1b4(unsigned char port, struct Win *w); w = 8 halfwords a..h (g signed).
 * Callers FUN_a013dc6c, FUN_a0149b8c.
 * 1. port 0 and 0xA802E3D3 != 0: g, a, e, c = x * RAW row +0x0A / RAW row +0x08 (int multiply, signed divide).
 *    else, port != 0 and 0xA802E3D4 & 0xF0000000: a, c rounded up to a multiple of 64, e = (e + 63) & 0xFFC0,
 *    g = (c - a) / 2 (signed shift).
 * 2. port record P = 0xA802DF30 + 0x78 * port: P+0x54 = b.
 * 3. port 0: hook 0xA802CC44 called if set, else 0xA802E3D0 bit 26 cleared; hook 0xA802CC40 likewise for bit 27.
 *    If class 0xA802E1A7 <= 4 and port-0 record +0x54 >= ROM halfword 0x1A30DA:
 *       if port-0 record bit 0, or record +0x40 bit 30, or 0xA802E3D0 bit 26:
 *            X = RAW row +0x26 + +0x28, Y = RAW row +0x30 + +0x32, E = F = 0
 *       else X = 0x18, Y = 3, E = e, F = f;
 *       window (A,B) = (c,d), (C,D) = (a,b)
 *    else (and every port other than port 3 with 0xA802E3D0 bit 21): (A,B) = (C,D) = (a,b), X = 0x18, Y = 3;
 *       if c < a and d < b: E = e, F = f; else E = e + g, F = f + h and g = h = 0.
 *    port 3 with 0xA802E3D0 bit 21: g = h = 0, (A,B) = (C,D) = (0x80, 0xA0), X = 0x18, Y = 2, E = F = 0.
 *    G = g + X (clamped at 0, signed), H = h + Y (0 when >= 0x800).
 * 4. P+0x4A = A, +0x52 = B, +0x4E = X, +0x58 = Y, +0x50 = G, +0x56 = H, +0x4C = C, +0x54 = D, +0x5A = E,
 *    +0x5C = F.
 * Row fields read: RAW active row 0xA802E378 only: +0x08 and +0x0A (scaling, port 0 with 0xA802E3D3 set)
 *   and +0x26, +0x28, +0x30, +0x32 (port-0 offsets X/Y in the bit-0/bit-30/bit-26 case). No transformed row, no
 *   row index.
 * Source form: union for 0xA802E3D0; 1-bit bitfield for record +0x40 bit 30; nested 'else if (w4 & 0xF0000000)
 *   { if (port != 0)'; flag materialised then the record pointer assigned before its test; branch-free G/H clamps.
 * Constructs with no effect on behaviour (needed for the firmware's block layout; visible in the -da dumps
 * 12.bp / 31.bbro):
 *   (a) 'else if (w->b >> 16) w0 &= ~bit27; else w0 &= ~bit27;' in the hook-0xA802CC40 else arm: both arms
 *       identical and the test is always false (u16 >> 16); gcc folds it only in 20.combine (nonzero_bits), i.e.
 *       after 12.bp, so the clear block keeps half its frequency (1750 instead of 3500) and bb-reorder starts a new
 *       trace after it, exactly the firmware's layout of the port-0 paths.
 *   (b) '__builtin_expect(q->h54 < rom, 0)': makes the "h54 below the ROM threshold" path unlikely. The signed form
 *       '(int)h54 - rom < 0' gives the same layout but emits bneg.
 *   (c) final stores written as DAT_a802df30[port].field (not through a pointer local): gives the
 *       address-computation order of the firmware.
 */
struct Win
{
  unsigned short a;
  unsigned short b;
  unsigned short c;
  unsigned short d;
  unsigned short e;
  unsigned short f;
  short g;
  unsigned short h;
};
struct Chan
{
  unsigned int w0;
  unsigned char p04[0x3c];
  unsigned int w40_31 : 1;
  unsigned int w40_30 : 1;
  unsigned int w40_rest : 30;
  unsigned char p44[6];
  unsigned short h4a;
  unsigned short h4c;
  unsigned short h4e;
  unsigned short h50;
  unsigned short h52;
  unsigned short h54;
  unsigned short h56;
  unsigned short h58;
  unsigned short h5a;
  unsigned short h5c;
  unsigned char p5e[0x1a];
};
struct RawRow
{
  unsigned int w0;
  unsigned short h4;
  unsigned char b6;
  unsigned char b7;
  unsigned short h08;
  unsigned short h0a;
  unsigned char p0c[0x1a];
  unsigned short h26;
  unsigned short h28;
  unsigned short h2a;
  unsigned short h2c;
  unsigned short h2e;
  unsigned short h30;
  unsigned short h32;
};
union SysFlags
{
  unsigned int w0;
  struct 
  {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned int w4;
  } s;
};
struct Hooks
{
  unsigned char p00[0x24];
  void (*f24)(void);
  void (*f28)(void);
};
extern struct Chan DAT_a802df30[4];
extern struct RawRow DAT_a802e378;
extern union SysFlags DAT_a802e3d0;
extern struct Hooks DAT_a802cc1c;
extern unsigned char DAT_a802e1a7;
extern const unsigned short DAT_001a30da;
void FUN_a013d1b4(unsigned char port, struct Win *w)
{
  unsigned short a6;
  unsigned short c6;
  unsigned short A;
  unsigned short B;
  unsigned short C;
  unsigned short D;
  unsigned short E;
  unsigned short F;
  unsigned short X;
  unsigned short Y;
  unsigned short H;
  short G;
  int flag;
  struct Chan *q;
  if ((port == 0) && (DAT_a802e3d0.s.b3 != 0))
  {
    w->g = (w->g * DAT_a802e378.h0a) / DAT_a802e378.h08;
    w->a = (w->a * DAT_a802e378.h0a) / DAT_a802e378.h08;
    w->e = (w->e * DAT_a802e378.h0a) / DAT_a802e378.h08;
    w->c = (w->c * DAT_a802e378.h0a) / DAT_a802e378.h08;
  }
  else
    if (DAT_a802e3d0.s.w4 & 0xf0000000)
  {
    if (port != 0)
    {
      a6 = (w->a + 0x3f) >> 6;
      c6 = (w->c + 0x3f) >> 6;
      w->a = a6 << 6;
      w->e = (w->e + 0x3f) & 0xffc0;
      w->c = c6 << 6;
      w->g = (w->c - w->a) >> 1;
    }
  }
  DAT_a802df30[port].h54 = w->b;
  if (port == 0)
  {
    if (DAT_a802cc1c.f28 != 0)
    {
      DAT_a802cc1c.f28();
    }
    else
    {
      DAT_a802e3d0.w0 &= ~0x4000000;
    }
    if (DAT_a802cc1c.f24 != 0)
    {
      DAT_a802cc1c.f24();
    }
    else
      if (w->b >> 16)
    {
      DAT_a802e3d0.w0 &= ~0x8000000;
    }
    else
    {
      DAT_a802e3d0.w0 &= ~0x8000000;
    }
    flag = 0;
    if (DAT_a802e1a7 > 4)
    {
      flag = 1;
    }
    q = &DAT_a802df30[port];
    if ((flag != 0) || __builtin_expect(q->h54 < DAT_001a30da, 0))
    {
      if ((w->c >= w->a) || (w->d >= w->b))
      {
        E = w->e + w->g;
        F = w->f + w->h;
        w->g = 0;
        w->h = 0;
        A = w->a;
        B = w->b;
        C = w->a;
        D = w->b;
        X = 0x18;
        Y = 3;
      }
      else
      {
        A = w->a;
        B = w->b;
        C = w->a;
        D = w->b;
        X = 0x18;
        Y = 3;
        E = w->e;
        F = w->f;
      }
    }
    else
      if (((!(q->w0 & 1)) && (!q->w40_30)) && !(DAT_a802e3d0.w0 & 0x4000000))
    {
      A = w->c;
      B = w->d;
      C = w->a;
      D = w->b;
      X = 0x18;
      Y = 3;
      E = w->e;
      F = w->f;
    }
    else
    {
      X = DAT_a802e378.h26 + DAT_a802e378.h28;
      Y = DAT_a802e378.h30 + DAT_a802e378.h32;
      A = w->c;
      B = w->d;
      C = w->a;
      D = w->b;
      E = 0;
      F = 0;
    }
    G = w->g + X;
    H = w->h + Y;
  }
  else
    if ((port == 3) && (DAT_a802e3d0.w0 & 0x200000))
  {
    w->g = 0;
    w->h = 0;
    A = 0x80;
    B = 0xa0;
    C = 0x80;
    D = 0xa0;
    X = 0x18;
    Y = 2;
    E = 0;
    F = 0;
    G = w->g + X;
    H = w->h + Y;
  }
  else
  {
    if ((w->c < w->a) && (w->d < w->b))
    {
      A = w->a;
      B = w->b;
      C = w->a;
      D = w->b;
      X = 0x18;
      Y = 3;
      E = w->e;
      F = w->f;
    }
    else
    {
      E = w->e + w->g;
      F = w->f + w->h;
      w->g = 0;
      w->h = 0;
      A = w->a;
      B = w->b;
      C = w->a;
      D = w->b;
      X = 0x18;
      Y = 3;
    }
    G = w->g + X;
    H = w->h + Y;
  }
  if (G < 0)
  {
    G = 0;
  }
  if (H >= 0x800)
  {
    H = 0;
  }
  DAT_a802df30[port].h4a = A;
  DAT_a802df30[port].h52 = B;
  DAT_a802df30[port].h4e = X;
  DAT_a802df30[port].h58 = Y;
  DAT_a802df30[port].h50 = G;
  DAT_a802df30[port].h56 = H;
  DAT_a802df30[port].h4c = C;
  DAT_a802df30[port].h54 = D;
  DAT_a802df30[port].h5a = E;
  DAT_a802df30[port].h5c = F;
}
