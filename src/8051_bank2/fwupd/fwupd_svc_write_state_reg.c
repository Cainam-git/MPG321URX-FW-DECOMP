/* fwupd_svc_write_state_reg  (FUN_CODE_d99e)
 *
 * Write the configured register value for one of two states over the service link.
 *   state: state 0/1
 * Name basis: derived - record 0x06F2..0x06F6 = enable flag, register number high / low, value for state 0 /
 *   1; fwupd_svc_write_register; caller fwupd_write_flash_blocks
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. LARGE parameter state (0x08FD), local reg (0x08FE).
 * The two arms end the same (MOVX A,@DPTR; MOV R5,A; LCALL da8a) and Keil cross-jumps them (SJMP 0xD9FC); the
 * failing tests jump to the RET (0xDA01), so there is no tail LJMP. The early-return form
 * 'if (fwupd_state_reg_on_flag != 1) return;' gives the same bytes; '(reg << 8) + fwupd_state_reg_number_low' does not (108 B).
 */
/* Five bytes at XDATA 0x06F2: on flag, register number high / low byte, value for state 0, value for state 1. */
extern unsigned char xdata fwupd_state_reg_on_flag, fwupd_state_reg_number_high, fwupd_state_reg_number_low, fwupd_state_reg_value_0, fwupd_state_reg_value_1;
unsigned char fwupd_svc_write_register(unsigned int reg, unsigned char val);

/* fwupd_svc_write_state_reg: when fwupd_state_reg_on_flag is 1, write one register of the main chip over the service link
 * (fwupd_svc_write_register): register (fwupd_state_reg_number_high << 8) | fwupd_state_reg_number_low, value fwupd_state_reg_value_0 for state 0
 * or fwupd_state_reg_value_1 for state 1. Any other state, or another flag value, writes nothing.
 *
 * state: 0 or 1.
 * Caller: fwupd_write_flash_blocks, before every block it writes, with bit 5 of the block number, so the state changes every
 * 32 blocks. fwupd_run_isp_write clears fwupd_state_reg_on_flag before the write starts. */
void fwupd_svc_write_state_reg(unsigned char state)
{
    unsigned int reg;
    if (fwupd_state_reg_on_flag == 1) {
        if (state == 0) {
            reg = fwupd_state_reg_number_high;
            reg = (reg << 8) | fwupd_state_reg_number_low;
            fwupd_svc_write_register(reg, fwupd_state_reg_value_0);
        } else if (state == 1) {
            reg = fwupd_state_reg_number_high;
            reg = (reg << 8) | fwupd_state_reg_number_low;
            fwupd_svc_write_register(reg, fwupd_state_reg_value_1);
        }
    }
}
