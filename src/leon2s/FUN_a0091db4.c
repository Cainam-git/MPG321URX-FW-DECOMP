/* FUN_a0091db4 (leon2s 0xa0091db4-0xa0091e70, 188 bytes), flags -mcpu=v8 -Os -g.
 * For i = 0 .. len / 16 - 1 (halfword counter): calls the ROM routines func_0x9f1b7b60(port) and
 * func_0x9f1b7b90(port), func_0x9f1b8048(port, 0xa0, base + i * 16, 0x10) and func_0x9f1b81f8(port, buf, 0x10) with a
 * 16-byte stack buffer, then copies the 16 buffer bytes to dst[i * 16 ..]. func_0x9f1b8048 returns int (its result is
 * ignored; a void prototype moves the port 'mov' out of the call delay slot); the offset i * 16 is an unsigned int.
 */
extern void func_0x9f1b7b60(unsigned char);
extern void func_0x9f1b7b90(unsigned char);
extern int func_0x9f1b8048(unsigned char, unsigned char, unsigned short, unsigned char);
extern void func_0x9f1b81f8(unsigned char, unsigned char *, unsigned char);

void FUN_a0091db4(unsigned char port, unsigned char *dst, unsigned short len, unsigned short base)
{
    unsigned char buf[16];
    unsigned short i, j;
    unsigned int off;

    for (i = 0; i < (len >> 4); i++) {
        func_0x9f1b7b60(port);
        func_0x9f1b7b90(port);
        off = i << 4;
        func_0x9f1b8048(port, 0xa0, off + base, 0x10);
        func_0x9f1b81f8(port, buf, 0x10);
        for (j = 0; j < 16; j++)
            dst[off + j] = buf[j];
    }
}
