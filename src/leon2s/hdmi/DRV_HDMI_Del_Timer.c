/* DRV_HDMI_Del_Timer  (DRV_HDMI_Del_Timer)
 *
 * Stop the HDMI receiver task timers of the given type.
 *   type: timer type
 * Name basis: proven - original name printed ('[MODEDET]: %s Start , type = %d')
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_Del_Timer @ 0xa009c284, flags -mcpu=v8 -Os -g.
 * Counterpart of DRV_HDMI_Start_Timer (same switch). The code range ends with the unreachable
 * ret/restore pair of the -g epilogue after the final tail call.
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
extern void sys_task_remove(struct TimerDesc *);

/* Removes the mode-detect task, the receive-detect task, or both (type, see HDMI_TIMER_*); other
 * types do nothing. The firmware's own print text says "Start" here.
 *   type: timer type */
void DRV_HDMI_Del_Timer(unsigned int type)
{
    if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
        dbg_printf("[MODEDET]: %s Start , type = %d \n", "DRV_HDMI_Del_Timer", type);
    switch (type) {
    case HDMI_TIMER_MODE_DETECT:
        sys_task_remove(&hdmi_rx21_mode_detect_timer);
        break;
    case HDMI_TIMER_BOTH:
        sys_task_remove(&hdmi_rx21_mode_detect_timer);
        /* fall through */
    case HDMI_TIMER_RX_DETECT:
        sys_task_remove(&hdmi_rx21_rx_detect_timer);
        break;
    }
}
