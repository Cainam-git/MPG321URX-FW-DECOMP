/* hdmi_start_eq_detect_task  (FUN_a0073540)
 *
 * Start the periodic HDMI equaliser check task.
 *   mode: 0 = start
 * Name basis: derived - sets the period of the task record that hdmi_create_eq_detect_task bound to the per-
 *   port EQ detect pass
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0073540 @ 0xa0073540, flags -mcpu=v8 -Os -g.
 * Twin of hdmi_tx_frl_start_timer. Leaf. The record is one {flags, period} struct; the callee is named by its address
 * FUN_a00b2194 (no symbol entry). The tail call is 'mov %o7,%g1; call; mov %g1,%o7'. Source form: one asm
 * nop on the mode != 0 path (a real nop in the firmware, not a delay slot).
 */
/* Task record of the equaliser check task (see hdmi_create_eq_detect_task). */
struct eq_detect_task_record { unsigned int flags; unsigned int period; };
extern struct eq_detect_task_record hdmi_eq_detect_task;
extern unsigned int hdmi_eq_detect_period;
extern void sys_task_start(struct R *);

/* With mode 0: sets the period of the equaliser check task from hdmi_eq_detect_period and hands the
 * task record to FUN_a00b2194. Any other mode does nothing.
 *   mode: 0 = start */
void hdmi_start_eq_detect_task(int mode)
{
  if (mode == 0) {
    hdmi_eq_detect_task.period = hdmi_eq_detect_period;
    sys_task_start(&hdmi_eq_detect_task);
    return;
  }
  __asm__ volatile ("nop");
}
