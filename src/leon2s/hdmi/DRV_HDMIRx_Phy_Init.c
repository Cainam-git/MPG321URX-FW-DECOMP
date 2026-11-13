/* DRV_HDMIRx_Phy_Init  (DRV_HDMIRx_Phy_Init)
 *
 * Initialise the HDMI receiver PHYs and start the equaliser check task.
 * Name basis: proven - original name printed: '[INIT]: DRV_HDMIRx_Phy_Init %d'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMIRx_Phy_Init @ 0xa0074bf8, flags -mcpu=v8 -Os -g.
 * Source form: the callees are declared without parameter lists, and hdmi_start_eq_detect_task is
 * called with all six incoming parameters (the first replaced by 0).
 */
#define HDMI_MSG_INIT_INFO 1         /* debug message bit: '[INIT]' lines (dbg_hdmi_message_flags) */

extern unsigned int dbg_hdmi_message_flags;
extern int DRV_HDMI_InitialSettings();
extern int dbg_printf();
extern void hdmi_eq_clear_scan_records(void);
extern int hdmi_start_eq_detect_task();
extern int hdmi_create_eq_detect_task();

/* Initialises the HDMI receiver PHYs: applies the initial PHY settings, clears the last two entries
 * of the PHY table, creates the equaliser check task and starts it. The parameters are only handed on
 * to hdmi_start_eq_detect_task (all but the first); this routine does not use them itself. */
void DRV_HDMIRx_Phy_Init(unsigned int param_1,unsigned int param_2,unsigned int param_3,unsigned int param_4
                        ,unsigned int param_5,unsigned int param_6)

{
  if ((dbg_hdmi_message_flags & HDMI_MSG_INIT_INFO) != 0) {
    dbg_printf("[INIT]: DRV_HDMIRx_Phy_Init %d\015\012",999);
  }
  DRV_HDMI_InitialSettings();
  hdmi_eq_clear_scan_records();
  hdmi_create_eq_detect_task(0);
  hdmi_start_eq_detect_task(0,param_2,param_3,param_4,param_5,param_6);
  return;
}