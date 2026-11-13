/* DRV_HDMI_ModeDetect_FSM_Complete  (DRV_HDMI_ModeDetect_FSM_Complete)
 *
 * Finish mode detection: read the mode, InfoFrames and clocks, then report sync stable.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: proven - original name printed ('Port%c DRV_HDMI_ModeDetect_FSM_Complete'); 'No AVI Info', 'Sync
 *   Stable'; state 7
 *
 * Matching notes
 * --------------
 * DRV_HDMI_ModeDetect_FSM_Complete (leon2s, 0xa009e368-0xa009e9a4, 1596 bytes), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - each packet test is written 'if (read != 0) { print } else { flags }' with the higher-placed status
 *    byte stored first;
 *  - lib_memset is declared returning its destination pointer and hdmi_rx21_calc_frame_rate returning int:
 *    both return types change the order in which the arguments are set up before the calls.
 */

/* Message groups of dbg_hdmi_message_flags. */
#define HDMI_MSG_INIT_INFO      0x01
#define HDMI_MSG_MODEDET_FLOW   0x04    /* every "[MODEDET]" line */

/* States of the mode detection: the index into the table hdmi_rx21_run_mode_detect_fsm runs. */
#define MODEDET_STATE_STANDBY       5   /* FSM_MODE_DETECT_STANDBY */
#define MODEDET_STATE_WATCH_STABLE  8   /* hdmi_rx21_modedet_watch_stable */

#define MODEDET_COUNT_MAX       10      /* upper limit of hdmi_rx21_stable_count_limits */
#define HDMI_MODE_HDMI          1       /* hdmi_mode value with which the packets are read */

/* Bits of the receiver's register blocks, used with reg_set_bit / reg_clear_bit (bit, address). */
#define BLOCK0_REG_B4           0xb4
#define BLOCK0_REG_B8           0xb8
#define BLOCK1_REG_34           0x34
#define BLOCK6_FRL_RATE         (0x90 / 4)  /* bits 24..27: printed as the FRL mode */

/* Each packet block of the receiver record ends in three status bytes. The last one 0 lets this routine
   read the packet; a successful read sets the two before it to 1. */
struct avi_block {                  /* +0x4c: the AVI data (struct avi_info of hdmi_rx21_read_avi_infoframe) */
    unsigned int header;
    unsigned int color_format;      /* printed as "Color format" (0 RGB, 1 422, 2 444, 3 420) */
    unsigned char fields[0x4d];
    unsigned char byte_0x55, byte_0x56, byte_0x57;
};
struct block_0xa4 { unsigned char bytes[0x18]; };
struct audio_infoframe_block {      /* +0xbc */
    unsigned char data[0x2a];
    unsigned char byte_0x2a, byte_0x2b, byte_0x2c;
    unsigned char _2d[3];
};
struct spd_infoframe_block {        /* +0xec */
    unsigned char data[0x20];
    unsigned char byte_0x20, byte_0x21, byte_0x22;
    unsigned char _23;
};
struct hdr_infoframe_block {        /* +0x114 (struct hdr_info of hdmi_rx21_read_hdr_infoframe) */
    unsigned char data[0x43];
    unsigned char byte_0x43, byte_0x44, byte_0x45;
    unsigned char _46[2];
};
struct audio_stream_block {         /* +0x162 */
    unsigned char data[0x1f];
    unsigned char byte_0x1f, byte_0x20, byte_0x21;
};
struct cvtem_block {                /* +0x184 */
    unsigned char data[2];
    unsigned char byte_0x2, byte_0x3, byte_0x4;
};

/* The record of one HDMI 2.1 receiver (400 bytes, hdmi_rx21_input_records). */
struct rx21_record {
    unsigned char byte_0x0;
    unsigned char mode_detected;
    unsigned char _02[2];
    unsigned char byte_0x4;
    unsigned char byte_0x5;
    unsigned char vrr_flags;            /* set by hdmi_rx21_detect_vrr_signalling */
    unsigned char event16_seen;
    unsigned char _08[0x10];
    unsigned char hdmi_mode;            /* +0x18: start of the mode info hdmi_rx21_update_mode_info fills */
    unsigned char _19[0x14];
    unsigned char cvtem_present;        /* +0x2d: hdmi_rx21_has_cvtem at the last completion */
    unsigned char _2e[4];
    unsigned short pixel_clock;         /* +0x32: in 0.1 MHz */
    unsigned char _34[0x18];
    struct avi_block avi;
    struct block_0xa4 block_0xa4;
    struct audio_infoframe_block audio_infoframe;
    struct spd_infoframe_block spd_infoframe;
    unsigned char _110[4];
    struct hdr_infoframe_block hdr_infoframe;
    unsigned char byte_0x15c;
    unsigned char _15d[5];
    struct audio_stream_block audio_stream;
    struct cvtem_block cvtem;
    unsigned char _189[7];
};

/* Register block addresses of one HDMI 2.1 receiver (0x34 bytes, hdmi_rx21_reg_blocks). */
struct rx21_reg_blocks {
    unsigned int block0;
    unsigned int block1;
    unsigned int blocks_2_to_5[4];
    volatile unsigned int *block6;
    unsigned char blocks_7_to_12[0x34 - 0x1c];
};

/* Mode-detection state of one HDMI 2.1 receiver (24 bytes). */
struct rx21_mode_detect_state {
    unsigned int state;                 /* MODEDET_STATE_* */
    unsigned char _4[6];
    unsigned char mode_change_flag;     /* printed 'Int Set Mode Change' where it is set */
    unsigned char byte_0xb;
    unsigned char _c[8];
    unsigned char avi_byte30_changed;   /* set when the packet service saw AVI byte_0x30 change */
    unsigned char _15[3];
};
extern struct rx21_record hdmi_rx21_input_records[];
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern struct rx21_mode_detect_state hdmi_rx21_mode_detect_states[];
extern unsigned int dbg_hdmi_message_flags;
extern unsigned char hdmi_rx21_vrr_was_on_flags[];
extern unsigned char hdmi_rx21_modedet_stable_flags[];
extern unsigned char hdmi_rx21_stable_watch_bytes[];
extern unsigned char hdmi_rx21_stable_count_limits[];

extern int dbg_printf(const char *, ...);
extern unsigned char hdmi_rx21_has_cvtem(unsigned char);
extern void reg_set_bit(unsigned int, int);
extern void reg_clear_bit(unsigned int, int);
extern unsigned char hdmi_rx21_update_mode_info(unsigned char, unsigned char *, unsigned char);
extern void hdmi_rx21_clear_detect_flags(unsigned char);
extern void hdmi_rx21_clear_status_flags(unsigned int);
extern unsigned char hdmi_rx21_read_avi_infoframe(unsigned char, struct avi_block *);
extern unsigned char hdmi_rx21_read_audio_infoframe(unsigned char, struct audio_infoframe_block *);
extern unsigned char hdmi_rx21_read_spd_infoframe(unsigned char, struct spd_infoframe_block *);
extern unsigned char hdmi_rx21_read_hdr_infoframe(unsigned char, struct hdr_infoframe_block *);
extern unsigned char hdmi_rx21_read_audio_stream_packet(unsigned char, struct audio_stream_block *);
extern unsigned char hdmi_rx21_read_cvtem(unsigned char, struct cvtem_block *);
extern void *lib_memset(unsigned char *, unsigned char, int);
extern unsigned short hdmi_rx21_calc_tmds_clock(unsigned char);
extern void hdmi_rx21_clear_all_events(unsigned int);
extern void DRV_HDMI_Setup_IntIRQ_Events(unsigned int, unsigned int);
extern void hdmi_rx21_enable_sync_events(unsigned int, unsigned int);
extern void hdmi_rx21_set_ctrl_bits_1b_18(unsigned char, unsigned char);
extern int hdmi_rx21_calc_frame_rate(unsigned char, unsigned int *, unsigned int *);
extern void DRV_HDMI_Set_AudStatus(unsigned char, unsigned char);
extern unsigned int timer_get_ticks(void);

/*
 * Mode-detection state 7 of an HDMI 2.1 receiver. The settle state (6) leads here.
 *
 *   port  HDMI 2.1 receiver 0 or 1 (printed as the letter 'A' + port)
 *
 * Returns 0 when the mode info is not valid (back to standby, state 5), else 1 with state 8 (watch the
 * stable input).
 *
 * Phases:
 *  1. Mode info: note whether a CVTEM packet is present (then bit 2 of block 0 register 0xB4 is cleared)
 *     and let hdmi_rx21_update_mode_info fill and check the mode info at +0x18; not valid: state 5.
 *  2. Reset of the per-input flags: timing change flag = vrr_flags != 0, the stable flags cleared, a pulse
 *     on bit 28 of block 1 register 0x34, mode_detected = 1, the detect and status flags cleared.
 *  3. Packets: in HDMI mode, read each of AVI, audio InfoFrame, SPD, HDR InfoFrame, audio stream and CVTEM
 *     whose block allows it, printing "No ..." when it is missing; otherwise clear all those blocks.
 *  4. Report: print the FRL mode, the pixel and TMDS clocks and the colour format.
 *  5. Switch to normal running: bit 24 of block 0 register 0xB8 set, pending events cleared, the count limit
 *     of the standby state capped at 10, the interrupt and sync events enabled, "Sync Stable" printed, the
 *     frame rate computed (its results are not used here), the audio marked stable, state 8.
 */
int DRV_HDMI_ModeDetect_FSM_Complete(unsigned char port)
{
    unsigned int line_rate = 0;         /* results of hdmi_rx21_calc_frame_rate, not used */
    unsigned int frame_rate = 0;
    unsigned int compressed = 0;

    if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
        dbg_printf("[MODEDET]: Port%c DRV_HDMI_ModeDetect_FSM_Complete\n", (char)(port + 0x41));

    /* Phase 1: read and check the mode. */
    if (hdmi_rx21_has_cvtem(port) != 0) {
        hdmi_rx21_input_records[port].cvtem_present = 1;
        reg_clear_bit(2, hdmi_rx21_reg_blocks[port].block0 + BLOCK0_REG_B4);
        compressed = 1;
    } else
        hdmi_rx21_input_records[port].cvtem_present = 0;
    if (hdmi_rx21_update_mode_info(port, &hdmi_rx21_input_records[port].hdmi_mode, compressed) == 0) {
        hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_STANDBY;
        return 0;
    }

    /* Phase 2: start the input's flags afresh. */
    hdmi_rx21_vrr_was_on_flags[port] = hdmi_rx21_input_records[port].vrr_flags != 0;
    hdmi_rx21_modedet_stable_flags[port] = 0;
    hdmi_rx21_stable_watch_bytes[port] = 0;
    hdmi_rx21_input_records[port].byte_0x4 = 1;
    hdmi_rx21_input_records[port].byte_0x5 = 1;
    hdmi_rx21_input_records[port].event16_seen = 0;
    hdmi_rx21_mode_detect_states[port].byte_0xb = 0;
    reg_set_bit(0x1c, hdmi_rx21_reg_blocks[port].block1 + BLOCK1_REG_34);
    reg_clear_bit(0x1c, hdmi_rx21_reg_blocks[port].block1 + BLOCK1_REG_34);
    hdmi_rx21_input_records[port].mode_detected = 1;
    hdmi_rx21_mode_detect_states[port].avi_byte30_changed = 0;
    hdmi_rx21_clear_detect_flags(port);
    hdmi_rx21_clear_status_flags(port);
    hdmi_rx21_input_records[port].byte_0x15c = 0;

    /* Phase 3: the packets, only in HDMI mode. */
    if (hdmi_rx21_input_records[port].hdmi_mode == HDMI_MODE_HDMI) {
        if (hdmi_rx21_input_records[port].avi.byte_0x57 == 0) {
            if (hdmi_rx21_read_avi_infoframe(port, &hdmi_rx21_input_records[port].avi) != 0) {
                if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
                    dbg_printf("[MODEDET]: Port%c No AVI Info !!\n", (char)(port + 0x41));
            } else {
                hdmi_rx21_input_records[port].avi.byte_0x55 = 1;
                hdmi_rx21_input_records[port].avi.byte_0x56 = 1;
            }
        }
        if (hdmi_rx21_input_records[port].audio_infoframe.byte_0x2c == 0) {
            if (hdmi_rx21_read_audio_infoframe(port, &hdmi_rx21_input_records[port].audio_infoframe) != 0) {
                if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
                    dbg_printf("[MODEDET]: Port%c No AUDIO Info !!\n", (char)(port + 0x41));
            } else {
                hdmi_rx21_input_records[port].audio_infoframe.byte_0x2a = 1;
                hdmi_rx21_input_records[port].audio_infoframe.byte_0x2b = 1;
            }
        }
        if (hdmi_rx21_input_records[port].spd_infoframe.byte_0x22 == 0) {
            if (hdmi_rx21_read_spd_infoframe(port, &hdmi_rx21_input_records[port].spd_infoframe) != 0) {
                if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
                    dbg_printf("[MODEDET]: Port%c No StdSPD Info !!\n", (char)(port + 0x41));
            } else {
                hdmi_rx21_input_records[port].spd_infoframe.byte_0x20 = 1;
                hdmi_rx21_input_records[port].spd_infoframe.byte_0x21 = 1;
            }
        }
        if (hdmi_rx21_input_records[port].hdr_infoframe.byte_0x45 == 0) {
            if (hdmi_rx21_read_hdr_infoframe(port, &hdmi_rx21_input_records[port].hdr_infoframe) != 0) {
                if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
                    dbg_printf("[MODEDET]: Port%c No HDR Info Frame !!\n", (char)(port + 0x41));
            } else {
                hdmi_rx21_input_records[port].hdr_infoframe.byte_0x43 = 1;
                hdmi_rx21_input_records[port].hdr_infoframe.byte_0x44 = 1;
            }
        }
        if (hdmi_rx21_input_records[port].audio_stream.byte_0x21 == 0) {
            if (hdmi_rx21_read_audio_stream_packet(port, &hdmi_rx21_input_records[port].audio_stream) != 0) {
                if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
                    dbg_printf("[MODEDET]: Port%c No AUD Stream !!\n", (char)(port + 0x41));
            } else {
                hdmi_rx21_input_records[port].audio_stream.byte_0x1f = 1;
                hdmi_rx21_input_records[port].audio_stream.byte_0x20 = 1;
            }
        }
        if (hdmi_rx21_input_records[port].cvtem.byte_0x4 == 0) {
            if (hdmi_rx21_read_cvtem(port, &hdmi_rx21_input_records[port].cvtem) != 0) {
                if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
                    dbg_printf("[MODEDET]: Port%c No CVTEM !!\n", (char)(port + 0x41));
            } else {
                hdmi_rx21_input_records[port].cvtem.byte_0x2 = 1;
                hdmi_rx21_input_records[port].cvtem.byte_0x3 = 1;
            }
        }
    } else {
        lib_memset((unsigned char *)&hdmi_rx21_input_records[port].avi, 0, sizeof(struct avi_block));
        lib_memset((unsigned char *)&hdmi_rx21_input_records[port].audio_infoframe, 0, sizeof(struct audio_infoframe_block));
        lib_memset((unsigned char *)&hdmi_rx21_input_records[port].block_0xa4, 0, sizeof(struct block_0xa4));
        lib_memset((unsigned char *)&hdmi_rx21_input_records[port].spd_infoframe, 0, sizeof(struct spd_infoframe_block));
        lib_memset((unsigned char *)&hdmi_rx21_input_records[port].hdr_infoframe, 0, sizeof(struct hdr_infoframe_block));
        lib_memset((unsigned char *)&hdmi_rx21_input_records[port].audio_stream, 0, sizeof(struct audio_stream_block));
        lib_memset((unsigned char *)&hdmi_rx21_input_records[port].cvtem, 0, sizeof(struct cvtem_block));
    }

    /* Phase 4: report. */
    dbg_printf("\x1b[32;1mDRV_HDMI_ModeDetect_FSM_Complete FRL mode = %ld\n\x1b[m",
                 (hdmi_rx21_reg_blocks[port].block6[BLOCK6_FRL_RATE] >> 24) & 0xf);
    dbg_printf("Pixel clock(0.1M) = %d, TMDS clock(0.1M) = %d\n", hdmi_rx21_input_records[port].pixel_clock, hdmi_rx21_calc_tmds_clock(port));
    dbg_printf("Color format = %d  (0: RGB, 1: 422, 2: 444, 3:420)\n", hdmi_rx21_input_records[port].avi.color_format);

    /* Phase 5: the input runs. */
    reg_set_bit(0x18, hdmi_rx21_reg_blocks[port].block0 + BLOCK0_REG_B8);
    hdmi_rx21_clear_all_events(port);
    if (hdmi_rx21_stable_count_limits[port] > MODEDET_COUNT_MAX)
        hdmi_rx21_stable_count_limits[port] = MODEDET_COUNT_MAX;
    hdmi_rx21_mode_detect_states[port].mode_change_flag = 0;
    DRV_HDMI_Setup_IntIRQ_Events(port, 1);
    hdmi_rx21_enable_sync_events(port, 1);
    hdmi_rx21_set_ctrl_bits_1b_18(port, 0);
    if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
        dbg_printf("[MODEDET]: Port%c Sync Stable !!\n", (char)(port + 0x41));
    hdmi_rx21_calc_frame_rate(port, &line_rate, &frame_rate);
    DRV_HDMI_Set_AudStatus(port, 1);
    hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_WATCH_STABLE;
    if (dbg_hdmi_message_flags & HDMI_MSG_INIT_INFO)
        dbg_printf("[INIT]: ## Port%c => Jay_ModeDet_End [%ld] ##\n\n", (char)(port + 0x41), timer_get_ticks());
    return 1;
}
