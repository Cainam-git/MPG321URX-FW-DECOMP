/* hdmi_tx_apply_request_regs  (FUN_a0094594)
 *
 * Write the requested option bytes of an HDMI TX channel into its registers.
 *   port: HDMI TX port 0/1
 * Name basis: descriptive - bank 1 regs 2 and 0x0B from request bytes +0x10..+0x12; mailbox command 0x40
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0094594 @ 0xa0094594 (-mcpu=v8 -Os -g)
 * Source form: the port is masked to a byte in place; the two register values are computed before the writes.
 */

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

extern int hdmi_tx_reg_write8();
extern unsigned char hdmi_tx_requests[];    /* HDMI TX requests, 0x14 bytes per port (struct hdmi_tx_request) */

/*
 * Copy the option bytes of the port's request record (bytes +0x10..+0x12, filled by the TX commands) into the
 * transmitter: register 2 of bank 1 gets the high nibble of byte +0x10 and the low nibble of byte +0x11,
 * register 0x0B gets byte +0x12. Called by ipc_dispatch_command for mailbox command 0x40, right after it stored
 * the three bytes.
 */
void hdmi_tx_apply_request_regs(unsigned int port)

{
  unsigned char *request;
  unsigned int reg2_value;
  unsigned char reg0b_value;

  port = port & 0xff;
  request = hdmi_tx_requests + port * 0x14;
  reg2_value = (request[0x10] & 0xf0) | (request[0x11] & 0xf);
  reg0b_value = request[0x12];
  hdmi_tx_reg_write8(port,HDMI_TX_BANK_PHY,2,reg2_value);
  hdmi_tx_reg_write8(port,HDMI_TX_BANK_PHY,0xb,reg0b_value);
  return;
}
