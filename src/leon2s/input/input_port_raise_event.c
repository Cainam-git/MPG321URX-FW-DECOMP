/* input_port_raise_event  (FUN_a00c5f18)
 *
 * Record an event for an input and write it to the hardware when the state changed.
 * Name basis: descriptive - bit of 0xA8078C58 and of 0xA80788D2
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c5f18 @ 0xa00c5f18, flags -mcpu=v8 -Os -g. The last call is a tail call.
 * Source forms: the byte is copied into an unsigned int before the masked shift; the value ORed into
 * input_port_event_flags is chosen in an if / else chain (port == 4 tested before the default) and ORed in once.
 */

extern unsigned char hdcp_rx_restart_bits;
extern unsigned char input_port_event_flags;
extern void input_port_write_event_byte(unsigned int port, unsigned int value);
extern void input_port_set_event_bit(unsigned char port, unsigned char value);

/*
 * Set (value != 0) or clear the bit of input 'port' in hdcp_rx_restart_bits. Only when that changes the bit:
 * the input's bit in input_port_event_flags is set (1 << port for the inputs 0..3, 0x10 for input 4, 0x20 for
 * the rest) and the value is written with input_port_write_event_byte. In every case it ends with
 * input_port_set_event_bit.
 */
void input_port_raise_event(unsigned int port_arg, unsigned int value_arg)
{
    unsigned char port = port_arg;
    unsigned char value = value_arg;
    int port_mask = 1 << port;
    unsigned char restart_bits = hdcp_rx_restart_bits;
    unsigned int restart_word = restart_bits;
    unsigned char event_bit;

    if (((int)(restart_word & port_mask) >> port) != value) {
        if (value != 0)
            hdcp_rx_restart_bits = port_mask | restart_bits;
        else
            hdcp_rx_restart_bits = restart_bits & ~port_mask;
        if (port < 4)
            event_bit = 1 << port;
        else if (port == 4)
            event_bit = 0x10;
        else
            event_bit = 0x20;
        input_port_event_flags |= event_bit;
        input_port_write_event_byte(port, value);
    }
    input_port_set_event_bit(port_arg, value_arg);
}
