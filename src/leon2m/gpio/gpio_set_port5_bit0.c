/* gpio_set_port5_bit0  (FUN_a0125a2c)
 *
 * Drive pin 0 of GPIO port 5 high for a non-zero argument, else low.
 * Name basis: descriptive - gpio_write_pin(5, 1, 1 or 0xFE)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125a2c @ 0xa0125a2c, flags -mcpu=v8 -O2 -g.
 */
extern int gpio_write_pin();

/*
 * Drive mask 1 (pin 0) of GPIO port 5: level 1 (high) when `on` is non-zero, level 0xfe (bit 0 clear: low) when
 * it is zero.
 * Called by UsbModeSelectRoutine; docs/MAP.md names GPIO 5.0 as one of the USB mode pins it drives.
 */
void gpio_set_port5_bit0(unsigned char on)
{
    if (on == 0) {
        gpio_write_pin(5, 1, 0xfe);
        return;
    }
    gpio_write_pin(5, 1, 1);
}
