/* oled_flag_registers_write  (FUN_a00fe44c)
 *
 * Write the 16-bit flag value kept in registers 0xCF009BB4 / 0xCF009BB8.
 * Name basis: descriptive - registers 0xCF009BB4 / 0xCF009BB8; written by the OLED power state machine,
 *   power_escape_fake_sleep and the FGA code with single bits changed
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fe44c @ 0xa00fe44c, flags -mcpu=v8 -O3 -g.
 * Source form: the high byte is taken from (value & 0xffff), then masked with 0x13.
 */

/* The two registers that hold the 16-bit value. */
#define RETAIN_REG_HIGH (*(volatile unsigned int *)0xcf009bb4)     /* bits 8..15 of the value */
#define RETAIN_REG_LOW  (*(volatile unsigned int *)0xcf009bb8)     /* bits 0..7 */

#define RETAIN_HIGH_BITS 0x13               /* the bits of the high byte the register keeps */

/*
 * Store a 16-bit value in the two registers at 0xCF009BB4 / 0xCF009BB8; oled_flag_registers_read reads it back.
 *
 * Only bits 8, 9 and 12 of the high byte are stored (mask 0x13); the low byte is stored whole.
 * The callers treat the value as flag bits, not as a count: the OLED power state machine (oled_power_task) sets
 * bits 5 and 8 (| 0x120) and clears them again (& 0xFEDF), the power-off code (APPSetPowerOff) clears them,
 * FGA_Init sets bit 4, and a calibration command over DDC/CI sets 0x126 for the time of the calibration and then
 * restores the value it read.
 */
void oled_flag_registers_write(unsigned short value)
{
  RETAIN_REG_HIGH = (value & 0xffff) >> 8 & RETAIN_HIGH_BITS;
  RETAIN_REG_LOW = value & 0xff;
  return;
}
