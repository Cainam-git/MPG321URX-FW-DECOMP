/* hdmi_cec_set_two_regs  (FUN_CODE_de3a)
 *
 * Write the two values of mailbox command 0x24 into CEC block registers.
 *   dest: first value
 *   length: second value
 * Name basis: descriptive - CEC block 0xD80x (hdmi_cec_*): regs 0xD820 = p1, 0xD810 = p2
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_de3a @ 0xde3a  OPTIMIZE(7,SPEED)
 * Source form: the _at_ variable declarations give 'MOV DPTR,#addr; MOV A,Rn; MOVX @DPTR,A' for each store, in source order.
 */
unsigned char xdata reg_hdmi_cec_tx_dest _at_ 0xD820;
unsigned char xdata reg_hdmi_cec_tx_length _at_ 0xD810;

/* Store the destination address and the byte count of the CEC message to
 * send (mailbox command 0x24).
 *   dest:   value for reg_hdmi_cec_tx_dest
 *   length: value for reg_hdmi_cec_tx_length */
void hdmi_cec_set_two_regs(unsigned char dest, unsigned char length) {
    reg_hdmi_cec_tx_dest = dest;
    reg_hdmi_cec_tx_length = length;
}
