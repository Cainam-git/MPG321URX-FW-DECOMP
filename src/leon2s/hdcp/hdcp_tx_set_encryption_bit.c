/* hdcp_tx_set_encryption_bit  (FUN_a00cc834)
 *
 * Set or clear the encryption control bit of an output.
 * Name basis: descriptive - an indexed register bit for output 2, register 4 bit 4 for the HDMI outputs
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cc834 @ 0xa00cc834-0xa00cc8d4 (160 bytes), flags -mcpu=v8 -Os -g.
 * Source form: one call per arm (the compiler keeps both argument sets and shares the call); the register
 * address is recomputed in each arm of output 2.
 */
#define reg_hdcp_tx_dp_control (*(volatile unsigned int *)0xcf018d00)
extern void hdcp_tx_reg_update_bits(unsigned char port, unsigned short reg, unsigned char mask, unsigned char set);

#define OUTPUT_DP               2               /* the DisplayPort output */
#define DP_ENCRYPTION_BIT       2               /* bit 1 of the register word used for output 2 */
#define HDMI_ENCRYPTION_REG     4               /* register of the HDMI output's protection block */
#define HDMI_ENCRYPTION_MASK    0x10            /* bit 4 of that register */

/*
 * Set (on != 0) or clear (on == 0) the encryption bit of an output.
 *
 * Output 2 (DisplayPort): the bit is in the register word whose address is 0xcf000000 | (value of
 * reg_hdcp_tx_dp_control << 2). The HDMI outputs (0 and 1): bit 4 of register 4 of the output's protection block.
 */
void hdcp_tx_set_encryption_bit(unsigned char port, unsigned char on)
{
    if (port == OUTPUT_DP) {
        if (on)
            *(volatile unsigned int *)((reg_hdcp_tx_dp_control << 2) | 0xcf000000) |= DP_ENCRYPTION_BIT;
        else
            *(volatile unsigned int *)((reg_hdcp_tx_dp_control << 2) | 0xcf000000) &= ~DP_ENCRYPTION_BIT;
    } else {
        if (on)
            hdcp_tx_reg_update_bits(port, HDMI_ENCRYPTION_REG, HDMI_ENCRYPTION_MASK, 1);
        else
            hdcp_tx_reg_update_bits(port, HDMI_ENCRYPTION_REG, HDMI_ENCRYPTION_MASK, 0);
    }
}
