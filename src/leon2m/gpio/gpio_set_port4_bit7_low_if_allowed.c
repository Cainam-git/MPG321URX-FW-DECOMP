/* gpio_set_port4_bit7_low_if_allowed  (FUN_a0124ab0)
 *
 * Drive pin 7 of GPIO port 4 low when the mode byte or the OLED power state allows it.
 * Name basis: descriptive - gpio_write_pin(4, 0x80, 0xFE) under the same condition
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124ab0 @ 0xa0124ab0, flags -mcpu=v8 -O2 -g.
 * Source form: the early exit is a plain `return;` and the write is the last statement (a tail call).
 */
extern unsigned char sys_pin_mode_byte;
extern unsigned char oled_power_get_state();
extern void gpio_write_pin(unsigned char, unsigned char, unsigned char);

/*
 * Write level 0xfe (bit 0 clear: low) to mask 0x80 (pin 7) of GPIO port 4, but only when sys_pin_mode_byte is 1 or the OLED power
 * state is not 0. Otherwise nothing happens.
 */
void gpio_set_port4_bit7_low_if_allowed(void)
{
    if (sys_pin_mode_byte != 1 && oled_power_get_state() == 0) {
        return;
    }
    gpio_write_pin(4, 0x80, 0xfe);
}
