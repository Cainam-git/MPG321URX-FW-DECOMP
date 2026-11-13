/* dp_tx_init_ports  (FUN_a0085ea8)
 *
 * Initialise the five DP outputs and their PHYs at start-up.
 * Name basis: derived - per output: bank set-up, link registers, PHY and misc registers; called by
 *   input_init_receivers
 *
 * Matching notes
 * --------------
 * FUN_a0085ea8 (leon2s 0xa0085ea8-0xa0086030), flags -mcpu=v8 -Os -g.
 * volatile only on the hardware registers.
 * Source form: output 0 written out before a loop over outputs 1..4 (both for the dp_tx_phy_write_output_field
 * calls and for the per-output sequence).
 */
/* 40-byte record per output (dp_tx_path_records); only the word at +0x20 is used here. */
struct path_record { unsigned char pad[0x20]; unsigned int word_0x20; unsigned char rest[4]; };
extern struct path_record dp_tx_path_records[];
#define R(a) (*(volatile unsigned int *)(a))
extern void dp_tx_phy_set_link_rate(unsigned int, unsigned int, unsigned int, unsigned int);
extern void dp_tx_phy_write_output_field(unsigned int, unsigned int);
extern unsigned char dp_tx_hpd_option_stub_copy(void);
extern unsigned char dp_tx_hpd_option_stub_copy2(unsigned char);
extern void dp_tx_init_ctl_banks(unsigned char);
extern void dp_tx_set_ctl_reg9_bit3(unsigned char, unsigned char);
extern void dp_tx_set_ctl_reg8_bits67(unsigned char, unsigned char);
extern void dp_tx_init_port_link_regs(unsigned char);
extern void dp_tx_init_port_phy(unsigned char);
extern void dp_tx_init_port_extra_regs(unsigned char);

/*
 * Start-up of the five DP outputs: program the PHY for link rate code 0x1e, clear each output's PHY field,
 * then set up every output that is not skipped.
 *
 * Called from input_init_receivers.
 *
 * Order: clear bits 6 and 7 of 0xcf0116bc; call dp_tx_phy_set_link_rate(1, 0x1e, 0, 0) and (0, 0x1e, 0, 0);
 * dp_tx_phy_write_output_field(output, 0) for outputs 0..4; then, for each output the two stub checks
 * (dp_tx_hpd_option_stub_copy for 0, dp_tx_hpd_option_stub_copy2 for 1..4, both 0 in this build) do not skip:
 * control banks, bit 3 of control register 9 from bit 12 of word +0x20 of the output's 40-byte record,
 * bits 6..7 of control register 8 from bits 13..14 of that word, then the link registers, the PHY and the
 * extra registers. Last, clear bits 3 and 4 of 0xcf00f21c.
 */
void dp_tx_init_ports(void)
{
    unsigned char i;     /* output 1..4 */

    R(0xcf0116bc) &= ~0x40;
    R(0xcf0116bc) &= ~0x80;
    dp_tx_phy_set_link_rate(1, 0x1e, 0, 0);
    dp_tx_phy_set_link_rate(0, 0x1e, 0, 0);
    dp_tx_phy_write_output_field(0, 0);
    for (i = 1; i <= 4; i++)
        dp_tx_phy_write_output_field(i, 0);
    if (!dp_tx_hpd_option_stub_copy()) {
        dp_tx_init_ctl_banks(0);
        dp_tx_set_ctl_reg9_bit3(0, (dp_tx_path_records[0].word_0x20 >> 12) & 1);
        dp_tx_set_ctl_reg8_bits67(0, (dp_tx_path_records[0].word_0x20 >> 13) & 3);
        dp_tx_init_port_link_regs(0);
        dp_tx_init_port_phy(0);
        dp_tx_init_port_extra_regs(0);
    }
    for (i = 1; i <= 4; i++) {
        if (dp_tx_hpd_option_stub_copy2(i))
            continue;
        dp_tx_init_ctl_banks(i);
        dp_tx_set_ctl_reg9_bit3(i, (dp_tx_path_records[i].word_0x20 >> 12) & 1);
        dp_tx_set_ctl_reg8_bits67(i, (dp_tx_path_records[i].word_0x20 >> 13) & 3);
        dp_tx_init_port_link_regs(i);
        dp_tx_init_port_phy(i);
        dp_tx_init_port_extra_regs(i);
    }
    R(0xcf00f21c) &= ~0x18;
}
