/* dp_mst_notify_task  (FUN_a00dbc8c)
 *
 * Step the three-state notification sequence, retrying after a time-out.
 * Name basis: descriptive - retries when more than the limit of ticks has passed
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00dbc8c @ 0xa00dbc8c-0xa00dbe74, -mcpu=v8 -Os -g.
 * Source form: '&&' conditions for the two state cases, with the flag copied into t in the second; the
 * r == 0 arms come first; the braces inside the two request arms are kept.
 */
extern unsigned char dp_mst_message_state_addressed_flag;
extern unsigned char dp_mst_notify_state;
extern unsigned char dp_mst_notify_select;
extern unsigned char dp_mst_message_state_notify_flag;
extern unsigned char dp_mst_message_state_notify_action;
extern unsigned int dp_mst_notify_ticks;
extern int dbg_printf(const char *, ...);
extern unsigned int timer_get_ticks(void);
extern void dp_mst_queue_fixed_up_message(void);
extern unsigned char dp_mst_send_status_message(unsigned char);

/*
 * Step the connection-status notification sequence of the MST service, and repeat the last
 * notification when it has not been confirmed in time. Takes no parameters, returns nothing.
 * Called by dp_mst_downstream_task when the receive ring of the current port is empty.
 *
 * Variables (see the data names): notify_state is 0 or 1 as set by the output hot-plug handling
 * (dp_mst_set_flag_6099), and becomes 2 once a step has run. notify_flag remembers the last step
 * (1 after the "connected" step, 0 after the other). notify_select holds which step to repeat,
 * notify_action is 1 while a repeat may still be needed, notify_ticks is the time of the last send.
 *
 * 1. Not addressed (LINK_ADDRESS not answered yet): only set notify_flag to 1 when state is 0 and to 0
 *    when state is 1, then return. No message is sent.
 * 2. State 0 or 1 (printing "HPDMSG_Update" with the flag): when state 0 meets flag 0, send a notification with dp_mst_send_status_message(1);
 *    when state 1 meets flag 1, send one with dp_mst_send_status_message(0). The firmware prints
 *    "CONNECTION_STATUS_NOTIFY_Request" with 0 for the first and 1 for the second. The step is
 *    remembered in notify_select and notify_flag. A result of 0 (nothing sent) sets notify_action and
 *    stamps notify_ticks; otherwise notify_action is cleared. State becomes 2.
 * 3. State 2: when notify_action is set and more than 500 ticks have passed, send the step
 *    named by notify_select again (select 0 = dp_mst_send_status_message(1), 1 = (0)) and update notify_action and notify_ticks the same way.
 */
void dp_mst_notify_task(void)
{
    unsigned char r = 0; /* result of dp_mst_send_status_message */
    unsigned char t;

    if (dp_mst_message_state_addressed_flag == 0) {
        if (dp_mst_notify_state == 0)
            dp_mst_message_state_notify_flag = 1;
        else if (dp_mst_notify_state == 1)
            dp_mst_message_state_notify_flag = 0;
        return;
    }
    /* A new step is due until the state has become 2. */
    if (dp_mst_notify_state != 2) {
        dbg_printf("\033[1;34mHPDMSG_Update : %d\r\n\033[m", dp_mst_message_state_notify_flag);
        if (dp_mst_notify_state == 0 && dp_mst_message_state_notify_flag == 0) {
            {
                dbg_printf("HPDMSG_Update : CONNECTION_STATUS_NOTIFY_Request %d\r\n", 0);
                dp_mst_queue_fixed_up_message();
                r = dp_mst_send_status_message(1);
                dp_mst_notify_select = 0;
                dp_mst_message_state_notify_flag = 1;
                if (r == 0) {
                    dp_mst_message_state_notify_action = 1;
                    dp_mst_notify_ticks = timer_get_ticks();
                } else
                    dp_mst_message_state_notify_action = 0;
            }
        } else if (dp_mst_notify_state == 1 && (t = dp_mst_message_state_notify_flag) == 1) {
            {
                dbg_printf("HPDMSG_Update : CONNECTION_STATUS_NOTIFY_Request %d\r\n", 1);
                dp_mst_queue_fixed_up_message();
                r = dp_mst_send_status_message(0);
                dp_mst_notify_select = t;
                dp_mst_message_state_notify_flag = 0;
                if (r == 0) {
                    dp_mst_message_state_notify_action = t;
                    dp_mst_notify_ticks = timer_get_ticks();
                } else
                    dp_mst_message_state_notify_action = 0;
            }
        }
        dp_mst_notify_state = 2;
        return;
    }
    /* State 2: retry after the time-out. */
    if (dp_mst_message_state_notify_action == 0)
        return;
    if (timer_get_ticks() - dp_mst_notify_ticks <= 500)
        return;
    if (dp_mst_notify_select == 0) {
        dp_mst_queue_fixed_up_message();
        r = dp_mst_send_status_message(1);
    } else if (dp_mst_notify_select == 1) {
        dp_mst_queue_fixed_up_message();
        r = dp_mst_send_status_message(0);
    }
    if (r == 0) {
        dp_mst_message_state_notify_action = 1;
        dp_mst_notify_ticks = timer_get_ticks();
    } else
        dp_mst_message_state_notify_action = 0;
}
