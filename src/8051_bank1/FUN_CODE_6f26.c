/* 8051_bank1 FUN_CODE_6f26 @ 0x6f26..0x708c (358 B)  SPI flash: program len bytes from XDATA src to flash address
 * addr in pages of up to 0x100 bytes. OPTIMIZE(8,SPEED) LARGE.
 * Steps: FUN_CODE_dc51(); FUN_CODE_0016(); FUN_CODE_7765(sr) saves the status bytes; a = addr; per page: 0xF1C0 = 0x82,
 * n = min(len, 0x100) (len reduced by n), the n bytes from src go to 0xF1C3, 0xF1C0 = 0x82, FUN_CODE_d5f3(6), wait
 * until bit 1 of FUN_CODE_cf73(5) is set, 0xF0F0..0xF0F2 = bytes 1..3 of a, then the Page Program sequence of
 * FUN_CODE_c5f0 with the count n - 1 in 0xF0EC/0xF0ED (high, low), a += 0x100, wait while bit 0 of FUN_CODE_cf73(5)
 * is set; until len is 0. Then FUN_CODE_b456(sr) and FUN_CODE_dc67(). Callers: FUN_CODE_9fc8, FUN_CODE_d3eb.
 * LARGE block: src 0xA4B6, addr 0xA4B8..0xA4BB, len 0xA4BC..0xA4BD, a 0xA4BE..0xA4C1, n 0xA4C2..0xA4C3,
 * sr 0xA4C4..0xA4C5; i in R6:R7. The 0xF0xx / 0xF1xx locations are hardware registers (volatile).
 * Source forms: the f0e5 wait is FUN_CODE_c5f0's 'for (;;) if (!(unsigned int)(f0e5 & 1)) break;' (CLR A before
 *   'f1c0 = 0'); the high count byte is '(unsigned int)(unsigned long)n >> 8': with the long conversion Keil loads n
 *   into R2:R3 as for a long operand, and the conversion back to int leaves an int shift ('MOV A,R2'), as in
 *   the firmware; the low byte is 'n & 0xff'.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f1c0, DAT_EXTMEM_f1c1, DAT_EXTMEM_f1c2, DAT_EXTMEM_f1c3;
extern unsigned char volatile xdata DAT_EXTMEM_f0e5, DAT_EXTMEM_f0e6, DAT_EXTMEM_f0ea, DAT_EXTMEM_f0eb;
extern unsigned char volatile xdata DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed, DAT_EXTMEM_f0ee;
extern unsigned char volatile xdata DAT_EXTMEM_f0f0, DAT_EXTMEM_f0f1, DAT_EXTMEM_f0f2, DAT_EXTMEM_f0f4;
void FUN_CODE_dc51(void);
void FUN_CODE_0016(void);
void FUN_CODE_7765(unsigned char *p);
void FUN_CODE_b456(unsigned char *p);
void FUN_CODE_dc67(void);
void FUN_CODE_d5f3(unsigned char cmd);
unsigned char FUN_CODE_cf73(unsigned char cmd);

void FUN_CODE_6f26(unsigned char xdata *src, unsigned long addr, unsigned int len)
{
    union { unsigned long l; unsigned char b[4]; } a;
    unsigned int n;
    unsigned char sr[2];
    unsigned int i;

    FUN_CODE_dc51();
    FUN_CODE_0016();
    FUN_CODE_7765(sr);
    a.l = addr;
    do {
        DAT_EXTMEM_f1c0 = 0x82;
        if (len >= 0x100) {
            n = 0x100;
            len -= 0x100;
        } else {
            n = len;
            len = 0;
        }
        for (i = 0; i < n; i++) DAT_EXTMEM_f1c3 = *src++;
        DAT_EXTMEM_f1c0 = 0x82;
        FUN_CODE_d5f3(6);
        while (!(FUN_CODE_cf73(5) & 2)) ;
        DAT_EXTMEM_f0f0 = a.b[1];
        DAT_EXTMEM_f0f1 = a.b[2];
        DAT_EXTMEM_f0f2 = a.b[3];
        DAT_EXTMEM_f0e6 = (DAT_EXTMEM_f0e6 & 0x0c) | 1;
        DAT_EXTMEM_f0f4 = 3;
        DAT_EXTMEM_f0ea = 2;
        n--;
        DAT_EXTMEM_f0eb = 0;
        DAT_EXTMEM_f0ec = (unsigned int)(unsigned long)n >> 8; DAT_EXTMEM_f0ed = n & 0xff;
        DAT_EXTMEM_f1c0 = 2;
        DAT_EXTMEM_f1c0;
        DAT_EXTMEM_f0ee = DAT_EXTMEM_f1c0;
        DAT_EXTMEM_f1c2 = DAT_EXTMEM_f1c2;
        DAT_EXTMEM_f1c1 = 1;
        DAT_EXTMEM_f1c0 = 4;
        DAT_EXTMEM_f0e5 = 1;
        for (;;) if (!(unsigned int)(DAT_EXTMEM_f0e5 & 1)) break;
        DAT_EXTMEM_f1c0 = 0;
        a.l += 0x100;
        while (FUN_CODE_cf73(5) & 1) ;
    } while (len != 0);
    FUN_CODE_b456(sr);
    FUN_CODE_dc67();
}
