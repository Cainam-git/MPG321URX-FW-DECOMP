/* hdcp_rx_update_port_status  (FUN_a00c3144)
 *
 * Update an input's bit in the status mask and its state byte, with a time-out.
 * Name basis: descriptive - mask at 0xA8078C5B
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c3144 @ 0xa00c3144-0xa00c32bc, flags -mcpu=v8 -Os -g.
 * Source form: in the state-13 arm the state byte is set to 1 before the mask update.
 */
/* Record of input_port_records (20 bytes): link state at +0, flags halfword at +0x12. */
struct port_record { unsigned char state; unsigned char pad[0x11]; unsigned short flags_0x12; };
/* The 16-byte hdcp_rx_record_hdmi20 entry: only the state byte at +0xD is used here. */
struct hdcp_rx_record { unsigned char pad[0xd]; unsigned char state; unsigned char rest[2]; };
extern struct port_record input_port_records[];
extern struct hdcp_rx_record hdcp_rx_record_hdmi20[];
extern unsigned char hdcp_rx_port_state_bytes[];
extern unsigned int hdcp_rx_port_status_ticks[];
extern unsigned char hdcp_rx_status_mask;
extern unsigned int timer_get_ticks(void);
extern unsigned int hdcp_rx_is_port_authenticated(unsigned char);

#define LINK_STATE_STANDBY      3               /* 'LINK_STANDBY' */
#define PORT_FLAG_BIT7          0x80            /* bit 7 of flags_0x12 */
#define HDCP_RX_STATE_STARTED   2               /* first state with the status bit set; states 2..12 set it */
#define HDCP_RX_STATE_AUTHED    13              /* 'HDCP22 AUTHED'; clears the bit and arms the hold time */
#define STATUS_HOLD_TICKS       699             /* the bit stays set this long after arming */

/*
 * Keep bit `port` of hdcp_rx_status_mask (the status bit of the input; the port-flag routines
 * hdmi_update_port_status_flags and its HDMI 2.1 and DisplayPort twins publish it) up to date.
 * hdcp_rx_port_state_bytes[port] is 1 while the hold time is armed; hdcp_rx_port_status_ticks[port] is the time
 * stamp of the hold.
 *
 * Order of the rules:
 *   - the state byte is cleared when bit 7 of the port record's flags is clear;
 *   - while the state byte is 1 and the port record's link state is 3 the time stamp is renewed;
 *   - if hdcp_rx_is_port_authenticated(port) is 1: the bit is cleared and the state byte cleared;
 *   - else while the state byte is 1 and not more than STATUS_HOLD_TICKS have passed since the time stamp:
 *     the bit is set;
 *   - else by the state of the input's protection record: states 2..12 set the bit; state 13 clears the bit and
 *     arms the hold (state byte 1); any other state clears the bit and the state byte.
 *
 * Called at the end of each pass of the protection tasks (hdcp_rx_hdmi_task, hdcp_rx_hdmi21_task, hdcp_rx_dp_task).
 */
void hdcp_rx_update_port_status(unsigned char port)
{
    unsigned char state;

    if ((input_port_records[port].flags_0x12 & PORT_FLAG_BIT7) == 0)
        hdcp_rx_port_state_bytes[port] = 0;
    if (hdcp_rx_port_state_bytes[port] == 1 && input_port_records[port].state == LINK_STATE_STANDBY)
        hdcp_rx_port_status_ticks[port] = timer_get_ticks();
    if ((unsigned char)hdcp_rx_is_port_authenticated(port) == 1) {
        hdcp_rx_status_mask &= ~(1 << port);
        hdcp_rx_port_state_bytes[port] = 0;
        return;
    }
    if (hdcp_rx_port_state_bytes[port] == 1 && timer_get_ticks() - hdcp_rx_port_status_ticks[port] <= STATUS_HOLD_TICKS) {
        hdcp_rx_status_mask |= 1 << port;
        return;
    }
    state = hdcp_rx_record_hdmi20[port].state;
    if ((unsigned char)(state - HDCP_RX_STATE_STARTED) <= 10) {
        hdcp_rx_status_mask |= 1 << port;
    } else if (state == HDCP_RX_STATE_AUTHED) {
        hdcp_rx_port_state_bytes[port] = 1;
        hdcp_rx_status_mask &= ~(1 << port);
    } else {
        hdcp_rx_status_mask &= ~(1 << port);
        hdcp_rx_port_state_bytes[port] = 0;
    }
}
