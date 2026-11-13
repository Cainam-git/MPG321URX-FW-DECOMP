/* DRV_HDMI21_RXDetect_FSM_LTS_Chk_SCDC_Err  (DRV_HDMI21_RXDetect_FSM_LTS_Chk_SCDC_Err)
 *
 * Run the SCDC error check state of HDMI 2.1 link training.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: proven - original name in the state name table; prints 'FRL_Rate Change at LTS_SCDC_ERR', 'SCDC
 *   Compare bypass'
 *
 * Matching notes
 * --------------
 * DRV_HDMI21_RXDetect_FSM_LTS_Chk_SCDC_Err (leon2s 0xa0098e88-0xa0099560, 1752 bytes), flags -mcpu=v8 -Os -g
 * (section default).
 * The names u8BestRCIdx, u16BestSCDCErrCnt and u16SCDCErrCnt are the ones in the firmware's format string.
 * Source forms the exact build depends on:
 *  - the three loops over the lanes in the index choice test the inlined helper lane_in_range(lane) (the
 *    inlined call keeps the exit test at the loop bottom with the address arithmetic of the body in it);
 *  - the lane loop of the error count tests 'lane < 4 && retry';
 *  - the 3-lane and 4-lane blocks have the counting arm first (the 3-lane test written '!= 7', the 4-lane
 *    test '!= 0xf');
 *  - p is assigned from port again after the first rate-write test and at the top of each pass;
 *  - the register block pointer is volatile unsigned long (its alias set lets the state store move between
 *    the register read and write in the first branch);
 *  - the end is the two labels finish / to_stable with the err test first.
 */
#define HDMI_MSG_EQ_FLOW 0x02           /* debug flag bit 1: EN_HDMI_MSG_EQ_FLOW, the "[EQ]" lines */
#define HDMI_MSG_HDMI21  0x800          /* debug flag bit 11: the "[HDMI21]" lines (no name in the group list) */
#define CHIP_REV_82      0x82           /* sys_get_chip_revision: 0x80..0x84 */

/* PHY index of each HDMI 2.1 receiver (as hdmi_rx21_get_phy_index). */
#define PHY_RX21_0 2
#define PHY_RX21_1 3

/* Link-training states: index into hdmi_rx21_rx_detect_state_handlers (state routine names). */
enum rx_detect_state {
    RX_DETECT_INIT              = 0,    /* DRV_HDMI21_RXDetect_FSM_Init */
    RX_DETECT_LTS_1             = 1,
    RX_DETECT_LTS_2             = 2,
    RX_DETECT_LTS_3             = 3,
    RX_DETECT_LTS_CHK_ERR       = 4,
    RX_DETECT_LTS_4             = 5,
    RX_DETECT_LTS_P             = 6,
    RX_DETECT_LTS_L             = 7,
    RX_DETECT_LTS_CHK_SCDC_ERR  = 8,    /* this routine */
    RX_DETECT_LTS_CHK_STABLE    = 9
};
#define MODE_DETECT_WAIT_EQ_DONE 0      /* first mode-detect state (hdmi_rx21_mode_detect_state_handlers) */

/* Registers. */
#define B6_LTS_STATUS   0x90            /* block 6: bits 24..27 FRL rate ("FRL_Rate") */
#define B6_RATE_WRITE   0xb0            /* block 6: bits 8..15 set to 0xFF; another value is a rate write */
#define PHY_REG_2E60    0x2e60          /* PHY: bits 24..27 lane lock bits ("Lane lock fail") */
#define LANE_LOCK_3_LANES 0x7
#define LANE_LOCK_4_LANES 0xf

#define SCDC_LOCK_FAIL_LIMIT 3          /* failed lock checks in a row before the clock recovery reset */
#define RATE_CED_BYPASS      6          /* frl_rate_in_phy 6: "CED Compare bypass" */
#define RATE_SCDC_BYPASS     1          /* frl_rate_in_phy 1: "SCDC Compare bypass" */
#define PRE_AEQ_INDEXES      2          /* pre-AEQ R index 0 and 1 are compared */

/* Register block addresses of an HDMI 2.1 receiver (13 words, table at 0xA807DB00). */
struct hdmi_rx21_reg_blocks {
    unsigned char block0_5[0x18];
    volatile unsigned long *block6;     /* 0xCE009600 (+0x1000 for receiver 1) */
    unsigned char block7_12[0x34 - 0x1c];
};
/* The fields of the link training record (0xB0 bytes, table at 0xA807D680) used here. */
struct hdmi_rx21_lts_record {
    unsigned char lane_count;           /* +0: 0, 3 or 4 */
    unsigned char frl_rate;
    unsigned char frl_rate_in_phy;      /* +2: "u8FRL_Rate_SetInPhy" */
    unsigned char pad_0x3[0x1a - 3];
    unsigned short scdc_error_counts[4][2]; /* +0x1A: per lane and pre-AEQ R index, from DRV_HDMI21_RX_SCDC_Chk_Err */
    unsigned char lane_lock_fails;
    unsigned char scdc_lock_fails;      /* +0x2B */
    unsigned char pad_0x2c[0x30 - 0x2c];
    unsigned int last_state;            /* +0x30: rx-detect state seen at the last pass */
    unsigned char pad_0x34[0xb0 - 0x34];
};
/* Mode-detect record of an HDMI 2.1 receiver (0x18 bytes). */
struct mode_detect_record {
    unsigned int state;                 /* index into hdmi_rx21_mode_detect_state_handlers */
    unsigned char pad_0x4[0x18 - 4];
};

extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];
extern unsigned int hdmi_rx21_rx_detect_states[];
extern struct mode_detect_record hdmi_rx21_mode_detect_states[];
extern unsigned int dbg_hdmi_message_flags;
/* Per lane: index of the pre-AEQ R value (hdmi_rx21_initial_rct_values) and of the C value
   (hdmi_rx21_initial_cft_values) that DRV_HDMI21_Set_PHY_PreAEQ writes. */
extern unsigned char hdmi_rx21_pre_aeq_r_indexes[];
extern unsigned char hdmi_rx21_pre_aeq_c_indexes[];
extern const char DAT_a0067868[];               /* "[HDMI21]: =%s=" (bold) */

extern unsigned char sys_get_chip_revision(void);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);
extern void DRV_HDMI21_PHY_PICDR_Reset(unsigned char);
extern int DRV_HDMI21_RX_SCDC_Chk_Err(unsigned int);
extern void hdmi_rx21_reset_lane_setting(unsigned char);
extern void DRV_HDMI21_Set_PHY_PreAEQ(unsigned char, unsigned char);

static inline int lane_in_range(unsigned char lane)
{
    return lane < 4;
}

/*
 * Link-training state RX_DETECT_LTS_CHK_SCDC_ERR of an HDMI 2.1 receiver: check the lane lock and the SCDC
 * error counts, retry with the next pre-AEQ index while lanes report errors, and keep the index with fewer
 * errors for each lane.
 *
 *   port  HDMI 2.1 receiver 0/1 (any other value returns at once)
 *
 * Returns 0: hdmi_rx21_run_rx_detect_fsm moves on to the next receiver.
 *
 * Phases:
 *  1. On entry to the state: print the routine name and note the state.
 *  2. Rate written again (B6_RATE_WRITE not 0xFF, newer chips) or an FRL rate other than the one the PHY is
 *     set for: go back to RX_DETECT_LTS_3 (and mark B6_RATE_WRITE on newer chips).
 *  3. Clear the SCDC error counts of the lanes in use.
 *  4. Each pass:
 *     a. lane lock: all lanes in use must show their lock bit; a failure counts scdc_lock_fails, and the
 *        third failure in a row resets the clock recovery (DRV_HDMI21_PHY_PICDR_Reset) and returns with the
 *        state unchanged;
 *     b. read the SCDC errors (DRV_HDMI21_RX_SCDC_Chk_Err, a bit per bad lane, printed as "CED_ALL");
 *     c. FRL rate 6: no comparison ("CED Compare bypass"), go to the end;
 *     d. no bad lane: go to the end;
 *     e. step the R and C index of each bad lane, lane by lane; at the first lane whose index passes 1 leave
 *        the loop. Otherwise write the lane settings again with the new indexes
 *        (hdmi_rx21_reset_lane_setting, DRV_HDMI21_Set_PHY_PreAEQ) and do the next pass.
 *  5. After the loop: FRL rate 1 prints "SCDC Compare bypass". Otherwise each lane whose R index is not 0
 *     takes index 1 when it had fewer SCDC errors than index 0, else index 0 (R and C index the same); the
 *     counts are printed and the lane settings written again.
 *  6. End: go to RX_DETECT_LTS_CHK_STABLE and restart the mode detection, except after the FRL rate 6
 *     bypass with bad lanes in a pass that came after a retry, which returns with the state unchanged.
 */
int DRV_HDMI21_RXDetect_FSM_LTS_Chk_SCDC_Err(unsigned int port)
{
    unsigned char p = port;
    unsigned char retry = 0;
    unsigned char phy;
    unsigned char bad_lanes;
    unsigned char lane;
    unsigned char r_index;

    if (p == 0)
        phy = PHY_RX21_0;
    else if (p == 1)
        phy = PHY_RX21_1;
    else
        return 0;

    /* 1. Entry into the state. */
    if (hdmi_rx21_rx_detect_states[p] != hdmi_rx21_lts_records[p].last_state) {
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_printf(DAT_a0067868, "DRV_HDMI21_RXDetect_FSM_LTS_Chk_SCDC_Err");
        hdmi_rx21_lts_records[p].last_state = hdmi_rx21_rx_detect_states[p];
    }

    /* 2. The rate was written or changed: train again. */
    if (sys_get_chip_revision() > CHIP_REV_82 && ((ARR_a807db00[p].block6[B6_RATE_WRITE / 4] >> 8) & 0xff) != 0xff) {
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_print_string("[HDMI21]: FRL_Rate Change/Write detect at LTS_SCDC_ERR cut4\n");
        hdmi_rx21_rx_detect_states[p] = RX_DETECT_LTS_3;
        ARR_a807db00[p].block6[B6_RATE_WRITE / 4] = (ARR_a807db00[p].block6[B6_RATE_WRITE / 4] & 0xffff00ff) | 0xff00;
        return 0;
    }
    p = port;
    if (((ARR_a807db00[p].block6[B6_LTS_STATUS / 4] >> 24) & 0xf) != hdmi_rx21_lts_records[p].frl_rate_in_phy) {
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_print_string("[HDMI21]: \tFRL_Rate Change at LTS_SCDC_ERR");
        hdmi_rx21_rx_detect_states[p] = RX_DETECT_LTS_3;
        if (sys_get_chip_revision() > CHIP_REV_82)
            ARR_a807db00[p].block6[B6_RATE_WRITE / 4] = (ARR_a807db00[p].block6[B6_RATE_WRITE / 4] & 0xffff00ff) | 0xff00;
        return 0;
    }

    /* 3. */
    for (lane = 0; lane < hdmi_rx21_lts_records[p].lane_count; lane++) {
        hdmi_rx21_lts_records[p].scdc_error_counts[lane][0] = 0;
        hdmi_rx21_lts_records[p].scdc_error_counts[lane][1] = 0;
    }

    /* 4. Passes. */
    for (;;) {
        p = port;
        /* a. Lane lock. */
        if (hdmi_rx21_lts_records[p].lane_count == 3) {
            if (((hdmi_phy_read_reg(phy, PHY_REG_2E60) >> 24) & 0xf) != LANE_LOCK_3_LANES) {
                hdmi_rx21_lts_records[p].scdc_lock_fails++;
                if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                    dbg_printf("[HDMI21]: Chk SCDC-Lane lock fail at 3 lane mode %d times\n\n", hdmi_rx21_lts_records[p].scdc_lock_fails);
                if (hdmi_rx21_lts_records[p].scdc_lock_fails == SCDC_LOCK_FAIL_LIMIT) {
                    hdmi_rx21_lts_records[p].scdc_lock_fails = 0;
                    DRV_HDMI21_PHY_PICDR_Reset(phy);
                    return 0;
                }
            } else {
                hdmi_rx21_lts_records[p].scdc_lock_fails = 0;
            }
        } else if (hdmi_rx21_lts_records[p].lane_count == 4) {
            if (((hdmi_phy_read_reg(phy, PHY_REG_2E60) >> 24) & 0xf) != LANE_LOCK_4_LANES) {
                hdmi_rx21_lts_records[p].scdc_lock_fails++;
                if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                    dbg_printf("[HDMI21]: Chk SCDC-Lane lock fail at 4 lane mode %d times\n\n", hdmi_rx21_lts_records[p].scdc_lock_fails);
                if (hdmi_rx21_lts_records[p].scdc_lock_fails == SCDC_LOCK_FAIL_LIMIT) {
                    hdmi_rx21_lts_records[p].scdc_lock_fails = 0;
                    DRV_HDMI21_PHY_PICDR_Reset(phy);
                    return 0;
                }
            } else {
                hdmi_rx21_lts_records[p].scdc_lock_fails = 0;
            }
        }

        /* b..d. SCDC errors. */
        bad_lanes = DRV_HDMI21_RX_SCDC_Chk_Err(p);
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_printf("[HDMI21]: ---------CED_ALL = %d, IQ chk--------\n\n", bad_lanes);
        if (hdmi_rx21_lts_records[p].frl_rate_in_phy == RATE_CED_BYPASS) {
            if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                dbg_print_string("[HDMI21]:  \nCED Compare bypass !!!");
            goto finish;
        }
        if (bad_lanes == 0)
            goto finish;

        /* e. Next pre-AEQ index for the bad lanes, until one passes index 1. */
        retry = 1;
        for (lane = 0; lane < 4 && retry; lane++) {
            if ((bad_lanes >> lane) & 1) {
                hdmi_rx21_pre_aeq_r_indexes[lane]++;
                hdmi_rx21_pre_aeq_c_indexes[lane]++;
            }
            if (hdmi_rx21_pre_aeq_r_indexes[lane] > 1 || hdmi_rx21_pre_aeq_c_indexes[lane] > 1)
                retry = 0;
        }
        if (!retry)
            break;
        hdmi_rx21_reset_lane_setting(phy);
        DRV_HDMI21_Set_PHY_PreAEQ(phy, 1);
    }

    /* 5. Keep the index with fewer SCDC errors for each lane. */
    if (hdmi_rx21_lts_records[p].frl_rate_in_phy == RATE_SCDC_BYPASS) {
        if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
            dbg_print_string("[EQ]:  \nSCDC Compare bypass !!!");
    } else {
        unsigned char u8BestRCIdx[4] = { 0 };
        unsigned short u16BestSCDCErrCnt[4] = { 0 };
        unsigned short u16SCDCErrCnt[4] = { 0 };

        for (lane = 0; lane_in_range(lane); lane++) {
            u16BestSCDCErrCnt[lane] = hdmi_rx21_lts_records[p].scdc_error_counts[lane][0];
            u8BestRCIdx[lane] = 0;
        }
        for (lane = 0; lane_in_range(lane); lane++) {
            for (r_index = 1; r_index < PRE_AEQ_INDEXES; r_index++) {
                if (hdmi_rx21_pre_aeq_r_indexes[lane] == 0) {
                    if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
                        dbg_printf("[EQ]: Port%c, CH%d, PreAEQ_R_Idx = %d , bypass compare !!!\n", (char)(port + 'A'), lane, 0);
                } else {
                    u16SCDCErrCnt[lane] = hdmi_rx21_lts_records[port & 0xff].scdc_error_counts[lane][r_index];
                    if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
                        dbg_printf("[EQ]: Port%c, CH%d, u8RC_Idx = %d  u16SCDCErrCnt[%d] = %d  / u8BestRCIdx[%d] = %d  u16BestSCDCErrCnt[%d] = %d  \n", (char)(port + 'A'), lane, r_index, lane, u16SCDCErrCnt[lane], lane,
                                     u8BestRCIdx[lane], lane, u16BestSCDCErrCnt[lane]);
                    if (u16SCDCErrCnt[lane] < u16BestSCDCErrCnt[lane])
                        u8BestRCIdx[lane] = r_index;
                }
            }
            hdmi_rx21_pre_aeq_r_indexes[lane] = u8BestRCIdx[lane];
            hdmi_rx21_pre_aeq_c_indexes[lane] = u8BestRCIdx[lane];
        }
        for (lane = 0; lane_in_range(lane); lane++) {
            for (r_index = 0; r_index < PRE_AEQ_INDEXES; r_index++) {
                if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
                    dbg_printf("[EQ]: Port%c, CH%d, PreAEQ_R_Idx = %d , SCDCErrCnt[%d] = 0x%04x\n", (char)(port + 'A'), lane, hdmi_rx21_pre_aeq_r_indexes[lane], r_index,
                                 hdmi_rx21_lts_records[port & 0xff].scdc_error_counts[lane][r_index]);
            }
        }
        hdmi_rx21_reset_lane_setting(phy);
        DRV_HDMI21_Set_PHY_PreAEQ(phy, 1);
    }

    /* 6. On to the stable check. */
finish:
    if (bad_lanes == 0)
        goto to_stable;
    if (retry)
        return 0;
to_stable:
    hdmi_rx21_rx_detect_states[port & 0xff] = RX_DETECT_LTS_CHK_STABLE;
    hdmi_rx21_mode_detect_states[port & 0xff].state = MODE_DETECT_WAIT_EQ_DONE;
    return 0;
}
