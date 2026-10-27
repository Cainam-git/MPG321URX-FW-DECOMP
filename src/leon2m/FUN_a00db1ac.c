/* leon2m FUN_a00db1ac @ 0xa00db1ac-0xa00db678 (307 words), flags -mcpu=v8 -O3 -g. Called by FUN_a009f42c.
 * A sequence of tests of the value v returned by FUN_a0090fcc() (called again for every test), with
 * T = the record DAT_a802d290:
 *  - v == 0x3f: byte 0xa802d420 = 0. v == 0x42: halfword T+0x1ac = 0x750, halfword T+0x1ae = 0x402.
 *  - 0x6f < v <= 0x76: byte T+0x1a4 = v - 0x70, FUN_a0096858().
 *  - 0x76 < v <= 0x79 and byte 0xa8025c56 differs from bits 18..19 of word T+0xac: FUN_a00db054() and bit 2 of
 *    byte 0xa802b08e set.
 *  - 0x22 < v <= 0x25 or v == 0xff: FUN_a00972cc() when v is 0xff, else FUN_a0097508() and FUN_a00976f8().
 *  - 0x7e < v <= 0x81: FUN_a0097d3c(). v == 0x84 or 0x7d: the steps of FUN_a00d934c. v == 0x85 or 0x7e:
 *    FUN_a00d93c8(). v == 0x109: FUN_a00a10c8(). v == 0x46 or 0x47: FUN_a0099658().
 *  - 0xba < v <= 0xbf: bit 15 of word T+0x1dc cleared for v == 0xbb, set for v == 0xbc; then FUN_a0126f4c().
 *  - 0xc2 < v <= 0xc4: FUN_a009a0d4() (tail call).
 * Source form: the same-file function FUN_a00d934c is defined here as a static copy and inlined; the halfword
 * +0x1ac is written before +0x1ae.
 */
struct R290 {
    unsigned char pad[0x1e];
    unsigned char b1e;
    unsigned char pad1;
    unsigned char b20;
    unsigned char pad2[0xa8 - 0x21];
    unsigned int wa8;
    unsigned int wac;
    unsigned char padb0[0x1a4 - 0xb0];
    unsigned char b1a4;
    unsigned char pad1a5[0x1ac - 0x1a5];
    unsigned short h1ac;
    unsigned short h1ae;
    unsigned char pad1b0[0x1dc - 0x1b0];
    unsigned int w1dc;
};
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802d420;
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern unsigned short FUN_a0090fcc(void);
extern void FUN_a0096858(void);
extern void FUN_a00db054(void);
extern void FUN_a00972cc(void);
extern void FUN_a0097508(void);
extern void FUN_a00976f8(void);
extern void FUN_a0097d3c(void);
extern void FUN_a00d5cd8(void);
extern void FUN_a00d9238(void);
extern void FUN_a01479ec(unsigned char);
extern void FUN_a0149978(int, unsigned char);
extern void FUN_a00d93c8(void);
extern void FUN_a00a10c8(void);
extern void FUN_a0099658(void);
extern void FUN_a0126f4c(void);
extern void FUN_a009a0d4(void);

static void FUN_a00d934c(void)
{
  struct R290 *p = &DAT_a802d290;
  unsigned char old = p->b1e;
  unsigned char cur = p->b20;

  p->wac |= 0x20000;
  p->b1e = cur;
  p->b20 = old;
  if (cur == old)
    return;
  FUN_a00d9238();
  if (p->wa8 & 0x4000)
    FUN_a01479ec(1);
  FUN_a0149978(1, p->b20);
  FUN_a00d5cd8();
}

void FUN_a00db1ac(void)
{
    if (FUN_a0090fcc() == 0x3f)
        DAT_a802d420 = 0;
    if (FUN_a0090fcc() == 0x42) {
        DAT_a802d290.h1ac = 0x750;
        DAT_a802d290.h1ae = 0x402;
    }
    if (FUN_a0090fcc() > 0x6f && FUN_a0090fcc() <= 0x76) {
        DAT_a802d290.b1a4 = FUN_a0090fcc() - 0x70;
        FUN_a0096858();
    }
    if (FUN_a0090fcc() > 0x76 && FUN_a0090fcc() <= 0x79 && DAT_a8025c56 != ((DAT_a802d290.wac >> 18) & 3)) {
        FUN_a00db054();
        DAT_a802b08e |= 4;
    }
    if ((FUN_a0090fcc() > 0x22 && FUN_a0090fcc() <= 0x25) || FUN_a0090fcc() == 0xff) {
        if (FUN_a0090fcc() == 0xff)
            FUN_a00972cc();
        else {
            FUN_a0097508();
            FUN_a00976f8();
        }
    }
    if (FUN_a0090fcc() > 0x7e && FUN_a0090fcc() <= 0x81)
        FUN_a0097d3c();
    if (FUN_a0090fcc() == 0x84 || FUN_a0090fcc() == 0x7d)
        FUN_a00d934c();
    if (FUN_a0090fcc() == 0x85 || FUN_a0090fcc() == 0x7e)
        FUN_a00d93c8();
    if (FUN_a0090fcc() == 0x109)
        FUN_a00a10c8();
    if (FUN_a0090fcc() == 0x46 || FUN_a0090fcc() == 0x47)
        FUN_a0099658();
    if (FUN_a0090fcc() > 0xba && FUN_a0090fcc() <= 0xbf) {
        if (FUN_a0090fcc() == 0xbb)
            DAT_a802d290.w1dc &= ~0x8000;
        else if (FUN_a0090fcc() == 0xbc)
            DAT_a802d290.w1dc |= 0x8000;
        FUN_a0126f4c();
    }
    if (FUN_a0090fcc() > 0xc2 && FUN_a0090fcc() <= 0xc4)
        FUN_a009a0d4();
}
