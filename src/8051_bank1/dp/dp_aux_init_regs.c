/* dp_aux_init_regs  (FUN_CODE_b56a)
 *
 * Load the start values of both DP receivers' AUX registers.
 * Name basis: derived - registers 0xDCB0..0xDCEA; enable bits by bit 0x00; only caller DP_EnableMRX
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_b56a, OPTIMIZE(8,SPEED). 0xDCB0.. and 0xDCE0.. are written as arrays (one MOV DPTR, then INC
 * DPTR); Keil loads 0x0C as INC A after 0x0B.
 */
extern unsigned char xdata DAT_EXTMEM_dcb0[];
extern unsigned char xdata DAT_EXTMEM_dce0[];
extern unsigned char xdata DAT_EXTMEM_dcb8, reg_dp_aux_ctrl_port1, reg_dp_aux_ctrl_port0, reg_dp_aux_mode_port0, reg_dp_aux_mode_port1;
extern bit sys_shared_bit_param;

/*
 * dp_aux_init_regs - write fixed start values into the AUX register block 0xDCB0..0xDCEA of the two DP receivers:
 * 0xDCB0..0xDCB3, 0xDCB8, the two control registers (4 each) and the eleven bytes 0xDCE0..0xDCEA. Then, by the
 * shared bit sys_shared_bit_param: set (or clear) bit 0 of 0xDCE8 and 0xDCEA and bit 6 of the two mode registers.
 * Only caller: DP_EnableMRX.
 */
void dp_aux_init_regs(void)
{
    DAT_EXTMEM_dcb0[0] = 0x01;
    DAT_EXTMEM_dcb0[1] = 0x2d;
    DAT_EXTMEM_dcb0[2] = 0x37;
    DAT_EXTMEM_dcb0[3] = 0x06;
    DAT_EXTMEM_dcb8 = 0xb2;
    reg_dp_aux_ctrl_port1 = 0x04;
    reg_dp_aux_ctrl_port0 = 0x04;
    DAT_EXTMEM_dce0[0] = 0x0b;
    DAT_EXTMEM_dce0[1] = 0x17;
    DAT_EXTMEM_dce0[2] = 0x0b;
    DAT_EXTMEM_dce0[3] = 0x0c;
    DAT_EXTMEM_dce0[4] = 0x36;
    DAT_EXTMEM_dce0[5] = 0xd9;
    DAT_EXTMEM_dce0[6] = 0xb5;
    DAT_EXTMEM_dce0[7] = 0x04;
    DAT_EXTMEM_dce0[8] = 0x0e;
    DAT_EXTMEM_dce0[9] = 0x08;
    DAT_EXTMEM_dce0[10] = 0x0e;
    if (sys_shared_bit_param) {
        DAT_EXTMEM_dce0[8] |= 0x01;
        reg_dp_aux_mode_port0 |= 0x40;
        DAT_EXTMEM_dce0[10] |= 0x01;
        reg_dp_aux_mode_port1 |= 0x40;
    } else {
        DAT_EXTMEM_dce0[8] &= ~0x01;
        reg_dp_aux_mode_port0 &= ~0x40;
        DAT_EXTMEM_dce0[10] &= ~0x01;
        reg_dp_aux_mode_port1 &= ~0x40;
    }
}
