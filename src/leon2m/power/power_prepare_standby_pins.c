/* power_prepare_standby_pins  (FUN_a0124fd0)
 *
 * Enable the 8051 DDC slave (address 0xA8) for two port masks, drive two pins low, set eight to input.
 * Note: Port masks 0x20 and 0x80; GPIO port 7 pins 5 and 4 low; the eight (port, mask) pins come from
 *   edid_bus_table +0x10..+0x1F.
 * Name basis: derived - ipc_8051_enable_ddc_slave twice (8051 command 0x07), two gpio_write_pin calls on port
 *   7, eight gpio_set_pin_input calls from a ROM table; called from SYSAPI_PowerSaving
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124fd0 @ 0xa0124fd0, flags -mcpu=v8 -O3 -g.
 * Source form: `base` is read from edid_bus_table AFTER the first two calls (the firmware builds the address at
 * that point; set at the top of the routine, it is built before the first call). The last gpio_set_pin_input call
 * is a tail call.
 */
extern const unsigned char edid_bus_table[];
extern void ipc_8051_enable_ddc_slave(unsigned char, unsigned char);
extern void gpio_write_pin(unsigned char, unsigned char, unsigned char);
extern void gpio_set_pin_input(unsigned char, unsigned char, unsigned char);

/* Offset in edid_bus_table of the four entries used here (16 bytes: two (port, mask) pins per entry). */
#define STANDBY_PINS_FIRST_ENTRY  0x10

/*
 * Pin set-up at the end of the power-saving sequence. It runs twice through the same steps, once for each of
 * the two 8051 port masks 0x20 and 0x80:
 *   1. send the 8051 command that sets its DDC/CI slave address (0xa8) for the ports of the mask and switches
 *      the slave on (ipc_8051_enable_ddc_slave);
 *   2. write level 0 to one pin of GPIO port 7 (mask 0x20 the first time, 0x10 the second);
 *   3. switch four pins to input (gpio_set_pin_input with 1); each pin is a (port, mask) byte pair taken from
 *      edid_bus_table, two entries per round: entries at +0x10 and +0x14 the first time, +0x18 and +0x1c the
 *      second.
 * Called by SYSAPI_PowerSaving.
 */
void power_prepare_standby_pins(void)
{
    const unsigned char *base;
    const unsigned char *pins;

    ipc_8051_enable_ddc_slave(0x20, 0xa8);
    gpio_write_pin(7, 0x20, 0);
    base = edid_bus_table;
    pins = base + STANDBY_PINS_FIRST_ENTRY;
    gpio_set_pin_input(pins[0], pins[1], 1);
    gpio_set_pin_input(pins[2], pins[3], 1);
    pins = base + 0x14;
    gpio_set_pin_input(pins[0], pins[1], 1);
    gpio_set_pin_input(pins[2], pins[3], 1);
    ipc_8051_enable_ddc_slave(0x80, 0xa8);
    gpio_write_pin(7, 0x10, 0);
    pins = base + 0x18;
    gpio_set_pin_input(pins[0], pins[1], 1);
    gpio_set_pin_input(pins[2], pins[3], 1);
    pins = base + 0x1c;
    gpio_set_pin_input(pins[0], pins[1], 1);
    gpio_set_pin_input(pins[2], pins[3], 1);
}
