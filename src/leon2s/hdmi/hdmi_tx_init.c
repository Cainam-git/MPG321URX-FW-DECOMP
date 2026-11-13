/* hdmi_tx_init  (FUN_a0095c30)
 *
 * Reset and prepare both HDMI TX ports at start-up.
 * Name basis: derived - hdmi_tx_reset_channel, step 0x10, DDC divider 100 per port; caller
 *   input_init_receivers
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0095c30 @ 0xa0095c30 (-mcpu=v8 -Os -g)
 * Source form: the six parameters of the decompilation are kept; the loop counter is a byte (do/while).
 */
#define TX_STEP_INIT_CORE_REGS 0x10     /* hdmi_tx_run_step step 16 */
#define HDMI_TX_BANK_VTEM      3        /* bank 3 of an HDMI transmitter's registers */
#define DDC_DIVIDER_START      100      /* start value of the DDC clock divider */

extern int hdmi_tx_reset_channel();
extern void hdmi_tx_set_ddc_clock_divider();
extern void hdmi_tx_run_step();
extern int hdmi_tx_frl_start_timer();
extern int hdmi_tx_frl_init_timer();
extern int hdmi_tx_reg_update_bits();

/*
 * Set both HDMI TX ports up at start-up and start the FRL training timer.
 * For each port: reset its channel record, run the core register step (TX_STEP_INIT_CORE_REGS), set the DDC clock
 * divider to its start value and set bit 4 of register 0xF2 of bank 3. Then the FRL training timer is created
 * and started.
 * The parameters are not used by this routine; the last five are handed on to hdmi_tx_frl_start_timer, which
 * ignores them. The caller (input_init_receivers) passes none.
 */
void hdmi_tx_init(unsigned int unused_arg, unsigned int forwarded_arg_1, unsigned int forwarded_arg_2,
                  unsigned int forwarded_arg_3, unsigned int forwarded_arg_4, unsigned int forwarded_arg_5)

{
  unsigned char port;
  
  port = 0;
  do {
    hdmi_tx_reset_channel(port);
    hdmi_tx_run_step(port,TX_STEP_INIT_CORE_REGS);
    hdmi_tx_set_ddc_clock_divider(port,DDC_DIVIDER_START);
    hdmi_tx_reg_update_bits(port,HDMI_TX_BANK_VTEM,0xf2,0x10,1);
    port = port + 1;
  } while (port < 2);
  hdmi_tx_frl_init_timer(0);
  hdmi_tx_frl_start_timer(0,forwarded_arg_1,forwarded_arg_2,forwarded_arg_3,forwarded_arg_4,forwarded_arg_5);
  return;
}
