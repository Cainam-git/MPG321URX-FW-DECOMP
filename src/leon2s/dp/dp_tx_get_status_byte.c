/* dp_tx_get_status_byte  (FUN_a0088f84)
 *
 * Return a DP output status byte published to the main processor.
 * Name basis: descriptive - byte read by ipc_publish_port_status
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os. A leaf routine without a register window.
 */
extern unsigned char dp_tx_status_byte;

/*
 * Return dp_tx_status_byte. ipc_publish_port_status copies its bits 0 and 1 into bits 6 and 7 of the status
 * word it sends to the main processor.
 */
unsigned char dp_tx_get_status_byte(void)
{
  return dp_tx_status_byte;
}
