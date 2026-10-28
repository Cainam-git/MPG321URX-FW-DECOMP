/* leon2m FUN_a008767c @ 0xa008767c-0xa008796c.
 * f = FUN_a0145660(0, 1) / 10 (unsigned short). When FUN_a0143c14(0) > 8, mode becomes 2 if (unsigned short)
 * (f - 84) <= 0xc3, 3 if bit 7 of word DAT_a802d290 + 0xa8 is set, and 0 if FUN_a00d7d48() returns non-zero;
 * otherwise mode is 0. After FUN_a0124a40(), word +0xb0 above 3 is cleared and selects 0. A non-zero parameter a
 * selects 0; otherwise a non-zero selection is replaced by word +0xb0, where the value 1 becomes 3 or 2 by bit 7
 * of word +0xa8. Then FUN_a014bac4 is called with (0xc, 0x134), (0x11, 0x61a8), (0x10, 0xe1), (0xe, 0x55),
 * (0, 0x10), (1, 0x10), (0x12, 0x19), (0xf, 0).
 * Selection 2: FUN_a014bac4(1, 0); f = DAT_a802e3ca / 10 if FUN_a014d504() is non-zero; FUN_a014bac4 with
 * (3, f - 2), (0xc, 0x3ff), (2, 0xb2); FUN_a00874c8(0x10, 0x10); FUN_a0125e00(); FUN_a014bc58(1).
 * Selection 3: a 13-byte local record {0x10, 0x14, 0x2d, 0x10, 0x19, -, 0xfa (u16), 0xa, -, f (u16), 0x80} is
 * passed to FUN_a01502c4, then FUN_a0125e00(); FUN_a014bc58(2).
 * Both continue with FUN_a014913c(FUN_a00d493c(5)), FUN_a0150768(1, 0xff), FUN_a014dbf4(1), FUN_a01438c8(1).
 * Other selections: FUN_a0125e1c(), FUN_a014bce4(0), FUN_a00d8cd4(), func_0x4008d1a0(50), FUN_a01438c8(0),
 * FUN_a0150768(1, 0xff), FUN_a014bac4(2, 0x3ff), FUN_a014913c(FUN_a00d493c(byte DAT_a802d290 + 0x19)),
 * FUN_a014bc58(0), FUN_a014dbf4(0). Every path ends with FUN_a00d8cd4().
 * Source form: mode is an int that is set to 0 by the FUN_a00d7d48 test and then copied into sel, which is copied
 * into the selection r; the same variable mode later holds word +0xb0 and the value-1 case is an if/else that
 * assigns r in both arms.
 */
struct Fac290 {
  unsigned char b000[0x19];
  unsigned char b019;
  unsigned char b01a[0x8e];
  unsigned int w0a8;
  unsigned int w0ac;
  unsigned int w0b0;
};
struct Par {
  unsigned char b0, b1, b2, b3, b4, b5;
  unsigned short h6;
  unsigned char b8, b9;
  unsigned short ha;
  unsigned char bc;
};

extern struct Fac290 DAT_a802d290;
extern unsigned short DAT_a802e3ca;
extern unsigned short FUN_a0145660(unsigned char, unsigned int);
extern unsigned char FUN_a0143c14(unsigned char);
extern int FUN_a00d7d48(void);
extern int FUN_a0124a40(void);
extern void FUN_a014bac4(unsigned int, unsigned short);
extern void FUN_a0125e1c(void);
extern void FUN_a014bce4(unsigned int);
extern void FUN_a00d8cd4(void);
extern void func_0x4008d1a0(int ms);
extern void FUN_a01438c8(unsigned char);
extern void FUN_a0150768(unsigned char, unsigned char);
extern unsigned char FUN_a00d493c(unsigned char);
extern void FUN_a014913c(unsigned char);
extern void FUN_a014bc58(unsigned int);
extern void FUN_a014dbf4(unsigned char);
extern unsigned char FUN_a014d504(void);
extern void FUN_a00874c8(unsigned char, unsigned char);
extern void FUN_a0125e00(void);
extern void FUN_a01502c4(struct Par *);

void FUN_a008767c(unsigned char a)
{
  unsigned short f;
  int mode;
  unsigned int r, sel;
  unsigned char c;
  struct Par p;

  f = FUN_a0145660(0, 1) / 10;
  c = FUN_a0143c14(0);
  mode = 0;
  sel = 0;
  if (c > 8) {
    if ((unsigned short)(f - 84) <= 0xc3)
      mode = 2;
    if (DAT_a802d290.w0a8 & 0x80)
      mode = 3;
    if (FUN_a00d7d48())
      mode = 0;
    sel = mode;
  }
  r = sel;
  FUN_a0124a40();
  if (DAT_a802d290.w0b0 > 3) {
    DAT_a802d290.w0b0 = 0;
    r = 0;
  }
  if (a) {
    r = 0;
  } else if (r != 0) {
    mode = DAT_a802d290.w0b0;
    if (mode == 1) {
      if (DAT_a802d290.w0a8 & 0x80)
        r = 3;
      else
        r = 2;
    } else
      r = mode;
  }
  FUN_a014bac4(0xc, 0x134);
  FUN_a014bac4(0x11, 0x61a8);
  FUN_a014bac4(0x10, 0xe1);
  FUN_a014bac4(0xe, 0x55);
  FUN_a014bac4(0, 0x10);
  FUN_a014bac4(1, 0x10);
  FUN_a014bac4(0x12, 0x19);
  FUN_a014bac4(0xf, 0);
  if (r == 2) {
    FUN_a014bac4(1, 0);
    if (FUN_a014d504())
      f = DAT_a802e3ca / 10;
    FUN_a014bac4(3, f - 2);
    FUN_a014bac4(0xc, 0x3ff);
    FUN_a014bac4(2, 0xb2);
    FUN_a00874c8(0x10, 0x10);
    FUN_a0125e00();
    FUN_a014bc58(1);
    FUN_a014913c(FUN_a00d493c(5));
    FUN_a0150768(1, 0xff);
    FUN_a014dbf4(1);
    FUN_a01438c8(1);
  } else if (r == 3) {
    p.b0 = 0x10;
    p.b1 = 0x14;
    p.b2 = 0x2d;
    p.b3 = 0x10;
    p.b4 = 0x19;
    p.h6 = 0xfa;
    p.b8 = 0xa;
    p.ha = f;
    p.bc = 0x80;
    FUN_a01502c4(&p);
    FUN_a0125e00();
    FUN_a014bc58(2);
    FUN_a014913c(FUN_a00d493c(5));
    FUN_a0150768(1, 0xff);
    FUN_a014dbf4(1);
    FUN_a01438c8(1);
  } else {
    FUN_a0125e1c();
    FUN_a014bce4(0);
    FUN_a00d8cd4();
    func_0x4008d1a0(50);
    FUN_a01438c8(0);
    FUN_a0150768(1, 0xff);
    FUN_a014bac4(2, 0x3ff);
    FUN_a014913c(FUN_a00d493c(DAT_a802d290.b019));
    FUN_a014bc58(0);
    FUN_a014dbf4(0);
  }
  FUN_a00d8cd4();
}
