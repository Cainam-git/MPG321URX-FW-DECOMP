/* hdmi_rx21_write_reg1f0c_bit18  (FUN_a00a1df0)
 *
 * Set or clear bit 18 of PHY register 0x1F0C.
 *   clear: 1 = clear, 0 = set
 * Name basis: descriptive - caller DRV_HDMI_DbgMenu
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a1df0, flags -mcpu=v8 -Os -g (section default). The two callees are declared int-returning with
 * no parameters; the call arguments are not passed.
 */
extern int hdmi_rx21_clear_reg1f0c_bit18();
extern int hdmi_rx21_set_reg1f0c_bit18();

/*
 * Clear (`clear` != 0) or set (`clear` == 0) bit 18 of register 0x1F0C of PHY 0. Called by DRV_HDMI_DbgMenu.
 */
void hdmi_rx21_write_reg1f0c_bit18(unsigned char clear)
{
  if (clear != 0) {
    hdmi_rx21_clear_reg1f0c_bit18();
    return;
  }
  hdmi_rx21_set_reg1f0c_bit18();
  return;
}
