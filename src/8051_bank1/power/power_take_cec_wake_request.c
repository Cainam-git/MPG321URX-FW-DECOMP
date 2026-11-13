/* power_take_cec_wake_request  (FUN_CODE_deb0)
 *
 * Return and clear the flag of a CEC power-up request.
 * Returns: 1 when a request was pending
 * Name basis: derived - bit 0x11 set by the CEC request printer hdmi_cec_report_request for
 *   _SYS_CECRequest_PowerUp and Power control
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_deb0 @ 0xdeb0  OPTIMIZE(8,SPEED) (also level 7).
 * Source form: copy the flag into a local bit (BIT 0x00), clear the flag, return the copy.
 */
extern bit power_cec_wake_request_flag;

/*
 * Take the CEC power-up request: return power_cec_wake_request_flag and clear it, so each request is seen once.
 * hdmi_cec_report_request sets the flag for a power-up or activate-source request, and for a device-control
 * power request with operand 0x40. Callers: sys_main in the power-saving and the power-off state; a 1 makes
 * the wake source WAKE_CEC.
 */
bit power_take_cec_wake_request(void)
{
    bit requested;
    requested = power_cec_wake_request_flag;
    power_cec_wake_request_flag = 0;
    return requested;
}
