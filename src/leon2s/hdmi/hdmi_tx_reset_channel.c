/* hdmi_tx_reset_channel  (FUN_a0091578)
 *
 * Reset an HDMI TX channel record to its default settings.
 *   port: HDMI TX port 0/1
 * Name basis: derived - clears the record fields, FRL rate 5, clock 0x94; callers hdmi_tx_init,
 *   hdmi_tx_service_port, hdmi_tx_stop_unless_enabled, hdmi_tx_run_setup_steps
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091578 @ 0xa0091578-0xa00916a8 (304 bytes), flags -mcpu=v8 -Os -g.
 * Source form: every field is a bit-field (big-endian, first field = most significant bit) assigned in its own
 * statement, in the order below; neighbouring bits that are cleared in one statement stay one field
 * (sync_positive, frl_dsc_bit2, packet_enables, bits_0_2, ...). The three dsc_encoder_record byte clears come
 * before the last two field writes.
 */
/* HDMI TX channel record (28 bytes per TX port, hdmi_tx_output_records). Bits count from the least significant bit
   of each word. */
struct hdmi_tx_channel_record {
    /* word 0 */
    unsigned int ctrl_bit31 : 1,        /* cleared through hdmi_tx_clear_ctrl_bit31 */
                 ctrl_bit30 : 1,
                 packet_bypass : 1,     /* bit 29: set-up step 1 (HDMITX_PacketSwitch_Bypass) instead of step 2 */
                 : 13,                  /* bits 24..28 and source_code (+1) */
                 audio_source : 8,      /* +2: the mode argument of hdmi_tx_setup_audio */
                 sync_positive : 2,     /* bit 7 hsync_positive, bit 6 vsync_positive */
                 hdmi_mode : 1,         /* bit 5 */
                 frl_dsc_bit2 : 3,      /* bit 4 frl_mode (0 = TMDS), bit 3 dsc_enable, bit 2 */
                 bits_0_1 : 2;
    /* word 1 (+4) */
    unsigned int status_bit31 : 1, : 31;
    /* word 2 (+8) */
    unsigned int pixel_clock;           /* MHz */
    /* word 3 (+0xC) */
    unsigned int word_0xc_bit31 : 1, : 7,
                 color_space : 8,       /* +0xD: picks the 'Color Space = ...' of hdmi_tx_send_avi_infoframe */
                 byte_0xe : 8,          /* +0xE: AVI InfoFrame register 0x147 */
                 byte_0xf : 8;
    /* word 4 (+0x10) */
    unsigned int word_0x10_bit31 : 1, : 7,
                 color_depth : 8,       /* +0x11: bits per colour, passed to hdmi_tx_set_color_depth */
                 byte_0x12 : 8,
                 word_0x10_bit7 : 1,
                 packet_enables : 4,    /* bits 6..3: SPD, audio, MPEG and PPS packet enables */
                 bits_0_2 : 3;          /* bit 2 request_pending, bit 1 active */
    /* word 5 (+0x14) */
    unsigned int word_0x14_bit31 : 1,
                 word_0x14_bit30 : 1, : 6,
                 frl_rate : 8,          /* +0x15 */
                 word_0x14_bit15 : 1,
                 cfg_bit14 : 1,
                 frl_rate_update : 1,   /* bit 13: 'Update FRL Rate' */
                 bit12 : 1,             /* with ctrl_bit31 it lets the set-up steps run */
                 bit11 : 1, : 11;       /* then input_code (+0x17) */
    /* word 6 (+0x18) */
    unsigned int word_0x18;
};
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];
extern unsigned char dsc_encoder_record[];
extern void hdmi_tx_clear_ctrl_bit31(unsigned char);

#define DEFAULT_COLOR_DEPTH     8       /* bits per colour */
#define DEFAULT_PIXEL_CLOCK     0x94    /* 148 MHz */
#define DEFAULT_FRL_RATE        5

/* Bytes of the compression encoder record (struct dsc_encoder_rec) cleared here. */
#define DSC_ENC_SOURCE          5
#define DSC_ENC_BYTE_6          6
#define DSC_ENC_FORMAT          7

/*
 * Put the channel record of one HDMI TX port back to its defaults.
 *
 *   port   HDMI TX port 0 or 1 (not checked)
 *
 * hdmi_tx_init calls it for both ports before TX_STEP_INIT_CORE_REGS; hdmi_tx_service_port, hdmi_tx_stop_unless_enabled and hdmi_tx_run_setup_steps
 * call it right after running TX_STEP_STOP on a port that was active.
 *
 * Defaults: HDMI mode on, 8 bits per colour, pixel clock 148 MHz, FRL rate 5, bit 7 of word 4 and bit 11 of
 * word 5 set. Cleared: the control bits 31 and 30, packet_bypass, the audio source, both sync polarities, the
 * FRL, DSC and low bits of word 0, the colour space bytes, the packet enables and the request and active bits,
 * the FRL update and configuration bits of word 5. The source code and the input code are kept.
 * The source, format and byte 6 of the compression encoder record are cleared as well.
 */
void hdmi_tx_reset_channel(unsigned char port)
{
    hdmi_tx_clear_ctrl_bit31(port);
    hdmi_tx_output_records[port].ctrl_bit30 = 0;
    hdmi_tx_output_records[port].hdmi_mode = 1;
    hdmi_tx_output_records[port].frl_dsc_bit2 = 0;
    hdmi_tx_output_records[port].word_0x10_bit7 = 1;
    hdmi_tx_output_records[port].packet_enables = 0;
    hdmi_tx_output_records[port].color_depth = DEFAULT_COLOR_DEPTH;
    hdmi_tx_output_records[port].word_0xc_bit31 = 0;
    hdmi_tx_output_records[port].word_0x10_bit31 = 0;
    hdmi_tx_output_records[port].byte_0x12 = 0;
    hdmi_tx_output_records[port].color_space = 0;
    hdmi_tx_output_records[port].byte_0xf = 0;
    hdmi_tx_output_records[port].byte_0xe = 0;
    hdmi_tx_output_records[port].packet_bypass = 0;
    hdmi_tx_output_records[port].bits_0_1 = 0;
    hdmi_tx_output_records[port].status_bit31 = 0;
    hdmi_tx_output_records[port].pixel_clock = DEFAULT_PIXEL_CLOCK;
    hdmi_tx_output_records[port].audio_source = 0;
    hdmi_tx_output_records[port].sync_positive = 0;
    hdmi_tx_output_records[port].word_0x14_bit31 = 0;
    hdmi_tx_output_records[port].word_0x14_bit30 = 0;
    hdmi_tx_output_records[port].cfg_bit14 = 0;
    hdmi_tx_output_records[port].frl_rate = DEFAULT_FRL_RATE;
    hdmi_tx_output_records[port].word_0x14_bit15 = 0;
    hdmi_tx_output_records[port].frl_rate_update = 0;
    hdmi_tx_output_records[port].bit12 = 0;
    dsc_encoder_record[DSC_ENC_SOURCE] = 0;
    dsc_encoder_record[DSC_ENC_BYTE_6] = 0;
    dsc_encoder_record[DSC_ENC_FORMAT] = 0;
    hdmi_tx_output_records[port].bits_0_2 = 0;
    hdmi_tx_output_records[port].bit11 = 1;
}
