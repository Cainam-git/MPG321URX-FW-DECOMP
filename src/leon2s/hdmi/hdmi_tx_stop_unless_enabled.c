/* hdmi_tx_stop_unless_enabled  (FUN_a009584c)
 *
 * Power down and reset the running HDMI TX ports unless an output is enabled.
 * Returns: 0 when either port enable flag is set; else 1, whether or not a port was running
 * Name basis: derived - returns 0 when command flag bit 0 or 1 is set; else step 9 (power down) and
 *   hdmi_tx_reset_channel
 *
 * Matching notes
 * --------------
 * FUN_a009584c (leon2s, 0xa009584c-0xa00958d4, 136 bytes, 34 words).
 * Flags: -mcpu=v8 -Os -g.
 * Source form: the two early checks are one '||' test with one 'return 0' (the firmware's clr %i0 sits in the first
 * bne delay slot; two separate ifs put it in the call delay slot).
 */
#define TX_STEP_STOP 9                  /* hdmi_tx_run_step step 9 */

extern unsigned char hdmi_tx_is_port0_enabled(void);   /* enable of HDMI TX port 0 */
extern unsigned char hdmi_tx_is_port1_enabled(void);   /* enable of HDMI TX port 1 */
extern int hdmi_tx_is_active(int);
extern void hdmi_tx_run_step(int, int);
extern void hdmi_tx_reset_channel(int);

/*
 * Stop every running HDMI TX port, but only when neither port is enabled.
 * Returns 0 and does nothing when the enable flag of port 0 or of port 1 is set. Otherwise each port that is
 * active gets the stop step (TX_STEP_STOP) and a reset of its channel record, and the result is 1.
 * Called by hdmi_tx_run_service, which does its regular work only when this returns 0.
 */
int hdmi_tx_stop_unless_enabled(void)
{
    if ((hdmi_tx_is_port0_enabled() & 0xff) || (hdmi_tx_is_port1_enabled() & 0xff))
        return 0;
    if (hdmi_tx_is_active(0) & 0xff) {
        hdmi_tx_run_step(0, TX_STEP_STOP);
        hdmi_tx_reset_channel(0);
    }
    if (hdmi_tx_is_active(1) & 0xff) {
        hdmi_tx_run_step(1, TX_STEP_STOP);
        hdmi_tx_reset_channel(1);
    }
    return 1;
}
