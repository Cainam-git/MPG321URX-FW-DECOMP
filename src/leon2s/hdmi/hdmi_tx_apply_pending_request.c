/* hdmi_tx_apply_pending_request  (FUN_a00916a8)
 *
 * Copy a pending HDMI TX request from the main processor into the channel record.
 *   port: HDMI TX port 0/1
 * Name basis: derived - only when the pending bit (word 4 bit 2) is set; source record 0xA807A8FC filled by
 *   commands 0x40..0x44
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00916a8 @ 0xa00916a8-0xa00918ec (145 words, leaf), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - bit-fields on both records, assigned in the firmware's store order;
 *  - the request's second halfword is a union of its bit-fields and two bytes (the source code is read as a
 *    byte, ldub);
 *  - mpeg_packet (channel word 4 bit 4) is a _Bool bit-field (the firmware normalises the copied bit with
 *    cmp/addx).
 */

/*
 * TX channel record of one HDMI output (28 bytes, hdmi_tx_output_records[port]); big-endian bit-fields, so the first field
 * is bit 31 of its word. The names of the single bits come from the routines that read them.
 */
struct hdmi_tx_channel_record {
    /* word 0 */
    unsigned int ctrl_bit31 : 1;        /* hdmi_tx_get_ctrl_bit31: with bit12 it lets the set-up steps run */
    unsigned int ctrl_bit30 : 1;        /* hdmi_tx_get_ctrl_bit30 */
    unsigned int packet_bypass : 1;     /* bit 29: set-up step 1 (HDMITX_PacketSwitch_Bypass) instead of step 2 */
    unsigned int bits_24_28 : 5;
    unsigned int source_code : 8;       /* +1: input code, or SOURCE_CODE_E1 / _E2 */
    unsigned int audio_source : 8;      /* +2: the mode argument of hdmi_tx_setup_audio */
    unsigned int hsync_positive : 1;    /* bit 7: hdmi_tx_get_hsync_polarity */
    unsigned int vsync_positive : 1;    /* bit 6: hdmi_tx_get_vsync_polarity */
    unsigned int hdmi_mode : 1;         /* bit 5 */
    unsigned int frl_mode : 1;          /* bit 4: hdmi_tx_is_frl_mode; 0 = TMDS */
    unsigned int dsc_enable : 1;        /* bit 3: 'DSC Enable' in the FRL set-up */
    unsigned int bit2 : 1;
    unsigned int bit1 : 1;
    unsigned int bit0 : 1;
    unsigned int word_0x4;              /* bit 31: hdmi_tx_get_status_bit31 */
    unsigned int pixel_clock;           /* +8 */
    /* word 3 */
    unsigned int word_0xc_bit31 : 1;
    unsigned int bits_24_30 : 7;
    unsigned int color_space : 8;       /* +0xD: picks the 'Color Space = ...' of hdmi_tx_send_avi_infoframe */
    unsigned int byte_0xe : 8;          /* +0xE: AVI InfoFrame register 0x147 */
    unsigned int byte_0xf : 8;
    /* word 4 */
    unsigned int word_0x10_bit31 : 1;
    unsigned int bits_0x10_24_30 : 7;
    unsigned int color_depth : 8;       /* +0x11: passed to hdmi_tx_set_color_depth */
    unsigned int byte_0x12 : 8;
    unsigned int word_0x10_bit7 : 1;
    unsigned int spd_packet : 1;        /* bit 6: 'SPD Packet Enable' */
    unsigned int audio_packet : 1;      /* bit 5: audio set-up and 'Audio INFO Packet Enable' */
    _Bool mpeg_packet : 1;              /* bit 4: 'MPEG Packet Enable' */
    unsigned int pps_packet : 1;        /* bit 3: 'PPS Packet Enable' */
    unsigned int request_pending : 1;   /* bit 2: hdmi_tx_mark_request_pending */
    unsigned int bits_0_1 : 2;          /* bit 1: hdmi_tx_set_active / hdmi_tx_is_active */
    /* word 5 */
    unsigned int half_0x14 : 16;        /* byte +0x15: FRL rate (hdmi_tx_get_frl_rate) */
    unsigned int word_0x14_bit15 : 1;
    unsigned int cfg_bit14 : 1;         /* hdmi_tx_set_cfg_bit14 / _clear_ */
    unsigned int frl_rate_update : 1;   /* bit 13: 'Update FRL Rate' */
    unsigned int bits_8_12 : 5;
    unsigned int input_code : 8;        /* +0x17: the input code when source_code is 0xE1 / 0xE2 */
    unsigned int word_0x18;
};

/*
 * HDMI TX request (20 bytes per HDMI TX port, hdmi_tx_requests), filled by the main processor's mailbox commands
 * 0x40..0x44. Field names as in ipc_dispatch_command; the comments say where this routine copies each field.
 */
struct hdmi_tx_request {
    unsigned short bit15 : 1;
    unsigned short bit14 : 1;               /* to ctrl_bit31 */
    unsigned short bit13 : 1;               /* to word_0xc_bit31 */
    unsigned short bit12 : 1;               /* to ctrl_bit30 */
    unsigned short hsync_positive : 1;      /* bit 11 */
    unsigned short vsync_positive : 1;      /* bit 10 */
    unsigned short hdmi_mode : 1;           /* bit 9 */
    unsigned short bit8 : 1;                /* to word_0x10_bit31 */
    unsigned short bit7 : 1;                /* to frl_mode */
    unsigned short bit6 : 1;                /* to dsc_enable */
    unsigned short bit5 : 1;                /* to bit2 and word_0x14_bit15 */
    unsigned short bit4 : 1;                /* to bit1 */
    unsigned short bit3 : 1;                /* to bit0 */
    unsigned short bit2 : 1;                /* to word_0x10_bit7 */
    unsigned short bit1 : 1;                /* to spd_packet */
    unsigned short bit0 : 1;                /* to audio_packet */
    union {
        struct {
            unsigned short bit15 : 1;       /* to mpeg_packet */
            unsigned short bit14 : 1;       /* to pps_packet */
            unsigned short bit13 : 1;       /* to packet_bypass */
            unsigned short bits_8_12 : 5;
            unsigned short low_byte : 8;
        } bits;
        unsigned char bytes[2];             /* bytes[1] (+3) = source code */
    } half_2;
    unsigned short pixel_clock;             /* +4 */
    unsigned char byte_0x6;                 /* to color_space */
    unsigned char byte_0x7;                 /* to byte_0xe */
    unsigned char byte_0x8;                 /* to byte_0x12 */
    unsigned char color_depth;              /* +9 */
    unsigned char byte_0xa;                 /* to byte_0xf */
    unsigned char byte_0xb;
    unsigned char input_code;               /* +0xC */
    unsigned char byte_0xd;
    unsigned short half_0xe;
    unsigned short half_0x10;
    unsigned short half_0x12;
};
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];
extern struct hdmi_tx_request hdmi_tx_requests[];

/*
 * Take over a pending request of the main processor into the TX channel record of one HDMI output.
 *
 *   port  HDMI TX port 0 or 1
 *
 * Called by hdmi_tx_run_service for port 0 and port 1, after hdmi_tx_service_port and before
 * hdmi_tx_run_setup_steps. Mailbox commands 0x41..0x44 mark the request pending (hdmi_tx_mark_request_pending);
 * without that mark nothing is copied. Request bytes +0xB and +0xD..+0x13 are not copied here.
 *
 * Phases:
 *   1. Return unless the request is pending; clear the mark.
 *   2. Copy the request's bytes and single bits into the channel record (each field comment of
 *      struct hdmi_tx_request says where it goes). Request bit 5 goes to two places.
 *   3. frl_mode is written once more from request bit 7 when frl_rate_update is clear.
 */
void hdmi_tx_apply_pending_request(unsigned char port)
{
    /* 1. */
    if (!hdmi_tx_output_records[port].request_pending)
        return;
    hdmi_tx_output_records[port].request_pending = 0;

    /* 2. In the firmware's store order. */
    hdmi_tx_output_records[port].source_code = hdmi_tx_requests[port].half_2.bytes[1];
    hdmi_tx_output_records[port].ctrl_bit31 = hdmi_tx_requests[port].bit14;
    hdmi_tx_output_records[port].pixel_clock = hdmi_tx_requests[port].pixel_clock;
    hdmi_tx_output_records[port].ctrl_bit30 = hdmi_tx_requests[port].bit12;
    hdmi_tx_output_records[port].hsync_positive = hdmi_tx_requests[port].hsync_positive;
    hdmi_tx_output_records[port].vsync_positive = hdmi_tx_requests[port].vsync_positive;
    hdmi_tx_output_records[port].hdmi_mode = hdmi_tx_requests[port].hdmi_mode;
    hdmi_tx_output_records[port].color_depth = hdmi_tx_requests[port].color_depth;
    hdmi_tx_output_records[port].word_0xc_bit31 = hdmi_tx_requests[port].bit13;
    hdmi_tx_output_records[port].word_0x10_bit31 = hdmi_tx_requests[port].bit8;
    hdmi_tx_output_records[port].color_space = hdmi_tx_requests[port].byte_0x6;
    hdmi_tx_output_records[port].byte_0xf = hdmi_tx_requests[port].byte_0xa;
    hdmi_tx_output_records[port].byte_0xe = hdmi_tx_requests[port].byte_0x7;
    hdmi_tx_output_records[port].byte_0x12 = hdmi_tx_requests[port].byte_0x8;
    hdmi_tx_output_records[port].packet_bypass = hdmi_tx_requests[port].half_2.bits.bit13;
    hdmi_tx_output_records[port].bit1 = hdmi_tx_requests[port].bit4;
    hdmi_tx_output_records[port].frl_mode = hdmi_tx_requests[port].bit7;
    hdmi_tx_output_records[port].dsc_enable = hdmi_tx_requests[port].bit6;
    hdmi_tx_output_records[port].bit2 = hdmi_tx_requests[port].bit5;
    hdmi_tx_output_records[port].word_0x14_bit15 = hdmi_tx_requests[port].bit5;
    hdmi_tx_output_records[port].bit0 = hdmi_tx_requests[port].bit3;
    hdmi_tx_output_records[port].word_0x10_bit7 = hdmi_tx_requests[port].bit2;
    hdmi_tx_output_records[port].spd_packet = hdmi_tx_requests[port].bit1;
    hdmi_tx_output_records[port].audio_packet = hdmi_tx_requests[port].bit0;
    hdmi_tx_output_records[port].mpeg_packet = hdmi_tx_requests[port].half_2.bits.bit15;
    hdmi_tx_output_records[port].pps_packet = hdmi_tx_requests[port].half_2.bits.bit14;
    hdmi_tx_output_records[port].input_code = hdmi_tx_requests[port].input_code;

    /* 3. */
    if (!hdmi_tx_output_records[port].frl_rate_update)
        hdmi_tx_output_records[port].frl_mode = hdmi_tx_requests[port].bit7;
}
