/* hdmi_phy_load_aeq_entry  (FUN_a0074ef4)
 *
 * Write one equaliser table entry to the register of one channel of a PHY.
 *   port: PHY
 *   idx: table entry
 * Name basis: derived - rct/cft fields of the AEQ table entry to the per-channel registers; callers EQ scan
 *   FSM steps
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0074ef4 @ 0xa0074ef4, flags -mcpu=v8 -Os -g.
 * Same form as the matching block of DRV_HDMI_EQScan_FSM_PHY_PreAEQ: rct and cft are read into locals
 * before the 'ch < 3' test, rct first.
 */
/* Entry of the equaliser table hdmi_eq_aeq_entries (4 bytes). */
struct AeqEnt { unsigned char rct; unsigned char byte_1; unsigned short cft; };
extern const struct AeqEnt hdmi_eq_aeq_entries[];
extern const unsigned short hdmi_phy_channel_eq_regs[];
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);

/* Writes one table entry into the register of channel ch (table hdmi_phy_channel_eq_regs): the low
 * 4 bits of the entry's rct go to bits 0..3, bits 4..7 are kept, cft goes to bits 8..23, and the top
 * byte is kept. Does nothing for ch of 3 or more.
 *   port: PHY page
 *   ch:   channel 0..2
 *   idx:  index into the entry table hdmi_eq_aeq_entries */
void hdmi_phy_load_aeq_entry(unsigned char port, unsigned char ch, unsigned char idx)
{
    unsigned short cft;
    unsigned char rct;

    rct = hdmi_eq_aeq_entries[idx].rct;
    cft = hdmi_eq_aeq_entries[idx].cft;
    if (ch < 3)
        hdmi_phy_update_reg(port, hdmi_phy_channel_eq_regs[ch], 0xff0000f0, (rct & 0xf) | (cft << 8));
}
