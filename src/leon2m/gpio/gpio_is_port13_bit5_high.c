/* gpio_is_port13_bit5_high  (FUN_a0124828)
 *
 * Return whether pin 5 of GPIO port 13 reads high.
 * Returns: 0 or 1
 * Name basis: descriptive - the pin PanelPowerOn drives; read by the power sequencer and the OLED handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124828, flags -mcpu=v8 -O3 -g.
 * Source form: no parameters, int return (a 64-bit return would add clr / or instructions). '(r & 0xff) == 1'
 * produces the and / xor 1 / cmp / 'subx %g0, -1' sequence.
 */

/* The pin that panel_power_off drives low and PanelPowerOn drives high. */
#define PANEL_POWER_GPIO_PORT 0xd
#define PANEL_POWER_PIN_MASK  0x20      /* pin 5 of that port */

extern int gpio_read_pin(int, int);

/* Return 1 when the panel power pin reads high, else 0. Called by panel_power_sequencer_task among others. */
int gpio_is_port13_bit5_high(void)
{
    int level;
    level = gpio_read_pin(PANEL_POWER_GPIO_PORT, PANEL_POWER_PIN_MASK);
    return (level & 0xff) == 1;
}
