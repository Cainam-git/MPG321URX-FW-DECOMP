/* gpio_api_set_pin_function  (FUN_a014dc74)
 *
 * Switch one of four fixed pins to its special function or back.
 * Name basis: descriptive - pin-function field 0xF or 0 for one of four pins; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014dc74, flags -mcpu=v8 -O2 -g (156 bytes, leaf).
 * Source form the exact build depends on: the function field value is written 'on == 0 ? 0 : 0xf'; the call
 * in each case is a tail call.
 */
extern void gpio_set_pin_function(unsigned char a, unsigned char b, unsigned int c);

/*
 * Set the function field of one of four fixed pins: 0xF when "on" is non-zero, otherwise 0.
 *
 *   pin  1..4; anything else does nothing. Pins 1 and 3 are pins 0x40 and 0x80 of pin group 0xD; pins 2 and 4
 *        are pins 4 and 8 of pin group 0xF (arguments of gpio_set_pin_function).
 *
 * Nothing calls it.
 */
void gpio_api_set_pin_function(unsigned char pin, unsigned char on)
{
    unsigned int function = on == 0 ? 0 : 0xf;
    switch (pin) {
    case 1:
        gpio_set_pin_function(0xd, 0x40, function);
        break;
    case 2:
        gpio_set_pin_function(0xf, 4, function);
        break;
    case 3:
        gpio_set_pin_function(0xd, 0x80, function);
        break;
    case 4:
        gpio_set_pin_function(0xf, 8, function);
        break;
    }
}
