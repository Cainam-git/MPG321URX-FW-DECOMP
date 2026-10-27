/* 8051_bank1 FUN_CODE_dca7 @ 0xdca7..0xdcbb (20 B)
 * FUN_CODE_d5f3(0x06), FUN_CODE_d5f3(0xC7), then calls FUN_CODE_cf73(0x05) until bit 1 of its result is clear.
 * No LCALL or LJMP to 0xDCA7 occurs in the bank-1 image.
 */
extern void FUN_CODE_d5f3(unsigned char cmd);
extern unsigned char FUN_CODE_cf73(unsigned char cmd);

void FUN_CODE_dca7(void)
{
    FUN_CODE_d5f3(0x06);
    FUN_CODE_d5f3(0xc7);
    while (FUN_CODE_cf73(0x05) & 0x02) ;
}
