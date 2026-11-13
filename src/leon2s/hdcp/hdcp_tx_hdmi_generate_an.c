/* hdcp_tx_hdmi_generate_an  (FUN_a00c85e4)
 *
 * Let the engine produce the session's random value and read its eight bytes.
 * Name basis: derived - bit 3 of register 0x0F, then registers 0x15..0x1C (An)
 *
 * Matching notes
 * --------------
 * FUN_a00c85e4 (leon2s 0xa00c85e4-0xa00c8688, 164 bytes, 41 words), flags -mcpu=v8 -Os -g.
 * Source form: the second read-modify-write of register 0x0F is in the firmware as well; the loop counter starts
 * at 0 after it ('clr %l0'). No return value.
 */
extern unsigned char hdmi_tx_reg_read8();
extern void hdmi_tx_reg_write8();

#define AN_LENGTH 8                             /* bytes read back */
#define AN_FIRST_REG 0x15                       /* registers 0x15..0x1C */

/*
 * Read the 8 bytes in registers 0x15..0x1C of HDMI output `port` into an. With read_only == 0 bit 3 of
 * register 0x0F is first set (the read-modify-write is done twice); with any other value the bytes are only
 * read.
 *
 * Called with read_only 0 from hdcp_tx_hdmi_state_run_checks and with 1 from
 * hdcp_tx_hdmi_state_read_repeater_info. hdcp_tx_hdmi_clear_an_request clears bit 3 again.
 */
void hdcp_tx_hdmi_generate_an(unsigned int port, unsigned char *an, unsigned char read_only)
{
  unsigned char i;
  unsigned char value;

  if (read_only == 0) {
    value = hdmi_tx_reg_read8(port & 0xff, 0, 0xf);
    hdmi_tx_reg_write8(port & 0xff, 0, 0xf, (unsigned char)(value | 8));
    value = hdmi_tx_reg_read8(port & 0xff, 0, 0xf);
    hdmi_tx_reg_write8(port & 0xff, 0, 0xf, (unsigned char)(value | 8));
  }
  i = 0;
  do {
    an[i] = hdmi_tx_reg_read8(port & 0xff, 0, (unsigned short)(i + AN_FIRST_REG));
    i = i + 1;
  } while (i < AN_LENGTH);
}
