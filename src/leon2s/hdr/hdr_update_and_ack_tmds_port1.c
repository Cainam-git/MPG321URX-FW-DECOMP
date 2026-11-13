/* hdr_update_and_ack_tmds_port1  (FUN_a00914e0)
 *
 * Update HDR10+ data of HDMI receiver 1 and clear its packet status bit.
 * Name basis: derived - hdr_update_hdr10plus_tmds_port1 then reg 0x7C = 0x80; no direct caller (handler table)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00914e0 @ 0xa00914e0 (-mcpu=v8 -Os -g).
 * Source form: hdmi_reg_write8 is declared without a prototype.
 */
extern void hdr_update_hdr10plus_tmds_port1(void);
extern int hdmi_reg_write8();

/*
 * Run hdr_update_hdr10plus_tmds_port1, then write 0x80 to register 0x7C of HDMI 2.0 receiver 1.
 * Same as hdr_update_and_ack_tmds_port0 for the other receiver.
 */
void hdr_update_and_ack_tmds_port1(void)

{
  hdr_update_hdr10plus_tmds_port1();
  hdmi_reg_write8(1,0x7c,0x80);
  return;
}
