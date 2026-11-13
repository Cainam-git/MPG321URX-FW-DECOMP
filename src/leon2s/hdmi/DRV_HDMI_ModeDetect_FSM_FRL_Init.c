/* DRV_HDMI_ModeDetect_FSM_FRL_Init  (DRV_HDMI_ModeDetect_FSM_FRL_Init)
 *
 * Run the FRL start state of the HDMI 2.1 mode-detect state machine.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: proven - original name printed ('With Check Reset Flow DRV_HDMI_ModeDetect_FSM_FRL_Init')
 *
 * Matching notes
 * --------------
 * DRV_HDMI_ModeDetect_FSM_FRL_Init (leon2s 0xa0096b08-0xa0096f60, 1112 bytes), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - the register blocks are reached through volatile pointers (every read-modify-write reloads);
 *  - the FRL rate test is 'int low = (u8)(rate - 1) < 2, rate_10 = rate == 10; if (low | rate_10)' (flag
 *    arithmetic, not '||');
 *  - the last four stores are written in the order that schedules to the firmware's order.
 */

/* Message groups of dbg_hdmi_message_flags. */
#define HDMI_MSG_MODEDET_FLOW   0x04

/* States of the mode detection (index of the table hdmi_rx21_run_mode_detect_fsm runs). */
#define MODEDET_STATE_WAIT_EQ_END   0   /* hdmi_rx21_modedet_wait_eq_done */
#define MODEDET_STATE_FRL_PAYLOAD   2   /* DRV_HDMI_ModeDetect_FSM_FRL_Payload */

/* Link-training state (hdmi_rx21_rx_detect_states) in which the mode detection keeps its state. */
#define RX_DETECT_LTS_CHK_STABLE    9   /* DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable */

/* Link-training record of each receiver (0xb0 bytes, hdmi_rx21_lts_records): byte 1 is the FRL rate. */
#define LTS_RECORD_SIZE         0xb0
#define LTS_FRL_RATE            1

/* Bits 0..2 and 4..6 of block 6 word 5: the lock weighting ("Set lock Weighting to 0x7"). */
#define LOCK_WEIGHT_LOW         0x07
#define LOCK_WEIGHT_HIGH        0x70

/* Register block addresses of one HDMI 2.1 receiver (0x34 bytes, hdmi_rx21_reg_blocks). */
struct rx21_reg_blocks {
    volatile unsigned int *block0;
    unsigned int blocks_1_to_2[2];
    volatile unsigned int *block3;
    unsigned int blocks_4_to_5[2];
    volatile unsigned int *block6;
    unsigned char blocks_7_to_12[0x34 - 0x1c];
};
/* Mode-detection state of one HDMI 2.1 receiver (24 bytes). */
struct rx21_mode_detect_state {
    unsigned int state;
    unsigned char byte_0x4;
    unsigned char _5[0x18 - 5];
};
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern unsigned int hdmi_rx21_rx_detect_states[];
extern struct rx21_mode_detect_state hdmi_rx21_mode_detect_states[];
extern unsigned char hdmi_rx21_lts_records[];        /* link-training records */
extern unsigned char hdmi_rx21_two_port_mode_flags[];
extern unsigned char hdmi_rx21_frl_lock_flags[];
extern unsigned char hdmi_rx21_frl_init_flags[];
extern unsigned int hdmi_rx21_frl_payload_words[];
extern unsigned int hdmi_rx21_frl_payload_ticks[];
extern unsigned char hdmi_rx21_frl_payload_bytes[];
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);
extern void reg_clear_bit(unsigned int bit, volatile unsigned int *p);
extern void reg_set_bit(unsigned int bit, volatile unsigned int *p);
extern void timer_delay_units(unsigned int);

/*
 * Mode-detection state 1 of an HDMI 2.1 receiver: set up the receiver's FRL registers and go to the payload
 * check (state 2).
 *
 *   port  HDMI 2.1 receiver 0 or 1 (printed as the letter 'A' + port)
 *
 * Always returns 0, so hdmi_rx21_run_mode_detect_fsm runs the next state on its next call.
 *
 * Phases:
 *  1. Unless the link training is in LTS_Chk_Stable (9) the state is set to 0; this is overwritten in
 *     phase 4, so the routine always leaves state 2. hdmi_rx21_two_port_mode_flags (the shift that
 *     hdmi_rx21_update_mode_info and the standby state apply to the horizontal values) is cleared.
 *  2. Block 0 and block 6 control bits; bit 8 of block 6 word 0 is cleared for FRL rates 1, 2 and 10 and
 *     set for the others.
 *  3. Lock weighting in block 6 word 5: 7 after hdmi_rx21_frl_lock_flags was set, 2 after
 *     hdmi_rx21_frl_init_flags was set (the payload check sets it), else 3; both flags are cleared.
 *  4. A fixed sequence of field writes to block 6 words 3..6 and 0x10..0x14 and block 3 word 0x19, with
 *     a pulse on bit 29 of block 6 word 5; then the payload check's values are cleared and the state is 2.
 */
int DRV_HDMI_ModeDetect_FSM_FRL_Init(unsigned char port)
{
    volatile unsigned int *block6;
    unsigned char frl_rate;
    int low_rate, rate_10;

    /* Phase 1 */
    if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
        dbg_printf("[MODEDET]: Port%c With Check Reset Flow DRV_HDMI_ModeDetect_FSM_FRL_Init\n",
                     (char)(port + 'A'));
    if (hdmi_rx21_rx_detect_states[port] != RX_DETECT_LTS_CHK_STABLE)
        hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_WAIT_EQ_END;
    hdmi_rx21_two_port_mode_flags[port] = 0;

    /* Phase 2: control bits; one of them depends on the FRL rate. */
    reg_clear_bit(0xc, hdmi_rx21_reg_blocks[port].block0 + 2);
    reg_set_bit(0xd, hdmi_rx21_reg_blocks[port].block0 + 2);
    reg_clear_bit(0xf, hdmi_rx21_reg_blocks[port].block0 + 2);
    reg_clear_bit(0x14, hdmi_rx21_reg_blocks[port].block0 + 0x21);
    frl_rate = hdmi_rx21_lts_records[port * LTS_RECORD_SIZE + LTS_FRL_RATE];
    low_rate = (unsigned char)(frl_rate - 1) < 2;
    rate_10 = frl_rate == 10;
    if (low_rate | rate_10)
        reg_clear_bit(8, hdmi_rx21_reg_blocks[port].block6);
    else
        reg_set_bit(8, hdmi_rx21_reg_blocks[port].block6);
    reg_set_bit(0xd, hdmi_rx21_reg_blocks[port].block6);
    reg_set_bit(0xc, hdmi_rx21_reg_blocks[port].block6);
    hdmi_rx21_reg_blocks[port].block6[1] = (hdmi_rx21_reg_blocks[port].block6[1] & 0xffff) | 0x34000000;
    reg_set_bit(0xb, hdmi_rx21_reg_blocks[port].block0 + 2);
    reg_clear_bit(1, hdmi_rx21_reg_blocks[port].block6 + 3);
    reg_set_bit(3, hdmi_rx21_reg_blocks[port].block6 + 3);

    /* Phase 3: lock weighting, chosen by what the earlier passes left. */
    if (hdmi_rx21_frl_lock_flags[port] == 1) {
        hdmi_rx21_reg_blocks[port].block6[5] |= 7;
        hdmi_rx21_reg_blocks[port].block6[5] |= 0x70;
        dbg_print_string("Set lock Weighting to 0x7 !!");
    } else if (hdmi_rx21_frl_init_flags[port] == 1) {
        hdmi_rx21_reg_blocks[port].block6[5] = (hdmi_rx21_reg_blocks[port].block6[5] & ~LOCK_WEIGHT_LOW) | 2;
        hdmi_rx21_reg_blocks[port].block6[5] = (hdmi_rx21_reg_blocks[port].block6[5] & ~LOCK_WEIGHT_HIGH) | 0x20;
    } else {
        hdmi_rx21_reg_blocks[port].block6[5] = (hdmi_rx21_reg_blocks[port].block6[5] & ~LOCK_WEIGHT_LOW) | 3;
        hdmi_rx21_reg_blocks[port].block6[5] = (hdmi_rx21_reg_blocks[port].block6[5] & ~LOCK_WEIGHT_HIGH) | 0x30;
    }
    hdmi_rx21_frl_lock_flags[port] = 0;
    hdmi_rx21_frl_init_flags[port] = 0;

    /* Phase 4: fixed FRL settings. */
    hdmi_rx21_reg_blocks[port].block6[3] = (hdmi_rx21_reg_blocks[port].block6[3] & 0xfe00ffff) | 0x200000;
    hdmi_rx21_reg_blocks[port].block6[4] = (hdmi_rx21_reg_blocks[port].block6[4] & ~0x1ff) | 0x20;
    hdmi_rx21_reg_blocks[port].block6[5] = (hdmi_rx21_reg_blocks[port].block6[5] & 0xfe00ffff) | 0x10000;
    reg_set_bit(0xe, hdmi_rx21_reg_blocks[port].block6);
    hdmi_rx21_reg_blocks[port].block6[0x11] = (hdmi_rx21_reg_blocks[port].block6[0x11] & 0xffffff) | 0xb8000000;
    hdmi_rx21_reg_blocks[port].block6[0x12] &= ~0xff;
    hdmi_rx21_reg_blocks[port].block6[4] = (hdmi_rx21_reg_blocks[port].block6[4] & 0xffff81ff) | 0x400;
    hdmi_rx21_reg_blocks[port].block6[0x13] = (hdmi_rx21_reg_blocks[port].block6[0x13] & 0xffff0000) | 0x100;
    reg_set_bit(8, hdmi_rx21_reg_blocks[port].block6 + 0x12);
    hdmi_rx21_reg_blocks[port].block6[0x13] = (hdmi_rx21_reg_blocks[port].block6[0x13] & 0xffffff) | 0x3000000;
    hdmi_rx21_reg_blocks[port].block6[4] = (hdmi_rx21_reg_blocks[port].block6[4] & ~0x1ff) | 4;
    hdmi_rx21_reg_blocks[port].block6[4] = (hdmi_rx21_reg_blocks[port].block6[4] & 0xffff81ff) | 0xa00;
    hdmi_rx21_reg_blocks[port].block6[4] = (hdmi_rx21_reg_blocks[port].block6[4] & ~0x7f0000) | 0x70000;
    hdmi_rx21_reg_blocks[port].block6[4] = (hdmi_rx21_reg_blocks[port].block6[4] & ~0x7f000000) | 0x5000000;
    hdmi_rx21_reg_blocks[port].block6[6] = (hdmi_rx21_reg_blocks[port].block6[6] & ~0xf) | 3;
    hdmi_rx21_reg_blocks[port].block6[0x10] = (hdmi_rx21_reg_blocks[port].block6[0x10] & 0xff0000ff) | 0x80000;
    reg_clear_bit(8, hdmi_rx21_reg_blocks[port].block6 + 0x1b);
    reg_set_bit(0x1d, hdmi_rx21_reg_blocks[port].block6 + 5);
    timer_delay_units(1);
    reg_clear_bit(0x1d, hdmi_rx21_reg_blocks[port].block6 + 5);
    hdmi_rx21_reg_blocks[port].block3[0x19] = (hdmi_rx21_reg_blocks[port].block3[0x19] & ~0xff0000) | 0xff0000;
    block6 = hdmi_rx21_reg_blocks[port].block6;
    block6[0x14] = 0x1000;
    block6[0x10] &= 0xffffff;
    block6[0x11] = (block6[0x11] & ~0xff) | 0x60;
    /* The payload check starts without a previous measurement. */
    hdmi_rx21_frl_payload_ticks[port] = 0;
    hdmi_rx21_frl_payload_words[port] = 0;
    hdmi_rx21_frl_payload_bytes[port] = 0;
    hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_FRL_PAYLOAD;
    return 0;
}
