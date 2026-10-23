/*
 * FUN_a00ca130 (leon2s, 0xa00ca130-0xa00ca4e8, 952 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Prints s_9f1c2110 with func_0xa0f83044 and runs the transfer sequence of the hardware
 * registers 0xcf018e00..0xcf018e28 (as in FUN_a00cd5e4) with the port registers of
 * func_0xa0fb6c98 / func_0xa0fb6bb8 / func_0xa0fb6c00, printing each step:
 * - func_0xa0fb6c98(port, 0x30, 0x80, 1); e10 = 0x1f, e14 = 0x80 and waits for bit 7 to clear; clears bit 0 of
 *   e18; e00 = 0x11; port register 0xe9 = 0xf and waits until its low nibble reads 0; e08 = 0x10, e0c = 0x3f.
 * - n = port register 0x2aa; one read of 0xe8; e14 = 2 and waits for bit 1 to clear; prints s_9f1c2120;
 *   n * 5 bytes v of register 0xe8 are printed (s_9f1b7578, v) and passed to FUN_a00ca074(0xaa, v).
 * - registers 0x2aa and 0x2ab to FUN_a00ca074(0xaa, v), then printed together (s_9f1c2128); prints
 *   s_9f1c2140; j = 0..7 printed and passed to FUN_a00ca074(0xaa, j); FUN_a00ca074(0xaa, 0x80).
 * - i = (n & 0xff) * 5 + 10: e28 = low byte, e24 = high byte; when e0c <= 6: e14 |= 1 and wait, e10 = 0x1f,
 *   e14 |= 0x80 and wait; e0c = 0, e04 = low byte of i * 8, e0c = 1, e04 = next byte; e14 |= 1 and wait;
 *   e00 = 0x22, e08 = 0; e10 |= 0x10 and wait for bit 4 to clear.
 * - j = 0..19: v = low byte of e04 is written to port register (j / 4) * 8 - j + 0x297 and printed
 *   (s_9f1c2148, j, v).
 * - tail call func_0xa0fb6c98(port, 0x30, 0x80, 0).
 * Source forms: the first loop counter i is reused for the length value; the printed 0x2aa value is read
 * into an unsigned int; the later loops share a second counter j (u16); the byte writes of i use
 * (unsigned char) casts.
 */
extern const char s_9f1c2110[];
extern const char s_9f1c2120[];
extern const char s_9f1b7578[];
extern const char s_9f1c2128[];
extern const char s_9f1c2140[];
extern const char s_9f1c2148[];
extern int func_0xa0f83044(const char *, ...);
extern void func_0xa0fb6c98(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned char func_0xa0fb6bb8(unsigned char, unsigned short);
extern void func_0xa0fb6c00(unsigned char, unsigned short, unsigned char);
extern void FUN_a00ca074(unsigned char, unsigned char);

#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00ca130(unsigned char port)
{
    unsigned short n;
    unsigned short i;
    unsigned short j;
    unsigned char v;
    unsigned int a;

    func_0xa0f83044(s_9f1c2110);
    func_0xa0fb6c98(port, 0x30, 0x80, 1);
    R(0xcf018e10) = 0x1f;
    R(0xcf018e14) = 0x80;
    while (R(0xcf018e14) & 0x80)
        ;
    R(0xcf018e18) &= ~1;
    R(0xcf018e00) = 0x11;
    func_0xa0fb6c00(port, 0xe9, 0xf);
    while (func_0xa0fb6bb8(port, 0xe9) & 0xf)
        ;
    R(0xcf018e08) = 0x10;
    R(0xcf018e0c) = 0x3f;
    n = func_0xa0fb6bb8(port, 0x2aa);
    func_0xa0fb6bb8(port, 0xe8);
    R(0xcf018e14) = 2;
    while (R(0xcf018e14) & 2)
        ;
    func_0xa0f83044(s_9f1c2120);
    for (i = 0; i < n * 5; i++) {
        v = func_0xa0fb6bb8(port, 0xe8);
        func_0xa0f83044(s_9f1b7578, v);
        FUN_a00ca074(0xaa, v);
    }
    i = (n & 0xff) * 5;
    FUN_a00ca074(0xaa, func_0xa0fb6bb8(port, 0x2aa));
    FUN_a00ca074(0xaa, func_0xa0fb6bb8(port, 0x2ab));
    a = func_0xa0fb6bb8(port, 0x2aa);
    func_0xa0f83044(s_9f1c2128, a, func_0xa0fb6bb8(port, 0x2ab));
    func_0xa0f83044(s_9f1c2140);
    for (j = 0; j < 8; j++) {
        v = j;
        func_0xa0f83044(s_9f1b7578, v);
        FUN_a00ca074(0xaa, v);
    }
    FUN_a00ca074(0xaa, 0x80);
    i += 10;
    R(0xcf018e28) = (unsigned char)i;
    R(0xcf018e24) = (unsigned char)(i >> 8);
    if (R(0xcf018e0c) <= 6) {
        R(0xcf018e14) |= 1;
        while (R(0xcf018e14) & 1)
            ;
        R(0xcf018e10) = 0x1f;
        R(0xcf018e14) |= 0x80;
        while (R(0xcf018e14) & 0x80)
            ;
    }
    R(0xcf018e0c) = 0;
    R(0xcf018e04) = (i << 3) & 0xff;
    R(0xcf018e0c) = 1;
    R(0xcf018e04) = ((i << 3) >> 8) & 0xff;
    R(0xcf018e14) |= 1;
    while (R(0xcf018e14) & 1)
        ;
    R(0xcf018e00) = 0x22;
    R(0xcf018e08) = 0;
    R(0xcf018e10) |= 0x10;
    while (R(0xcf018e10) & 0x10)
        ;
    for (j = 0; j < 20; j++) {
        v = R(0xcf018e04);
        func_0xa0fb6c00(port, (j / 4) * 8 - j + 0x297, v);
        func_0xa0f83044(s_9f1c2148, j, v);
    }
    func_0xa0fb6c98(port, 0x30, 0x80, 0);
}
