/* hdmi_tx_frl_start_timer  (FUN_a00a45d8)
 *
 * Start the HDMI TX FRL training timer with its period.
 *   mode: 0 = start
 * Name basis: derived - twin of hdmi_start_eq_detect_task; descriptor 0xA8079218, period 0xA8078744; caller
 *   hdmi_tx_init
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a45d8 @ 0xa00a45d8, flags -mcpu=v8 -Os -g.
 * Twin of hdmi_start_eq_detect_task. Leaf: the start call is a tail call ('mov %o7,%g1; call; mov %g1,%o7'). The
 * mode != 0 path ends in one real nop (not a delay slot), written as an asm statement. The callee is called by
 * its address (FUN_a00b2194, the task start routine sys_task_start).
 */
/* Descriptor of the timer: periodic flag, period in ticks, callback (set by hdmi_tx_frl_init_timer). */
struct hdmi_tx_timer_desc { unsigned int periodic; unsigned int period; };
extern struct hdmi_tx_timer_desc hdmi_tx_frl_timer;
extern unsigned int hdmi_tx_frl_timer_period;
extern void sys_task_start(struct hdmi_tx_timer_desc *);

/* With mode 0: copy hdmi_tx_frl_timer_period into the timer descriptor and start the timer. Any other mode
   does nothing. Called by hdmi_tx_init after hdmi_tx_frl_init_timer. */
void hdmi_tx_frl_start_timer(int mode)
{
  if (mode == 0) {
    hdmi_tx_frl_timer.period = hdmi_tx_frl_timer_period;
    sys_task_start(&hdmi_tx_frl_timer);
    return;
  }
  __asm__ volatile ("nop");
}
