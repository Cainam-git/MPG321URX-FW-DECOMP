/* gpio_set_port13_bit6_high  (FUN_a01249b4)
 *
 * Drive pin 6 of GPIO port 13 high.
 * Name basis: descriptive - gpio_write_pin(0xd, 0x40, 1); a step of the panel power sequencer
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01249b4, flags -mcpu=v8 -O2 -g.
 * The call is a tail call: the caller's return address is handed on and the callee returns straight to this
 * routine's caller. The last word is the nop the compiler places behind such a call sequence.
 */
#define GPIO_PORT_13   0xd
#define PIN_6_MASK     0x40
#define GPIO_LEVEL_HIGH 1       /* bit 0 of the level is the output level */

extern void gpio_write_pin(unsigned char, unsigned char, unsigned char);

/* Drive pin 6 of GPIO port 13 high. Called by panel_power_sequencer_task. */
void gpio_set_port13_bit6_high(void)
{
    gpio_write_pin(GPIO_PORT_13, PIN_6_MASK, GPIO_LEVEL_HIGH);
}
