/* hdmi_rx21_service_irq_port1  (FUN_a00a2928)
 *
 * Service the interrupt of HDMI 2.1 receiver 1: HDR10+, then sync events.
 * Name basis: derived - hdr_update_hdr10plus_hdmi21_port1, then hdmi_rx21_service_sync_events, or clears and
 *   disables the events when idle
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2928 @ 0xa00a2928, flags -mcpu=v8 -Os -g.
 * Source form: the "mode detected" arm comes first, so the firmware's branch goes to the clear-events path.
 * The callees are declared int-returning and their results returned; hdmi_rx21_service_sync_events and
 * hdmi_rx21_enable_sync_events have no prototype.
 */
extern unsigned char hdmi_rx21_input_record1_mode_detected;
extern void hdr_update_hdr10plus_hdmi21_port1(void);
extern int hdmi_rx21_enable_sync_events();
extern void hdmi_rx21_clear_all_events(unsigned int);
extern int hdmi_rx21_service_sync_events();
extern void hdmi_rx21_reg_write8(unsigned int, unsigned short, unsigned int);

/*
 * Interrupt service of HDMI 2.1 receiver 1; the same steps as hdmi_rx21_service_irq_port0 for receiver 0.
 * The first two parameters are not used; the other four are passed on to hdmi_rx21_service_sync_events.
 * Returns the result of the last routine called.
 */
int hdmi_rx21_service_irq_port1(unsigned int unused1, unsigned int unused2, int arg3, unsigned int arg4,
                 unsigned int arg5, unsigned int arg6)
{
  hdr_update_hdr10plus_hdmi21_port1();
  hdmi_rx21_reg_write8(1, 0x9c8, 1);
  if (hdmi_rx21_input_record1_mode_detected != 0) {
    return hdmi_rx21_service_sync_events(1, 0, arg3, arg4, arg5, arg6);
  }
  hdmi_rx21_clear_all_events(1);
  return hdmi_rx21_enable_sync_events(1, 0);
}
