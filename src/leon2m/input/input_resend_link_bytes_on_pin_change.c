/* input_resend_link_bytes_on_pin_change  (FUN_a0124244)
 *
 * When GPIO port 2 bit 0 or bit 3 changed, write link row bytes 8, 0xA, 0xB of port 0 or 1 again.
 * Note: Sends input port type 1 before and 2 after for port 2 or 3; argument 1 only forgets the remembered
 *   pins.
 * Name basis: descriptive - byte 8 = 0x36/0x63/0x9C/0xC9 chosen from the two pins; ipc_set_input_port_type and
 *   a port link update
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124244, flags -mcpu=v8 -O3 -g. No volatile.
 * Source forms the exact build depends on:
 *  - `source` goes through an int temporary (`tmp = 0; if (...) tmp = 2; source = tmp;`) that is set before the
 *    call of gpio_is_port2_bit3_high;
 *  - the level and the two link bytes are selected with the test `source != 2` first in each if / else;
 *  - in the mode 1 branch the store to input_last_gpio2_bit0_pin is written before the one to
 *    input_last_gpio2_bit3_pin;
 *  - the level pin value is read into an int and stored with its low byte.
 */
extern unsigned char input_last_gpio2_bit0_pin;
extern unsigned char input_last_gpio2_bit3_pin;
extern unsigned int nvram_get_device_option_bit25(void);
extern int gpio_is_port2_bit0_high(void);
extern int gpio_is_port2_bit3_high(void);
extern void ipc_set_input_port_type(unsigned char, int);
extern void input_set_port_link_tail_bytes(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

#define PIN_WATCH_FORGET        1       /* mode: forget the remembered pins */
#define PIN_WATCH_NONE          0xff    /* remembered value meaning "nothing seen yet" */
#define SOURCE_PIN_HIGH         2       /* source value when pin 0 of GPIO port 2 is high; 0 otherwise */

/* Value of the link byte 8 for each combination of the two pins (level pin high / low, source 2 / 0). */
#define LEVEL_PIN_HIGH_SOURCE_2 0x36
#define LEVEL_PIN_HIGH_SOURCE_0 0x63
#define LEVEL_PIN_LOW_SOURCE_2  0x9c
#define LEVEL_PIN_LOW_SOURCE_0  0xc9

/*
 * One step of the watch on the two GPIO port 2 pins (bit 0 = source, bit 3 = level). When either pin has
 * changed since the last step, send the input processor a new set of link bytes for the pin combination.
 *
 *   mode  1: forget the remembered pins (both are set to 0xff) and do nothing else
 *         any other value: do the check
 *
 * The port that is told is 2, or 3 when the device option bit 25 is not 1; the link row that gets the bytes
 * is 0, or 1 in that same case. On a change the sequence is: input port type 1 for that port, the link bytes
 * (byte 8 = the level from the table above, bytes 0xa and 0xb = 0xf and 1 when the source pin is high, else
 * 0 and 0), input port type 2, then the new pins are remembered.
 * Called with 0 from the timer routine APPTimerRoutine, and with 1 from App_Initialize.
 */
void input_resend_link_bytes_on_pin_change(unsigned char mode)
{
    unsigned char link_port, byte_8, byte_a, byte_b;
    unsigned char type_port;
    unsigned char source;
    int level_pin;
    int tmp;

    type_port = 2;
    link_port = 0;
    if ((unsigned char)nvram_get_device_option_bit25() != 1) {
        link_port = 1;
        type_port = 3;
    }
    if (mode == PIN_WATCH_FORGET) {
        input_last_gpio2_bit0_pin = PIN_WATCH_NONE;
        input_last_gpio2_bit3_pin = PIN_WATCH_NONE;
        return;
    }
    tmp = 0;
    if ((unsigned char)gpio_is_port2_bit0_high())
        tmp = SOURCE_PIN_HIGH;
    source = tmp;
    level_pin = gpio_is_port2_bit3_high();
    /* Nothing to do while both pins read as at the last step. */
    if (input_last_gpio2_bit0_pin == source && input_last_gpio2_bit3_pin == (unsigned char)level_pin)
        return;
    ipc_set_input_port_type(type_port, 1);
    if ((unsigned char)level_pin != 1) {
        if (source != SOURCE_PIN_HIGH)
            byte_8 = LEVEL_PIN_LOW_SOURCE_0;
        else
            byte_8 = LEVEL_PIN_LOW_SOURCE_2;
    } else {
        if (source != SOURCE_PIN_HIGH)
            byte_8 = LEVEL_PIN_HIGH_SOURCE_0;
        else
            byte_8 = LEVEL_PIN_HIGH_SOURCE_2;
    }
    if (source != SOURCE_PIN_HIGH) {
        byte_b = 0;
        byte_a = 0;
    } else {
        byte_b = 1;
        byte_a = 0xf;
    }
    input_set_port_link_tail_bytes(link_port, byte_8, byte_a, byte_b, 1);
    ipc_set_input_port_type(type_port, 2);
    input_last_gpio2_bit0_pin = source;
    input_last_gpio2_bit3_pin = level_pin;
}
