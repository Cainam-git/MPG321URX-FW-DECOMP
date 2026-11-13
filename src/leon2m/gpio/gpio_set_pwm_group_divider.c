/* gpio_set_pwm_group_divider  (FUN_a0111028)
 *
 * Enable the PWM group and program its divider.
 * Name basis: descriptive - bit 7 of 0xCF0115FC and 0xC0 / n - 2 in two bytes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0111028, flags -mcpu=v8 -O3 -g.
 * Source form: divider is an unsigned short, so the high byte is taken with sll 16 / srl 24; the division is signed
 * (the unsigned char n is promoted to int).
 */
#define R(a) (*(volatile unsigned int *)(a))

/*
 * Set bit 7 of 0xCF0115FC, then write the value 0xC0 / n - 2 to the divider: its low byte to 0xCF0115F0 and its
 * bits 8..15 to 0xCF0115F4. n must not be 0. Called by gpio_setup_pwm_group_pins with n = 2.
 */
void gpio_set_pwm_group_divider(unsigned char n)
{
    unsigned short divider = 0xc0 / n - 2;

    R(0xcf0115fc) |= 0x80;
    R(0xcf0115f0) = divider & 0xff;
    R(0xcf0115f4) = divider >> 8;
}
