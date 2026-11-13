/* gpio_pulse_port7_bit7  (FUN_a01259f4)
 *
 * Write pin 7 of GPIO port 7 high, wait 201 ticks, then write it low.
 * Name basis: descriptive - two gpio_write_pin calls around timer_sleep_ticks(200), which waits its argument +
 *   1 ticks; called by UsbModeSelectRoutine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01259f4 @ 0xa01259f4, flags -mcpu=v8 -O2 -g.
 */
extern void gpio_write_pin();
extern int timer_sleep_ticks();

#define PULSE_WAIT   200        /* argument of timer_sleep_ticks, which waits this value + 1 ticks */

/*
 * Write level 0xff (bit 0 set: high) to mask 0x80 (pin 7) of GPIO port 7, wait with timer_sleep_ticks(200) (201
 * ticks), then write level 0 (low) to the same pin.
 * Called by UsbModeSelectRoutine; docs/MAP.md names GPIO 7.7 as one of the USB mode pins it drives.
 */
void gpio_pulse_port7_bit7(void)
{
    gpio_write_pin(7, 0x80, 0xff);
    timer_sleep_ticks(PULSE_WAIT);
    gpio_write_pin(7, 0x80, 0);
}
