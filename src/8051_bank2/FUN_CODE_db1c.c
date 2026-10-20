/* 8051_bank2 FUN_CODE_db1c @ 0xdb1c  update agent: bit-banged I2C byte read (byte-exact with
 * OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC)).
 * Releases SDA (P1.6), then 8 times: shift the byte left, raise SCL (P1.7), wait a half bit, wait up to 255 polls
 * for clock stretching, sample SDA into bit 0, drop SCL. Then sends ACK (SDA low) when last == 0 or NACK (SDA high)
 * for the final byte, clocks it out and returns the byte. Locals in IDATA. Used by the reply reader FUN_CODE_bba9.
 */
sfr P1 = 0x90;
sbit SDA = P1 ^ 6;
sbit SCL = P1 ^ 7;
void FUN_CODE_e462(void);

unsigned char FUN_CODE_db1c(unsigned char last)
{
    unsigned char idata n;
    unsigned char idata v;
    unsigned char idata w;
    last &= 1;
    SDA = 1;
    for (n = 0; n < 8; n++) {
        v <<= 1;
        SCL = 1;
        FUN_CODE_e462();
        w = 0xff;
        while (!SCL && --w);
        if (!SDA) v &= 0xfe; else v |= 0x01;
        SCL = 0;
        FUN_CODE_e462();
    }
    if (!last) SDA = 0; else SDA = 1;
    FUN_CODE_e462();
    SCL = 1;
    FUN_CODE_e462();
    SCL = 0;
    FUN_CODE_e462();
    return v;
}
