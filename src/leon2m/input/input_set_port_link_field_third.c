/* input_set_port_link_field_third  (FUN_a012af40)
 *
 * Store a port's third link setting in the settings and its link row, and send the row.
 * Name basis: descriptive - 2-bit field of settings halfword +0x2F or nibble of +0x31; mailbox command 0x21
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012af40 @ 0xa012af40-0xa012b078, flags -mcpu=v8 -O3 -g.
 * Source forms: the settings record is a packed struct with the halfwords +0x2D and +0x2F as 16-bit bit-fields; the
 * row is copied with memcpy (GCC expands it inline), which places the row address computation after the first
 * halfword load as in the firmware.
 */
/* The device settings record (0xA802E1A0, 0x50 bytes), the fields used here. */
struct __attribute__((packed, aligned(4))) device_settings_record {
    unsigned char unused_00[0x2c];
    unsigned char selection_nibbles;    /* +0x2C: one nibble per port, the selection n of that port */
    unsigned short halfword_0x2d:16;
    unsigned short halfword_0x2f:16;    /* +0x2F: a byte per port, each with a 2-bit field per selection */
    unsigned char byte_0x31;            /* +0x31: one nibble per port */
    unsigned char unused_32[0x50 - 0x32];
};
/* A port link row (0x16 bytes at port_link_rows); only the first two bytes are named here. */
struct port_link_row { unsigned char byte_0x00, byte_0x01; unsigned short rest[10]; };
extern struct device_settings_record device_settings;
extern struct port_link_row port_link_rows[];
extern void *memcpy(void *, const void *, unsigned int);
extern void ipc_set_dp_rx_mode(unsigned char, unsigned char *);

/*
 * Store `value` as link setting byte 0 of port `port` in the settings and in its link row, and send the row.
 *
 *   port   port number
 *   value  new value
 *
 * With n = nibble `port` of settings byte +0x2C: for n up to 2 the value goes into the 2-bit field n of the
 * port's byte in settings halfword +0x2F, for a larger n into nibble `port` of settings byte +0x31. Row byte 0
 * gets the value; the row is sent with ipc_set_dp_rx_mode (mailbox command 0x21). The settings record is not
 * saved here.
 */
void input_set_port_link_field_third(unsigned char port, unsigned char value)
{
    struct port_link_row row;
    unsigned char n = (device_settings.selection_nibbles >> (port * 4)) & 0xf;

    if (n <= 2)
        device_settings.halfword_0x2f = (device_settings.halfword_0x2f & ~((3 << (port * 8)) << (n * 2))) | ((value << (port * 8)) << (n * 2));
    else
        device_settings.byte_0x31 = (device_settings.byte_0x31 & ~(0xf << (port * 4))) | (value << (port * 4));
    port_link_rows[port].byte_0x00 = value;
    memcpy(&row, &port_link_rows[port], sizeof row);
    ipc_set_dp_rx_mode(port, (unsigned char *)&row);
}
