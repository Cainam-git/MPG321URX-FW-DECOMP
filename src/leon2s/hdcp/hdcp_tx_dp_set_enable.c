/* hdcp_tx_dp_set_enable  (FUN_a00cca38)
 *
 * Switch the protection of the DisplayPort output on or off.
 * Name basis: derived - bit 1 of 0xCF018D00 and two companion bits
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cca38 @ 0xa00cca38 (-mcpu=v8 -Os -g)
 * Source form: the registers are volatile words addressed by literal; the 'else' arm clears with the mask
 * 0xfffffffe / 0xfffffffd.
 */
extern int dp_tx_ctl_reg_read8();

#define REG_HDCP_TX_DP_CONTROL  0xcf018d00      /* reg_hdcp_tx_dp_control; bit 1 = enable */
#define REG_CF018D54            0xcf018d54
#define REG_CF018DDC            0xcf018ddc

/*
 * Switch the protection of the DisplayPort output on (enable == 1) or off (any other value).
 *
 * On: when bit 0 of dp_tx_ctl_reg_read8(0, 6) is set, bit 1 of register 0xcf018d54 and bit 0 of register
 * 0xcf018ddc are set first; then bit 1 of the control register 0xcf018d00 is set.
 * Off: when that same bit 0 is set, bit 0 of 0xcf018ddc is cleared; then bit 1 of 0xcf018d00 is cleared.
 */
void hdcp_tx_dp_set_enable(unsigned int enable)
{
    unsigned int ctl_bits;

    if ((enable & 0xff) == 1)
    {
        ctl_bits = dp_tx_ctl_reg_read8(0, 6);
        if (ctl_bits & 1)
        {
            *(volatile unsigned int *)REG_CF018D54 |= 2;
            *(volatile unsigned int *)REG_CF018DDC |= 1;
        }
        *(volatile unsigned int *)REG_HDCP_TX_DP_CONTROL |= 2;
    }
    else
    {
        ctl_bits = dp_tx_ctl_reg_read8(0, 6);
        if (ctl_bits & 1)
        {
            *(volatile unsigned int *)REG_CF018DDC &= 0xfffffffe;
        }
        *(volatile unsigned int *)REG_HDCP_TX_DP_CONTROL &= 0xfffffffd;
    }
}
