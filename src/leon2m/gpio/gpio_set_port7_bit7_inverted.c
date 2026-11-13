/* gpio_set_port7_bit7_inverted  (FUN_a01259c0)
 *
 * Drive pin 7 of GPIO port 7 low for a non-zero argument, else release it high.
 * Name basis: descriptive - gpio_write_pin(7, 0x80, 0 or 0xFF)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01259c0 @ 0xa01259c0, flags -mcpu=v8 -O2 -g.
 */
extern int gpio_write_pin();

/*
 * Drive mask 0x80 (pin 7) of GPIO port 7: level 0 when `on` is non-zero, level 0xff (bit 0 set: high) when it is
 * zero. The level is the inverse of the argument.
 * Called by APPSetPowerOff, power_enter_app_state and UsbModeSelectRoutine; docs/MAP.md names GPIO 7.7 as one of
 * the USB mode pins that UsbModeSelectRoutine drives.
 */
void gpio_set_port7_bit7_inverted(unsigned char on)
{
    if (on != 0) {
        gpio_write_pin(7, 0x80, 0);
        return;
    }
    gpio_write_pin(7, 0x80, 0xff);
}
