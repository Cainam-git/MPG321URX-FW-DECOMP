/* leon2m FUN_a008e270 @ 0xa008e270-0xa008e520 (172 words), flags -mcpu=v8 -O3 -g. Called by FUN_a009e91c.
 * By the byte 0xa802afbd:
 *  0x12: FUN_a0090fa0(0x111), FUN_a0146dc0(0, 0), FUN_a00dc3dc(), FUN_a0145c5c(n, 0) for n = 0xb, 0xa, 0xd, 0xc, 0x10,
 *        0xe, 0xf, FUN_a0145360(1), byte 0xa802b08e |= 4, FUN_a008d2f8();
 *  0x1c: FUN_a0090fd8(), FUN_a00b50d8(0), byte 0xa802afbb = 0;
 *  other: for 0x14 first byte 0xa802afbe = bit 6 of the word 0xa802d290 + 0x1d4, that bit = 1, byte +0x009 = byte
 *        +0x1d8, FUN_a00d8cd4(), byte 0xa802b08e |= 8. Then FUN_a0146a80(x, y, w, 0x790, 0) with the 3-byte record
 *        {x, y, w} 0xa802afbd of the ROM table 0x100242, and with v = 0xa802afbd read again and its record
 *        FUN_a0146a80(x + w, y, n, 0x90, 0): n = 3 for v 1..12, 5 for 0x11 and 0x14, 0xa for 0x13 and 0x18, 1 for 0x10,
 *        6 for 0xf, 4 otherwise.
 * Source form: an if-chain in the firmware's compare order with one call per arm; the bit is a 1-bit bit-field,
 * written before the byte copy.
 */
struct pos { unsigned char x, y, w; };
struct Fac290 {
  unsigned char b000[9];
  unsigned char b009;
  unsigned char b00a[0x1ca];
  union {
    unsigned int w;
    struct { unsigned int hi:25, b6:1, lo:6; } f;
  } u1d4;
  unsigned char b1d8;
};

extern struct pos DAT_00100242[];
extern unsigned char DAT_a802afbb, DAT_a802afbd, DAT_a802afbe, DAT_a802b08e;
extern struct Fac290 DAT_a802d290;
extern int FUN_a00d8cd4(void);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0090fa0(int);
extern void FUN_a0146dc0(int, int);
extern void FUN_a00dc3dc(void);
extern void FUN_a0145c5c(int, int);
extern void FUN_a0145360(int);
extern void FUN_a008d2f8(void);
extern void FUN_a0090fd8(void);
extern void FUN_a00b50d8(unsigned int);

void FUN_a008e270(void)
{
  unsigned char v;

  if (DAT_a802afbd == 0x12) {
    FUN_a0090fa0(0x111);
    FUN_a0146dc0(0, 0);
    FUN_a00dc3dc();
    FUN_a0145c5c(0xb, 0);
    FUN_a0145c5c(0xa, 0);
    FUN_a0145c5c(0xd, 0);
    FUN_a0145c5c(0xc, 0);
    FUN_a0145c5c(0x10, 0);
    FUN_a0145c5c(0xe, 0);
    FUN_a0145c5c(0xf, 0);
    FUN_a0145360(1);
    DAT_a802b08e |= 4;
    FUN_a008d2f8();
  } else if (DAT_a802afbd == 0x1c) {
    FUN_a0090fd8();
    FUN_a00b50d8(0);
    DAT_a802afbb = 0;
  } else {
    if (DAT_a802afbd == 0x14) {
      DAT_a802afbe = DAT_a802d290.u1d4.f.b6;
      DAT_a802d290.u1d4.f.b6 = 1;
      DAT_a802d290.b009 = DAT_a802d290.b1d8;

      FUN_a00d8cd4();
      DAT_a802b08e |= 8;
    }
    FUN_a0146a80(DAT_00100242[DAT_a802afbd].x, DAT_00100242[DAT_a802afbd].y, DAT_00100242[DAT_a802afbd].w, 0x790, 0);
    v = DAT_a802afbd;
    if ((unsigned char)(v - 1) < 12)
      FUN_a0146a80(DAT_00100242[v].x + DAT_00100242[v].w, DAT_00100242[v].y, 3, 0x90, 0);
    else if (v == 0x11)
      FUN_a0146a80(DAT_00100242[v].x + DAT_00100242[v].w, DAT_00100242[v].y, 5, 0x90, 0);
    else if (v == 0x13)
      FUN_a0146a80(DAT_00100242[v].x + DAT_00100242[v].w, DAT_00100242[v].y, 0xa, 0x90, 0);
    else if (v == 0x18)
      FUN_a0146a80(DAT_00100242[v].x + DAT_00100242[v].w, DAT_00100242[v].y, 0xa, 0x90, 0);
    else if (v == 0x10)
      FUN_a0146a80(DAT_00100242[v].x + DAT_00100242[v].w, DAT_00100242[v].y, 1, 0x90, 0);
    else if (v == 0xf)
      FUN_a0146a80(DAT_00100242[v].x + DAT_00100242[v].w, DAT_00100242[v].y, 6, 0x90, 0);
    else if (v == 0x14)
      FUN_a0146a80(DAT_00100242[v].x + DAT_00100242[v].w, DAT_00100242[v].y, 5, 0x90, 0);
    else
      FUN_a0146a80(DAT_00100242[v].x + DAT_00100242[v].w, DAT_00100242[v].y, 4, 0x90, 0);
  }
}
