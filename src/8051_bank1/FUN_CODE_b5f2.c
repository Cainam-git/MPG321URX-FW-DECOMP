/* 8051_bank1 FUN_CODE_b5f2 @ 0xB5F2..0xB679 (135 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Register sequence on XDATA 0xF0xx / 0xF1xx: 0xF0EA = XDATA 0xA771, 0xF0E6 = (0xF0E6 & 0x0C) | 1, 0xF0EB = 0,
 * 0xF0EC = 2, 0xF0ED = 0, 0xF0F0 / 0xF0F1 / 0xF0F2 = XDATA 0xA74E / 0xA750 / 0xA74F, 0xF0F4 = 0x0B,
 * 0xF1C0 = 0x81, 0xF0E5 = 2, wait while bit 1 of 0xF0E5 is set; 0xF1C0 = 0x82 and XDATA 0xA779 = 0xF1C0 (read
 * back); then the uint at XDATA 0xA74C = the sum of 0x200 reads of 0xF1C0. The wait test is int-typed
 * ('(unsigned int)(x & 2)', ANL/JNZ). The 0xF0xx / 0xF1xx locations are hardware registers (volatile). No aids.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f1c0, DAT_EXTMEM_f0e5, DAT_EXTMEM_f0e6, DAT_EXTMEM_f0ea;
extern unsigned char volatile xdata DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed;
extern unsigned char volatile xdata DAT_EXTMEM_f0f0, DAT_EXTMEM_f0f1, DAT_EXTMEM_f0f2, DAT_EXTMEM_f0f4;
extern unsigned char xdata DAT_EXTMEM_a771, DAT_EXTMEM_a74e, DAT_EXTMEM_a74f, DAT_EXTMEM_a750, DAT_EXTMEM_a779;
extern unsigned int xdata DAT_EXTMEM_a74c;

void FUN_CODE_b5f2(void)
{
    unsigned int i;

    DAT_EXTMEM_f0ea = DAT_EXTMEM_a771;
    DAT_EXTMEM_f0e6 = (DAT_EXTMEM_f0e6 & 0x0c) | 1;
    DAT_EXTMEM_f0eb = 0;
    DAT_EXTMEM_f0ec = 2;
    DAT_EXTMEM_f0ed = 0;
    DAT_EXTMEM_f0f0 = DAT_EXTMEM_a74e;
    DAT_EXTMEM_f0f1 = DAT_EXTMEM_a750;
    DAT_EXTMEM_f0f2 = DAT_EXTMEM_a74f;
    DAT_EXTMEM_f0f4 = 0x0b;
    DAT_EXTMEM_f1c0 = 0x81;
    DAT_EXTMEM_f0e5 = 2;
    while ((unsigned int)(DAT_EXTMEM_f0e5 & 2)) ;
    DAT_EXTMEM_f1c0 = 0x82;
    DAT_EXTMEM_a779 = DAT_EXTMEM_f1c0;
    DAT_EXTMEM_a74c = 0;
    for (i = 0; i < 0x200; i++) DAT_EXTMEM_a74c += DAT_EXTMEM_f1c0;
}
