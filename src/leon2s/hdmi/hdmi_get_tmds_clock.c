/* hdmi_get_tmds_clock  (FUN_a00911bc)
 *
 * Return the TMDS clock of an HDMI receiver, times 4 in 1/40 mode.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: derived - hdmi_phy_read_clock_count shifted by 2 when the PHY record ratio flag (+4) is set
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00911bc @ 0xa00911bc (-mcpu=v8 -Os -g)
 * Source form: the array is declared at 0xA807CC64 with the +4 in the index.
 */
/*
 * Read the clock count of HDMI receiver 'port' and, when the PHY record of that receiver has a non-zero
 * clock_ratio_mode (byte +4 of its 24-byte entry in hdmi_phy_records), shift it left by 2 before returning it.
 * Only bit 0 of 'port' is used.
 */
extern int hdmi_phy_read_clock_count();
extern unsigned char hdmi_phy_records[];

#define PHY_RECORD_SIZE 24             /* bytes per receiver entry of hdmi_phy_records */
#define PHY_CLOCK_RATIO_MODE 4         /* byte offset of clock_ratio_mode in the entry */

unsigned short hdmi_get_tmds_clock(unsigned int port)
{
    unsigned int clock;

    port = port & 1;
    clock = hdmi_phy_read_clock_count(port);
    if (hdmi_phy_records[port * PHY_RECORD_SIZE + PHY_CLOCK_RATIO_MODE] != 0) {
        clock = clock << 2;
    }
    return (unsigned short)clock;
}
