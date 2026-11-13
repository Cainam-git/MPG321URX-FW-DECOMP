/* hdcp_tx_update_timers  (FUN_a00cfab8)
 *
 * Count the copy-protection timers down by the ticks that have passed.
 * Name basis: derived - RAM slots at 0xA8078B60, floor 0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cfab8 @ 0xa00cfab8-0xa00cfb20 (26 words), flags -mcpu=v8 -Os -g.
 * Source form: the timers are a plain RAM array (a volatile one reloads each slot 3 times) and the 'passed
 * ticks > slot' arm comes first (the firmware falls through to the clear and branches to the subtract).
 */
extern unsigned int hdcp_tx_timer_last_ticks;
extern unsigned int hdcp_tx_timers[];
extern unsigned int timer_get_ticks(void);

#define HDCP_TX_TIMER_COUNT     15      /* words of the timer array hdcp_tx_timers */

/*
 * Count the 15 copy-protection timers (array hdcp_tx_timers, one word each) down by the ticks that have passed
 * since the last call. A timer that has fewer ticks left than that becomes 0 and stays there. The tick count of
 * this call is kept in hdcp_tx_timer_last_ticks. Timers are started by hdcp_tx_set_timer and read by
 * hdcp_tx_get_timer; both call this routine first.
 */
void hdcp_tx_update_timers(void)
{
    unsigned int now;
    unsigned int passed;
    unsigned char i;

    now = timer_get_ticks();
    passed = now - hdcp_tx_timer_last_ticks;
    hdcp_tx_timer_last_ticks = now;
    for (i = 0; i < HDCP_TX_TIMER_COUNT; i++) {
        if (passed > hdcp_tx_timers[i])
            hdcp_tx_timers[i] = 0;
        else
            hdcp_tx_timers[i] -= passed;
    }
}
