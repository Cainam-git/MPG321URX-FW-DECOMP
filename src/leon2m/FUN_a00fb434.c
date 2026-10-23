/* leon2m FUN_a00fb434 @ 0xa00fb434-0xa00fb9ec (366 words), flags -mcpu=v8 -O3 -g.
 * Callers: FUN_a00fb9ec, FUN_a00fbaf8, FUN_a00fbc80, FUN_a00fbdcc, FUN_a00fc044.
 * FUN_a00fb434(id, p, w, h) reads v = *p and acts on the registers from 0xd0040000 on; it returns 1.
 *   id 0: byte 0xa802b7fd = v (a register offset); id 1: *p = register 0xd0040000 + that offset;
 *   id 2: register 0xd0040000 + offset = v; id 4: halfword 0xa802d67a = v limited to 0x2d0..0x2000;
 *   id 5: halfword 0xa802d678 = v limited to 0x1e0..0x10e0; id 7, 9..17: v is written into one bit range of
 *   one register (0x98 bits 16..19, 0x00 bit 31, 0x0c bits 8..12, 0xe4 bits 24..31, 0x110/0x140/0x138 bit 31,
 *   0x130/0x160 bits 16..23, 0x138 bits 16..24); id 8 and ids above 17: nothing.
 *   id 3: fixed values are written to 27 registers, then 0xa802d67a = w limited to 0x2d0..0x1400 and
 *   0xa802d678 = h limited to 0x1e0..0xb40.
 *   id 6: the same two limited stores, then with H = 0xa802d678 and W = 0xa802d67a: register 0x00 bits 0..12 = H,
 *   bits 16..28 = W; hc = H / 12 and wc = W / 24, each rounded up; register 0x04 bits 0..8 = 0x18c (in four
 *   constant ranges), bits 10..18 = hc, bits 20..28 = wc; a = (((wc >> 1) - 1) >> 1) << 1; register 0xc4 bits
 *   0..3 = a >> 3, bits 4..11 = 0, bits 16..23 = a, bits 24..31 = (hc >> 1) - 1.
 * Source form: ids 1, 2, 3 and 6 set a mode byte inside the switch and act after it (if-chain on the mode).
 * Bit ranges are written by the inlined helpers fset/rset, which take the highest and lowest bit number and
 * build the mask as (1 << hi) | ((1 << hi) - (1 << lo)); the mask is formed at RTL level, which keeps it in a
 * register for both the and and the andn, keeps the 'and 0x80000000' after 'sll 31' and builds 0x1f00 as
 * sethi 0x1000 + or 0xf00. The limits are written as ?: expressions on the globals.
 */
extern unsigned short DAT_a802d67a;
extern unsigned short DAT_a802d678;
#define R(a) (*(volatile unsigned int *)(a))
static unsigned int fset(unsigned int x, unsigned int hi, unsigned int lo, unsigned int v)
{
    unsigned int m = (1 << hi) | ((1 << hi) - (1 << lo));

    return (x & ~m) | ((v << lo) & m);
}

static void rset(unsigned int a, unsigned int hi, unsigned int lo, unsigned int v)
{
    R(a) = fset(R(a), hi, lo, v);
}

extern unsigned char DAT_a802b7fd;

int FUN_a00fb434(unsigned int id, unsigned int *p, unsigned int w, unsigned int h)
{
    unsigned char mode = 0;
    unsigned int v = *p;

    switch (id) {
    case 0:
        DAT_a802b7fd = v;
        break;
    case 1:
        mode = 1;
        break;
    case 2:
        mode = 2;
        break;
    case 3:
        mode = 3;
        break;
    case 4:
        DAT_a802d67a = v < 0x2d0 ? 0x2d0 : (v > 0x2000 ? 0x2000 : v);
        break;
    case 5:
        DAT_a802d678 = v < 0x1e0 ? 0x1e0 : (v > 0x10e0 ? 0x10e0 : v);
        break;
    case 6:
        mode = 4;
        break;
    case 7:
        rset(0xd0040098, 19, 16, v);
        break;
    case 8:
        break;
    case 9:
        rset(0xd0040000, 31, 31, v);
        break;
    case 10:
        rset(0xd004000c, 12, 8, v);
        break;
    case 11:
        rset(0xd00400e4, 31, 24, v);
        break;
    case 12:
        rset(0xd0040110, 31, 31, v);
        break;
    case 13:
        rset(0xd0040140, 31, 31, v);
        break;
    case 14:
        rset(0xd0040138, 31, 31, v);
        break;
    case 15:
        rset(0xd0040130, 23, 16, v);
        break;
    case 16:
        rset(0xd0040160, 23, 16, v);
        break;
    case 17:
        rset(0xd0040138, 24, 16, v);
        break;
    }
    if (mode == 1) {
        *p = R(0xd0040000 + DAT_a802b7fd);
    } else if (mode == 2) {
        R(0xd0040000 + DAT_a802b7fd) = v;
    } else if (mode == 3) {
        R(0xd0040000) = 0x7802438;
        R(0xd0040004) = 0x501698c;
        R(0xd0040008) = 0x80000000;
        R(0xd0040008) = (R(0xd0040008) & ~3) | 2;
        R(0xd0040208) = (R(0xd0040208) & ~3) | 1;
        R(0xd004000c) = 0;
        R(0xd0040020) = 0xc2800100;
        R(0xd0040024) = 0;
        R(0xd0040028) = 0x2000200;
        R(0xd004002c) = 0x10200;
        R(0xd0040030) = 0x2fff04b0;
        R(0xd0040034) = 0x808d63;
        R(0xd00400c0) = 0x80000000;
        R(0xd00400c4) = 0x2c260000;
        R(0xd0040080) = 0x80112830;
        R(0xd0040090) = 0x8102080;
        R(0xd0040098) = 0xf0101010;
        R(0xd0040094) = 0x400717e0;
        R(0xd004009c) = 0x50506000;
        R(0xd00400ac) = 0x73c00380;
        R(0xd00400d4) = 0x3f00004;
        R(0xd00400d8) = 0x1110113;
        R(0xd00400e0) = 0x4b321900;
        R(0xd00400e4) = 0x80808064;
        R(0xd00400e8) = 0xff010064;
        R(0xd00400f0) = 0xfffff0f0;
        R(0xd00400f4) = 0x20000000;
        R(0xd00400f8) = 0xc0fec0;
        DAT_a802d67a = w;
        DAT_a802d678 = h;
        DAT_a802d67a = DAT_a802d67a < 0x2d0 ? 0x2d0 : (DAT_a802d67a > 0x1400 ? 0x1400 : DAT_a802d67a);
        DAT_a802d678 = DAT_a802d678 < 0x1e0 ? 0x1e0 : (DAT_a802d678 > 0xb40 ? 0xb40 : DAT_a802d678);
    } else if (mode == 4) {
        unsigned int x, hc, wc, a, b;
        unsigned short hh, ww;

        DAT_a802d678 = h;
        DAT_a802d67a = w;
        DAT_a802d67a = DAT_a802d67a < 0x2d0 ? 0x2d0 : (DAT_a802d67a > 0x1400 ? 0x1400 : DAT_a802d67a);
        DAT_a802d678 = DAT_a802d678 < 0x1e0 ? 0x1e0 : (DAT_a802d678 > 0xb40 ? 0xb40 : DAT_a802d678);
        hh = DAT_a802d678;
        x = R(0xd0040000);
        x = fset(x, 12, 0, hh);
        ww = DAT_a802d67a;
        x = fset(x, 28, 16, ww);
        R(0xd0040000) = x;
        hc = hh / 12 + (hh % 12 != 0);
        wc = ww / 24 + (ww % 24 != 0);
        x = R(0xd0040004);
        x = fset(x, 1, 0, 0);
        x = fset(x, 3, 2, 3);
        x = fset(x, 6, 4, 0);
        x = fset(x, 8, 7, 3);
        x = fset(x, 18, 10, hc);
        x = fset(x, 28, 20, wc);
        R(0xd0040004) = x;
        a = (((wc >> 1) - 1) >> 1) << 1;
        b = (hc >> 1) - 1;
        x = R(0xd00400c4);
        x = fset(x, 3, 0, a >> 3);
        x = fset(x, 11, 4, 0);
        x = fset(x, 23, 16, a);
        x = fset(x, 31, 24, b);
        R(0xd00400c4) = x;
    }
    return 1;
}
