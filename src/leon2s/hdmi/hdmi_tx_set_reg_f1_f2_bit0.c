/* hdmi_tx_set_reg_f1_f2_bit0  (FUN_a009498c)
 *
 * Set bit 0 of HDMI TX bank 3 registers 0xF1 and 0xF2 from the record flags.
 *   port: HDMI TX port 0/1
 * Name basis: descriptive - word 0 bit 2 sets both; 0xF2 only when not in FRL mode
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009498c @ 0xa009498c (-mcpu=v8 -Os -g)
 * Source form: the record word is read again for the second test (as in the original); the third argument value of the
 * last call of each branch is the flag variable, 1 or 0.
 */
#define HDMI_TX_BANK_VTEM 3             /* bank 3 of an HDMI transmitter's registers */

#define CHANNEL_WORD0_BIT2     0x04     /* word 0 of the channel record; no name known */
#define CHANNEL_FRL_MODE       0x10     /* word 0 bit 4: the channel is in FRL mode */

extern void hdmi_tx_reg_update_bits();
extern unsigned int hdmi_tx_output_records[];     /* channel records of the HDMI TX ports, 7 words each */

/*
 * Set (or clear) bit 0 of registers 0xF1 and 0xF2 of bank 3 according to bit 2 of the channel record's word 0.
 *   port: HDMI TX port 0/1
 * With bit 2 set, bit 0 of register 0xF1 is set, and bit 0 of register 0xF2 is set too unless the channel is in
 * FRL mode. With bit 2 clear, both bits are cleared.
 * Called by hdmi_tx_run_step in the two packet set-up steps, after the sync polarity.
 */
void hdmi_tx_set_reg_f1_f2_bit0(unsigned int port)
{
    unsigned int index;
    unsigned int on;

    index = port & 0xff;
    on = 0;
    if ((hdmi_tx_output_records[index * 7] & CHANNEL_WORD0_BIT2) != 0) {
        on = 1;
        hdmi_tx_reg_update_bits(index, HDMI_TX_BANK_VTEM, 0xf1, 1, 1);
        if ((hdmi_tx_output_records[index * 7] & CHANNEL_FRL_MODE) == 0) {
            hdmi_tx_reg_update_bits(index, HDMI_TX_BANK_VTEM, 0xf2, 1, on);
        }
    } else {
        hdmi_tx_reg_update_bits(index, HDMI_TX_BANK_VTEM, 0xf1, 1, 0);
        hdmi_tx_reg_update_bits(index, HDMI_TX_BANK_VTEM, 0xf2, 1, on);
    }
}
