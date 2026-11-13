/* oled_set_off_sensing  (FUN_a01268cc)
 *
 * Start or stop the panel's off-state sensing.
 * Name basis: proven - prints 'OLED set OFF Sensing %d'; register 0xC0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01268cc, flags -mcpu=v8 -O3 -g.
 * oled_power_task has its own copy of this routine.
 */
/* The OLED panel controller is the device at I2C address 0x60 on software I2C bus 0. Its registers are
   numbered with two address bytes; each one holds a 16-bit value, sent high byte first. */
#define OLED_I2C_ADDRESS        0x60
#define OLED_REG_ADDRESS_BYTES  2
#define I2C_BIT_DELAY           5
#define I2C_BUS_0               0
#define OLED_REG_OFF_SENSING    0xc0

extern unsigned char oled_write_buffer[2];
extern unsigned char oled_is_controller_enabled(void);
extern unsigned short i2c_api_write_block();
extern int dbg_printf();
/*
 * Write the off-sensing control (register 0xC0) of the OLED panel controller. The value is not read back.
 *
 * Does nothing while the controller is not enabled (oled_is_controller_enabled).
 *
 *   state  one byte; the high byte of the register value is sent as 0. Callers outside oled_power_task pass 0
 */
void oled_set_off_sensing(unsigned char state)
{
    oled_write_buffer[0] = 0;
    oled_write_buffer[1] = state;
    if (!oled_is_controller_enabled()) return;
    dbg_printf("\033[1;32mOLED set OFF Sensing %d\r\n\033[m", state);
    i2c_api_write_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_OFF_SENSING, I2C_BIT_DELAY, I2C_BUS_0, oled_write_buffer, 2, 1);
}
