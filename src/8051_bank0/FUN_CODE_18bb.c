/* 8051_bank0 FUN_CODE_18bb @ 0x18bb  STBC boot loader: test of XDATA 0xD511 == 0x20
 * (OPTIMIZE(7,SPEED)).
 * Returns (in the carry flag, via bit 0x20.1) whether XDATA 0xD511 reads 0x20. 0xD511 is a hardware register that this
 * code only reads. Callers: FUN_CODE_1616 (UART set-up: baud divisor by the result),
 * FUN_CODE_17e2, FUN_CODE_18c9 and code at 0x18ad. Apart from the flash contents this is the boot loader's only
 * external input.
 */
unsigned char bdata _bdata_20 _at_ 0x20;
sbit _0_1 = _bdata_20 ^ 1;                          /* result bit, returned in CY */
unsigned char volatile xdata DAT_d511 _at_ 0xd511;  /* chip variant register */

bit FUN_CODE_18bb(void)
{
    _0_1 = 0;
    if (DAT_d511 == 0x20) {
        _0_1 = 1;
    }
    return _0_1;
}
