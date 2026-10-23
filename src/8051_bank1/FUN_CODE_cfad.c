/* 8051_bank1 FUN_CODE_cfad @ 0xcfad  OPTIMIZE(8,SPEED)
 * For i = 0 .. IDATA 0x4D - 1: while bit 3 of XDATA 0xF0FA is set runs a 100-step delay loop, then writes XDATA
 * 0xA2B0[i] to XDATA 0xF0FB. Then clears IDATA 0x4D and writes 0x55 to XDATA 0xF00A. Same code as FUN_CODE_d021
 * with other addresses. XDATA 0xF0FA is volatile (it is polled). Called from 0x1F87 and 0xDB47.
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
