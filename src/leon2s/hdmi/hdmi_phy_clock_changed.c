/* hdmi_phy_clock_changed  (FUN_a0074fc4)
 *
 * Return whether the measured clock differs from the saved one by more than 2.
 *   port: PHY
 * Returns: 1 when changed
 * Name basis: derived - saved halfword +0xA of the PHY table vs hdmi_phy_read_clock_count; caller
 *   hdmi_eq_check_clock
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0074fc4 @ 0xa0074fc4, flags -mcpu=v8 -Os -g.
 * Source form: abs() is the GCC built-in (sra/xor/sub); an if (d < 0) d = -d form swaps the xor operands.
 */
/* Entry of hdmi_phy_records: one per HDMI PHY (24 bytes). */
struct hdmi_phy_record {
    unsigned char bytes_0x0_to_0x9[0xa];
    unsigned short measured_clock;      /* +0xa: clock count saved earlier */
    unsigned char bytes_0xc_to_0x17[0xc];
};
extern struct hdmi_phy_record hdmi_phy_records[];
extern unsigned short hdmi_phy_read_clock_count(unsigned char);
extern int abs(int);

/* Returns 1 when the clock count measured now (hdmi_phy_read_clock_count) differs from the count saved
 * in the PHY's record by more than 2, otherwise 0.
 *   port: PHY index */
int hdmi_phy_clock_changed(unsigned char port)
{
    int d = hdmi_phy_records[port].measured_clock - hdmi_phy_read_clock_count(port);

    return abs(d) > 2;
}
