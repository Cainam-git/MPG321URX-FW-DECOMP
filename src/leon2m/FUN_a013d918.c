/* leon2m FUN_a013d918 @ 0xa013d918-0xa013dbcc (692 bytes)  channel window set-up (panel-row reader).
 * -mcpu=v8 -O3 -g (jf 100 match, rawcmp 173/0). No compiler aids.
 *
 * void(u8 ch): c = channel record 0xA802DF30[ch] (0x78 bytes). blk = word0 bits 12-15 (the 0xff test is dead
 * code kept by the compiler). Channel 0 with word0 bit 0, +0x40 bit 30 or 0xA802E3D0 bit 26 takes h/m from the
 * active panel row copy 0xA802E378 (+0x26 / +0x30); otherwise h = 0x10, m = 2 (m = 1 for channel 3 when
 * 0xA802E3D0 bit 21). FUN_a0105910 / FUN_a0105a3c program the window from +0x4A..+0x58; unless word0 bits 4-7
 * == 4 it switches bank (FUN_a00f6cf4 / FUN_a00f63bc), computes the crop offsets dx/dy and calls FUN_a00f6d00
 * (channel 0 + bit 0: row +0x26/+0x28/+0x30/+0x32 margins; channel 0 + 0xA802E3D3: full row +0x08 x +0x0A).
 * Channel 3: FUN_a0106d3c(blk, 0x3f, 0xff) or (blk, 0x30, 0xc0) by 0xA802E3D0 bit 21.
 * PANEL ROW FIELDS READ: active row copy 0xA802E378 +0x08, +0x0A, +0x26, +0x28, +0x30, +0x32.
 * Code facts: h, dx, dy are unsigned short (16-bit call arguments; with int the firmware's zero-extension and
 *   add operand order are lost); word0 read through c; one combined 'ch == 0 && (...)' test; the ch == 3 test
 *   as 'if (ch == 3 && bit) m = 1; else m = 2;' (laid out of line by bb-reorder); dx/dy cleared first.
 */

struct Chan
{
  unsigned int w0;
  unsigned char p04[0x3c];
  unsigned int w40;
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
  unsigned char rest[0x1a];
};
struct RawRow
{
  unsigned char p00[8];
  unsigned short h08;
  unsigned short h0a;
  unsigned char p0c[0x1a];
  unsigned short h26;
  unsigned short h28;
  unsigned char p2a[6];
  unsigned short h30;
  unsigned short h32;
};
extern struct Chan DAT_a802df30[4];
extern struct RawRow DAT_a802e378;
extern unsigned int DAT_a802e3d0;
extern unsigned char DAT_a802e3d3;
extern void FUN_a0105910(unsigned int, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);
extern void FUN_a0105a3c(unsigned int, unsigned short, unsigned short, unsigned short, unsigned short);
extern unsigned char FUN_a00f6cf4(void);
extern void FUN_a00f63bc(unsigned char);
extern void FUN_a00f6d00(unsigned short, unsigned short, unsigned short, unsigned short);
extern void FUN_a0106d3c(unsigned char, unsigned char, unsigned char);
extern void FUN_a0106d3c(unsigned char, unsigned char, unsigned char);
void FUN_a013d918(unsigned char ch)
{
    struct Chan *c;
    unsigned int blk;
    unsigned int w0;
    unsigned short h;
    unsigned int m;
    unsigned char bank;
    unsigned short dx;
    unsigned short dy;

    dx = 0;
    dy = 0;
    c = &DAT_a802df30[ch];
    w0 = c->w0;
    blk = (w0 >> 12) & 0xf;
    if (blk == 0xff)
        return;
    if (ch == 0 && ((w0 & 1) || (c->w40 & 0x40000000) || (DAT_a802e3d0 & 0x4000000))) {
        h = DAT_a802e378.h26;
        m = DAT_a802e378.h30;
    } else {
        h = 0x10;
        if (ch == 3 && (DAT_a802e3d0 & 0x200000))
            m = 1;
        else
            m = 2;
    }
    FUN_a0105910(blk, DAT_a802df30[ch].h4a, DAT_a802df30[ch].h52, DAT_a802df30[ch].h4e, DAT_a802df30[ch].h58, h, m);
    FUN_a0105a3c(blk, DAT_a802df30[ch].h4c, DAT_a802df30[ch].h54, DAT_a802df30[ch].h50, DAT_a802df30[ch].h56);
    if ((c->w0 & 0xf0) != 0x40) {
        bank = FUN_a00f6cf4();
        FUN_a00f63bc((c->w0 >> 4) & 0xf);
        if (DAT_a802df30[ch].h4c < DAT_a802df30[ch].h4a)
            dx = DAT_a802df30[ch].h50 - DAT_a802df30[ch].h4e;
        if (DAT_a802df30[ch].h54 < DAT_a802df30[ch].h52)
            dy = DAT_a802df30[ch].h56 - DAT_a802df30[ch].h58;
        if (ch == 0 && (c->w0 & 1))
            FUN_a00f6d00(DAT_a802df30[0].h50 - (DAT_a802e378.h26 + DAT_a802e378.h28),
                         DAT_a802df30[0].h56 - (DAT_a802e378.h30 + DAT_a802e378.h32),
                         DAT_a802df30[0].h4c, DAT_a802df30[0].h54);
        else if (ch == 0 && DAT_a802e3d3)
            FUN_a00f6d00(0, 0, DAT_a802e378.h08, DAT_a802e378.h0a);
        else
            FUN_a00f6d00(DAT_a802df30[ch].h5a + dx, DAT_a802df30[ch].h5c + dy, DAT_a802df30[ch].h4c, DAT_a802df30[ch].h54);
        FUN_a00f63bc(bank);
    }
    if (ch == 3) {
        if (DAT_a802e3d0 & 0x200000)
            FUN_a0106d3c((DAT_a802df30[3].w0 >> 12) & 0xf, 0x3f, 0xff);
        else
            FUN_a0106d3c((DAT_a802df30[3].w0 >> 12) & 0xf, 0x30, 0xc0);
    }
}
