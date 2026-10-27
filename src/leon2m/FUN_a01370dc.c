/* leon2m FUN_a01370dc @ 0xa01370dc-0xa013730c (560 bytes), flags -mcpu=v8 -O3 -g. Callers: FUN_a012bb94, FUN_a012bc08, FUN_a012be4c, FUN_a012c004, FUN_a012c090, FUN_a01387a4 and many small
 * wrappers at 0xa013730c..0xa01393bc.
 * Sends a command through mailbox portal 1, offset 0x80 (eight words): first up to 100 rounds of MailBox_Read
 * (func_0x4008c4d0) of the first word until it is zero, with func_0x4008d1a0(1) between rounds. len is limited to 0x1c; the
 * len bytes from p are packed little-endian into words 1..7 (len / 4 whole words, then the len % 4 remaining bytes
 * into the next word). Word 0 = (cmd << 8 | (u8)(len + 4) << 16 | 0x55) & 0xffffff, then its top byte is set to
 * the XOR of all bytes of the eight words (v ^ v >> 8 ^ v >> 16 ^ v >> 24 summed with XOR). The eight words are
 * written with MailBox_Write (func_0x4008c5f8), FUN_a00de970() is called, and when wait is non-zero the first word
 * is polled again the same way (at most 100 rounds) until it is zero.
 * Source form: the buffer is reached through a pointer b for the calls, the checksum loop and the top-byte update;
 * the checksum loop compares with a limit variable m = 8 (cmp 8; bcs); n = 100 is set before b.
 */
extern void func_0x4008c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008c5f8(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008d1a0(unsigned short);
extern void FUN_a00de970(void);

void FUN_a01370dc(unsigned int cmd, unsigned char len, unsigned char *p, unsigned char wait)
{
    unsigned int buf[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    unsigned char k = 0, i, n, m, words, rest;
    unsigned int *b;
    unsigned int sum, v;

    n = 100;
    b = buf;
    do {
        func_0x4008c4d0(1, 0x80, b, 1);
        if (buf[0] == 0)
            break;
        func_0x4008d1a0(1);
    } while (--n);
    if (len > 0x1c)
        len = 0x1c;
    words = len / 4;
    rest = len % 4;
    for (i = 0; i < words; i++) {
        buf[i + 1] = p[k] | (p[k + 1] << 8) | (p[k + 2] << 16) | (p[k + 3] << 24);
        k += 4;
    }
    if (rest != 0) {
        for (i = 0; i < rest; i++)
            buf[(len >> 2) + 1] |= p[k + i] << (i * 8);
    }
    buf[0] = ((cmd << 8) | ((unsigned char)(len + 4) << 16) | 0x55) & 0xffffff;
    sum = 0;
    m = 8;
    for (i = 0; i < m; i++) {
        v = b[i];
        sum = v ^ sum ^ (v >> 8) ^ (v >> 16) ^ (v >> 24);
    }
    b[0] |= sum << 24;
    func_0x4008c5f8(1, 0x80, b, 8);
    FUN_a00de970();
    n = 100;
    while (wait) {
        func_0x4008c4d0(1, 0x80, b, 1);
        if (buf[0] == 0)
            break;
        func_0x4008d1a0(1);
        if (--n == 0)
            break;
    }
}
