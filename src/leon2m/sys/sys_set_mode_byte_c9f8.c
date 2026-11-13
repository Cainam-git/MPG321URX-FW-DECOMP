/* sys_set_mode_byte_c9f8  (FUN_a01243bc)
 *
 * Store the mode byte at 0xA802C9F8.
 * Name basis: descriptive - tested by the two conditional pin routines
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01243bc @ 0xa01243bc (-mcpu=v8 -O2 -g)
 */
extern unsigned char sys_pin_mode_byte;

/* Set sys_pin_mode_byte. The two conditional pin routines (gpio_set_port4_bit7_high_if_allowed, gpio_set_port4_bit4_low_if_allowed) test it for the value 1. */
void sys_set_mode_byte_c9f8(unsigned char mode)
{
  sys_pin_mode_byte = mode;
}
