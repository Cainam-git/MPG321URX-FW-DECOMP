/* 8051_bank1 FUN_CODE_8d60 @ 0x8d60..0x8e61 (257 bytes), OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_8d60(a, len, c): XDATA 0xF60A = 0xF60B = 0; 0xF60C / 0xF60D = low / next byte of len / 4 (?C?ULDIV);
 * 0xF60E = c. When bit 0x02 (BITS_20_2) is set, FUN_CODE_d81c gets bits 31..24 of a. Then 0xF600 = 0x40,
 * 0xF0EA = XDATA 0xA771, 0xF0E6 = (0xF0E6 & 0x0C) | 1, bytes 1..3 of len (most significant first, through the
 * union t) to 0xF0EB..0xF0ED and of a to 0xF0F0..0xF0F2, 0xF0F4 = 3, 0xF1C0 = 0, 0xF0E5 = 2; waits until bit 1 of
 * 0xF0E5 clears, then 0xF601 = 0x40 and 0xF600 = 0.
 * LARGE slots: a 0xA4EA, len 0xA4EE, c 0xA4F2, t 0xA4F3 (stored with ?C?LSTXDATA, read back byte by byte).
 * volatile only on 0xF0E5 (polled). Source form: the poll test is int-typed for the firmware's ANL / JNZ.
 * Caller: FUN_CODE_c43e (LCALL at 0xC489).
 */
typedef union { unsigned long l; unsigned char b[4]; } DW;
extern unsigned char xdata DAT_EXTMEM_f60a, DAT_EXTMEM_f60b, DAT_EXTMEM_f60c, DAT_EXTMEM_f60d, DAT_EXTMEM_f60e;
extern unsigned char xdata DAT_EXTMEM_f600, DAT_EXTMEM_f601;
extern unsigned char volatile xdata DAT_EXTMEM_f0e5;
extern unsigned char xdata DAT_EXTMEM_f0e6, DAT_EXTMEM_f0ea;
extern unsigned char xdata DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed;
extern unsigned char xdata DAT_EXTMEM_f0f0, DAT_EXTMEM_f0f1, DAT_EXTMEM_f0f2, DAT_EXTMEM_f0f4;
extern unsigned char xdata DAT_EXTMEM_f1c0;
extern unsigned char xdata DAT_EXTMEM_a771;
extern bit BITS_20_2;
extern void FUN_CODE_d81c(unsigned char ext);

void FUN_CODE_8d60(unsigned long a, unsigned long len, unsigned char c)
{
    DW t;

    DAT_EXTMEM_f60a = 0;
    DAT_EXTMEM_f60b = 0;
    DAT_EXTMEM_f60c = len / 4;
    DAT_EXTMEM_f60d = (len / 4) >> 8;
    DAT_EXTMEM_f60e = c;
    if (BITS_20_2)
        FUN_CODE_d81c((unsigned char)((a >> 24) & 0xff));
    DAT_EXTMEM_f600 = 0x40;
    DAT_EXTMEM_f0ea = DAT_EXTMEM_a771;
    DAT_EXTMEM_f0e6 = (DAT_EXTMEM_f0e6 & 0x0c) | 0x01;
    t.l = len;
    DAT_EXTMEM_f0eb = t.b[1];
    DAT_EXTMEM_f0ec = t.b[2];
    DAT_EXTMEM_f0ed = t.b[3];
    t.l = a;
    DAT_EXTMEM_f0f0 = t.b[1];
    DAT_EXTMEM_f0f1 = t.b[2];
    DAT_EXTMEM_f0f2 = t.b[3];
    DAT_EXTMEM_f0f4 = 0x03;
    DAT_EXTMEM_f1c0 = 0;
    DAT_EXTMEM_f0e5 = 0x02;
    while ((unsigned int)(DAT_EXTMEM_f0e5 & 0x02))
        ;
    DAT_EXTMEM_f601 = 0x40;
    DAT_EXTMEM_f600 = 0;
}
