/* hdmi_rx21_write_all_port_enables  (FUN_a00a2c18)
 *
 * Set or clear the port enable bit of both HDMI 2.1 receivers.
 *   enable: 1 = enable
 * Name basis: derived - bit 0 of control register 8 as in hdmi_rx21_write_port_enable; caller
 *   _hdmi21_Initialize
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2c18 @ 0xa00a2c18, flags -mcpu=v8 -Os -g.
 * Source form: do/while over a counter held in an unsigned int and masked with 0xff; the row array is
 * declared as rows of 0x34 bytes.
 */
extern int reg_set_bit();
extern int reg_clear_bit();

extern unsigned char hdmi_rx21_reg_blocks[][0x34];      /* word 0 of a row = block 0 of the receiver */

/* Set (enable = 1) or clear (enable = 0) bit 0 of the word at offset 8 of register block 0 of both HDMI 2.1
   receivers; any other value changes nothing. Called by _hdmi21_Initialize with 1. Returns 0. */
int hdmi_rx21_write_all_port_enables(unsigned char enable)
{
  unsigned int i = 0;
  do {
    if (enable == 1) reg_set_bit(0, *(int *)hdmi_rx21_reg_blocks[i & 0xff] + 8);
    else if (enable == 0) reg_clear_bit(0, *(int *)hdmi_rx21_reg_blocks[i & 0xff] + 8);
    i++;
  } while ((i & 0xff) < 2);
  return 0;
}
