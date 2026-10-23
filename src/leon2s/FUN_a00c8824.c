/* leon2s FUN_a00c8824 @ 0xa00c8824-0xa00c89b8, -mcpu=v8 -Os -g.
 * (u8 port, u8 ch, u16 len), returns u8. len > 0x27b: func_0xa0f83044(0x9f1c1ff8) (ROM print, ROM address)
 * and 0xb. Otherwise FUN_a00c8048(port, 0x74, 0x43, len); r = FUN_a00c81f8(port, buf, len) (buf = 640-byte
 * stack buffer); func_0xa0fb67b8(2, 0x88, 0x40, 1), (ch, 0x37, 0x10, 0) and (ch, 0x37, 0x10, 1);
 * FUN_a00c87e8(port, 0xb, 0x4005); func_0xa0f83044(0x9f1c2020); each byte of buf goes to
 * func_0xa0fb65c4(ch, 0x38, b) and FUN_a00c7654(port, 1, b); then FUN_a00c7654(port, 1,
 * func_0xa0fb7fd8(port, 0, 0x10 + i)) for i = 0..4; FUN_a00c87e8(port, 0, 0); func_0xa0fb67b8(ch, 0x37,
 * 0x10, 0) and (2, 0x88, 0x40, 0); returns (u8)r. The func_0x.. callees are ROM routines outside the image.
 */
extern int func_0xa0f83044(const char *, ...);
extern unsigned char FUN_a00c8048(unsigned char, unsigned char, unsigned char, unsigned short);
extern int FUN_a00c81f8(unsigned int, unsigned char *, unsigned short);
extern void func_0xa0fb67b8(unsigned char, unsigned short, unsigned int, unsigned char);
extern void func_0xa0fb65c4(unsigned char, unsigned short, unsigned char);
extern unsigned char func_0xa0fb7fd8(unsigned char, int, unsigned short);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern void FUN_a00c7654(unsigned char, unsigned short, unsigned char);

unsigned char FUN_a00c8824(unsigned char port, unsigned char ch, unsigned short len)
{
    unsigned char buf[640];
    unsigned char r;
    unsigned short i;

    if (len > 0x27b) {
        func_0xa0f83044((const char *)0x9f1c1ff8);
        return 0xb;
    }
    FUN_a00c8048(port, 0x74, 0x43, len);
    r = FUN_a00c81f8(port, buf, len);
    func_0xa0fb67b8(2, 0x88, 0x40, 1);
    func_0xa0fb67b8(ch, 0x37, 0x10, 0);
    func_0xa0fb67b8(ch, 0x37, 0x10, 1);
    FUN_a00c87e8(port, 0xb, 0x4005);
    func_0xa0f83044((const char *)0x9f1c2020);
    for (i = 0; i < len; i++) {
        func_0xa0fb65c4(ch, 0x38, buf[i]);
        FUN_a00c7654(port, 1, buf[i]);
    }
    for (i = 0; i <= 4; i++)
        FUN_a00c7654(port, 1, func_0xa0fb7fd8(port, 0, i + 0x10));
    FUN_a00c87e8(port, 0, 0);
    func_0xa0fb67b8(ch, 0x37, 0x10, 0);
    func_0xa0fb67b8(2, 0x88, 0x40, 0);
    return r;
}
