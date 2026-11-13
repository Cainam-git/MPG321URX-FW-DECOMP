/* hdmi_cec_api_reset  (FUN_a0147760)
 *
 * Clear the CEC control register.
 * Name basis: derived - writes 0 to 0xCF012000, the block of the CEC receive and reply routines
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0147760 @ 0xa0147760, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: a plain call whose result is dropped.
 */
extern int hdmi_cec_reset();

/* Clear CEC_REG_00 of the CEC block through hdmi_cec_reset. Called from APPSetPowerOff and power_enter_app_state. */
void hdmi_cec_api_reset(void)
{
  hdmi_cec_reset();
}
