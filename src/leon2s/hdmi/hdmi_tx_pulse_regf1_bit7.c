/* hdmi_tx_pulse_regf1_bit7  (FUN_a0094a10)
 *
 * Pulse bit 7 of HDMI TX bank 3 register 0xF1.
 *   port: HDMI TX port 0/1
 * Name basis: descriptive - set, wait, clear
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0094a10 @ 0xa0094a10 (-mcpu=v8 -Os -g)
 * Source form: the port parameter is a byte-wide value passed straight on.
 */
#define HDMI_TX_BANK_VTEM 3             /* bank 3 of an HDMI transmitter's registers */

extern void hdmi_tx_reg_update_bits();
extern int timer_delay_long_units();

/*
 * Pulse bit 7 of register 0xF1 of bank 3: set it, wait one delay unit (timer_delay_long_units(1)), clear it.
 *   port: HDMI TX port 0/1
 * Called by hdmi_tx_run_step at the end of the FRL link step (TX_STEP_LINK_FRL).
 */
void hdmi_tx_pulse_regf1_bit7(unsigned char port)

{
  hdmi_tx_reg_update_bits(port,HDMI_TX_BANK_VTEM,0xf1,0x80,1);
  timer_delay_long_units(1);
  hdmi_tx_reg_update_bits(port,HDMI_TX_BANK_VTEM,0xf1,0x80,0);
  return;
}
