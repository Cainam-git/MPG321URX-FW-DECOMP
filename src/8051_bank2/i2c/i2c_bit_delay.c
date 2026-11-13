/* i2c_bit_delay  (FUN_CODE_e462)
 *
 * Wait for one bit time of the I2C bus.
 * Name basis: proven - idle loop set by the XDATA byte at 0x09D2
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e462 @ 0xe462, no options recorded: the default OPTIMIZE(7,SPEED).
 * Source form: the counter is declared idata.
 */
#include <intrins.h>
sfr P1 = 0x90;
sbit SDA = P1 ^ 6;      /* data line of the bus the update agent drives by hand (not used here) */
sbit SCL = P1 ^ 7;      /* clock line (not used here) */
extern unsigned char xdata i2c_bit_delay_count;
void i2c_bit_delay(void);

/* The delay between two pin changes of the bit-banged bus: i2c_bit_delay_count rounds of three NOPs.
 * i2c_set_bit_delay sets the count: fwupd_svc_claim_link sets 0x14 at its start and 1 at its end. */
void i2c_bit_delay(void)
{
    unsigned char idata rounds;
    rounds = i2c_bit_delay_count;
    while (rounds > 0) {
        _nop_(); _nop_(); _nop_();
        rounds--;
    }
}
