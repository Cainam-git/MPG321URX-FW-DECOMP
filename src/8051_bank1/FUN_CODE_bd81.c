/* 8051_bank1 FUN_CODE_bd81 @ 0xbd81  SPI flash: program one 256-byte page (byte-exact with
 * OPTIMIZE(8,SPEED) LARGE).
 * LARGE memory model: the three parameters are stored by the compiler in this function's XDATA block at 0xA4BA..
 * 0xA4BC (Keil's ?_FUN_CODE_bd81?BYTE; overlaid with other functions' blocks, so 0xA4B3.. are not real globals).
 * (hi, mid, lo) = 24-bit flash address. Between FUN_CODE_dc51 / FUN_CODE_dc67 (called around every flash operation
 * of the update loop): copies the 256 bytes at XDATA 0x3200 into the SPI write buffer (0xF1C0 = 0x82, 256 writes to
 * 0xF1C3, 0xF1C0 = 0x81), Write Enable (06h) and wait for WEL, address into 0xF0F0..0xF0F2, FUN_CODE_c5f0 (issues
 * SPI command 02h = Page Program), then waits while WIP (status bit 0).
 * Used by the STBC update loop FUN_CODE_6c34 (commands 2 and 5). Boot/update path.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f1c0, DAT_EXTMEM_f1c3, DAT_EXTMEM_f0f0, DAT_EXTMEM_f0f1, DAT_EXTMEM_f0f2;
extern void FUN_CODE_dc51(void);
extern void FUN_CODE_dc67(void);
extern void FUN_CODE_d5f3(unsigned char cmd);
extern unsigned char FUN_CODE_cf73(unsigned char cmd);
extern void FUN_CODE_c5f0(void);
void FUN_CODE_bd81(unsigned char hi, unsigned char mid, unsigned char lo)
{
    unsigned char xdata *p;
    unsigned char i;
    FUN_CODE_dc51();
    p = (unsigned char xdata *)0x3200;
    DAT_EXTMEM_f1c0 = 0x82;
    i = 0;
    do {
        DAT_EXTMEM_f1c3 = p[i++];
    } while (i);
    DAT_EXTMEM_f1c0 = 0x81;
    FUN_CODE_d5f3(6);
    while (!(FUN_CODE_cf73(5) & 2)) ;
    DAT_EXTMEM_f0f0 = hi;
    DAT_EXTMEM_f0f1 = mid;
    DAT_EXTMEM_f0f2 = lo;
    FUN_CODE_c5f0();
    while (FUN_CODE_cf73(5) & 1) ;
    FUN_CODE_dc67();
}
