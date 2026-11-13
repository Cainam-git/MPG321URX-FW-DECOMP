/* hdmi_cec_get_operand  (FUN_CODE_dedc)
 *
 * Return the operand byte of the last CEC request.
 * Returns: operand
 * Name basis: derived - byte 0xA759; hdmi_cec_report_request treats DeviceControl_Power with operand 0x40 as
 *   power-up
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dedc @ 0xdedc  OPTIMIZE(7,SPEED)
 * Source form: the byte is defined here with _at_ 0xa759.
 */
unsigned char xdata hdmi_cec_operand _at_ 0xa759;

/*
 * Return hdmi_cec_operand: hdmi_cec_receive_message stores there the byte after opcode 0x44 (CEC_OP_USER_CONTROL)
 * of a received message; hdmi_cec_select_port sets it to 0xFF. Only caller: hdmi_cec_report_request, which takes
 * operand 0x40 of a device-control power request as a power-up request.
 */
unsigned char hdmi_cec_get_operand(void) {
    return hdmi_cec_operand;
}
