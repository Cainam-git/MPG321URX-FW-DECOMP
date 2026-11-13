/* dp_tx_update_edp_fastmute  (FUN_a0089e74)
 *
 * Switch the fast-mute pattern of eDP outputs 1..4 from a control bit.
 * Name basis: proven - prints 'DPTX_EnableEDPFastmutePattern' / 'DPTX_DisableEDPFastmutePattern'; bit 1 of
 *   0xCF03C940
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * The byte counter is initialised at its declaration (the firmware sets it before the test). Both prints pass
 * the final counter value (5).
 */
#define REG_CONTROL_C940 (*(volatile unsigned int *)0xcf03c940)
extern char DAT_a0068c60[], DAT_a0068c90[];
extern int dbg_printf(const char *, ...);
extern void dp_tx_reg_update_bits(unsigned int, short, unsigned int, unsigned int);

#define CONTROL_C940_FASTMUTE_BIT 2

/*
 * Set or clear bit 4 of register 0x7D on eDP outputs 1..4 (not output 0) according to bit 1 of register
 * 0xCF03C940, and print "DPTX_EnableEDPFastmutePattern %d" or "DPTX_DisableEDPFastmutePattern %d" with the
 * counter value 5.
 */
void dp_tx_update_edp_fastmute(void)
{
    unsigned char output = 1;

    if (REG_CONTROL_C940 & CONTROL_C940_FASTMUTE_BIT) {
        for (; output <= 4; output++)
            dp_tx_reg_update_bits(output, 0x7d, 0x10, 1);
        dbg_printf(DAT_a0068c60, output);
    } else {
        for (; output <= 4; output++)
            dp_tx_reg_update_bits(output, 0x7d, 0x10, 0);
        dbg_printf(DAT_a0068c90, output);
    }
}
