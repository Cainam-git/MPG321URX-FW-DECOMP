/* hdcp_tx_hdmi_run_state  (FUN_a00d03a0)
 *
 * Call the handler for the current state of an HDMI output's handshake.
 * Name basis: derived - switch on the state byte 0..0x4F of the port record
 *
 * Matching notes
 * --------------
 * leon2s hdcp_tx_hdmi_run_state @ 0xa00d03a0-0xa00d0530, flags -mcpu=v8 -Os -g.
 * The switch on the state byte (values 0..0x4F, 27 case labels) compiles to the 80-entry jump table
 * hdcp_tx_hdmi_run_state_jump_table at 0xa00d0260; the code addresses it as 0x9f1c0260, so its entries
 * lie 0xF10000 below the load addresses (the link offset of this code). Each case tail-calls its handler
 * with port; values without a case return.
 */
/* Protection record of an output (24 bytes, docs/DATA.md); only the state byte is used here. */
struct hdcp_tx_record {
    unsigned char bits_24_31;
    unsigned char bits_16_23;
    unsigned char state;                /* +2: set by hdcp_tx_select_next_state from the handlers' step results */
    unsigned char device_count;         /* +3 */
    unsigned char rest[20];
};
extern struct hdcp_tx_record hdcp_tx_records[];
extern void hdcp_tx_hdmi_state_read_status_reg(unsigned char);
extern void hdcp_tx_hdmi_state_stay(unsigned char);
extern void hdcp_tx_hdmi_state_check_ri(unsigned char);
extern void hdcp_tx_hdmi_state_read_repeater_info(unsigned char);
extern void hdcp_tx_hdmi_state_check_v(unsigned char);
extern void hdcp_tx_hdmi_state_start_engine(unsigned char);
extern void hdcp_tx_hdmi_state_pass(unsigned char);
extern void hdcp_tx_hdmi_state_check_link(unsigned char);
extern void hdcp_tx_hdmi_state_read_message(unsigned char);
extern void hdcp_tx_hdmi_state_compare_results(unsigned char);
extern void hdcp_tx_hdmi_state_send_key_block(unsigned char);
extern void hdcp_tx_hdmi_state_send_engine_bytes(unsigned char);
extern void hdcp_tx_hdmi_state_read_32_bytes(unsigned char);
extern void hdcp_tx_hdmi_state_read_pairing_info(unsigned char);
extern void hdcp_tx_hdmi_state_send_lc_init(unsigned char);
extern void hdcp_tx_hdmi_state_read_result_block(unsigned char);
extern void hdcp_tx_hdmi_state_send_session_key(unsigned char);
extern void hdcp_tx_hdmi_update_record(unsigned char);
extern void hdcp_tx_hdmi_state_forward_16_bytes(unsigned char);
extern void hdcp_tx_hdmi_state_send_stream_manage(unsigned char);
extern void hdcp_tx_hdmi_state_read_second_result(unsigned char);
extern void hdcp_tx_hdmi_state_stay_copy(unsigned char);
extern void hdcp_tx_hdmi_state_refresh_status(unsigned char);
extern void hdcp_tx_hdmi_state_start(unsigned char);
extern void hdcp_tx_hdmi_state_probe(unsigned char);
extern void hdcp_tx_hdmi_state_run_checks(unsigned char);
extern void hdcp_tx_hdmi_state_wait_clear_an_request(unsigned char);

/*
 * Run one step of the copy-protection handshake of an HDMI output: call the handler of the output's state.
 *
 *   port  the HDMI output, 0 or 1
 *
 * Called by hdcp_tx_service_port (which hdcp_tx_task calls) for outputs 0 and 1.
 * The handler only reports a result in the record's bits 16..17; hdcp_tx_service_port then calls
 * hdcp_tx_select_next_state, which picks the next state from it. hdcp_tx_dp_run_state is the same dispatcher
 * for the DisplayPort output.
 *
 * The states form three groups:
 *   0x00, 0x01    start. In state 1 hdcp_tx_hdmi_state_probe gives result 2 when hdcp_tx_hdmi_probe_receiver
 *                 returns 0x22 (the receiver's byte at DDC offset 0x50 reads 4), which leads to state 0x40;
 *                 result 1 leads to state 0x10.
 *   0x10..0x18    one form of the handshake; state 0x13 goes on to 0x14 (device list) when the record's
 *                 repeater bit (word 0 bit 28) is set, else to 0x16.
 *   0x40..0x4F    the other form, entered at 0x40.
 * Other values have no handler.
 */
void hdcp_tx_hdmi_run_state(unsigned char port)
{
    switch (hdcp_tx_records[port].state) {
    /* Start. */
    case 0x00:
        hdcp_tx_hdmi_state_read_status_reg(port);
        break;
    case 0x01:
        hdcp_tx_hdmi_state_probe(port);
        break;
    /* States 0x10..0x18. */
    case 0x10:
        hdcp_tx_hdmi_state_wait_clear_an_request(port);
        break;
    case 0x11:
        hdcp_tx_hdmi_state_run_checks(port);
        break;
    case 0x12:
        hdcp_tx_hdmi_state_stay(port);
        break;
    case 0x13:
        hdcp_tx_hdmi_state_check_ri(port);
        break;
    case 0x14:
        hdcp_tx_hdmi_state_read_repeater_info(port);
        break;
    case 0x15:
        hdcp_tx_hdmi_state_check_v(port);
        break;
    case 0x16:
        hdcp_tx_hdmi_state_start_engine(port);
        break;
    case 0x17:
        hdcp_tx_hdmi_state_pass(port);
        break;
    case 0x18:
        hdcp_tx_hdmi_state_check_link(port);
        break;
    /* States 0x40..0x4F. */
    case 0x40:
        hdcp_tx_hdmi_state_start(port);
        break;
    case 0x41:
        hdcp_tx_hdmi_state_read_message(port);
        break;
    case 0x42:
        hdcp_tx_hdmi_state_compare_results(port);
        break;
    case 0x43:
        hdcp_tx_hdmi_state_send_key_block(port);
        break;
    case 0x44:
        hdcp_tx_hdmi_state_send_engine_bytes(port);
        break;
    case 0x45:
        hdcp_tx_hdmi_state_read_32_bytes(port);
        break;
    case 0x46:
        hdcp_tx_hdmi_state_read_pairing_info(port);
        break;
    case 0x47:
        hdcp_tx_hdmi_state_send_lc_init(port);
        break;
    case 0x48:
        hdcp_tx_hdmi_state_read_result_block(port);
        break;
    case 0x49:
        hdcp_tx_hdmi_state_send_session_key(port);
        break;
    case 0x4a:
        hdcp_tx_hdmi_update_record(port);
        break;
    case 0x4b:
        hdcp_tx_hdmi_state_forward_16_bytes(port);
        break;
    case 0x4c:
        hdcp_tx_hdmi_state_send_stream_manage(port);
        break;
    case 0x4d:
        hdcp_tx_hdmi_state_read_second_result(port);
        break;
    case 0x4e:
        hdcp_tx_hdmi_state_stay_copy(port);
        break;
    case 0x4f:
        hdcp_tx_hdmi_state_refresh_status(port);
        break;
    }
}
