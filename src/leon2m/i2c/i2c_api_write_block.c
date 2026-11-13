/* i2c_api_write_block  (FUN_a0147aa0)
 *
 * Write a block to a device on the software I2C bus.
 * Name basis: derived - forwards to the routine that ends in i2c_gpio_write_block; used by the panel register
 *   writes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0147aa0 @ 0xa0147aa0, flags -mcpu=v8 -O2 -g.
 * Source form: the callee is declared without a prototype; device is an unsigned char parameter that is masked
 * with 0xff again before the call, and address_bytes is an unsigned int that is masked with 0xff; the buffer
 * address is passed as an unsigned int.
 */
extern int i2c_bus0_write_block();

/*
 * Forward to i2c_bus0_write_block: write `length` bytes from `buf` to memory address `memory_address` of the I2C
 * device `device`. The parameters are those of i2c_bus0_write_block (see there for delay, bus_index and tries);
 * the result is what that routine returns (bytes written).
 */
unsigned short i2c_api_write_block(unsigned char device,unsigned int address_bytes,unsigned short memory_address,unsigned short delay,
                      unsigned char bus_index,unsigned int buf,unsigned short length,unsigned char tries)

{
  device = device & 0xff;
  return i2c_bus0_write_block(device,address_bytes & 0xff,memory_address,delay,bus_index,buf,length,tries);
}
