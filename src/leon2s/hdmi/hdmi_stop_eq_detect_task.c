/* hdmi_stop_eq_detect_task  (FUN_a00735c0)
 *
 * Stop the periodic HDMI equaliser check task.
 * Name basis: derived - clears the task record of hdmi_create_eq_detect_task; caller DRV_HDMI_DbgHDMITaskCtrl
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00735c0 @ 0xa00735c0, flags -mcpu=v8 -Os -g.
 * Source form: sys_task_remove is declared without a parameter list.
 */
extern unsigned int hdmi_eq_detect_task;
extern int sys_task_remove();

/* With mode 0: removes the equaliser check task (sys_task_remove on its descriptor). Any other mode
 * does nothing. Called by DRV_HDMI_DbgHDMITaskCtrl.
 *   mode: 0 = stop */
void hdmi_stop_eq_detect_task(int mode)

{
  if (mode == 0) {
    sys_task_remove(&hdmi_eq_detect_task);
    return;
  }
  return;
}