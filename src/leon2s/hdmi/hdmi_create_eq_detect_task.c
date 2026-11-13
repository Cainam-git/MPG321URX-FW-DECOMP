/* hdmi_create_eq_detect_task  (FUN_a0073578)
 *
 * Register the per-port HDMI equaliser check as a timer task.
 *   mode: 0 = create
 * Name basis: derived - task record {0, period, EQ detect pass over ports 0..3}; caller DRV_HDMIRx_Phy_Init
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0073578 @ 0xa0073578, flags -mcpu=v8 -Os -g.
 * Same code as hdmi_tx_frl_init_timer with other constants. The routine address is taken as an unsigned int.
 */
/* Task descriptor passed to the task routines. */
struct Rec { unsigned int flags; unsigned int period; unsigned int fn; };
extern unsigned int hdmi_task_period;
extern struct Rec hdmi_eq_detect_task;
extern unsigned int DRV_HDMI_EQDetect_Timer();
extern int sys_task_create();

/* With mode 0: fills the equaliser check task descriptor (flags 0, period from hdmi_task_period,
 * routine FUN_a0083324) and creates the task. Any other mode does nothing. Called by DRV_HDMIRx_Phy_Init.
 *   mode: 0 = create */
void hdmi_create_eq_detect_task(int mode)
{
    if (mode == 0) {
        hdmi_eq_detect_task.flags = 0;
        hdmi_eq_detect_task.fn = (unsigned int)DRV_HDMI_EQDetect_Timer;
        hdmi_eq_detect_task.period = hdmi_task_period;
        sys_task_create(&hdmi_eq_detect_task);
    }
}
