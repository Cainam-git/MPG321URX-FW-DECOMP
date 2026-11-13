/* panel_is_link_ready  (FUN_a012498c)
 *
 * Return whether the panel link reports ready.
 * Returns: 0 or 1
 * Name basis: derived - gpio_read_pin(7, 0x40); the sequencer prints 'eDP time out!' while waiting for it
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012498c @ 0xa012498c (-mcpu=v8 -O3 -g)
 * Source form: only the low byte of the pin read is compared with 1.
 */
extern int gpio_read_pin(int, int);

#define PANEL_LINK_GPIO_PORT    7       /* GPIO port 7 */
#define PANEL_LINK_PIN_MASK     0x40    /* pin 6 of that port */

/* Return 1 when the panel link ready pin reads high, else 0. */
int panel_is_link_ready(void)
{
    return (gpio_read_pin(PANEL_LINK_GPIO_PORT, PANEL_LINK_PIN_MASK) & 0xff) == 1;
}
