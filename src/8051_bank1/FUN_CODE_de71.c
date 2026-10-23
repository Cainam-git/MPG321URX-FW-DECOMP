/* 8051_bank1 FUN_CODE_de71 @ 0xde71  OPTIMIZE(7,SPEED)
 * Writes 0x88 to XDATA 0xD507 and 0xD508: two direct MOVX stores, no calls.
 */
extern xdata unsigned char DAT_EXTMEM_d507;
extern xdata unsigned char DAT_EXTMEM_d508;

void FUN_CODE_de71(void)
{
    DAT_EXTMEM_d507 = 0x88;
    DAT_EXTMEM_d508 = 0x88;
}
