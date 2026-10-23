/* 8051_bank1 FUN_CODE_d5c8 @ 0xd5c8  OPTIMIZE(7,SPEED)
 * XDATA 0xD929 = 0x71; 0xD90B &= 0x7F; 0xD904 &= 0x01 when 0xD511 == 0x20, else &= 0x0F; 0xD90C |= 0x01; then
 * FUN_CODE_daad().
 */
extern xdata unsigned char DAT_EXTMEM_d929;
extern xdata unsigned char DAT_EXTMEM_d90b;
extern xdata unsigned char DAT_EXTMEM_d511;
extern xdata unsigned char DAT_EXTMEM_d904;
extern xdata unsigned char DAT_EXTMEM_d90c;

void FUN_CODE_daad(void);  // at 0xdaad

void FUN_CODE_d5c8(void)
{
    DAT_EXTMEM_d929 = 0x71;
    DAT_EXTMEM_d90b = DAT_EXTMEM_d90b & 0x7f;
    if (DAT_EXTMEM_d511 == 0x20) {
        DAT_EXTMEM_d904 = DAT_EXTMEM_d904 & 0x01;
    } else {
        DAT_EXTMEM_d904 = DAT_EXTMEM_d904 & 0x0f;
    }
    DAT_EXTMEM_d90c = DAT_EXTMEM_d90c | 0x01;
    FUN_CODE_daad();
}
