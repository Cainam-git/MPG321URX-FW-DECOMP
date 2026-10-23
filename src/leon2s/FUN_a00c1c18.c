/*
 * FUN_a00c1c18 (leon2s, 0xa00c1c18-0xa00c224c, 1588 bytes), flags -mcpu=v8 -Os -g.
 * Clears registers 0xcf012b84 / 0xcf012b88, writes 0x44 to 0xcf012b8c, calls the ROM routine
 * func_0xa0f83044(s_9f1b7538, 0) and func_0xa0fb67b8(2, 0x2e, 4, 1). Reads 5 bytes from address 0x138
 * (func_0xa0f9d2e0(addr, len, buf)) into a: all zero -> FUN_a00c0c08(a, b); else reads 0x11a bytes from 0x20
 * into b, sets b[0x118] = 0x68 when a is 24 c8 eb 3e 9c (else 0) and b[0x119] = 0. Calls FUN_a00c0ce8,
 * FUN_a00c0dfc and FUN_a00c1318 each with (0, a, b) and (1, a, b). Reads 5 bytes from 0x260 into a: all zero
 * -> FUN_a00c0c78(a, b); else reads 0x11a bytes from 0x148 into b and clears b[0x118] / b[0x119]. Then
 * FUN_a00c0b48(a, b), FUN_a00c0a88(a, b), ROM calls (2, 0x2e, 4, 0), (2, 0x46, 0x60), (2, 0x41, 0x10, 1),
 * (2, 0x42, 1, 1), clears bytes 0x80..0x13f of the 320-byte buffer e and DAT_a807d628. Reads 16 bytes from
 * 0x270 into c: all zero -> FUN_a00c0ecc(c, d, 0, e) and DAT_a807d628 = 1; else reads 0x20a bytes from 0x280
 * into d and 0x80 bytes from 0x50a into e. Calls FUN_a00c0f88, FUN_a00c10c4 and FUN_a00c1550 each with
 * (0 / 1, c, d, 0, e). Clears DAT_a807d62c, reads 0x24 bytes from 0x590 into DAT_a807d638; when its first
 * 16 bytes are zero: FUN_a00c12d8(DAT_a807d638, 0, 0) and DAT_a807d62c = 1. Then FUN_a00c1778(i, 1) for
 * i = 0..3 and FUN_a00c1778(i, 0) for i = 4, 5, FUN_a00c18fc(), FUN_a00c79c8(3), DAT_a8078c5c = 1,
 * func_0xa0f7fedc(), func_0xa0f83044(s_9f1b7550, 0), func_0xa0fc2070(0, DAT_9f1b1ac0).
 * Source form: the five stack buffers are declared in frame order (a, b, c, d, e); the byte tests are
 * written out as && chains; unsigned short loop counters.
 */
#define REG_cf012b84 (*(volatile unsigned int *)0xcf012b84)
#define REG_cf012b88 (*(volatile unsigned int *)0xcf012b88)
#define REG_cf012b8c (*(volatile unsigned int *)0xcf012b8c)

extern unsigned char DAT_a807d628;
extern unsigned char DAT_a807d62c;
extern unsigned char DAT_a807d638[];
extern unsigned char DAT_a8078c5c;
extern const char s_9f1b7538[];
extern const char s_9f1b7550[];
extern const unsigned char DAT_9f1b1ac0[];

extern int func_0xa0f83044(const char *, ...);
extern void func_0xa0fb67b8(unsigned char, unsigned short, unsigned int, unsigned char);
extern void func_0xa0fb65c4(unsigned char, unsigned short, unsigned char);
extern void func_0xa0fb6aa0(unsigned char, unsigned short, unsigned char, unsigned char);
extern void func_0xa0f9d2e0(unsigned short, unsigned short, unsigned char *);
extern void func_0xa0f7fedc(void);
extern void func_0xa0fc2070(unsigned int, const unsigned char *);
extern void FUN_a00c0c08(unsigned char *, unsigned char *);
extern void FUN_a00c0c78(unsigned char *, unsigned char *);
extern void FUN_a00c0ce8(unsigned char, unsigned char *, unsigned char *);
extern void FUN_a00c0dfc(unsigned char, unsigned char *, unsigned char *);
extern void FUN_a00c1318(unsigned char, unsigned char *, unsigned char *);
extern void FUN_a00c0b48(unsigned char *, unsigned char *);
extern void FUN_a00c0a88(unsigned char *, unsigned char *);
extern void FUN_a00c0ecc(unsigned char *, unsigned char *, unsigned char *, unsigned char *);
extern void FUN_a00c0f88(unsigned char, unsigned char *, unsigned char *, unsigned char *, unsigned char *);
extern void FUN_a00c10c4(unsigned char, unsigned char *, unsigned char *, unsigned char *, unsigned char *);
extern void FUN_a00c1550(unsigned char, unsigned char *, unsigned char *, unsigned char *, unsigned char *);
extern void FUN_a00c12d8(unsigned char *, unsigned int, unsigned int);
extern void FUN_a00c1778(unsigned char, unsigned char);
extern void FUN_a00c18fc(void);
extern void FUN_a00c79c8(unsigned char);

void FUN_a00c1c18(void)
{
    unsigned char a[5];
    unsigned char b[0x11a];
    unsigned char c[0x10];
    unsigned char d[0x210];
    unsigned char e[0x140];
    unsigned short i;

    REG_cf012b84 = 0;
    REG_cf012b88 = 0;
    REG_cf012b8c = 0x44;
    func_0xa0f83044(s_9f1b7538, 0);
    func_0xa0fb67b8(2, 0x2e, 4, 1);
    func_0xa0f9d2e0(0x138, 5, a);
    if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0) {
        FUN_a00c0c08(a, b);
    } else {
        func_0xa0f9d2e0(0x20, 0x11a, b);
        if (a[0] == 0x24 && a[1] == 0xc8 && a[2] == 0xeb && a[3] == 0x3e && a[4] == 0x9c)
            b[0x118] = 0x68;
        else
            b[0x118] = 0;
        b[0x119] = 0;
    }
    FUN_a00c0ce8(0, a, b);
    FUN_a00c0ce8(1, a, b);
    FUN_a00c0dfc(0, a, b);
    FUN_a00c0dfc(1, a, b);
    FUN_a00c1318(0, a, b);
    FUN_a00c1318(1, a, b);
    func_0xa0f9d2e0(0x260, 5, a);
    if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0) {
        FUN_a00c0c78(a, b);
    } else {
        func_0xa0f9d2e0(0x148, 0x11a, b);
        b[0x118] = 0;
        b[0x119] = 0;
    }
    FUN_a00c0b48(a, b);
    FUN_a00c0a88(a, b);
    func_0xa0fb67b8(2, 0x2e, 4, 0);
    func_0xa0fb65c4(2, 0x46, 0x60);
    func_0xa0fb6aa0(2, 0x41, 0x10, 1);
    func_0xa0fb6aa0(2, 0x42, 1, 1);
    for (i = 0x80; i < 0x140; i++)
        e[i] = 0;
    DAT_a807d628 = 0;
    func_0xa0f9d2e0(0x270, 0x10, c);
    if (c[0] == 0 && c[1] == 0 && c[2] == 0 && c[3] == 0 && c[4] == 0 && c[5] == 0 && c[6] == 0 &&
        c[7] == 0 && c[8] == 0 && c[9] == 0 && c[10] == 0 && c[11] == 0 && c[12] == 0 && c[13] == 0 &&
        c[14] == 0 && c[15] == 0) {
        FUN_a00c0ecc(c, d, 0, e);
        DAT_a807d628 = 1;
    } else {
        func_0xa0f9d2e0(0x280, 0x20a, d);
        func_0xa0f9d2e0(0x50a, 0x80, e);
    }
    FUN_a00c0f88(0, c, d, 0, e);
    FUN_a00c0f88(1, c, d, 0, e);
    FUN_a00c10c4(0, c, d, 0, e);
    FUN_a00c10c4(1, c, d, 0, e);
    FUN_a00c1550(0, c, d, 0, e);
    FUN_a00c1550(1, c, d, 0, e);
    DAT_a807d62c = 0;
    func_0xa0f9d2e0(0x590, 0x24, DAT_a807d638);
    if (DAT_a807d638[0] == 0 && DAT_a807d638[1] == 0 && DAT_a807d638[2] == 0 && DAT_a807d638[3] == 0 &&
        DAT_a807d638[4] == 0 && DAT_a807d638[5] == 0 && DAT_a807d638[6] == 0 && DAT_a807d638[7] == 0 &&
        DAT_a807d638[8] == 0 && DAT_a807d638[9] == 0 && DAT_a807d638[10] == 0 && DAT_a807d638[11] == 0 &&
        DAT_a807d638[12] == 0 && DAT_a807d638[13] == 0 && DAT_a807d638[14] == 0 &&
        DAT_a807d638[15] == 0) {
        FUN_a00c12d8(DAT_a807d638, 0, 0);
        DAT_a807d62c = 1;
    }
    for (i = 0; i < 4; i++)
        FUN_a00c1778(i, 1);
    for (i = 4; i < 6; i++)
        FUN_a00c1778(i, 0);
    FUN_a00c18fc();
    FUN_a00c79c8(3);
    DAT_a8078c5c = 1;
    func_0xa0f7fedc();
    func_0xa0f83044(s_9f1b7550, 0);
    func_0xa0fc2070(0, DAT_9f1b1ac0);
}
