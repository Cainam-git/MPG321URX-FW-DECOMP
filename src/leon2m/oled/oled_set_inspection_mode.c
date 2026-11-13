/* oled_set_inspection_mode  (FUN_a01275b0)
 *
 * Write the inspection mode setting to the OLED panel controller and verify it.
 * Name basis: proven - prints 'OLED set Inspection Mode' and 'OLED Get Inspection Mode'; write and read-back
 *   over I2C device 0x60, with retries
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01275b0, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the whole routine is inside one if on oled_is_controller_enabled (no early return); the
 * retry test is `count < 10`, written here as `count < OLED_LAST_RETRY + 1`.
 */
/* The OLED panel controller is the device at I2C address 0x60 on software I2C bus 0. Its registers are
   numbered with two address bytes; each one holds a 16-bit value, sent high byte first. */
#define OLED_I2C_ADDRESS        0x60
#define OLED_REG_ADDRESS_BYTES  2
#define I2C_BIT_DELAY           5
#define I2C_BUS_0               0
#define OLED_REG_INSPECTION_MODE 0x1c6
#define OLED_SETTLE_TICKS       0x32      /* wait after a write and after a read-back */
#define OLED_RETRY_TICKS        5         /* wait between a repeated write and its read-back */
#define OLED_LAST_RETRY         9         /* repeating continues while the retry count is at most this */

extern unsigned char oled_is_controller_enabled(void);
extern unsigned short i2c_api_write_block();
extern unsigned short i2c_api_read_block();
extern int dbg_printf();
extern void timer_sleep_ticks(int ms);
extern unsigned char oled_write_buffer[2];
extern unsigned char oled_read_buffer[2];
extern unsigned char oled_write_retry_count;

/*
 * Write the inspection mode (register 0x1C6) of the OLED panel controller and check it.
 *
 * Does nothing while the controller is not enabled (oled_is_controller_enabled).
 * After the write it waits, reads the register back and prints what it read. While the read-back differs
 * from what was written and the retry counter oled_write_retry_count is at most 9, it writes again, waits
 * and reads again, and adds 1 to the counter.
 * That counter is shared by the OLED register writers of this group and nothing in the firmware clears it.
 *
 *   mode  one byte; callers pass 0 or 1
 *
 * The repeat loop waits OLED_RETRY_TICKS, not OLED_SETTLE_TICKS.
 */
void oled_set_inspection_mode(unsigned char mode)
{
    oled_write_buffer[1] = mode;
    oled_write_buffer[0] = 0;
    if (oled_is_controller_enabled()) {
        dbg_printf("\033[1;32mOLED set Inspection Mode %d\r\n\033[m", mode);
        i2c_api_write_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_INSPECTION_MODE, I2C_BIT_DELAY, I2C_BUS_0, oled_write_buffer, 2, 1);
        timer_sleep_ticks(OLED_SETTLE_TICKS);
        i2c_api_read_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_INSPECTION_MODE, I2C_BIT_DELAY, I2C_BUS_0, oled_read_buffer, 2);
        dbg_printf("\033[1;32mOLED Get Inspection Mode %x %x\r\n\033[m", oled_read_buffer[0], oled_read_buffer[1]);
        timer_sleep_ticks(OLED_SETTLE_TICKS);
        while ((oled_write_buffer[1] != oled_read_buffer[1] || oled_write_buffer[0] != oled_read_buffer[0]) && oled_write_retry_count < OLED_LAST_RETRY + 1) {
            dbg_printf("\033[1;32mOLED set Inspection Mode->retry (%d %d) (%d %d)\r\n\033[m", oled_write_buffer[0], oled_write_buffer[1], oled_read_buffer[0], oled_read_buffer[1]);
            i2c_api_write_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_INSPECTION_MODE, I2C_BIT_DELAY, I2C_BUS_0, oled_write_buffer, 2, 1);
            timer_sleep_ticks(OLED_RETRY_TICKS);
            i2c_api_read_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_INSPECTION_MODE, I2C_BIT_DELAY, I2C_BUS_0, oled_read_buffer, 2);
            oled_write_retry_count++;
        }
    }
}
