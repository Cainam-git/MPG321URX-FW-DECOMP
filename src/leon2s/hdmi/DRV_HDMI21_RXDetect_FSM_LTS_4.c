/* DRV_HDMI21_RXDetect_FSM_LTS_4  (DRV_HDMI21_RXDetect_FSM_LTS_4)
 *
 * Run link training state 4 of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: proven - original name printed ('DRV_HDMI21_RXDetect_FSM_LTS_4')
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI21_RXDetect_FSM_LTS_4 @ 0xa00983ec, flags -mcpu=v8 -Os -g.
 * Source form: the port is masked in place (port &= 0xff) and the record is a struct with its one used
 * field after 0x30 bytes of padding.
 */
#define HDMI_MSG_HDMI21 0x800   /* debug message bit: '[HDMI21]' lines (dbg_hdmi_message_flags) */

#define RX_DETECT_LTS_L 7       /* state of the HDMI 2.1 receive state machine */

extern unsigned int dbg_hdmi_message_flags;
extern unsigned int hdmi_rx21_rx_detect_states[];   /* state of each HDMI 2.1 receiver */

/* One 0xb0-byte link-training record per receiver (only last_state is used here). */
struct hdmi_rx21_lts_record {
    unsigned char bytes_0x0_to_0x2f[0x30];
    unsigned int last_state;            /* +0x30: state last reported */
    unsigned char bytes_0x34_to_0xaf[0x7c];
};
extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];

extern char DAT_a00678c8[];
extern int dbg_printf(const char *, ...);

/* Link training state 4: goes straight on to state 7 (LTS_L). Prints its name when the state differs
 * from the last state reported for this receiver.
 *   port:   HDMI 2.1 receiver 0 or 1
 *   unused: not read
 * Returns 0. */
int DRV_HDMI21_RXDetect_FSM_LTS_4(unsigned char port, unsigned int unused)
{
    port &= 0xff;

    if (hdmi_rx21_rx_detect_states[port] != hdmi_rx21_lts_records[port].last_state) {
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21) {
            dbg_printf(DAT_a00678c8, "DRV_HDMI21_RXDetect_FSM_LTS_4");
        }
        hdmi_rx21_lts_records[port].last_state = hdmi_rx21_rx_detect_states[port];
    }

    hdmi_rx21_rx_detect_states[port] = RX_DETECT_LTS_L;
    return 0;
}
