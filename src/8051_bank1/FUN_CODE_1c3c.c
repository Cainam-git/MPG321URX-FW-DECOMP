/* 8051_bank1 FUN_CODE_1c3c @ 0x1C3C..0x224F (1555 bytes), OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_1c3c(p): p is a generic pointer to a record of unsigned long words (caller FUN_CODE_9243 at 0x92A4
 * passes the 5-word buffer at XDATA 0xA47A). LARGE parameter p at XDATA 0xA48E..0xA490; locals type 0xA491,
 * b1 0xA492, b2 0xA493, n 0xA494, b3 0xA495, i 0xA496, w 0xA497..0xA498 (uint), buf[16] 0xA499..0xA4A8.
 * Word p[0] gives type = bits 3..0, b1 = bits 7..4, b2 = bits 15..8, n = bits 23..16 (limited to 0x10),
 * b3 = bits 31..24 (each read with ?C?LLDPTR and shifted with ?C?ULSHR); then XDATA 0xF00A = 0x55,
 * FUN_CODE_8072(buf, p + 1, n) copies n bytes of the following words to buf, and w = b3 << 4.
 * Switch on type (jump table 0x1D0B, 15 LJMPs; types 5, 12, 13, 14 and others return):
 *   1: n + w <= 0x800: XDATA 0xF800[w + i] = buf[i]; else prints "EDID address out of range!\r\n" (CODE 0x5582).
 *   2: n + w > 0x80: prints "DATA_I2C OOR\r\n" (CODE 0x559F), returns when w >= 0x80, else n = 0x80 - w.
 *      b2 bit 7 clear: XDATA 0xA360[w + i] = buf[i]; set: 0xA360 = buf[0], 0xA361 = buf[1]. Then, when b1 bit 0
 *      is set: b2 bit 7 clear: w = w + n - 2, FUN_CODE_50c9(b2, A360, A361, &A362, w), clear 0xA360..0xA36F;
 *      b2 bit 7 set: b2 &= 0x7F, w = 1 when it is 0, FUN_CODE_83f3(b2, A360, A361, &A362, w), XDATA 0xA3E4 = b2,
 *      0xA35F = 1, 0xA46E = low byte of w.
 *   3: b2 = 1 / 2 / 3 / 4: each buf[i] to FUN_CODE_d511 / db32 / db4b / db64; for 2, 3, 4 then FUN_CODE_cfad /
 *      cfe7 / d021 when b1 bit 0 is set.
 *   4: n + w > 0x3C: prints "DATA_DDCCI OOR\r\n" (CODE 0x55AE), returns when w >= 2, else n = 2 - w.
 *      b2 odd: XDATA (0xA001 + (b2 >> 1) * 0x3C)[0x3C - (i + w)] = buf[i]; b2 even: (0xA002 + (b2 >> 1) * 0x3C)
 *      [w + i] = buf[i]. When b1 bit 0 is set: IDATA 0x32[b2] = 0x3B - (w + n) (b2 odd) or w + n (b2 even).
 *   6: FUN_CODE_224f(p[i + 1]) for i < n / 4.     7: FUN_CODE_a36c(b2 + w, n, buf), FUN_CODE_dbdf(FUN_CODE_b781()).
 *   8 / 9 / 10: FUN_CODE_9053 / b3cb / a819 (w, n, buf).     11: FUN_CODE_74af(buf).
 *   15: prints "DataTest %08lx, %08lx, %08lx, %08lx %08lx" (CODE 0x55BF) with p[0], p[1], p[2], p[3], p[3].
 * Source forms: the 0xA001 / 0xA002 arrays are declared with a fixed size ([4][0x3C], 240 bytes), which makes
 * Keil compute the row offset in 8 bits (MUL AB, CLR A / ADDC); the empty statement 'if (!(b1 & 1)) ;' at the
 * end of type 4 gives the firmware's second test of b1 bit 0 (JNB to a RET, else LJMP to the shared RET).
 * 0xF00A is a hardware register (volatile).
 */
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
extern unsigned char xdata DAT_EXTMEM_f800[];
extern unsigned char xdata DAT_EXTMEM_a360[];
extern unsigned char xdata DAT_EXTMEM_a001[4][0x3c];
extern unsigned char xdata DAT_EXTMEM_a002[4][0x3c];
extern unsigned char xdata DAT_EXTMEM_a3e4, DAT_EXTMEM_a35f, DAT_EXTMEM_a46e;
extern unsigned long xdata DAT_EXTMEM_a51a, DAT_EXTMEM_a51e, DAT_EXTMEM_a522, DAT_EXTMEM_a526, DAT_EXTMEM_a52a;
extern unsigned char idata DAT_INTMEM_32[];
extern void FUN_CODE_2820(void *fmt, ...) large;
extern void FUN_CODE_8072(unsigned char *dst, unsigned char *src, unsigned int n);
extern void FUN_CODE_50c9(unsigned char a, unsigned char b, unsigned char c, unsigned char *p, unsigned int n);
extern void FUN_CODE_83f3(unsigned char a, unsigned char b, unsigned int c, unsigned char *p, unsigned int n);
extern unsigned char FUN_CODE_d511(unsigned char c);
extern void FUN_CODE_db32(unsigned char v);
extern void FUN_CODE_db4b(unsigned char v);
extern void FUN_CODE_db64(unsigned char v);
extern void FUN_CODE_cfad(void);
extern void FUN_CODE_cfe7(void);
extern void FUN_CODE_d021(void);
extern void FUN_CODE_224f(unsigned long p);
extern void FUN_CODE_a36c(unsigned int off, unsigned int n, unsigned char *p);
extern unsigned long FUN_CODE_b781(void);
extern void FUN_CODE_dbdf(unsigned long v);
extern void FUN_CODE_9053(unsigned int off, unsigned char n, unsigned char *p);
extern void FUN_CODE_b3cb(unsigned int off, unsigned char n, unsigned char *p);
extern void FUN_CODE_a819(unsigned int off, unsigned char n, unsigned char *p);
extern void FUN_CODE_74af(unsigned char *p);

void FUN_CODE_1c3c(unsigned long *p)
{
    unsigned char type, b1, b2, n, b3, i;
    unsigned int w;
    unsigned char buf[16];

    type = *p & 0x0f;
    b1 = (*p & 0xf0) >> 4;
    b2 = *p >> 8;
    n = *p >> 16;
    b3 = *p >> 24;
    DAT_EXTMEM_f00a = 0x55;
    if (n > 0x10) n = 0x10;
    FUN_CODE_8072(buf, (unsigned char *)(p + 1), n);
    w = b3;
    w <<= 4;
    switch (type) {
    case 1:
        if (n + w <= 0x800) {
            for (i = 0; i < n; i++) DAT_EXTMEM_f800[w + i] = buf[i];
        } else {
            FUN_CODE_2820((void code *)0x5582);
        }
        break;
    case 2:
        if (n + w > 0x80) {
            FUN_CODE_2820((void code *)0x559f);
            if (w >= 0x80) return;
            n = 0x80 - w;
        }
        if (!(b2 & 0x80)) {
            for (i = 0; i < n; i++) DAT_EXTMEM_a360[w + i] = buf[i];
        } else {
            DAT_EXTMEM_a360[0] = buf[0];
            DAT_EXTMEM_a360[1] = buf[1];
        }
        if (!(b1 & 1)) break;
        if (!(b2 & 0x80)) {
            w = w + n - 2;
            FUN_CODE_50c9(b2, DAT_EXTMEM_a360[0], DAT_EXTMEM_a360[1], &DAT_EXTMEM_a360[2], w);
            for (i = 0; i < 0x10; i++) DAT_EXTMEM_a360[i] = 0;
        } else {
            b2 &= 0x7f;
            if (w == 0) w = 1;
            FUN_CODE_83f3(b2, DAT_EXTMEM_a360[0], DAT_EXTMEM_a360[1], &DAT_EXTMEM_a360[2], w);
            DAT_EXTMEM_a3e4 = b2;
            DAT_EXTMEM_a35f = 1;
            DAT_EXTMEM_a46e = w;
        }
        break;
    case 3:
        if (b2 == 1) {
            for (i = 0; i < n; i++) FUN_CODE_d511(buf[i]);
        } else if (b2 == 2) {
            for (i = 0; i < n; i++) FUN_CODE_db32(buf[i]);
            if (b1 & 1) FUN_CODE_cfad();
        } else if (b2 == 3) {
            for (i = 0; i < n; i++) FUN_CODE_db4b(buf[i]);
            if (b1 & 1) FUN_CODE_cfe7();
        } else if (b2 == 4) {
            for (i = 0; i < n; i++) FUN_CODE_db64(buf[i]);
            if (b1 & 1) FUN_CODE_d021();
        }
        break;
    case 4:
        if (n + w > 0x3c) {
            FUN_CODE_2820((void code *)0x55ae);
            if (w >= 2) return;
            n = 2 - w;
        }
        if (b2 & 1) {
            for (i = 0; i < n; i++) DAT_EXTMEM_a001[b2 >> 1][0x3c - (w + i)] = buf[i];
        } else {
            for (i = 0; i < n; i++) DAT_EXTMEM_a002[b2 >> 1][w + i] = buf[i];
        }
        if (b1 & 1) {
            if (b2 & 1) DAT_INTMEM_32[b2] = 0x3b - (w + n);
            else DAT_INTMEM_32[b2] = w + n;
        }
        if (!(b1 & 1)) ;
        break;
    case 6:
        for (i = 0; i < n / 4; i++) FUN_CODE_224f(p[i + 1]);
        break;
    case 7:
        FUN_CODE_a36c(b2 + w, n, buf);
        FUN_CODE_dbdf(FUN_CODE_b781());
        break;
    case 8:
        FUN_CODE_9053(w, n, buf);
        break;
    case 9:
        FUN_CODE_b3cb(w, n, buf);
        break;
    case 10:
        FUN_CODE_a819(w, n, buf);
        break;
    case 11:
        FUN_CODE_74af(buf);
        break;
    case 15:
        FUN_CODE_2820((void code *)0x55bf, p[0], p[1], p[2], p[3], p[3]);
        break;
    }
}
