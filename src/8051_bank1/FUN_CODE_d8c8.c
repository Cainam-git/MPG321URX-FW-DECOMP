/* 8051_bank1 FUN_CODE_d8c8 @ 0xd8c8  MATCH (OPTIMIZE(7,SPEED))
 * Reads xdata 0xA6A6. If it equals 1, writes 0x20 to xdata 0xA66E; otherwise writes 0x10 to 0xA66E, sets bit
 * 0x22.7 (bit address 0x17, BITS_22_7), writes 2 to xdata 0xA781 and calls FUN_CODE_a9f6. Both paths end with
 * FUN_CODE_d4e1(0).
 */
extern unsigned char xdata DAT_EXTMEM_a6a6;
extern unsigned char xdata DAT_EXTMEM_a66e;
extern unsigned char xdata DAT_EXTMEM_a781;
extern bit BITS_22_7;
void FUN_CODE_a9f6(void);
void FUN_CODE_d4e1(unsigned char);

void FUN_CODE_d8c8(void)
{
    if (DAT_EXTMEM_a6a6 == 0x01)
    {
        DAT_EXTMEM_a66e = 0x20;
    }
    else
    {
        DAT_EXTMEM_a66e = 0x10;
        BITS_22_7 = 1;
        DAT_EXTMEM_a781 = 0x02;
        FUN_CODE_a9f6();
    }
    FUN_CODE_d4e1(0);
}
