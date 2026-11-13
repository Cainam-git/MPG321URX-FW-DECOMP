/* hdmi_clear_scdc_config  (FUN_a008ff58)
 *
 * Clear the SCDC configuration mirror registers of an HDMI receiver.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: derived - regs 0x2DF..0x2E1 (0x2E1 = TMDS_Config mirror) and 0x2FD bit 3
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008ff58 @ 0xa008ff58 (-mcpu=v8 -Os -g)
 * Source form: the writes are in the order 0x2E1, 0x2DF, 0x2E0, then bit 3 of 0x2FD.
 */

#define RX_REG_2DF  0x2df
#define RX_REG_2E0  0x2e0
#define RX_REG_2E1  0x2e1
#define RX_REG_2FD  0x2fd

extern void hdmi_reg_write8();
extern int hdmi_reg_update_bits();

/* Registers 0x2E1, 0x2DF and 0x2E0 are set to 0 and bit 3 of register 0x2FD is cleared (hdmi_set_reg2fd_bit3 sets that bit).
   Called by hdmi_tmds_restart_port. */
void hdmi_clear_scdc_config(unsigned char port)
{
    hdmi_reg_write8(port, RX_REG_2E1, 0);
    hdmi_reg_write8(port, RX_REG_2DF, 0);
    hdmi_reg_write8(port, RX_REG_2E0, 0);
    hdmi_reg_update_bits(port, RX_REG_2FD, 8, 0);
}
