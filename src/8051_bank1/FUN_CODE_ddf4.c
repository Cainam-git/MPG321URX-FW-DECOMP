/* 8051_bank1 FUN_CODE_ddf4 @ 0xddf4
 * XDATA 0xA3E2 counts 0..3: ++, then reset to 0 when >= 4 (CLR C / SUBB A,#4 / JC). Only caller 0x9329.
 * Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 */
extern unsigned char xdata DAT_EXTMEM_a3e2;
void FUN_CODE_ddf4(void)
{
    DAT_EXTMEM_a3e2++;
    if (DAT_EXTMEM_a3e2 >= 4) DAT_EXTMEM_a3e2 = 0;
}
