/* hdmi_rx21_service_packet_events  (FUN_a00a1150)
 *
 * Run the packet-event callbacks of an HDMI 2.1 receiver and refresh its AVI data.
 *   port: receiver
 * Name basis: derived - status words 0x70..0x90 and 0xC4 -> callback tables; a changed AVI byte 0x30 sets
 *   avi_byte30_changed, a changed colour format restarts mode detection standby
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a1150 @ 0xa00a1150-0xa00a13a0, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - `rx` is an unsigned char local; the last three statements index with (unsigned char)port instead (the
 *    firmware masks the parameter again there);
 *  - each event word is read once into `status`, the callbacks run, then the word is written back;
 *  - the old AVI record is copied with lib_memcpy(&old, ..., sizeof(old)) into a local of the 0x58-byte type.
 */

/* The decoded AVI data (struct avi_info of hdmi_rx21_read_avi_infoframe, 0x58 bytes): the fields used here. */
struct avi_info {
    unsigned int word_0x0;
    unsigned int color_format;          /* RGB, YCbCr422, YCbCr444, YCbCr420 */
    unsigned char _8[0x28];
    unsigned char byte_0x30;            /* bits 24..30 of AVI data word 0 */
    unsigned char _31[0x24];
    unsigned char seen;                 /* +0x55: set to 1 here */
    unsigned char update;               /* +0x56: set to 1 here */
    unsigned char hold;                 /* +0x57: while non-zero the AVI data is not read the second time */
};

/* The record of one HDMI 2.1 receiver (400 bytes, hdmi_rx21_input_records): the fields used here. */
struct rx21_record {
    unsigned char byte_0x0;
    unsigned char mode_detected;        /* 1 after DRV_HDMI_ModeDetect_FSM_Complete */
    unsigned char _2[6];
    unsigned char avi_reread_request;   /* set by hdmi_rx21_service_sync_events (event 0xE); cleared here */
    unsigned char _9[0x4c - 0x09];
    struct avi_info avi;                /* +0x4C */
    unsigned char _a4[0x158 - 0xa4];
    unsigned char hdr_update;           /* +0x158: set by hdmi_rx21_on_hdr_infoframe, returned by
                                           hdmi_rx21_get_hdr_packet_flag */
    unsigned char _159[0x190 - 0x159];
};

/* Mode-detection state of one HDMI 2.1 receiver (24 bytes): the field used here. */
struct rx21_mode_detect_state {
    unsigned char _0[0x14];
    unsigned char avi_byte30_changed;   /* set here when AVI byte_0x30 changed */
    unsigned char _15[3];
};

/* Table of register block addresses, one 0x34-byte row per HDMI 2.1 receiver (filled by
   hdmi_rx21_init_register_pointers). This routine uses blocks 0 and 9. */
struct rx21_reg_blocks {
    volatile unsigned int *block0;
    unsigned char blocks_1_to_8[0x20];
    volatile unsigned int *block9;
    unsigned char blocks_10_to_12[0x34 - 0x28];
};

/* Event words of register block 0 (word offsets; the layout of hdmi_rx21_event_table) and one word of block 9. */
#define EVENT_REG_70  (0x70 / 4)
#define EVENT_REG_74  (0x74 / 4)
#define EVENT_REG_78  (0x78 / 4)
#define EVENT_REG_7C  (0x7c / 4)
#define EVENT_REG_80  (0x80 / 4)
#define EVENT_REG_90  (0x90 / 4)
#define BLOCK9_REG_C4 (0xc4 / 4)

/* Status bits handled here, written back as 1 together with the rest of the word as read. */
#define HANDLED_70    0x06020400        /* bits 10, 17, 25, 26: events 2, 9, 0x11, 0x12 */
#define HANDLED_74    0x00000003        /* bits 0, 1: events 0x18, 0x19 */
#define HANDLED_7C    0x00000008        /* bit 3: event 0x2B */
#define HANDLED_80    0x20000000        /* bit 29: event 0x35 */

extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern struct rx21_record hdmi_rx21_input_records[];
extern struct rx21_mode_detect_state hdmi_rx21_mode_detect_states[];
extern unsigned int *hdmi_rx21_event_callbacks_5[], *hdmi_rx21_event_callbacks_4[], *hdmi_rx21_event_callbacks_3[], *hdmi_rx21_event_callbacks_2[], *hdmi_rx21_event_callbacks_8[];
extern unsigned int *hdmi_rx21_event_callbacks_1[], *hdmi_rx21_event_callbacks_0[], *hdmi_rx21_event_callbacks_7[], *hdmi_rx21_event_callbacks_6[];
extern void hdmi_rx21_run_event_callbacks(unsigned int, unsigned char, unsigned int **);
extern unsigned int hdmi_rx21_status30_bit4(unsigned int);
extern void *lib_memcpy(void *, const void *, int);
extern unsigned char hdmi_rx21_read_avi_infoframe(unsigned char, struct avi_info *);
extern void hdmi_rx21_modedet_restart_standby(unsigned int);
extern void hdmi_rx21_clear_mode_status(unsigned char);

/*
 * Run the packet callbacks of HDMI 2.1 receiver `port` and, when asked to, read its AVI data again.
 *
 *   port  HDMI 2.1 receiver 0 or 1 (only the low byte counts)
 *
 * Called once per pass by hdmi_rx21_modedet_watch_stable.
 *
 * Part 1: for each event word, hdmi_rx21_run_event_callbacks calls the callback of each status bit picked out
 * here (bit n of the mask = slot n of the table), whatever the enable bits say. The tables live in data RAM;
 * the start values of the slots used are given at each call. The word is then written back with those status
 * bits set, as hdmi_rx21_ack_event does for one event. Words 0x78, 0x90 and block 9 word 0xC4 get an empty
 * mask: their tables are never called and the words are written back as read.
 *
 * Part 2, only when avi_reread_request is 1 (it is cleared) and the receiver is mode_detected and
 * hdmi_rx21_status30_bit4 returns 1: read the AVI data again and compare it with the old copy. A changed
 * byte_0x30 sets avi_byte30_changed of the mode-detection state; otherwise a changed color_format puts the
 * mode detection into standby and clears the detected-mode flags. Then seen and update are set and, unless
 * hold is set, the AVI data is read once more.
 */
void hdmi_rx21_service_packet_events(unsigned int port)
{
    unsigned char rx = port & 0xff;
    unsigned int status;
    unsigned char ready;
    struct avi_info old;

    status = hdmi_rx21_reg_blocks[rx].block0[EVENT_REG_70];
    /* Event 2: slot 2 = hdmi_rx21_clear_event_word. */
    hdmi_rx21_run_event_callbacks(rx, (status >> 8) & 4, hdmi_rx21_event_callbacks_5);
    /* Event 9: slot 1 = hdmi_rx21_on_audio_stream_packet. */
    hdmi_rx21_run_event_callbacks(rx, (status >> 16) & 2, hdmi_rx21_event_callbacks_4);
    /* Events 0x11 / 0x12: slot 1 = hdmi_rx21_on_spd_packet, slot 2 = hdmi_rx21_on_audio_infoframe. */
    hdmi_rx21_run_event_callbacks(rx, (status >> 24) & 6, hdmi_rx21_event_callbacks_3);
    hdmi_rx21_reg_blocks[rx].block0[EVENT_REG_70] = status | HANDLED_70;
    status = hdmi_rx21_reg_blocks[rx].block0[EVENT_REG_74];
    /* Events 0x18 / 0x19: slots 0 and 1 = hdmi_rx21_pulse_bit9_set_flag and its copy. */
    hdmi_rx21_run_event_callbacks(rx, status & 3, hdmi_rx21_event_callbacks_2);
    hdmi_rx21_reg_blocks[rx].block0[EVENT_REG_74] = status | HANDLED_74;
    status = hdmi_rx21_reg_blocks[rx].block0[EVENT_REG_78];
    hdmi_rx21_run_event_callbacks(rx, 0, hdmi_rx21_event_callbacks_8);
    hdmi_rx21_reg_blocks[rx].block0[EVENT_REG_78] = status;
    status = hdmi_rx21_reg_blocks[rx].block0[EVENT_REG_7C];
    /* Event 0x2B: slot 3 = hdmi_rx21_empty_callback. */
    hdmi_rx21_run_event_callbacks(rx, status & 8, hdmi_rx21_event_callbacks_1);
    hdmi_rx21_reg_blocks[rx].block0[EVENT_REG_7C] = status | HANDLED_7C;
    /* hdr_update is set again below only when the HDR callback runs in this pass. */
    hdmi_rx21_input_records[rx].hdr_update = 0;
    status = hdmi_rx21_reg_blocks[rx].block0[EVENT_REG_80];
    /* Event 0x35: slot 5 = hdmi_rx21_on_hdr_infoframe. */
    hdmi_rx21_run_event_callbacks(rx, (status >> 24) & 0x20, hdmi_rx21_event_callbacks_0);
    hdmi_rx21_reg_blocks[rx].block0[EVENT_REG_80] = status | HANDLED_80;
    status = hdmi_rx21_reg_blocks[rx].block0[EVENT_REG_90];
    hdmi_rx21_run_event_callbacks(rx, 0, hdmi_rx21_event_callbacks_7);
    hdmi_rx21_reg_blocks[rx].block0[EVENT_REG_90] = status;
    status = hdmi_rx21_reg_blocks[rx].block9[BLOCK9_REG_C4];
    hdmi_rx21_run_event_callbacks(rx, 0, hdmi_rx21_event_callbacks_6);
    hdmi_rx21_reg_blocks[rx].block9[BLOCK9_REG_C4] = status;
    if (hdmi_rx21_input_records[rx].avi_reread_request == 1) {
        hdmi_rx21_input_records[rx].avi_reread_request = 0;
        if (hdmi_rx21_input_records[rx].mode_detected == 1) {
            ready = hdmi_rx21_status30_bit4(rx);
            if (ready == 1) {
                lib_memcpy(&old, &hdmi_rx21_input_records[rx].avi, sizeof(old));
                hdmi_rx21_read_avi_infoframe(rx, &hdmi_rx21_input_records[rx].avi);
                if (hdmi_rx21_input_records[rx].avi.byte_0x30 != old.byte_0x30)
                    hdmi_rx21_mode_detect_states[rx].avi_byte30_changed = 1;
                else if (hdmi_rx21_input_records[rx].avi.color_format != old.color_format) {
                    hdmi_rx21_modedet_restart_standby(rx);
                    hdmi_rx21_clear_mode_status(rx);
                }
                hdmi_rx21_input_records[(unsigned char)port].avi.seen = 1;
                hdmi_rx21_input_records[(unsigned char)port].avi.update = 1;
                if (hdmi_rx21_input_records[(unsigned char)port].avi.hold == 0)
                    hdmi_rx21_read_avi_infoframe((unsigned char)port, &hdmi_rx21_input_records[(unsigned char)port].avi);
            }
        }
    }
}
