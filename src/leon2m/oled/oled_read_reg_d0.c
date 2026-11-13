/* oled_read_reg_d0  (FUN_a01269a4)
 *
 * Read register 0xD0 of the OLED panel controller.
 * Returns: value
 * Name basis: descriptive - I2C device 0x60; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01269a4, flags -mcpu=v8 -O3 -g.
 */
/* The OLED panel controller is the device at I2C address 0x60 on software I2C bus 0. Its registers are
   numbered with two address bytes; each one holds a 16-bit value, sent high byte first. */
#define OLED_I2C_ADDRESS        0x60
#define OLED_REG_ADDRESS_BYTES  2
#define I2C_BIT_DELAY           5
#define I2C_BUS_0               0
#define OLED_REG_D0             0xd0

extern unsigned char oled_is_controller_enabled(void);
extern unsigned short i2c_api_read_block();
extern unsigned char oled_read_buffer[2];

/*
 * Read register 0xD0 of the OLED panel controller. No caller in the firmware.
 *
 * Reads the register only while the controller is enabled (oled_is_controller_enabled). Otherwise nothing is
 * read and the value left in oled_read_buffer by the previous read is returned. The 16-bit value arrives high
 * byte first.
 */
unsigned short oled_read_reg_d0(void)
{
    if (oled_is_controller_enabled())
        i2c_api_read_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_D0, I2C_BIT_DELAY, I2C_BUS_0, oled_read_buffer, 2);
    return (oled_read_buffer[0] << 8) | oled_read_buffer[1];
}
