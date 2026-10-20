/* leon2m FUN_a0123c80 @ 0xa0123c80-0xa0123cf0 (28 words).
 * Compares the first n bytes of buf with the bytes at 0xa802d850 (the address FUN_a0124174 returns). At the first
 * differing byte it returns 0. When byte n - 1 also matches it prints "File match\r\n" through FUN_a00df170 and
 * returns 1; n == 0 returns 0. Callers: FUN_a0147fb4 and FUN_a0148120.
 */
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned char DAT_a802d850[];

unsigned char FUN_a0123c80(unsigned char *buf, unsigned char n)
{
    unsigned char i;

    for (i = 0; i < n; i++) {
        if (buf[i] != DAT_a802d850[i])
            return 0;
        if (i == n - 1) {
            FUN_a00df170("File match\r\n");
            return 1;
        }
    }
    return 0;
}
