/* input_set_port_link_flag_row7  (FUN_a012b164)
 *
 * Store a port's on/off link flag (row byte 7) and send the row.
 * Name basis: descriptive - bit of settings byte +0x32; mailbox command 0x21
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012b164 @ 0xa012b164-0xa012b328, flags -mcpu=v8 -O3 -g.
 */
/* The device settings record (0xA802E1A0, 0x50 bytes), the fields used here. */
struct device_settings_record {
    unsigned char unused_00[0x2c];
    unsigned char selection_nibbles;    /* +0x2C: one nibble per port, the selection n of that port */
    unsigned char unused_2d[5];
    unsigned char byte_0x32;            /* +0x32: one nibble per port, one bit per selection */
    unsigned char unused_33[0x50 - 0x33];
};
/* A port link row (0x16 bytes at port_link_rows); only byte 7 is named here. */
struct port_link_row {
    unsigned short halfword_0x00, halfword_0x02, halfword_0x04;
    unsigned char byte_0x06, byte_0x07;
    unsigned short rest[7];
};
extern struct device_settings_record device_settings;
extern struct port_link_row port_link_rows[];
extern void ipc_set_dp_rx_mode(unsigned char, unsigned char *);

/*
 * Store flag `value` as link row byte 7 of port `port`, in the settings and in its link row, and send the row.
 *
 *   port   port number
 *   value  new value (one bit is stored in the settings)
 *
 * With n = nibble `port` of settings byte +0x2C, the value goes into bit n of nibble `port` of settings byte
 * +0x32. The row is sent with ipc_set_dp_rx_mode (mailbox command 0x21). The settings record is not saved here.
 */
void input_set_port_link_flag_row7(unsigned char port, unsigned char value)
{
    struct port_link_row row;
    struct device_settings_record *settings = &device_settings;
    unsigned char n = (settings->selection_nibbles >> (port * 4)) & 0xf;

    settings->byte_0x32 = (settings->byte_0x32 & ~((1 << (port * 4)) << n)) | ((value << (port * 4)) << n);
    port_link_rows[port].byte_0x07 = value;
    row = port_link_rows[port];
    ipc_set_dp_rx_mode(port, (unsigned char *)&row);
}
