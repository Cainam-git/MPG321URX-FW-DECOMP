/* 8051_bank2 FUN_CODE_e53b @ 0xe53b  update agent: set the service-bus speed (byte-exact with
 * OPTIMIZE(8,SPEED) LARGE). A non-zero argument becomes the I2C half-bit delay XDATA 0x09D2 (FUN_CODE_e462); 0 keeps
 * the current value. FUN_CODE_d1bb slows the bus to 0x14 while it hands the scaler over and restores 1 at the end.
 */
extern unsigned char xdata DAT_EXTMEM_09d2;
void FUN_CODE_e53b(unsigned char a)
{
    if (a) DAT_EXTMEM_09d2 = a;
}
