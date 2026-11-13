/* input_api_power_on_dp_port  (FUN_a014deec)
 *
 * Switch on the ports of a source with code 0x71 or 0x81 and send its number as a DP receiver setting.
 * Note: Code 0x71 uses port mask 0x10 and number 0, code 0x81 mask 0x20 and number 1; other codes do nothing.
 *   Nothing calls it.
 * Name basis: derived - input_power_on_ports_by_mask(0x10 or 0x20), then ipc_api_set_dp_rx_setting_11f
 *   (mailbox command 0x80)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014deec @ 0xa014deec-0xa014df68, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: the choice is a switch (an if/else chain or an early-return helper gives
 * other code); the 0x71 case sets the value to 0 (the firmware clears the register on that path); the two calls of
 * input_power_on_ports_by_mask are merged by the compiler into one call site.
 */

extern unsigned char input_port_table_find_code(unsigned char);
extern unsigned char input_find_port_entry_by_bus_id(unsigned char);
extern unsigned char input_entry_index_to_port_code(unsigned char);
extern void input_power_on_ports_by_mask(int mask, int on);
extern void ipc_api_set_dp_rx_setting_11f(unsigned char receiver);

#define PORT_CODE_0x71 0x71
#define PORT_CODE_0x81 0x81
#define NO_RECEIVER    0xff

/*
 * For the source whose port code is 0x71 or 0x81, switch on its ports and pass its number to the input
 * processor.
 *
 *   source  the source, as input_port_table_find_code takes it
 *
 * The source is turned into a port code (index, port entry, code). For 0x71 the ports of mask 0x10 are switched
 * on and 0 is passed to ipc_api_set_dp_rx_setting_11f; for 0x81 the ports of mask 0x20 are switched on and 1 is
 * passed. For any other code nothing happens. (The name says HDMI; the mailbox call is the one for a DisplayPort
 * receiver setting.)
 */
void input_api_power_on_dp_port(unsigned char source)
{
    unsigned char receiver;

    switch (input_entry_index_to_port_code(input_find_port_entry_by_bus_id(input_port_table_find_code(source)))) {
    case PORT_CODE_0x71: receiver = 0; input_power_on_ports_by_mask(0x10, 1); break;
    case PORT_CODE_0x81: receiver = 1; input_power_on_ports_by_mask(0x20, 1); break;
    default: receiver = NO_RECEIVER; break;
    }
    if (receiver == NO_RECEIVER)
        return;
    ipc_api_set_dp_rx_setting_11f(receiver);
}
