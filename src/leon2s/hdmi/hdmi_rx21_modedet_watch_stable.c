/* hdmi_rx21_modedet_watch_stable  (FUN_a009d2f8)
 *
 * Watch a stable HDMI 2.1 input for DSC, VRR and timing changes (mode-detect state 8).
 *   port: HDMI 2.1 receiver 0/1
 * Returns: 0
 * Name basis: derived - state 8 of table 0xA00B4258; 'HDMI 21 DSC Port%c modechange', 'dsc mode changed, frame
 *   cnt diff'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009d2f8 @ 0xa009d2f8-0xa009d5cc, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the first block indexes with rx (the port's low byte), the event16_seen block with 'port & 0xff' in each
 *    access, then port itself is masked and used for the rest;
 *  - the second frame count read uses its own local (new_frame_count); unused stays declared;
 *  - hdmi_rx21_stable_watch_ticks is declared unsigned long (alias set);
 *  - the later callees are declared with unsigned int parameters (the firmware passes the masked port as is).
 */
/* One row per HDMI 2.1 receiver (hdmi_rx21_reg_blocks): the addresses of its register blocks. */
struct hdmi_rx21_reg_blocks {
    volatile unsigned int *block0;
    unsigned char blocks_1_to_12[0x30];
};
/* The 400-byte record of an HDMI 2.1 receiver (hdmi_rx21_input_records), fields used here. */
struct rx21_record {
    unsigned char bytes_0x0[6];
    unsigned char vrr_flags;            /* +6: written by hdmi_rx21_detect_vrr_signalling */
    unsigned char event16_seen;         /* +7: 1 when receiver event 0x16 was pending in the last event pass */
    unsigned char bytes_0x8[0x10];
    unsigned char hdmi_mode;            /* +0x18: the HDMI/DVI bit (hdmi_rx21_status30_bit4) as stored */
    unsigned char bytes_0x19[0x2d - 0x19];
    unsigned char cvtem_present;        /* +0x2D: hdmi_rx21_has_cvtem as stored by the Complete state */
    unsigned char rest[0x190 - 0x2e];
};
/* Mode detection state of one HDMI 2.1 receiver (hdmi_rx21_mode_detect_states, 0x18 bytes). */
struct rx21_mode_detect_state {
    unsigned int state;                 /* MODEDET_STATE_* */
    unsigned char bytes_0x4[5];
    unsigned char byte_0x9;             /* set to 0xF by FSM_MODE_DETECT_STANDBY */
    unsigned char mode_change_flag;     /* +0xA: makes hdmi_rx21_detect_timing_change report a change */
    unsigned char rest[0x18 - 0xb];
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern struct rx21_record hdmi_rx21_input_records[];
extern struct rx21_mode_detect_state hdmi_rx21_mode_detect_states[];
extern unsigned char hdmi_rx21_modedet_stable_flags[];  /* last event16_seen; cleared by the Complete state */
extern unsigned char hdmi_rx21_stable_watch_bytes[];    /* 1 once the reference frame count is taken */
extern unsigned int hdmi_rx21_stable_watch_words[];     /* reference frame count */
extern unsigned long hdmi_rx21_stable_watch_ticks[];    /* allowed difference: reference / 333 */
extern int dbg_printf(const char *, ...);
extern void hdmi_rx21_update_port_mode(unsigned char);
extern int hdmi_rx21_read_avi_type(unsigned char);
extern unsigned char hdmi_rx21_has_cvtem(unsigned int);
extern void hdmi_rx21_detect_vrr_signalling(unsigned char);
extern void hdmi_rx21_service_packet_events(unsigned int);
extern unsigned char hdmi_rx21_detect_timing_change(unsigned int);
extern void hdmi_rx21_clear_mode_status(unsigned int);
extern void hdmi_rx21_update_packet_forward_bit(unsigned int);

enum {
    MODEDET_STATE_WAIT_EQ_END = 0,      /* hdmi_rx21_modedet_wait_eq_done: detection starts again */
    MODEDET_STATE_COMPLETE    = 7       /* DRV_HDMI_ModeDetect_FSM_Complete */
};

#define INFOFRAME_TYPE_AVI          0x82
#define BLOCK0_FRAME_COUNT          (0x98 / 4)  /* word +0x98 of block 0, the 'frame cnt' of the print */
#define FRAME_COUNT_DIVISOR         333         /* allowed difference = reference / 333 */

/*
 * State 8 (MODEDET_STATE_WATCH_STABLE) of the HDMI 2.1 mode detection: the input has been detected; watch it
 * for anything that asks for a new detection. Run through the state table of hdmi_rx21_run_mode_detect_fsm.
 *
 *   port   HDMI 2.1 receiver 0 or 1
 *
 * Returns 0 (the state machine stops for this pass).
 *
 * In order:
 *  1. hdmi_rx21_update_port_mode.
 *  2. When hdmi_mode is 1: byte_0x9 of the state counts down by one while the AVI area does not hold an AVI
 *     InfoFrame (type 0x82); a CVTEM packet that came or went since the Complete state prints
 *     'HDMI 21 DSC Port%c modechange' and sets mode_change_flag; the VRR flags are read again.
 *  3. When event16_seen changed since the last call: a change from 1 to 0 sends the detection to
 *     MODEDET_STATE_COMPLETE. The new value is kept in hdmi_rx21_modedet_stable_flags.
 *  4. hdmi_rx21_service_packet_events; a timing change reported by hdmi_rx21_detect_timing_change sends the
 *     detection back to MODEDET_STATE_WAIT_EQ_END.
 *  5. Without VRR flags and with a CVTEM packet: the frame count of block 0 is compared with a reference
 *     taken the first time. When they differ by more than reference / 333, a new reference is taken, the
 *     detected-mode flags are cleared, the detection goes back to MODEDET_STATE_WAIT_EQ_END and
 *     'dsc mode changed, frame cnt diff > %ld' is printed with the new allowed difference.
 *  6. hdmi_rx21_update_packet_forward_bit.
 */
int hdmi_rx21_modedet_watch_stable(unsigned int port)
{
    unsigned char rx = port;
    unsigned int frame_count, new_frame_count;
    int count_diff, unused;

    hdmi_rx21_update_port_mode(rx);
    if (hdmi_rx21_input_records[rx].hdmi_mode == 1) {
        if (hdmi_rx21_read_avi_type(rx) != INFOFRAME_TYPE_AVI) {
            if (hdmi_rx21_mode_detect_states[rx].byte_0x9 != 0)
                hdmi_rx21_mode_detect_states[rx].byte_0x9--;
        }
        if (hdmi_rx21_has_cvtem(rx) != hdmi_rx21_input_records[rx].cvtem_present) {
            dbg_printf("HDMI 21 DSC Port%c modechange\r\n", (char)(port + 'A'));
            hdmi_rx21_mode_detect_states[rx].mode_change_flag = 1;
        }
        hdmi_rx21_detect_vrr_signalling(rx);
    }
    if (hdmi_rx21_input_records[port & 0xff].event16_seen != hdmi_rx21_modedet_stable_flags[port & 0xff]) {
        if (hdmi_rx21_modedet_stable_flags[port & 0xff] == 1 && hdmi_rx21_input_records[port & 0xff].event16_seen == 0)
            hdmi_rx21_mode_detect_states[port & 0xff].state = MODEDET_STATE_COMPLETE;
        hdmi_rx21_modedet_stable_flags[port & 0xff] = hdmi_rx21_input_records[port & 0xff].event16_seen;
    }
    port &= 0xff;
    hdmi_rx21_service_packet_events(port);
    if (hdmi_rx21_detect_timing_change(port) == 1)
        hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_WAIT_EQ_END;
    if (hdmi_rx21_input_records[port].vrr_flags == 0 && hdmi_rx21_has_cvtem(port)) {
        if (hdmi_rx21_stable_watch_bytes[port] == 0) {
            frame_count = ARR_a807db00[port].block0[BLOCK0_FRAME_COUNT];
            hdmi_rx21_stable_watch_words[port] = frame_count;
            hdmi_rx21_stable_watch_ticks[port] = frame_count / FRAME_COUNT_DIVISOR;
            hdmi_rx21_stable_watch_bytes[port] = 1;
        }
        count_diff = hdmi_rx21_stable_watch_words[port] - ARR_a807db00[port].block0[BLOCK0_FRAME_COUNT];
        if ((unsigned int)__builtin_abs(count_diff) > hdmi_rx21_stable_watch_ticks[port]) {
            new_frame_count = ARR_a807db00[port].block0[BLOCK0_FRAME_COUNT];
            hdmi_rx21_stable_watch_ticks[port] = new_frame_count / FRAME_COUNT_DIVISOR;
            hdmi_rx21_stable_watch_words[port] = new_frame_count;
            hdmi_rx21_clear_mode_status(port);
            hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_WAIT_EQ_END;
            dbg_printf("dsc mode changed, frame cnt diff > %ld\r\n", hdmi_rx21_stable_watch_ticks[port]);
        }
    }
    hdmi_rx21_update_packet_forward_bit(port);
    return 0;
}
