/* oled_controller_disable  (FUN_a01248ac)
 *
 * Switch the enable pin of the OLED panel controller off.
 * Name basis: derived - gpio_write_pin(9, 8, 0xFE)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01248ac @ 0xa01248ac (-mcpu=v8 -O2 -g)
 * Source form: the pin level is the constant 0xfe (only bit 0 of the level is the output level).
 */
extern int gpio_write_pin();

#define OLED_ENABLE_GPIO_PORT   9       /* GPIO port 9 */
#define OLED_ENABLE_PIN_MASK    8       /* pin 3 of that port */
#define GPIO_LEVEL_LOW          0xfe    /* bit 0 clear: output low */

/* Drive the enable pin of the OLED panel controller low; oled_controller_enable drives it high. */
void oled_controller_disable(void)
{
    gpio_write_pin(OLED_ENABLE_GPIO_PORT, OLED_ENABLE_PIN_MASK, GPIO_LEVEL_LOW);
}
