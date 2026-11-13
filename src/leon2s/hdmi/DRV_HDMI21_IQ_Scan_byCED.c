/* DRV_HDMI21_IQ_Scan_byCED  (DRV_HDMI21_IQ_Scan_byCED)
 *
 * Scan the IQ setting per lane by character error counts and apply the middle of the good range.
 *   port: PHY
 * Name basis: proven - original name printed: 'DRV_HDMI21_IQ_Scan_byCED'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI21_IQ_Scan_byCED @ 0xa007fa0c-0xa007fde0, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - K&R definition with an unsigned char parameter (zero-extended at every use);
 *  - the error counts are one flat 128-entry array indexed ced[lane * 0x20 + k - 0x10] in every lane arm, and
 *    each arm has its own hdmi_phy_test_bit call (GCC cross-jumps them);
 *  - the first-good marks are cleared before the last-good marks.
 */
#define PHY_RX21_0 2                    /* PHY index of HDMI 2.1 receiver 0 (receiver 1 is 3) */
#define HDMI_MSG_HDMI21 0x800           /* debug flag bit 11: the "[HDMI21]" lines */

/* PHY registers holding the character error count (CED) of two lanes each: 0x2E64 lanes 0 and 1, 0x2E68 lanes 2
   and 3. The even lane uses bits 0..14 with the valid flag in bit 15, the odd lane bits 16..30 with bit 31. */
#define PHY_REG_CED_01      0x2e64
#define PHY_REG_CED_23      0x2e68
#define CED_VALID_BIT_EVEN  0xf
#define CED_VALID_BIT_ODD   0x1f
#define CED_COUNT_MAX       0x7fff      /* also stored for a lane whose count is not valid */

#define IQ_FIRST            0x10        /* first setting tried */
#define IQ_END              0x30        /* one past the last setting tried: 32 settings */
#define IQ_SETTINGS         0x20
#define ALL_LANES           0xff        /* lane argument of hdmi_rx21_write_lane_setting: all four lanes */
#define CED_GOOD_BELOW      100         /* a count below this makes the setting good */
#define FIRST_GOOD_FOUND    0x80        /* bit 7 of first_good: the first good setting has been recorded */
#define FIRST_GOOD_MASK     0x3f

struct Lane176 {
    unsigned char n;                    /* hdmi_rx21_lts_record.lane_count */
    unsigned char rest[0xaf];
};
extern struct Lane176 hdmi_rx21_lts_records[];
extern unsigned int dbg_hdmi_message_flags;
extern const char DAT_a0067868[];
extern void *lib_memset(void *, int, unsigned int);
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);
extern unsigned int hdmi_phy_test_bit(unsigned int, unsigned char, unsigned short);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern void hdmi_rx21_write_lane_setting(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern void hdmi_rx21_restart_lanes(unsigned char);
extern void hdmi_rx21_pulse_lane_bit4_all(unsigned char);

/*
 * Pick the IQ setting of each lane of an HDMI 2.1 receiver from the character error counts (CED).
 *
 *   port  PHY of the receiver: 2 or 3 (HDMI 2.1 receiver 0 or 1). Any other value returns at once.
 *
 * Every setting from 0x10 to 0x2F is written to all four lanes in turn (hdmi_rx21_write_lane_setting), the lanes
 * are restarted, and for each lane of the receiver (lane_count of its link training record) the CED count is
 * read if the lane's valid flag is set; a lane without the flag gets the count 0x7FFF and the line
 * "1ms CED[n] non valid". A count below 100 makes the setting good: the lane remembers the first good
 * setting (first_good, marked with bit 7 so it is taken only once) and the last good one (last_good).
 * The setting finally written to each lane is the middle of its good range, (last + first) / 2 + 0x10, and the
 * lanes are then pulsed (hdmi_rx21_pulse_lane_bit4_all). A lane with no good setting gets 0x10.
 *
 * Called from DRV_HDMI21_RXDetect_FSM_LTS_P (HDMI 2.1 link training, FRL rate 5 and 6). The "[HDMI21]" line with
 * the routine name is printed when debug flag bit 11 is set.
 */
void DRV_HDMI21_IQ_Scan_byCED(port)
    unsigned char port;
{
    unsigned char best[4] = {0, 0, 0, 0};       /* setting written at the end, per lane */
    unsigned short ced[128];                    /* error count of [lane][setting - 0x10] */
    unsigned char first_good[4];
    unsigned char last_good[4];
    unsigned char valid = 0;
    unsigned char rx;                           /* receiver 0 or 1 */
    unsigned char lane, setting;
    unsigned int reg;
    unsigned int valid_bit;

    lib_memset(ced, 0, 0x100);
    if (port == PHY_RX21_0)
        rx = 0;
    else if (port == PHY_RX21_0 + 1)
        rx = 1;
    else
        return;
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf(DAT_a0067868, "DRV_HDMI21_IQ_Scan_byCED");
    for (lane = 0; lane < hdmi_rx21_lts_records[rx].n; lane++) {
        first_good[lane] = 0;
        last_good[lane] = 0;
    }
    for (setting = IQ_FIRST; setting < IQ_END; setting++) {
        hdmi_rx21_write_lane_setting(port, ALL_LANES, setting, setting, setting, setting);
        hdmi_rx21_restart_lanes(port);
        for (lane = 0; lane < hdmi_rx21_lts_records[rx].n; lane++) {
            /* Is the count of this lane valid? Only lanes 0..3 are looked at; a higher number keeps the last result. */
            if (lane == 0) {
                reg = PHY_REG_CED_01;
                valid_bit = CED_VALID_BIT_EVEN;
                valid = hdmi_phy_test_bit(valid_bit, port, reg) != 0;
            } else if (lane == 1) {
                reg = PHY_REG_CED_01;
                valid_bit = CED_VALID_BIT_ODD;
                valid = hdmi_phy_test_bit(valid_bit, port, reg) != 0;
            } else if (lane == 2) {
                reg = PHY_REG_CED_23;
                valid_bit = CED_VALID_BIT_EVEN;
                valid = hdmi_phy_test_bit(valid_bit, port, reg) != 0;
            } else if (lane == 3) {
                reg = PHY_REG_CED_23;
                valid_bit = CED_VALID_BIT_ODD;
                valid = hdmi_phy_test_bit(valid_bit, port, reg) != 0;
            }
            if (valid) {
                if (lane == 0)
                    ced[lane * IQ_SETTINGS + setting - IQ_FIRST] = hdmi_phy_read_reg(port, PHY_REG_CED_01) & CED_COUNT_MAX;
                else if (lane == 1)
                    ced[lane * IQ_SETTINGS + setting - IQ_FIRST] = (hdmi_phy_read_reg(port, PHY_REG_CED_01) >> 16) & CED_COUNT_MAX;
                else if (lane == 2)
                    ced[lane * IQ_SETTINGS + setting - IQ_FIRST] = hdmi_phy_read_reg(port, PHY_REG_CED_23) & CED_COUNT_MAX;
                else if (lane == 3)
                    ced[lane * IQ_SETTINGS + setting - IQ_FIRST] = (hdmi_phy_read_reg(port, PHY_REG_CED_23) >> 16) & CED_COUNT_MAX;
                if (ced[lane * IQ_SETTINGS + setting - IQ_FIRST] < CED_GOOD_BELOW) {
                    if (!(first_good[lane] & FIRST_GOOD_FOUND))
                        first_good[lane] = (setting - IQ_FIRST) | FIRST_GOOD_FOUND;
                    last_good[lane] = setting - IQ_FIRST;
                }
            } else {
                ced[lane * IQ_SETTINGS + setting - IQ_FIRST] = CED_COUNT_MAX;
                dbg_printf("1ms CED[%d] non valid\n\n", lane);
            }
        }
    }
    /* The middle of the good range of each lane. */
    for (lane = 0; lane < hdmi_rx21_lts_records[rx].n; lane++)
        best[lane] = ((last_good[lane] + (first_good[lane] & FIRST_GOOD_MASK)) >> 1) + IQ_FIRST;
    dbg_printf("u8IQ_Best_Idx = ");
    for (lane = 0; lane < hdmi_rx21_lts_records[rx].n; lane++)
        dbg_printf(" CH%d = 0x%02X \r\n", lane, best[lane]);
    dbg_print_string("\n========IQ scan end======\n");
    hdmi_rx21_write_lane_setting(port, ALL_LANES, best[0], best[1], best[2], best[3]);
    hdmi_rx21_pulse_lane_bit4_all(port);
}
