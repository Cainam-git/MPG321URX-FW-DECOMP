/* dp_get_port_dsc_support  (FUN_a012b22c)
 *
 * Return the DSC flag of a DisplayPort input from device settings byte +0x32.
 * Returns: 0 or 1
 * Note: dp_set_port_dsc_support writes its bit into byte +0x33, not into the byte read here.
 * Name basis: derived - bit n of the port's nibble of device settings byte +0x32 (n = the port's nibble of
 *   byte +0x2C); read by SYSAPI_GetSystemDPDSCSupport
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012b22c @ 0xa012b22c-0xa012b260 (13 words), flags -mcpu=v8 -O3 -g.
 * Source form: `selection` is computed before `flags` (the source order decides the load order).
 */
/* The device settings record (0xA802E1A0, 0x50 bytes), the fields used here. */
struct device_settings_record {
    unsigned char unused_00[0x2c];
    unsigned char selection_nibbles;    /* +0x2C: one nibble per port, the bit number n of that port */
    unsigned char unused_2d[0x32 - 0x2d];
    unsigned char dsc_flag_nibbles;     /* +0x32: one nibble per port, bit n of the nibble is read here */
};
extern struct device_settings_record device_settings;

/*
 * Return the DSC flag of a DisplayPort port.
 *
 *   port  port number (0 or 1); its nibble is taken from settings bytes +0x2C and +0x32
 *
 * With n = nibble `port` of settings byte +0x2C, the result is bit n of nibble `port` of settings byte +0x32.
 * Called by SYSAPI_GetSystemDPDSCSupport.
 */
unsigned char dp_get_port_dsc_support(unsigned char port)
{
    unsigned char selection = (device_settings.selection_nibbles >> (port * 4)) & 0xf;
    unsigned char flags = (device_settings.dsc_flag_nibbles >> (port * 4)) & 0xf;

    return (flags >> selection) & 1;
}
