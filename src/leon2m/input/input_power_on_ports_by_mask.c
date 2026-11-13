/* input_power_on_ports_by_mask  (FUN_a0151aa4)
 *
 * Switch on the input ports selected by a mask and start their timers.
 * Name basis: derived - header: port switch-on by mask (mailbox command to the 8051, port timers)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0151aa4 @ 0xa0151aa4..0xa0151c84 (120 words), flags -mcpu=v8 -O3 -g.
 * Source form: plain if-chains as written, one per mask bit. The bit-31 test is the signed compare
 * (int) word >= 0.
 */

/* Mask bits of the port entries: mask bit n + 2 belongs to port entry n (bits 0, 1, 6 and 7 are not used here). */
#define PORT_MASK_ENTRY0     0x04
#define PORT_MASK_ENTRY1     0x08
#define PORT_MASK_ENTRY2     0x10
#define PORT_MASK_ENTRY3     0x20
/* Port timers started per entry (input_port_timer_start timer number, time value). */
#define PORT_TIMER_ENTRY0    4
#define PORT_TIMER_ENTRY1    5
#define PORT_TIMER_ENTRY2    6
#define PORT_TIMER_ENTRY3    7
#define PORT_TIMER_HDMI_TIME 1000               /* entries 0 and 1 */
#define PORT_TIMER_DP_TIME   800                /* entries 2 and 3 */

/* Port entry: byte +0x10 is the bus id. */
struct port_entry { unsigned short class_and_flags; unsigned char rest[14]; unsigned char bus_id, byte_0x11; };
extern struct port_entry port_entries[];
extern int device_settings;                     /* word 0 of the device settings record */
extern unsigned char input_is_port_cable_present(unsigned char);
extern void input_release_port_control_pin(unsigned char);
extern unsigned char input_port_table_get_bus_id(unsigned char);
extern void edid_set_port_internal_edid(unsigned char, unsigned char);
extern void ipc_restart_hdmi_port(unsigned char);
extern void input_port_timer_start(unsigned char, unsigned short);
extern unsigned char sys_return_zero_copy3(unsigned char);
extern void input_set_port_pin_function(unsigned char, unsigned char);
extern void sys_poll_events_stub_copy5(unsigned char, unsigned char);

/*
 * Switch on the input ports selected by a mask and start their port timers.
 *
 * mask: bits 0x04, 0x08, 0x10 and 0x20 select port entries 0..3, in this order of work; the other bits do
 *       nothing. The callers pass the mask bit of the port entry that belongs to a port code (0x51 gives
 *       0x04, 0x61 0x08, 0x71 0x10, 0x81 0x20); the start-up code passes 0xFF.
 * on:   1 = always switch the selected ports on. Any other value switches entries 0 and 1 on only when a
 *       cable is detected on them, and entries 2 and 3 only when bit 31 of device settings word 0 is clear or
 *       sys_return_zero_copy3 for the entry does not return 1.
 *
 * For every selected entry that qualifies: the control pin of the entry's port is released
 * (input_release_port_control_pin), then
 *  - entries 0 and 1: the internal EDID of the port is set as its stored flag says, the input processor is asked
 *    to restart the HDMI port (ipc_restart_hdmi_port 0 or 1), and port timer 4 or 5 is started with 1000;
 *  - entries 2 and 3: the pin function of input 0 or 1 is set to 0, the (empty) event source stub is called,
 *    and port timer 6 or 7 is started with 800.
 */
void input_power_on_ports_by_mask(unsigned char mask, unsigned char on)
{
    if (mask & PORT_MASK_ENTRY0) {
        if (on == 1 || input_is_port_cable_present(port_entries[0].bus_id)) {
            input_release_port_control_pin(port_entries[0].bus_id);
            edid_set_port_internal_edid(input_port_table_get_bus_id(port_entries[0].bus_id), 0);
            ipc_restart_hdmi_port(0);
            input_port_timer_start(PORT_TIMER_ENTRY0, PORT_TIMER_HDMI_TIME);
        }
    }
    if (mask & PORT_MASK_ENTRY1) {
        if (on == 1 || input_is_port_cable_present(port_entries[1].bus_id)) {
            input_release_port_control_pin(port_entries[1].bus_id);
            edid_set_port_internal_edid(input_port_table_get_bus_id(port_entries[1].bus_id), 0);
            ipc_restart_hdmi_port(1);
            input_port_timer_start(PORT_TIMER_ENTRY1, PORT_TIMER_HDMI_TIME);
        }
    }
    if (mask & PORT_MASK_ENTRY2) {
        if (on == 1 || device_settings >= 0 || sys_return_zero_copy3(0) != 1) {
            input_release_port_control_pin(port_entries[2].bus_id);
            input_set_port_pin_function(0, 0);
            sys_poll_events_stub_copy5(0, 0);
            input_port_timer_start(PORT_TIMER_ENTRY2, PORT_TIMER_DP_TIME);
        }
    }
    if (mask & PORT_MASK_ENTRY3) {
        if (on == 1 || device_settings >= 0 || sys_return_zero_copy3(1) != 1) {
            input_release_port_control_pin(port_entries[3].bus_id);
            input_set_port_pin_function(1, 0);
            sys_poll_events_stub_copy5(1, 0);
            input_port_timer_start(PORT_TIMER_ENTRY3, PORT_TIMER_DP_TIME);
        }
    }
}
