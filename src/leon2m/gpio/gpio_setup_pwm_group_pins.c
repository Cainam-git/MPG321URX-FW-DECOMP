/* gpio_setup_pwm_group_pins  (FUN_a014dc28)
 *
 * Program the PWM divider and switch the pins of the selected groups to it.
 * Name basis: descriptive - divider write, then the pin-function setter for groups 1 and/or 2; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014dc28, flags -mcpu=v8 -O2 -g.
 * Source form the exact build depends on: the callees take one byte argument here (the firmware sets only the
 * first argument register before each call); the second selection is a tail call.
 */
extern void gpio_set_pwm_group_divider(unsigned char n);
extern void gpio_select_pwm_group_pins(unsigned char n);

/*
 * Set the PWM divider (to 2) and switch the pins of the chosen PWM groups to the PWM function.
 *
 *   group_mask  bit 0 selects group 1 and bit 1 selects group 2
 *
 * Nothing calls it.
 */
void gpio_setup_pwm_group_pins(unsigned char group_mask)
{
    gpio_set_pwm_group_divider(2);
    if (group_mask & 1)
        gpio_select_pwm_group_pins(1);
    if (group_mask & 2)
        gpio_select_pwm_group_pins(2);
}
