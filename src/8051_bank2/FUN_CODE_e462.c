/* 8051_bank2 FUN_CODE_e462 @ 0xe462  update agent: bit-banged I2C half-bit delay (byte-exact with
 * OPTIMIZE(8,SPEED) LARGE). Counts the calibration byte XDATA 0x09D2 down over three NOPs (counter in IDATA).
 */
#include <intrins.h>
sfr P1 = 0x90;
sbit SDA = P1 ^ 6;
sbit SCL = P1 ^ 7;
extern unsigned char xdata DAT_EXTMEM_09d2;
void FUN_CODE_e462(void);
void FUN_CODE_e462(void)
{
    unsigned char idata n;
    n = DAT_EXTMEM_09d2;
    while (n > 0) {
        _nop_(); _nop_(); _nop_();
        n--;
    }
}
