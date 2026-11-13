/* panel_power_off  (FUN_a0124874)
 *
 * Switch the panel power pin off.
 * Name basis: proven - gpio_write_pin(0xD, 0x20, 0xFE), the pin PanelPowerOn switches on
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124874 @ 0xa0124874 (-mcpu=v8 -O2 -g)
 * Source form: the pin level is the constant 0xfe (only bit 0 of the level is the output level).
 */
extern int gpio_write_pin();

#define PANEL_POWER_GPIO_PORT   0xd     /* GPIO port 13 */
#define PANEL_POWER_PIN_MASK    0x20    /* pin 5 of that port */
#define GPIO_LEVEL_LOW          0xfe    /* bit 0 clear: output low */

/* Drive the panel power pin low; PanelPowerOn drives it high. */
void panel_power_off(void)
{
    gpio_write_pin(PANEL_POWER_GPIO_PORT, PANEL_POWER_PIN_MASK, GPIO_LEVEL_LOW);
}
