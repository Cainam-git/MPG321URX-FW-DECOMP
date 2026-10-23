/* 8051_bank1 FUN_CODE_c21d @ 0xC21D..0xC278 (91 bytes; unlisted code found in a gap of the function table).
 * Flash command through the F0Ex block: F0E6 = (F0E6 & 0x0C) | 1, F0F4 = 7, F0EA = XDATA 0xF068, F0EB = 0, F0EC = 0,
 * F0ED = 2, F1C0 = 0x81, F0E5 = 2 and wait until F0E5 bit 1 clears, F1C0 = 0x82 and one discarded read of F1C0,
 * then three reads of F1C0 into XDATA 0xF064..0xF066. Compare FUN_CODE_738c (same register sequence).
 * Source forms: the F0E6 value goes through the loop counter i ('i = F0E6 & 0x0C | 1; F0E6 = i;' gives MOV R7,A
 * before the store); the discarded read is the expression statement 'DAT_EXTMEM_f1c0;' (volatile register).
 * No caller in the image. No aids.
 */
extern volatile unsigned char xdata DAT_EXTMEM_f0e5, DAT_EXTMEM_f0e6, DAT_EXTMEM_f0ea, DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed;
extern volatile unsigned char xdata DAT_EXTMEM_f0f4, DAT_EXTMEM_f1c0;
extern unsigned char xdata DAT_EXTMEM_f068;
extern unsigned char xdata DAT_EXTMEM_f064[];
void FUN_CODE_c21d(void)
{
    unsigned char i;
    i = DAT_EXTMEM_f0e6 & 0x0c | 1;
    DAT_EXTMEM_f0e6 = i;
    DAT_EXTMEM_f0f4 = 7;
    DAT_EXTMEM_f0ea = DAT_EXTMEM_f068;
    DAT_EXTMEM_f0eb = 0;
    DAT_EXTMEM_f0ec = 0;
    DAT_EXTMEM_f0ed = 2;
    DAT_EXTMEM_f1c0 = 0x81;
    DAT_EXTMEM_f0e5 = 2;
    while ((unsigned int)(DAT_EXTMEM_f0e5 & 2)) ;
    DAT_EXTMEM_f1c0 = 0x82;
    DAT_EXTMEM_f1c0;
    for (i = 0; i < 3; i++) DAT_EXTMEM_f064[i] = DAT_EXTMEM_f1c0;
}
