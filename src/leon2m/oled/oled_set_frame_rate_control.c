/* oled_set_frame_rate_control  (FUN_a0126704)
 *
 * Write the refresh-rate row index to the OLED panel controller and verify it.
 * Name basis: proven - 'OLED set Frame rate control'; register 0xB2 of I2C device 0x60, up to ten retries
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0126704, flags -mcpu=v8 -O3 -g -msoft-float.

 */
/* The OLED panel controller is the device at I2C address 0x60 on software I2C bus 0. Its registers are
   numbered with two address bytes; each one holds a 16-bit value, sent high byte first. */
#define OLED_I2C_ADDRESS        0x60
#define OLED_REG_ADDRESS_BYTES  2
#define I2C_BIT_DELAY           5
#define I2C_BUS_0               0
#define OLED_REG_FRAME_RATE_CONTROL 0xb2
#define OLED_SETTLE_TICKS       0x32      /* wait after a write and after a read-back */
#define OLED_LAST_RETRY         9         /* repeating continues while the retry count is at most this */

extern unsigned char oled_write_buffer[2], oled_read_buffer[2], oled_write_retry_count;
extern unsigned char oled_is_controller_enabled(void);
extern unsigned short i2c_api_write_block();
extern unsigned short i2c_api_read_block();
extern int timer_sleep_ticks();
extern int dbg_printf();
/*
 * Write the refresh-rate row index (register 0xB2) of the OLED panel controller and check it.
 *
 * Does nothing while the controller is not enabled (oled_is_controller_enabled).
 * After the write it waits, reads the register back and prints what it read. While the read-back differs
 * from what was written and the retry counter oled_write_retry_count is at most 9, it writes again, waits
 * and reads again, and adds 1 to the counter.
 * That counter is shared by the OLED register writers of this group and nothing in the firmware clears it.
 *
 *   row_index  one byte; the high byte of the register value is sent as 0
 *
 * Called from oled_frc_task, with the row index kept in oled_frc_state_row_index, and from oled_power_task
 * with 0.
 */
void oled_set_frame_rate_control(unsigned char row_index)
{
    oled_write_buffer[1] = row_index;
    oled_write_buffer[0] = 0;
    if (!oled_is_controller_enabled()) return;
    dbg_printf("\033[1;32mOLED set Frame rate control %d\r\n\033[m", row_index);
    i2c_api_write_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_FRAME_RATE_CONTROL, I2C_BIT_DELAY, I2C_BUS_0, oled_write_buffer, 2, 1);
    timer_sleep_ticks(OLED_SETTLE_TICKS);
    i2c_api_read_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_FRAME_RATE_CONTROL, I2C_BIT_DELAY, I2C_BUS_0, oled_read_buffer, 2);
    dbg_printf("\033[1;32mOLED Get Frame rate control %x %x\r\n\033[m", oled_read_buffer[0], oled_read_buffer[1]);
    timer_sleep_ticks(OLED_SETTLE_TICKS);
    while ((oled_write_buffer[1] != oled_read_buffer[1] || oled_write_buffer[0] != oled_read_buffer[0]) && oled_write_retry_count <= OLED_LAST_RETRY) {
        dbg_printf("\033[1;32mOLED set Frame rate control->retry (%d %d) (%d %d)\r\n\033[m", oled_write_buffer[0], oled_write_buffer[1], oled_read_buffer[0], oled_read_buffer[1]);
        i2c_api_write_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_FRAME_RATE_CONTROL, I2C_BIT_DELAY, I2C_BUS_0, oled_write_buffer, 2, 1);
        timer_sleep_ticks(OLED_SETTLE_TICKS);
        i2c_api_read_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_FRAME_RATE_CONTROL, I2C_BIT_DELAY, I2C_BUS_0, oled_read_buffer, 2);
        oled_write_retry_count++;
    }
}
