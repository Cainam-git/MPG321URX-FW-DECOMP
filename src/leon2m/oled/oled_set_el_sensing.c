/* oled_set_el_sensing  (FUN_a0126938)
 *
 * Start or stop the panel's EL sensing.
 * Note: Nothing calls this copy; oled_power_task contains the same steps.
 * Name basis: proven - prints 'OLED set EL sensing %d'; register 0xC2; no caller
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0126938, flags -mcpu=v8 -O3 -g.
 */
/* The OLED panel controller is the device at I2C address 0x60 on software I2C bus 0. Its registers are
   numbered with two address bytes; each one holds a 16-bit value, sent high byte first. */
#define OLED_I2C_ADDRESS        0x60
#define OLED_REG_ADDRESS_BYTES  2
#define I2C_BIT_DELAY           5
#define I2C_BUS_0               0
#define OLED_REG_EL_SENSING     0xc2

extern unsigned char oled_write_buffer[2];
extern unsigned char oled_is_controller_enabled(void);
extern unsigned short i2c_api_write_block();
extern int dbg_printf();
/*
 * Write the EL-sensing control (register 0xC2) of the OLED panel controller. The value is not read back.
 *
 * Does nothing while the controller is not enabled (oled_is_controller_enabled).
 *
 *   state  one byte; the high byte of the register value is sent as 0
 *
 * Not called: oled_power_task has its own copy of this routine.
 */
void oled_set_el_sensing(unsigned char state)
{
    oled_write_buffer[0] = 0;
    oled_write_buffer[1] = state;
    if (!oled_is_controller_enabled()) return;
    dbg_printf("\033[1;32mOLED set EL sensing %d\r\n\033[m", state);
    i2c_api_write_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_EL_SENSING, I2C_BIT_DELAY, I2C_BUS_0, oled_write_buffer, 2, 1);
}
