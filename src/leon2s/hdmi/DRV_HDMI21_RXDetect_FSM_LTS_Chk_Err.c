/* DRV_HDMI21_RXDetect_FSM_LTS_Chk_Err  (DRV_HDMI21_RXDetect_FSM_LTS_Chk_Err)
 *
 * Check FRL rate and lane errors during link training and handle FLT updates.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: proven - original name printed (fn_ text); 'FRL_Rate Error, enter error handle', 'LTS_ChkE <W
 *   FLT updated>'; state 4
 *
 * Matching notes
 * --------------
 * DRV_HDMI21_RXDetect_FSM_LTS_Chk_Err (leon2s 0xa009ec38-0xa009f5c8, 2448 bytes), flags -mcpu=v8 -Os -g -msoft-float.
 * Source forms the exact build depends on:
 *  - as DRV_HDMI21_RXDetect_FSM_LTS_3: -msoft-float, the clear_lane_requests helper taking the raw port, and
 *    the record and register accesses through [port & 0xff] after the first tests;
 *  - the tests whose short arm comes first in the firmware are written that way round (FLT_UPDATE clear,
 *    rate field == 0, rate >= 7);
 *  - RX_DETECT_LTS_L is written in both zero-rate arms; the rate is (word & 0xf000000) >> 24 in the later
 *    tests;
 *  - hdmi_rx21_set_frl_clock_wrapper is called without a prototype (the unsigned int port & 0xff is passed as
 *    is; the callee masks its unsigned char parameters itself).
 */
#define HDMI_MSG_HDMI21 0x800           /* debug flag bit 11: the "[HDMI21]" lines (no name in the group list) */
#define CHIP_REV_82     0x82            /* sys_get_chip_revision: 0x80..0x84 */

/* PHY index of each HDMI 2.1 receiver (as hdmi_rx21_get_phy_index). */
#define PHY_RX21_0 2
#define PHY_RX21_1 3

/* Link-training states: index into hdmi_rx21_rx_detect_state_handlers (state routine names). */
enum rx_detect_state {
    RX_DETECT_INIT              = 0,    /* DRV_HDMI21_RXDetect_FSM_Init */
    RX_DETECT_LTS_1             = 1,
    RX_DETECT_LTS_2             = 2,
    RX_DETECT_LTS_3             = 3,
    RX_DETECT_LTS_CHK_ERR       = 4,    /* this routine */
    RX_DETECT_LTS_4             = 5,
    RX_DETECT_LTS_P             = 6,
    RX_DETECT_LTS_L             = 7,
    RX_DETECT_LTS_CHK_SCDC_ERR  = 8,
    RX_DETECT_LTS_CHK_STABLE    = 9
};

/* Registers of receiver register block 6 (byte offsets). */
#define B6_LTS_CONTROL  0x80            /* bit 5 FLT_UPDATE */
#define FLT_UPDATE_BIT  5               /* set by the training states, waited on: "LTS_ChkE <W FLT updated>" */
#define B6_LTS_STATUS   0x90            /* bits 24..27 FRL rate ("FRL_Rate"), bit 17 NO_RETRAIN_BIT */
#define NO_RETRAIN_BIT  0x11            /* set: the wait timeout prints "no_retrain" */
#define B6_LANE_REQ_01  0xa0            /* lane request fields: lane 0 bits 24..27, lane 1 bits 28..31 */
#define B6_LANE_REQ_23  0xa4            /* lane 2 bits 0..3, lane 3 bits 4..7 */
#define B6_RATE_WRITE   0xb0            /* bits 8..15: set to 0xFF; another value is reported as a rate write */

#define FRL_RATE_ABOVE_12G   7          /* rates from 7 up: "FRL_Rate > 12G, request for lower FRL rate" */
#define LANE_REQ_LOWER_RATE  0xf        /* request field value written with that message */
#define LANE_REQ_TXFFE_STEP  0xe        /* written for a failing lane together with its TxFFE step */
#define CHK_ERR_WAIT_PASSES  300        /* passes with FLT_UPDATE still set before the timeout message */

/* Register block addresses of an HDMI 2.1 receiver (13 words, table at 0xA807DB00). */
struct hdmi_rx21_reg_blocks {
    volatile unsigned int *block0;      /* 0xCE009000 (+0x1000 for receiver 1) */
    unsigned char block1_5[0x18 - 4];
    volatile unsigned int *block6;      /* 0xCE009600 */
    unsigned char block7_12[0x34 - 0x1c];
};
/* The fields of the link training record (0xB0 bytes, table at 0xA807D680) used here. */
struct hdmi_rx21_lts_record {
    unsigned char lane_count;           /* +0: 0, 3 or 4 */
    unsigned char frl_rate;             /* +1: FRL rate taken over by hdmi_rx21_update_frl_rate */
    unsigned char frl_rate_in_phy;      /* +2: "u8FRL_Rate_SetInPhy" */
    unsigned char pad_0x3[0xc];
    unsigned char txffe[4];             /* +0xF: TxFFE level of each lane ("TxFFE[%d]") */
    unsigned char txffe_max;            /* +0x13: "TxFFE_Max_L" */
    unsigned char pad_0x14[0x2b - 0x14];
    unsigned char scdc_lock_fails;      /* +0x2B: counted by the SCDC error check */
    unsigned char pad_0x2c[4];
    unsigned int last_state;            /* +0x30: rx-detect state seen at the last pass */
    unsigned char byte_0x34;
    unsigned char pad_0x35[0xb0 - 0x35];
};

extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];
extern unsigned int hdmi_rx21_rx_detect_states[];
extern unsigned char hdmi_rx21_frl_rate_change_flags[];
extern unsigned short hdmi_rx21_lts_error_halves[];
extern unsigned char hdmi_rx21_ltp_force_pass;
extern unsigned int hdmi_rx21_ltp_end_ticks[];
extern unsigned int hdmi_rx21_ltp_timer_ticks[];
extern unsigned int dbg_hdmi_message_flags;
extern const char DAT_a0067868[];               /* "[HDMI21]: =%s=" (bold) */

extern unsigned char sys_get_chip_revision(void);
extern void reg_set_bit(unsigned int, volatile unsigned int *);
extern unsigned int reg_test_bit(unsigned int, volatile unsigned int *);
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);
extern void hdmi_rx21_update_frl_rate(unsigned int);
extern void hdmi_rx21_set_frl_clock_wrapper();
extern void timer_delay_long_units(unsigned short);
extern void DRV_HDMI21_Set_PHY(unsigned char, unsigned char);
extern unsigned char hdmi_rx21_check_sr_detect(unsigned char);
extern unsigned int timer_get_ticks(void);

/* Clear the request field of each of the four lanes. */
static inline void clear_lane_requests(unsigned int port)
{
    unsigned char lane;

    for (lane = 0; lane < 4; lane++) {
        if (lane == 0)
            ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_01 / 4] &= 0xf0ffffff;
        else if (lane == 1)
            ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_01 / 4] &= 0x0fffffff;
        else if (lane == 2)
            ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_23 / 4] &= ~0xf;
        else if (lane == 3)
            ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_23 / 4] &= ~0xf0;
    }
}

/*
 * Link-training state RX_DETECT_LTS_CHK_ERR of an HDMI 2.1 receiver: once FLT_UPDATE is clear, check the
 * FRL rate, set the PHY for it and check every lane; then ask for a lower rate, a TxFFE step of the failing
 * lanes, or go on.
 *
 *   port  HDMI 2.1 receiver 0/1 (any other value returns at once)
 *
 * Returns 0: hdmi_rx21_run_rx_detect_fsm moves on to the next receiver.
 *
 * Phases:
 *  1. On entry to the state: print the routine name and note the state.
 *  2. FRL rate field 0: clear the lane requests, go to RX_DETECT_LTS_L.
 *  3. FLT_UPDATE still set: count the pass; after CHK_ERR_WAIT_PASSES passes print "no_retrain"
 *     (NO_RETRAIN_BIT set), or print "Maybe need HPD at this case" and go back to RX_DETECT_INIT.
 *  4. FLT_UPDATE clear: print the rate; rate 0 is handled as in phase 2.
 *  5. Rate FRL_RATE_ABOVE_12G or more: write LANE_REQ_LOWER_RATE into every lane in use, set FLT_UPDATE,
 *     go to RX_DETECT_LTS_3.
 *  6. A rate other than the one the PHY is set for: take it over (hdmi_rx21_update_frl_rate), note it,
 *     raise the rate change flag (chip revisions up to 0x82), byte_0x34 = (frl_rate >= 4), set the FRL clock,
 *     wait one delay unit and set the PHY up for the rate (DRV_HDMI21_Set_PHY).
 *  7. Lane check (hdmi_rx21_check_sr_detect; skipped while hdmi_rx21_ltp_force_pass is set):
 *     - no failing lane: mark word B6_RATE_WRITE (newer chips), clear the lane requests, set FLT_UPDATE, go
 *       to RX_DETECT_LTS_P and clear scdc_lock_fails;
 *     - failing lanes and txffe_max 0: go to RX_DETECT_LTS_3;
 *     - otherwise each failing lane steps its TxFFE level (a step past txffe_max gives 0) and gets
 *       LANE_REQ_TXFFE_STEP; set FLT_UPDATE, go to RX_DETECT_LTS_3, and print the time since the start of
 *       the link training pattern timer (hdmi_rx21_ltp_timer_ticks).
 */
int DRV_HDMI21_RXDetect_FSM_LTS_Chk_Err(unsigned int port)
{
    unsigned char p = port;
    unsigned char phy;
    unsigned char lane;
    unsigned char failed_lanes;

    if (p == 0)
        phy = PHY_RX21_0;
    else if (p == 1)
        phy = PHY_RX21_1;
    else
        return 0;

    /* 1. Entry into the state. */
    if (hdmi_rx21_rx_detect_states[p] != hdmi_rx21_lts_records[p].last_state) {
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_printf(DAT_a0067868, "DRV_HDMI21_RXDetect_FSM_LTS_Chk_Err");
        hdmi_rx21_lts_records[p].last_state = hdmi_rx21_rx_detect_states[p];
    }

    if (((ARR_a807db00[p].block6[B6_LTS_STATUS / 4] >> 24) & 0xf) == 0) {
        /* 2. No FRL rate. */
        clear_lane_requests(port);
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_print_string("[HDMI21]: FRL_Rate = 0 Error, enter error handle");
        hdmi_rx21_rx_detect_states[port & 0xff] = RX_DETECT_LTS_L;
        return 0;
    } else {
        if (reg_test_bit(FLT_UPDATE_BIT, ARR_a807db00[p].block6 + B6_LTS_CONTROL / 4) == 0) {
            if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                dbg_print_string("[HDMI21]: LTS_ChkE <Clr FLT_Update>\n");
        } else {
            /* 3. Still waiting for FLT_UPDATE to clear. */
            if (hdmi_rx21_lts_error_halves[p] == 0 && (dbg_hdmi_message_flags & HDMI_MSG_HDMI21))
                dbg_print_string("[HDMI21]: LTS_ChkE <W FLT updated>\n");
            if (++hdmi_rx21_lts_error_halves[p] >= CHK_ERR_WAIT_PASSES) {
                hdmi_rx21_lts_error_halves[p] = 0;
                if (reg_test_bit(NO_RETRAIN_BIT, ARR_a807db00[p].block6 + B6_LTS_STATUS / 4)) {
                    dbg_print_string("no_retrain\n");
                } else {
                    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                        dbg_printf("[HDMI21]: \n\tMaybe need HPD at this case(%d, %d).\n", p, hdmi_rx21_lts_error_halves[p]);
                    hdmi_rx21_rx_detect_states[p] = RX_DETECT_INIT;
                }
            }
            return 0;
        }

        /* 4. FLT_UPDATE is clear: look at the rate. */
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_printf("[HDMI21]: FRL_Rate = %d\n", (ARR_a807db00[p].block6[B6_LTS_STATUS / 4] >> 24) & 0xf);
        if ((ARR_a807db00[port & 0xff].block6[B6_LTS_STATUS / 4] & 0xf000000) == 0) {
            clear_lane_requests(port);
            if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                dbg_print_string("[HDMI21]: FRL_Rate Error, enter error handle");
            hdmi_rx21_rx_detect_states[port & 0xff] = RX_DETECT_LTS_L;
            return 0;
        } else {
            if (((ARR_a807db00[port & 0xff].block6[B6_LTS_STATUS / 4] & 0xf000000) >> 24) >= FRL_RATE_ABOVE_12G) {
                /* 5. Ask every lane in use for a lower rate. */
                if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                    dbg_print_string("[HDMI21]: FRL_Rate > 12G, request for lower FRL rate");
                for (lane = 0; lane < hdmi_rx21_lts_records[port & 0xff].lane_count; lane++) {
                    if (lane == 0)
                        ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_01 / 4] = (ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_01 / 4] & 0xf0ffffff) | 0xf000000;
                    else if (lane == 1)
                        ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_01 / 4] = (ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_01 / 4] & 0x0fffffff) | 0xf0000000;
                    else if (lane == 2)
                        ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_23 / 4] = (ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_23 / 4] & ~0xf) | 0xf;
                    else if (lane == 3)
                        ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_23 / 4] = (ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_23 / 4] & ~0xf0) | 0xf0;
                }
                reg_set_bit(FLT_UPDATE_BIT, ARR_a807db00[port & 0xff].block6 + B6_LTS_CONTROL / 4);
                hdmi_rx21_rx_detect_states[port & 0xff] = RX_DETECT_LTS_3;
            } else {
                /* 6. A new rate: set the clock and the PHY up for it. */
                if (((ARR_a807db00[port & 0xff].block6[B6_LTS_STATUS / 4] & 0xf000000) >> 24) != hdmi_rx21_lts_records[port & 0xff].frl_rate_in_phy) {
                    hdmi_rx21_update_frl_rate(port & 0xff);
                    hdmi_rx21_lts_records[port & 0xff].frl_rate_in_phy = (ARR_a807db00[port & 0xff].block6[B6_LTS_STATUS / 4] & 0xf000000) >> 24;
                    if (sys_get_chip_revision() <= CHIP_REV_82)
                        hdmi_rx21_frl_rate_change_flags[port & 0xff] = 1;
                    if (hdmi_rx21_lts_records[port & 0xff].frl_rate >= 4)
                        hdmi_rx21_lts_records[port & 0xff].byte_0x34 = 1;
                    else
                        hdmi_rx21_lts_records[port & 0xff].byte_0x34 = 0;
                    hdmi_rx21_set_frl_clock_wrapper(port & 0xff, hdmi_rx21_lts_records[port & 0xff].frl_rate_in_phy);
                    timer_delay_long_units(1);
                    DRV_HDMI21_Set_PHY(phy, hdmi_rx21_lts_records[port & 0xff].frl_rate_in_phy);
                    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                        dbg_printf("[HDMI21]: LTS_Chk_Err u8FRL_Rate_SetInPhy = %d\n", hdmi_rx21_lts_records[port & 0xff].frl_rate_in_phy);
                }

                /* 7. Lane check; a set bit in failed_lanes is a failing lane. */
                failed_lanes = 0;
                if (hdmi_rx21_ltp_force_pass == 0)
                    failed_lanes = hdmi_rx21_check_sr_detect(port);
                if (failed_lanes == 0) {
                    /* All lanes pass. */
                    if (sys_get_chip_revision() > CHIP_REV_82)
                        ARR_a807db00[port & 0xff].block6[B6_RATE_WRITE / 4] = (ARR_a807db00[port & 0xff].block6[B6_RATE_WRITE / 4] & 0xffff00ff) | 0xff00;
                    for (lane = 0; lane < 4; lane++) {
                        if (lane == 0)
                            ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_01 / 4] &= 0xf0ffffff;
                        else if (lane == 1)
                            ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_01 / 4] &= 0x0fffffff;
                        else if (lane == 2)
                            ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_23 / 4] &= ~0xf;
                        else if (lane == 3)
                            ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_23 / 4] &= ~0xf0;
                    }
                    reg_set_bit(FLT_UPDATE_BIT, ARR_a807db00[port & 0xff].block6 + B6_LTS_CONTROL / 4);
                    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                        dbg_printf("[HDMI21]: LTS_Chk_Err wait for FLT_update clear 3 (%d)\n", hdmi_rx21_lts_records[port & 0xff].frl_rate_in_phy);
                    hdmi_rx21_rx_detect_states[port & 0xff] = RX_DETECT_LTS_P;
                    hdmi_rx21_lts_records[port & 0xff].scdc_lock_fails = 0;
                } else if (hdmi_rx21_lts_records[port & 0xff].txffe_max == 0) {
                    hdmi_rx21_rx_detect_states[port & 0xff] = RX_DETECT_LTS_3;
                } else {
                    /* One TxFFE step for each failing lane. */
                    for (lane = 0; lane < hdmi_rx21_lts_records[port & 0xff].lane_count; lane++) {
                        if ((failed_lanes >> lane) & 1) {
                            hdmi_rx21_lts_records[port & 0xff].txffe[lane]++;
                            if (lane == 0)
                                ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_01 / 4] = (ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_01 / 4] & 0xf0ffffff) | 0xe000000;
                            else if (lane == 1)
                                ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_01 / 4] = (ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_01 / 4] & 0x0fffffff) | 0xe0000000;
                            else if (lane == 2)
                                ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_23 / 4] = (ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_23 / 4] & ~0xf) | 0xe;
                            else if (lane == 3)
                                ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_23 / 4] = (ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_23 / 4] & ~0xf0) | 0xe0;
                            if (hdmi_rx21_lts_records[port & 0xff].txffe[lane] % (hdmi_rx21_lts_records[port & 0xff].txffe_max + 1) == 0)
                                hdmi_rx21_lts_records[port & 0xff].txffe[lane] = 0;
                        }
                        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                            dbg_printf("[HDMI21]: TxFFE[%d] = %d\n", lane, hdmi_rx21_lts_records[port & 0xff].txffe[lane]);
                    }
                    reg_set_bit(FLT_UPDATE_BIT, ARR_a807db00[port & 0xff].block6 + B6_LTS_CONTROL / 4);
                    hdmi_rx21_rx_detect_states[port & 0xff] = RX_DETECT_LTS_3;
                    hdmi_rx21_ltp_end_ticks[port & 0xff] = timer_get_ticks();
                    dbg_printf("Jex: TxFFE, (%ld)\n\n", hdmi_rx21_ltp_end_ticks[port & 0xff] - hdmi_rx21_ltp_timer_ticks[port & 0xff]);
                }
            }
            return 0;
        }
    }
}
