/* DRV_HDMI_Start_Timer  (DRV_HDMI_Start_Timer)
 *
 * Start the HDMI receiver task timers of the given type with their periods.
 *   type: timer type
 * Name basis: proven - original name printed ('[MODEDET]: %s Start , type = %d'); mode-detect timer and
 *   receive-detect timer
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_Start_Timer @ 0xa009c310, flags -mcpu=v8 -Os -g.
 * Source form: type 0x15 falls through from the mode-detect case into the receive-detect case.
 */
#define HDMI_MSG_MODEDET_FLOW 4 /* debug message bit: '[MODEDET]' lines (dbg_hdmi_message_flags) */

/* Timer types of DRV_HDMI_Init_Timer / _Start_Timer / _Del_Timer. */
enum {
    HDMI_TIMER_MODE_DETECT = 1,     /* mode-detect timer (hdmi_rx21_mode_detect_timer) */
    HDMI_TIMER_RX_DETECT   = 0x14,  /* receive-detect timer (hdmi_rx21_rx_detect_timer) */
    HDMI_TIMER_BOTH        = 0x15   /* both, mode-detect first */
};

/* Task descriptor passed to the task routines. */
struct TimerDesc { unsigned int flags; unsigned int period; void (*fn)(void); };
extern struct TimerDesc hdmi_rx21_mode_detect_timer, hdmi_rx21_rx_detect_timer;
extern unsigned char hdmi_rx21_rx_detect_period, hdmi_rx21_mode_detect_period;
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern void sys_task_start(struct TimerDesc *);

/* Sets the period of the mode-detect task (from byte hdmi_rx21_mode_detect_period), of the receive-detect task (from
 * byte hdmi_rx21_rx_detect_period), or of both, and adds the task. Other types do nothing.
 *   type: timer type (HDMI_TIMER_*) */
void DRV_HDMI_Start_Timer(unsigned int type)
{
    if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
        dbg_printf("[MODEDET]: %s Start , type = %d \n", "DRV_HDMI_Start_Timer", type);
    switch (type) {
    case HDMI_TIMER_MODE_DETECT:
        hdmi_rx21_mode_detect_timer.period = hdmi_rx21_mode_detect_period;
        sys_task_start(&hdmi_rx21_mode_detect_timer);
        break;
    case HDMI_TIMER_BOTH:
        hdmi_rx21_mode_detect_timer.period = hdmi_rx21_mode_detect_period;
        sys_task_start(&hdmi_rx21_mode_detect_timer);
        /* fall through */
    case HDMI_TIMER_RX_DETECT:
        hdmi_rx21_rx_detect_timer.period = hdmi_rx21_rx_detect_period;
        sys_task_start(&hdmi_rx21_rx_detect_timer);
        break;
    }
}
