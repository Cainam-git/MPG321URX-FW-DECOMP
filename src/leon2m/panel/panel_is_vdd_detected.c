/* panel_is_vdd_detected  (FUN_a0124914)
 *
 * Return whether the panel supply voltage is detected.
 * Returns: 0 or 1
 * Name basis: proven - gpio_read_pin(9, 4); the sequencer prints 'VDD DET not high' when it is not 1
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124914 @ 0xa0124914 (-mcpu=v8 -O3 -g)
 * Source form: the masked pin read is kept in its own variable and compared with 1 by xor; this gives the
 * firmware's two-register sequence (and ..., %g1 / xor %g1, 1, ...).
 */
extern int gpio_read_pin(int port, int mask);

#define PANEL_VDD_GPIO_PORT     9       /* GPIO port 9 */
#define PANEL_VDD_PIN_MASK      4       /* pin 2 of that port */

/* Return 1 when the panel supply detection pin reads high, else 0. */
int panel_is_vdd_detected(void)
{
    unsigned int pin_state = gpio_read_pin(PANEL_VDD_GPIO_PORT, PANEL_VDD_PIN_MASK);
    unsigned int low_byte = pin_state & 0xff;
    return (low_byte ^ 1) == 0;
}
