/* 8051_bank2 FUN_CODE_d275 @ 0xd275  update agent: bit-banged I2C byte send (byte-exact with
 * OPTIMIZE(8,SPEED) LARGE).
 * Shifts b out MSB first on P1.6 (SDA), clocking P1.7 (SCL) with half-bit delays (FUN_CODE_e462). Then releases SDA,
 * raises SCL and waits up to 255 polls for the slave to release SCL (clock stretching). Returns 0 when the slave pulled
 * SDA low (ACK); when SDA is high it polls SDA up to 7 more half-bits and returns 1 (NACK) only if it stayed high.
 * Ends with SCL low, SDA high. Locals live in IDATA. Used for every byte of FUN_CODE_bfcf (service-bus write).
 */
#include <intrins.h>
sfr P1 = 0x90;
sbit SDA = P1 ^ 6;
sbit SCL = P1 ^ 7;
extern unsigned char xdata DAT_EXTMEM_09d2;
void FUN_CODE_e462(void);
unsigned char FUN_CODE_d275(unsigned char b)
{
    unsigned char idata n;
    unsigned char idata ack;
    unsigned char idata v;
    v = b;
    for (n = 0; n < 8; n++) {
        FUN_CODE_e462();
        SCL = 0;
        FUN_CODE_e462();
        if (v & 0x80) SDA = 1; else SDA = 0;
        FUN_CODE_e462();
        SCL = 1;
        v <<= 1;
    }
    FUN_CODE_e462();
    SCL = 0;
    FUN_CODE_e462();
    SDA = 1;
    FUN_CODE_e462();
    SCL = 1;
    FUN_CODE_e462();
    v = 0xff;
    while (!SCL && --v);
    if (!SDA) ack = 0;
    else {
        n = 7;
        while (SDA && n) {
            FUN_CODE_e462();
            n--;
        }
        if (n == 0) ack = 1; else ack = 0;
    }
    SCL = 0;
    SDA = 1;
    FUN_CODE_e462();
    FUN_CODE_e462();
    return ack;
}
