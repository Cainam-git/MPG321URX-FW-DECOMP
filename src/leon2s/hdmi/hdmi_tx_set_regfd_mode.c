/* hdmi_tx_set_regfd_mode  (FUN_a0094a50)
 *
 * Set (mode 1) or clear HDMI TX register 0xFD bits 5..6 and two related fields.
 *   port: HDMI TX port
 *   mode: 1 sets the bits, any other value clears them
 * Note: The caller hdmi_tx_run_step passes bit 30 of word 0 of the TX channel record; mode 1 writes 8, any
 *   other mode 4, into the bank 1 register 0x80 field.
 * Name basis: descriptive - register 0xFD mask 0x60, block 0xA00B4D40 reg 0x81 mask 0x30, bank 1 reg 0x80;
 *   caller the FRL link step of hdmi_tx_run_step
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0094a50 @ 0xa0094a50 (-mcpu=v8 -Os -g)
 * Source form: both parameters are unsigned chars; the comparison with 1 selects the value written to bank 1 reg 0x80.
 */
#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

extern void hdmi_tx_reg_update_bits();
extern int hdmi_tx_reg_write_field();
extern int hdmi_tx_sys_reg_update_bits();

/*
 * Set the part of the FRL link set-up that depends on one flag.
 *   port: HDMI TX port 0/1
 *   mode: the flag; hdmi_tx_run_step passes bit 30 of the channel record's word 0
 * With mode 1 the bits are set, with any other value cleared: bits 5..6 of register 0xFD of bank 0 and bits 4..5
 * of register 0x81 of the transmitter system block. Bits 2..3 of register 0x80 of bank 1 become 8 for mode 1,
 * else 4. Called in TX_STEP_LINK_FRL.
 */
void hdmi_tx_set_regfd_mode(unsigned char port, unsigned char mode)
{
    hdmi_tx_reg_update_bits(port, 0, 0xfd, 0x60, mode);
    hdmi_tx_sys_reg_update_bits(port, 0x81, 0x30, mode);
    
    if (mode == 1) {
        hdmi_tx_reg_write_field(port, HDMI_TX_BANK_PHY, 0x80, 0xc, 8);
    } else {
        hdmi_tx_reg_write_field(port, HDMI_TX_BANK_PHY, 0x80, 0xc, 4);
    }
    return;
}
