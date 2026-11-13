/* input_port_code_to_receiver_index  (FUN_a014226c)
 *
 * Convert a port code to the index of its receiver.
 * Returns: index or 0xFF
 * Name basis: descriptive - 0x31/0x71 -> 0, 0x41/0x81 -> 1, 0x51 -> 2, 0x61 -> 3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014226c @ 0xa014226c-0xa01422f4, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: the switch carries case labels that have no code of their own and give
 * the default's value 0xff: 0x11 (on the same label as 0x21) and a range 0x91 ... 0xff. They change the compare
 * tree the compiler builds (the firmware's tree is rooted at 0x51, with a range at each end of the case list); the
 * bytes do not fix the values of the two labels, 0x11 and 0x91 are chosen. The case order 0x31, 0x51, 0x61, 0x71,
 * 0x41, 0x81 gives the firmware's block order at the end.
 */

/*
 * Convert a port code to the index of its receiver.
 *
 *   port_code  0x31 and 0x71 give 0, 0x41 and 0x81 give 1, 0x51 gives 2, 0x61 gives 3
 *
 * Any other code gives 0xFF. Called from input_channel_bring_up_task, ipc_8051_send_usb_c_info and sys_set_channel_source.
 */
unsigned char input_port_code_to_receiver_index(unsigned char port_code)
{
    unsigned char receiver;

    switch (port_code) {
    case 0x11:
    case 0x21: receiver = 0xff; break;
    case 0x31: receiver = 0; break;
    case 0x51: receiver = 2; break;
    case 0x61: receiver = 3; break;
    case 0x71: receiver = 0; break;
    case 0x41: receiver = 1; break;
    case 0x81: receiver = 1; break;
    case 0x91 ... 0xff: receiver = 0xff; break;
    default: receiver = 0xff; break;
    }
    return receiver;
}
