/* edid_enable_internal_edid  (FUN_a01253bc)
 *
 * Switch the internal EDID of a port on or off and remember the choice.
 * Name basis: proven - calls the routine that prints 'Enable Internal EDID', or its counterpart
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01253bc @ 0xa01253bc, flags -mcpu=v8 -O3 -g.
 * Source form: the lookup of the EDID base is a static helper (port_edid_base) that the compiler inlines; the
 * firmware has no call to edid_get_port_memory_base here. The last call of each arm is a tail call.
 */
/* One 0x16-byte record of the port table (docs/DATA.md); only the EDID base is read here. */
struct port_table_entry {
    unsigned char code, type, bus_id, byte_0x03;    /* +0..+3 */
    unsigned short edid_size;                       /* +4 */
    unsigned short edid_base;                       /* +6: base of the EDID memory */
    unsigned char rest[14];                         /* +8..+0x15 */
};
extern unsigned char port_table_index_by_bus_id[];                /* row in port_table by bus id; 0xff = no row */
extern struct port_table_entry port_table[];
extern unsigned char edid_internal_enabled_bits;
extern unsigned char device_settings[];
extern const unsigned short edid_variant_lengths[];
extern int edid_get_port_size(unsigned int);
extern void ipc_8051_disable_internal_edid(unsigned char);
extern void ipc_8051_enable_internal_edid(unsigned char, unsigned short, unsigned char);

#define NO_ROW                0xff
#define NO_EDID               0xffff
#define EDID_CHOICE_OFFSET    0x1b      /* device_settings byte of port 0 that picks the EDID variant */
#define NO_EDID_CHOICE        0xff      /* the length then comes from edid_get_port_size */

/* Same lookup as edid_get_port_memory_base. */
static unsigned short port_edid_base(unsigned char bus_id)
{
    unsigned char row = port_table_index_by_bus_id[bus_id];
    unsigned short base = NO_EDID;
    if (row != NO_ROW)
        base = port_table[row].edid_base;
    return base;
}

/*
 * Switch the internal EDID of the input with this bus id on (on != 0) or off, and record it in bit `bus_id` of
 * edid_internal_enabled_bits.
 * On: tell the 8051 (ipc_8051_enable_internal_edid) the port bit, the EDID length and the EDID base divided by 128.
 * The length is edid_variant_lengths[] of the variant stored in device_settings[0x1b + bus_id], or
 * edid_get_port_size when that byte is 0xff.
 * Off: tell the 8051 to switch it off (ipc_8051_disable_internal_edid).
 * Called by edid_api_enable_internal_edid.
 */
void edid_enable_internal_edid(unsigned char bus_id, unsigned char on)
{
    unsigned short edid_base, length;

    if (on) {
        edid_internal_enabled_bits |= 1 << bus_id;
        edid_base = port_edid_base(bus_id);
        if (device_settings[EDID_CHOICE_OFFSET + bus_id] == NO_EDID_CHOICE)
            length = edid_get_port_size(bus_id);
        else
            length = edid_variant_lengths[device_settings[EDID_CHOICE_OFFSET + bus_id]];
        ipc_8051_enable_internal_edid(1 << bus_id, length, edid_base >> 7);
    } else {
        edid_internal_enabled_bits &= ~(1 << bus_id);
        ipc_8051_disable_internal_edid(1 << bus_id);
    }
}
