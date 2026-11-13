/* power_api_is_woken_by_power_key  (FUN_a0148a24)
 *
 * Return whether the power key woke the monitor, and prepare two output pins if so.
 * Returns: 0 or 1
 * Name basis: proven - prints 'WakeUpByPowerKey !'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148a24, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the result is a _Bool (the firmware masks it with 1 before returning);
 * when wake status 0 is not 1 and not 2 it is read once more and the value dropped.
 */
extern unsigned char power_read_wake_status(unsigned char idx);
extern int dbg_printf(const char *fmt, ...);
extern void gpio_set_port4_bit4_low_if_allowed(void);
extern void gpio_set_port4_bit7_low_if_allowed(void);

/*
 * Return 1 when the monitor was woken by the power key, otherwise 0. In the power-key case it also sets
 * pin 4 and pin 7 of GPIO port 4 low (each only if its routine allows it).
 *
 * The power key is recognised by wake status register 0 reading 1 and register 1 reading 0x11.
 * Called by APPOnSystemAfterNvramInit and App_CoolInitialize.
 */
_Bool power_api_is_woken_by_power_key(void)
{
    _Bool woken_by_power_key = 0;

    if (power_read_wake_status(0) == 1) {
        if (power_read_wake_status(1) == 0x11) {
            woken_by_power_key = 1;
            dbg_printf("WakeUpByPowerKey !\r\n");
            gpio_set_port4_bit4_low_if_allowed();
            gpio_set_port4_bit7_low_if_allowed();
        }
    } else if (power_read_wake_status(0) != 2) {
        power_read_wake_status(0);      /* read again; the value is not used */
    }
    return woken_by_power_key;
}
