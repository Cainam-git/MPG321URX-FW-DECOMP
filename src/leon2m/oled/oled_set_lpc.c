/* oled_set_lpc  (FUN_a0126dcc)
 *
 * Write the LPC setting to the OLED panel controller and verify it.
 * Note: Nothing calls it.
 * Name basis: proven - prints 'OLED set LPC' and 'OLED Get LPC'; write and read-back over I2C device 0x60,
 *   with retries
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0126dcc, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the repeat loop is a while loop with the byte compares, the count test and the
 * oled_is_controller_enabled test in its condition (the firmware puts the loop body before the condition blocks).
 */
/* The OLED panel controller is the device at I2C address 0x60 on software I2C bus 0. Its registers are
   numbered with two address bytes; each one holds a 16-bit value, sent high byte first. */
#define OLED_I2C_ADDRESS        0x60
#define OLED_REG_ADDRESS_BYTES  2
#define I2C_BIT_DELAY           5
#define I2C_BUS_0               0
#define OLED_REG_LPC            0xa0
#define OLED_SETTLE_TICKS       0x32      /* wait after a write and after a read-back */
#define OLED_LAST_RETRY         9         /* repeating continues while the retry count is at most this */

extern unsigned char oled_read_buffer[2];
extern unsigned char oled_write_buffer[2];
extern int oled_is_controller_enabled(void);
extern unsigned short i2c_api_write_block(unsigned char, unsigned int, unsigned short, unsigned short, unsigned char, unsigned int, unsigned short, unsigned char);
extern unsigned short i2c_api_read_block(unsigned int, unsigned int, unsigned short, unsigned short, unsigned char, unsigned int, unsigned short);
extern int timer_sleep_ticks(int);
extern int dbg_printf(const char *, ...);

/*
 * Write the LPC setting (register 0xA0) of the OLED panel controller and check it.
 *
 * Does nothing while the controller is not enabled (oled_is_controller_enabled).
 * After the write it waits, reads the register back and prints what it read. While the read-back differs
 * from what was written, at most 10 further write and read-back rounds follow (counted by a local counter,
 * not by oled_write_retry_count); a round is skipped as soon as the controller is no longer enabled.
 *
 *   setting  one byte; the high byte of the register value is sent as 0
 */
void oled_set_lpc(unsigned char setting)
{
    unsigned char retries = 0;

    oled_write_buffer[1] = setting;
    oled_write_buffer[0] = 0;
    if (!(oled_is_controller_enabled() & 0xff)) return;
    dbg_printf("\033[1;32mOLED set LPC %x %x\r\n\033[m", oled_write_buffer[0], oled_write_buffer[1]);
    i2c_api_write_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_LPC, I2C_BIT_DELAY, I2C_BUS_0, (unsigned int)&oled_write_buffer, 2, 1);
    timer_sleep_ticks(OLED_SETTLE_TICKS);
    i2c_api_read_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_LPC, I2C_BIT_DELAY, I2C_BUS_0, (unsigned int)&oled_read_buffer, 2);
    dbg_printf("\033[1;32mOLED Get LPC %x %x\r\n\033[m", oled_read_buffer[0], oled_read_buffer[1]);
    timer_sleep_ticks(OLED_SETTLE_TICKS);
    while ((oled_write_buffer[1] != oled_read_buffer[1] || oled_write_buffer[0] != oled_read_buffer[0]) && retries <= OLED_LAST_RETRY && (oled_is_controller_enabled() & 0xff)) {
        dbg_printf("\033[1;32mOLED set LPC->retry (%d %d) (%d %d)\r\n\033[m", oled_write_buffer[0], oled_write_buffer[1], oled_read_buffer[0], oled_read_buffer[1]);
        i2c_api_write_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_LPC, I2C_BIT_DELAY, I2C_BUS_0, (unsigned int)&oled_write_buffer, 2, 1);
        timer_sleep_ticks(OLED_SETTLE_TICKS);
        i2c_api_read_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_LPC, I2C_BIT_DELAY, I2C_BUS_0, (unsigned int)&oled_read_buffer, 2);
        retries++;
    }
}
