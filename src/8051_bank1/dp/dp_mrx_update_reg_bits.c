/* dp_mrx_update_reg_bits  (FUN_CODE_c73e)
 *
 * Set or clear bits in one register of DP receiver 0 or 1.
 *   receiver: receiver 0/1
 *   reg_index: register
 *   mask: bits
 *   set_bits: 1 set, 0 clear
 * Name basis: derived - 0x4D00[idx] (receiver 0) / 0x4E00[idx] (receiver 1), the banks of dp_mrx_read_reg /
 *   dp_mrx_write_reg
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c73e @ 0xc73e (82 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * LARGE parameter block at XDATA 0xA4B9: 'receiver' is stored there and read back for the second test; the fourth
 * parameter does not fit in registers and is passed in its slot 0xA4BC. 'reg_index' stays in R5, 'mask' in R3.
 * Keil shares the final read-modify-write of both 'set_bits == 1' paths and of both clear paths.
 */
extern unsigned char xdata reg_dp_mrx0_window[];
extern unsigned char xdata reg_dp_mrx1_window[];

/*
 * Set (set_bits == 1) or clear (any other value) the bits of mask in register
 * reg_index of DP receiver 0 or 1. Any other receiver number does nothing.
 * Called with receiver 0/1 from the code at 0x45AA and 0x942E.
 */
void dp_mrx_update_reg_bits(unsigned char receiver, unsigned char reg_index, unsigned char mask, unsigned char set_bits)
{
    if (receiver == 0) {
        if (set_bits == 1) reg_dp_mrx0_window[reg_index] |= mask;
        else reg_dp_mrx0_window[reg_index] &= ~mask;
    } else if (receiver == 1) {
        if (set_bits == 1) reg_dp_mrx1_window[reg_index] |= mask;
        else reg_dp_mrx1_window[reg_index] &= ~mask;
    }
}
