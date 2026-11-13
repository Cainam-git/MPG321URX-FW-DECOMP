/* dp_mrx_write_reg  (FUN_CODE_d884)
 *
 * Write one register of DisplayPort receiver 0 or 1.
 *   sel: receiver 0/1
 *   idx: register
 *   v: value
 * Note: Runs in register bank 3 (interrupt context).
 * Name basis: derived - 72 calls from DP_EnableMRX set-up sequences and the AUX request handler
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d884 @ 0xd884  Options: OPTIMIZE(8,SPEED) LARGE.
 * Source form: 'using 3'. LARGE gives MOV A,R7 / CJNE A,#01H (SMALL does not); a switch gives other code.
 */
extern unsigned char xdata reg_dp_mrx0_window[];
extern unsigned char xdata reg_dp_mrx1_window[];

/*
 * Write 'value' to register 'reg_index' of DisplayPort receiver 0 or 1 ('receiver'); other receiver numbers
 * write nothing. Runs in register bank 3. Twin of dp_mrx_read_reg. Called by the DP receiver set-up code
 * (dp_aux_track_link_training, dp_mrx_init_regs_80_fc, dp_mrx_init_regs_c6).
 */
void dp_mrx_write_reg(unsigned char receiver, unsigned char reg_index, unsigned char value) using 3
{
    if (receiver == 0) reg_dp_mrx0_window[reg_index] = value;
    else if (receiver == 1) reg_dp_mrx1_window[reg_index] = value;
}
