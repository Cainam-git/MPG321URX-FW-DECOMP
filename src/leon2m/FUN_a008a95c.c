/* leon2m FUN_a008a95c @ 0xa008a95c-0xa008abe0 (161 words), flags -mcpu=v8 -O3 -g. Called by FUN_a009e91c.
 * When the byte 0xa802afbd is 0x14: bit 6 of the word 0xa802d290 + 0x1d4 = bit 0 of the byte 0xa802afbe; when that
 * bit is then 0, FUN_a00d8cd4() and byte 0xa802b08e |= 8.
 * Then with v = 0xa802afbd and the 3-byte record {x, y, w} v of the ROM table 0x100242:
 * FUN_a0146a80(x + w, y, n, 0x790, 0) with n = 3 for v 1..12, 0xa for 0x13 and 0x18, 1 for 0x10, 6 for 0xf and 0x14,
 * 4 otherwise; then FUN_a0146a80(x, y, w, 0x90, 0) with the record of the byte 0xa802afbd read again.
 * Source form: an if-chain in the firmware's compare order with one call per arm; the bit is a 1-bit bit-field.
 */
struct pos { unsigned char x, y, w; };
struct Fac290 {
  unsigned char b000[0x1d4];
  union {
    unsigned int w;
    struct { unsigned int hi:25, b6:1, lo:6; } f;
  } u1d4;
};

extern struct pos DAT_00100242[];
extern unsigned char DAT_a802afbd, DAT_a802afbe, DAT_a802b08e;
extern struct Fac290 DAT_a802d290;
extern int FUN_a00d8cd4(void);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);

void FUN_a008a95c(void)
{
  unsigned char v;

  if (DAT_a802afbd == 0x14) {
    DAT_a802d290.u1d4.f.b6 = DAT_a802afbe & 1;
    if (!(DAT_a802d290.u1d4.w & 0x40)) {
      FUN_a00d8cd4();
      DAT_a802b08e |= 8;
    }
  }
  v = DAT_a802afbd;
  if ((unsigned char)(v - 1) < 12)
    FUN_a0146a80(DAT_00100242[v].x + DAT_00100242[v].w, DAT_00100242[v].y, 3, 0x790, 0);
  else if (v == 0x13)
    FUN_a0146a80(DAT_00100242[v].x + DAT_00100242[v].w, DAT_00100242[v].y, 0xa, 0x790, 0);
  else if (v == 0x18)
    FUN_a0146a80(DAT_00100242[v].x + DAT_00100242[v].w, DAT_00100242[v].y, 0xa, 0x790, 0);
  else if (v == 0x10)
    FUN_a0146a80(DAT_00100242[v].x + DAT_00100242[v].w, DAT_00100242[v].y, 1, 0x790, 0);
  else if (v == 0xf)
    FUN_a0146a80(DAT_00100242[v].x + DAT_00100242[v].w, DAT_00100242[v].y, 6, 0x790, 0);
  else if (v == 0x14)
    FUN_a0146a80(DAT_00100242[v].x + DAT_00100242[v].w, DAT_00100242[v].y, 6, 0x790, 0);
  else
    FUN_a0146a80(DAT_00100242[v].x + DAT_00100242[v].w, DAT_00100242[v].y, 4, 0x790, 0);
  FUN_a0146a80(DAT_00100242[DAT_a802afbd].x, DAT_00100242[DAT_a802afbd].y, DAT_00100242[DAT_a802afbd].w, 0x90, 0);
}
