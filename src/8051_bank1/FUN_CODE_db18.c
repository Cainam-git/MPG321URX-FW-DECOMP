/* 8051_bank1 FUN_CODE_db18 @ 0xdb18
 * If XDATA 0xD511 == 0x1A and XDATA 0xD510 >= 1: XDATA 0xF06B = 3 then 1 (volatile real: two writes in a row).
 * Only caller 0x3ffa. Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 */
extern unsigned char xdata DAT_EXTMEM_d510, DAT_EXTMEM_d511;
extern unsigned char volatile xdata DAT_EXTMEM_f06b;
void FUN_CODE_db18(void)
{
    if (DAT_EXTMEM_d511 == 0x1a && DAT_EXTMEM_d510 >= 1) {
        DAT_EXTMEM_f06b = 3;
        DAT_EXTMEM_f06b = 1;
    }
}
