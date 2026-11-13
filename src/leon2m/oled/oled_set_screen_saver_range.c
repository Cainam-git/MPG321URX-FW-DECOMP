/* oled_set_screen_saver_range  (FUN_a0126f4c)
 *
 * Write the screen saver range setting to the OLED panel controller and verify it.
 * Name basis: proven - prints 'OLED set Screen Saver Range' and 'OLED Get Screen Saver Range'; write and read-
 *   back over I2C device 0x60, with retries
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0126f4c @ 0xa0126f4c-0xa0127154 (130 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the repeat loop is a while loop whose condition holds the two byte compares and the retry count
 * test; the retry count is the shared byte oled_write_retry_count, incremented once per round. The settings
 * word +0x1DC is read as a union of a word and four bytes (byte 3 = settings byte +0x1DF).
 */
/* The OLED panel controller is the device at I2C address 0x60 on software I2C bus 0. Its registers are
   numbered with two address bytes; each one holds a 16-bit value, sent high byte first. */
#define OLED_I2C_ADDRESS            0x60
#define OLED_REG_ADDRESS_BYTES      2
#define I2C_BIT_DELAY               5
#define I2C_BUS_0                   0
#define OLED_REG_SCREEN_SAVER_RANGE 0x60
#define OLED_SETTLE_TICKS           0x32      /* wait after a write and after a read-back */
#define OLED_LAST_RETRY             9         /* repeating continues while the retry count is at most this */

#define OLED_CARE_STATIC_SCREEN     0x8000    /* bit 15 of the oled_care_flags word: Static Screen Detection on */

/* The fields of the user settings record that are read here (docs/RECORDS.md). */
struct user_settings_record {
    unsigned char pad0[0x1dc];
    union {
        unsigned int word;                      /* +0x1DC: oled_care_flags */
        unsigned char bytes[4];                 /* bytes[3] = +0x1DF: static_screen_level */
    } oled_care_flags;
    unsigned char static_screen_start_time;     /* +0x1E0 */
    unsigned char static_screen_time_required;  /* +0x1E1 */
};
extern struct user_settings_record user_settings;
extern unsigned char oled_read_buffer[2];
extern unsigned char oled_write_buffer[2];
extern unsigned char oled_write_retry_count;
extern int oled_is_controller_enabled(void);
extern unsigned short i2c_api_write_block(unsigned char, unsigned int, unsigned short, unsigned short, unsigned char, unsigned int, unsigned short, unsigned char);
extern unsigned short i2c_api_read_block(unsigned int, unsigned int, unsigned short, unsigned short, unsigned char, unsigned int, unsigned short);
extern int timer_sleep_ticks(int);
extern int dbg_printf(const char *, ...);

/*
 * Send the Static Screen Detection settings to the OLED panel controller as one 16-bit value in register 0x60,
 * and check it by reading the register back. No parameters, no return value.
 *
 * The value is built in oled_write_buffer (byte 0 is sent first, so it is the high byte):
 *   - Static Screen Detection off (bit 15 of the oled_care_flags word clear): both bytes 0;
 *   - on: byte 0 = (1 - start_time) | ((1 - time_required) << 4), byte 1 = reduce level + 1.
 *
 * While the controller is not enabled (oled_is_controller_enabled) nothing is sent; the buffer is still filled.
 * Otherwise: print the value and the four inputs, write, wait, read back into oled_read_buffer, print what was
 * read, wait. While the read-back differs from what was written and the shared byte oled_write_retry_count is
 * at most 9, print the retry text, write again, wait, read back, and add 1 to that count. This routine never
 * clears the count, so the retries of all callers share one budget; the retry text is the one of the Pixel
 * Shift speed setter.
 *
 * Callers: oled_user_apply_screen_saver_range, and the menu code that accepts the Static Screen Detection
 * choices (after it set or cleared bit 15).
 */
void oled_set_screen_saver_range(void)
{
    if (!(user_settings.oled_care_flags.word & OLED_CARE_STATIC_SCREEN)) {
        oled_write_buffer[1] = 0;
        oled_write_buffer[0] = 0;
    } else {
        oled_write_buffer[0] = (1 - user_settings.static_screen_start_time) | ((1 - user_settings.static_screen_time_required) << 4);
        oled_write_buffer[1] = user_settings.oled_care_flags.bytes[3] + 1;
    }
    if (!(oled_is_controller_enabled() & 0xff)) return;
    dbg_printf("\033[1;32mOLED set Screen Saver Range %x %x\r\n\033[m", oled_write_buffer[0], oled_write_buffer[1]);
    /* The inputs: Static Screen on/off bit, start time, reduce level, time required. */
    dbg_printf("%x %x %x %x\r\n", (user_settings.oled_care_flags.word >> 15) & 1, user_settings.static_screen_start_time, user_settings.oled_care_flags.bytes[3], user_settings.static_screen_time_required);
    i2c_api_write_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_SCREEN_SAVER_RANGE, I2C_BIT_DELAY, I2C_BUS_0, (unsigned int)&oled_write_buffer, 2, 1);
    timer_sleep_ticks(OLED_SETTLE_TICKS);
    i2c_api_read_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_SCREEN_SAVER_RANGE, I2C_BIT_DELAY, I2C_BUS_0, (unsigned int)&oled_read_buffer, 2);
    dbg_printf("\033[1;32mOLED Get Screen Saver Range %x %x\r\n\033[m", oled_read_buffer[0], oled_read_buffer[1]);
    timer_sleep_ticks(OLED_SETTLE_TICKS);
    while ((oled_write_buffer[1] != oled_read_buffer[1] || oled_write_buffer[0] != oled_read_buffer[0]) && oled_write_retry_count <= OLED_LAST_RETRY) {
        dbg_printf("\033[1;32mOLED set PixelShift Speed->retry (%d %d) (%d %d)\r\n\033[m", oled_write_buffer[0], oled_write_buffer[1], oled_read_buffer[0], oled_read_buffer[1]);
        i2c_api_write_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_SCREEN_SAVER_RANGE, I2C_BIT_DELAY, I2C_BUS_0, (unsigned int)&oled_write_buffer, 2, 1);
        timer_sleep_ticks(OLED_SETTLE_TICKS);
        i2c_api_read_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_SCREEN_SAVER_RANGE, I2C_BIT_DELAY, I2C_BUS_0, (unsigned int)&oled_read_buffer, 2);
        oled_write_retry_count++;
    }
}
