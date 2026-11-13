/* hdmi_rx21_pulse_lane_bit4_masked  (FUN_a007f900)
 *
 * Pulse bit 4 of PHY register 0x060 of each lane in the mask (set, one long delay unit, clear).
 *   port: PHY
 *   mask: lanes
 * Name basis: descriptive - lane register table 0x2060, 0x2460, 0x2860, 0x3060; set, long delay unit, clear
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007f900 @ 0xa007f900, flags -mcpu=v8 -Os -g.
 * Source form: the externs are declared without prototypes and the routine returns the 64-bit join of its two
 * arguments, as the decompiler wrote it (the returned value is not used). Each of the two loops is written out.
 */
extern int hdmi_phy_write_bit();
extern int timer_delay_long_units();
extern unsigned short hdmi_rx21_lane_regs_0x060[];

#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))

/*
 * Pulse bit 4 of register 0x060 of the lanes in the mask: set the bit on every selected lane, wait one long delay
 * unit, then clear it on every selected lane. The register number of each lane comes from the table
 * hdmi_rx21_lane_regs_0x060 (0x2060, 0x2460, 0x2860, 0x3060).
 *   port: PHY index.  mask: lanes, bit 0..3 = lane 0..3.
 * Called by hdmi_rx21_pulse_lane_bit4_all and hdmi_rx21_load_lane_values_masked.
 */
int hdmi_rx21_pulse_lane_bit4_masked(unsigned int port, unsigned int mask)

{
  unsigned short lane;
  
  lane = 0;
  do {
    if (((int)(mask & 0xff) >> lane & 1U) != 0) {
      if (lane < 4) {
        hdmi_phy_write_bit(1, 4, port & 0xff, hdmi_rx21_lane_regs_0x060[(unsigned int)lane]);
      }
    }
    lane = lane + 1;
  } while (lane < 4);
  timer_delay_long_units(1);
  lane = 0;
  do {
    if (((int)(mask & 0xff) >> lane & 1U) != 0) {
      if (lane < 4) {
        hdmi_phy_write_bit(0, 4, port & 0xff, hdmi_rx21_lane_regs_0x060[(unsigned int)lane]);
      }
    }
    lane = lane + 1;
  } while (lane < 4);
  return CONCAT44(mask, port);
}
