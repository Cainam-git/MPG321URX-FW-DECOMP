/* leon2m FUN_a00b88e0 @ 0xa00b88e0-0xa00b89c4 (57 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00a5e68.
 * Draws a value at screen position (x, y): FUN_a0146b50(200, 0), FUN_a0146b6c(2, 0), FUN_a0146a80(x + 3, y + 11,
 * 0x10, 0x792, 0); formats FUN_a00d8b38() with the format string "n%d HZ" (0x1981d8, image-relative) into a
 * 16-byte local buffer with FUN_a01577f4; stores the index of the first zero byte minus 1 into buffer byte 0;
 * then FUN_a00a31a4(0, x + 8, y + 11, 6, buffer, 0).
 */
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned short FUN_a00d8b38(void);
extern void FUN_a01577f4(unsigned char *, unsigned int, unsigned short);
extern void FUN_a00a31a4(int, unsigned short, unsigned short, int, unsigned char *, int);

void FUN_a00b88e0(unsigned short x, unsigned short y)
{
    unsigned char buf[16];
    unsigned char i;

    FUN_a0146b50(200, 0);
    FUN_a0146b6c(2, 0);
    FUN_a0146a80(x + 3, y + 11, 0x10, 0x792, 0);
    FUN_a01577f4(buf, 0x1981d8, FUN_a00d8b38());
    for (i = 0; i < 16; i++)
        if (buf[i] == 0)
            break;
    buf[0] = i - 1;
    FUN_a00a31a4(0, x + 8, y + 11, 6, buf, 0);
}
