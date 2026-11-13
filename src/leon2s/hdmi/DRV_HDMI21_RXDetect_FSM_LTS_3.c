/* DRV_HDMI21_RXDetect_FSM_LTS_3  (DRV_HDMI21_RXDetect_FSM_LTS_3)
 *
 * Run link training state 3: wait for FLT_update to clear, take the FRL rate, set lane requests 5..8.
 *   port: HDMI 2.1 receiver 0/1
 * Note: Then sets FLT_update again and goes to the error check state; with no FRL rate it goes back to state
 *   LTS_L.
 * Name basis: proven - original name printed ('DRV_HDMI21_RXDetect_FSM_LTS_3'); 'no_retrain', 'Maybe need HPD
 *   Toggle'
 *
 * Matching notes
 * --------------
 * DRV_HDMI21_RXDetect_FSM_LTS_3 (leon2s 0xa009860c-0xa0098b60, 1364 bytes), flags -mcpu=v8 -Os -g -msoft-float.
 * Source forms the exact build depends on:
 *  - clearing the lane request fields is the static inline helper clear_lane_requests, which takes the raw
 *    port (its first two uses); the third copy is written in place with the routine's own loop counter;
 *  - the register blocks are reached through hdmi_rx21_reg_blocks[port & 0xff] in the helper and in the last arm;
 *  - the port test is two nested ifs (|| folds into a range test).
 * -msoft-float changes the loop-invariant threshold, so the 0x60000000 constant of lane 1 stays inside the
 * last loop as in the firmware.
 */
#define HDMI_MSG_HDMI21 0x800           /* debug flag bit 11: the "[HDMI21]" lines (no name in the group list) */
#define CHIP_REV_82     0x82            /* sys_get_chip_revision: 0x80..0x84 */

/* Link-training states: index into hdmi_rx21_rx_detect_state_handlers (state routine names). */
enum rx_detect_state {
    RX_DETECT_INIT              = 0,    /* DRV_HDMI21_RXDetect_FSM_Init */
    RX_DETECT_LTS_1             = 1,
    RX_DETECT_LTS_2             = 2,
    RX_DETECT_LTS_3             = 3,    /* this routine */
    RX_DETECT_LTS_CHK_ERR       = 4,
    RX_DETECT_LTS_4             = 5,
    RX_DETECT_LTS_P             = 6,
    RX_DETECT_LTS_L             = 7,
    RX_DETECT_LTS_CHK_SCDC_ERR  = 8,
    RX_DETECT_LTS_CHK_STABLE    = 9
};

/* Registers of receiver register block 6 (byte offsets). */
#define B6_LTS_CONTROL  0x80            /* bit 4 cleared on each pass; bit 5 FLT_UPDATE */
#define FLT_UPDATE_BIT  5               /* set here, waited on: "LTS_3 <W>", "LTS_ChkE <W FLT updated>" */
#define B6_LTS_STATUS   0x90            /* bits 24..27 FRL rate ("FRL_Rate"), bit 17 NO_RETRAIN_BIT */
#define NO_RETRAIN_BIT  0x11            /* set: the wait timeout prints "no_retrain" */
#define B6_LANE_REQ_01  0xa0            /* lane request fields: lane 0 bits 24..27, lane 1 bits 28..31 */
#define B6_LANE_REQ_23  0xa4            /* lane 2 bits 0..3, lane 3 bits 4..7 */
#define B0_CONTROL_8    8               /* register block 0, word +8 */

#define LTS3_WAIT_PASSES 300            /* passes with FLT_UPDATE still set before the timeout message */

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
    unsigned char pad_0x1[0x13];
    unsigned char byte_0x14;
    unsigned char pad_0x15[0x30 - 0x15];
    unsigned int last_state;            /* +0x30: rx-detect state seen at the last pass */
    unsigned char pad_0x34[0xb0 - 0x34];
};

extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];
extern unsigned int hdmi_rx21_rx_detect_states[];
extern unsigned char hdmi_rx21_frl_rate_change_flags[];
extern unsigned short hdmi_rx21_lts3_halves[];
extern unsigned short hdmi_rx21_lts_error_halves[];
extern unsigned int dbg_hdmi_message_flags;
extern const char DAT_a0067868[];               /* "[HDMI21]: =%s=" (bold) */

extern unsigned char sys_get_chip_revision(void);
extern int hdmi_rx21_frl_rate_is_zero(unsigned int);
extern void reg_clear_bit(unsigned int, volatile unsigned int *);
extern void reg_set_bit(unsigned int, volatile unsigned int *);
extern unsigned int reg_test_bit(unsigned int, volatile unsigned int *);
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);
extern void hdmi_rx21_update_frl_rate(unsigned int);

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
 * Link-training state RX_DETECT_LTS_3 of an HDMI 2.1 receiver: wait until FLT_UPDATE is clear, then take
 * over the FRL rate and start the error check.
 *
 *   port  HDMI 2.1 receiver 0/1 (any other value returns at once)
 *
 * Returns 0: hdmi_rx21_run_rx_detect_fsm, which calls the state routines, moves on to the next receiver.
 *
 * Phases:
 *  1. On chip revisions up to 0x82 clear the receiver's FRL rate change flag. On entry to the state (the
 *     state word differs from last_state): print the routine name, note the state, restart the wait count.
 *  2. Clear bit 4 of B6_LTS_CONTROL.
 *  3. No FRL rate requested (hdmi_rx21_frl_rate_is_zero): clear the lane requests, go to RX_DETECT_LTS_L.
 *  4. FLT_UPDATE still set: count the pass; after LTS3_WAIT_PASSES passes restart the count and print
 *     "no_retrain" (NO_RETRAIN_BIT set) or "Maybe need HPD Toggle". The state stays the same.
 *  5. FLT_UPDATE clear: clear byte_0x14. No FRL rate: as phase 3. Otherwise, when the FRL rate field of
 *     B6_LTS_STATUS is not 0: set bit 11 of block 0 word +8, take the rate over (hdmi_rx21_update_frl_rate,
 *     which also sets lane_count), clear the lane requests, write 5, 6, 7, 8 into the request fields of
 *     lanes 0..lane_count-1, set FLT_UPDATE, go to RX_DETECT_LTS_CHK_ERR and restart its wait count.
 */
int DRV_HDMI21_RXDetect_FSM_LTS_3(unsigned int port)
{
    unsigned char p = port;
    unsigned char lane;

    if (p != 0) {
        if (p != 1)
            return 0;
    }

    /* 1. Rate change flag; entry into the state. */
    if (sys_get_chip_revision() <= CHIP_REV_82)
        hdmi_rx21_frl_rate_change_flags[p] = 0;
    if (hdmi_rx21_rx_detect_states[p] != hdmi_rx21_lts_records[p].last_state) {
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_printf(DAT_a0067868, "DRV_HDMI21_RXDetect_FSM_LTS_3");
        hdmi_rx21_lts_records[p].last_state = hdmi_rx21_rx_detect_states[p];
        hdmi_rx21_lts3_halves[p] = 0;
    }

    /* 2. */
    reg_clear_bit(4, ARR_a807db00[p].block6 + B6_LTS_CONTROL / 4);

    if (hdmi_rx21_frl_rate_is_zero(p) & 0xff) {
        /* 3. No FRL rate. */
        clear_lane_requests(port);
        hdmi_rx21_rx_detect_states[port & 0xff] = RX_DETECT_LTS_L;
    } else if (reg_test_bit(FLT_UPDATE_BIT, ARR_a807db00[p].block6 + B6_LTS_CONTROL / 4)) {
        /* 4. Still waiting for FLT_UPDATE to clear. */
        if (hdmi_rx21_lts3_halves[p] == 0 && (dbg_hdmi_message_flags & HDMI_MSG_HDMI21))
            dbg_print_string("[HDMI21]: \n\tLTS_3 <W>");
        if (++hdmi_rx21_lts3_halves[p] >= LTS3_WAIT_PASSES) {
            hdmi_rx21_lts3_halves[p] = 0;
            if (reg_test_bit(NO_RETRAIN_BIT, ARR_a807db00[p].block6 + B6_LTS_STATUS / 4))
                dbg_print_string("no_retrain\n");
            else if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                dbg_printf("[HDMI21]: \n\tMaybe need HPD Toggle(%d, %d)\n", p, hdmi_rx21_lts3_halves[p]);
        }
    } else {
        /* 5. FLT_UPDATE is clear. */
        hdmi_rx21_lts_records[p].byte_0x14 = 0;
        if (hdmi_rx21_frl_rate_is_zero(p) & 0xff) {
            clear_lane_requests(port);
            hdmi_rx21_rx_detect_states[port & 0xff] = RX_DETECT_LTS_L;
        } else if (((ARR_a807db00[p].block6[B6_LTS_STATUS / 4] >> 24) & 0xf) != 0) {
            reg_set_bit(0xb, ARR_a807db00[p].block0 + B0_CONTROL_8 / 4);
            hdmi_rx21_update_frl_rate(p);
            /* Clear all four lane requests (written out in place, see the matching notes). */
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
            /* Start values 5..8, one per lane in use. */
            for (lane = 0; lane < hdmi_rx21_lts_records[port & 0xff].lane_count; lane++) {
                if (lane == 0)
                    ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_01 / 4] = (ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_01 / 4] & 0xf0ffffff) | 0x5000000;
                else if (lane == 1)
                    ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_01 / 4] = (ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_01 / 4] & 0x0fffffff) | 0x60000000;
                else if (lane == 2)
                    ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_23 / 4] = (ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_23 / 4] & ~0xf) | 7;
                else if (lane == 3)
                    ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_23 / 4] = (ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_23 / 4] & ~0xf0) | 0x80;
            }
            reg_set_bit(FLT_UPDATE_BIT, ARR_a807db00[port & 0xff].block6 + B6_LTS_CONTROL / 4);
            hdmi_rx21_rx_detect_states[port & 0xff] = RX_DETECT_LTS_CHK_ERR;
            hdmi_rx21_lts_error_halves[port & 0xff] = 0;
        }
    }
    return 0;
}
