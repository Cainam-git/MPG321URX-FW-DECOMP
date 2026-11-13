/* oled_set_pixel_shift_speed  (FUN_a0126c58)
 *
 * Write the pixel shift speed setting to the OLED panel controller and verify it.
 * Name basis: proven - prints 'OLED set PixelShift Speed' and 'OLED Get PixelShift Speed'; write and read-back
 *   over I2C device 0x60, with retries
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0126c58, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: -msoft-float belongs to the flags: without it the compiler chooses other registers.
 * oled_is_controller_enabled returns an unsigned char and is compared with 0 here.
 */
/* The OLED panel controller is the device at I2C address 0x60 on software I2C bus 0. Its registers are
   numbered with two address bytes; each one holds a 16-bit value, sent high byte first. */
#define OLED_I2C_ADDRESS        0x60
#define OLED_REG_ADDRESS_BYTES  2
#define I2C_BIT_DELAY           5
#define I2C_BUS_0               0
#define OLED_REG_PIXEL_SHIFT_SPEED 0x72
#define OLED_SETTLE_TICKS       0x32      /* wait after a write and after a read-back */
#define OLED_RETRY_TICKS        5         /* wait between a repeated write and its read-back */
#define OLED_LAST_RETRY         9         /* repeating continues while the retry count is at most this */

extern unsigned char oled_read_buffer[2];
extern unsigned char oled_write_buffer[2];
extern unsigned char oled_write_retry_count;
extern unsigned char oled_is_controller_enabled(void);
extern unsigned short i2c_api_write_block(unsigned char, unsigned int, unsigned short, unsigned short, unsigned char, unsigned int, unsigned short, unsigned char);
extern unsigned short i2c_api_read_block(unsigned int, unsigned int, unsigned short, unsigned short, unsigned char, unsigned int, unsigned short);
extern int timer_sleep_ticks(int);
extern int dbg_printf(const char *, ...);

/*
 * Write the pixel shift speed (register 0x72) of the OLED panel controller and check it.
 *
 * Does nothing while the controller is not enabled (oled_is_controller_enabled).
 * After the write it waits, reads the register back and prints what it read. While the read-back differs
 * from what was written and the retry counter oled_write_retry_count is at most 9, it writes again, waits
 * and reads again, and adds 1 to the counter.
 * That counter is shared by the OLED register writers of this group and nothing in the firmware clears it.
 *
 *   speed  one byte; oled_user_apply_pixel_shift_speed passes the pixel shift setting of the user settings
 *
 * The repeat loop waits OLED_RETRY_TICKS, not OLED_SETTLE_TICKS.
 */
void oled_set_pixel_shift_speed(unsigned char speed)
{
    oled_write_buffer[1] = speed;
    oled_write_buffer[0] = 0;
    if (oled_is_controller_enabled() == 0)
        return;
    dbg_printf("\033[1;32mOLED set PixelShift Speed %d\r\n\033[m", speed);
    i2c_api_write_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_PIXEL_SHIFT_SPEED, I2C_BIT_DELAY, I2C_BUS_0, (unsigned int)&oled_write_buffer, 2, 1);
    timer_sleep_ticks(OLED_SETTLE_TICKS);
    i2c_api_read_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_PIXEL_SHIFT_SPEED, I2C_BIT_DELAY, I2C_BUS_0, (unsigned int)&oled_read_buffer, 2);
    dbg_printf("\033[1;32mOLED Get PixelShift Speed %x %x\r\n\033[m", oled_read_buffer[0], oled_read_buffer[1]);
    timer_sleep_ticks(OLED_SETTLE_TICKS);
    while ((oled_write_buffer[1] != oled_read_buffer[1] || oled_write_buffer[0] != oled_read_buffer[0]) && oled_write_retry_count <= OLED_LAST_RETRY) {
        dbg_printf("\033[1;32mOLED set PixelShift Speed->retry (%d %d) (%d %d)\r\n\033[m", oled_write_buffer[0], oled_write_buffer[1], oled_read_buffer[0], oled_read_buffer[1]);
        i2c_api_write_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_PIXEL_SHIFT_SPEED, I2C_BIT_DELAY, I2C_BUS_0, (unsigned int)&oled_write_buffer, 2, 1);
        timer_sleep_ticks(OLED_RETRY_TICKS);
        i2c_api_read_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_PIXEL_SHIFT_SPEED, I2C_BIT_DELAY, I2C_BUS_0, (unsigned int)&oled_read_buffer, 2);
        oled_write_retry_count++;
    }
}
