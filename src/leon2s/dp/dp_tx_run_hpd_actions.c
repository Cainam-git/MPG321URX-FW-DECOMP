/* dp_tx_run_hpd_actions  (DPTX_IsHPDAction_Off)
 *
 * Handle plug, unplug and IRQ events of the DP output.
 *   port: DP output 0..4
 * Name basis: proven - prints 'DPTX_IsHPDAction_On/Off'; calls EDID read, caps read and training-lost check;
 *   label from one print
 *
 * Matching notes
 * --------------
 * DPTX_IsHPDAction_Off (leon2s 0xa0089428-0xa0089750), flags -mcpu=v8 -Os -g.
 * Source form: the two two-value choices as '== ? :' conditional expressions (their if-conversion order).
 */
/* Bits of the work word `todo`. Each set bit asks for one step; the steps run at the end of the routine in
   the order of the tests there. */
#define TODO_TRAIN_LINK    0x01     /* run link training; when it returns 1, write the downspread setting */
#define TODO_READ_CAPS     0x02     /* read the sink's DPCD capabilities */
#define TODO_READ_EDID     0x04     /* read the sink's EDID */
#define TODO_CHECK_SINK    0x08     /* look at the sink's status bytes (sets the other bits as needed) */
#define TODO_TEST_REQUEST  0x10     /* answer the sink's automated test request */
#define TODO_UNPLUGGED     0x40     /* drop the cached sink data and set link pattern 7 */

/* Results of dp_tx_get_hpd_pulse. */
#define HPD_PLUG           1
#define HPD_UNPLUG         2

extern unsigned char dp_tx_forced_hpd_flags[];
extern unsigned char dp_tx_hpd_flag;
extern unsigned char dp_tx_hpd_option_stub(void);
extern unsigned char dp_tx_get_mode_flag(void);
extern void dp_mst_reset_port(void);
extern unsigned char dp_tx_is_connected(unsigned char);
extern unsigned char dp_tx_get_hpd_pulse(unsigned char);
extern int dbg_print_string(const char *);
extern unsigned char dp_tx_hpd_event_bit2(unsigned char);
extern unsigned short dp_tx_take_action_flags(unsigned char);
extern unsigned char dp_tx_check_training_lost(unsigned char, unsigned char *, unsigned char *);
extern unsigned char dp_get_port_setting_112(unsigned char);
extern void dp_mst_set_flag_6099(unsigned char);
extern void dp_mst_set_enable(unsigned char);
extern unsigned char dp_tx_check_level_crossing(unsigned char);
extern unsigned char dp_tx_get_path_option(unsigned char);
extern unsigned char dp_tx_handle_test_request(unsigned char, unsigned char *);
extern void dp_tx_read_sink_edid(unsigned char);
extern void dp_tx_read_sink_caps(unsigned char);
extern void dp_tx_clear_caps_valid(unsigned char);
extern void dp_tx_set_link_pattern(unsigned char, unsigned char);
extern unsigned char dp_tx_train_links(unsigned char, unsigned char *);
extern unsigned char dp_tx_write_downspread(unsigned char);

/*
 * Look at the hot-plug state of one DP output and carry out what it needs: after a plug read the EDID and the
 * capabilities and train the link, after an unplug clear the cached sink data, and in between check the sink's
 * status bytes for a lost link or a test request.
 *
 *   port  DP output 0..4
 *
 * Called from dp_tx_run_output_tasks, with output 0.
 *
 * The routine first collects the steps to do as bits in `todo` (see TODO_*), then runs them in a fixed order:
 * EDID, capabilities, unplug clean-up, link training. A plug sets 0x807 on output 0 (bits 0..2 and a bit 0x800
 * that nothing tests here) and 8 (check sink) on the others; an unplug sets TODO_UNPLUGGED. Output 0 also
 * switches the MST mode of the link on and off around unplug and training when dp_get_port_setting_112(0) /
 * dp_tx_get_mode_flag() say so.
 */
void dp_tx_run_hpd_actions(unsigned char port)
{
    unsigned char sink_status[16] = {0};    /* filled by dp_tx_check_training_lost and the test-request handler */
    unsigned char train_arg = 1;            /* passed by address to the training-lost check and to link training */
    unsigned short todo = 0;
    unsigned char event;

    /* Only reached when the (switched-off) HPD option returns 1; with the stub it never does. */
    if (dp_tx_hpd_option_stub() == 1) {
        if (dp_tx_get_mode_flag())
            dp_mst_reset_port();
    }
    if (dp_tx_forced_hpd_flags[port] == 1) {
        /* A forced check: treat the output as freshly plugged (line high) or unplugged (line low). The
           pulse query is still made, but its result is dropped. */
        event = dp_tx_is_connected(port) == 1 ? HPD_PLUG : HPD_UNPLUG;
        dp_tx_get_hpd_pulse(port);
        dp_tx_forced_hpd_flags[port] = 0;
    } else
        event = dp_tx_get_hpd_pulse(port);
    if (event == HPD_PLUG) {
        dbg_print_string("DPTX_IsHPDAction_On\r");
        todo = port == 0 ? 0x807 : TODO_CHECK_SINK;
    } else if (event == HPD_UNPLUG) {
        dbg_print_string("DPTX_IsHPDAction_Off\r");
        dp_tx_hpd_flag = 0;
        todo = TODO_UNPLUGGED;
    }
    /* Hot-plug event bit 2 on a connected output, and any pending action flags, ask for a sink check. */
    if (dp_tx_hpd_event_bit2(port) && dp_tx_is_connected(port) == 1)
        todo |= TODO_CHECK_SINK;
    todo |= dp_tx_take_action_flags(port);
    if (todo & TODO_CHECK_SINK) {
        if (dp_tx_check_training_lost(port, sink_status, &train_arg) == 1) {
            /* Link lost: read the capabilities again and retrain. */
            if (dp_get_port_setting_112(0) && port == 0)
                dp_mst_set_flag_6099(1);
            todo |= TODO_TRAIN_LINK | TODO_READ_CAPS;
        }
        if (dp_tx_check_level_crossing(port))
            todo |= TODO_TRAIN_LINK;
        if (sink_status[6] & 0x40) {
            if (dp_tx_get_path_option(port))
                todo |= TODO_READ_EDID;
        }
        if (sink_status[2] != 0)
            todo |= TODO_TEST_REQUEST;
    }
    if (todo & TODO_TEST_REQUEST) {
        switch (dp_tx_handle_test_request(port, sink_status)) {
        case 1:
            todo |= TODO_TRAIN_LINK | TODO_READ_CAPS;
            break;
        case 2:
            todo = 0;               /* handled completely: cancel every other step */
            break;
        }
    }
    if (todo & TODO_READ_EDID)
        dp_tx_read_sink_edid(port);
    if (todo & TODO_READ_CAPS)
        dp_tx_read_sink_caps(port);
    if (todo & TODO_UNPLUGGED) {
        dp_tx_clear_caps_valid(port);
        dp_tx_set_link_pattern(port, 7);
        if (dp_get_port_setting_112(0) && port == 0) {
            dp_mst_set_enable(0);
            dp_mst_set_flag_6099(1);
        }
    }
    if (todo & TODO_TRAIN_LINK) {
        if (dp_tx_get_mode_flag() && port == 0)
            dp_mst_set_enable(1);
        if (dp_tx_train_links(port, &train_arg) == 1) {
            if (dp_tx_get_mode_flag() && port == 0)
                dp_mst_set_flag_6099(0);
            dp_tx_write_downspread(port);
        }
    }
}
