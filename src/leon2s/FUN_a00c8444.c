/* FUN_a00c8444 (leon2s 0xa00c8444-0xa00c850c, 200 bytes), flags -mcpu=v8 -Os -g.
 * Tests bit 28 (bit-field f28) of word 0 of the 24-byte record DAT_a8078bb0[port]. When set, register 0xf of
 * port is rewritten with bit 4 set and register 0xcc with bit 3 set; when clear, the same two bits are
 * cleared. Each rewrite reads the register with func_0xa0fb7fd8(port, 0, reg) and writes it with
 * func_0xa0fb8054(port, 0, reg, value); the last write is a tail call.
 * Record layout as in FUN_a00c91f8 (big-endian bit-fields, first field = most significant bit).
 */
struct Rec24 {
    unsigned int a:3;
    unsigned int f28:1;
    unsigned int cnt:4;
    unsigned int f23:1;
    unsigned int mid:5;
    unsigned int st:2;
    unsigned int x:8;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char pad[17];
};
extern struct Rec24 DAT_a8078bb0[];
extern unsigned int func_0xa0fb7fd8(unsigned char, int, unsigned short);
extern void func_0xa0fb8054(unsigned char, int, unsigned short, unsigned char);

void FUN_a00c8444(unsigned char port)
{
    if (DAT_a8078bb0[port].f28) {
        func_0xa0fb8054(port, 0, 0xf, func_0xa0fb7fd8(port, 0, 0xf) | 0x10);
        func_0xa0fb8054(port, 0, 0xcc, func_0xa0fb7fd8(port, 0, 0xcc) | 8);
    } else {
        func_0xa0fb8054(port, 0, 0xf, func_0xa0fb7fd8(port, 0, 0xf) & 0xef);
        func_0xa0fb8054(port, 0, 0xcc, func_0xa0fb7fd8(port, 0, 0xcc) & 0xf7);
    }
}
