/* dp_mrx_disable_aux_irqs  (FUN_CODE_d75e)
 *
 * Turn off the AUX request interrupts of both DisplayPort receivers.
 * Name basis: derived - clears bit 0 of the request control regs 0xDCDE/DF and 0xDCCE/CF tested by the AUX
 *   interrupt dp_aux_service
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d75e @ 0xd75e  OPTIMIZE(8,SPEED)
 * Source form: Ghidra's symbol names are kept; the variables are declared with _at_.
 */
unsigned char xdata reg_dp_mrx_aux_irq_enable _at_ 0xcc87;
unsigned char xdata reg_dp_aux_mode_port1 _at_ 0xdcce;
unsigned char xdata reg_dp_aux_request_ctrl_port1 _at_ 0xdccf;
unsigned char xdata reg_dp_aux_mode_port0 _at_ 0xdcde;
unsigned char xdata reg_dp_aux_request_ctrl_port0 _at_ 0xdcdf;
unsigned char xdata DAT_EXTMEM_f161 _at_ 0xf161;

/*
 * Switch off the AUX request interrupts of both DisplayPort receivers: clear bit 0 of XDATA 0xDCDE, 0xDCDF,
 * 0xDCCE and 0xDCCF, set bits 0..1 of 0xF161 (purpose of this register not shown) and clear the AUX interrupt
 * enable bits 3..4 of reg_dp_mrx_aux_irq_enable (0xCC87).
 */
void dp_mrx_disable_aux_irqs(void)

{
  reg_dp_aux_mode_port0 = reg_dp_aux_mode_port0 & 0xfe;
  reg_dp_aux_request_ctrl_port0 = reg_dp_aux_request_ctrl_port0 & 0xfe;
  reg_dp_aux_mode_port1 = reg_dp_aux_mode_port1 & 0xfe;
  reg_dp_aux_request_ctrl_port1 = reg_dp_aux_request_ctrl_port1 & 0xfe;
  DAT_EXTMEM_f161 = DAT_EXTMEM_f161 | 3;
  reg_dp_mrx_aux_irq_enable = reg_dp_mrx_aux_irq_enable & 0xe7;
  return;
}
