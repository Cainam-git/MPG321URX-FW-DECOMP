/* DRV_HDMI_Init_Timer  (DRV_HDMI_Init_Timer)
 *
 * Set up the HDMI receiver task timers of the given type.
 *   type: timer type
 * Name basis: proven - original name printed ('[MODEDET]: %s Start , type = %d'); types 1, 0x14, 0x15
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_Init_Timer @ 0xa009c188, flags -mcpu=v8 -Os -g.
 * Source form: cases in ascending order; type 0x15 repeats both descriptor blocks; each block stores the
 * flag word, the function pointer and then the period.
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
extern unsigned char hdmi_task_period;
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern void sys_task_create(struct TimerDesc *);
extern void hdmi_rx21_run_mode_detect_fsm(void);
extern void hdmi_rx21_run_rx_detect_fsm(void);

/* Fills the descriptor of the mode-detect task (routine hdmi_rx21_run_mode_detect_fsm), of the
 * receive-detect task (hdmi_rx21_run_rx_detect_fsm), or of both, with flags 0 and the period byte
 * hdmi_task_period, and creates the task. Other types do nothing.
 *   type: timer type (HDMI_TIMER_*) */
void DRV_HDMI_Init_Timer(unsigned int type)
{
    if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
        dbg_printf("[MODEDET]: %s Start , type = %d \n", "DRV_HDMI_Init_Timer", type);
    switch (type) {
    case HDMI_TIMER_MODE_DETECT:
        hdmi_rx21_mode_detect_timer.flags = 0;
        hdmi_rx21_mode_detect_timer.fn = hdmi_rx21_run_mode_detect_fsm;
        hdmi_rx21_mode_detect_timer.period = hdmi_task_period;
        sys_task_create(&hdmi_rx21_mode_detect_timer);
        break;
    case HDMI_TIMER_RX_DETECT:
        hdmi_rx21_rx_detect_timer.flags = 0;
        hdmi_rx21_rx_detect_timer.fn = hdmi_rx21_run_rx_detect_fsm;
        hdmi_rx21_rx_detect_timer.period = hdmi_task_period;
        sys_task_create(&hdmi_rx21_rx_detect_timer);
        break;
    case HDMI_TIMER_BOTH:
        hdmi_rx21_mode_detect_timer.flags = 0;
        hdmi_rx21_mode_detect_timer.fn = hdmi_rx21_run_mode_detect_fsm;
        hdmi_rx21_mode_detect_timer.period = hdmi_task_period;
        sys_task_create(&hdmi_rx21_mode_detect_timer);
        hdmi_rx21_rx_detect_timer.flags = 0;
        hdmi_rx21_rx_detect_timer.fn = hdmi_rx21_run_rx_detect_fsm;
        hdmi_rx21_rx_detect_timer.period = hdmi_task_period;
        sys_task_create(&hdmi_rx21_rx_detect_timer);
        break;
    }
}
