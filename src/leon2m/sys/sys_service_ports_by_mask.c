/* sys_service_ports_by_mask  (FUN_a01519d8)
 *
 * Run the service calls for the port group selected by sel (4, 8, 0x10 or 0x20).
 * Name basis: descriptive - switch on sel with per-entry calls
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01519d8 (-mcpu=v8 -O3 -g, the section default).
 * Source form: a switch on the mask value; port_entries is an array of 18-byte entries whose port number is at +0x10.
 */
/* Port entry (0x12 bytes); only the port number at +0x10 is used here. */
struct port_entry { unsigned short h0; unsigned char rest[14]; unsigned char port, b11; };
extern struct port_entry port_entries[];
extern unsigned char input_port_table_get_bus_id(unsigned char);
extern void edid_set_port_internal_edid(unsigned char, unsigned char);
extern void input_assert_port_control_pin(unsigned int);
extern void input_set_port_pin_function(unsigned char, unsigned char);
extern void sys_poll_events_stub_copy5(unsigned char, unsigned char);

#define PORT_MASK_ENTRY0 0x04   /* mask bit of port entry 0; entries 1..3 are 0x08, 0x10, 0x20 */
#define PORT_MASK_ENTRY1 0x08
#define PORT_MASK_ENTRY2 0x10
#define PORT_MASK_ENTRY3 0x20

/*
 * Service the port entry that a mask bit stands for; any other value does nothing.
 *
 *   mask  0x04 and 0x08: switch the internal EDID of the port of entry 0 or 1 (looked up through its bus id) with
 *         the value 1, then drive the control pin of that port.
 *         0x10 and 0x20: call the empty routine sys_poll_events_stub_copy5 with (0, 1) or (1, 1), drive the
 *         control pin of the port of entry 2 or 3, then switch pin function of input 0 or 1 with (0, 1) or (1, 1).
 *
 * Callers: App_Initialize (twice), sys_main_loop_periodic_task.
 */
void sys_service_ports_by_mask(unsigned char mask)
{
    switch (mask) {
    case PORT_MASK_ENTRY0:
        edid_set_port_internal_edid(input_port_table_get_bus_id(port_entries[0].port), 1);
        input_assert_port_control_pin(port_entries[0].port);
        break;
    case PORT_MASK_ENTRY1:
        edid_set_port_internal_edid(input_port_table_get_bus_id(port_entries[1].port), 1);
        input_assert_port_control_pin(port_entries[1].port);
        break;
    case PORT_MASK_ENTRY2:
        sys_poll_events_stub_copy5(0, 1);
        input_assert_port_control_pin(port_entries[2].port);
        input_set_port_pin_function(0, 1);
        break;
    case PORT_MASK_ENTRY3:
        sys_poll_events_stub_copy5(1, 1);
        input_assert_port_control_pin(port_entries[3].port);
        input_set_port_pin_function(1, 1);
        break;
    }
}
