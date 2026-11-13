/* i2c_api_write_read  (FUN_a0147b70)
 *
 * Write, then read, in one transfer with a device on the software I2C bus.
 * Name basis: derived - forwards to the routine that ends in i2c_gpio_write_read; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0147b70 @ 0xa0147b70, flags -mcpu=v8 -O2 -g.
 * Source form: the callee is declared without a prototype; device is an unsigned int parameter that is masked
 * with 0xff before the call; the buffer addresses are passed as unsigned ints.
 */
extern int i2c_bus0_write_read();

/*
 * Forward to i2c_bus0_write_read: send `write_length` bytes at `write_buf`, then read `read_length` bytes into
 * `read_buf`, in one transfer. The parameters are those of i2c_bus0_write_read (see there for delay and
 * bus_index); the result is what that routine returns (bytes read). Nothing calls this routine.
 */
unsigned short i2c_api_write_read(unsigned int device,unsigned int write_buf,unsigned short write_length,unsigned short delay,
                      unsigned char bus_index,unsigned int read_buf,unsigned short read_length)

{
  device = device & 0xff;
  return i2c_bus0_write_read(device,write_buf,write_length,delay,bus_index,read_buf,read_length);
}
