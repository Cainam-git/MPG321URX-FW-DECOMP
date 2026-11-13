/* hdmi_cec_report_request  (FUN_CODE_cd4b)
 *
 * Print the pending CEC power request and flag a power-up request.
 * Name basis: proven - prints '_SYS_CECRequest_PowerUp' / _PowerDown / _ActivateSC / _DeviceControl_Power;
 *   sets bit 0x11 for power-up requests
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_cd4b @ 0xcd4b (65 B)  Byte-exact with OPTIMIZE(8,SPEED).
 * Source form: Keil tests the cases in the order 2, 3, 5, 1 and shares the final LCALL of the four print calls.
 */
extern bit power_cec_wake_request_flag;
extern unsigned char hdmi_cec_poll_request(void);
extern unsigned char hdmi_cec_get_operand(void);
extern void lib_printf517(void *fmt, ...) large;   /* printf */

/* Request codes returned by hdmi_cec_poll_request, named by the text printed for each. */
#define CEC_REQUEST_POWER_UP        1
#define CEC_REQUEST_POWER_DOWN      2
#define CEC_REQUEST_ACTIVATE_SC     3
#define CEC_REQUEST_DEVICE_CONTROL  5

/*
 * Fetch the pending CEC request and print its name. Power-up and
 * activate-source requests set power_cec_wake_request_flag; a device-control
 * power request sets it only when the operand is 0x40. Any other request
 * code does nothing. Only caller: the code at 0xDC4D.
 */
void hdmi_cec_report_request(void)
{
    switch (hdmi_cec_poll_request()) {
    case CEC_REQUEST_POWER_UP:
        power_cec_wake_request_flag = 1;
        lib_printf517((void code *)0xb9f4 /* "_SYS_CECRequest_PowerUp\r\n" */);
        break;
    case CEC_REQUEST_POWER_DOWN:
        lib_printf517((void code *)0xba0e /* "_SYS_CECRequest_PowerDown\r\n" */);
        break;
    case CEC_REQUEST_ACTIVATE_SC:
        power_cec_wake_request_flag = 1;
        lib_printf517((void code *)0xba2a /* "_SYS_CECRequest_ActivateSC\r\n" */);
        break;
    case CEC_REQUEST_DEVICE_CONTROL:
        if (hdmi_cec_get_operand() == 0x40) power_cec_wake_request_flag = 1;
        lib_printf517((void code *)0xba47 /* "_SYS_CECRequest_DeviceControl_Power\r\n" */);
        break;
    }
}
