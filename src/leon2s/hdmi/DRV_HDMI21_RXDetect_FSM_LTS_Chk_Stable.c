/* DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable  (DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable)
 *
 * Watch a trained HDMI 2.1 link for rate changes, lane lock loss and error bursts.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: 0
 * Name basis: proven - original name printed (fn_ text); 'FRL_Rate Change at LTS_Stable', 'Chk stable-Lane
 *   lock fail'; state 9 of 0xA00B4230
 *
 * Matching notes
 * --------------
 * DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable (leon2s 0xa0099ffc-0xa009a41c, 1056 bytes), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - after the first early return the records are indexed with 'port & 0xff' (the firmware re-extends the
 *    parameter);
 *  - the 4-lane test is written '!= 0xf' first, the 3-lane test '== 7' first;
 *  - hdmi_rx21_rx_detect_states is declared unsigned long (alias set: the state store then schedules after
 *    the field value in the "cut4" block);
 *  - the routine name is a separate static string (routine_name);
 *  - the register words are reached as word offsets of block pointers (block6 + 0x20 = byte 0x80).
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
    RX_DETECT_LTS_CHK_ERR       = 4,
    RX_DETECT_LTS_4             = 5,
    RX_DETECT_LTS_P             = 6,
    RX_DETECT_LTS_L             = 7,
    RX_DETECT_LTS_CHK_SCDC_ERR  = 8,
    RX_DETECT_LTS_CHK_STABLE    = 9     /* this routine */
};
#define MODE_DETECT_WAIT_EQ_DONE 0      /* first mode-detect state (hdmi_rx21_mode_detect_state_handlers) */

/* Registers, as word offsets of the register block pointers. */
#define B6_LTS_CONTROL_W 0x20           /* block 6 byte 0x80: bit 4 tested here */
#define B6_LTS_STATUS    0x90           /* block 6 (bytes): bits 24..27 FRL rate ("FRL_Rate") */
#define B6_LTS_STATUS_W  0x24           /* the same word, bit 17 NO_RETRAIN_BIT */
#define NO_RETRAIN_BIT   0x11
#define B6_RATE_WRITE    0xb0           /* block 6 (bytes): bits 8..15 set to 0xFF; another value is a rate write */
#define B3_CONTROL_7C_W  0x1f           /* block 3 byte 0x7C */
#define PHY_REG_2E60     0x2e60         /* PHY: bits 24..27 lane lock bits ("Lane lock fail") */
#define LANE_LOCK_3_LANES 0x7
#define LANE_LOCK_4_LANES 0xf

#define LANE_LOCK_FAIL_LIMIT 3          /* failed lock checks in a row before training again */
#define RATE_6               6          /* frl_rate with the periodic lane control pulse */
#define STABLE_PULSE_PASSES  200

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
    unsigned char lane_count;           /* +0: 0, 3 or 4 */
    unsigned char frl_rate;             /* +1: FRL rate taken over by hdmi_rx21_update_frl_rate */
    unsigned char frl_rate_in_phy;      /* +2: "u8FRL_Rate_SetInPhy" */
    unsigned char pad_0x3[0x2a - 3];
    unsigned char lane_lock_fails;      /* +0x2A */
    unsigned char scdc_lock_fails;
    unsigned char stable_count;         /* +0x2C: passes at FRL rate 6 */
    unsigned char pad_0x2d[3];
    unsigned int last_state;            /* +0x30: rx-detect state seen at the last pass */
    unsigned char pad_0x34[0xb0 - 0x34];
};
/* Mode-detect record of an HDMI 2.1 receiver (0x18 bytes). */
struct mode_detect_record {
    unsigned int state;                 /* index into hdmi_rx21_mode_detect_state_handlers */
    unsigned char byte_0x4;
    unsigned char pad_0x5[0x18 - 5];
};
/* HDMI receiver (PHY) record (24 bytes each, table at 0xA807CC64, indexed by PHY). */
struct hdmi_phy_record {
    unsigned char power;                /* +0 */
    unsigned char eq_done;              /* +1: set to 1 when the EQ scan reaches its done state */
    unsigned char pad_0x2[0x18 - 2];
};

extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];
extern unsigned long hdmi_rx21_rx_detect_states[];
extern struct mode_detect_record hdmi_rx21_mode_detect_states[];
extern struct hdmi_phy_record hdmi_phy_records[];
extern unsigned char hdmi_rx21_ltp_force_pass;
extern unsigned int dbg_hdmi_message_flags;
extern const char DAT_a0067868[];               /* "[HDMI21]: =%s=" (bold) */

extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);
extern unsigned char sys_get_chip_revision(void);
extern void hdmi_rx21_pulse_ctrl_bit(unsigned char);
extern void reg_clear_bit(unsigned int, volatile unsigned int *);
extern unsigned int reg_test_bit(unsigned int, volatile unsigned int *);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern void hdmi_rx21_reset_ced_history(unsigned char);
extern void hdmi_rx21_reset_rsed_history(unsigned char);
extern void hdmi_rx21_track_ced_errors(unsigned char);
extern void hdmi_rx21_track_rsed_errors(unsigned char);
extern void hdmi_rx21_set_lane_ctrl_all(unsigned char);
extern void hdmi_rx21_clear_lane_ctrl_all(unsigned char);
extern void timer_delay_long_units(int);

static const char routine_name[] = "DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable";

/*
 * Link-training state RX_DETECT_LTS_CHK_STABLE of an HDMI 2.1 receiver, the last state of a trained link:
 * watch the error counts, the FRL rate and the lane lock, and go back to RX_DETECT_LTS_3 when they change.
 *
 *   port  HDMI 2.1 receiver 0/1 (any other value returns at once)
 *
 * Returns 0: hdmi_rx21_run_rx_detect_fsm moves on to the next receiver.
 *
 * Phases:
 *  1. On entry to the state: print the routine name, note the state, pulse the PHY control bit
 *     (hdmi_rx21_pulse_ctrl_bit), clear bit 11 of block 3 word 0x7C and clear the character and
 *     Reed-Solomon error histories.
 *  2. Every pass: track the character and Reed-Solomon error counts (hdmi_rx21_track_ced_errors / _rsed_).
 *  3. Bit 4 of block 6 word 0x80 clear while the PHY's eq_done is not 1: restart the mode detection and set
 *     eq_done.
 *  4. Rate written again (B6_RATE_WRITE not 0xFF, newer chips): go to RX_DETECT_LTS_3 and mark the word.
 *  5. FRL rate other than the one the PHY is set for: clear eq_done, go to RX_DETECT_LTS_3 (mark the word
 *     on newer chips).
 *  6. Unless NO_RETRAIN_BIT is set or hdmi_rx21_ltp_force_pass is on: check the lane lock bits of the lanes
 *     in use; LANE_LOCK_FAIL_LIMIT failures in a row go to RX_DETECT_LTS_3 with frl_rate_in_phy and eq_done
 *     cleared.
 *  7. At FRL rate 6: every pass counts stable_count; after more than STABLE_PULSE_PASSES passes it restarts
 *     and the lane control bits are set for one delay unit and cleared again.
 */
int DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable(unsigned int port)
{
    unsigned char p = port;
    unsigned char phy;
    unsigned char value;

    if (p == 0)
        phy = PHY_RX21_0;
    else if (p == 1)
        phy = PHY_RX21_1;
    else
        return 0;

    /* 1. Entry into the state. */
    if (hdmi_rx21_rx_detect_states[p] != hdmi_rx21_lts_records[p].last_state) {
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_printf(DAT_a0067868, routine_name);
        hdmi_rx21_lts_records[p].last_state = hdmi_rx21_rx_detect_states[p];
        hdmi_rx21_pulse_ctrl_bit(phy);
        reg_clear_bit(0xb, ARR_a807db00[p].block3 + B3_CONTROL_7C_W);
        hdmi_rx21_reset_ced_history(p);
        hdmi_rx21_reset_rsed_history(p);
    }

    /* 2. Error counts. */
    hdmi_rx21_track_ced_errors(p);
    hdmi_rx21_track_rsed_errors(p);

    /* 3. */
    if (reg_test_bit(4, ARR_a807db00[p].block6 + B6_LTS_CONTROL_W) == 0 && hdmi_phy_records[phy].eq_done != 1) {
        hdmi_rx21_mode_detect_states[p].state = MODE_DETECT_WAIT_EQ_DONE;
        hdmi_phy_records[phy].eq_done = 1;
    }

    /* 4. The rate was written again. */
    if (sys_get_chip_revision() > CHIP_REV_82 && ((ARR_a807db00[p].block6[B6_RATE_WRITE / 4] >> 8) & 0xff) != 0xff) {
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_print_string("[HDMI21]: FRL_Rate Change/Write detect at LTS_Stable cut4\n");
        hdmi_rx21_rx_detect_states[p] = RX_DETECT_LTS_3;
        ARR_a807db00[p].block6[B6_RATE_WRITE / 4] = (ARR_a807db00[p].block6[B6_RATE_WRITE / 4] & 0xffff00ff) | 0xff00;
        return 0;
    }

    /* 5. The rate changed. */
    if (((ARR_a807db00[port & 0xff].block6[B6_LTS_STATUS / 4] & 0xf000000) >> 24) != hdmi_rx21_lts_records[port & 0xff].frl_rate_in_phy) {
        hdmi_phy_records[phy].eq_done = 0;
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_print_string("[HDMI21]: FRL_Rate Change at LTS_Stable\n");
        hdmi_rx21_rx_detect_states[port & 0xff] = RX_DETECT_LTS_3;
        if (sys_get_chip_revision() > CHIP_REV_82)
            ARR_a807db00[port & 0xff].block6[B6_RATE_WRITE / 4] = (ARR_a807db00[port & 0xff].block6[B6_RATE_WRITE / 4] & 0xffff00ff) | 0xff00;
        return 0;
    }

    /* 6. Lane lock. */
    if (reg_test_bit(NO_RETRAIN_BIT, ARR_a807db00[port & 0xff].block6 + B6_LTS_STATUS_W) == 0 && hdmi_rx21_ltp_force_pass == 0) {
        value = hdmi_rx21_lts_records[port & 0xff].lane_count;
        if (value == 3) {
            if (((hdmi_phy_read_reg(phy, PHY_REG_2E60) & 0xf000000) >> 24) == LANE_LOCK_3_LANES) {
                hdmi_rx21_lts_records[port & 0xff].lane_lock_fails = 0;
            } else {
                hdmi_rx21_lts_records[port & 0xff].lane_lock_fails++;
                if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                    dbg_printf("[HDMI21]: Chk stable-Lane lock fail at 3 lane mode %d times\n\n",
                                 hdmi_rx21_lts_records[port & 0xff].lane_lock_fails);
            }
        } else if (value == 4) {
            if (((hdmi_phy_read_reg(phy, PHY_REG_2E60) & 0xf000000) >> 24) != LANE_LOCK_4_LANES) {
                hdmi_rx21_lts_records[port & 0xff].lane_lock_fails++;
                if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                    dbg_printf("[HDMI21]: Chk stable-Lane lock fail at 4 lane mode %d times\n\n",
                                 hdmi_rx21_lts_records[port & 0xff].lane_lock_fails);
            } else {
                hdmi_rx21_lts_records[port & 0xff].lane_lock_fails = 0;
            }
        }
        if (hdmi_rx21_lts_records[port & 0xff].lane_lock_fails == LANE_LOCK_FAIL_LIMIT) {
            hdmi_rx21_rx_detect_states[port & 0xff] = RX_DETECT_LTS_3;
            hdmi_rx21_lts_records[port & 0xff].frl_rate_in_phy = 0;
            hdmi_phy_records[phy].eq_done = 0;
        }
    }

    /* 7. Periodic lane control pulse at rate 6. */
    if (hdmi_rx21_lts_records[port & 0xff].frl_rate == RATE_6) {
        value = hdmi_rx21_lts_records[port & 0xff].stable_count;
        hdmi_rx21_lts_records[port & 0xff].stable_count = value + 1;
        if (value > STABLE_PULSE_PASSES) {
            hdmi_rx21_lts_records[port & 0xff].stable_count = 0;
            hdmi_rx21_set_lane_ctrl_all(phy);
            timer_delay_long_units(1);
            hdmi_rx21_clear_lane_ctrl_all(phy);
        }
    }
    return 0;
}
