/* DRV_HDMI21_RXDetect_FSM_LTS_P  (DRV_HDMI21_RXDetect_FSM_LTS_P)
 *
 * Run the LTS:P link training state (pattern check, FLT update) of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: proven - original name printed (fn_ text); 'LTS_P <W>', 'LTS_P <Clr FLT_Update>', '3 Lane lock
 *   pass'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI21_RXDetect_FSM_LTS_P @ 0xa009ae98-0xa009b5f4, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - hdmi_rx21_rx_detect_states is declared unsigned long, as in the sibling states LTS_L and LTS_Chk_Stable; a
 *    long store cannot alias the unsigned int registers, which sets the order of the state store and the
 *    B6_RATE_WRITE update;
 *  - after the entry block the records are indexed with 'port & 0xff', and from the lock-pass branch on with
 *    port itself after 'port &= 0xff';
 *  - the end time is stored with a chained assignment, and the stay-in-state store is written
 *    *(hdmi_rx21_rx_detect_states + port) = RX_DETECT_LTS_P, which places the fail count increment as in the
 *    firmware;
 *  - the routine name is a string literal in the call.
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
    RX_DETECT_LTS_P             = 6,    /* this routine */
    RX_DETECT_LTS_L             = 7,
    RX_DETECT_LTS_CHK_SCDC_ERR  = 8,
    RX_DETECT_LTS_CHK_STABLE    = 9
};

/* Registers of receiver register block 0 (byte offsets). */
#define B0_CONTROL_4    4               /* bit 8 pulsed on entry; bit 21 cleared when the RS check passes */
#define B0_CONTROL_8    8               /* bit 11 set on entry */
/* Registers of receiver register block 6 (byte offsets). */
#define B6_REG_34       0x34
#define B6_RS_ERRORS    0x38            /* low 16 bits: "RS un-correct error" */
#define B6_REG_60       0x60            /* set to 1 on entry */
#define B6_LTS_CONTROL  0x80            /* bit 4 LTS_P_PASS_BIT, bit 5 FLT_UPDATE_BIT */
#define LTS_P_PASS_BIT  4               /* set when this state passes; LTS_3 clears it, LTS_Chk_Stable tests it */
#define FLT_UPDATE_BIT  5               /* set by LTS_3 / LTS_Chk_Err; this state waits until it is clear */
#define B6_LTS_STATUS   0x90            /* bits 24..27 FRL rate ("FRL_Rate"), bit 17 NO_RETRAIN_BIT */
#define NO_RETRAIN_BIT  0x11            /* set: the wait timeout prints "no_retrain" */
#define B6_RATE_WRITE   0xb0            /* bits 8..15 set to 0xFF; another value is a rate write */
/* Register block 8: four words, one per lane; low 15 bits = character error count ("correct error"). */
#define CED_COUNT_MASK  0x7fff

#define PHY_REG_2E60    0x2e60          /* PHY: bits 24..27 lane lock bits ("Lane lock pass") */
#define LANE_LOCK_3_LANES 0x7
#define LANE_LOCK_4_LANES 0xf
#define PHY_REG_2E70    0x2e70          /* PHY: bits 14..15 set with 3 lanes, cleared with 4 */

#define LTSP_WAIT_PASSES      300       /* passes with FLT_UPDATE still set before the timeout message */
#define RS_PASS_COUNT         0x8000    /* "RS un-correct error" value that counts as a pass */
#define RS_FAIL_LIMIT         5         /* more failed RS checks than this count as a pass */
#define LOCK_WAIT_RESET_PASSES 3        /* passes without lane lock before the clock recovery reset */
#define FRL_RATE_5            5         /* frl_rate_in_phy 5 and 6 take the CED IQ scan */

/* Register block addresses of an HDMI 2.1 receiver (13 words, table at 0xA807DB00). */
struct hdmi_rx21_reg_blocks {
    volatile unsigned int *block0;      /* 0xCE009000 (+0x1000 for receiver 1) */
    unsigned char block1_5[0x18 - 4];
    volatile unsigned int *block6;      /* 0xCE009600 */
    unsigned char block7[4];
    volatile unsigned int *block8;      /* 0xCE009800: the per-lane character error counts */
    unsigned char block9_12[0x34 - 0x24];
};
/* The fields of the link training record (0xB0 bytes, table at 0xA807D680) used here. */
struct hdmi_rx21_lts_record {
    unsigned char lane_count;           /* +0: 0, 3 or 4 */
    unsigned char frl_rate;             /* +1: FRL rate taken over by hdmi_rx21_update_frl_rate */
    unsigned char frl_rate_in_phy;      /* +2: "u8FRL_Rate_SetInPhy" */
    unsigned char pad_0x3[0x2b - 3];
    unsigned char scdc_lock_fails;      /* +0x2B: here, passes without lane lock */
    unsigned char stable_count;         /* +0x2C: counted by LTS_Chk_Stable */
    unsigned char pad_0x2d[3];
    unsigned int last_state;            /* +0x30: rx-detect state seen at the last pass */
    unsigned char pad_0x34[3];
    unsigned char byte_0x37;
    unsigned char byte_0x38;
    unsigned char byte_0x39;
    unsigned char pad_0x3a[0xb0 - 0x3a];
};

extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];
extern unsigned long hdmi_rx21_rx_detect_states[];
extern unsigned short hdmi_rx21_ltsp_wait_passes[];  /* per receiver: passes waiting for FLT_UPDATE to clear */
extern unsigned char hdmi_rx21_ltsp_rs_fails[];    /* per receiver: failed RS checks in a row */
extern unsigned char hdmi_rx21_ltp_force_pass;
extern unsigned int hdmi_rx21_ltp_end_ticks[];      /* per receiver: end time of the LTP timer ("e:") */
extern unsigned int hdmi_rx21_ltp_timer_ticks[];/* per receiver: start time ("s:"), set by hdmi_rx21_update_frl_rate */
extern unsigned int dbg_hdmi_message_flags;
extern const char DAT_a0067868[];               /* "[HDMI21]: =%s=" (bold) */
extern const char DAT_a006a548[];               /* "LTP time = %ld, s:%ld, e:%ld" (red) */

extern unsigned char sys_get_chip_revision(void);
extern void reg_set_bit(unsigned int, volatile unsigned int *);
extern void reg_clear_bit(unsigned int, volatile unsigned int *);
extern unsigned int reg_test_bit(unsigned int, volatile unsigned int *);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);
extern void timer_delay_long_units(unsigned short);
extern void DRV_HDMI21_PHY_PICDR_Reset(unsigned char);
extern unsigned char hdmi_rx21_check_sr_detect(unsigned int);
extern unsigned int timer_get_ticks(void);
extern void hdmi_rx21_reset_lane_setting(unsigned char);
extern void DRV_HDMI21_IQ_Scan_byCED(unsigned char);
extern void hdmi_rx21_set_lane_ctrl_all(unsigned char);
extern void hdmi_rx21_clear_lane_ctrl_all(unsigned char);
extern void DRV_HDMI21_ReStart_AEQ2(unsigned char, int, int, int);

/*
 * Link-training state RX_DETECT_LTS_P of an HDMI 2.1 receiver: once FLT_UPDATE is clear, wait for the lane
 * lock of the lanes in use, check the Reed-Solomon ("RS") error count, and hand the link on to the error
 * check states.
 *
 *   port  HDMI 2.1 receiver 0/1 (any other value returns at once)
 *
 * Returns 0: hdmi_rx21_run_rx_detect_fsm, which calls the state routines, moves on to the next receiver.
 *
 * Phases:
 *  1. On entry to the state (the state word differs from last_state): print the routine name, note the
 *     state, clear byte_0x38 / byte_0x39, set bit 11 of block 0 word 8, bit 13 of block 6 word 0 and
 *     block 6 word 0x60 = 1; with 3 lanes clear bit 8 of block 6 word 0 and set bits 14..15 of PHY_REG_2E70,
 *     otherwise the other way round; pulse bit 8 of block 0 word 4 for one delay unit; clear the wait and
 *     fail counts.
 *  2. Rate written again (B6_RATE_WRITE not 0xFF, chip revisions above 0x82): mark the word and go back to
 *     RX_DETECT_LTS_3.
 *  3. FRL rate field of B6_LTS_STATUS other than frl_rate_in_phy: go back to RX_DETECT_LTS_3 (and mark
 *     B6_RATE_WRITE on newer chips).
 *  4. FLT_UPDATE still set: count the pass; every LTSP_WAIT_PASSES passes restart the count and print
 *     "no_retrain" (NO_RETRAIN_BIT set) or "HPD Toggle". The state stays the same.
 *  5. With hdmi_rx21_ltp_force_pass on: set LTS_P_PASS_BIT and go to RX_DETECT_LTS_CHK_STABLE.
 *  6. Lane lock: PHY_REG_2E60 must show the lock bits of all lanes in use (3 or 4).
 *  7. Locked: print the RS error count and the sum of the four character error counts. Unless the RS count
 *     reads RS_PASS_COUNT or more than RS_FAIL_LIMIT checks failed in a row, the check fails: write 0xFFFF
 *     into the low halves of block 6 words 0x34 and 0x38, count the failure and stay in this state.
 *     On a pass: set LTS_P_PASS_BIT, clear bit 21 of block 0 word 4, note the end time and print the LTP
 *     time, put the lane setting back to its default, then
 *       - frl_rate_in_phy 5 or 6: run the CED IQ scan, pulse the lane control bits and go to
 *         RX_DETECT_LTS_CHK_STABLE;
 *       - any other rate: restart adaptive equalisation (DRV_HDMI21_ReStart_AEQ2) and go to
 *         RX_DETECT_LTS_CHK_SCDC_ERR.
 *  8. Not locked (also with a lane count other than 3 or 4): every LOCK_WAIT_RESET_PASSES-th pass resets
 *     the clock recovery (DRV_HDMI21_PHY_PICDR_Reset); on chip revisions up to 0x82 a lane failing the
 *     scrambler-reset check (hdmi_rx21_check_sr_detect) then sends the link back to RX_DETECT_LTS_3.
 */
int DRV_HDMI21_RXDetect_FSM_LTS_P(unsigned int port)
{
    unsigned char p = port;
    unsigned char phy;
    unsigned char locked;
    unsigned int value;             /* register word to write back, later the end time */

    phy = PHY_RX21_0;
    locked = 0;
    if (p != 0) {
        if (p == 1)
            phy = PHY_RX21_1;
        else
            return 0;
    }

    /* 1. Entry into the state. */
    if (hdmi_rx21_rx_detect_states[p] != hdmi_rx21_lts_records[p].last_state) {
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_printf(DAT_a0067868, "DRV_HDMI21_RXDetect_FSM_LTS_P");
        hdmi_rx21_lts_records[p].last_state = hdmi_rx21_rx_detect_states[p];
        hdmi_rx21_lts_records[p].byte_0x38 = 0;
        hdmi_rx21_lts_records[p].byte_0x39 = 0;
        reg_set_bit(0xb, ARR_a807db00[p].block0 + B0_CONTROL_8 / 4);
        reg_set_bit(0xd, ARR_a807db00[p].block6);           /* block 6 word 0 */
        ARR_a807db00[p].block6[B6_REG_60 / 4] = 1;
        if (hdmi_rx21_lts_records[p].lane_count == 3) {
            reg_clear_bit(8, ARR_a807db00[p].block6);
            hdmi_phy_update_reg(phy, PHY_REG_2E70, 0xffffffff, 0xc000);
        } else {
            reg_set_bit(8, ARR_a807db00[p].block6);
            hdmi_phy_update_reg(phy, PHY_REG_2E70, 0xffff3fff, 0);
        }
        reg_set_bit(8, ARR_a807db00[p].block0 + B0_CONTROL_4 / 4);
        timer_delay_long_units(1);
        reg_clear_bit(8, ARR_a807db00[p].block0 + B0_CONTROL_4 / 4);
        hdmi_rx21_ltsp_wait_passes[p] = 0;
        hdmi_rx21_ltsp_rs_fails[p] = 0;
    }

    /* 2. The rate was written again. */
    if (sys_get_chip_revision() > CHIP_REV_82 && ((ARR_a807db00[port & 0xff].block6[B6_RATE_WRITE / 4] >> 8) & 0xff) != 0xff) {
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_print_string("[HDMI21]: FRL_Rate Change/Write detect at LTS_P cut4\n");
        value = (ARR_a807db00[port & 0xff].block6[B6_RATE_WRITE / 4] & 0xffff00ff) | 0xff00;
        hdmi_rx21_rx_detect_states[port & 0xff] = RX_DETECT_LTS_3;
        ARR_a807db00[port & 0xff].block6[B6_RATE_WRITE / 4] = value;
        return 0;
    }

    /* 3. The rate changed. */
    if (((ARR_a807db00[port & 0xff].block6[B6_LTS_STATUS / 4] >> 24) & 0xf) != hdmi_rx21_lts_records[port & 0xff].frl_rate_in_phy) {
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_print_string("[HDMI21]: FRL_Rate Change at LTS_P");
        hdmi_rx21_rx_detect_states[port & 0xff] = RX_DETECT_LTS_3;
        if (sys_get_chip_revision() > CHIP_REV_82)
            ARR_a807db00[port & 0xff].block6[B6_RATE_WRITE / 4] = (ARR_a807db00[port & 0xff].block6[B6_RATE_WRITE / 4] & 0xffff00ff) | 0xff00;
        return 0;
    }

    /* 4. Wait for FLT_UPDATE to clear. */
    if (reg_test_bit(FLT_UPDATE_BIT, ARR_a807db00[port & 0xff].block6 + B6_LTS_CONTROL / 4) == 0) {
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_print_string("[HDMI21]: LTS_P <Clr FLT_Update>\n");
    } else {
        if (hdmi_rx21_ltsp_wait_passes[port & 0xff] == 0 && (dbg_hdmi_message_flags & HDMI_MSG_HDMI21))
            dbg_print_string("[HDMI21]: LTS_P <W>\n");
        if (++hdmi_rx21_ltsp_wait_passes[port & 0xff] >= LTSP_WAIT_PASSES) {
            hdmi_rx21_ltsp_wait_passes[port & 0xff] = 0;
            if (reg_test_bit(NO_RETRAIN_BIT, ARR_a807db00[port & 0xff].block6 + B6_LTS_STATUS / 4)) {
                if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                    dbg_print_string("[HDMI21]: no_retrain\n");
            } else {
                /* The count printed is the one just cleared. */
                if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                    dbg_printf("[HDMI21]: HPD Toggle(%d, %d)\n", port & 0xff, hdmi_rx21_ltsp_wait_passes[port & 0xff]);
            }
        }
        return 0;
    }

    if (hdmi_rx21_ltp_force_pass == 0) {
        /* 6. Lane lock. */
        if (hdmi_rx21_lts_records[port & 0xff].lane_count == 3) {
            if (((hdmi_phy_read_reg(phy, PHY_REG_2E60) >> 24) & 0xf) == LANE_LOCK_3_LANES) {
                locked = 1;
                if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                    dbg_print_string("[HDMI21]: 3 Lane lock pass\n");
            } else {
                locked = 0;
                if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                    dbg_print_string("[HDMI21]: Wait 3 Lane lock\n");
            }
        } else if (hdmi_rx21_lts_records[port & 0xff].lane_count == 4) {
            if (((hdmi_phy_read_reg(phy, PHY_REG_2E60) >> 24) & 0xf) == LANE_LOCK_4_LANES) {
                locked = 1;
                if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                    dbg_print_string("[HDMI21]: 4 Lane lock pass\n");
            } else {
                locked = 0;
                if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                    dbg_print_string("[HDMI21]: Wait 4 Lane lock\n");
            }
        }
        if (locked) {
            /* 7. Reed-Solomon error check. */
            if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                dbg_printf("[HDMI21]: RS un-correct error = 0x%04X, correct error = 0x%04X\n\n", ARR_a807db00[port & 0xff].block6[B6_RS_ERRORS / 4] & 0xffff,
                             (ARR_a807db00[port & 0xff].block8[0] & CED_COUNT_MASK) + (ARR_a807db00[port & 0xff].block8[1] & CED_COUNT_MASK)
                             + (ARR_a807db00[port & 0xff].block8[2] & CED_COUNT_MASK) + (ARR_a807db00[port & 0xff].block8[3] & CED_COUNT_MASK));
            port &= 0xff;
            if ((ARR_a807db00[port].block6[B6_RS_ERRORS / 4] & 0xffff) == RS_PASS_COUNT || hdmi_rx21_ltsp_rs_fails[port] > RS_FAIL_LIMIT) {
                reg_set_bit(LTS_P_PASS_BIT, ARR_a807db00[port].block6 + B6_LTS_CONTROL / 4);
                reg_clear_bit(0x15, ARR_a807db00[port].block0 + B0_CONTROL_4 / 4);
                if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                    dbg_print_string("[HDMI21]: LTS:P RS Pass\n");
            } else {
                if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                    dbg_print_string("[HDMI21]: LTS:P RS Fail\n");
                ARR_a807db00[port].block6[B6_REG_34 / 4] |= 0xffff;
                ARR_a807db00[port].block6[B6_RS_ERRORS / 4] |= 0xffff;
                *(hdmi_rx21_rx_detect_states + port) = RX_DETECT_LTS_P;
                hdmi_rx21_ltsp_rs_fails[port]++;
                return 0;
            }

            /* Passed: note the end of the LTP timer and print the time since the rate was taken over. */
            hdmi_rx21_ltsp_rs_fails[port] = 0;
            value = hdmi_rx21_ltp_end_ticks[port] = timer_get_ticks();
            hdmi_rx21_lts_records[port].byte_0x37 = 0;
            dbg_printf(DAT_a006a548, value - hdmi_rx21_ltp_timer_ticks[port], hdmi_rx21_ltp_timer_ticks[port], value);
            hdmi_rx21_reset_lane_setting(phy);
            if ((unsigned char)(hdmi_rx21_lts_records[port].frl_rate_in_phy - FRL_RATE_5) <= 1) {
                DRV_HDMI21_IQ_Scan_byCED(phy);
                hdmi_rx21_set_lane_ctrl_all(phy);
                timer_delay_long_units(1);
                hdmi_rx21_clear_lane_ctrl_all(phy);
                hdmi_rx21_rx_detect_states[port] = RX_DETECT_LTS_CHK_STABLE;
                hdmi_rx21_lts_records[port].stable_count = 0;
            } else {
                DRV_HDMI21_ReStart_AEQ2(phy, 0, 1, 0);
                hdmi_rx21_rx_detect_states[port] = RX_DETECT_LTS_CHK_SCDC_ERR;
            }
        } else {
            /* 8. No lane lock yet. */
            if (++hdmi_rx21_lts_records[port & 0xff].scdc_lock_fails == LOCK_WAIT_RESET_PASSES) {
                hdmi_rx21_lts_records[port & 0xff].scdc_lock_fails = 0;
                DRV_HDMI21_PHY_PICDR_Reset(phy);
                if (sys_get_chip_revision() <= CHIP_REV_82 && hdmi_rx21_check_sr_detect(port & 0xff))
                    hdmi_rx21_rx_detect_states[port & 0xff] = RX_DETECT_LTS_3;
            }
        }
    } else {
        /* 5. Debug switch: no checks. */
        reg_set_bit(LTS_P_PASS_BIT, ARR_a807db00[port & 0xff].block6 + B6_LTS_CONTROL / 4);
        hdmi_rx21_rx_detect_states[port & 0xff] = RX_DETECT_LTS_CHK_STABLE;
        hdmi_rx21_lts_records[port & 0xff].stable_count = 0;
        dbg_print_string("Debug mode, foce pass for LTP. No need to check\n");
    }
    return 0;
}
