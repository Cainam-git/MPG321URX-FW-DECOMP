/* hdmi_rx21_reset_error_counter  (FUN_a0098b60)
 *
 * Clear the error counter of an HDMI 2.1 receiver and flag it for the LTS_L state.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: descriptive - halfword 0xA8079054[p] = 0, bit 2/3 of 0xA80788D2; caller
 *   DRV_HDMI21_RXDetect_FSM_LTS_L
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0098b60 @ 0xa0098b60 (-mcpu=v8 -Os -g)
 * The compiler places the halfword store in the branch delay slot and hoists the second base address.
 */
extern unsigned short hdmi_rx21_error_counters[];   /* one per HDMI 2.1 receiver */
extern unsigned char input_port_event_flags;        /* event bits waiting to be published to the main processor */

/*
 * Set the error counter of an HDMI 2.1 receiver to 0 and raise its event bit: bit 2 of input_port_event_flags for
 * receiver 0, bit 3 for receiver 1.
 *   port: HDMI 2.1 receiver 0/1
 * Called by DRV_HDMI21_RXDetect_FSM_LTS_L.
 */
void hdmi_rx21_reset_error_counter(unsigned int port)
{
    port &= 0xff;
    hdmi_rx21_error_counters[port] = 0;
    if (port == 0) {
        input_port_event_flags |= 4;
    } else if (port == 1) {
        input_port_event_flags |= 8;
    }
}
