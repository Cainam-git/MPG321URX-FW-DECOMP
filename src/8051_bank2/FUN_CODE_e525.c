/* 8051_bank2 FUN_CODE_e525 @ 0xe525  update agent: I2C STOP condition (byte-exact with
 * OPTIMIZE(8,SPEED) LARGE). SDA low, delay, SCL high, delay, SDA high (stop) on P1.6 / P1.7.
 */
#include <intrins.h>
sfr P1 = 0x90;
sbit SDA = P1 ^ 6;
sbit SCL = P1 ^ 7;
extern unsigned char xdata DAT_EXTMEM_09d2;
void FUN_CODE_e462(void);
void FUN_CODE_e525(void)
{
    SDA = 0;
    FUN_CODE_e462();
    SCL = 1;
    FUN_CODE_e462();
    SDA = 1;
}
