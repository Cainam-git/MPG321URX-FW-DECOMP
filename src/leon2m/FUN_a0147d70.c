/* FUN_a0147d70 (leon2m 0xa0147d70-0xa0147fb4, 580 bytes), flags -mcpu=v8 -O3 -g.
 * int (void). name = FUN_a0124174(); len = index of the first zero byte in name[0..0x2c] (0x2c when none),
 * printed with "TotalFileNameLen = %d". Returns 5 when len > 0x27. Writes 0x5a, then 0x5b, to register
 * 0xcf03c660, waits each time until it reads back different, and assembles a and b from the bytes of registers
 * 0xcf03c678 / 674 / 670 / 66c (high to low). Between FUN_a0115644(1) and FUN_a0115644(0) it adds up the bytes
 * of a >> 5 blocks of 32 bytes read with FUN_a011403c(buf, b + i, 1, 0) (16-bit sum, printed as "checksum").
 * chk = the four values FUN_a0123c4c(name[len - 8 .. len - 5]) as nibbles 12 / 8 / 4 / 0, printed as
 * "FileNameChkSum". Returns 2 when the sum equals chk, else 3 (the caller keeps the low byte).
 * Source form: the result r is set to 2 before the last print call and changed to 3 after it, so the
 * final compare stays a branch (a set right before the test would be if-converted).
 */
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned char *FUN_a0124174(void);
extern void FUN_a0115644(unsigned char on);
extern void FUN_a011403c(unsigned char *out, unsigned int addr, unsigned char n, unsigned char mode);
extern unsigned char FUN_a0123c4c(int ch);

#define R(a) (*(volatile unsigned int *)(a))

int FUN_a0147d70(void)
{
    unsigned char *name = FUN_a0124174();
    unsigned char buf[32];
    unsigned char k, j, len = 0;
    unsigned int a, b, n, i;
    unsigned short sum, chk;
    int r;

    for (k = 0; k <= 0x2c; k++) {
        if (name[k] == 0) {
            len = k;
            break;
        }
        if (k == 0x2c)
            len = k;
    }
    FUN_a00df170("TotalFileNameLen = %d\r\n", len);
    if (len > 0x27)
        return 5;
    R(0xcf03c660) = 0x5a;
    while (R(0xcf03c660) == 0x5a)
        ;
    a = (R(0xcf03c678) << 24) + (R(0xcf03c674) << 16) + (R(0xcf03c670) << 8) + R(0xcf03c66c);
    R(0xcf03c660) = 0x5b;
    while (R(0xcf03c660) == 0x5b)
        ;
    b = (R(0xcf03c678) << 24) + (R(0xcf03c674) << 16) + (R(0xcf03c670) << 8) + R(0xcf03c66c);
    FUN_a0115644(1);
    n = a >> 5;
    sum = 0;
    for (i = 0; i < n; i++) {
        FUN_a011403c(buf, b + i, 1, 0);
        for (j = 0; j <= 0x1f; j++)
            sum += buf[j];
    }
    FUN_a00df170("checksum = %x\r\n", sum);
    FUN_a0115644(0);
    chk = FUN_a0123c4c(name[len - 8]) << 12 | FUN_a0123c4c(name[len - 7]) << 8 | FUN_a0123c4c(name[len - 6]) << 4
        | FUN_a0123c4c(name[len - 5]);
    r = 2;
    FUN_a00df170("FileNameChkSum = %x\r\n", chk);
    if (sum != chk)
        r = 3;
    return r;
}
