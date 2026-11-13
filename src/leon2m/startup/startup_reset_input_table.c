/* startup_reset_input_table  (FUN_a0141b60)
 *
 * Reset the seven-entry input table.
 * Name basis: derived - called from start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0141b60 @ 0xa0141b60, flags -mcpu=v8 -O3 -g.
 * Source form: bit-fields for bit 7 and the 4-bit type of halfword 0, a u8 loop counter, the stores to entries 0
 * and 1 before the call, entry 2 before entry 3 in both arms, and the 0xFC..0xFE stores written before the four
 * type stores.
 */

#define PORT_ENTRY_COUNT    7       /* entries of port_entries */
#define PORT_TYPE_RESET     2       /* type given to entries 0..3 */
#define BUS_ID_ENTRY_4      0xfc    /* bus ids of entries 4, 5 and 6 */
#define BUS_ID_ENTRY_5      0xfd
#define BUS_ID_ENTRY_6      0xfe

/* One port entry (0x12 bytes, docs/DATA.md): the inputs as the control logic sees them. */
struct port_entry {
    unsigned short type:4,              /* +0, bits 15..12: the class of the entry */
                   bit_11:1, bit_10:1, bit_9:1, bit_8:1,
                   flag_bit_7:1,        /* cleared in every entry here */
                   low_bits:7;
    unsigned char other[14];
    unsigned char bus_id;               /* +0x10 */
    unsigned char byte_0x11;
};
extern struct port_entry port_entries[];
extern unsigned int nvram_get_device_option_bit25(void);

/*
 * Reset the seven port entries at power-on (phase 5 of the system start-up, after the default records and the
 * stored settings and before the clock blocks):
 *   - bit 7 of halfword 0 is cleared in all seven;
 *   - bus ids: entry 0 gets 3, entry 1 gets 4, entries 4, 5 and 6 get 0xFC, 0xFD and 0xFE; entries 2 and 3 get
 *     5 and 6 when nvram_get_device_option_bit25 (bit 25 of the first word of the device settings record) is set
 *     and 6 and 5 when it is clear, so one configuration bit swaps the two;
 *   - the type (class) of entries 0..3 is set to 2.
 * RAM only; it cannot fail or wait. Called by the system start-up (startup_bring_up_system).
 */
void startup_reset_input_table(void)
{
    unsigned char i;
    for (i = 0; i < PORT_ENTRY_COUNT; i++)
        port_entries[i].flag_bit_7 = 0;
    port_entries[0].bus_id = 3;
    port_entries[1].bus_id = 4;
    if (nvram_get_device_option_bit25() & 0xff) {
        port_entries[2].bus_id = 5;
        port_entries[3].bus_id = 6;
    } else {
        port_entries[2].bus_id = 6;
        port_entries[3].bus_id = 5;
    }
    port_entries[4].bus_id = BUS_ID_ENTRY_4;
    port_entries[5].bus_id = BUS_ID_ENTRY_5;
    port_entries[6].bus_id = BUS_ID_ENTRY_6;
    port_entries[0].type = PORT_TYPE_RESET;
    port_entries[1].type = PORT_TYPE_RESET;
    port_entries[2].type = PORT_TYPE_RESET;
    port_entries[3].type = PORT_TYPE_RESET;
}
