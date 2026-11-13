/* DRV_HDMI_ModeDetect_FSM_FRL_Payload  (DRV_HDMI_ModeDetect_FSM_FRL_Payload)
 *
 * Run the FRL payload check state of the HDMI 2.1 mode detection.
 *   port_number: HDMI 2.1 receiver 0/1
 * Name basis: proven - original name printed; 'RS err', 'FRL Preload_unstable'; calls FRL_PLL
 *
 * Matching notes
 * --------------
 * DRV_HDMI_ModeDetect_FSM_FRL_Payload (leon2s 0xa0096f60-0xa009723c, 732 bytes), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - an unsigned int parameter copied into the unsigned char local port after the first print;
 *  - FRL_PLL takes the payload value as its second parameter (it is already in %o1 at the call);
 *  - the range test is two nested ifs with the print in both else arms;
 *  - the link-training record pointer is taken again in the in-range block (lts_in_range);
 *  - volatile only on the register block pointers.
 * The payload measurement is called by its link label FUN_a00967ec (hdmi_rx21_measure_payload_delay).
 */

/* Message groups of dbg_hdmi_message_flags. */
#define HDMI_MSG_MODEDET_FLOW   0x04

/* States of the mode detection (index of the table hdmi_rx21_run_mode_detect_fsm runs). */
#define MODEDET_STATE_WAIT_EQ_END   0   /* hdmi_rx21_modedet_wait_eq_done */
#define MODEDET_STATE_FRL_PAYLOAD   2   /* this routine */
#define MODEDET_STATE_FRL_CHK       3   /* DRV_HDMI_ModeDetect_FSM_FRL_Chk */

/* Link-training states (hdmi_rx21_rx_detect_states). */
#define RX_DETECT_LTS_3             3   /* DRV_HDMI21_RXDetect_FSM_LTS_3 */
#define RX_DETECT_LTS_CHK_STABLE    9   /* DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable */

/* Bytes of the link-training record (0xb0 bytes per receiver, hdmi_rx21_lts_records). */
#define LTS_RECORD_SIZE         0xb0
#define LTS_FRL_RATE            1
#define LTS_FRL_RATE_IN_PHY     2       /* 'u8FRL_Rate_SetInPhy' */
#define LTS_BYTE_3B             0x3b
#define LTS_BYTE_3C             0x3c

/* Block 6 of the receiver's registers. */
#define BLOCK6_RS_ERRORS        0xd     /* bits 0..14 printed as "RS err"; writing 0xffff to bits 0..15 follows each read */
#define BLOCK6_LOCK_WEIGHT      5       /* bits 0..2 and 4..6: the lock weighting (see FRL_Init) */
#define BLOCK6_REG_90           (0x90 / 4)
#define FLT_NO_RETRAIN_BIT      0x11    /* in BLOCK6_REG_90; the runner prints "FLT_no_retrain" on it too */
/* Block 8 of the receiver's registers. */
#define BLOCK8_PACKETS          0xa     /* bits 0..15 printed as "pkt" */

#define RS_ERRORS_BAD           0x3fff  /* more errors than this count as a bad pass */
#define BAD_PASSES_MAX          0x13    /* more bad passes than this restart the link training */
#define PAYLOAD_MAX             0x7a4   /* a measured payload of 0 or above this is measured again */
#define PAYLOAD_DRIFT_MAX       29      /* largest change between two measurements that counts as stable */

/* Register block addresses of one HDMI 2.1 receiver (0x34 bytes, hdmi_rx21_reg_blocks). */
struct rx21_reg_blocks {
    volatile unsigned int *block0;
    unsigned int blocks_1_to_5[5];
    volatile unsigned int *block6;
    unsigned int block7;
    volatile unsigned int *block8;
    unsigned char blocks_9_to_12[0x34 - 0x24];
};
/* Mode-detection state of one HDMI 2.1 receiver (24 bytes). */
struct rx21_mode_detect_state {
    unsigned int state;
    unsigned char byte_0x4;
    unsigned char _5[0x18 - 5];
};
/* HDMI PHY record (the PHY link table entry, 24 bytes per PHY, hdmi_phy_records). */
struct hdmi_phy_record {
    unsigned char power;
    unsigned char eq_done;              /* read by hdmi_phy_is_eq_done; the EQ scan sets it at its end */
    unsigned char _2[0x18 - 2];
};
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern unsigned int hdmi_rx21_rx_detect_states[];
extern struct rx21_mode_detect_state hdmi_rx21_mode_detect_states[];
extern unsigned char hdmi_rx21_lts_records[];        /* link-training records */
extern struct hdmi_phy_record hdmi_phy_records[];
extern unsigned int hdmi_rx21_frl_payload_ticks[];
extern unsigned int hdmi_rx21_frl_payload_words[];
extern unsigned char hdmi_rx21_frl_payload_bytes[];
extern unsigned char hdmi_rx21_frl_init_flags[];
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);
extern unsigned int reg_test_bit(unsigned int, volatile unsigned int *);
extern unsigned int hdmi_rx21_measure_payload_delay(unsigned char);
extern void FRL_PLL(unsigned int, unsigned int);
extern void reg_set_bit(unsigned int, volatile unsigned int *);
extern void reg_clear_bit(unsigned int, volatile unsigned int *);
extern void timer_delay_long_units(unsigned short);

/*
 * Mode-detection state 2 of an HDMI 2.1 receiver: check the FRL payload. FRL_Init (state 1) leads here.
 *
 *   port_number  HDMI 2.1 receiver 0 or 1 (printed as the letter 'A' + port)
 *
 * Always returns 0, so hdmi_rx21_run_mode_detect_fsm runs the next state on its next call.
 * Per-receiver data: hdmi_rx21_frl_payload_ticks = this pass's payload measurement,
 * hdmi_rx21_frl_payload_words = the previous pass's, hdmi_rx21_frl_payload_bytes = count of bad passes.
 *
 * Phases:
 *  1. With the FLT_no_retrain bit set, do nothing. Unless the link training is in LTS_Chk_Stable (9), the
 *     state is set to 0 (and stays 0 where no later phase sets it).
 *  2. Measure: read and reset the RS error count, measure the payload (hdmi_rx21_measure_payload_delay).
 *  3. More than 0x3FFF errors: count a bad pass and check again (state 2); after more than 19 bad passes
 *     send the link training back to LTS_3, the mode detection to state 0, clear the PHY link table
 *     entry's eq_done byte (entry number = receiver number) and the link-training FRL_Rate_SetInPhy byte.
 *  4. A payload of 0 or above 0x7A4: measure again (state 2).
 *  5. A payload within 29 of the previous one: set the FRL PLL for it, pulse bit 8 of block 0 word 1 and go
 *     to the FRL lock check (state 3). With an FRL rate above 4, a payload of 100 or less and lock
 *     weighting 3 in both fields, set hdmi_rx21_frl_init_flags (FRL_Init then uses weighting 2) and go to
 *     state 0 instead. Otherwise print "FRL Preload_unstable".
 *  6. Keep this payload as the previous one.
 */
int DRV_HDMI_ModeDetect_FSM_FRL_Payload(unsigned int port_number)
{
    unsigned char port;
    unsigned char *lts;
    unsigned char *lts_in_range;
    unsigned int rs_errors;
    int drift;

    /* Phase 1 */
    dbg_printf("Port%c DRV_HDMI_ModeDetect_FSM_FRL_Payload\n", (char)(port_number + 'A'));
    port = port_number;
    if (reg_test_bit(FLT_NO_RETRAIN_BIT, hdmi_rx21_reg_blocks[port].block6 + BLOCK6_REG_90) != 0) {
        dbg_print_string("FLT_no_retrain, don't do anything\n");
        return 0;
    }
    if (hdmi_rx21_rx_detect_states[port] != RX_DETECT_LTS_CHK_STABLE) {
        hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_WAIT_EQ_END;
        dbg_printf("check stand by%d\r\n", 3);
    }

    /* Phase 2: error count and payload. */
    rs_errors = hdmi_rx21_reg_blocks[port].block6[BLOCK6_RS_ERRORS] & 0x7fff;
    dbg_printf("RS err=0x%04X, pkt=0x%04X\n", rs_errors, hdmi_rx21_reg_blocks[port].block8[BLOCK8_PACKETS] & 0xffff);
    hdmi_rx21_frl_payload_ticks[port] = hdmi_rx21_measure_payload_delay(port);     /* hdmi_rx21_measure_payload_delay */
    hdmi_rx21_reg_blocks[port].block6[BLOCK6_RS_ERRORS] |= 0xffff;

    if (rs_errors > RS_ERRORS_BAD) {
        /* Phase 3: too many errors. */
        if (++hdmi_rx21_frl_payload_bytes[port] > BAD_PASSES_MAX) {
            hdmi_rx21_frl_payload_bytes[port] = 0;
            if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
                dbg_print_string("[MODEDET]: Trigger FRL Packets abnormal handling flow\n");
            lts = hdmi_rx21_lts_records + port * LTS_RECORD_SIZE;
            hdmi_rx21_rx_detect_states[port] = RX_DETECT_LTS_3;
            hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_WAIT_EQ_END;
            hdmi_phy_records[port].eq_done = 0;
            lts[LTS_FRL_RATE_IN_PHY] = 0;
        } else
            hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_FRL_PAYLOAD;
    } else if (hdmi_rx21_frl_payload_ticks[port] == 0 || hdmi_rx21_frl_payload_ticks[port] > PAYLOAD_MAX) {
        /* Phase 4: no usable measurement. */
        hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_FRL_PAYLOAD;
    } else {
        /* Phase 5: a payload close to the previous one is stable. */
        drift = hdmi_rx21_frl_payload_ticks[port] - hdmi_rx21_frl_payload_words[port];
        if (drift >= -PAYLOAD_DRIFT_MAX) {
            if (drift <= PAYLOAD_DRIFT_MAX) {
                FRL_PLL(port, hdmi_rx21_frl_payload_ticks[port]);
                hdmi_rx21_reg_blocks[port].block8[0x20] |= 7;
                reg_set_bit(8, hdmi_rx21_reg_blocks[port].block0 + 1);
                timer_delay_long_units(1);
                reg_clear_bit(8, hdmi_rx21_reg_blocks[port].block0 + 1);
                lts_in_range = hdmi_rx21_lts_records + port * LTS_RECORD_SIZE;
                lts_in_range[LTS_BYTE_3B] = 0;
                hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_FRL_CHK;
                lts_in_range[LTS_BYTE_3C] = 0;
                if (lts_in_range[LTS_FRL_RATE] > 4 && hdmi_rx21_frl_payload_ticks[port] <= 0x64 && (hdmi_rx21_reg_blocks[port].block6[BLOCK6_LOCK_WEIGHT] & 0x7f) == 0x33) {
                    hdmi_rx21_frl_init_flags[port] = 1;
                    hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_WAIT_EQ_END;
                }
            } else {
                if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
                    dbg_print_string("[MODEDET]: FRL Preload_unstable\n");
            }
        } else {
            if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
                dbg_print_string("[MODEDET]: FRL Preload_unstable\n");
        }
    }

    /* Phase 6 */
    hdmi_rx21_frl_payload_words[port] = hdmi_rx21_frl_payload_ticks[port];
    return 0;
}
