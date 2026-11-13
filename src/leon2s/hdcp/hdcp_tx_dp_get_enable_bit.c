/* hdcp_tx_dp_get_enable_bit  (FUN_a00c972c)
 *
 * Return the protection enable bit of the DisplayPort output.
 * Returns: 0 or 1
 * Name basis: descriptive - bit 1 of register 0xCF018D00
 *
 * Matching notes
 * --------------
 * FUN_a00c972c (leon2s 0xa00c972c-0xa00c9750, 36 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: a result byte that starts at 0, returned as 'result & 1' (as in sys_dsc_dec_get_regb4_bit2).
 */
#define reg_hdcp_tx_dp_control (*(volatile unsigned int *)0xcf018d00)

#define DP_CONTROL_ENABLE_BIT 0x02              /* bit 1 of reg_hdcp_tx_dp_control */

/*
 * Return bit 1 of the DisplayPort protection control register 0xCF018D00 (0 or 1).
 *
 * Called by hdcp_tx_get_output_status, hdcp_tx_dp_state_sync_enable and hdcp_tx_dp_state_sync_enable_copy.
 */
unsigned char hdcp_tx_dp_get_enable_bit(void)
{
    unsigned char result = 0;

    if (reg_hdcp_tx_dp_control & DP_CONTROL_ENABLE_BIT)
        result = 1;
    return result & 1;
}
