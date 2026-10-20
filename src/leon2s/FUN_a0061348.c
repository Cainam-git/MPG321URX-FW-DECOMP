/* FUN_a0061348 (leon2s 0xa0061348-0xa00613cc, 132 bytes), flags -mcpu=v8 -Os -g.
 * Writes the word x as 8 hexadecimal digits (most significant first) to the UART: each digit is looked up in the
 * character table s_a00b3a08 ("0123456789ABCDEF") and sent with the body of FUN_a006122c (wait for bit 5 of status register
 * 0xc00c0014, at most 0xffffe polls, then write 0xc00c0000), which is inlined from a static copy.
 */
#define REG_c00c0000 (*(volatile unsigned int *)0xc00c0000)
#define REG_c00c0014 (*(volatile unsigned int *)0xc00c0014)
extern const char s_a00b3a08[];

static void putc_(unsigned char c)
{
    unsigned int n = 0;

    while ((REG_c00c0014 & 0x20) == 0) {
        if (++n > 0xffffe)
            break;
    }
    REG_c00c0000 = c;
}

void FUN_a0061348(unsigned int x)
{
    int i;

    for (i = 0; i < 8; i++)
        putc_(s_a00b3a08[(x >> (28 - i * 4)) & 0xf]);
}
