/* i2c_api_read_block  (FUN_a0147ae8)
 *
 * Read a block from a device on the software I2C bus.
 * Name basis: derived - forwards to the routine that ends in i2c_gpio_read_block; used by the panel register
 *   writes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0147ae8 @ 0xa0147ae8, flags -mcpu=v8 -O2 -g.
 * Source form: the callee is declared without a prototype; device and address_bytes are unsigned int parameters
 * that are masked with 0xff before the call; the buffer address is passed as an unsigned int.
 */
extern int i2c_bus0_read_block();

/*
 * Forward to i2c_bus0_read_block: read `length` bytes from memory address `memory_address` of the I2C device
 * `device` into `buf`. The parameters are those of i2c_bus0_read_block (see there for delay and bus_index);
 * the result is what that routine returns (bytes read).
 */
unsigned short i2c_api_read_block(unsigned int device,unsigned int address_bytes,unsigned short memory_address,unsigned short delay,
                      unsigned char bus_index,unsigned int buf,unsigned short length)

{
  device = device & 0xff;
  return i2c_bus0_read_block(device,address_bytes & 0xff,memory_address,delay,bus_index,buf,length);
}
