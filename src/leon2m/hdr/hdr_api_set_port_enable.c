/* hdr_api_set_port_enable  (FUN_a014b980)
 *
 * Switch the HDR handling on or off for one input port, or for all.
 * Name basis: derived - port codes 0x51/0x61/0x71/0x81; source 0xFE = all; called from UserSwitchEDID
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014b980, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: for the all-ports value the option test is written twice (the true
 * arm first both times); the single-port part is a switch on the entry index with a case for each of 0..3.
 */
#define PORT_CODE_ENTRY0 0x51   /* port codes of port entries 0..3 */
#define PORT_CODE_ENTRY1 0x61
#define PORT_CODE_ENTRY2 0x71
#define PORT_CODE_ENTRY3 0x81

#define SOURCE_ALL 0xfe         /* source value that means every port */

extern int input_port_table_find_code(unsigned char);
extern int input_find_port_entry_by_bus_id(unsigned char);
extern unsigned char nvram_get_device_option_bit25(void);
extern void ipc_set_hdr_source_enable(unsigned char port, unsigned char v);

/*
 * Switch the HDR handling of one input port, or of all of them, on or off (the request goes to the input
 * processor).
 *
 *   source  port code of the source, or SOURCE_ALL; a source is turned into a port entry 0..3 and entries
 *           other than 0..3 do nothing
 *   enable  the value passed on
 *
 * For SOURCE_ALL the four port codes are sent in turn; when device option bit 25 is set, the codes of
 * entries 3 and 2 are sent in swapped order (0x81 before 0x71).
 * Called by UserSwitchEDID.
 */
void hdr_api_set_port_enable(unsigned char source, unsigned char enable)
{
    if (source == SOURCE_ALL) {
        ipc_set_hdr_source_enable(PORT_CODE_ENTRY0, enable);
        ipc_set_hdr_source_enable(PORT_CODE_ENTRY1, enable);
        if (nvram_get_device_option_bit25() == 1)
            ipc_set_hdr_source_enable(PORT_CODE_ENTRY3, enable);
        else
            ipc_set_hdr_source_enable(PORT_CODE_ENTRY2, enable);
        if (nvram_get_device_option_bit25() == 1)
            ipc_set_hdr_source_enable(PORT_CODE_ENTRY2, enable);
        else
            ipc_set_hdr_source_enable(PORT_CODE_ENTRY3, enable);
        return;
    }
    switch ((unsigned char)input_find_port_entry_by_bus_id(input_port_table_find_code(source))) {
    case 0:
        ipc_set_hdr_source_enable(PORT_CODE_ENTRY0, enable);
        break;
    case 1:
        ipc_set_hdr_source_enable(PORT_CODE_ENTRY1, enable);
        break;
    case 2:
        ipc_set_hdr_source_enable(PORT_CODE_ENTRY2, enable);
        break;
    case 3:
        ipc_set_hdr_source_enable(PORT_CODE_ENTRY3, enable);
        break;
    }
}
