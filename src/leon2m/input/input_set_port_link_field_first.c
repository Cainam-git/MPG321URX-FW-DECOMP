/* input_set_port_link_field_first  (FUN_a012add8)
 *
 * Store a port's first link setting in the settings and its link row, and send the row.
 * Name basis: descriptive - nibble of settings byte +0x2C, row bytes 0..2; mailbox command 0x21
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012add8 @ 0xa012add8-0xa012af40, flags -mcpu=v8 -O3 -g.
 * Source forms: the settings record is a packed struct with the halfwords +0x2D and +0x2F as 16-bit bit-fields (the
 * loads and stores are byte accesses); the row is copied to a local with a structure copy before the send.
 */
/* The device settings record (0xA802E1A0, 0x50 bytes), the fields used here. */
struct __attribute__((packed, aligned(4))) device_settings_record {
    unsigned char unused_00[0x2c];
    unsigned char selection_nibbles;    /* +0x2C: one nibble per port, the selection n of that port */
    unsigned short halfword_0x2d:16;    /* +0x2D: a byte per port, each with a 2-bit field per selection */
    unsigned short halfword_0x2f:16;    /* +0x2F: same layout */
    unsigned char byte_0x31, byte_0x32, byte_0x33;      /* one nibble per port */
    unsigned char unused_34[0x50 - 0x34];
};
/* A port link row (0x16 bytes at port_link_rows); only the first 16 bytes are named here. */
struct port_link_row {
    unsigned char byte_0x00, byte_0x01, byte_0x02, byte_0x03, byte_0x04, byte_0x05, byte_0x06, byte_0x07;
    unsigned short rest[7];
};
extern struct device_settings_record device_settings;
extern struct port_link_row port_link_rows[];
extern void ipc_set_dp_rx_mode(unsigned char, unsigned char *);

/*
 * Store selection n for port `port` and reload the link row of that port from the settings.
 *
 *   port  port number
 *   n     the selection, stored in nibble `port` of settings byte +0x2C
 *
 * Row byte 2 gets n. Row bytes 0 and 1 get the 2-bit field n of the port's byte in settings halfwords +0x2F and
 * +0x2D; for n above 2 row byte 0 gets nibble `port` of settings byte +0x31 instead. Row bytes 7 and 6 get bit n
 * of nibble `port` of settings bytes +0x32 and +0x33. The row is then sent with ipc_set_dp_rx_mode (mailbox
 * command 0x21). The settings record itself is not saved here.
 */
void input_set_port_link_field_first(unsigned char port, unsigned int n)
{
    struct port_link_row row;

    device_settings.selection_nibbles = (device_settings.selection_nibbles & ~(0xf << (port * 4))) | (n << (port * 4));
    port_link_rows[port].byte_0x02 = n;
    port_link_rows[port].byte_0x00 = n <= 2 ? ((unsigned char)(device_settings.halfword_0x2f >> (port * 8)) >> (n * 2)) & 3
                                            : (device_settings.byte_0x31 >> (port * 4)) & 0xf;
    port_link_rows[port].byte_0x01 = ((unsigned char)(device_settings.halfword_0x2d >> (port * 8)) >> (n * 2)) & 3;
    port_link_rows[port].byte_0x07 = (((device_settings.byte_0x32 >> (port * 4)) & 0xf) >> n) & 1;
    port_link_rows[port].byte_0x06 = (((device_settings.byte_0x33 >> (port * 4)) & 0xf) >> n) & 1;
    row = port_link_rows[port];
    ipc_set_dp_rx_mode(port, (unsigned char *)&row);
}
