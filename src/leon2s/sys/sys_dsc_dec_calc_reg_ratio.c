/* sys_dsc_dec_calc_reg_ratio  (FUN_a00a6110)
 *
 * Return the ratio of the upper halves of decoder registers 2 and 3.
 *   decoder
 * Returns: ratio
 * Name basis: descriptive - 1 when the divisor or the ratio is 0; caller sys_dsc_dec_run_state
 *
 * Matching notes
 * --------------
 * FUN_a00a6110 (leon2s 0xa00a6110-0xa00a6190, 128 bytes, leaf), flags -mcpu=v8 -Os -g.
 * The register block is read through a volatile pointer again for each use. One result variable (single exit).
 */
struct dsc_decoder_record { unsigned int regs_main; volatile unsigned int *regs_second; unsigned int regs_third; };
extern struct dsc_decoder_record sys_dsc_dec_records[];

/* Divide the upper 16 bits of register word 2 by the upper 16 bits of register word 3 of the decoder's second
 * register block. The result is 1 when the divisor is 0 or when the quotient (as a byte) is 0.
 * Called by sys_dsc_dec_run_state.
 *   decoder: decoder number
 */
unsigned char sys_dsc_dec_calc_reg_ratio(unsigned char decoder)
{
    volatile unsigned int *regs = sys_dsc_dec_records[decoder].regs_second;
    unsigned char ratio = 1;

    if (((regs[3] >> 16) & 0xffff) != 0) {
        ratio = ((regs[2] >> 16) & 0xffff) / ((regs[3] >> 16) & 0xffff);
        if (ratio == 0)
            ratio = 1;
    }
    return ratio;
}
