/* i2c_api_write_two_buffers  (FUN_a0147b28)
 *
 * Write two buffers in one transfer to a device on the software I2C bus.
 * Name basis: derived - forwards to the routine that ends in i2c_gpio_write_two_buffers; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0147b28 @ 0xa0147b28, flags -mcpu=v8 -O2 -g.
 * Source form: the callee is declared without a prototype; device is an unsigned char parameter that is masked
 * with 0xff again before the call; the buffer addresses are passed as unsigned ints.
 */
extern int i2c_bus0_write_two_buffers();

/*
 * Forward to i2c_bus0_write_two_buffers: send the device address byte, then `first_length` bytes at `first_buf`
 * and `length` bytes at `buf`, in one transfer. The parameters are those of i2c_bus0_write_two_buffers (see
 * there for delay, bus_index and tries); the result is what that routine returns. Nothing calls this routine.
 */
unsigned short i2c_api_write_two_buffers(unsigned char device,unsigned int first_buf,unsigned short first_length,unsigned short delay,
                      unsigned char bus_index,unsigned int buf,unsigned short length,unsigned char tries)

{
  device = device & 0xff;
  return i2c_bus0_write_two_buffers(device,first_buf,first_length,delay,bus_index,buf,length,tries);
}
