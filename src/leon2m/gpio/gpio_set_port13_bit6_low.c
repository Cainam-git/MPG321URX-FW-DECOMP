/* gpio_set_port13_bit6_low  (FUN_a01249d0)
 *
 * Drive pin 6 of GPIO port 13 low.
 * Name basis: descriptive - gpio_write_pin(0xd, 0x40, 0xFE); a step of the panel power sequencer
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01249d0, flags -mcpu=v8 -O2 -g.
 * The call is a tail call: the caller's return address is handed on and the callee returns straight to this
 * routine's caller. The last word is the nop the compiler places behind such a call sequence. The level is the
 * constant 0xFE (only bit 0 is the output level).
 */
#define GPIO_PORT_13   0xd
#define PIN_6_MASK     0x40
#define GPIO_LEVEL_LOW 0xfe     /* bit 0 clear: output low */

extern void gpio_write_pin(unsigned char, unsigned char, unsigned char);

/* Drive pin 6 of GPIO port 13 low. Called by panel_power_sequencer_task. */
void gpio_set_port13_bit6_low(void)
{
    gpio_write_pin(GPIO_PORT_13, PIN_6_MASK, GPIO_LEVEL_LOW);
}
