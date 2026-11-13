/* oled_set_pixel_shift_on_off  (FUN_a0126ae4)
 *
 * Switch the panel's pixel shift on or off and verify it.
 * Name basis: proven - prints 'OLED set PixelShift OnOff' and 'OLED Get PixelShift OnOff'; register 0x70
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0126ae4, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: -msoft-float belongs to the flags: without it the compiler chooses other registers.
 */
/* The OLED panel controller is the device at I2C address 0x60 on software I2C bus 0. Its registers are
   numbered with two address bytes; each one holds a 16-bit value, sent high byte first. */
#define OLED_I2C_ADDRESS        0x60
#define OLED_REG_ADDRESS_BYTES  2
#define I2C_BIT_DELAY           5
#define I2C_BUS_0               0
#define OLED_REG_PIXEL_SHIFT_ON_OFF 0x70
#define OLED_SETTLE_TICKS       0x32      /* wait after a write and after a read-back */
#define OLED_LAST_RETRY         9         /* repeating continues while the retry count is at most this */

extern unsigned char oled_read_buffer[2];
extern unsigned char oled_write_buffer[2];
extern unsigned char oled_write_retry_count;
extern int oled_is_controller_enabled(void);
extern unsigned short i2c_api_write_block(unsigned char, unsigned int, unsigned short, unsigned short, unsigned char, unsigned int, unsigned short, unsigned char);
extern unsigned short i2c_api_read_block(unsigned int, unsigned int, unsigned short, unsigned short, unsigned char, unsigned int, unsigned short);
extern int timer_sleep_ticks(int);
extern int dbg_printf(const char *, ...);

/*
 * Switch the pixel shift (register 0x70) of the OLED panel controller on or off and check it.
 *
 * Does nothing while the controller is not enabled (oled_is_controller_enabled).
 * After the write it waits, reads the register back and prints what it read. While the read-back differs
 * from what was written and the retry counter oled_write_retry_count is at most 9, it writes again, waits
 * and reads again, and adds 1 to the counter.
 * That counter is shared by the OLED register writers of this group and nothing in the firmware clears it.
 *
 *   enable  one byte; the caller passes bit 29 of the OLED care flags of the user settings
 */
void oled_set_pixel_shift_on_off(unsigned char enable)
{
    oled_write_buffer[1] = enable;
    oled_write_buffer[0] = 0;
    if (!(oled_is_controller_enabled() & 0xff)) return;
    dbg_printf("\033[1;32mOLED set PixelShift OnOff %d\r\n\033[m", enable);
    i2c_api_write_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_PIXEL_SHIFT_ON_OFF, I2C_BIT_DELAY, I2C_BUS_0, (unsigned int)&oled_write_buffer, 2, 1);
    timer_sleep_ticks(OLED_SETTLE_TICKS);
    i2c_api_read_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_PIXEL_SHIFT_ON_OFF, I2C_BIT_DELAY, I2C_BUS_0, (unsigned int)&oled_read_buffer, 2);
    dbg_printf("\033[1;32mOLED Get PixelShift OnOff %x %x\r\n\033[m", oled_read_buffer[0], oled_read_buffer[1]);
    timer_sleep_ticks(OLED_SETTLE_TICKS);
    while ((oled_write_buffer[1] != oled_read_buffer[1] || oled_write_buffer[0] != oled_read_buffer[0]) && oled_write_retry_count <= OLED_LAST_RETRY) {
        dbg_printf("\033[1;32mOLED set PixelShift OnOff->retry (%d %d) (%d %d)\r\n\033[m", oled_write_buffer[0], oled_write_buffer[1], oled_read_buffer[0], oled_read_buffer[1]);
        i2c_api_write_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_PIXEL_SHIFT_ON_OFF, I2C_BIT_DELAY, I2C_BUS_0, (unsigned int)&oled_write_buffer, 2, 1);
        timer_sleep_ticks(OLED_SETTLE_TICKS);
        i2c_api_read_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_PIXEL_SHIFT_ON_OFF, I2C_BIT_DELAY, I2C_BUS_0, (unsigned int)&oled_read_buffer, 2);
        oled_write_retry_count++;
    }
}
