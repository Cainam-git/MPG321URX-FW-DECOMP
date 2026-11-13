/* dp_mrx_read_reg  (FUN_CODE_d737)
 *
 * Read one register of DisplayPort receiver 0 or 1.
 *   sel: receiver 0/1
 *   idx: register
 * Returns: register byte
 * Note: Runs in register bank 3 (interrupt context).
 * Name basis: derived - banks 0x4D00/0x4E00 programmed by DP_EnableMRX and the AUX request handler
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d737 @ 0xd737  Options: OPTIMIZE(8,SPEED) LARGE.
 * Source form: 'using 3' (register bank 3, entry PUSH PSW / MOV PSW,#18H). For a receiver other than 0 or 1 the
 * result is not set: the firmware returns R6 of bank 3 as it is (MOV R7,1EH). LARGE gives the second test
 * MOV A,R7 / CJNE A,#01H (SMALL: CJNE R7: 51 %); the window bases must be array symbols (MOV A,#LOW sym / ADD A,R5).
 */
extern unsigned char xdata reg_dp_mrx0_window[];
extern unsigned char xdata reg_dp_mrx1_window[];

/*
 * Read register 'reg_index' of DisplayPort receiver 0 or 1 ('receiver'). Runs in register bank 3. Twin of
 * dp_mrx_write_reg. Called by the DP receiver set-up code (dp_aux_track_link_training, dp_mrx_init_regs_c6).
 */
unsigned char dp_mrx_read_reg(unsigned char receiver, unsigned char reg_index) using 3
{
    unsigned char value;

    if (receiver == 0) value = reg_dp_mrx0_window[reg_index];
    else if (receiver == 1) value = reg_dp_mrx1_window[reg_index];
    return value;
}
