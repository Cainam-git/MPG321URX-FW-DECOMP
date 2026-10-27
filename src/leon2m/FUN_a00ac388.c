/* leon2m FUN_a00ac388 @ 0xa00ac388-0xa00ac718 (912 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Callers: FUN_a00939b0, FUN_a0094ed8, FUN_a0094f58, FUN_a00af44c. Same formatting as FUN_a00b89c4: bytes
 * 0x198 + i and 0x19c + i of DAT_a802d290 printed as "n%d%d : %d%d" (tens and units, FUN_a01577f4 with the
 * string s_001981b0) into a 16-byte buffer whose byte 0 is then replaced by the string length - 1 (counted up to 15).
 * mode != 0: FUN_a0146b50(0x111, 0), FUN_a0146b6c(0, 0); FUN_a00a31a4(0, 0x2a, 6, 1, FUN_a00a3844(table 0x18e9f8,
 * byte 8 + 0x91), 0); for i = 1: FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(table 0x193248, i * 29 + byte 8
 * - 29), 0); for i = 0..3 the formatted buffer to FUN_a00a31a4(0, 0x2a, i * 2 + 10, 1, buf, 0), preceded by
 * FUN_a0146b20(0, 0x2a, i * 2 + 10, 10, 0, 0) when i == byte 0x1a0 - 1; then with n = byte 0x1a0 + 1 and
 * r = n * 2 + 6 (n <= 6) or n * 2 - 8: FUN_a0146b20(0, 0x28, r, 1, 0xf, 0) and FUN_a0146b20(0, 0x29, r, 1, 0x10, 0).
 * mode 0: FUN_a0146b50(0x139, 0), FUN_a0146b6c(0, 0), FUN_a0146b20(0, 0x2a, byte 0x1a0 * 3 + 10, 0xb, 0, 0), then
 * the formatted pair j = byte 0x1a0 - 1 to FUN_a00a31a4(0, 0x2a, j * 2 + 10, 1, buf, 0).
 * Source form: the format string as the symbol s_001981b0; r assigned in both arms of 'if (n <= 6)'.
 */
struct St {
    unsigned char pad[8];
    unsigned char b08;
    unsigned char pad09[0x198 - 9];
    unsigned char b198[4];
    unsigned char b19c[4];
    unsigned char b1a0;
};
extern struct St DAT_a802d290;
extern unsigned int DAT_0018e9f8[];
extern unsigned int DAT_00193248[];
extern const char s_001981b0[];
extern void FUN_a01577f4(unsigned char *, const char *, ...);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned short, int, unsigned int, int);

void FUN_a00ac388(unsigned char mode)
{
    unsigned char buf[16];
    unsigned char i, k, j, n, r;

    if (mode != 0) {
        FUN_a0146b50(0x111, 0);
        FUN_a0146b6c(0, 0);
        FUN_a00a31a4(0, 0x2a, 6, 1, FUN_a00a3844(DAT_0018e9f8, DAT_a802d290.b08 + 0x91), 0);
        for (i = 1; i <= 1; i++)
            FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_00193248, i * 29 + DAT_a802d290.b08 - 29), 0);
        for (i = 0; i <= 3; i++) {
            FUN_a01577f4(buf, s_001981b0, DAT_a802d290.b198[i] / 10, DAT_a802d290.b198[i] % 10,
                         DAT_a802d290.b19c[i] / 10, DAT_a802d290.b19c[i] % 10);
            for (k = 0; k <= 0xe; k++)
                if (buf[k] == 0)
                    break;
            buf[0] = k - 1;
            if (i == DAT_a802d290.b1a0 - 1)
                FUN_a0146b20(0, 0x2a, i * 2 + 10, 10, 0, 0);
            FUN_a00a31a4(0, 0x2a, i * 2 + 10, 1, (unsigned int)buf, 0);
        }
        n = DAT_a802d290.b1a0 + 1;
        if (n <= 6)
            r = n * 2 + 6;
        else
            r = n * 2 - 8;
        FUN_a0146b20(0, 0x28, r, 1, 0xf, 0);
        FUN_a0146b20(0, 0x29, r, 1, 0x10, 0);
    } else {
        FUN_a0146b50(0x139, 0);
        FUN_a0146b6c(0, 0);
        FUN_a0146b20(0, 0x2a, DAT_a802d290.b1a0 * 3 + 10, 0xb, 0, 0);
        j = DAT_a802d290.b1a0 - 1;
        FUN_a01577f4(buf, s_001981b0, DAT_a802d290.b198[j] / 10, DAT_a802d290.b198[j] % 10,
                     DAT_a802d290.b19c[j] / 10, DAT_a802d290.b19c[j] % 10);
        for (k = 0; k <= 0xe; k++)
            if (buf[k] == 0)
                break;
        buf[0] = k - 1;
        FUN_a00a31a4(0, 0x2a, j * 2 + 10, 1, (unsigned int)buf, 0);
    }
}
