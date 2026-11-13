/* input_set_port_pin_function  (FUN_a0107a20)
 *
 * Switch the pin of input 0 or 1, or of both (argument 2), to function 9 or back to 0.
 * Name basis: descriptive - bit 5 of 0xCF03C348 / 0xCF03C2B8 and the pin-function setter; used around power
 *   saving
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0107a20 @ 0xa0107a20-0xa0107b9c (95 words), flags -mcpu=v8 -O3 -g.
 * Source form: the two registers are volatile int accesses with |= 0x20 / &= ~0x20; the four arms are written
 * out in full, one pair of gpio_set_pin_function calls per arm.
 */
#define REG_CF03C348 (*(volatile unsigned int *)0xcf03c348)
#define REG_CF03C2B8 (*(volatile unsigned int *)0xcf03c2b8)
extern unsigned char input_pin_config_bytes;
extern void gpio_set_pin_function(unsigned char, unsigned char, unsigned char);

#define PIN_GROUP         6         /* gpio_set_pin_function: the pin group used for both inputs */
#define PIN_MASK_1        1         /* gpio_set_pin_function: pin masks of the two pins in the group */
#define PIN_MASK_2        2
#define PIN_FUNCTION_ON   9         /* function value that is set when switching on; 0 when switching off */
#define PIN_REG_BIT5      0x20      /* bit 5 of the two registers above: set on switching on, cleared on off */

/*
 * Switch the pin function of input 0 or 1 on or off, or of both.
 *
 *   input_number  0 or 1: one input; 2: both inputs; anything above 2 does nothing
 *   enable        1: switch on; any other value: switch off
 *
 * Input 0 is the one of group mask 0x10 and input 1 the one of group mask 0x20 in input_power_on_ports_by_mask
 * and sys_service_ports_by_mask. Input 0 uses register 0xCF03C348 and input 1 register 0xCF03C2B8. Each input
 * has one pin of pin group 6; which of the two pins (mask 1 or 2) belongs to which input depends on the first
 * pin configuration byte (input_pin_config_bytes): when it is 1, input 0 takes pin mask 2 and input 1 pin
 * mask 1, otherwise the other way round.
 *
 * Switching on sets bit 5 of the input's register first and then sets the pin function to 9. Switching off sets
 * the pin function to 0 first and then clears bit 5. What function 9 is is not shown by the code.
 *
 * Callers: sys_service_ports_by_mask (on, one input), input_power_on_ports_by_mask (off, one input) and
 * SYSAPI_PowerSaving (off, both inputs).
 */
void input_set_port_pin_function(unsigned char input_number, unsigned char enable)
{
    if (input_number > 2)
        return;
    if (enable == 1) {
        if (input_number == 0 || input_number == 2) {
            REG_CF03C348 |= PIN_REG_BIT5;
            if (input_pin_config_bytes == 1)
                gpio_set_pin_function(PIN_GROUP, PIN_MASK_2, PIN_FUNCTION_ON);
            else
                gpio_set_pin_function(PIN_GROUP, PIN_MASK_1, PIN_FUNCTION_ON);
        }
        if (input_number == 1 || input_number == 2) {
            REG_CF03C2B8 |= PIN_REG_BIT5;
            if (input_pin_config_bytes == 1)
                gpio_set_pin_function(PIN_GROUP, PIN_MASK_1, PIN_FUNCTION_ON);
            else
                gpio_set_pin_function(PIN_GROUP, PIN_MASK_2, PIN_FUNCTION_ON);
        }
    } else {
        if (input_number == 0 || input_number == 2) {
            if (input_pin_config_bytes == 1)
                gpio_set_pin_function(PIN_GROUP, PIN_MASK_2, 0);
            else
                gpio_set_pin_function(PIN_GROUP, PIN_MASK_1, 0);
            REG_CF03C348 &= ~PIN_REG_BIT5;
        }
        if (input_number == 1 || input_number == 2) {
            if (input_pin_config_bytes == 1)
                gpio_set_pin_function(PIN_GROUP, PIN_MASK_1, 0);
            else
                gpio_set_pin_function(PIN_GROUP, PIN_MASK_2, 0);
            REG_CF03C2B8 &= ~PIN_REG_BIT5;
        }
    }
}
