/* oled_controller_enable  (FUN_a0124890)
 *
 * Switch the enable pin of the OLED panel controller on.
 * Name basis: derived - gpio_write_pin(9, 8, 1); every access to the controller first checks this pin
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124890 @ 0xa0124890-0xa01248ac (7 words), flags -mcpu=v8 -O2 -g.
 * Calls gpio_write_pin(9, 8, 1) as a tail call. The caller's return address is handed on, so the callee returns
 * straight to this routine's caller. The last word is the nop the compiler places behind such a call sequence.
 */
extern void gpio_write_pin(unsigned char, unsigned char, unsigned char);

#define OLED_ENABLE_GPIO_PORT   9       /* GPIO port 9 */
#define OLED_ENABLE_PIN_MASK    8       /* pin 3 of that port */
#define GPIO_LEVEL_HIGH         1

/*
 * Drive the enable pin of the OLED panel controller high. oled_controller_disable drives it low and
 * oled_is_controller_enabled reads it; every register access to the controller checks it first.
 */
void oled_controller_enable(void)
{
    gpio_write_pin(OLED_ENABLE_GPIO_PORT, OLED_ENABLE_PIN_MASK, GPIO_LEVEL_HIGH);
}
