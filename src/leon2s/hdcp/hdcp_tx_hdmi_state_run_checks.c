/* hdcp_tx_hdmi_state_run_checks  (FUN_a00ccdb4)
 *
 * State handler: read the receiver's capability and key selection, send the random value and own key.
 * Note: A failing step gives 'again' (the state runs again), not a failure.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_hdmi_run_state; calls hdcp_tx_hdmi_read_bcaps,
 *   hdcp_tx_hdmi_generate_an, hdcp_tx_hdmi_read_bksv, hdcp_tx_hdmi_write_an, hdcp_tx_hdmi_write_aksv
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ccdb4 @ 0xa00ccdb4-0xa00ccf0c, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - one if per failing step, each with its own 'step_result = STEP_AGAIN; return;';
 *  - the register update has its own if/else on bit 18 (last argument 0 or 1) instead of passing the bit;
 *  - the 8-byte buffers are declared in the order c, a, then the one-byte b.
 */

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
struct hdcp_tx_record {
    unsigned int bits_19_31 : 13;
    unsigned int bit18 : 1;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned int state_and_count : 16;  /* +2 state, +3 device_count */
    unsigned char rest[20];
};

/* Result of a state handler. hdcp_tx_select_next_state picks the next state from it; for this state (0x11):
   STEP_NEXT -> 0x12, STEP_AGAIN -> state kept. */
enum {
    STEP_NEXT  = 1,
    STEP_AGAIN = 3
};

#define AN_LENGTH           8           /* bytes of the session's random value, and of the DDC reads */
#define REG_0x12F           0x12f       /* register of bank 0 of the HDMI transmitter: bit 0 follows bit 18 */

extern struct hdcp_tx_record hdcp_tx_records[];
extern void hdcp_tx_disable_output(unsigned char);
extern unsigned int hdmi_tx_ddc_start_edid_tail(unsigned char, unsigned int);
extern int hdmi_tx_ddc_read(unsigned int, unsigned char *, unsigned short);
extern void hdmi_tx_reg_update_bits(unsigned char, int, int, int, int);
extern unsigned int hdmi_tx_ddc_reset(unsigned char);
extern unsigned char hdmi_tx_ddc_read_at(unsigned char, unsigned char *);
extern void hdcp_tx_hdmi_pulse_reg0f_bit2(unsigned char, unsigned char);
extern int hdcp_tx_hdmi_read_bcaps(unsigned int, unsigned char *);
extern void hdcp_tx_hdmi_set_repeater_bits(unsigned char);
extern void hdcp_tx_hdmi_generate_an(unsigned int, unsigned char *, unsigned char);
extern unsigned int hdcp_tx_hdmi_read_bksv(unsigned char);
extern void hdcp_tx_hdmi_write_an(unsigned int, unsigned char *);
extern void hdcp_tx_hdmi_write_aksv(unsigned char);

/*
 * State 0x11 of an HDMI output: reset the output's protection, read the downstream device's capability byte
 * and key-selection value, and send it the session's random value and the monitor's own key-selection value.
 *
 *   port  the HDMI output, 0 or 1
 *
 * Called by hdcp_tx_hdmi_run_state in state 0x11. The result is step_result: STEP_NEXT when every step
 * worked; STEP_AGAIN at the first step that fails (the state is kept and the handler runs again).
 *
 * In order:
 *   1. hdcp_tx_disable_output; read 8 bytes through the DDC into the buffer a (hdmi_tx_ddc_start_edid_tail,
 *      hdmi_tx_ddc_read; their results are not tested); bit 0 of register 0x12F of the HDMI transmitter
 *      (bank 0) is set when bit 18 of the record is set, else cleared.
 *   2. Each of these fails with STEP_AGAIN when it returns non-zero: hdmi_tx_ddc_reset, hdmi_tx_ddc_read_at
 *      (8 bytes into the buffer c, which is not used again).
 *   3. Pulse bit 2 of register 0x0F (hdcp_tx_hdmi_pulse_reg0f_bit2 with 1); read the capability byte
 *      (hdcp_tx_hdmi_read_bcaps; fails with STEP_AGAIN); hdcp_tx_hdmi_set_repeater_bits.
 *   4. Let the engine make the random value into buffer a (overwriting the 8 bytes of step 1); read the
 *      receiver's key-selection value (hdcp_tx_hdmi_read_bksv; fails with STEP_AGAIN).
 *   5. Send the random value (hdcp_tx_hdmi_write_an), then the monitor's own key-selection value
 *      (hdcp_tx_hdmi_write_aksv).
 */
void hdcp_tx_hdmi_state_run_checks(unsigned char port)
{
    unsigned char buffer_c[AN_LENGTH];
    unsigned char buffer_a[AN_LENGTH];
    unsigned char capability;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    hdcp_tx_disable_output(port);
    hdmi_tx_ddc_start_edid_tail(port, 0);
    hdmi_tx_ddc_read(port, buffer_a, AN_LENGTH);
    if (hdcp_tx_records[port].bit18 == 0)
        hdmi_tx_reg_update_bits(port, 0, REG_0x12F, 1, 0);
    else
        hdmi_tx_reg_update_bits(port, 0, REG_0x12F, 1, 1);
    if ((unsigned char)hdmi_tx_ddc_reset(port) != 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    if (hdmi_tx_ddc_read_at(port, buffer_c) != 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    hdcp_tx_hdmi_pulse_reg0f_bit2(port, 1);
    if ((unsigned char)hdcp_tx_hdmi_read_bcaps(port, &capability) != 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    hdcp_tx_hdmi_set_repeater_bits(port);
    hdcp_tx_hdmi_generate_an(port, buffer_a, 0);
    if ((unsigned char)hdcp_tx_hdmi_read_bksv(port) != 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    hdcp_tx_hdmi_write_an(port, buffer_a);
    hdcp_tx_hdmi_write_aksv(port);
}
