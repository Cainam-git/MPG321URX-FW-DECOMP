/* 8051_bank1 FUN_CODE_d021 @ 0xd021
 * Sends IDATA 0x53 bytes from XDATA 0xA320[] to XDATA 0xF073; before each byte waits while bit 3 of XDATA 0xF072 is set
 * (100-step empty loop per poll); then IDATA 0x53 = 0 and XDATA 0xF00A = 0x55. volatile is real for 0xF072 (polled).
 * Twin of FUN_CODE_cfad (0x4D / 0xA2B0 / 0xF0FA / 0xF0FB). Callers 0x2006, 0xd847, 0xdb79.
 * Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 */
extern unsigned char idata DAT_INTMEM_53;
extern unsigned char xdata DAT_EXTMEM_a320[];
extern unsigned char volatile xdata DAT_EXTMEM_f072;
extern unsigned char xdata DAT_EXTMEM_f073;
extern unsigned char xdata DAT_EXTMEM_f00a;
void FUN_CODE_d021(void)
{
    unsigned char i, j;
    for (i = 0; i < DAT_INTMEM_53; i++) {
        while (DAT_EXTMEM_f072 & 0x08) {
            for (j = 0; j < 100; j++) ;
        }
        DAT_EXTMEM_f073 = DAT_EXTMEM_a320[i];
    }
    DAT_INTMEM_53 = 0;
    DAT_EXTMEM_f00a = 0x55;
}
