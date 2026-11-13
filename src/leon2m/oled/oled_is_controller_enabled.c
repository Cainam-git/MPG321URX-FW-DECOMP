/* oled_is_controller_enabled  (FUN_a01248c8)
 *
 * Return whether the OLED panel controller is enabled.
 * Returns: 0 or 1
 * Name basis: derived - gpio_read_pin(9, 8); checked before every I2C access to device 0x60
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01248c8 @ 0xa01248c8 (-mcpu=v8 -O3 -g)
 * Source form: only the low byte of the pin read is compared with 1.
 */
extern int gpio_read_pin(int, int);

#define OLED_ENABLE_GPIO_PORT   9       /* GPIO port 9 */
#define OLED_ENABLE_PIN_MASK    8       /* pin 3 of that port */

/*
 * Return 1 when the enable pin of the OLED panel controller reads high, else 0. The routines that read or
 * write a controller register over I2C (oled_set_lum_gain and the others) leave the controller alone when this
 * is 0.
 */
int oled_is_controller_enabled(void)
{
    return (gpio_read_pin(OLED_ENABLE_GPIO_PORT, OLED_ENABLE_PIN_MASK) & 0xff) == 1;
}
