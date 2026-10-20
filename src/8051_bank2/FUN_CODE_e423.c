/* 8051_bank2 FUN_CODE_e423 @ 0xe423  update agent: I2C START condition (byte-exact with
 * OPTIMIZE(8,SPEED) LARGE). The service bus is bit-banged on port 1: P1.7 = SCL, P1.6 = SDA. SCL high, SDA low
 * (start), SCL low, with a half-bit delay (FUN_CODE_e462) after each step.
 */
#include <intrins.h>
sfr P1 = 0x90;
sbit SDA = P1 ^ 6;
sbit SCL = P1 ^ 7;
extern unsigned char xdata DAT_EXTMEM_09d2;
void FUN_CODE_e462(void);
void FUN_CODE_e423(void)
{
    SCL = 1;
    FUN_CODE_e462();
    SDA = 0;
    FUN_CODE_e462();
    SCL = 0;
    FUN_CODE_e462();
}
