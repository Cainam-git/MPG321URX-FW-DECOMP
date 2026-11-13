/* gpio_user_set_port7_bit1  (FUN_a00db12c)
 *
 * Drive pin 1 of GPIO port 7 by a settings bit and an override.
 * Name basis: descriptive - bit 7 of the settings word at 0xA802D47C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00db12c @ 0xa00db12c, flags -mcpu=v8 -O3 -g.
 * Source form: the test is written as
 * '((word >> 7 ^ 1) & 1) != 0 || force_low != 0' and each arm returns on its own, with a blank line between the
 * header and the brace.
 */

#define TYPE_C_PD_CHARGE  0x80  /* bit 7 of settings word +0x1EC: Type C PD Charge */

extern unsigned int user_settings_boundary_detection;       /* user settings word +0x1EC */
extern void gpio_set_port7_bit1_high(void);
extern void gpio_set_port7_bit1_low(void);

/*
 * Set pin 1 of GPIO port 7: high only when the Type C PD Charge switch (bit 7 of settings word +0x1EC) is on
 * and force_low is 0; low in every other case. Every caller passes force_low 0.
 * Called when the Type C PD Charge switch changes (menu, PC tool, factory mode) and when the settings are applied.
 */
void gpio_user_set_port7_bit1(unsigned char force_low)

{
  if (((user_settings_boundary_detection >> 7 ^ 1) & 1) != 0 || force_low != '\0') {
    gpio_set_port7_bit1_low();
    return;
  }
  gpio_set_port7_bit1_high();
  return;
}
