/* sys_service_ddc_and_cec  (FUN_CODE_dc3b)
 *
 * Re-arm idle DDC/CI links and, while off or saving power, report CEC requests.
 * Name basis: derived - ddc_rearm_idle_slaves, then hdmi_cec_report_request (prints _SYS_CECRequest_*) when
 *   run state 0xA770 is 0 or 1
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dc3b @ 0xdc3b  OPTIMIZE(7,SPEED)
 * The extern name thunk_FUN_CODE_deff makes the linker emit the LCALL operand 0xDEFF.
 */
#define RUN_STATE_POWER_SAVING 0   /* sys_run_state values */
#define RUN_STATE_POWER_OFF    1

extern void sys_empty_function_2(void);
extern void thunk_FUN_CODE_deff(void);
extern void hdmi_cec_report_request(void);
extern unsigned char xdata sys_run_state;

/* Call sys_empty_function_2 and the routine at 0xDEFF (a thunk to
 * ddc_rearm_idle_slaves), then call hdmi_cec_report_request while the run
 * state is power saving or power off. */
void sys_service_ddc_and_cec(void)
{
    sys_empty_function_2();
    thunk_FUN_CODE_deff();
    if ((sys_run_state == RUN_STATE_POWER_OFF) || (sys_run_state == RUN_STATE_POWER_SAVING)) {
        hdmi_cec_report_request();
    }
}
