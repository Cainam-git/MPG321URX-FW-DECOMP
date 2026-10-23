/* 8051_bank1 FUN_CODE_b679 @ 0xB679..0xB6FE (133 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Prints "\r\n<<<< Flash change to Quad mode!!>>>\r\n" (CODE 0xA2B8), FUN_CODE_d5f3(6), prints
 * "\r\nWrite enable!!\r\n" (CODE 0xA2E0); then XDATA 0xF134 |= 0xC0, 0xF11D |= 0x80, 0xF11D &= 0xBF,
 * 0xF075 |= 0x10, 0xF050 = (0xF050 & 0xDF) | 0x04, 0xF0E6 = (0xF0E6 & 0x0C) | 0x41, 0xF0F4 = 3, 0xF0EB = 0,
 * 0xF0EC = 0, 0xF0ED = 2, 0xF0EE = 1, 0xF1C0 = 0x82, 0xF1C3 = 0x42 then 0, 0xF1C0 = 0x84, 0xF0E5 = 1, waits
 * while bit 0 of 0xF0E5 is set (int-typed test), and stores 0x6B to XDATA 0xA771.
 * The 0xF0xx / 0xF1xx locations are hardware registers (volatile). No aids.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f134, DAT_EXTMEM_f11d, DAT_EXTMEM_f075, DAT_EXTMEM_f050;
extern unsigned char volatile xdata DAT_EXTMEM_f0e5, DAT_EXTMEM_f0e6, DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec;
extern unsigned char volatile xdata DAT_EXTMEM_f0ed, DAT_EXTMEM_f0ee, DAT_EXTMEM_f0f4, DAT_EXTMEM_f1c0, DAT_EXTMEM_f1c3;
extern unsigned char xdata DAT_EXTMEM_a771;
extern void FUN_CODE_2820(void *fmt, ...) large;
void FUN_CODE_d5f3(unsigned char cmd);

void FUN_CODE_b679(void)
{
    FUN_CODE_2820((void code *)0xa2b8);   /* "\r\n<<<< Flash change to Quad mode!!>>>\r\n" */
    FUN_CODE_d5f3(6);
    FUN_CODE_2820((void code *)0xa2e0);   /* "\r\nWrite enable!!\r\n" */
    DAT_EXTMEM_f134 |= 0xc0;
    DAT_EXTMEM_f11d |= 0x80;
    DAT_EXTMEM_f11d &= 0xbf;
    DAT_EXTMEM_f075 |= 0x10;
    DAT_EXTMEM_f050 = (DAT_EXTMEM_f050 & 0xdf) | 0x04;
    DAT_EXTMEM_f0e6 = (DAT_EXTMEM_f0e6 & 0x0c) | 0x41;
    DAT_EXTMEM_f0f4 = 3;
    DAT_EXTMEM_f0eb = 0;
    DAT_EXTMEM_f0ec = 0;
    DAT_EXTMEM_f0ed = 2;
    DAT_EXTMEM_f0ee = 1;
    DAT_EXTMEM_f1c0 = 0x82;
    DAT_EXTMEM_f1c3 = 0x42;
    DAT_EXTMEM_f1c3 = 0;
    DAT_EXTMEM_f1c0 = 0x84;
    DAT_EXTMEM_f0e5 = 1;
    while ((unsigned int)(DAT_EXTMEM_f0e5 & 1)) ;
    DAT_EXTMEM_a771 = 0x6b;
}
