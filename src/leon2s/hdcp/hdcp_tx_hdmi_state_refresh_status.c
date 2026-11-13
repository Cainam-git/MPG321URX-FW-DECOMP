/* hdcp_tx_hdmi_state_refresh_status  (FUN_a00cc900)
 *
 * State handler: refresh the status of an output and correct its encryption bit.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_hdmi_run_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cc900 @ 0xa00cc900 (-mcpu=v8 -Os -g)
 * Source form: the record is addressed as bytes of word 0 (port * 0x18); the step result is set with a word
 * 'or' of 0x30000.
 */
extern unsigned char hdcp_tx_records;
extern unsigned char dp_tx_option_enabled_stub_copy2();
extern int hdcp_tx_get_output_status();
extern int hdcp_tx_hdmi_set_reg4_bit7();
extern int hdcp_tx_set_encryption_bit();

#define STEP_AGAIN_BITS         0x30000         /* step_result (word 0 bits 16..17) = 3, STEP_AGAIN */
#define HDCP_TX_RECORD_SIZE     0x18

/*
 * State 0x4F of hdcp_tx_hdmi_run_state: refresh the status of the output.
 *
 * Sets bit 7 of register 4 of the output's protection block, then compares the value of
 * dp_tx_option_enabled_stub_copy2 (it always returns 1) with hdcp_tx_get_output_status; when they differ
 * hdcp_tx_set_encryption_bit is called with the first value. The step result is set to 3 (STEP_AGAIN).
 */
void hdcp_tx_hdmi_state_refresh_status(unsigned int port_arg)
{
  unsigned char wanted;
  unsigned int current;
  unsigned int port;

  port = port_arg & 0xff;
  hdcp_tx_hdmi_set_reg4_bit7(port,1);
  wanted = dp_tx_option_enabled_stub_copy2(port);
  current = hdcp_tx_get_output_status(port);
  if ((wanted & 0xff) != (current & 0xff)) {
    hdcp_tx_set_encryption_bit(port,wanted & 0xff);
  }
  *(unsigned int *)(&hdcp_tx_records + port * HDCP_TX_RECORD_SIZE) =
       *(unsigned int *)(&hdcp_tx_records + port * HDCP_TX_RECORD_SIZE) | STEP_AGAIN_BITS;
}
