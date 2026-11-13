/* dp_tx_clear_caps_valid  (FUN_a00866b8)
 *
 * Clear the valid bit of a DP output's sink capability record.
 *   output
 * Name basis: descriptive - bit 7 of byte 0 of the 6-byte caps record; caller dp_tx_run_hpd_actions
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00866b8 @ 0xa00866b8 (-mcpu=v8 -Os -g)
 * Source form: the record offset is an unsigned short local.
 */
extern unsigned char dp_tx_sink_caps_records[];    /* 6-byte caps record per output */

/*
 * Clear bit 7 of byte 0 of the output's 6-byte record in dp_tx_sink_caps_records. Called by DPTX_IsHPDAction_Off.
 *   output: link output
 */
void dp_tx_clear_caps_valid(unsigned int output)
{
  unsigned short offset;
  
  offset = (output & 0xff) * 6;
  dp_tx_sink_caps_records[offset] = dp_tx_sink_caps_records[offset] & 0x7f;
  return;
}
