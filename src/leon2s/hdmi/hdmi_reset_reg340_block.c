/* hdmi_reset_reg340_block  (FUN_a008f4ec)
 *
 * Reset HDMI receiver registers 0x340..0x343 to their start values.
 *   port: HDMI 2.0 receiver 0 / 1, or 2 = both
 * Note: port: receiver 0 or 1, or 2 for both receivers (as hdmi_init_receivers calls it).
 * Name basis: descriptive - 0x341 = 0, 0x342 = 0x40, 0x343 = 0, 0x340 bits; callers receiver init and
 *   hdmi_tmds_run_link_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008f4ec @ 0xa008f4ec (-mcpu=v8 -Os -g)
 * Source form: the two calls on register 0x340 come last, in this order.
 */

#define RX_REG_340  0x340
#define RX_REG_341  0x341
#define RX_REG_342  0x342
#define RX_REG_343  0x343

extern void hdmi_reg_write8();
extern int hdmi_reg_update_bits();

/* Called with port 0 or 1 by the link state machine when a port goes to STANDBY, and with port 2 (both
   receivers) by hdmi_init_receivers. Registers 0x341, 0x342 and 0x343 get 0x00, 0x40 and 0x00. In register 0x340 bits 0..2 are set and then
   bits 1 and 2 are cleared again, so bit 0 stays set. What these registers control is not shown. */
void hdmi_reset_reg340_block(unsigned char port)
{
    hdmi_reg_write8(port, RX_REG_341, 0);
    hdmi_reg_write8(port, RX_REG_342, 0x40);
    hdmi_reg_write8(port, RX_REG_343, 0);
    hdmi_reg_update_bits(port, RX_REG_340, 7, 1);
    hdmi_reg_update_bits(port, RX_REG_340, 6, 0);
}
