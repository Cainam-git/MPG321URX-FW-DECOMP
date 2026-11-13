/* dp_tx_phy_apply_output_options  (FUN_a00ab584)
 *
 * Write the stored per-output PHY option bytes, or the defaults.
 * Name basis: descriptive - bytes 0xA807D28C.. when 0xA807D289 is 0xA0, else 0x80; registers 0xCF013280 /
 *   0xCF013284; caller dp_tx_init_port_phy
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ab584 @ 0xa00ab584, flags -mcpu=v8 -Os -g. Leaf.
 * Source form: one base symbol covers the flag byte and the five option bytes; the select write is an
 * unsigned char cast; select_bits is read once; only the two registers are volatile.
 */
#define DP_TX_PHY_SELECT_REG (*(volatile unsigned int *)0xcf013280)   /* bits 0..4 */
#define DP_TX_PHY_OPTION_REG (*(volatile unsigned int *)0xcf013284)   /* low 5 bits kept, rest written */
extern unsigned char sys_otp_dp_tx_phy_options[];   /* [0] = 0xA0 when valid; [3..7] = one option byte per bit */

/*
 * Write the option byte of each of the five select bits (bits 0..4 of register 0xCF013280) into register
 * 0xCF013284: first the select bit is set, then the option register is updated, keeping its low 5 bits.
 *
 * The bytes come from sys_otp_dp_tx_phy_options[3..7] when byte [0] is 0xA0. Otherwise all five select bits are
 * set at once and the option register gets the fixed value 0x80. Caller: dp_tx_init_port_phy.
 */
void dp_tx_phy_apply_output_options(void)
{
    unsigned int select_bits;

    if (sys_otp_dp_tx_phy_options[0] == 0xa0) {
        select_bits = DP_TX_PHY_SELECT_REG & ~0x1f;
        DP_TX_PHY_SELECT_REG = (unsigned char)(select_bits | 1);
        DP_TX_PHY_OPTION_REG = (DP_TX_PHY_OPTION_REG & 0x1f) | sys_otp_dp_tx_phy_options[3];
        DP_TX_PHY_SELECT_REG = (unsigned char)(select_bits | 2);
        DP_TX_PHY_OPTION_REG = (DP_TX_PHY_OPTION_REG & 0x1f) | sys_otp_dp_tx_phy_options[4];
        DP_TX_PHY_SELECT_REG = (unsigned char)(select_bits | 4);
        DP_TX_PHY_OPTION_REG = (DP_TX_PHY_OPTION_REG & 0x1f) | sys_otp_dp_tx_phy_options[5];
        DP_TX_PHY_SELECT_REG = (unsigned char)(select_bits | 8);
        DP_TX_PHY_OPTION_REG = (DP_TX_PHY_OPTION_REG & 0x1f) | sys_otp_dp_tx_phy_options[6];
        DP_TX_PHY_SELECT_REG = (unsigned char)(select_bits | 0x10);
        DP_TX_PHY_OPTION_REG = (DP_TX_PHY_OPTION_REG & 0x1f) | sys_otp_dp_tx_phy_options[7];
    } else {
        DP_TX_PHY_SELECT_REG |= 0x1f;
        DP_TX_PHY_OPTION_REG = (DP_TX_PHY_OPTION_REG & 0x1f) | 0x80;
    }
}
