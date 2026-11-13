/* edid_get_port_memory_base  (FUN_a0125380)
 *
 * Return the base address of an input's EDID memory.
 * Returns: address or 0xFFFF
 * Name basis: derived - halfword +6 of the port table entry of the slot
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125380 @ 0xa0125380, flags -mcpu=v8 -O3 -g (also exact with -msoft-float; -O2 gives other code).
 * Source form: the port table record is a plain struct (u16 at +6), which lets the compiler fold the stride;
 * a byte-pointer cast form `*(u16 *)(table + row * 0x16 + 6)` gives different code (no hoisted address).
 * The result is an unsigned short (the firmware shifts left and right by 16 on return).
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

#define NO_ROW      0xff
#define NO_EDID     0xffff      /* returned when the bus id has no row */

/*
 * Return the base address of the EDID memory of the input with this bus id (+6 of its port table row), or
 * 0xffff when no row has that bus id.
 * Called by edid_read_port_edid, edid_write_port_edid, startup_load_port_edids and edid_set_port_internal_edid.
 */
unsigned short edid_get_port_memory_base(unsigned char bus_id)
{
    unsigned char row = port_table_index_by_bus_id[bus_id];
    unsigned short base = NO_EDID;
    if (row != NO_ROW)
        base = port_table[row].edid_base;
    return base;
}
