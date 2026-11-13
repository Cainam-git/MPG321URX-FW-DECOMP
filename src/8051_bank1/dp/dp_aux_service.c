/* dp_aux_service  (FUN_CODE_c1c1)
 *
 * Serve pending AUX requests of both DP receivers.
 * Name basis: derived - pending bits of 0xDCDF/0xDCDE and 0xDCCF/0xDCCE; answer mode (bit 0x15) or snoop mode;
 *   then sys_step_clock_switch; caller irq_ext1_peripherals
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c1c1, OPTIMIZE(7,SPEED), register bank 3 ('using 3').
 * The bit tests are int-typed ('ANL A,#n / JZ'). The chip id test goes through a bit value (CJNE, SETB C / CLR C, JC):
 * written as a '(bit)' conversion of the comparison.
 */
extern unsigned char xdata reg_dp_aux_request_ctrl_port0, reg_dp_aux_mode_port0, reg_dp_aux_request_ctrl_port1, reg_dp_aux_mode_port1, reg_chip_id;
extern bit dp_aux_answer_mode_flag;
void dp_aux_answer_port0(void);
void dp_aux_snoop_port0(void);
void dp_aux_answer_port1(void);
void dp_aux_snoop_port1(void);
void sys_step_clock_switch(void);

/*
 * dp_aux_service - for each DP receiver: when bit 0 of its 0xDCDF (receiver 0) / 0xDCCF (receiver 1) and bit 3 of its
 * mode register (0xDCDE / 0xDCCE) are both set, call the answer routine (dp_aux_answer_mode_flag set) or the snoop
 * routine (flag clear) of that receiver, then set bit 3 of the mode register again. Finally call
 * sys_step_clock_switch unless reg_chip_id is 0x20.
 * Only caller: the interrupt handler irq_ext1_peripherals.
 */
void dp_aux_service(void) using 3
{
    if ((unsigned int)(reg_dp_aux_request_ctrl_port0 & 0x01) && (unsigned int)(reg_dp_aux_mode_port0 & 0x08)) {
        if (dp_aux_answer_mode_flag) dp_aux_answer_port0(); else dp_aux_snoop_port0();
        reg_dp_aux_mode_port0 |= 0x08;
    }
    if ((unsigned int)(reg_dp_aux_request_ctrl_port1 & 0x01) && (unsigned int)(reg_dp_aux_mode_port1 & 0x08)) {
        if (dp_aux_answer_mode_flag) dp_aux_answer_port1(); else dp_aux_snoop_port1();
        reg_dp_aux_mode_port1 |= 0x08;
    }
    if (!(bit)(reg_chip_id == 0x20)) sys_step_clock_switch();
}
