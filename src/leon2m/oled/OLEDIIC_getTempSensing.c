/* OLEDIIC_getTempSensing  (FUN_a0126a4c)
 *
 * Read the panel temperature from the OLED panel controller.
 * Returns: temperature
 * Name basis: proven - prints '1.OLEDIIC_getTempSensing %d' (original name); register 8 scaled by 0.0625
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0126a4c, flags -mcpu=v8 -O3 -msoft-float (without -g; with -g it does not match).
 */
#define OLED_I2C_ADDRESS        0x60
#define OLED_REG_ADDRESS_BYTES  2
#define I2C_BIT_DELAY           5
#define I2C_BUS_0               0
#define OLED_REG_TEMPERATURE    8
#define TEMPERATURE_STEP        0.0625      /* the register value is multiplied by this */

extern unsigned char oled_read_buffer[2];
extern unsigned char oled_is_controller_enabled(void);
extern unsigned short i2c_api_read_block();
extern int dbg_printf();

/*
 * Read the temperature register (8) of the OLED panel controller and return it scaled by 0.0625, cut to a
 * whole number. Prints the raw value and the scaled value.
 *
 * The register is read only while the controller is enabled (oled_is_controller_enabled); otherwise the value
 * left in oled_read_buffer by the previous read is used. The raw 16-bit value arrives high byte first.
 */
unsigned short OLEDIIC_getTempSensing(void)
{
    unsigned short raw, temperature;
    if (oled_is_controller_enabled())
        i2c_api_read_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_TEMPERATURE, I2C_BIT_DELAY, I2C_BUS_0, oled_read_buffer, 2);
    raw = (oled_read_buffer[0] << 8) | oled_read_buffer[1];
    dbg_printf("1.OLEDIIC_getTempSensing %d\r\n", raw);
    temperature = raw * TEMPERATURE_STEP;
    dbg_printf("2.OLEDIIC_getTempSensing %d\r\n", temperature);
    return temperature;
}
