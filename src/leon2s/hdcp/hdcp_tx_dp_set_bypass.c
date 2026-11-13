/* hdcp_tx_dp_set_bypass  (FUN_a00c68f8)
 *
 * Set or clear bit 6 of the DisplayPort protection control register and print it.
 * Name basis: descriptive - 0xCF018D00 bit 6; flag at 0xA8078C5A; set by a command from the main processor
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c68f8 @ 0xa00c68f8-0xa00c6968 (28 words), flags -mcpu=v8 -Os -g.
 * Source form: the log argument is a fresh volatile re-read of the register after the store. The flag byte is the
 * symbol 0xa8078c5a itself (%lo = 0x5a on the sethi of 0xa8078c00), not base 0xa8078c00 + 0x5a.
 */
extern unsigned char hdcp_tx_dp_bypass_flag;
#define reg_hdcp_tx_dp_control (*(volatile unsigned int *)0xcf018d00)
extern int dbg_printf(unsigned int, ...);

/*
 * Set or clear bit 6 of the DisplayPort protection control register 0xCF018D00 and print the low byte of the
 * register. Runs on the command 0x5D (ipc_set_hdcp_tx_dp_bypass) of the main processor.
 *
 *   bypass_off  non-zero: clear bit 6 and clear hdcp_tx_dp_bypass_flag;
 *               zero: set bit 6 and set hdcp_tx_dp_bypass_flag
 *
 * hdcp_tx_service_port runs the DisplayPort output state machine (hdcp_tx_dp_run_state) for output 2 only
 * while the flag is set.
 */
void hdcp_tx_dp_set_bypass(unsigned char bypass_off)
{
    if (bypass_off != 0) {
        reg_hdcp_tx_dp_control &= 0xffffffbf;
        dbg_printf(0x9f1b7608, (unsigned char)reg_hdcp_tx_dp_control);
        hdcp_tx_dp_bypass_flag = 0;
    } else {
        reg_hdcp_tx_dp_control |= 0x40;
        dbg_printf(0x9f1b7630, (unsigned char)reg_hdcp_tx_dp_control);
        hdcp_tx_dp_bypass_flag = 1;
    }
}
