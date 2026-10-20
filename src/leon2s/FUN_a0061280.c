/* FUN_a0061280 (leon2s 0xa0061280-0xa0061348, 200 bytes), flags -mcpu=v8 -Os -g.
 * Writes the zero-terminated string s to the UART, sending '\r' after every '\n'. Each character is sent like
 * FUN_a006122c: wait for bit 5 of status register 0xc00c0014 (at most 0xffffe polls), then write 0xc00c0000.
 * Source forms: the string character is sent by an open-coded wait and store (the firmware reads *s at the
 * store and again for the '\n' test); the '\r' goes through a static inline helper with an int parameter.
 */
#define REG_c00c0000 (*(volatile unsigned int *)0xc00c0000)
#define REG_c00c0014 (*(volatile unsigned int *)0xc00c0014)

static inline void putc_(int c)
{
    unsigned int n = 0;

    while ((REG_c00c0014 & 0x20) == 0) {
        if (++n > 0xffffe)
            break;
    }
    REG_c00c0000 = c;
}

void FUN_a0061280(const unsigned char *s)
{
    unsigned int n;

    while (*s != 0) {
        n = 0;
        while ((REG_c00c0014 & 0x20) == 0) {
            if (++n > 0xffffe)
                break;
        }
        REG_c00c0000 = *s;
        if (*s == '\n')
            putc_('\r');
        s++;
    }
}
