/* DRV_HDMI21_Set_PHY  (DRV_HDMI21_Set_PHY)
 *
 * Set up the HDMI 2.1 PHY for the trained link rate and search the lane EQ values.
 *   port: PHY
 * Name basis: proven - original name printed: 'DRV_HDMI21_Set_PHY'
 *
 * Matching notes
 * --------------
 * DRV_HDMI21_Set_PHY (leon2s 0xa0080494-0xa0083324, 11920 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - K&R definition with unsigned char parameters (the firmware masks %i0 / %i1 at each use);
 *  - every per-lane call has its own lane guard ('if (lane < 4)') and the lane register tables are const;
 *  - arms that the firmware shares only from a call onward are written out in full in each arm (also the 0x3140
 *    call after the 0x2140 / 0x2540 / 0x2940 arms, the 0x2020..0x3020 calls after the 0x360c / 0x3610 arms and
 *    the hdmi_rx21_setup_lanes_all / hdmi_rx21_set_lane_bit7_all calls of the optical and the last arm);
 *  - the two 0x21f4 writes are two if statements on the same rate test (the compiler threads the second test);
 *  - the lane loops before the search use the search's loop variable lane;
 *  - one byte variable, value, holds the 0x2068..0x3068 field value and later the RCT step;
 *  - cft_widen[lane] is assigned the && expression;
 *  - the rate 1 arm writes record bytes 0x15..0x18 through a block-scope pointer rec;
 *  - the independent stores of the rate arms are listed in the order that gives the firmware's store sequence;
 *  - the local arrays are declared in the order of their frame offsets (fp-16 .. fp-208);
 *  - the 0xffff initializer of best_errors is copied by GCC's implicit memcpy, declared with the link name
 *    lib_memcpy (lib_memcpy);
 *  - the link-training record is reached as a byte array (hdmi_rx21_lts_records[rx][byte]).
 */
#define HDMI_MSG_HDMI21 0x800           /* debug flag bit 11: the "[HDMI21]" lines (no name in the group list) */

/* PHY index of each HDMI 2.1 receiver (as hdmi_rx21_get_phy_index). */
#define PHY_RX21_0 2
#define PHY_RX21_1 3

/* Bytes of the link training record (0xB0 bytes per receiver, table at 0xA807D680). */
#define LTS_LANE_COUNT  0               /* 0, 3 or 4, set by hdmi_rx21_update_frl_rate */
#define LTS_BYTE_0x34   0x34            /* set to (frl_rate >= 4) by LTS_Chk_Err; 0 ends this routine after
                                           the read-back */

/* PHY registers. The four lanes have their own register pages 0x2000 / 0x2400 / 0x2800 / 0x3000; register
   0x178 of each lane (hdmi_rx21_lane_eq_regs: 0x2178 .. 0x3178) holds RCT in bits 0..3 and CFT in bits 8..23. */
#define PHY_REG_SCDC_ERR_01 0x2e64      /* low 15 bits of each half: lane 0 / lane 1 error count ("H21 SCDC") */
#define PHY_REG_SCDC_ERR_23 0x2e68      /* the same for lanes 2 / 3 */
#define PHY_REG_2E5C        0x2e5c      /* bit 23 set while the triangle search runs */

#define RCT_MASK        0xf
#define RCT_MAX         0xf             /* highest RCT value; the search ends each lane there */
#define CFT_OPTICAL_MAX 7               /* every lane at RCT_MAX with CFT up to this: "Run optical flow" */
#define SEARCH_ROWS     4               /* rows of the triangle search: row r tries CFT (1 << (2r + eq_step)) - 1 */
#define SEARCH_START_RCT 8              /* RCT written with every row; the lanes' own RCT is then read back */
#define ALL_LANES_MASK  0xf             /* lane bits 0..3 */

extern unsigned char hdmi_rx21_lts_records[][0xb0];
/* Per lane: index into hdmi_rx21_initial_rct_values (0xcc50) and hdmi_rx21_initial_cft_values (0xcc60) of
   the start values written here; DRV_HDMI21_RXDetect_FSM_LTS_Chk_SCDC_Err steps and keeps them. */
extern unsigned char hdmi_rx21_pre_aeq_r_indexes[4];
extern unsigned char hdmi_rx21_pre_aeq_c_indexes[4];
extern const unsigned int hdmi_rx21_initial_cft_values[];
extern unsigned int DAT_a00b3ae0;
extern const unsigned int hdmi_rx21_initial_rct_values[];
extern const unsigned short hdmi_rx21_lane_regs_0x17c[4], hdmi_rx21_lane_eq_regs[4], hdmi_rx21_lane_regs_0x328[4], hdmi_rx21_lane_regs_0x308[4];
extern const unsigned short hdmi_rx21_lane_regs_0x334[4], hdmi_rx21_lane_regs_0x314[4], hdmi_rx21_lane_regs_0x170[4];
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);
extern void hdmi_phy_clear_ctrl_bits(unsigned char);
extern void hdmi_phy_set_rate_fields(unsigned char);
extern void hdmi_phy_switch_channel_bit21(unsigned char, unsigned char, unsigned char);
extern void hdmi_rx21_clear_lane_bit7_masked(unsigned int, unsigned char);
extern void hdmi_rx21_clear_lane_bit7_all(unsigned char);
extern unsigned char hdmi_rx21_pick_eq_step(unsigned char, unsigned char, unsigned char);
extern unsigned short hdmi_rx21_score_lane(unsigned char, unsigned char, unsigned char, unsigned char);
extern void hdmi_rx21_setup_lanes_all(unsigned char);
extern void hdmi_rx21_set_lane_bit7_all(unsigned char);
extern void hdmi_rx21_reload_lane_regs(unsigned int, int);
extern void hdmi_rx21_apply_lane_eq(unsigned int, unsigned char, unsigned char *, unsigned short *);
extern void hdmi_rx21_reset_lane_setting(unsigned char);
extern void hdmi_phy_reset_all_lane_regs(unsigned char);
extern void hdmi_rx21_load_lane_values_masked(unsigned int, unsigned char, unsigned char *, unsigned short *);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern void hdmi_phy_update_reg(unsigned char, unsigned short, unsigned int, unsigned int);
extern void timer_delay_long_units(int);
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");
static const char routine_name[] = "DRV_HDMI21_Set_PHY";

/*
 * Set the PHY of an HDMI 2.1 receiver up for an FRL rate, then find the RCT / CFT values of its lanes.
 *
 *   phy       PHY index: PHY_RX21_0 or PHY_RX21_1 (any other value returns at once)
 *   frl_rate  FRL rate code 1..6 (bits 24..27 of block 6 word 0x90 of the receiver)
 *
 * Callers: DRV_HDMI21_RXDetect_FSM_LTS_Chk_Err, when the FRL rate in the status word differs from
 * frl_rate_in_phy (it passes the new frl_rate_in_phy, read from the same bits that
 * hdmi_rx21_update_frl_rate has just stored as frl_rate), and DRV_HDMI_EQDetect_Timer, when the record's
 * frl_rate differs from the value it saw last and is not 0 (it passes frl_rate).
 *
 * The lane loops of the search run over lane_count lanes, but the RCT step loop only ends when all four
 * lane bits are done, and the row set-up reads eq_step[0..3]. With these callers lane_count is 4 at rates 5
 * and 6 (hdmi_rx21_update_frl_rate: 3 for rates 1..2, 4 above). rct[] and cft[] get start values only for
 * rates 1..6; for any other rate the firmware writes whatever the stack holds.
 *
 * Phases:
 *  1. Choose the record of the receiver, print the rate, clear the PHY control bits, put the lane setting
 *     back to its default and reset the lane registers.
 *  2. PHY set-up, part 1: rate-dependent register writes, and the per-lane registers 0x314 / 0x308 / 0x334 /
 *     0x328 / 0x17C / 0x170 from the lane register tables (0x308 field 0 at rate 6, else 0xF0).
 *  3. Start RCT / CFT of every lane, written to the lane EQ registers:
 *       rates 2..4  entry 0 of hdmi_rx21_initial_rct_values / _cft_values (3 / 3); lane index bytes 0;
 *       rate 1      entry 1 (8 / 0xFF); lane index bytes 1, record bytes 0x15..0x18 = 1;
 *       rates 5, 6  RCT 8, CFT 0xF.
 *  4. PHY set-up, part 2: more rate-dependent register writes; the field of lane register 0x68 is 3 at
 *     rates 5 / 6, 5 at rate 4, else 0x13, and rates 4..6 switch bit 3 of lane register 0x70 on.
 *  5. Read the RCT / CFT the lanes in use settled on and print them ("1st_AEQ").
 *  6. Stop here when record byte 0x34 is 0 (LTS_Chk_Err sets it for frl_rate 4 and above).
 *  7. Every lane in use at RCT_MAX with CFT up to CFT_OPTICAL_MAX: "Run optical flow" - set the lanes up
 *     and set bit 7 on all lanes.
 *  8. Otherwise, at rates 5 and 6, "Run Triangle search flow" per lane (0x360C / 0x3610 get 0xBFD0 at rate 6,
 *     0x83D0 at rate 5; bit 23 of PHY_REG_2E5C is set for the time of the search):
 *     a. start with RCT 0xF / CFT 0xFF on all lanes, and choose eq_step per lane (hdmi_rx21_pick_eq_step);
 *     b. SEARCH_ROWS rows: row r writes CFT (1 << (2r + eq_step)) - 1 and RCT 8, restarts the lanes, then
 *        reads back the RCT each lane settled on and scores the lane (hdmi_rx21_score_lane);
 *     c. each row again with the read-back RCT; a lane whose RCT gives (1 << RCT) - 1 below the row's CFT
 *        gets RCT 2r + eq_step and is scored again. Its SCDC error count is read: among the rows without
 *        errors the lane keeps the one with the highest score, among the rows with errors the one with the
 *        fewest; later rows win ties;
 *     d. each lane takes the RCT / CFT of its best error-free row, or, when all four rows had errors, of the
 *        row with the fewest errors (best_score then 0);
 *     e. step the RCT up by 2 from there (to at most RCT_MAX) until every lane has reached RCT_MAX; a step
 *        replaces the best value when it is error-free with a score at least as high, or, while the lane has
 *        no error-free value, when it is error-free or has no more errors;
 *     f. one more CFT bit ((CFT + 1) * 2 - 1) for lanes whose CFT is not (1 << RCT) - 1 and is below
 *        (1 << (eq_step + 6)) - 1, kept by the same rules;
 *     g. write the best RCT / CFT of every lane.
 *  9. Any other rate: fixed values in 0x360C / 0x3610, set the lanes up and set bit 7 on all lanes.
 * 10. Print the final RCT / CFT of the four lanes ("Final register R/C").
 */
void DRV_HDMI21_Set_PHY(phy, frl_rate)
    unsigned char phy, frl_rate;
{
    unsigned short errors, error_rows;  /* error_rows: bit 4 * lane + row set when that row had errors */
    unsigned int bits;
    unsigned char rx, row, lane, rate_4_to_6, reg308_field, optical, retry_lanes, value, done_lanes;
    unsigned short lane_errors;
    unsigned char cft_widen[4] = {0};   /* 1: the lane tries one more CFT bit */
    unsigned char eq_step[4];
    unsigned char row_rct[4][4];        /* [row][lane] */
    unsigned char best_rct[4] = {0};
    unsigned char best_score_row[4] = {0};
    unsigned char best_error_row[4] = {0};
    unsigned short row_cft[4][4];
    unsigned short best_cft[4] = {0};
    unsigned short row_score[4][4];
    unsigned short best_score[4] = {0}; /* 0 while the lane has no error-free result */
    unsigned short score[4] = {0};
    unsigned short row_errors[4][4];
    unsigned short best_errors[4] = {0xffff, 0xffff, 0xffff, 0xffff};
    unsigned char rct[4];
    unsigned short cft[4];

    /* 1. Receiver, then reset. */
    error_rows = 0;
    lane_errors = 0;
    done_lanes = 0;
    if (phy == PHY_RX21_0)
        rx = 0;
    else if (phy == PHY_RX21_1)
        rx = 1;
    else
        return;
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf("[HDMI21]: \x1b[35;1mPort%c  %s u8FRL_Rate %d\n\x1b[m", (char)(phy + 0x41), routine_name, frl_rate);
    hdmi_phy_clear_ctrl_bits(phy);
    timer_delay_long_units(1);
    hdmi_rx21_reset_lane_setting(phy);
    hdmi_phy_reset_all_lane_regs(phy);

    /* 2. PHY set-up, part 1. */
    if ((unsigned char)(frl_rate - 1) < 3) {
        hdmi_phy_write_bit(1, 0x1b, phy, PHY_REG_2E5C);
        hdmi_phy_write_bit(1, 0x1b, phy, 0x2e38);
        hdmi_phy_update_reg(phy, 0x2e00, 0xfffffff0, 7);
        hdmi_phy_write_bit(0, 0x1d, phy, 0x3618);
        hdmi_phy_write_bit(1, 0x1c, phy, 0x3618);
        hdmi_phy_update_reg(phy, 0x3618, 0xf8ffffff, 0x3000000);
    } else {
        hdmi_phy_write_bit(0, 0x1b, phy, PHY_REG_2E5C);
        hdmi_phy_write_bit(0, 0x1b, phy, 0x2e38);
        hdmi_phy_update_reg(phy, 0x2e00, 0xfffffff0, 0xf);
        hdmi_phy_write_bit(1, 0x1d, phy, 0x3618);
        hdmi_phy_write_bit(1, 0x1c, phy, 0x3618);
        hdmi_phy_update_reg(phy, 0x3618, 0xf8ffffff, 0x4000000);
    }
    hdmi_phy_switch_channel_bit21(phy, 1, 1);
    hdmi_phy_write_bit(1, 0x14, phy, 0x2f08);
    hdmi_phy_write_bit(0, 0x14, phy, 0x2f08);
    hdmi_phy_update_reg(phy, 0x2000, 0xffffff00, 0xf9);
    if ((unsigned char)(frl_rate - 4) < 3) {
        hdmi_phy_write_bit(1, 4, phy, 0x3608);
        hdmi_phy_write_bit(1, 5, phy, 0x3608);
        hdmi_phy_write_bit(1, 0, phy, 0x1140);
    } else {
        hdmi_phy_write_bit(0, 4, phy, 0x3608);
        hdmi_phy_write_bit(0, 0, phy, 0x1140);
    }
    hdmi_phy_write_bit(1, 0x10, phy, 0x2c04);
    hdmi_phy_write_bit(1, 0x13, phy, 0x2c04);
    hdmi_phy_update_reg(phy, 0x2000, 0xff00ffff, 0x6e0000);
    hdmi_phy_write_bit(1, 8, phy, 0x3608);
    hdmi_phy_write_bit(1, 9, phy, 0x3608);
    if ((unsigned char)(frl_rate - 2) < 5)
        hdmi_phy_update_reg(phy, 0x3608, 0xff00ffff, 0xc0000);
    else
        hdmi_phy_update_reg(phy, 0x3608, 0xff00ffff, 0x50000);
    hdmi_phy_write_bit(1, 0x18, phy, 0x2f40);
    /* Per-lane registers from the lane register tables. */
    reg308_field = frl_rate == 6 ? 0 : 0xf0;
    for (lane = 0; lane < 4; lane++) {
        if (lane < 4)
            hdmi_phy_update_reg(phy, hdmi_rx21_lane_regs_0x314[lane], 0xffff00ff, 0x8800);
        if (lane < 4)
            hdmi_phy_update_reg(phy, hdmi_rx21_lane_regs_0x308[lane], 0xff00ffff, reg308_field << 16);
        if (lane < 4)
            hdmi_phy_update_reg(phy, hdmi_rx21_lane_regs_0x334[lane], 0xffff00ff, 0x8800);
        if (lane < 4)
            hdmi_phy_update_reg(phy, hdmi_rx21_lane_regs_0x328[lane], 0xff00ffff, 0x300000);
    }
    hdmi_phy_update_reg(phy, 0x201c, 0xffffff, 0x88000000);
    for (lane = 0; lane < 4; lane++) {
        if (lane < 4)
            hdmi_phy_update_reg(phy, hdmi_rx21_lane_regs_0x17c[lane], 0xff00ffff, 0xff0000);
        if (lane < 4)
            hdmi_phy_update_reg(phy, hdmi_rx21_lane_regs_0x17c[lane], 0xffffff00, 0xa0);
        if (lane < 4)
            hdmi_phy_write_bit(0, 0x10, phy, hdmi_rx21_lane_regs_0x170[lane]);
        if (lane < 4)
            hdmi_phy_write_bit(0, 0x11, phy, hdmi_rx21_lane_regs_0x170[lane]);
    }

    /* 3. Start RCT / CFT of the lanes; the index bytes record which table entry was used. */
    if ((unsigned char)(frl_rate - 2) < 3) {
        hdmi_rx21_pre_aeq_r_indexes[3] = 0;
        hdmi_rx21_pre_aeq_r_indexes[2] = 0;
        rct[0] = hdmi_rx21_initial_rct_values[0];
        hdmi_rx21_pre_aeq_r_indexes[1] = 0;
        hdmi_rx21_pre_aeq_r_indexes[0] = 0;
        rct[1] = hdmi_rx21_initial_rct_values[0];
        rct[2] = hdmi_rx21_initial_rct_values[0];
        rct[3] = hdmi_rx21_initial_rct_values[0];
        hdmi_rx21_pre_aeq_c_indexes[3] = 0;
        hdmi_rx21_pre_aeq_c_indexes[2] = 0;
        hdmi_rx21_pre_aeq_c_indexes[1] = 0;
        hdmi_rx21_pre_aeq_c_indexes[0] = 0;
        cft[0] = hdmi_rx21_initial_cft_values[0];
        cft[1] = hdmi_rx21_initial_cft_values[0];
        cft[2] = hdmi_rx21_initial_cft_values[0];
        cft[3] = hdmi_rx21_initial_cft_values[0];
    } else if (frl_rate == 1) {
        unsigned char *rec = hdmi_rx21_lts_records[rx];

        hdmi_rx21_pre_aeq_r_indexes[3] = 1;
        hdmi_rx21_pre_aeq_r_indexes[2] = 1;
        rec[0x18] = 1;
        rec[0x17] = 1;
        rec[0x16] = 1;
        rct[0] = hdmi_rx21_initial_rct_values[1];
        hdmi_rx21_pre_aeq_r_indexes[1] = 1;
        hdmi_rx21_pre_aeq_r_indexes[0] = 1;
        rec[0x15] = 1;
        rct[1] = hdmi_rx21_initial_rct_values[1];
        rct[2] = hdmi_rx21_initial_rct_values[1];
        rct[3] = hdmi_rx21_initial_rct_values[1];
        hdmi_rx21_pre_aeq_c_indexes[3] = 1;
        hdmi_rx21_pre_aeq_c_indexes[2] = 1;
        hdmi_rx21_pre_aeq_c_indexes[1] = 1;
        cft[0] = hdmi_rx21_initial_cft_values[1];
        cft[1] = hdmi_rx21_initial_cft_values[1];
        cft[2] = hdmi_rx21_initial_cft_values[1];
        cft[3] = hdmi_rx21_initial_cft_values[1];
        hdmi_rx21_pre_aeq_c_indexes[0] = 1;
    } else if ((unsigned char)(frl_rate - 5) < 2) {
        rct[0] = 8;
        rct[1] = 8;
        rct[2] = 8;
        rct[3] = 8;
        cft[0] = 0xf;
        cft[1] = 0xf;
        cft[2] = 0xf;
        cft[3] = 0xf;
    }
    for (lane = 0; lane < 4; lane++) {
        if (lane < 4)
            hdmi_phy_update_reg(phy, hdmi_rx21_lane_eq_regs[lane], 0xff0000f0, (rct[lane] & RCT_MASK) | (cft[lane] << 8));
    }

    /* 4. PHY set-up, part 2. */
    hdmi_phy_write_bit(1, 7, phy, 0x201c);
    hdmi_phy_write_bit(1, 7, phy, 0x241c);
    hdmi_phy_write_bit(1, 7, phy, 0x281c);
    hdmi_phy_write_bit(1, 7, phy, 0x301c);
    if ((unsigned char)(frl_rate - 4) < 3) {
        hdmi_phy_update_reg(phy, 0x201c, 0xfffffff9, 6);
        hdmi_phy_update_reg(phy, 0x241c, 0xfffffff9, 6);
        hdmi_phy_update_reg(phy, 0x281c, 0xfffffff9, 6);
        hdmi_phy_update_reg(phy, 0x301c, 0xfffffff9, 6);
    } else if (frl_rate == 1 || frl_rate == 3 || frl_rate == 2) {
        hdmi_phy_update_reg(phy, 0x201c, 0xfffffff9, 4);
        hdmi_phy_update_reg(phy, 0x241c, 0xfffffff9, 4);
        hdmi_phy_update_reg(phy, 0x281c, 0xfffffff9, 4);
        hdmi_phy_update_reg(phy, 0x301c, 0xfffffff9, 4);
    }
    if (frl_rate == 6) {
        hdmi_phy_update_reg(phy, 0x3614, 0xffffff00, 0x55);
        hdmi_phy_update_reg(phy, 0x3614, 0xffff00ff, 0x5500);
    } else {
        hdmi_phy_update_reg(phy, 0x3614, 0xffffff00, 0);
        hdmi_phy_update_reg(phy, 0x3614, 0xffff00ff, 0);
    }
    if ((unsigned char)(frl_rate - 2) < 5)
        hdmi_phy_update_reg(phy, 0x2f44, 0xffffffc0, 0x3f);
    else if (frl_rate == 1)
        hdmi_phy_update_reg(phy, 0x2f44, 0xffffffc0, 0x1f);
    if (frl_rate == 6) {
        hdmi_phy_update_reg(phy, 0x360c, 0xffff0000, 0x3fd0);
        hdmi_phy_update_reg(phy, 0x360c, 0xffff, 0x3fd00000);
        hdmi_phy_update_reg(phy, 0x3610, 0xffff0000, 0x3fd0);
        hdmi_phy_update_reg(phy, 0x3610, 0xffff, 0x3fd00000);
        hdmi_phy_update_reg(phy, 0x2020, 0xffcfffff, 0x300000);
        hdmi_phy_update_reg(phy, 0x2420, 0xffcfffff, 0x300000);
        hdmi_phy_update_reg(phy, 0x2820, 0xffcfffff, 0x300000);
        hdmi_phy_update_reg(phy, 0x3020, 0xffcfffff, 0x300000);
    } else {
        if ((unsigned char)(frl_rate - 4) < 2) {
            hdmi_phy_update_reg(phy, 0x360c, 0xffff0000, 0x3d0);
            hdmi_phy_update_reg(phy, 0x360c, 0xffff, 0x3d00000);
            hdmi_phy_update_reg(phy, 0x3610, 0xffff0000, 0x3d0);
            hdmi_phy_update_reg(phy, 0x3610, 0xffff, 0x3d00000);
            hdmi_phy_update_reg(phy, 0x2020, 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(phy, 0x2420, 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(phy, 0x2820, 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(phy, 0x3020, 0xffcfffff, 0x100000);
        } else {
            hdmi_phy_update_reg(phy, 0x360c, 0xffff0000, 0x83d0);
            hdmi_phy_update_reg(phy, 0x360c, 0xffff, 0x83d00000);
            hdmi_phy_update_reg(phy, 0x3610, 0xffff0000, 0x83d0);
            hdmi_phy_update_reg(phy, 0x3610, 0xffff, 0x83d00000);
            hdmi_phy_update_reg(phy, 0x2020, 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(phy, 0x2420, 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(phy, 0x2820, 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(phy, 0x3020, 0xffcfffff, 0x100000);
        }
    }
    hdmi_phy_update_reg(phy, 0x23c0, 0xffff00ff, 0x5000);
    hdmi_phy_update_reg(phy, 0x27c0, 0xffff00ff, 0x1000);
    hdmi_phy_update_reg(phy, 0x2bc0, 0xffff00ff, 0x1000);
    hdmi_phy_update_reg(phy, 0x33c0, 0xffff00ff, 0x1000);
    hdmi_phy_update_reg(phy, 0x3614, 0xff00ffff, 0x7c0000);
    hdmi_phy_update_reg(phy, 0x3614, 0xffffff, 0xff000000);
    hdmi_phy_update_reg(phy, 0x3618, 0xffffff00, 0xff);
    hdmi_phy_update_reg(phy, 0x3620, 0xffffff00, 0);
    hdmi_phy_update_reg(phy, 0x3620, 0xffff00ff, 0x100);
    hdmi_phy_update_reg(phy, 0x2020, 0xffffff, 0xa2000000);
    hdmi_phy_write_bit(1, 0x10, phy, 0x2004);
    hdmi_phy_write_bit(1, 0x10, phy, 0x2404);
    hdmi_phy_write_bit(1, 0x10, phy, 0x2804);
    hdmi_phy_write_bit(1, 0x10, phy, 0x3004);
    hdmi_phy_write_bit(1, 0, phy, 0x3600);
    hdmi_phy_write_bit(1, 1, phy, 0x3600);
    hdmi_phy_set_rate_fields(phy);
    hdmi_phy_write_bit(1, 0x10, phy, 0x361c);
    hdmi_phy_write_bit(1, 0x11, phy, 0x361c);
    hdmi_phy_write_bit(1, 0x12, phy, 0x361c);
    hdmi_phy_update_reg(phy, 0x361c, 0xff8fffff, 0x600000);
    if ((unsigned char)(frl_rate - 4) < 3) {
        hdmi_phy_update_reg(phy, 0x2028, 0xffffff, 0x31000000);
        hdmi_phy_update_reg(phy, 0x2008, 0xffffff, 0x3a000000);
    } else if ((unsigned char)(frl_rate - 1) < 3) {
        hdmi_phy_update_reg(phy, 0x2028, 0xffffff, 0x30000000);
        hdmi_phy_update_reg(phy, 0x2008, 0xffffff, 0x3b000000);
    }
    hdmi_phy_write_bit(1, 8, phy, 0x200c);
    if (frl_rate == 1)
        hdmi_phy_update_reg(phy, 0x200c, 0xfffff9ff, 0x400);
    else if ((unsigned char)(frl_rate - 2) < 2)
        hdmi_phy_update_reg(phy, 0x200c, 0xfffff9ff, 0x200);
    else
        hdmi_phy_update_reg(phy, 0x200c, 0xfffff9ff, 0);
    hdmi_phy_update_reg(phy, 0x2034, 0xff00ffff, 0xf00000);
    if (frl_rate == 1) {
        hdmi_phy_update_reg(phy, 0x2014, 0xff0fffff, 0x800000);
        hdmi_phy_update_reg(phy, 0x2414, 0xff0fffff, 0x800000);
        hdmi_phy_update_reg(phy, 0x2814, 0xff0fffff, 0x800000);
        hdmi_phy_update_reg(phy, 0x3014, 0xff0fffff, 0x800000);
    } else {
        hdmi_phy_update_reg(phy, 0x2014, 0xff0fffff, 0xf00000);
        hdmi_phy_update_reg(phy, 0x2414, 0xff0fffff, 0xf00000);
        hdmi_phy_update_reg(phy, 0x2814, 0xff0fffff, 0xf00000);
        hdmi_phy_update_reg(phy, 0x3014, 0xff0fffff, 0xf00000);
    }
    if ((unsigned char)(frl_rate - 2) < 5)
        hdmi_phy_write_bit(1, 8, phy, 0x3600);
    else
        hdmi_phy_write_bit(0, 8, phy, 0x3600);
    hdmi_phy_update_reg(phy, 0x3534, 0xffff00ff, 0xe000);
    if ((unsigned char)(frl_rate - 1) < 3) {
        hdmi_phy_write_bit(1, 0x11, phy, 0x2014);
        hdmi_phy_write_bit(1, 0x11, phy, 0x2414);
        hdmi_phy_write_bit(1, 0x11, phy, 0x2814);
        hdmi_phy_write_bit(1, 0x11, phy, 0x3014);
        hdmi_phy_update_reg(phy, 0x2018, 0xff9fffff, 0x200000);
        hdmi_phy_update_reg(phy, 0x2418, 0xff9fffff, 0x200000);
        hdmi_phy_update_reg(phy, 0x2818, 0xff9fffff, 0x200000);
        hdmi_phy_update_reg(phy, 0x3018, 0xff9fffff, 0x200000);
        hdmi_phy_update_reg(phy, 0x2018, 0xffff9fff, 0);
        hdmi_phy_update_reg(phy, 0x2418, 0xffff9fff, 0);
        hdmi_phy_update_reg(phy, 0x2818, 0xffff9fff, 0);
        hdmi_phy_update_reg(phy, 0x3018, 0xffff9fff, 0);
    } else {
        hdmi_phy_write_bit(0, 0x11, phy, 0x2014);
        hdmi_phy_write_bit(0, 0x11, phy, 0x2414);
        hdmi_phy_write_bit(0, 0x11, phy, 0x2814);
        hdmi_phy_write_bit(0, 0x11, phy, 0x3014);
        hdmi_phy_update_reg(phy, 0x2018, 0xff9fffff, 0x400000);
        hdmi_phy_update_reg(phy, 0x2418, 0xff9fffff, 0x400000);
        hdmi_phy_update_reg(phy, 0x2818, 0xff9fffff, 0x400000);
        hdmi_phy_update_reg(phy, 0x3018, 0xff9fffff, 0x400000);
        hdmi_phy_update_reg(phy, 0x2018, 0xffff9fff, 0x4000);
        hdmi_phy_update_reg(phy, 0x2418, 0xffff9fff, 0x4000);
        hdmi_phy_update_reg(phy, 0x2818, 0xffff9fff, 0x4000);
        hdmi_phy_update_reg(phy, 0x3018, 0xffff9fff, 0x4000);
    }
    hdmi_phy_update_reg(phy, 0x2154, 0xffffff, 0x2000000);
    hdmi_phy_write_bit(1, 0x15, phy, 0x2148);
    hdmi_phy_write_bit(1, 0x15, phy, 0x2548);
    hdmi_phy_write_bit(1, 0x15, phy, 0x2948);
    hdmi_phy_write_bit(1, 0x15, phy, 0x3148);
    hdmi_phy_update_reg(phy, 0x2104, 0xffffff00, 3);
    hdmi_phy_update_reg(phy, 0x2108, 0xffffff00, 5);
    hdmi_phy_update_reg(phy, 0x2108, 0xffff00ff, 0x100);
    hdmi_phy_update_reg(phy, 0x2504, 0xffffff00, 3);
    hdmi_phy_update_reg(phy, 0x2508, 0xffffff00, 5);
    hdmi_phy_update_reg(phy, 0x2508, 0xffff00ff, 0x100);
    hdmi_phy_update_reg(phy, 0x2904, 0xffffff00, 3);
    hdmi_phy_update_reg(phy, 0x2908, 0xffffff00, 5);
    hdmi_phy_update_reg(phy, 0x2908, 0xffff00ff, 0x100);
    hdmi_phy_update_reg(phy, 0x3104, 0xffffff00, 3);
    hdmi_phy_update_reg(phy, 0x3108, 0xffffff00, 5);
    hdmi_phy_update_reg(phy, 0x3108, 0xffff00ff, 0x100);
    hdmi_phy_update_reg(phy, 0x2154, 0xffffff00, 0xf0);
    hdmi_phy_update_reg(phy, 0x2154, 0xffffe0ff, 0);
    hdmi_phy_update_reg(phy, 0x214c, 0xffff00ff, 0x600);
    hdmi_phy_update_reg(phy, 0x2160, 0xfcffffff, 0x3000000);
    hdmi_phy_update_reg(phy, 0x2160, 0xf3ffffff, 0x8000000);
    hdmi_phy_write_bit(1, 0x1c, phy, 0x2160);
    hdmi_phy_write_bit(1, 0x1d, phy, 0x2160);
    hdmi_phy_write_bit(1, 0x1e, phy, 0x2160);
    hdmi_phy_write_bit(1, 0x12, phy, 0x215c);
    hdmi_phy_write_bit(0, 0x13, phy, 0x215c);
    hdmi_phy_write_bit(0, 0x14, phy, 0x215c);
    hdmi_phy_write_bit(0, 0x15, phy, 0x215c);
    hdmi_phy_write_bit(1, 0x16, phy, 0x215c);
    if (frl_rate > 3) {
        hdmi_phy_write_bit(1, 0, phy, 0x2140);
        hdmi_phy_write_bit(1, 0, phy, 0x2540);
        hdmi_phy_write_bit(1, 0, phy, 0x2940);
        hdmi_phy_write_bit(1, 0, phy, 0x3140);
    } else {
        hdmi_phy_write_bit(0, 0, phy, 0x2140);
        hdmi_phy_write_bit(1, 0, phy, 0x2540);
        hdmi_phy_write_bit(1, 0, phy, 0x2940);
        hdmi_phy_write_bit(1, 0, phy, 0x3140);
    }
    hdmi_phy_update_reg(phy, 0x21f0, 0xffffff00, 0x80);
    if (frl_rate == 1)
        hdmi_phy_update_reg(phy, 0x21f4, 0xffff0fff, 0x8000);
    else
        hdmi_phy_update_reg(phy, 0x21f4, 0xffff0fff, 0xf000);
    if (frl_rate == 1)
        hdmi_phy_update_reg(phy, 0x21f4, 0xfffffc00, 0x96);
    else if ((unsigned char)(frl_rate - 2) < 2)
        hdmi_phy_update_reg(phy, 0x21f4, 0xfffffc00, 300);
    else if (frl_rate == 4)
        hdmi_phy_update_reg(phy, 0x21f4, 0xfffffc00, 400);
    else if (frl_rate == 5)
        hdmi_phy_update_reg(phy, 0x21f4, 0xfffffc00, 500);
    else if (frl_rate == 6)
        hdmi_phy_update_reg(phy, 0x21f4, 0xfffffc00, 600);
    hdmi_phy_write_bit(0, 0x1b, phy, 0x3604);
    hdmi_phy_update_reg(phy, 0x2f44, 0xffff00ff, 0x7100);
    hdmi_phy_update_reg(phy, 0x2f44, 0xff00ffff, 0x710000);
    hdmi_phy_update_reg(phy, 0x2f44, 0xffffff, 0x71000000);
    hdmi_phy_update_reg(phy, 0x2f48, 0xffffff00, 0x71);
    /* The field of lane register 0x68 written below, and the rate group 4..6. */
    rate_4_to_6 = 0;
    if ((unsigned char)(frl_rate - 5) < 2) {
        rate_4_to_6 = 1;
        value = 3;
    } else {
        value = 0x13;
        if (frl_rate == 4) {
            rate_4_to_6 = 1;
            value = 5;
        }
    }
    hdmi_phy_update_reg(phy, 0x2060, 0xffcfffff, 0);
    hdmi_phy_update_reg(phy, 0x2460, 0xffcfffff, 0);
    hdmi_phy_update_reg(phy, 0x2860, 0xffcfffff, 0);
    hdmi_phy_update_reg(phy, 0x3060, 0xffcfffff, 0);
    hdmi_phy_update_reg(phy, 0x2060, 0xff3fffff, 0x800000);
    hdmi_phy_update_reg(phy, 0x2460, 0xff3fffff, 0x800000);
    hdmi_phy_update_reg(phy, 0x2860, 0xff3fffff, 0x800000);
    hdmi_phy_update_reg(phy, 0x3060, 0xff3fffff, 0x800000);
    if (frl_rate == 1) {
        hdmi_phy_write_bit(0, 0x13, phy, 0x2c34);
        hdmi_phy_write_bit(1, 0x19, phy, 0x2c34);
        hdmi_phy_write_bit(0, 0x10, phy, 0x2c34);
        hdmi_phy_write_bit(0, 0x11, phy, 0x2c34);
        hdmi_phy_write_bit(0, 0x12, phy, 0x2c34);
        hdmi_phy_update_reg(phy, 0x2c30, 0xfff0ffff, 0xb0000);
        hdmi_phy_update_reg(phy, 0x2c30, 0xff0fffff, 0x400000);
        hdmi_phy_update_reg(phy, 0x2c30, 0xf0ffffff, 0xd000000);
        hdmi_phy_update_reg(phy, 0x2c30, 0xfffffff, 0x20000000);
        hdmi_phy_write_bit(0, 0, phy, 0x2c30);
        hdmi_phy_update_reg(phy, 0x2c34, 0xff1fffff, 0xc00000);
        hdmi_phy_update_reg(phy, 0x2c38, 0xfffff1ff, 0);
        hdmi_phy_update_reg(phy, 0x2c34, 0xfffff3ff, 0);
        hdmi_phy_write_bit(0, 0x14, phy, 0x2c34);
        hdmi_phy_update_reg(phy, 0x2c24, 0xfcffffff, 0);
        hdmi_phy_write_bit(0, 5, phy, 0x2c20);
        hdmi_phy_write_bit(0, 4, phy, 0x2c20);
    } else if ((unsigned char)(frl_rate - 2) < 2) {
        hdmi_phy_write_bit(0, 0x13, phy, 0x2c34);
        hdmi_phy_write_bit(1, 0x19, phy, 0x2c34);
        hdmi_phy_write_bit(0, 0x10, phy, 0x2c34);
        hdmi_phy_write_bit(0, 0x11, phy, 0x2c34);
        hdmi_phy_write_bit(0, 0x12, phy, 0x2c34);
        hdmi_phy_update_reg(phy, 0x2c30, 0xfff0ffff, 0xb0000);
        hdmi_phy_update_reg(phy, 0x2c30, 0xff0fffff, 0x400000);
        hdmi_phy_update_reg(phy, 0x2c30, 0xf0ffffff, 0xd000000);
        hdmi_phy_update_reg(phy, 0x2c30, 0xfffffff, 0x20000000);
        hdmi_phy_write_bit(0, 0, phy, 0x2c30);
        hdmi_phy_update_reg(phy, 0x2c34, 0xff1fffff, 0xc00000);
        hdmi_phy_update_reg(phy, 0x2c38, 0xfffff1ff, 0);
        hdmi_phy_update_reg(phy, 0x2c34, 0xfffff3ff, 0);
        hdmi_phy_write_bit(0, 0x14, phy, 0x2c34);
        hdmi_phy_update_reg(phy, 0x2c24, 0xfcffffff, 0);
        hdmi_phy_write_bit(0, 5, phy, 0x2c20);
        hdmi_phy_write_bit(0, 4, phy, 0x2c20);
    } else if (frl_rate == 4) {
        hdmi_phy_write_bit(1, 0x13, phy, 0x2c34);
        hdmi_phy_write_bit(0, 0x19, phy, 0x2c34);
        hdmi_phy_write_bit(1, 0x10, phy, 0x2c34);
        hdmi_phy_write_bit(0, 0x11, phy, 0x2c34);
        hdmi_phy_write_bit(1, 0x12, phy, 0x2c34);
        hdmi_phy_update_reg(phy, 0x2c30, 0xfff0ffff, 0xa0000);
        hdmi_phy_update_reg(phy, 0x2c30, 0xff0fffff, 0x300000);
        hdmi_phy_update_reg(phy, 0x2c30, 0xf0ffffff, 0xc000000);
        hdmi_phy_update_reg(phy, 0x2c30, 0xfffffff, 0x10000000);
        hdmi_phy_write_bit(1, 0, phy, 0x2c30);
        hdmi_phy_update_reg(phy, 0x2c34, 0xff1fffff, 0x800000);
        hdmi_phy_update_reg(phy, 0x2c38, 0xfffff1ff, 0x600);
        hdmi_phy_update_reg(phy, 0x2c34, 0xfffff3ff, 0xc00);
        hdmi_phy_write_bit(1, 0x14, phy, 0x2c34);
        hdmi_phy_update_reg(phy, 0x2c24, 0xfcffffff, 0x3000000);
        hdmi_phy_write_bit(1, 5, phy, 0x2c20);
        hdmi_phy_write_bit(0, 4, phy, 0x2c20);
        timer_delay_long_units(1);
        hdmi_phy_write_bit(1, 4, phy, 0x2c20);
    } else if (frl_rate == 5) {
        hdmi_phy_write_bit(1, 0x13, phy, 0x2c34);
        hdmi_phy_write_bit(0, 0x19, phy, 0x2c34);
        hdmi_phy_write_bit(1, 0x10, phy, 0x2c34);
        hdmi_phy_write_bit(1, 0x11, phy, 0x2c34);
        hdmi_phy_write_bit(0, 0x12, phy, 0x2c34);
        hdmi_phy_update_reg(phy, 0x2c30, 0xfff0ffff, 0xa0000);
        hdmi_phy_update_reg(phy, 0x2c30, 0xff0fffff, 0x300000);
        hdmi_phy_update_reg(phy, 0x2c30, 0xf0ffffff, 0xc000000);
        hdmi_phy_update_reg(phy, 0x2c30, 0xfffffff, 0x10000000);
        hdmi_phy_write_bit(1, 0, phy, 0x2c30);
        hdmi_phy_update_reg(phy, 0x2c34, 0xff1fffff, 0x800000);
        hdmi_phy_update_reg(phy, 0x2c38, 0xfffff1ff, 0x600);
        hdmi_phy_update_reg(phy, 0x2c34, 0xfffff3ff, 0xc00);
        hdmi_phy_write_bit(1, 0x14, phy, 0x2c34);
        hdmi_phy_update_reg(phy, 0x2c24, 0xfcffffff, 0x3000000);
        hdmi_phy_write_bit(1, 5, phy, 0x2c20);
        hdmi_phy_write_bit(0, 4, phy, 0x2c20);
        timer_delay_long_units(1);
        hdmi_phy_write_bit(1, 4, phy, 0x2c20);
    } else if (frl_rate == 6) {
        hdmi_phy_write_bit(1, 0x13, phy, 0x2c34);
        hdmi_phy_write_bit(0, 0x19, phy, 0x2c34);
        hdmi_phy_write_bit(1, 0x10, phy, 0x2c34);
        hdmi_phy_write_bit(1, 0x11, phy, 0x2c34);
        hdmi_phy_write_bit(0, 0x12, phy, 0x2c34);
        hdmi_phy_update_reg(phy, 0x2c30, 0xfff0ffff, 0xa0000);
        hdmi_phy_update_reg(phy, 0x2c30, 0xff0fffff, 0x300000);
        hdmi_phy_update_reg(phy, 0x2c30, 0xf0ffffff, 0xc000000);
        hdmi_phy_update_reg(phy, 0x2c30, 0xfffffff, 0x10000000);
        hdmi_phy_write_bit(1, 0, phy, 0x2c30);
        hdmi_phy_update_reg(phy, 0x2c34, 0xff1fffff, 0x800000);
        hdmi_phy_update_reg(phy, 0x2c38, 0xfffff1ff, 0x600);
        hdmi_phy_update_reg(phy, 0x2c34, 0xfffff3ff, 0xc00);
        hdmi_phy_write_bit(1, 0x14, phy, 0x2c34);
        hdmi_phy_update_reg(phy, 0x2c24, 0xfcffffff, 0x3000000);
        hdmi_phy_write_bit(1, 5, phy, 0x2c20);
        hdmi_phy_write_bit(0, 4, phy, 0x2c20);
        timer_delay_long_units(1);
        hdmi_phy_write_bit(1, 4, phy, 0x2c20);
    }
    hdmi_phy_update_reg(phy, 0x2068, 0xff00ffff, value << 16);
    hdmi_phy_update_reg(phy, 0x2468, 0xff00ffff, value << 16);
    hdmi_phy_update_reg(phy, 0x2868, 0xff00ffff, value << 16);
    hdmi_phy_update_reg(phy, 0x3068, 0xff00ffff, value << 16);
    hdmi_rx21_reset_lane_setting(phy);
    if (rate_4_to_6) {
        hdmi_phy_write_bit(1, 3, phy, 0x2070);
        hdmi_phy_write_bit(1, 3, phy, 0x2470);
        hdmi_phy_write_bit(1, 3, phy, 0x2870);
        hdmi_phy_write_bit(1, 3, phy, 0x3070);
        hdmi_phy_update_reg(phy, 0x2028, 0xff00ffff, 0x20000);
        hdmi_phy_update_reg(phy, 0x2428, 0xff00ffff, 0x20000);
        hdmi_phy_update_reg(phy, 0x2828, 0xff00ffff, 0x20000);
        hdmi_phy_update_reg(phy, 0x3028, 0xff00ffff, 0x20000);
        hdmi_phy_update_reg(phy, 0x2008, 0xff00ffff, 0x120000);
        hdmi_phy_update_reg(phy, 0x2408, 0xff00ffff, 0x120000);
        hdmi_phy_update_reg(phy, 0x2808, 0xff00ffff, 0x120000);
        hdmi_phy_update_reg(phy, 0x3008, 0xff00ffff, 0x120000);
        hdmi_phy_write_bit(1, 0x11, phy, 0x2008);
        hdmi_phy_write_bit(1, 0x11, phy, 0x2408);
        hdmi_phy_write_bit(1, 0x11, phy, 0x2808);
        hdmi_phy_write_bit(1, 0x11, phy, 0x3008);
        hdmi_phy_write_bit(1, 0x18, phy, 0x2028);
        hdmi_phy_write_bit(0, 0x18, phy, 0x2008);
    } else if (frl_rate == 6) {
        /* Never reached: rate 6 sets rate_4_to_6. */
        hdmi_phy_update_reg(phy, 0x2028, 0xff00ffff, 0x20000);
        hdmi_phy_update_reg(phy, 0x2428, 0xff00ffff, 0x20000);
        hdmi_phy_update_reg(phy, 0x2828, 0xff00ffff, 0x20000);
        hdmi_phy_update_reg(phy, 0x3028, 0xff00ffff, 0x20000);
        hdmi_phy_update_reg(phy, 0x2008, 0xff00ffff, 0x120000);
        hdmi_phy_update_reg(phy, 0x2408, 0xff00ffff, 0x120000);
        hdmi_phy_update_reg(phy, 0x2808, 0xff00ffff, 0x120000);
        hdmi_phy_update_reg(phy, 0x3008, 0xff00ffff, 0x120000);
        hdmi_phy_write_bit(1, 3, phy, 0x2070);
        hdmi_phy_write_bit(1, 3, phy, 0x2470);
        hdmi_phy_write_bit(1, 3, phy, 0x2870);
        hdmi_phy_write_bit(1, 3, phy, 0x3070);
    } else {
        hdmi_phy_update_reg(phy, 0x2028, 0xff00ffff, 0);
        hdmi_phy_update_reg(phy, 0x2428, 0xff00ffff, 0);
        hdmi_phy_update_reg(phy, 0x2828, 0xff00ffff, 0);
        hdmi_phy_update_reg(phy, 0x3028, 0xff00ffff, 0);
        hdmi_phy_update_reg(phy, 0x2008, 0xff00ffff, 0x100000);
        hdmi_phy_update_reg(phy, 0x2408, 0xff00ffff, 0x100000);
        hdmi_phy_update_reg(phy, 0x2808, 0xff00ffff, 0x100000);
        hdmi_phy_update_reg(phy, 0x3008, 0xff00ffff, 0x100000);
        hdmi_phy_write_bit(0, 3, phy, 0x2070);
        hdmi_phy_write_bit(0, 3, phy, 0x2470);
        hdmi_phy_write_bit(0, 3, phy, 0x2870);
        hdmi_phy_write_bit(0, 3, phy, 0x3070);
        hdmi_phy_write_bit(0, 0x18, phy, 0x2028);
        hdmi_phy_write_bit(0, 0x11, phy, 0x2028);
        hdmi_phy_write_bit(0, 0x11, phy, 0x2428);
        hdmi_phy_write_bit(0, 0x11, phy, 0x2828);
        hdmi_phy_write_bit(0, 0x11, phy, 0x3028);
    }
    hdmi_phy_update_reg(phy, 0x2c00, 0xffffff00, 0);
    if ((unsigned char)(frl_rate - 1) < 2) {
        hdmi_phy_write_bit(1, 0x1b, phy, PHY_REG_2E5C);
        hdmi_phy_write_bit(1, 0x1b, phy, 0x2e38);
        hdmi_phy_update_reg(phy, 0x2e00, 0xfffffff0, 7);
        hdmi_phy_write_bit(1, 0x17, phy, 0x2e04);
    } else {
        hdmi_phy_write_bit(0, 0x1b, phy, PHY_REG_2E5C);
        hdmi_phy_write_bit(0, 0x1b, phy, 0x2e38);
        hdmi_phy_update_reg(phy, 0x2e00, 0xfffffff0, 0xf);
        hdmi_phy_write_bit(0, 0x17, phy, 0x2e04);
    }
    timer_delay_long_units(10);
    hdmi_phy_switch_channel_bit21(phy, 0, 1);
    timer_delay_long_units(1);

    /* 5. What the lanes settled on. */
    for (lane = 0; lane < hdmi_rx21_lts_records[rx][LTS_LANE_COUNT]; lane++) {
        if (lane < 4)
            rct[lane] = hdmi_phy_read_reg(phy, hdmi_rx21_lane_eq_regs[lane]) & RCT_MASK;
        if (lane < 4)
            cft[lane] = (hdmi_phy_read_reg(phy, hdmi_rx21_lane_eq_regs[lane]) & 0xffff00) >> 8;
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_printf("[HDMI21]:     1st_AEQ CH%d RCT=0x%02X, CFT=0x%04X\n", lane, rct[lane], cft[lane]);
    }

    /* 6. */
    if (hdmi_rx21_lts_records[rx][LTS_BYTE_0x34] == 0)
        return;

    /* 7. "Optical" when every lane in use is at RCT_MAX with a small CFT. */
    optical = 1;
    for (lane = 0; lane < hdmi_rx21_lts_records[rx][LTS_LANE_COUNT]; lane++)
        if (rct[lane] != RCT_MAX || cft[lane] > CFT_OPTICAL_MAX)
            optical = 0;
    if (optical) {
        dbg_print_string("Run optical flow");
        hdmi_rx21_setup_lanes_all(phy);
        hdmi_rx21_set_lane_bit7_all(phy);
    } else if ((unsigned char)(frl_rate - 5) < 2) {
        /* 8. Triangle search. */
        if (frl_rate == 6) {
            hdmi_phy_update_reg(phy, 0x360c, 0xffff0000, 0xbfd0);
            hdmi_phy_update_reg(phy, 0x360c, 0xffff, 0xbfd00000);
            hdmi_phy_update_reg(phy, 0x3610, 0xffff0000, 0xbfd0);
            hdmi_phy_update_reg(phy, 0x3610, 0xffff, 0xbfd00000);
        } else {
            hdmi_phy_update_reg(phy, 0x360c, 0xffff0000, 0x83d0);
            hdmi_phy_update_reg(phy, 0x360c, 0xffff, 0x83d00000);
            hdmi_phy_update_reg(phy, 0x3610, 0xffff0000, 0x83d0);
            hdmi_phy_update_reg(phy, 0x3610, 0xffff, 0x83d00000);
        }
        dbg_print_string("Run Triangle search flow\n");
        hdmi_phy_write_bit(1, 0x17, phy, PHY_REG_2E5C);

        /* 8a. Start values and the step of each lane. */
        rct[0] = 0xf;
        cft[0] = 0xff;
        rct[1] = 0xf;
        cft[1] = 0xff;
        rct[2] = 0xf;
        cft[2] = 0xff;
        rct[3] = 0xf;
        cft[3] = 0xff;
        hdmi_rx21_clear_lane_bit7_masked(phy, ALL_LANES_MASK);
        hdmi_rx21_apply_lane_eq(phy, ALL_LANES_MASK, rct, cft);
        for (lane = 0; lane < hdmi_rx21_lts_records[rx][LTS_LANE_COUNT]; lane++)
            eq_step[lane] = hdmi_rx21_pick_eq_step(phy, lane, frl_rate);

        /* 8b. One pass per row: load the row's values, restart the lanes, read back RCT and score. */
        for (row = 0; row < SEARCH_ROWS; row++) {
            row_cft[row][0] = (1 << (row * 2 + eq_step[0])) - 1;
            row_rct[row][0] = SEARCH_START_RCT;
            row_cft[row][1] = (1 << (row * 2 + eq_step[1])) - 1;
            row_cft[row][2] = (1 << (row * 2 + eq_step[2])) - 1;
            row_rct[row][1] = SEARCH_START_RCT;
            row_rct[row][2] = SEARCH_START_RCT;
            row_rct[row][3] = SEARCH_START_RCT;
            row_cft[row][3] = (1 << (row * 2 + eq_step[3])) - 1;
            hdmi_rx21_reload_lane_regs(phy, ALL_LANES_MASK);
            hdmi_rx21_load_lane_values_masked(phy, ALL_LANES_MASK, row_rct[row], row_cft[row]);
            timer_delay_long_units(1);
            hdmi_rx21_setup_lanes_all(phy);
            hdmi_rx21_set_lane_bit7_all(phy);
            timer_delay_long_units(1);
            hdmi_rx21_clear_lane_bit7_all(phy);
            for (lane = 0; lane < hdmi_rx21_lts_records[rx][LTS_LANE_COUNT]; lane++) {
                if (lane < 4)
                    row_rct[row][lane] = hdmi_phy_read_reg(phy, hdmi_rx21_lane_eq_regs[lane]) & RCT_MASK;
                row_score[row][lane] = hdmi_rx21_score_lane(phy, lane, frl_rate, eq_step[lane]);
            }
        }

        /* 8c. Apply each row again; count its errors and keep the best row per lane. */
        for (row = 0; row < SEARCH_ROWS; row++) {
            retry_lanes = 0;
            for (lane = 0; lane < hdmi_rx21_lts_records[rx][LTS_LANE_COUNT]; lane++) {
                /* The read-back RCT is too low for the row's CFT: use 2 * row + eq_step and score again. */
                if ((1 << row_rct[row][lane]) - 1 < row_cft[row][lane]) {
                    retry_lanes |= 1 << lane;
                    row_rct[row][lane] = row * 2 + eq_step[lane];
                }
            }
            hdmi_rx21_apply_lane_eq(phy, ALL_LANES_MASK, row_rct[row], row_cft[row]);
            for (lane = 0; lane < hdmi_rx21_lts_records[rx][LTS_LANE_COUNT]; lane++) {
                if ((retry_lanes >> lane) & 1)
                    row_score[row][lane] = hdmi_rx21_score_lane(phy, lane, frl_rate, eq_step[lane]);
                if (lane == 0)
                    row_errors[row][lane] = hdmi_phy_read_reg(phy, PHY_REG_SCDC_ERR_01) & 0x7fff;
                else if (lane == 1)
                    row_errors[row][lane] = (hdmi_phy_read_reg(phy, PHY_REG_SCDC_ERR_01) & 0x7fffffff) >> 16;
                else if (lane == 2)
                    row_errors[row][lane] = hdmi_phy_read_reg(phy, PHY_REG_SCDC_ERR_23) & 0x7fff;
                else if (lane == 3)
                    row_errors[row][lane] = (hdmi_phy_read_reg(phy, PHY_REG_SCDC_ERR_23) & 0x7fffffff) >> 16;
                errors = row_errors[row][lane];
                bits = error_rows;
                if (errors != 0)
                    bits |= (1 << row) << (lane << 2);
                error_rows = bits;
                /* No errors: the highest score wins; with errors: the fewest errors win. */
                if ((error_rows & ((1 << row) << (lane << 2))) == 0) {
                    if (row_score[row][lane] >= best_score[lane]) {
                        best_score[lane] = row_score[row][lane];
                        best_score_row[lane] = row;
                    }
                } else if (errors <= best_errors[lane]) {
                    best_errors[lane] = errors;
                    best_error_row[lane] = row;
                }
            }
        }
        /* 8d. Best row of each lane; best_score 0 marks a lane whose rows all had errors. */
        for (lane = 0; lane < hdmi_rx21_lts_records[rx][LTS_LANE_COUNT]; lane++) {
            if (((error_rows >> (lane << 2)) & 0xf) == 0xf) {
                best_rct[lane] = row_rct[best_error_row[lane]][lane];
                best_cft[lane] = row_cft[best_error_row[lane]][lane];
                best_score[lane] = 0;
            } else {
                best_score[lane] = row_score[best_score_row[lane]][lane];
                best_rct[lane] = row_rct[best_score_row[lane]][lane];
                best_cft[lane] = row_cft[best_score_row[lane]][lane];
            }
        }
        /* 8e. Step RCT up by 2 from the best row's value; a lane at RCT_MAX is done. */
        for (lane = 0; lane < hdmi_rx21_lts_records[rx][LTS_LANE_COUNT]; lane++) {
            if (best_rct[lane] == RCT_MAX) {
                rct[lane] = RCT_MAX;
                done_lanes |= 1 << lane;
            } else if (best_rct[lane] == RCT_MAX - 1) {
                rct[lane] = RCT_MAX;
            } else {
                rct[lane] = best_rct[lane] + 2;
            }
        }
        while (done_lanes != ALL_LANES_MASK) {
            hdmi_rx21_apply_lane_eq(phy, ~done_lanes & ALL_LANES_MASK, rct, best_cft);
            for (lane = 0; lane < hdmi_rx21_lts_records[rx][LTS_LANE_COUNT]; lane++) {
                if ((~done_lanes >> lane) & 1) {
                    score[lane] = hdmi_rx21_score_lane(phy, lane, frl_rate, eq_step[lane]);
                    if (lane == 0)
                        lane_errors = hdmi_phy_read_reg(phy, PHY_REG_SCDC_ERR_01) & 0x7fff;
                    else if (lane == 1)
                        lane_errors = (hdmi_phy_read_reg(phy, PHY_REG_SCDC_ERR_01) & 0x7fffffff) >> 16;
                    else if (lane == 2)
                        lane_errors = hdmi_phy_read_reg(phy, PHY_REG_SCDC_ERR_23) & 0x7fff;
                    else if (lane == 3)
                        lane_errors = (hdmi_phy_read_reg(phy, PHY_REG_SCDC_ERR_23) & 0x7fffffff) >> 16;
                    /* Without an error-free value yet, take an error-free step or one with no more errors;
                       afterwards only error-free steps with a score at least as high. */
                    if (best_score[lane] == 0) {
                        if (lane_errors == 0) {
                            best_score[lane] = score[lane];
                            best_rct[lane] = rct[lane];
                        } else if (lane_errors <= best_errors[lane]) {
                            best_errors[lane] = lane_errors;
                            best_rct[lane] = rct[lane];
                            best_score[lane] = 0;
                        }
                    } else if (lane_errors == 0 && score[lane] >= best_score[lane]) {
                        best_score[lane] = score[lane];
                        best_rct[lane] = rct[lane];
                    }
                }
                /* The step at RCT_MAX was the last one; the next value is capped at RCT_MAX. */
                if (rct[lane] > 14)
                    done_lanes |= 1 << lane;
                value = rct[lane] + 2;
                rct[lane] = value;
                if (value == 16)
                    rct[lane] = 15;
            }
        }

        /* 8f. One more CFT bit, kept by the same rules. */
        for (lane = 0; lane < hdmi_rx21_lts_records[rx][LTS_LANE_COUNT]; lane++) {
            cft_widen[lane] = best_cft[lane] != (1 << best_rct[lane]) - 1 && best_cft[lane] < (1 << (eq_step[lane] + 6)) - 1;
            cft[lane] = ((best_cft[lane] + 1) << cft_widen[lane]) - 1;
        }
        hdmi_rx21_apply_lane_eq(phy, ALL_LANES_MASK, best_rct, cft);
        for (lane = 0; lane < hdmi_rx21_lts_records[rx][LTS_LANE_COUNT]; lane++) {
            if (cft_widen[lane]) {
                score[lane] = hdmi_rx21_score_lane(phy, lane, frl_rate, eq_step[lane]);
                if (lane == 0)
                    lane_errors = hdmi_phy_read_reg(phy, PHY_REG_SCDC_ERR_01) & 0x7fff;
                else if (lane == 1)
                    lane_errors = (hdmi_phy_read_reg(phy, PHY_REG_SCDC_ERR_01) & 0x7fffffff) >> 16;
                else if (lane == 2)
                    lane_errors = hdmi_phy_read_reg(phy, PHY_REG_SCDC_ERR_23) & 0x7fff;
                else if (lane == 3)
                    lane_errors = (hdmi_phy_read_reg(phy, PHY_REG_SCDC_ERR_23) & 0x7fffffff) >> 16;
                if (best_score[lane] == 0) {
                    if (lane_errors == 0) {
                        best_score[lane] = score[lane];
                        best_cft[lane] = cft[lane];
                    } else if (lane_errors <= best_errors[lane]) {
                        best_score[lane] = 0;
                        best_cft[lane] = cft[lane];
                        best_errors[lane] = lane_errors;
                    }
                } else if (lane_errors == 0 && score[lane] >= best_score[lane]) {
                    best_score[lane] = score[lane];
                    best_cft[lane] = cft[lane];
                }
            }
        }
        /* 8g. The result. */
        hdmi_rx21_apply_lane_eq(phy, ALL_LANES_MASK, best_rct, best_cft);
        hdmi_phy_write_bit(0, 0x17, phy, PHY_REG_2E5C);
    } else {
        /* 9. Other rates. */
        hdmi_phy_update_reg(phy, 0x360c, 0xffff0000, 0x83d0);
        hdmi_phy_update_reg(phy, 0x360c, 0xffff, 0x83d00000);
        hdmi_phy_update_reg(phy, 0x3610, 0xffff0000, 0x83d0);
        hdmi_phy_update_reg(phy, 0x3610, 0xffff, 0x83d00000);
        hdmi_rx21_setup_lanes_all(phy);
        hdmi_rx21_set_lane_bit7_all(phy);
    }

    /* 10. Lane EQ registers 0x178 of the four lanes. */
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_print_string("[HDMI21]: Final register R/C:\n");
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf("[HDMI21]:  CH0 0x%lX, 0x%04lX\n", hdmi_phy_read_reg(phy, 0x2178) & 0xf, (hdmi_phy_read_reg(phy, 0x2178) & 0xffff00) >> 8);
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf("[HDMI21]:  CH1 0x%lX, 0x%04lX\n", hdmi_phy_read_reg(phy, 0x2578) & 0xf, (hdmi_phy_read_reg(phy, 0x2578) & 0xffff00) >> 8);
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf("[HDMI21]:  CH2 0x%lX, 0x%04lX\n", hdmi_phy_read_reg(phy, 0x2978) & 0xf, (hdmi_phy_read_reg(phy, 0x2978) & 0xffff00) >> 8);
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf("[HDMI21]:  CH3 0x%lX, 0x%04lX\n", hdmi_phy_read_reg(phy, 0x3178) & 0xf, (hdmi_phy_read_reg(phy, 0x3178) & 0xffff00) >> 8);
}
