/* i2c_set_bit_delay  (FUN_CODE_e53b)
 *
 * Set the bit time of the update agent's I2C bus.
 * Name basis: proven - XDATA byte at 0x09D2; only a non-zero value is stored
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e53b @ 0xe53b, no options recorded: the default OPTIMIZE(7,SPEED).
 */
extern unsigned char xdata i2c_bit_delay_count;

/* Store `count` as the length of i2c_bit_delay (rounds of three NOPs); 0 leaves the current value.
 * Only caller: fwupd_svc_claim_link, with 0x14 at its start and 1 at its end. */
void i2c_set_bit_delay(unsigned char count)
{
    if (count) i2c_bit_delay_count = count;
}
