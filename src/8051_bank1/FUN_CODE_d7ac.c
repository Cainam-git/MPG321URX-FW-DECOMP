/* 8051_bank1 FUN_CODE_d7ac @ 0xd7ac
 * XDATA 0xF0A8 = 0x7F then 0x0F, FUN_CODE_d44e(20), 0xF0A8 = 0; returns bit 0 < XDATA 0xF0AD < 10.
 * volatile is real: the firmware writes 0xF0A8 twice in a row and reads 0xF0AD twice (MOVX after each compare).
 * Only caller 0x5337. Byte-exact with OPTIMIZE(8,SPEED).
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0a8;
extern unsigned char volatile xdata DAT_EXTMEM_f0ad;
void FUN_CODE_d44e(unsigned int t);
bit FUN_CODE_d7ac(void)
{
    DAT_EXTMEM_f0a8 = 0x7f;
    DAT_EXTMEM_f0a8 = 0x0f;
    FUN_CODE_d44e(20);
    DAT_EXTMEM_f0a8 = 0;
    return DAT_EXTMEM_f0ad > 0 && DAT_EXTMEM_f0ad < 10;
}
