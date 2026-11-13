/* oled_flag_registers_read  (FUN_a00fe47c)
 *
 * Read the 16-bit flag value kept in registers 0xCF009BB4 / 0xCF009BB8.
 * Returns: value
 * Name basis: descriptive - registers 0xCF009BB4 / 0xCF009BB8; every caller tests, sets or clears single bits
 *   of the value (0x10, 0x20, 0x100, 0x126)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fe47c @ 0xa00fe47c-0xa00fe4a4 (10 words, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: one expression; the high register is read first.
 */

/* The two registers that hold the 16-bit value. */
#define RETAIN_REG_HIGH (*(volatile unsigned int *)0xcf009bb4)     /* bits 8..15 of the value */
#define RETAIN_REG_LOW  (*(volatile unsigned int *)0xcf009bb8)     /* bits 0..7 */

/*
 * Return the 16-bit value stored with oled_flag_registers_write: register 0xCF009BB4 as the high byte,
 * 0xCF009BB8 as the low byte.
 *
 * Read by the OLED power state machine (oled_power_task), the power-off code (APPSetPowerOff), FGA_Init and the
 * calibration commands over DDC/CI, which treat the value as flag bits (see oled_flag_registers_write).
 */
unsigned short oled_flag_registers_read(void)
{
    return (RETAIN_REG_HIGH << 8) | RETAIN_REG_LOW;
}
