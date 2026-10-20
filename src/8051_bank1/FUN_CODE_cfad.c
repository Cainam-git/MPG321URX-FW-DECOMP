/* 8051_bank1 FUN_CODE_cfad @ 0xcfad
 * Twin of FUN_CODE_d021: sends IDATA 0x4D bytes from XDATA 0xA2B0[] to XDATA 0xF0FB, waiting while bit 3 of XDATA
 * 0xF0FA is set (volatile real: polled); then IDATA 0x4D = 0 and XDATA 0xF00A = 0x55. Callers 0x1f87, 0xdb47.
 * Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 */
extern unsigned char idata DAT_INTMEM_4d;
extern unsigned char xdata DAT_EXTMEM_a2b0[];
extern unsigned char volatile xdata DAT_EXTMEM_f0fa;
extern unsigned char xdata DAT_EXTMEM_f0fb;
extern unsigned char xdata DAT_EXTMEM_f00a;
void FUN_CODE_cfad(void)
{
    unsigned char i, j;
    for (i = 0; i < DAT_INTMEM_4d; i++) {
        while (DAT_EXTMEM_f0fa & 0x08) {
            for (j = 0; j < 100; j++) ;
        }
        DAT_EXTMEM_f0fb = DAT_EXTMEM_a2b0[i];
    }
    DAT_INTMEM_4d = 0;
    DAT_EXTMEM_f00a = 0x55;
}
