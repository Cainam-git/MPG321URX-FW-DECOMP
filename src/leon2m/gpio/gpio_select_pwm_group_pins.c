/* gpio_select_pwm_group_pins  (FUN_a0111088)
 *
 * Switch the pins of the selected PWM groups to function 8.
 * Name basis: descriptive - four pins per group bit, groups 9 and 10
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0111088 @ 0xa0111088, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the decompiler's shape is kept. The routine is declared void but its last arm ends in
 * 'return gpio_set_pin_function(...)' with six arguments, and the end of the routine returns a constant; the
 * unused parameters and the two unused locals belong to that form.
 */

extern void gpio_set_pin_function();

#define PIN_FUNCTION_8 8        /* function code written to every pin switched here */

/*
 * Switch pins of pin groups 9 and 10 to function 8 (gpio_set_pin_function). Each of the four low bits of
 * 'group_bits' stands for four pins:
 *
 *   bit 0  group 9, pin masks 0x01 0x02 0x04 0x08      bit 2  group 10, pin masks 0x01 0x02 0x04 0x08
 *   bit 1  group 9, pin masks 0x10 0x20 0x40 0x80      bit 3  group 10, pin masks 0x10 0x20 0x40 0x80
 *
 * Called by gpio_setup_pwm_group_pins with 1 or 2 (the two halves of group 9). The other parameters are not
 * used.
 */
void gpio_select_pwm_group_pins(unsigned char group_bits,unsigned int unused_2,unsigned int unused_3,unsigned int unused_4,
            unsigned int unused_5,unsigned int unused_6)

{
  unsigned int unused_group;
  unsigned int unused_pins;
  
  if ((group_bits & 1) != 0) {
    gpio_set_pin_function(9,1,PIN_FUNCTION_8);
    gpio_set_pin_function(9,2,PIN_FUNCTION_8);
    gpio_set_pin_function(9,4,PIN_FUNCTION_8);
    gpio_set_pin_function(9,8,PIN_FUNCTION_8);
  }
  if ((group_bits & 2) != 0) {
    gpio_set_pin_function(9,0x10,PIN_FUNCTION_8);
    gpio_set_pin_function(9,0x20,PIN_FUNCTION_8);
    gpio_set_pin_function(9,0x40,PIN_FUNCTION_8);
    gpio_set_pin_function(9,0x80,PIN_FUNCTION_8);
  }
  if ((group_bits & 4) != 0) {
    gpio_set_pin_function(10,1,PIN_FUNCTION_8);
    gpio_set_pin_function(10,2,PIN_FUNCTION_8);
    gpio_set_pin_function(10,4,PIN_FUNCTION_8);
    gpio_set_pin_function(10,8,PIN_FUNCTION_8);
  }
  if ((group_bits & 8) != 0) {
    gpio_set_pin_function(10,0x10,PIN_FUNCTION_8);
    gpio_set_pin_function(10,0x20,PIN_FUNCTION_8);
    gpio_set_pin_function(10,0x40,PIN_FUNCTION_8);
    unused_group = 10;
    unused_pins = 0x80;
    return gpio_set_pin_function(10,0x80,PIN_FUNCTION_8,unused_4,unused_5,unused_6);
  }
  return 0x800000000a;
}
