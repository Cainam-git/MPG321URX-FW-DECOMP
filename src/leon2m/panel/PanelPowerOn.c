/* PanelPowerOn  (FUN_a0124850)
 *
 * Print the message and switch the panel power pin on.
 * Name basis: proven - prints 'PanelPowerOn' (original name); gpio_write_pin(0xD, 0x20, 1)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124850 @ 0xa0124850 (-mcpu=v8 -O2 -g)
 * Source form: the pin level is the plain constant 1, as in the firmware.
 */
extern int dbg_printf();
extern int gpio_write_pin();

#define PANEL_POWER_GPIO_PORT   0xd     /* GPIO port 13 */
#define PANEL_POWER_PIN_MASK    0x20    /* pin 5 of that port */
#define GPIO_LEVEL_HIGH         1

/*
 * Print the message and drive the panel power pin high. panel_power_off drives the same pin low.
 * oled_frc_task starts its power-up sequence when it reads this pin high.
 */
void PanelPowerOn(void)
{
    dbg_printf("\033[1;35mPanelPowerOn\r\n\033[m");
    gpio_write_pin(PANEL_POWER_GPIO_PORT, PANEL_POWER_PIN_MASK, GPIO_LEVEL_HIGH);
}
