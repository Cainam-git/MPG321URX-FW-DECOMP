/* hdmi_rx21_service_irq_port0  (FUN_a00a28d8)
 *
 * Service the interrupt of HDMI 2.1 receiver 0: HDR10+, then sync events.
 * Name basis: derived - hdr_update_hdr10plus_hdmi21_port0, then hdmi_rx21_service_sync_events, or clears all
 *   events and calls hdmi_rx21_enable_sync_events when idle
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a28d8 @ 0xa00a28d8, flags -mcpu=v8 -Os -g.
 * Source form: the "mode detected" arm comes first (the firmware ends it with a tail call into
 * hdmi_rx21_service_sync_events); the six parameters are declared because the last four are passed on.
 */
extern unsigned char hdmi_rx21_input_record0_mode_detected;
extern void hdr_update_hdr10plus_hdmi21_port0(void);
extern void hdmi_rx21_enable_sync_events(unsigned int, unsigned int);
extern unsigned char hdmi_rx21_clear_all_events(unsigned int);
extern void hdmi_rx21_service_sync_events(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void hdmi_rx21_reg_write8(unsigned int, unsigned int, unsigned int);

/*
 * Interrupt service of HDMI 2.1 receiver 0. The first two parameters are not used; the other four are passed
 * on to hdmi_rx21_service_sync_events.
 *
 * Every call updates the HDR10+ state of the receiver and writes 1 to its register 0x9C8. Then, when the
 * receiver's input record has its mode-detected byte (record byte +1) set, the sync events are serviced.
 * Otherwise all its events are cleared and enable_sync_events is called.
 */
void hdmi_rx21_service_irq_port0(unsigned int unused1, unsigned int unused2, unsigned int arg3, unsigned int arg4,
                  unsigned int arg5, unsigned int arg6)
{
    hdr_update_hdr10plus_hdmi21_port0();
    hdmi_rx21_reg_write8(0, 0x9c8, 1);
    if (hdmi_rx21_input_record0_mode_detected != 0) {
        hdmi_rx21_service_sync_events(0, 0, arg3, arg4, arg5, arg6);
        return;
    }
    hdmi_rx21_clear_all_events(0);
    hdmi_rx21_enable_sync_events(0, 0);
}
