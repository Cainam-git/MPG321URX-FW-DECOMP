/* hdr_update_and_ack_tmds_port0  (FUN_a00914c4)
 *
 * Update HDR10+ data of HDMI receiver 0 and clear its packet status bit.
 * Name basis: derived - hdr_update_hdr10plus_tmds_port0 then reg 0x7C = 0x80; no direct caller (handler table)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00914c4 @ 0xa00914c4 (-mcpu=v8 -Os -g).
 * Source form: hdmi_reg_write8 is declared without a prototype.
 */
extern void hdr_update_hdr10plus_tmds_port0(void);
extern int hdmi_reg_write8();

/*
 * Run hdr_update_hdr10plus_tmds_port0, then write 0x80 to register 0x7C of HDMI 2.0 receiver 0.
 * No call instruction targets it; it is reached through a table of handlers.
 */
void hdr_update_and_ack_tmds_port0(void)

{
  hdr_update_hdr10plus_tmds_port0();
  hdmi_reg_write8(0,0x7c,0x80);
  return;
}
