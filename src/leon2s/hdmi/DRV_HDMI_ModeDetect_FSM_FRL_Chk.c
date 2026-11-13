/* DRV_HDMI_ModeDetect_FSM_FRL_Chk  (DRV_HDMI_ModeDetect_FSM_FRL_Chk)
 *
 * Run the FRL lock check state of the HDMI 2.1 mode detection.
 *   port_number: HDMI 2.1 receiver 0/1
 * Name basis: proven - original name printed; 'FRL lock timeout (%d), back to standby', 'Restart 21_RX'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_ModeDetect_FSM_FRL_Chk @ 0xa009723c-0xa009740c (464 bytes), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - an unsigned int parameter copied into the unsigned char local port; the letter in the first print is
 *    made from the parameter itself;
 *  - sel is set to 2 and then to 3 for port 1 (not a conditional expression);
 *  - the link-training record is addressed through the byte pointer rec = hdmi_rx21_lts_records + port * 0xb0, the
 *    pass counter is pre-incremented inside the compare and the timeout counter inside the store;
 *  - on the restart path rec[0x3c] is cleared before rec[2].
 */
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern unsigned int hdmi_rx21_rx_detect_states[];
extern struct rx21_mode_detect_state hdmi_rx21_mode_detect_states[];
extern unsigned char hdmi_rx21_lts_records[];        /* link-training records, 0xb0 bytes per receiver */
extern struct hdmi_phy_record hdmi_phy_records[];
extern unsigned int hdmi_rx21_frl_payload_ticks[];
extern unsigned char hdmi_rx21_frl_lock_flags[];
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);
extern unsigned int reg_test_bit(unsigned int, volatile unsigned int *);

/* States of the mode detection (index of the table hdmi_rx21_run_mode_detect_fsm runs). */
#define MODEDET_STATE_WAIT_EQ_END   0   /* hdmi_rx21_modedet_wait_eq_done */
#define MODEDET_STATE_CHECK_PLL     4   /* hdmi_rx21_modedet_check_pll */

/* Link-training state (hdmi_rx21_rx_detect_states). */
#define RX_DETECT_LTS_3             3   /* DRV_HDMI21_RXDetect_FSM_LTS_3 */
#define RX_DETECT_LTS_CHK_STABLE    9   /* DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable */

/* Bytes of the link-training record (0xb0 bytes per receiver, hdmi_rx21_lts_records). */
#define LTS_RECORD_SIZE        0xb0
#define LTS_FRL_RATE_IN_PHY    2        /* 'u8FRL_Rate_SetInPhy' */
#define LTS_LOCK_PASSES        0x3b     /* passes of this state counted towards a lock timeout */
#define LTS_LOCK_TIMEOUTS      0x3c     /* lock timeouts so far (printed as "FRL lock timeout (%d)") */

/* Block 6 of the receiver's registers (word offsets). */
#define BLOCK6_REG_1C          (0x1c / 4)
#define B6_LTS_STATUS          0x90     /* byte offset in block 6 (block6 is indexed in words) */
#define BLOCK6_BIT5            5        /* in BLOCK6_REG_1C: sends the mode detection to the PLL check */
#define NO_RETRAIN_BIT         0x11     /* in B6_LTS_STATUS; the runner prints "FLT_no_retrain" on it too */
#define FRL_RATE_SHIFT         24       /* bits 24..27 of B6_LTS_STATUS: FRL rate */
#define FRL_RATE_2             2

#define LOCK_PASSES_MAX        5        /* passes of this state that make one lock timeout */
#define LOCK_TIMEOUTS_MAX      3        /* timeouts that send the mode detection back to standby; the next one restarts the receiver */
#define PAYLOAD_TICKS_MIN      700      /* hdmi_rx21_frl_payload_ticks above this, with FRL rate 2, sets the lock flag */
#define PLL_CHECK_COUNT        10       /* byte +4 of the mode-detect record when going to the PLL check */
#define PHY_ENTRY_RX21_FIRST   2        /* hdmi_phy_records entries 2 / 3 belong to HDMI 2.1 receivers 0 / 1 */

/* Register block addresses of one HDMI 2.1 receiver (0x34 bytes, hdmi_rx21_reg_blocks). */
struct rx21_reg_blocks {
    unsigned int blocks_0_to_5[6];
    volatile unsigned int *block6;
    unsigned char blocks_7_to_12[0x34 - 0x1c];
};
/* Mode-detection state of one HDMI 2.1 receiver (24 bytes). */
struct rx21_mode_detect_state {
    unsigned int state;
    unsigned char byte_0x4;
    unsigned char pad_0x5[0x18 - 5];
};
/* HDMI PHY record (24 bytes per PHY, hdmi_phy_records). */
struct hdmi_phy_record {
    unsigned char power;
    unsigned char eq_done;              /* +1: set to 1 when the EQ scan reaches its done state */
    unsigned char pad_0x2[0x18 - 2];
};

/*
 * Mode-detection state 3 of an HDMI 2.1 receiver: the FRL lock check. Always returns 0.
 *   port_number: HDMI 2.1 receiver 0 or 1 (printed as the letter 'A' + port)
 * Order of the decisions:
 *  1. With the FLT_no_retrain bit set (block 6), print "FLT_no_retrain, don't do anything" and leave.
 *  2. Set the mode-detect state to 0 (WAIT_EQ_END), unless the link training is in LTS_Chk_Stable (9).
 *  3. Bit 5 of block 6 word 0x1c set: state 4 (PLL check), byte +4 of the record 10, leave.
 *  4. Otherwise count this pass in the link-training record; every fifth pass counts as a lock timeout:
 *     - for the first three timeouts print "FRL lock timeout (n), back to standby", set the FRL lock flag
 *       of the port if the payload ticks are above 700 and the FRL rate field of block 6 is 2, and set the
 *       state to 0;
 *     - the next one prints "Restart 21_RX", sends the link training back to LTS_3, clears eq_done of the
 *       receiver's PHY entry, the timeout counter and the FRL_Rate_SetInPhy byte.
 */
int DRV_HDMI_ModeDetect_FSM_FRL_Chk(unsigned int port_number)
{
    unsigned char port;
    unsigned char sel;
    unsigned char *rec;
    unsigned char timeouts;

    port = port_number;
    sel = PHY_ENTRY_RX21_FIRST;
    if (port == 1)
        sel = PHY_ENTRY_RX21_FIRST + 1;
    if (reg_test_bit(NO_RETRAIN_BIT, hdmi_rx21_reg_blocks[port].block6 + B6_LTS_STATUS / 4) != 0) {
        dbg_print_string("FLT_no_retrain, don't do anything\n");
        return 0;
    }
    dbg_printf("Port%c DRV_HDMI_ModeDetect_FSM_FRL_Chk \n", (char)(port_number + 0x41));
    if (hdmi_rx21_rx_detect_states[port] != RX_DETECT_LTS_CHK_STABLE)
        hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_WAIT_EQ_END;
    if (reg_test_bit(BLOCK6_BIT5, hdmi_rx21_reg_blocks[port].block6 + BLOCK6_REG_1C) != 0) {
        hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_CHECK_PLL;
        hdmi_rx21_mode_detect_states[port].byte_0x4 = PLL_CHECK_COUNT;
        return 0;
    }
    rec = hdmi_rx21_lts_records + port * LTS_RECORD_SIZE;
    if (++rec[LTS_LOCK_PASSES] == LOCK_PASSES_MAX) {
        timeouts = rec[LTS_LOCK_TIMEOUTS];
        rec[LTS_LOCK_PASSES] = 0;
        if (timeouts <= LOCK_TIMEOUTS_MAX - 1) {
            rec[LTS_LOCK_TIMEOUTS] = ++timeouts;
            dbg_printf("FRL lock timeout (%d), back to standby\n\n", timeouts);
            if (hdmi_rx21_frl_payload_ticks[port] > PAYLOAD_TICKS_MIN && ((hdmi_rx21_reg_blocks[port].block6[B6_LTS_STATUS / 4] >> FRL_RATE_SHIFT) & 0xf) == FRL_RATE_2)
                hdmi_rx21_frl_lock_flags[port] = 1;
            hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_WAIT_EQ_END;
        } else {
            dbg_print_string("Restart 21_RX\n");
            hdmi_rx21_rx_detect_states[port] = RX_DETECT_LTS_3;
            hdmi_phy_records[sel].eq_done = 0;
            rec[LTS_LOCK_TIMEOUTS] = 0;
            rec[LTS_FRL_RATE_IN_PHY] = 0;
        }
    }
    return 0;
}
