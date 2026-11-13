/* dp_tx_update_edp_post_pattern  (FUN_a0089f00)
 *
 * Switch the post pattern of eDP outputs 1..4 from a control bit.
 * Note: Register 0x11 = 0x1B is the same write dp_tx_set_reg11_mode does, so that routine sets the post
 *   pattern.
 * Name basis: proven - prints 'DPTX_EnableEDPPostPattern' / 'DPTX_DisableEDPPostPattern'; bit 2 of 0xCF03C940,
 *   reg 0x11 = 0x1B
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * The byte counter is initialised at its declaration (the firmware sets it before the test). Both prints pass
 * the final counter value (5).
 */
#define REG_CONTROL_C940 (*(volatile unsigned int *)0xcf03c940)
extern char DAT_a0068cc0[], DAT_a0068cf0[];
extern int dbg_printf(const char *, ...);
extern void dp_tx_reg_write8(unsigned int, unsigned short, unsigned int);

#define CONTROL_C940_POST_PATTERN_BIT 4

/*
 * Write register 0x11 on eDP outputs 1..4 (not output 0): 0x1B when bit 2 of register 0xCF03C940 is set,
 * otherwise 0. Prints "DPTX_EnableEDPPostPattern %d" or "DPTX_DisableEDPPostPattern %d" with the counter
 * value 5. dp_tx_set_reg11_mode writes the same register-0x11 values.
 */
void dp_tx_update_edp_post_pattern(void)
{
    unsigned char output = 1;

    if (REG_CONTROL_C940 & CONTROL_C940_POST_PATTERN_BIT) {
        for (; output <= 4; output++)
            dp_tx_reg_write8(output, 0x11, 0x1b);
        dbg_printf(DAT_a0068cc0, output);
    } else {
        for (; output <= 4; output++)
            dp_tx_reg_write8(output, 0x11, 0);
        dbg_printf(DAT_a0068cf0, output);
    }
}
