/*
 * FUN_a00c8c64 (leon2s, 0xa00c8c64-0xa00c90b4, 1104 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Works on the 24-byte record DAT_a8078bb0[port] (word 0 bit-fields as in FUN_a00c91f8:
 * f28 = bit 28, f23 = bit 23, st = bits 16..17; bytes +3..+6 plain members). Sets st = 1; sel = 1 when
 * byte +1 of the 28-byte record ARR_a807d580[port] is 0x41 or 0x61, else 0.
 * - FUN_a00c0a04(port) != 0: st = 3, return. f23 = 0. FUN_a00c8360(port, &s) != 0, bit 5 of s clear, or
 *   FUN_a00c82dc(port, h) != 0: st = 3, return.
 * - Bit 7 of h[0]: b5 = 1, st = 2, return. Bit 3 of h[1]: b6 = 1, st = 2, return.
 * - n = h[0] & 0x7f; b3 = n, b4 = h[1] & 7, b5 = h[0] >> 7, b6 = bit 3 of h[1]. FUN_a00c7bf8(port) != 0:
 *   st = 3, return.
 * - FUN_a00c8824(port, sel, n * 5); n == 0 prints s_9f1c2088 and clears f28. Writes h[0], h[1] to
 *   registers 0x200/0x201 and the 8 bytes from FUN_a00c85e4(port, buf, 1) to 0x202..0x209 with
 *   func_0xa0fb65c4(sel, reg, v); 0 to 0x33 and 0x34, m = n * 5 to 0x35 (low byte) and 0x36 (high byte);
 *   func_0xa0fb67b8(sel, 0x37, 4, 1), (sel, 0x37, 1, 0), func_0xa0fc1794(10), (sel, 0x37, 1, 1); waits
 *   until bit 0 of func_0xa0fb657c(sel, 0x37) is set; then reads registers 0x20d..0x20a, 0x211..0x20e,
 *   0x215..0x212, 0x219..0x216, 0x21d..0x21a into DAT_a807d238[0..19].
 * Source forms: the sel switch has a case below 0x41 with the default action (0x31 here; any of 0x30..0x39
 * gives the same code): the compiler drops its compare, but it makes 0x41 the root of the compare tree as in
 * the firmware; the 0x51 case sets sel = 0. n is assigned before the record stores and b3 = n; m is an
 * unsigned short computed before the 0x33 write; the failure exits each have their own 'st = 3; return;'
 * (merged by the compiler). buf is 24 bytes (firmware frame layout: buf at %fp-32, h at -40, s at -41);
 * FUN_a00c85e4 fills the first 8.
 */
struct Rec24 {
    unsigned int a : 3;
    unsigned int f28 : 1;
    unsigned int cnt : 4;
    unsigned int f23 : 1;
    unsigned int mid : 5;
    unsigned int st : 2;
    unsigned int x : 8;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char pad[17];
};
struct Rec28 { unsigned char b0; unsigned char b1; unsigned char pad[26]; };
extern struct Rec24 DAT_a8078bb0[];
extern struct Rec28 ARR_a807d580[];
extern unsigned char DAT_a807d238[];
extern const char s_9f1c2088[];
extern unsigned char FUN_a00c0a04(unsigned char);
extern unsigned char FUN_a00c8360(unsigned char, unsigned char *);
extern unsigned char FUN_a00c82dc(unsigned char, unsigned char *);
extern unsigned char FUN_a00c7bf8(unsigned char);
extern void FUN_a00c8824(unsigned char, unsigned char, unsigned short);
extern void FUN_a00c85e4(unsigned char, unsigned char *, unsigned char);
extern int func_0xa0f83044(const char *, ...);
extern void func_0xa0fb65c4(unsigned char, unsigned short, unsigned char);
extern void func_0xa0fb67b8(unsigned char, unsigned short, unsigned int, unsigned char);
extern unsigned int func_0xa0fb657c(unsigned char, unsigned short);
extern void func_0xa0fc1794(unsigned int);

void FUN_a00c8c64(unsigned char port)
{
    unsigned char buf[24];
    unsigned char h[2];
    unsigned char s;
    unsigned char sel;
    unsigned char n;
    unsigned char i;
    unsigned short m;

    sel = 0;
    DAT_a8078bb0[port].st = 1;
    switch (ARR_a807d580[port].b1) {
    case 0x31:
        sel = 0;
        break;
    case 0x41:
        sel = 1;
        break;
    case 0x51:
        sel = 0;
        break;
    case 0x61:
        sel = 1;
        break;
    }
    if (FUN_a00c0a04(port)) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    DAT_a8078bb0[port].f23 = 0;
    if (FUN_a00c8360(port, &s)) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    if ((s & 0x20) == 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    if (FUN_a00c82dc(port, h)) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    if (h[0] & 0x80) {
        DAT_a8078bb0[port].b5 = 1;
        DAT_a8078bb0[port].st = 2;
        return;
    }
    if (h[1] & 8) {
        DAT_a8078bb0[port].b6 = 1;
        DAT_a8078bb0[port].st = 2;
        return;
    }
    n = h[0] & 0x7f;
    DAT_a8078bb0[port].b3 = n;
    DAT_a8078bb0[port].b4 = h[1] & 7;
    DAT_a8078bb0[port].b5 = h[0] >> 7;
    DAT_a8078bb0[port].b6 = (h[1] >> 3) & 1;
    if (FUN_a00c7bf8(port)) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    FUN_a00c8824(port, sel, n * 5);
    if (n == 0) {
        func_0xa0f83044(s_9f1c2088);
        DAT_a8078bb0[port].f28 = 0;
    }
    func_0xa0fb65c4(sel, 0x200, h[0]);
    func_0xa0fb65c4(sel, 0x201, h[1]);
    FUN_a00c85e4(port, buf, 1);
    for (i = 0; i < 8; i++)
        func_0xa0fb65c4(sel, i + 0x202, buf[i]);
    m = n * 5;
    func_0xa0fb65c4(sel, 0x33, 0);
    func_0xa0fb65c4(sel, 0x34, 0);
    func_0xa0fb65c4(sel, 0x35, m & 0xff);
    func_0xa0fb65c4(sel, 0x36, m >> 8);
    func_0xa0fb67b8(sel, 0x37, 4, 1);
    func_0xa0fb67b8(sel, 0x37, 1, 0);
    func_0xa0fc1794(10);
    func_0xa0fb67b8(sel, 0x37, 1, 1);
    while ((func_0xa0fb657c(sel, 0x37) & 1) == 0)
        ;
    DAT_a807d238[0] = func_0xa0fb657c(sel, 0x20d);
    DAT_a807d238[1] = func_0xa0fb657c(sel, 0x20c);
    DAT_a807d238[2] = func_0xa0fb657c(sel, 0x20b);
    DAT_a807d238[3] = func_0xa0fb657c(sel, 0x20a);
    DAT_a807d238[4] = func_0xa0fb657c(sel, 0x211);
    DAT_a807d238[5] = func_0xa0fb657c(sel, 0x210);
    DAT_a807d238[6] = func_0xa0fb657c(sel, 0x20f);
    DAT_a807d238[7] = func_0xa0fb657c(sel, 0x20e);
    DAT_a807d238[8] = func_0xa0fb657c(sel, 0x215);
    DAT_a807d238[9] = func_0xa0fb657c(sel, 0x214);
    DAT_a807d238[10] = func_0xa0fb657c(sel, 0x213);
    DAT_a807d238[11] = func_0xa0fb657c(sel, 0x212);
    DAT_a807d238[12] = func_0xa0fb657c(sel, 0x219);
    DAT_a807d238[13] = func_0xa0fb657c(sel, 0x218);
    DAT_a807d238[14] = func_0xa0fb657c(sel, 0x217);
    DAT_a807d238[15] = func_0xa0fb657c(sel, 0x216);
    DAT_a807d238[16] = func_0xa0fb657c(sel, 0x21d);
    DAT_a807d238[17] = func_0xa0fb657c(sel, 0x21c);
    DAT_a807d238[18] = func_0xa0fb657c(sel, 0x21b);
    DAT_a807d238[19] = func_0xa0fb657c(sel, 0x21a);
}
