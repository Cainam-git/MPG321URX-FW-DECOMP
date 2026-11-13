/* hdmi_read_vtotal  (FUN_a0090100)
 *
 * Return the total frame height of an HDMI receiver.
 *   port: HDMI 2.0 receiver 0/1
 * Returns: lines
 * Name basis: derived - reg 0x3C; stored as the VTOTAL field of the link timing record
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0090100 @ 0xa0090100 (-mcpu=v8 -Os -g)
 * Source form: the callee is declared without a prototype and returns int.
 */

#define RX_VTOTAL   0x3c

extern int hdmi_reg_read16_stable();

/* Reads the total number of lines from register 0x3C (read until two reads agree). hdmi_save_link_timing stores
   it in the record as vtotal. */
unsigned short hdmi_read_vtotal(unsigned int port)

{
  port = port & 0xff;
  return hdmi_reg_read16_stable(port,RX_VTOTAL);
}
