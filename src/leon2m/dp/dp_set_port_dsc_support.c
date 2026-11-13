/* dp_set_port_dsc_support  (FUN_a012b260)
 *
 * Store whether DSC is enabled for a DisplayPort input and send the port's link row.
 * Note: The bit goes to device settings byte +0x33; dp_get_port_dsc_support reads byte +0x32.
 * Name basis: derived - bit of settings byte +0x33, row byte 6; mailbox command 0x20
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012b260 @ 0xa012b260-0xa012b328 (50 words), flags -mcpu=v8 -O3 -g.
 * Source form: as input_set_port_link_field_second (same row copy); the settings are accessed through a struct
 * pointer.
 */
/* The device settings record (0xA802E1A0, 0x50 bytes), the fields used here. */
struct device_settings_record {
    unsigned char unused_00[0x2c];
    unsigned char selection_nibbles;    /* +0x2C: one nibble per port, the bit number n of that port */
    unsigned char unused_2d[5];
    unsigned char byte_0x32;
    unsigned char dsc_bits;             /* +0x33: written here, bit (4 * port + n) */
    unsigned char unused_34[0x50 - 0x34];
};
/* A port link row (0x16 bytes at port_link_rows); only the first bytes are named here. */
struct port_link_row {
    unsigned short half_0x00, half_0x02, half_0x04;
    unsigned char dsc_flag;             /* +6 */
    unsigned char byte_0x07;
    unsigned short rest[7];
};
extern struct device_settings_record device_settings;
extern struct port_link_row port_link_rows[];
extern void ipc_set_dp_rx_config(unsigned char, unsigned char *);

/*
 * Store the DSC flag of a DisplayPort port in the settings and in its link row, and send the row.
 *
 *   port   port number (0 or 1)
 *   value  new flag value
 *
 * With n = nibble `port` of settings byte +0x2C, bit (4 * port + n) of settings byte +0x33 is set to `value`.
 * Row byte 6 gets the value; the row is then sent with ipc_set_dp_rx_config (mailbox command 0x20). The settings
 * record is not saved here. Called by dp_api_set_dsc_support.
 */
void dp_set_port_dsc_support(unsigned char port, unsigned char value)
{
    struct port_link_row row;
    struct device_settings_record *settings = &device_settings;
    unsigned char n = (settings->selection_nibbles >> (port * 4)) & 0xf;

    settings->dsc_bits = (settings->dsc_bits & ~((1 << (port * 4)) << n)) | ((value << (port * 4)) << n);
    port_link_rows[port].dsc_flag = value;
    row = port_link_rows[port];
    ipc_set_dp_rx_config(port, (unsigned char *)&row);
}
