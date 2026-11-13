/* DRV_HDMI_DbgHDMITaskCtrl  (DRV_HDMI_DbgHDMITaskCtrl)
 *
 * Start or stop the HDMI EQ task or receiver timers from the debug menu.
 * Returns: 0
 * Name basis: proven - original name printed; hdmi_start/stop_eq_detect_task, DRV_HDMI_Start_Timer /
 *   DRV_HDMI_Del_Timer
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_DbgHDMITaskCtrl @ 0xa00a3250, flags -mcpu=v8 -Os -g.
 * Source form: both argument bytes are read into locals before the tests (the firmware loads byte 7 once).
 */
extern int dbg_print_string(const char *);
extern void hdmi_start_eq_detect_task(unsigned char);
extern void hdmi_stop_eq_detect_task(unsigned char);
extern void DRV_HDMI_Start_Timer(unsigned char);
extern void DRV_HDMI_Del_Timer(unsigned char);

/* Debug menu command 7. Starts or stops one HDMI task.
 *   arg: the two words {which, on}, read as bytes: byte 3 = which (the low byte of word 0): 0 = the
 *        equaliser check task, 1 = the receiver timers (type 1); byte 7 = on (the low byte of word 1):
 *        non-zero starts, 0 stops. Other values of `which` do nothing.
 * Returns 0. */
int DRV_HDMI_DbgHDMITaskCtrl(unsigned char *arg)
{
    unsigned char sel, on;

    dbg_print_string("DRV_HDMI_DbgHDMITaskCtrl");
    sel = arg[3];
    on = arg[7];
    if (sel == 0) {
        if (on != 0)
            hdmi_start_eq_detect_task(0);
        else
            hdmi_stop_eq_detect_task(0);
    } else if (sel == 1) {
        if (on != 0)
            DRV_HDMI_Start_Timer(1);
        else
            DRV_HDMI_Del_Timer(1);
    }
    return 0;
}
