/* hdcp_tx_dp_run_state  (FUN_a00d0968)
 *
 * Call the handler for the current state of the DisplayPort output's handshake.
 * Name basis: derived - switch on the state byte 0..0x4F of the port record
 *
 * Matching notes
 * --------------
 * leon2s hdcp_tx_dp_run_state @ 0xa00d0968-0xa00d0af8, flags -mcpu=v8 -Os -g.
 * The switch on the state byte (values 0..0x4F, 27 case labels) compiles to the 80-entry jump table
 * hdcp_tx_dp_run_state_jump_table at 0xa00d0828; the code addresses it as 0x9f1c0828, so its entries
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
extern void hdcp_tx_dp_state_read_caps(unsigned char);
extern void hdcp_tx_dp_state_read_bksv(unsigned char);
extern void hdcp_tx_dp_state_stay(unsigned char);
extern void hdcp_tx_dp_state_compare_reads(unsigned char);
extern void hdcp_tx_dp_state_check_link_bits(unsigned char);
extern void hdcp_tx_dp_state_read_message(unsigned char);
extern void hdcp_tx_dp_state_init_counters(unsigned char);
extern void hdcp_tx_hdmi_state_pass_copy(unsigned char);
extern void hdcp_tx_dp_state_sync_enable(unsigned char);
extern void hdcp_tx_dp_state_compare_results(unsigned char);
extern void hdcp_tx_dp_state_send_key_block(unsigned char);
extern void hdcp_tx_dp_state_send_32_bytes(unsigned char);
extern void hdcp_tx_dp_state_compare_aux_block(unsigned char);
extern void hdcp_tx_dp_state_exchange_first(unsigned char);
extern void hdcp_tx_dp_state_send_lc_init(unsigned char);
extern void hdcp_tx_dp_state_exchange_third(unsigned char);
extern void hdcp_tx_dp_state_send_session_key(unsigned char);
extern void hdcp_tx_dp_state_read_receiver_ids(unsigned char);
extern void hdcp_tx_dp_state_send_engine_result(unsigned char);
extern void hdcp_tx_dp_state_send_stream_manage(unsigned char);
extern void hdcp_tx_dp_state_stay_copy(unsigned char);
extern void hdcp_tx_dp_state_sync_enable_copy(unsigned char);
extern void hdcp_tx_dp_state_read_two_blocks(unsigned char);
extern void hdcp_tx_dp_state_read_hdcp2_messages(unsigned char);
extern void hdcp_tx_dp_state_wait_timer(unsigned char);
extern void hdcp_tx_dp_state_reset_session(unsigned char);
extern void hdcp_tx_dp_state_check_link(unsigned char);

/*
 * Run one step of the copy-protection handshake of the DisplayPort output: call the handler of its state.
 *
 *   port  the output, 2
 *
 * Called by hdcp_tx_service_port (which hdcp_tx_task calls) for output 2, only while hdcp_tx_dp_bypass_flag is
 * set. The handler only reports a result in the record's bits 16..17; hdcp_tx_service_port then calls
 * hdcp_tx_select_next_state, which picks the next state from it. Same states and same order as
 * hdcp_tx_hdmi_run_state, with the DisplayPort handlers; states 0x12, 0x17 and 0x4E use handlers that are
 * copies of HDMI ones (hdcp_tx_dp_state_stay, _pass_copy, _fail_copy3).
 *
 * The states form three groups:
 *   0x00, 0x01    start. In state 1 hdcp_tx_dp_state_read_caps gives result 2 when the byte at AUX 0x6921D
 *                 reads 2, which leads to state 0x40; result 1 leads to state 0x10.
 *   0x10..0x18    one form of the handshake; state 0x13 goes on to 0x14 when the record's repeater bit (word 0
 *                 bit 28) is set, else to 0x16.
 *   0x40..0x4F    the other form, entered at 0x40.
 * Other values have no handler.
 */
void hdcp_tx_dp_run_state(unsigned char port)
{
    switch (hdcp_tx_records[port].state) {
    /* Start. */
    case 0x00:
        hdcp_tx_dp_state_check_link(port);
        break;
    case 0x01:
        hdcp_tx_dp_state_read_caps(port);
        break;
    /* States 0x10..0x18. */
    case 0x10:
        hdcp_tx_dp_state_wait_timer(port);
        break;
    case 0x11:
        hdcp_tx_dp_state_read_bksv(port);
        break;
    case 0x12:
        hdcp_tx_dp_state_stay(port);
        break;
    case 0x13:
        hdcp_tx_dp_state_compare_reads(port);
        break;
    case 0x14:
        hdcp_tx_dp_state_check_link_bits(port);
        break;
    case 0x15:
        hdcp_tx_dp_state_read_message(port);
        break;
    case 0x16:
        hdcp_tx_dp_state_init_counters(port);
        break;
    case 0x17:
        hdcp_tx_hdmi_state_pass_copy(port);
        break;
    case 0x18:
        hdcp_tx_dp_state_sync_enable(port);
        break;
    /* States 0x40..0x4F. */
    case 0x40:
        hdcp_tx_dp_state_reset_session(port);
        break;
    case 0x41:
        hdcp_tx_dp_state_read_hdcp2_messages(port);
        break;
    case 0x42:
        hdcp_tx_dp_state_compare_results(port);
        break;
    case 0x43:
        hdcp_tx_dp_state_send_key_block(port);
        break;
    case 0x44:
        hdcp_tx_dp_state_send_32_bytes(port);
        break;
    case 0x45:
        hdcp_tx_dp_state_compare_aux_block(port);
        break;
    case 0x46:
        hdcp_tx_dp_state_exchange_first(port);
        break;
    case 0x47:
        hdcp_tx_dp_state_send_lc_init(port);
        break;
    case 0x48:
        hdcp_tx_dp_state_exchange_third(port);
        break;
    case 0x49:
        hdcp_tx_dp_state_send_session_key(port);
        break;
    case 0x4a:
        hdcp_tx_dp_state_read_receiver_ids(port);
        break;
    case 0x4b:
        hdcp_tx_dp_state_send_engine_result(port);
        break;
    case 0x4c:
        hdcp_tx_dp_state_send_stream_manage(port);
        break;
    case 0x4d:
        hdcp_tx_dp_state_read_two_blocks(port);
        break;
    case 0x4e:
        hdcp_tx_dp_state_stay_copy(port);
        break;
    case 0x4f:
        hdcp_tx_dp_state_sync_enable_copy(port);
        break;
    }
}
