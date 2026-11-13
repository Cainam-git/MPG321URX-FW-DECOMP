/* FSM_MODE_DETECT_STANDBY  (FSM_MODE_DETECT_STANDBY)
 *
 * Compare the measured HDMI 2.1 timing with the last pass and count the passes that stay the same.
 *   port_number: HDMI 2.1 receiver 0/1
 * Returns: 1 when the stable count has passed its limit with a stable pixel clock (also when the PHY clock
 *   check fails), else 0
 * Name basis: proven - state name printed in 'go back to FSM_MODE_DETECT_STANDBY state' (the state it returns
 *   to, state 0); 'New/Old H_Total', 'Sync Stable Count'
 *
 * Matching notes
 * --------------
 * leon2s FSM_MODE_DETECT_STANDBY @ 0xa00977e8-0xa0097ed0, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - an unsigned int parameter copied into the unsigned char local port ('port = port_number;'), as in the
 *    sibling DRV_HDMI_ModeDetect_FSM_FRL_Chk;
 *  - phy = 2, then 3 when receiver_is_1(port): a static helper with the body of the firmware's own
 *    hdmi_is_second_port ('r = 0; if (port == 1) r = 1; return r & 1;'), inlined (firmware 0xa00977f0 'xor; cmp;
 *    addx; mov 3; sub' and the copy into phy);
 *  - the register block read as hdmi_rx21_reg_blocks[port].block0[...] in each expression;
 *  - the prints pass (char)(port + 'A'); the limit test is written 'stable_count > limit'.
 */

/* Message groups of dbg_hdmi_message_flags. */
#define HDMI_MSG_MODEDET_FLOW   0x04

/* States of the mode detection (index of the table hdmi_rx21_run_mode_detect_fsm runs). */
#define MODEDET_STATE_WAIT_EQ_END   0   /* hdmi_rx21_modedet_wait_eq_done */
#define MODEDET_STATE_SETTLE        6   /* hdmi_rx21_mode_detect_settle */

/* PHY numbers of the two HDMI 2.1 receivers. */
#define PHY_RX21_0              2
#define PHY_RX21_1              3

/* Words of register block 0 that hold the measured timing. */
#define BLOCK0_HTOTAL           (0x38 / 4)  /* bits 16..31, shifted left by hdmi_rx21_two_port_mode_flags */
#define BLOCK0_VTOTAL           (0x3c / 4)
#define BLOCK0_HACTIVE          (0x4c / 4)  /* "DE": bits 16..31, shifted like the total */
#define BLOCK0_VACTIVE          (0x50 / 4)  /* "DE_Line" */
#define BLOCK0_REG_2_BIT11      0xb     /* set by DRV_HDMI_ModeDetect_FSM_FRL_Init */

#define VTOTAL_TOLERANCE        5       /* lines */
#define ACTIVE_TOLERANCE        1
#define CLOCK_TOLERANCE         0x28    /* largest difference of the two pixel clock readings that is stable */
#define CLOCK_JUMP              500     /* a larger difference restarts the count once it is above 3 */
#define CLOCK_STORE_MIN         101     /* measured clocks 101..0x4587 are stored */
#define CLOCK_STORE_SPAN        0x4522
#define PHY_CLOCK_TOLERANCE     500

/* Register block addresses of one HDMI 2.1 receiver (0x34 bytes, hdmi_rx21_reg_blocks). */
struct rx21_reg_blocks {
    volatile unsigned int *block0;
    unsigned char blocks_1_to_12[0x34 - 4];
};
/* Mode-detection state of one HDMI 2.1 receiver (24 bytes). */
struct rx21_mode_detect_state {
    unsigned int state;                 /* MODEDET_STATE_* */
    unsigned char byte_0x4;
    unsigned char stable_count;         /* "Sync Stable Count" */
    unsigned char hold_count;           /* counted down by the settle state */
    unsigned char _7[2];
    unsigned char byte_0x9;
    unsigned char _a[0x18 - 0xa];
};
/* The record of one HDMI 2.1 receiver (400 bytes, hdmi_rx21_input_records): the part used here. */
struct rx21_record {
    unsigned char _00[6];
    unsigned char vrr_flags;            /* set by hdmi_rx21_detect_vrr_signalling */
    unsigned char _07[0x19 - 7];
    unsigned char color_depth;          /* +0x19 */
    unsigned short htotal;              /* +0x1a: the values of the last pass */
    unsigned short vtotal;
    unsigned short hactive;
    unsigned short vactive;
    unsigned char _22[400 - 0x22];
};
/* HDMI PHY record (the PHY link table entry, 24 bytes per PHY, hdmi_phy_records). */
struct hdmi_phy_record {
    unsigned char power;
    unsigned char eq_done;              /* read by hdmi_phy_is_eq_done; the EQ scan sets it at its end */
    unsigned char _2[6];
    unsigned short phy_clock_mhz;       /* +8: printed as "PHY_clk" */
    unsigned char _a[0x18 - 0xa];
};

extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern struct rx21_mode_detect_state hdmi_rx21_mode_detect_states[];
extern struct rx21_record hdmi_rx21_input_records[];
extern struct hdmi_phy_record hdmi_phy_records[];
extern unsigned char hdmi_rx21_lts_records[][0xb0];  /* link-training records: byte 1 is the FRL rate */
extern unsigned char hdmi_rx21_stable_count_limits[];
extern unsigned char hdmi_rx21_two_port_mode_flags[];
extern unsigned char hdmi_rx21_standby_fail_counts[];
extern unsigned int dbg_hdmi_message_flags;

extern void reg_clear_bit(unsigned int, volatile unsigned int *);
extern unsigned short hdmi_rx21_measure_pixel_clock(unsigned char, unsigned char);
extern int dbg_printf(const char *, ...);
extern int abs(int);
extern void hdmi_rx21_detect_vrr_signalling(unsigned char);
extern unsigned char hdmi_rx21_has_cvtem(unsigned char);
extern unsigned int reg_test_bit(unsigned int, volatile unsigned int *);
extern unsigned char hdmi_get_port_mode_byte(unsigned int);
extern void hdmi_set_port_mode_byte(unsigned int, unsigned char);
extern unsigned short hdmi_rx21_get_pixel_clock(unsigned int);
extern void hdmi_rx21_store_clock(unsigned char, unsigned short);

static unsigned char receiver_is_1(unsigned char port)
{
    unsigned char r = 0;
    if (port == 1)
        r = 1;
    return r & 1;
}

/*
 * Mode-detection state 5 of an HDMI 2.1 receiver: compare the measured timing with the last pass and count
 * the passes in which it stayed the same.
 *
 *   port_number  HDMI 2.1 receiver 0 or 1 (printed as the letter 'A' + port)
 *
 * Returns 1 when the count has passed its limit with a stable pixel clock (state 6, or state 0 when the
 * PHY clock does not fit), else 0 (hdmi_rx21_run_mode_detect_fsm then stops until its next call).
 *
 * Phases:
 *  1. Measure: H_Total, V_Total, DE and DE_Line from register block 0 and the pixel clock; print the new and
 *     the stored values. A stored H_Total of 1716 with a new one of 858 and both V_Totals 262 or 263 is
 *     replaced by the new one before the compare.
 *  2. Compare: same timing when the V_Totals differ by at most 5 lines (or vrr_flags is set) and DE and
 *     DE_Line by at most 1; the new DE_Line must not be zero, and without a CVTEM packet neither the new DE
 *     nor the stored H_Total and V_Total.
 *     Same: count the pass. Different: the count starts again, and the input goes back to state 0, either
 *     at once (bit 11 of block 0 word 2 set: "2.1 unstable") or after the PHY's mode byte is switched:
 *     a set mode byte is cleared, otherwise every second failure sets it ("start only guess scramble");
 *     there the PHY's eq_done byte is cleared too ("Restart 2.0 EQ Flow").
 *  3. Store the new timing values. The pixel clock is stable when the receiver's pixel clock
 *     (hdmi_rx21_get_pixel_clock) and the new measurement differ by at most 40; measurements of 101..17799
 *     are stored. A difference of more than 500 restarts a count above 3.
 *  4. Count above hdmi_rx21_stable_count_limits[port] with a stable clock: when the FRL rate is not 0 the
 *     pixel clock times colour depth / 8, shifted by bits 6..7 of block 0 word 2, must lie within 500 of
 *     ten times the PHY clock, else state 0. Otherwise clear the PHY's mode byte and go to the settle
 *     state 6 with hold_count 10.
 */
int FSM_MODE_DETECT_STANDBY(unsigned int port_number)
{
    unsigned char port;
    unsigned char phy;                  /* PHY of this receiver */
    unsigned char clock_stable;
    unsigned char limit;
    unsigned short htotal, vtotal, hactive, vactive;
    unsigned short clock, clock_diff;

    port = port_number;
    clock_stable = 0;
    limit = hdmi_rx21_stable_count_limits[port];
    phy = PHY_RX21_0;
    if (receiver_is_1(port))
        phy = PHY_RX21_1;

    /* Phase 1: measure. */
    reg_clear_bit(0xc, hdmi_rx21_reg_blocks[port].block0 + 1);
    htotal = (hdmi_rx21_reg_blocks[port].block0[BLOCK0_HTOTAL] >> 16) << hdmi_rx21_two_port_mode_flags[port];
    vtotal = hdmi_rx21_reg_blocks[port].block0[BLOCK0_VTOTAL];
    hactive = (hdmi_rx21_reg_blocks[port].block0[BLOCK0_HACTIVE] >> 16) << hdmi_rx21_two_port_mode_flags[port];
    vactive = hdmi_rx21_reg_blocks[port].block0[BLOCK0_VACTIVE];
    clock = hdmi_rx21_measure_pixel_clock(port, 0);
    dbg_printf("Port%c New H_Total = %d, V_Total = %d, DE = %d, DE_Line = %d\n", (char)(port + 'A'), htotal, vtotal, hactive, vactive);
    dbg_printf("Port%c Old H_Total = %d, V_Total = %d, DE = %d, DE_Line = %d, \n", (char)(port + 'A'), hdmi_rx21_input_records[port].htotal, hdmi_rx21_input_records[port].vtotal,
                 hdmi_rx21_input_records[port].hactive, hdmi_rx21_input_records[port].vactive);
    if (hdmi_rx21_input_records[port].htotal == 0x6b4 && htotal == 0x35a && (unsigned short)(vtotal - 0x106) <= 1 &&
        (unsigned short)(hdmi_rx21_input_records[port].vtotal - 0x106) <= 1)
        hdmi_rx21_input_records[port].htotal = htotal;
    hdmi_rx21_detect_vrr_signalling(port);

    /* Phase 2: compare with the last pass. */
    if ((hdmi_rx21_has_cvtem(port) == 0 &&
         (hdmi_rx21_input_records[port].vrr_flags != 0 ||
          (abs(hdmi_rx21_input_records[port].vtotal - vtotal) <= VTOTAL_TOLERANCE)) &&
         abs(hdmi_rx21_input_records[port].hactive - hactive) <= ACTIVE_TOLERANCE &&
         abs(hdmi_rx21_input_records[port].vactive - vactive) <= ACTIVE_TOLERANCE && vactive != 0 &&
         hactive != 0 && hdmi_rx21_input_records[port].htotal != 0 && hdmi_rx21_input_records[port].vtotal != 0) ||
        (hdmi_rx21_has_cvtem(port) == 1 &&
         (hdmi_rx21_input_records[port].vrr_flags != 0 ||
          (abs(hdmi_rx21_input_records[port].vtotal - vtotal) <= VTOTAL_TOLERANCE)) &&
         abs(hdmi_rx21_input_records[port].vactive - vactive) <= ACTIVE_TOLERANCE && vactive != 0 &&
         abs(hdmi_rx21_input_records[port].hactive - hactive) <= ACTIVE_TOLERANCE)) {
        hdmi_rx21_mode_detect_states[port].stable_count++;
        if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
            dbg_printf("[MODEDET]: Port%c Sync Stable Count = %d\n", (char)(port + 'A'), hdmi_rx21_mode_detect_states[port].stable_count);
    } else {
        hdmi_rx21_mode_detect_states[port].stable_count = 0;
        if (reg_test_bit(BLOCK0_REG_2_BIT11, hdmi_rx21_reg_blocks[port].block0 + 2) != 0) {
            hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_WAIT_EQ_END;
            dbg_printf("Port%c 2.1 unstable, back to Standby\n", (char)(port + 'A'));
        } else {
            if (hdmi_get_port_mode_byte(phy)) {
                if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
                    dbg_printf("[MODEDET]: Port %c still fail go back to origin flow \n", (char)(port + 'A'));
                hdmi_set_port_mode_byte(phy, 0);
            } else if (++hdmi_rx21_standby_fail_counts[port] > 1) {
                if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
                    dbg_printf("[MODEDET]: Port %c start only guess scramble\n", (char)(port + 'A'));
                hdmi_set_port_mode_byte(phy, 1);
                hdmi_rx21_standby_fail_counts[port] = 0;
            }
            hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_WAIT_EQ_END;
            hdmi_phy_records[phy].eq_done = 0;
            dbg_printf("Port%c Reset Sync Stable Count = 0, and Back To Standby, Restart 2.0 EQ Flow\n", (char)(port + 'A'));
        }

    }

    /* Phase 3: keep this pass's values; check the pixel clock. */
    hdmi_rx21_input_records[port].vactive = vactive;
    hdmi_rx21_input_records[port].htotal = htotal;
    hdmi_rx21_input_records[port].vtotal = vtotal;
    hdmi_rx21_input_records[port].hactive = hactive;

    clock_diff = abs(hdmi_rx21_get_pixel_clock(port) - clock);
    if (clock_diff <= CLOCK_TOLERANCE)
        clock_stable = 1;
    if ((unsigned short)(clock - CLOCK_STORE_MIN) <= CLOCK_STORE_SPAN)
        hdmi_rx21_store_clock(port, clock);
    if (!clock_stable) {
        dbg_printf("unstable pixel clk = %d\r\n", hdmi_rx21_get_pixel_clock(port));
        if (hdmi_rx21_mode_detect_states[port].stable_count > 3 && clock_diff > CLOCK_JUMP)
            hdmi_rx21_mode_detect_states[port].stable_count = 0;
    }

    /* Phase 4: stable long enough. */
    if (hdmi_rx21_mode_detect_states[port].stable_count > limit && clock_stable) {
        if (hdmi_rx21_lts_records[port][1] != 0) {
            /* The pixel clock must agree with the PHY's clock. */
            if (abs((((int)(hdmi_rx21_get_pixel_clock(port) * hdmi_rx21_input_records[port].color_depth) >> 3) << ((hdmi_rx21_reg_blocks[port].block0[2] & 0xc0) >> 6)) -
                    hdmi_phy_records[phy].phy_clock_mhz * 10) > PHY_CLOCK_TOLERANCE) {
                if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
                    dbg_printf("[MODEDET]: Abnormal Pixel Clock(PHY_clk: %d), go back to FSM_MODE_DETECT_STANDBY state\n", hdmi_phy_records[phy].phy_clock_mhz);
                hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_WAIT_EQ_END;
                return 1;
            }
        }
        hdmi_set_port_mode_byte(phy & 3, 0);
        hdmi_rx21_standby_fail_counts[port] = 0;
        hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_SETTLE;
        hdmi_rx21_mode_detect_states[port].hold_count = 10;
        hdmi_rx21_mode_detect_states[port].byte_0x9 = 0xf;

        dbg_printf("stable pixel clk = %d\r\n", hdmi_rx21_get_pixel_clock(port));
        return 1;
    }
    return 0;
}
