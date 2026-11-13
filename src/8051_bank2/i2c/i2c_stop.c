/* i2c_stop  (FUN_CODE_e525)
 *
 * Send an I2C stop condition on the update agent's bus.
 * Name basis: proven - pin sequence with the bit delay
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e525 @ 0xe525, no options recorded: the default OPTIMIZE(7,SPEED).
 */
#include <intrins.h>
sfr P1 = 0x90;
sbit SDA = P1 ^ 6;      /* data line of the bus the update agent drives by hand */
sbit SCL = P1 ^ 7;      /* clock line */
extern unsigned char xdata i2c_bit_delay_count;
void i2c_bit_delay(void);

/* End a transfer on the bit-banged bus: SDA low, SCL high, then SDA high while SCL is high, with a bit delay
 * between the steps. Both lines are left high.
 * Callers: the packet routines of the bus (i2c_write_packet, i2c_read_packet and the other service senders). */
void i2c_stop(void)
{
    SDA = 0;
    i2c_bit_delay();
    SCL = 1;
    i2c_bit_delay();
    SDA = 1;
}
