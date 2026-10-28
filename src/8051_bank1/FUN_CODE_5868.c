/* 8051_bank1 module FUN_CODE_5868: FUN_CODE_5868 @ 0x5868..0x5A39 (with the common-entry block FUN_CODE_5864
 * @ 0x5864..0x5868) and FUN_CODE_38a7 @ 0x38A7..0x3C4D, OPTIMIZE(8,SPEED) LARGE.
 * One Keil module (code): the block 0x5864 'MOV R2,#0A4H / MOV R1,#97H' loads the low two bytes of the generic
 *   pointer &buf (XDATA 0xA497, a LARGE local of FUN_CODE_38a7) and falls into FUN_CODE_5868; its only users are
 *   the three calls in FUN_CODE_38a7 (0x3A67, 0x3BBC, 0x3C49). Keil builds such a block only from calls inside
 *   the same module.
 * FUN_CODE_5868(p, q, n): LARGE parameters p (generic pointer, XDATA 0xA517..0xA519), q (generic pointer to
 *   unsigned long, 0xA51A..0xA51C), n (uint, 0xA51D..0xA51E); locals i 0xA51F, cnt 0xA520. cnt = (n + 3) >> 2;
 *   for each i < cnt the four bytes p[4i]..p[4i+3] are packed into q[i], first byte most significant
 *   (each step q[i] = (q[i] << 8) + p[...], through ?C?LLDOPTR / ?C?LSHL / ?C?LSTOPTR).
 * FUN_CODE_38a7(): LARGE locals i 0xA494, j 0xA495, ch 0xA496, buf[128] 0xA497..0xA516. Returns unless
 *   FUN_CODE_de12() is set. Then the first of these that applies fills buf, stores the source type in XDATA
 *   0xA3E7, the byte count in the uint 0xA3EA, (count + 3) >> 2 in 0xA3E5 and 0 in 0xA3E6, and passes buf, the
 *   unsigned long array at 0xA3EC and the count to FUN_CODE_5868:
 *   - FUN_CODE_de92() clear: ch = FUN_CODE_d90a() (0xFF: return). Only when IDATA 0x2A[ch] is not 0 (ch even) or
 *     not 0x3B (ch odd): type 4; ch odd: buf[j] = XDATA (0xA0F4 + (ch >> 1) * 0x3C)[i] for i = 0x3B down to
 *     IDATA 0x2A[ch] + 1; ch even: buf[i] = the same row [i] for i < IDATA 0x2A[ch]. 0xA3E8 = ch, 0xA3E9 = 2,
 *     FUN_CODE_dbc8(ch).
 *   - FUN_CODE_de50() clear, ch = FUN_CODE_ce87() not 0xFF and FUN_CODE_ddb6(ch) clear: type 3, count =
 *     FUN_CODE_6917(ch, buf), 0xA3E8 = ch; after the FUN_CODE_5868 call 0xA3E3 |= 1 << ch.
 *   - FUN_CODE_de9c() set: type 1, buf[i] = XDATA 0xF800[i + (0xA46D << 4)] for i < 0xA46C; count = 0xA46C;
 *     then 0xA46C = 0xA46D = 0.
 *   - FUN_CODE_de5b() clear: type 2, buf[i] = XDATA 0xA362[i] for i < 0xA46E; count = 0xA46E; 0xA3E8 = 0xA3E4,
 *     0xA3E9 = 2; after the FUN_CODE_5868 call 0xA35F = 0.
 *   - FUN_CODE_dea6() clear: prints "Reload IR\r\n" (CODE 0x55E9); type 5; for i < 0x80 until FUN_CODE_dce3()
 *     returns non-zero: buf[i] = FUN_CODE_d697(); count = i.
 *   The XDATA bytes 0xA3E3..0xA46E are one structure (Keil addresses 0xA3E5/0xA3E6, 0xA3E8/0xA3E9 and
 *   0xA46C/0xA46D with INC DPTR, as for members of one object); the field names describe positions only.
 * Source form (FUN_CODE_38a7, 'mask |= 1 << ch'): the mask byte and ch are copied to locals m and c.
 */
struct rec_a3e3 {
    unsigned char mask;         /* 0xA3E3 */
    unsigned char e4;           /* 0xA3E4 */
    unsigned char words;        /* 0xA3E5 */
    unsigned char e6;           /* 0xA3E6 */
    unsigned char type;         /* 0xA3E7 */
    unsigned char ch;           /* 0xA3E8 */
    unsigned char e9;           /* 0xA3E9 */
    unsigned int len;           /* 0xA3EA */
    unsigned long d[32];        /* 0xA3EC */
    unsigned char cnt;          /* 0xA46C */
    unsigned char off;          /* 0xA46D */
    unsigned char n2;           /* 0xA46E */
};
extern struct rec_a3e3 xdata DAT_EXTMEM_a3e3;
extern unsigned char xdata DAT_EXTMEM_a0f4[4][0x3c];
extern unsigned char xdata DAT_EXTMEM_f800[];
extern unsigned char xdata DAT_EXTMEM_a362[];
extern unsigned char xdata DAT_EXTMEM_a35f;
extern unsigned char idata DAT_INTMEM_2a[];
extern void FUN_CODE_2820(void *fmt, ...) large;
bit FUN_CODE_de12(void);
bit FUN_CODE_de92(void);
unsigned char FUN_CODE_d90a(void);
bit FUN_CODE_de50(void);
unsigned char FUN_CODE_ce87(void);
bit FUN_CODE_ddb6(unsigned char n);
bit FUN_CODE_de9c(void);
bit FUN_CODE_de5b(void);
bit FUN_CODE_dea6(void);
unsigned char FUN_CODE_dce3(void);
unsigned char FUN_CODE_d697(void);
unsigned char FUN_CODE_6917(unsigned char ch, unsigned char *buf);
void FUN_CODE_dbc8(unsigned char n);
void FUN_CODE_5868(unsigned char *p, unsigned long *q, unsigned int n);

void FUN_CODE_38a7(void)
{
    unsigned char i, j, ch;
    unsigned char buf[128];
    unsigned int w;
    unsigned char m, c;

    ch = 0xff;
    if (!FUN_CODE_de12()) return;
    if (!FUN_CODE_de92()) {
        ch = FUN_CODE_d90a();
        if (ch == 0xff) return;
        if ((!(ch & 1) && DAT_INTMEM_2a[ch] != 0) || ((ch & 1) && DAT_INTMEM_2a[ch] != 0x3b)) {
            DAT_EXTMEM_a3e3.type = 4;
            if (ch & 1) {
                for (i = 0x3b, j = 0; i > DAT_INTMEM_2a[ch]; i--, j++)
                    buf[j] = DAT_EXTMEM_a0f4[ch >> 1][i];
            } else {
                for (i = 0, j = 0; i < DAT_INTMEM_2a[ch]; i++, j++)
                    buf[i] = DAT_EXTMEM_a0f4[ch >> 1][i];
            }
            DAT_EXTMEM_a3e3.len = j;
            DAT_EXTMEM_a3e3.words = (DAT_EXTMEM_a3e3.len + 3) >> 2;
            DAT_EXTMEM_a3e3.e6 = 0;
            DAT_EXTMEM_a3e3.ch = ch;
            DAT_EXTMEM_a3e3.e9 = 2;
            FUN_CODE_dbc8(ch);
            FUN_CODE_5868(buf, DAT_EXTMEM_a3e3.d, DAT_EXTMEM_a3e3.len);
        }
    } else if (!FUN_CODE_de50() && (ch = FUN_CODE_ce87()) != 0xff && !FUN_CODE_ddb6(ch)) {
        DAT_EXTMEM_a3e3.type = 3;
        DAT_EXTMEM_a3e3.len = FUN_CODE_6917(ch, buf);
        DAT_EXTMEM_a3e3.words = (DAT_EXTMEM_a3e3.len + 3) >> 2;
        DAT_EXTMEM_a3e3.e6 = 0;
        DAT_EXTMEM_a3e3.ch = ch;
        FUN_CODE_5868(buf, DAT_EXTMEM_a3e3.d, DAT_EXTMEM_a3e3.len);
        m = DAT_EXTMEM_a3e3.mask;
        c = ch;
        DAT_EXTMEM_a3e3.mask = m | (1 << c);
    } else if (FUN_CODE_de9c()) {
        DAT_EXTMEM_a3e3.type = 1;
        w = DAT_EXTMEM_a3e3.off;
        for (i = 0; i < DAT_EXTMEM_a3e3.cnt; i++)
            buf[i] = DAT_EXTMEM_f800[i + (w << 4)];
        DAT_EXTMEM_a3e3.len = DAT_EXTMEM_a3e3.cnt;
        DAT_EXTMEM_a3e3.words = (DAT_EXTMEM_a3e3.len + 3) >> 2;
        DAT_EXTMEM_a3e3.e6 = 0;
        DAT_EXTMEM_a3e3.cnt = 0;
        DAT_EXTMEM_a3e3.off = 0;
        FUN_CODE_5868(buf, DAT_EXTMEM_a3e3.d, DAT_EXTMEM_a3e3.len);
    } else if (!FUN_CODE_de5b()) {
        DAT_EXTMEM_a3e3.type = 2;
        for (i = 0; i < DAT_EXTMEM_a3e3.n2; i++)
            buf[i] = DAT_EXTMEM_a362[i];
        DAT_EXTMEM_a3e3.len = DAT_EXTMEM_a3e3.n2;
        DAT_EXTMEM_a3e3.words = (DAT_EXTMEM_a3e3.len + 3) >> 2;
        DAT_EXTMEM_a3e3.e6 = 0;
        DAT_EXTMEM_a3e3.ch = DAT_EXTMEM_a3e3.e4;
        DAT_EXTMEM_a3e3.e9 = 2;
        FUN_CODE_5868(buf, DAT_EXTMEM_a3e3.d, DAT_EXTMEM_a3e3.len);
        DAT_EXTMEM_a35f = 0;
    } else if (!FUN_CODE_dea6()) {
        FUN_CODE_2820((void code *)0x55e9);   /* "Reload IR\r\n" */
        DAT_EXTMEM_a3e3.type = 5;
        for (i = 0; i < 0x80; i++) {
            if (FUN_CODE_dce3() != 0) break;
            buf[i] = FUN_CODE_d697();
        }
        DAT_EXTMEM_a3e3.len = i;
        DAT_EXTMEM_a3e3.words = (DAT_EXTMEM_a3e3.len + 3) >> 2;
        DAT_EXTMEM_a3e3.e6 = 0;
        FUN_CODE_5868(buf, DAT_EXTMEM_a3e3.d, DAT_EXTMEM_a3e3.len);
    }
}

void FUN_CODE_5868(unsigned char *p, unsigned long *q, unsigned int n)
{
    unsigned char i, cnt;

    cnt = (n + 3) >> 2;
    for (i = 0; i < cnt; i++) {
        q[i] = p[i * 4];
        q[i] = (q[i] << 8) + p[i * 4 + 1];
        q[i] = (q[i] << 8) + p[i * 4 + 2];
        q[i] = (q[i] << 8) + p[i * 4 + 3];
    }
}
