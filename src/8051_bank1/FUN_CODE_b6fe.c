/* 8051_bank1 FUN_CODE_b6fe @ 0xB6FE..0xB781 (131 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Register sequence on XDATA 0xF0xx / 0xF1xx: 0xF0EA = 0x0B, 0xF0E6 = (0xF0E6 & 0x0C) | 1, 0xF0F4 = 0x0B,
 * 0xF0EB = 0, 0xF0EC = 2, 0xF0ED = 0, 0xF0F0 / 0xF0F1 / 0xF0F2 = XDATA 0xA74E / 0xA750 / 0xA74F, 0xF1C0 = 0x81,
 * 0xF0E5 = 2, wait while bit 1 of 0xF0E5 is set (int-typed test); 0xF1C0 = 0x82 and XDATA 0xA778 = 0xF1C0 (read
 * back); then 0x200 reads of 0xF1C0 are stored through the XDATA byte pointer at 0xA74A, which advances
 * (?C?ILDIX). Counterpart of FUN_CODE_b5f2 (which sums the bytes instead).
 * The 0xF0xx / 0xF1xx locations are hardware registers (volatile). No aids.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f1c0, DAT_EXTMEM_f0e5, DAT_EXTMEM_f0e6, DAT_EXTMEM_f0ea;
extern unsigned char volatile xdata DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed;
extern unsigned char volatile xdata DAT_EXTMEM_f0f0, DAT_EXTMEM_f0f1, DAT_EXTMEM_f0f2, DAT_EXTMEM_f0f4;
extern unsigned char xdata DAT_EXTMEM_a74e, DAT_EXTMEM_a74f, DAT_EXTMEM_a750, DAT_EXTMEM_a778;
extern unsigned char xdata * xdata DAT_EXTMEM_a74a;

void FUN_CODE_b6fe(void)
{
    unsigned int i;

    DAT_EXTMEM_f0ea = 0x0b;
    DAT_EXTMEM_f0e6 = (DAT_EXTMEM_f0e6 & 0x0c) | 1;
    DAT_EXTMEM_f0f4 = 0x0b;
    DAT_EXTMEM_f0eb = 0;
    DAT_EXTMEM_f0ec = 2;
    DAT_EXTMEM_f0ed = 0;
    DAT_EXTMEM_f0f0 = DAT_EXTMEM_a74e;
    DAT_EXTMEM_f0f1 = DAT_EXTMEM_a750;
    DAT_EXTMEM_f0f2 = DAT_EXTMEM_a74f;
    DAT_EXTMEM_f1c0 = 0x81;
    DAT_EXTMEM_f0e5 = 2;
    while ((unsigned int)(DAT_EXTMEM_f0e5 & 2)) ;
    DAT_EXTMEM_f1c0 = 0x82;
    DAT_EXTMEM_a778 = DAT_EXTMEM_f1c0;
    for (i = 0; i < 0x200; i++) *DAT_EXTMEM_a74a++ = DAT_EXTMEM_f1c0;
}
