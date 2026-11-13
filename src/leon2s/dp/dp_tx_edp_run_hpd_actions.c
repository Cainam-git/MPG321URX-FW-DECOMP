/* dp_tx_edp_run_hpd_actions  (eDP_IsHPDAction_Off)
 *
 * Handle plug, unplug and IRQ events of the eDP outputs.
 *   all_edp: non-zero = all eDP outputs
 * Note: Link-lost check, EDID read and training run once for the whole output range; only the test-request
 *   step runs per flagged output.
 * Name basis: proven - prints 'eDP_IsHPDAction_On/Off', 'eDPAction ReadEDID/Training/HPDDisConnect'; label
 *   taken from one print
 *
 * Matching notes
 * --------------
 * leon2s eDP_IsHPDAction_Off @ 0xa0089090-0xa0089420 (912 bytes), flags -mcpu=v8 -Os -g (section default).
 * FUN_a0087824 is dp_tx_train_links (label TRAINING_NORESPONSE).
 * Source forms the exact build depends on:
 *  - last initialised to 0 at its declaration and assigned again in the '!all_edp' arm as 'first = 0; last = 0;'
 *    (the firmware's 'mov %l5,%l7' copy of first's zero register);
 *  - in the forced-event test, event = HPD_UNPLUG is the else arm (not set before the test);
 *  - the test-request result is a switch.
 */

/* Bits of the work word `todo` (as in dp_tx_run_hpd_actions). Events and dp_tx_take_action_flags set them;
   the steps run at the end of the routine in the order of the tests there. */
#define TODO_TRAIN_LINK         0x01    /* set up the caps records and train the links */
#define TODO_READ_CAPS          0x02    /* set with TODO_TRAIN_LINK by a test request; no step here tests it */
#define TODO_READ_EDID          0x04    /* read the sink's EDID */
#define TODO_CHECK_SINK         0x08    /* look at the sinks' status bytes (sets the other bits as needed) */
#define TODO_TEST_REQUEST       0x10    /* answer the sinks' test requests */
#define TODO_UNPLUGGED          0x40    /* print only ('HPDDisConnect') */
#define TODO_PHY_FIELD_CLEAR    0x4000  /* only from dp_tx_take_action_flags: clear the output's PHY field */

/* Results of dp_tx_get_hpd_pulse. */
#define HPD_PLUG                1
#define HPD_UNPLUG              2

/* Results of dp_tx_handle_test_request. */
#define TEST_RESULT_RETRAIN     1
#define TEST_RESULT_DONE        2

#define SINK_STATUS_TEST_BYTE   2       /* status byte that, when not 0, asks for TODO_TEST_REQUEST */

extern unsigned char dp_tx_forced_hpd_flags[];
extern unsigned char dp_tx_edp_last_output;
extern unsigned char dp_tx_edp_first_output;
extern unsigned char dp_tx_edp_hpd_enable;
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);
extern unsigned char lib_make_bit_range_mask(unsigned char, unsigned char);
extern unsigned char dp_tx_is_connected(unsigned char);
extern unsigned char dp_tx_get_hpd_pulse(unsigned char);
extern unsigned char dp_tx_hpd_event_bit2(unsigned char);
extern unsigned short dp_tx_take_action_flags(unsigned char);
extern void dp_tx_phy_write_output_field(unsigned int, unsigned int);
extern unsigned char dp_tx_check_training_lost(unsigned char, unsigned char *, unsigned char *);
extern unsigned char dp_tx_handle_test_request(unsigned char, unsigned char *);
extern void dp_tx_read_sink_edid(unsigned char);
extern void dp_tx_init_sink_caps(unsigned char, unsigned char *);
extern unsigned char dp_tx_train_links(unsigned char, unsigned char *);

/*
 * Look at the hot-plug state of the eDP outputs and carry out what they need: after a plug, train the links
 * (which also sets up the caps records), after an unplug only a print, and in between check the sinks' status
 * bytes for a lost link or a test request.
 *
 *   all_edp  0: output 0 only; non-zero: outputs dp_tx_edp_first_output..dp_tx_edp_last_output. The caller,
 *            dp_tx_run_output_tasks, passes dp_tx_edp_first_output.
 *
 * Phases, in order:
 *   1. Events, per output of the range, only while dp_tx_edp_hpd_enable is not 0: a plug (or a forced check
 *      with the output connected, printed 'GOGO') asks for TODO_TRAIN_LINK | TODO_CHECK_SINK, an unplug (or a
 *      forced check with the output not connected) for TODO_UNPLUGGED; event bit 2 on a connected output
 *      asks for TODO_CHECK_SINK.
 *   2. Per output of the range: add the output's pending action flags. A connected output clears
 *      TODO_UNPLUGGED, also when an earlier output asked for it; an output that is not connected leaves
 *      output_mask. Once TODO_PHY_FIELD_CLEAR is in todo, the PHY field of this and every later output is
 *      cleared.
 *   3. The steps, each for the whole range (the calls get the first output number, which the callees treat as
 *      their all_edp switch): sink check (link lost -> TODO_TRAIN_LINK, status byte 2 -> TODO_TEST_REQUEST),
 *      test requests per output in output_mask (result 1 -> train again, result 2 -> drop every step), EDID
 *      read, unplug print, and last the training.
 */
void dp_tx_edp_run_hpd_actions(unsigned char all_edp)
{
    unsigned char sink_status[16] = {0};    /* filled by dp_tx_check_training_lost, read by the test request */
    unsigned char output_mask = 0;          /* bit n = output n connected; passed to the checks and training */
    unsigned short todo = 0;
    unsigned char first;
    unsigned char last = 0;
    unsigned char port;
    unsigned char event;

    if (!all_edp) {
        first = 0;
        last = 0;
    } else {
        first = dp_tx_edp_first_output;
        last = dp_tx_edp_last_output;
    }
    output_mask = lib_make_bit_range_mask(first, last);

    /* Phase 1: hot-plug events. */
    for (port = first; port <= last; port++) {
        if (dp_tx_edp_hpd_enable == 0)
            continue;
        if (dp_tx_forced_hpd_flags[port] == 1) {
            /* A forced check: plug or unplug by the line state; the pulse query is made, its result dropped. */
            if (dp_tx_is_connected(port) == 1) {
                event = HPD_PLUG;
                dbg_printf("=========================================GOGO %d!!\r\n", port);
            } else
                event = HPD_UNPLUG;
            dp_tx_get_hpd_pulse(port);
            dp_tx_forced_hpd_flags[port] = 0;
        } else
            event = dp_tx_get_hpd_pulse(port);
        if (event == HPD_PLUG) {
            dbg_printf("eDP_IsHPDAction_On %d\r\n", port);
            todo |= TODO_TRAIN_LINK | TODO_CHECK_SINK;
        } else if (event == HPD_UNPLUG) {
            dbg_printf("eDP_IsHPDAction_Off %d\r\n", port);
            todo |= TODO_UNPLUGGED;
        }
        if (dp_tx_hpd_event_bit2(port)) {
            dbg_print_string("eDP_IsIRQAction\r");
            if (dp_tx_is_connected(port) == 1)
                todo |= TODO_CHECK_SINK;
        }
    }

    /* Phase 2: pending action flags and the connected outputs. */
    for (port = first; port <= last; port++) {
        todo = dp_tx_take_action_flags(port) | todo;
        if (dp_tx_is_connected(port) == 1)
            todo &= ~TODO_UNPLUGGED;
        else
            output_mask &= ~(1 << port);
        if (todo & TODO_PHY_FIELD_CLEAR)
            dp_tx_phy_write_output_field(port, 0);
    }
    if (todo != 0)
        dbg_printf("action = %d\r\n", todo);

    /* Phase 3: the steps. */
    if (todo & TODO_CHECK_SINK) {
        dbg_printf("eDPAction CheckSinkStatus %d\r\n", first);
        if (dp_tx_check_training_lost(first, sink_status, &output_mask) == 1)
            todo |= TODO_TRAIN_LINK;
        if (sink_status[SINK_STATUS_TEST_BYTE] != 0) {
            dbg_printf("eDPAction IRQVectorHandle %d\r\n", first);
            todo |= TODO_TEST_REQUEST;
        }
    }
    if (todo & TODO_TEST_REQUEST) {
        for (port = first; port <= last; port++) {
            if ((output_mask >> port) & 1) {
                switch (dp_tx_handle_test_request(port, sink_status)) {
                case TEST_RESULT_RETRAIN:
                    todo |= TODO_TRAIN_LINK | TODO_READ_CAPS;
                    break;
                case TEST_RESULT_DONE:
                    todo = 0;       /* handled completely: cancel every other step */
                    break;
                }
            }
        }
    }
    if (todo & TODO_READ_EDID) {
        dbg_printf("eDPAction ReadEDID %d\r\n", first);
        dp_tx_read_sink_edid(first);
    }
    if (todo & TODO_UNPLUGGED)
        dbg_printf("eDPAction HPDDisConnect %d\r\n", first);
    if (todo & TODO_TRAIN_LINK) {
        dbg_printf("eDPAction Training %d\r\n", first);
        /* dp_tx_init_sink_caps takes only the first argument. */
        dp_tx_init_sink_caps(first, &output_mask);
        if (dp_tx_train_links(first, &output_mask) == 1)
            dbg_printf("training finish %d\r\n", first);
    }
}
