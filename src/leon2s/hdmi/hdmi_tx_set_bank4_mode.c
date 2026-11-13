/* hdmi_tx_set_bank4_mode  (FUN_a0094e40)
 *
 * Set the HDMI TX bank 4 mode bits and reg 8 bits 4..5 for a mode.
 *   port: HDMI TX port
 *   frl_rate: mode
 *   dsc_enable: 1 = variant
 * Name basis: descriptive - bank 4 reg 0 bits 0..1, bank 0 reg 8 bits 4..5
 *
 * Matching notes
 * --------------
 * FUN_a0094e40 (leon2s 0xa0094e40-0xa0094f64, 292 bytes), flags -mcpu=v8 -Os -g.
 * Source form: bit 15 of word +0x14 is a 1-bit bit-field (srl 15 / btst 1), tested with the 0 arm first; each test
 * selects between two full calls; the last call is a sibling call.
 */
#define HDMI_TX_BANK_CORE 0             /* bank 0 of an HDMI transmitter's registers */
#define HDMI_TX_BANK_FRL  4             /* bank 4 of an HDMI transmitter's registers (the FRL registers) */

/* Channel record of an HDMI TX port (hdmi_tx_output_records, 0x1c bytes); only the fields used here are named. */
struct hdmi_tx_channel_record {
    unsigned char byte_0x0, source_code, audio_source, byte_0x3;
    unsigned int words_0x4[4];
    unsigned int : 16;
    unsigned int word_0x14_bit15 : 1;   /* set together with word 0 bit 2 by the TX request (command 0x40..0x44) */
    unsigned int : 15;
    unsigned int word_0x18;
};
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];
extern void hdmi_tx_reg_update_bits(unsigned int port, unsigned int sub, short reg, unsigned int mask, unsigned int mode);
extern void hdmi_tx_sys_reg_update_bits(unsigned int param_1, short param_2, unsigned int param_3, unsigned int param_4);

/*
 * Set the mode bits of bank 4 register 0 and bits 4..5 of bank 0 register 8.
 *   port: HDMI TX port 0/1
 *   frl_rate: the channel's FRL rate; 1, 2 and 10 clear bit 1 of bank 4 register 0, every other value sets it
 *   dsc_enable: 1 = clear bit 4 of bank 0 register 8 and set bit 4 of register 0xA3 of the transmitter system
 *     block; any other value sets bit 4 of register 8 only
 * Bit 0 of bank 4 register 0 follows bit 15 of word 5 of the channel record. Bit 5 of bank 0 register 8 is set last.
 * Called by hdmi_tx_run_step in TX_STEP_LINK_FRL with the channel's frl_rate and its dsc_enable bit.
 */
void hdmi_tx_set_bank4_mode(unsigned char port, unsigned char frl_rate, unsigned char dsc_enable)
{
    if (frl_rate == 1 || frl_rate == 2 || frl_rate == 10)
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_FRL, 0, 2, 0);
    else
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_FRL, 0, 2, 1);
    if (!hdmi_tx_output_records[port].word_0x14_bit15)
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_FRL, 0, 1, 0);
    else
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_FRL, 0, 1, 1);
    if (dsc_enable == 1) {
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_CORE, 8, 0x10, 0);
        hdmi_tx_sys_reg_update_bits(port, 0xa3, 0x10, 1);
    } else
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_CORE, 8, 0x10, 1);
    hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_CORE, 8, 0x20, 1);
}
