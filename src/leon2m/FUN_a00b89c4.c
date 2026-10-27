/* leon2m FUN_a00b89c4 @ 0xa00b89c4-0xa00b8ca8 (185 words), flags -mcpu=v8 -O3 -g (also -msoft-float).
 * Callers: FUN_a00ae39c, FUN_a00ae4f0, FUN_a00b8e7c.
 * FUN_a0146b6c(2, 0), FUN_a0146b50(0x6f, 0), FUN_a00a7c88(). mode non-zero: formats bytes 0x19b and 0x19f of
 * 0xa802d290 as "n%d%d : %d%d" (tens and units of each, FUN_a01577f4) into a 16-byte buffer, replaces byte 0 of the
 * buffer with the string length - 1 (length counted up to 15) and passes it to FUN_a00a31a4(0, 6, 5, 0xa, buf, 0).
 * mode 0: FUN_a00a31a4(0, 6, 5, 0xa, FUN_a00a3844(table 0x193248, byte 8), 0), then the same formatting for the
 * byte pairs 0x198 + i / 0x19c + i with row i * 2 + 7, i = 0..2. Then as FUN_a00b8ca8: when byte 0xa8025c56 >> 2
 * equals mode, FUN_a00ad86c(byte & 3, 0) and FUN_a0146b20(0, j + 4, k * 2 + 5, 1, j + 0x1c, 0) for j = 0, 1;
 * otherwise FUN_a0146c40(4, 0, 0).
 * Source form: the mode != 0 branch counts the length with i, the mode 0 branch with k.
 */
struct St {
    unsigned char pad[8];
    unsigned char b08;
    unsigned char pad09[0x198 - 9];
    unsigned char b198[4];
    unsigned char b19c[4];
};
extern struct St DAT_a802d290;
extern unsigned int DAT_00193248[];
extern void FUN_a01577f4(unsigned char *, const char *, ...);
extern unsigned char DAT_a8025c56;
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern void FUN_a00a7c88(void);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned short, int, unsigned int, int);
extern void FUN_a00ad86c(unsigned char, unsigned char);
extern void FUN_a0146c40(int, int, int);

void FUN_a00b89c4(unsigned char mode)
{
    unsigned char buf[16];
    unsigned char i, k;

    FUN_a0146b6c(2, 0);
    FUN_a0146b50(0x6f, 0);
    FUN_a00a7c88();
    if (mode != 0) {
        FUN_a01577f4(buf, "n%d%d : %d%d", DAT_a802d290.b198[3] / 10, DAT_a802d290.b198[3] % 10,
                     DAT_a802d290.b19c[3] / 10, DAT_a802d290.b19c[3] % 10);
        for (i = 0; i <= 0xe; i++)
            if (buf[i] == 0)
                break;
        buf[0] = i - 1;
        FUN_a00a31a4(0, 6, 5, 0xa, (unsigned int)buf, 0);
    } else {
        FUN_a00a31a4(0, 6, 5, 0xa, FUN_a00a3844(DAT_00193248, DAT_a802d290.b08), 0);
        for (i = 0; i <= 2; i++) {
            FUN_a01577f4(buf, "n%d%d : %d%d", DAT_a802d290.b198[i] / 10, DAT_a802d290.b198[i] % 10,
                         DAT_a802d290.b19c[i] / 10, DAT_a802d290.b19c[i] % 10);
            for (k = 0; k <= 0xe; k++)
                if (buf[k] == 0)
                    break;
            buf[0] = k - 1;
            FUN_a00a31a4(0, 6, i * 2 + 7, 0xa, (unsigned int)buf, 0);
        }
    }
    if (mode == DAT_a8025c56 >> 2) {
        FUN_a00ad86c(DAT_a8025c56 & 3, 0);
        k = DAT_a8025c56 & 3;
        if (k > 3)
            k -= 4;
        for (i = 0; i <= 1; i++)
            FUN_a0146b20(0, i + 4, k * 2 + 5, 1, i + 0x1c, 0);
    } else {
        FUN_a0146c40(4, 0, 0);
    }
}
