/* input_api_set_port_signal  (FUN_a014b4b4)
 *
 * Switch the signal of all seven input slots on or off (source 0xFE); any other source sends nothing.
 * Note: Per slot: 8051 command 0x1F with mask 1 << slot when the slot's internal EDID is enabled, else a
 *   direct GPIO write (table bytes 8, 9, 10).
 * Name basis: descriptive - loop over slots 0..6 for source 0xFE; for another source first slot = last slot
 *   and the loop body does not run
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014b4b4 @ 0xa014b4b4-0xa014b65c (106 words), flags -mcpu=v8 -O3 -g -msoft-float (with -O3 -g the
 * 'mov 1' of '1 << slot' is hoisted out of the loop; the firmware sets it in every pass).
 * Source form: input_get_port_bus_id is the matched neighbour input_get_port_bus_id, defined here as a static copy and
 * inlined (GCC copies its table lookup into the entry 1 path); first_slot/last_slot are set in both arms of
 * 'if (port_code == ALL_PORTS) ... else ...' (presetting them before an 'if (port_code != ALL_PORTS)' gives
 * another block layout).
 */

#define ALL_PORTS  0xfe                         /* port_code value that stands for all slots */
#define SLOT_COUNT 7                            /* slots 0..6 */

/* Port entry: byte +0x10 is the bus id. */
struct port_entry { unsigned char pad00[0x10]; unsigned char bus_id; unsigned char byte_0x11; };
extern struct port_entry port_entries[];
extern int input_port_table_find_code(unsigned char);
extern unsigned char input_find_port_entry_by_bus_id(unsigned char entry_index);
extern unsigned char input_entry_index_to_port_code(unsigned char entry_index);
extern unsigned char input_port_table_get_bus_id(unsigned int port_entry_bus_id);

extern unsigned char edid_is_internal_edid_enabled(unsigned char);
extern void ipc_8051_set_edid_slave_bit6(unsigned char, unsigned char);
extern unsigned char input_slot_get_table_byte8(unsigned char);
extern unsigned char input_slot_get_table_byte9(unsigned char);
extern unsigned char input_slot_get_table_byte10(unsigned char);
extern void gpio_write_pin(unsigned char gpio_port, unsigned char pin_mask, unsigned char level);

/*
 * The bus id (port table byte +2) of the port entry that belongs to a port code. The entry is chosen by the
 * port code of the input: 0x61 gives entry 1, 0x71 entry 2, 0x81 entry 3, anything else entry 0.
 */
static unsigned char input_get_port_bus_id(unsigned char port_code)
{
    unsigned char code = input_entry_index_to_port_code(input_find_port_entry_by_bus_id(input_port_table_find_code(port_code)));
    unsigned char entry = 0;

    switch (code) {
    case 0x51:
        entry = 0;
        break;
    case 0x61:
        entry = 1;
        break;
    case 0x71:
        entry = 2;
        break;
    case 0x81:
        entry = 3;
        break;
    }
    return input_port_table_get_bus_id(port_entries[entry & 3].bus_id);
}

/*
 * Switch the signal of input slots on or off.
 *
 * port_code: ALL_PORTS (0xFE) runs the loop over slots 0..6. Any other value sets the first and the last slot
 *            both to the bus id of that port's entry, so the loop body is not run and nothing is sent.
 * on:        1 = on, 0 = off.
 *
 * Per slot: if the slot's internal EDID is enabled, the 8051 is asked (command 0x1F, ipc_8051_set_edid_slave_bit6)
 * to set or clear bit 6 of the EDID slave control register for the port mask 1 << slot. Otherwise the slot's pin is written directly:
 * table bytes 8, 9 and 10 of the slot are the GPIO port, pin mask and level; the level is inverted when
 * switching off.
 * Callers pass ALL_PORTS; on = 0 comes only from sys_clear_factory_mode_flag, after it clears bit 14 of user
 * settings word 0.
 */
void input_api_set_port_signal(unsigned char port_code, unsigned char on)
{
    unsigned char slot, first_slot, last_slot;

    if (port_code == ALL_PORTS) {
        first_slot = 0;
        last_slot = SLOT_COUNT;
    } else {
        last_slot = input_get_port_bus_id(port_code);
        first_slot = last_slot;
    }
    for (slot = first_slot; slot < last_slot; slot++) {
        if (edid_is_internal_edid_enabled(slot))
            ipc_8051_set_edid_slave_bit6(1 << slot, on);
        else if (on)
            gpio_write_pin(input_slot_get_table_byte8(slot), input_slot_get_table_byte9(slot), input_slot_get_table_byte10(slot));
        else
            gpio_write_pin(input_slot_get_table_byte8(slot), input_slot_get_table_byte9(slot), ~input_slot_get_table_byte10(slot));
    }
}
