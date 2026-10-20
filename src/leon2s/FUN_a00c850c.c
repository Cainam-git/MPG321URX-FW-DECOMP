/* FUN_a00c850c (leon2s 0xa00c850c-0xa00c85b8, 172 bytes), flags -mcpu=v8 -Os -g.
 * r = FUN_a00c8048(port, 0x74, 0, 5); a non-zero r is returned at once. Otherwise reads 5 bytes of port
 * into the stack buffer buf with FUN_a00c81f8(port, buf, 5), writes them to registers 0x10..0x14 through
 * func_0xa0fb8054(port, 0, 0x10 + i, buf[i]), and returns 0x78 when FUN_a00c83e4(buf) (declared char)
 * equals r (0 here), else 0.
 * Source forms: r is an int; the loop counter i (unsigned char) is reused for the FUN_a00c83e4 result and for
 * the value 0x78 that is returned (this keeps the firmware's sign extension, xor with r and
 * addx/neg/and/add sequence).
 */
extern void func_0xa0fb8054(unsigned char, int, unsigned short, unsigned char);
extern unsigned char FUN_a00c8048(unsigned char port, unsigned char a, unsigned char b, unsigned short n);
extern void FUN_a00c81f8(unsigned char port, unsigned char *buf, unsigned short n);
extern char FUN_a00c83e4(unsigned char *buf);

unsigned int FUN_a00c850c(unsigned char port)
{
    unsigned char buf[5];
    unsigned char i;
    int r;

    r = FUN_a00c8048(port, 0x74, 0, 5);
    if (r != 0)
        return r;
    FUN_a00c81f8(port, buf, 5);
    for (i = 0; i < 5; i++)
        func_0xa0fb8054(port, 0, i + 0x10, buf[i]);
    i = FUN_a00c83e4(buf);
    if (i == r) {
        i = 0x78;
        return i;
    }
    return 0;
}
