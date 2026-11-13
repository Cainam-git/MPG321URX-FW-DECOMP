/* hdmi_tx_service_port  (FUN_a0095e08)
 *
 * Check hot-plug of an enabled HDMI TX port, or shut a disabled one down.
 *   port: HDMI TX port 0/1
 * Name basis: derived - command flag bits 0/1 enable the ports; disabled running ports get step 9 and a record
 *   reset
 *
 * Matching notes
 * --------------
 * FUN_a0095e08 (leon2s 0xa0095e08-0xa0095ea4, 156 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the two hdmi_tx_check_hotplug calls stand at the end of the function, reached by goto tail0 / tail1
 * (as separate blocks after a label they keep their own 0 / 1 argument; written in the port tests, the argument
 * becomes the known port value).
 */
#define TX_STEP_STOP 9                  /* hdmi_tx_run_step step 9 */

extern unsigned char hdmi_tx_is_port0_enabled(void);   /* enable of HDMI TX port 0 */
extern unsigned char hdmi_tx_is_port1_enabled(void);   /* enable of HDMI TX port 1 */
extern unsigned int hdmi_tx_is_active(unsigned char);
extern void hdmi_tx_run_step(unsigned char, unsigned char);
extern void hdmi_tx_reset_channel(unsigned char);
extern void hdmi_tx_check_hotplug(unsigned char);

/*
 * Regular work for one HDMI TX port. An enabled port (its enable flag is set) gets the hot-plug check. A port
 * that is not enabled but still active gets the stop step (TX_STEP_STOP) and a reset of its channel record.
 *   port: HDMI TX port; a value above 1 does nothing
 * Called by hdmi_tx_run_service.
 */
void hdmi_tx_service_port(unsigned char port)
{
    if (port > 1)
        return;
    if (port == 0) {
        if (hdmi_tx_is_port0_enabled())
            goto tail0;
        if (hdmi_tx_is_active(0) & 0xff) {
            hdmi_tx_run_step(0, TX_STEP_STOP);
            hdmi_tx_reset_channel(0);
        }
    } else if (port == 1) {
        if (hdmi_tx_is_port1_enabled())
            goto tail1;
        if (hdmi_tx_is_active(1) & 0xff) {
            hdmi_tx_run_step(1, TX_STEP_STOP);
            hdmi_tx_reset_channel(1);
        }
    }
    return;
tail0:
    hdmi_tx_check_hotplug(0);
    return;
tail1:
    hdmi_tx_check_hotplug(1);
}
