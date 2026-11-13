/* hdcp_tx_hdmi_probe_receiver  (FUN_a00c966c)
 *
 * Try up to ten times to reach the receiver's protection port and read its version.
 * Returns: 0x22 on success, else 0
 * Name basis: derived - two calls with 10-tick waits between tries
 *
 * Matching notes
 * --------------
 * FUN_a00c966c (leon2s 0xa00c966c-0xa00c972c, 48 words), flags -mcpu=v8 -Os -g.
 * Source form: "if (version == 4) return 0x22; return 0x14;" (the != form gives addx -1 / and 0xe).
 */
extern unsigned char hdmi_tx_ddc_reset(unsigned int port);
extern void timer_delay_long_units(unsigned int param_1);
extern unsigned char hdcp_tx_hdmi_read_hdcp2_version(unsigned int port, unsigned int buf);

#define PROBE_TRIES      10                     /* tries of each of the two steps */
#define PROBE_WAIT       10                     /* argument of the wait routine after each try */
#define PROBE_VERSION    4                      /* initial value of the version byte, and the value that gives 0x22 */
#define PROBE_OK         0x22
#define PROBE_OTHER      0x14

/*
 * Try to reach the screen on HDMI output `port`. Step 1 resets the DDC channel (hdmi_tx_ddc_reset); step 2
 * reads the HDCP2Version byte (hdcp_tx_hdmi_read_hdcp2_version). Each step is tried up to 10 times, with the wait
 * routine called with 10 after every try, and stops at the first try that returns 0.
 *
 * Returns 0 when the version read still fails after the last try. Otherwise it returns 0x22 when the version
 * byte is 4 (its value before the read is also 4) and 0x14 for any other value.
 *
 * Called from hdcp_tx_hdmi_state_probe, which sets the step result to 3 (STEP_AGAIN) when it returns 0 and to
 * 2 (STEP_OTHER) when it returns 0x22.
 */
int hdcp_tx_hdmi_probe_receiver(unsigned int port)
{
    unsigned char version;
    unsigned char result;
    unsigned char count;
    
    version = PROBE_VERSION;
    count = PROBE_TRIES;
    do {
        result = hdmi_tx_ddc_reset(port & 0xff);
        timer_delay_long_units(PROBE_WAIT);
        count--;
    } while ((result != 0) && (count > 0));
    
    count = PROBE_TRIES;
    do {
        result = hdcp_tx_hdmi_read_hdcp2_version(port & 0xff, (unsigned int)&version);
        timer_delay_long_units(PROBE_WAIT);
        count--;
    } while ((result != 0) && (count > 0));
    
    if (result != 0) {
        return 0;
    }
    if (version == PROBE_VERSION) {
        return PROBE_OK;
    }
    return PROBE_OTHER;
}
