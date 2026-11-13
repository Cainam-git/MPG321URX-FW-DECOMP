/* DRV_HDMI21_RXDetect_FSM_LTS_L  (DRV_HDMI21_RXDetect_FSM_LTS_L)
 *
 * Run state LTS:L of an HDMI 2.1 receiver: go to LTS:3 once an FRL rate is set, else count passes.
 *   port: HDMI 2.1 receiver 0/1
 * Note: After more than 700 counted passes it calls hdmi_rx21_reset_error_counter and prints 'HPD Toggle to
 *   recover'.
 * Name basis: proven - original name printed (fn_ text); 'Port%d HPD Toggle to recover(%d)'; state 7 of
 *   0xA00B4230
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI21_RXDetect_FSM_LTS_L @ 0xa009bba8-0xa009bef0, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - hdmi_rx21_rx_detect_states is declared unsigned long (as in the sibling states LTS_P and LTS_Chk_Stable);
 *  - 'sel = 2;' is assigned before the port test, which keeps the port byte in one register for the record
 *    address of the lane request loop;
 *  - the routine name is a static const char array, not a string literal in the call.
 */
#define HDMI_MSG_HDMI21 0x800           /* debug flag bit 11: the "[HDMI21]" lines */

/* Link-training states: index into hdmi_rx21_rx_detect_state_handlers (state routine names). */
enum rx_detect_state {
    RX_DETECT_LTS_3 = 3,
    RX_DETECT_LTS_L = 7                 /* this routine */
};

/* Registers of receiver register block 0 and 6 (byte offsets). */
#define B0_CONTROL_4    4               /* bit 17 is tested */
#define B6_LTS_STATUS   0x90            /* bits 24..27 FRL rate ("FRL_Rate"), bit 17 NO_RETRAIN_BIT */
#define NO_RETRAIN_BIT  0x11
#define B6_LANE_REQ_01  0xa0            /* lane request fields: lane 0 bits 24..27, lane 1 bits 28..31 */
#define B6_LANE_REQ_23  0xa4            /* lane 2 bits 0..3, lane 3 bits 4..7 */
#define PHY_REG_3600    0x3600          /* PHY register: bits 0 and 1 are cleared on entry */

#define LTS_L_NO_RETRAIN_PASSES 0x64    /* passes counted before NO_RETRAIN_BIT is cleared */
#define LTS_L_RECOVER_PASSES    0x2bc   /* passes counted before the recovery (700) */

/* Register block addresses of an HDMI 2.1 receiver (13 words, table at 0xA807DB00). */
struct hdmi_rx21_reg_blocks {
    volatile unsigned int *block0;      /* 0xCE009000 (+0x1000 for receiver 1) */
    unsigned char block1_2[8];
    volatile unsigned int *block3;      /* 0xCE009300 */
    unsigned char block4_5[8];
    volatile unsigned int *block6;      /* 0xCE009600 */
    unsigned char block7_12[0x34 - 0x1c];
};
/* The fields of the link training record (0xB0 bytes, table at 0xA807D680) used here. */
struct hdmi_rx21_lts_record {
    unsigned char lane_count;           /* +0 */
    unsigned char frl_rate;             /* +1 */
    unsigned char frl_rate_in_phy;      /* +2: "u8FRL_Rate_SetInPhy" */
    unsigned char pad_0x3[0x30 - 3];
    unsigned int last_state;            /* +0x30: rx-detect state seen at the last pass */
    unsigned char pad_0x34[0xb0 - 0x34];
};
/* The fields of the receiver record (0x190 bytes, table at 0xA807D7E0) used here. */
struct rx21_record {
    unsigned char byte_0x0;
    unsigned char mode_detected;        /* +1 */
    unsigned char pad_0x2[0x190 - 2];
};
/* The fields of the PHY record (0x18 bytes per PHY, table at 0xA807CC64) used here. */
struct hdmi_phy_record {
    unsigned char power;                /* +0 */
    unsigned char eq_done;              /* +1 */
    unsigned char pad_0x2[4];
    unsigned char byte_0x6;
    unsigned char pad_0x7[0x18 - 7];
};

extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];
extern unsigned long hdmi_rx21_rx_detect_states[];
extern struct hdmi_phy_record hdmi_phy_records[];
extern struct rx21_record hdmi_rx21_input_records[];
extern unsigned short hdmi_rx21_error_counters[];       /* per receiver: passes counted in this state */
extern unsigned int dbg_hdmi_message_flags;
extern const char DAT_a0067868[];               /* "[HDMI21]: =%s=" (bold) */

extern int dbg_printf(const char *, ...);
extern void reg_set_bit(unsigned int, volatile unsigned int *);
extern void reg_clear_bit(unsigned int, volatile unsigned int *);
extern unsigned int reg_test_bit(unsigned int, volatile unsigned int *);
extern void DRV_HDMI21_LTS_STS_InitialSettings(unsigned char);        /* DRV_HDMI21_LTS_STS_InitialSettings */
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern void hdmi_rx21_reset_error_counter(unsigned char);

static const char fn_[] = "DRV_HDMI21_RXDetect_FSM_LTS_L";

/*
 * Link-training state RX_DETECT_LTS_L of an HDMI 2.1 receiver: the state entered when no FRL rate is
 * requested. It leaves for RX_DETECT_LTS_3 as soon as the FRL rate field of B6_LTS_STATUS is not 0; until
 * then it counts passes and, after LTS_L_RECOVER_PASSES of them, asks for a recovery.
 *
 *   port  HDMI 2.1 receiver 0/1 (any other value returns at once)
 *
 * Returns 0: hdmi_rx21_run_rx_detect_fsm, which calls the state routines, moves on to the next receiver.
 *
 * 1. On entry to the state (the state word differs from last_state): clear the lane requests, print the
 *    routine name, zero the pass count, note the state, clear frl_rate_in_phy, set bit 22 of B6_LANE_REQ_01,
 *    run DRV_HDMI21_LTS_STS_InitialSettings and clear bits 0 and 1 of PHY register 0x3600.
 * 2. FRL rate field not 0: state RX_DETECT_LTS_3, pass count 0, return.
 * 3. Otherwise: a receiver record with mode_detected 1 zeroes the pass count. Above LTS_L_RECOVER_PASSES the
 *    count is zeroed again and hdmi_rx21_reset_error_counter flags the receiver in input_port_event_flags;
 *    "HPD Toggle to recover" is printed. Below that, above LTS_L_NO_RETRAIN_PASSES a set NO_RETRAIN_BIT is
 *    cleared, and a pass is counted when byte 6 of the PHY record is not 0, bit 17 of B0_CONTROL_4 is set and
 *    mode_detected is 0.
 * 4. The state stays RX_DETECT_LTS_L.
 */
int DRV_HDMI21_RXDetect_FSM_LTS_L(unsigned int port)
{
    unsigned char p = port;
    unsigned char phy;                  /* PHY of the receiver: 2 or 3 */
    unsigned char i;

    phy = 2;
    if (p != 0) {
        if (p == 1)
            phy = 3;
        else
            return 0;
    }
    /* 1. Entry into the state. */
    if (hdmi_rx21_rx_detect_states[p] != hdmi_rx21_lts_records[p].last_state) {
        for (i = 0; i <= 3; i++) {
            if (i == 0)
                ARR_a807db00[p].block6[B6_LANE_REQ_01 / 4] &= 0xf0ffffff;
            else if (i == 1)
                ARR_a807db00[p].block6[B6_LANE_REQ_01 / 4] &= 0x0fffffff;
            else if (i == 2)
                ARR_a807db00[p].block6[B6_LANE_REQ_23 / 4] &= ~0xf;
            else if (i == 3)
                ARR_a807db00[p].block6[B6_LANE_REQ_23 / 4] &= ~0xf0;
        }
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_printf(DAT_a0067868, fn_);
        hdmi_rx21_error_counters[p] = 0;
        hdmi_rx21_lts_records[p].last_state = hdmi_rx21_rx_detect_states[p];
        hdmi_rx21_lts_records[p].frl_rate_in_phy = 0;
        reg_set_bit(0x16, ARR_a807db00[p].block6 + B6_LANE_REQ_01 / 4);
        DRV_HDMI21_LTS_STS_InitialSettings(p);
        hdmi_phy_write_bit(0, 0, p, PHY_REG_3600);
        hdmi_phy_write_bit(0, 1, p, PHY_REG_3600);
    }
    /* 2. A rate is requested: continue with the link training. */
    if ((ARR_a807db00[p].block6[B6_LTS_STATUS / 4] >> 24) & 0xf) {
        hdmi_rx21_rx_detect_states[p] = RX_DETECT_LTS_3;
        hdmi_rx21_error_counters[p] = 0;
        return 0;
    }
    /* 3. Still no rate. */
    if (hdmi_rx21_input_records[p].mode_detected == 1)
        hdmi_rx21_error_counters[p] = 0;
    if (hdmi_rx21_error_counters[p] > LTS_L_RECOVER_PASSES) {
        hdmi_rx21_error_counters[p] = 0;
        hdmi_rx21_reset_error_counter(p);
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_printf("[HDMI21]: Port%d HPD Toggle to recover(%d)\n\n", p, 1);
    } else {
        if (hdmi_rx21_error_counters[p] > LTS_L_NO_RETRAIN_PASSES && reg_test_bit(NO_RETRAIN_BIT, ARR_a807db00[p].block6 + B6_LTS_STATUS / 4))
            reg_clear_bit(NO_RETRAIN_BIT, ARR_a807db00[p].block6 + B6_LTS_STATUS / 4);
        if (hdmi_phy_records[phy].byte_0x6 != 0 && reg_test_bit(0x11, ARR_a807db00[p].block0 + B0_CONTROL_4 / 4) && hdmi_rx21_input_records[p].mode_detected == 0)
            hdmi_rx21_error_counters[p]++;
    }
    /* 4. */
    hdmi_rx21_rx_detect_states[p] = RX_DETECT_LTS_L;
    return 0;
}
