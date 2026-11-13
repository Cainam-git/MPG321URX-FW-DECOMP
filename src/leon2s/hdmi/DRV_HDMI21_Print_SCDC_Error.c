/* DRV_HDMI21_Print_SCDC_Error  (DRV_HDMI21_Print_SCDC_Error)
 *
 * Read and print the SCDC error counters of each HDMI 2.1 lane.
 *   port: PHY
 * Name basis: proven - original name printed: 'DRV_HDMI21_Print_SCDC_Error'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI21_Print_SCDC_Error @ 0xa00795a0-0xa0079778, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the hdmi_phy_write_bit calls take an unsigned char copy p of the port, the hdmi_phy_read_reg calls take
 *    'port & 0xff' (a separate AND per call: GCC does not see it as equal to the zero-extended copy);
 *  - the routine name is a static const char array, not a string literal in the call.
 */
#define PHY_RX21_0 2                    /* PHY index of HDMI 2.1 receiver 0 (receiver 1 is 3) */
#define HDMI_MSG_HDMI21 0x800           /* debug flag bit 11: the "[HDMI21]" lines */

#define PHY_REG_2E60        0x2e60      /* PHY register: bit 20 set, bit 16 pulsed before the counts are read */
#define PHY_REG_SCDC_ERR_01 0x2e64      /* low 15 bits of each half: SCDC error count of lane 0 / lane 1 */
#define PHY_REG_SCDC_ERR_23 0x2e68      /* same for lane 2 / lane 3 */
#define SCDC_ERR_COUNT_MASK 0x7fff

extern unsigned char hdmi_rx21_lts_records[][0xb0];      /* link training records; byte 0 = lane count */
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern void hdmi_phy_write_bit(int mode, unsigned int bit, unsigned char reg, unsigned short val);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern void timer_delay_units(unsigned int);
extern void timer_delay_long_units(unsigned int);
static const char fn_[] = "DRV_HDMI21_Print_SCDC_Error";

/*
 * Restart the SCDC error counters of an HDMI 2.1 receiver and read them back, one per lane, for the debug
 * log. Nothing is returned or stored: the counts only go into the "[HDMI21]" lines.
 *
 *   port  PHY of the receiver: 2 or 3 (HDMI 2.1 receiver 0 or 1). Any other value returns 0 at once.
 *
 * Bit 20 and bit 16 of PHY register 0x2E60 are set, bit 16 is cleared again after a short wait, and after a
 * longer wait the counts of PHY_REG_SCDC_ERR_01 / _23 are read, for as many lanes as the receiver's link
 * training record gives (lane_count). With debug flag bit 11 set each count is printed as
 * "Port<letter> , ch<lane>, H21 SCDC <count>".
 *
 * Called from DRV_HDMI21_ReStart_AEQ2 and DRV_HDMI21_Set_PHY_PreAEQ.
 */
int DRV_HDMI21_Print_SCDC_Error(unsigned int port)
{
    unsigned int err[4] = {0, 0, 0, 0};         /* raw register halves, one per lane */
    unsigned char p = port;
    unsigned char rx;                           /* receiver 0 or 1 */
    unsigned char lane;

    if (p == PHY_RX21_0)
        rx = 0;
    else if (p == PHY_RX21_0 + 1)
        rx = 1;
    else
        return 0;
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf("[HDMI21]: \x1b[1m=%s=\n\x1b[m", fn_);
    hdmi_phy_write_bit(1, 0x14, p, PHY_REG_2E60);
    hdmi_phy_write_bit(1, 0x10, p, PHY_REG_2E60);
    timer_delay_units(1);
    hdmi_phy_write_bit(0, 0x10, p, PHY_REG_2E60);
    timer_delay_long_units(1);
    for (lane = 0; lane < hdmi_rx21_lts_records[rx][0]; lane++) {
        if (lane == 0)
            err[0] = hdmi_phy_read_reg(port & 0xff, PHY_REG_SCDC_ERR_01) & 0xffff;
        else if (lane == 1)
            err[1] = hdmi_phy_read_reg(port & 0xff, PHY_REG_SCDC_ERR_01) >> 16;
        else if (lane == 2)
            err[2] = hdmi_phy_read_reg(port & 0xff, PHY_REG_SCDC_ERR_23) & 0xffff;
        else
            err[lane] = hdmi_phy_read_reg(port & 0xff, PHY_REG_SCDC_ERR_23) >> 16;
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_printf("[HDMI21]: # Port%c , ch%d, H21 SCDC %ld \n", (char)(port + 'A'), lane, err[lane] & SCDC_ERR_COUNT_MASK);
    }
    return 0;
}
