/* input_port_list_build  (FUN_a0152e28)
 *
 * Build the port record list for the current configuration and return its size.
 * Returns: record count times 3
 * Name basis: descriptive - sequence of input_port_list_append calls
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0152e28 @ 0xa0152e28, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: bit 31 of sys_config is tested as a one-bit bit-field (a "< 0" test gives
 * other branch predictions and puts the case blocks of the switch before the bit-31 arm); each of the two arms
 * that depend on nvram_get_device_option_bit25 makes its own input_port_list_append call (a code variable is
 * if-converted); the list buffer is passed on as an unsigned int.
 */

/* The first word of the system configuration record; only bit 31 is used here. */
struct sys_config_bits { unsigned int bit_31 : 1, bits_30_0 : 31; };
extern struct sys_config_bits sys_config;
extern unsigned char device_settings_pip_mode;
extern unsigned char nvram_get_device_option_bit25(void);
extern unsigned char sys_get_channel_signal_code(unsigned char channel);
extern void input_port_list_append(unsigned char code, unsigned int list, unsigned char *count);

#define PORT_LIST_END 0xff              /* code of the record that ends the list */
#define RECORD_SIZE   3                 /* bytes per list record */

/*
 * Fill a list of 3-byte port records for the present configuration and return its size in bytes.
 *
 *   list  the buffer that input_port_list_append writes the records to
 *
 * When bit 31 of the system configuration record is set, the codes 0x51 and 0x61 are appended, then 0x81 and
 * 0x71 when option bit 25 of the device settings is 1, otherwise 0x71 and 0x81. Otherwise the number of
 * channels n follows from the picture mode (device_settings_pip_mode: 0 gives 1; 1, 2, 5 give 2; 3, 6 give 3;
 * 4, 7 give 4; any other value 1) and the signal codes of the channels 0 to n-1 are appended. The list always
 * ends with the code 0xFF.
 * Called from ipc_8051_send_wake_port_table.
 */
unsigned char input_port_list_build(unsigned int list)
{
    unsigned char count = 0;
    unsigned char channels = 1;
    unsigned char i;

    if (sys_config.bit_31) {
        input_port_list_append(0x51, list, &count);
        input_port_list_append(0x61, list, &count);
        if (nvram_get_device_option_bit25() == 1)
            input_port_list_append(0x81, list, &count);
        else
            input_port_list_append(0x71, list, &count);
        if (nvram_get_device_option_bit25() == 1)
            input_port_list_append(0x71, list, &count);
        else
            input_port_list_append(0x81, list, &count);
    } else {
        switch (device_settings_pip_mode) {
        case 0: channels = 1; break;
        case 1: case 2: case 5: channels = 2; break;
        case 3: case 6: channels = 3; break;
        case 4: case 7: channels = 4; break;
        }
        for (i = 0; i < channels; i++)
            input_port_list_append(sys_get_channel_signal_code(i), list, &count);
    }
    input_port_list_append(PORT_LIST_END, list, &count);
    return count * RECORD_SIZE;
}
