/* CONV2HDMITX_UpdateInterface  (CONV2HDMITX_UpdateInterface)
 *
 * Copy the input's picture format (mode, depth, clock) into an HDMI output record.
 *   port: HDMI TX port
 *   channel: the TX channel record of that port
 * Name basis: proven - original name printed ('CONV2HDMITX_UpdateInterface NOT support this input!!!'); input
 *   codes 0x31..0x81
 *
 * Matching notes
 * --------------
 * CONV2HDMITX_UpdateInterface (leon2s 0xa00a94f4-0xa00a9870, 892 bytes), flags -mcpu=v8 -Os -g (section
 * default).
 * Source forms the exact build depends on:
 *  - input_code is assigned in both arms of the 0xE1/0xE2 test, and the test reads byte +1 itself;
 *  - hdmi20_rx, hdmi21_rx and dp_rx are set by a first switch whose default arm clears all three, then a
 *    second switch on input_code does the work;
 *  - dp_format[] is declared and zero-initialised after the lib_memset call;
 *  - the three closing clears run in the order audio, extra, pps.
 */

/* Input codes: which input feeds an HDMI output (byte +1 of the TX channel record). */
enum {
    INPUT_CODE_HDMI20_0 = 0x31,     /* HDMI 2.0 receiver 0 */
    INPUT_CODE_HDMI20_1 = 0x41,     /* HDMI 2.0 receiver 1 */
    INPUT_CODE_HDMI21_0 = 0x51,     /* HDMI 2.1 receiver 0 */
    INPUT_CODE_HDMI21_1 = 0x61,     /* HDMI 2.1 receiver 1 */
    INPUT_CODE_DP_0     = 0x71,     /* DisplayPort receiver 0 */
    INPUT_CODE_DP_1     = 0x81,     /* DisplayPort receiver 1 */
    SOURCE_CODE_E1      = 0xe1,     /* with these two codes the input code is in byte +0x17 */
    SOURCE_CODE_E2      = 0xe2
};

#define AVI_PACKET_SIZE 0x13            /* bytes cleared in the stack packet */

/* TX channel record of one HDMI output (28 bytes each, table at 0xA807D580; this routine fills it). */
struct hdmi_tx_channel_record {
    unsigned char byte_0;
    unsigned char source_code;          /* +1: input code, or SOURCE_CODE_E1 / _E2 */
    unsigned char byte_2;
    unsigned int hsync_positive : 1;    /* +3 bit 7 (word 0 bit 7): read by hdmi_tx_get_hsync_polarity */
    unsigned int vsync_positive : 1;    /* word 0 bit 6: read by hdmi_tx_get_vsync_polarity */
    unsigned int hdmi_mode : 1;         /* word 0 bit 5 */
    unsigned int bits_0_4 : 5;
    unsigned int word_4;
    unsigned int pixel_clock;           /* +8 */
    unsigned char pad_0xc[5];
    unsigned char color_depth;          /* +0x11: passed to hdmi_tx_set_color_depth */
    unsigned char pad_0x12[5];
    unsigned char input_code;           /* +0x17: the input code when source_code is 0xE1 / 0xE2 */
};

/* Three bytes per data packet of an output; filled from the DP input record for DP inputs. */
struct tx_packet_group {
    unsigned char state;                /* replaced from the DP record; 1 or 0 picks the action */
    unsigned char pending;              /* ORed in from the DP record, cleared once acted on */
    unsigned char byte_2;               /* replaced from the DP record; no action unless 0 */
};
struct tx_packet_groups {
    struct tx_packet_group extra;       /* InfoFrame in the 0x160 slot */
    struct tx_packet_group vtem;        /* VTEM packet */
    struct tx_packet_group audio;       /* audio InfoFrame */
    struct tx_packet_group pps;         /* compression parameter (PPS) packet */
};
struct tx_packet_state {
    unsigned char per_dp_input[6];      /* three bytes per DP input, read by HDMITX_PacketSwitch_Bypass */
    struct tx_packet_groups output[4];
};
extern struct tx_packet_state hdmi_tx_packet_state;
extern void *lib_memset(void *, int, unsigned int);
extern int dbg_print_string(const char *);
extern unsigned char hdmi_get_saved_reg30_bit4(unsigned int);
extern unsigned char hdmi_get_saved_color_depth(unsigned int);
extern unsigned char hdmi_get_saved_reg55_bit0(unsigned int);
extern unsigned char hdmi_get_saved_reg55_bit1(unsigned int);
extern unsigned short hdmi_get_saved_pixel_clock(unsigned int);
extern unsigned char hdmi_rx21_get_hdmi_mode(unsigned int);
extern unsigned char hdmi_rx21_get_color_depth(unsigned int);
extern unsigned char hdmi_rx21_get_mode_byte_2f(unsigned int);
extern unsigned char hdmi_rx21_get_mode_byte_30(unsigned int);
extern unsigned short hdmi_rx21_get_pixel_clock(unsigned int);
extern unsigned char dp_get_port_record_byte_f6(unsigned int);
extern unsigned char dp_get_port_record_byte_f7(unsigned int);
extern unsigned char dp_get_port_record_byte_f8(unsigned int);
extern unsigned int dp_get_port_record_word_fc(unsigned int);
extern unsigned char dp_get_port_record_byte_f2(unsigned int);
extern unsigned char dp_get_port_record_byte_f3(unsigned int);
extern unsigned char dp_get_port_record_byte_f4(unsigned int);
extern unsigned char dp_get_port_record_byte_f5(unsigned int);
extern void hdmi_tx_build_avi_infoframe(unsigned int, unsigned char *, unsigned char *);
extern void hdmi_tx_enable_avi_packet(unsigned char, unsigned char);
extern void hdmi_tx_update_avi_payload(unsigned char, unsigned char *);

/*
 * Copy the picture format of the input that feeds an HDMI output into the output's TX channel record.
 *
 *   port     HDMI TX port 0/1
 *   channel  the TX channel record of that port
 *
 * Called by hdmi_tx_run_step in step 1. That step then passes the record's colour depth (or 8) to
 * hdmi_tx_set_color_depth, and hdmi_tx_set_sync_polarity reads the two polarity bits.
 *
 * Phases:
 *  1. Clear the AVI packet and the four DP format bytes.
 *  2. Find the input code: byte +1, or byte +0x17 when byte +1 is 0xE1 or 0xE2.
 *  3. Turn the input code into a receiver number (0 or 1) of its kind.
 *  4. Copy the format of that receiver into the record:
 *     - HDMI 2.0 inputs: the receiver's saved values; AVI packet sending switched off;
 *     - HDMI 2.1 inputs: the values of the HDMI 2.1 input record (the pixel clock divided by 10, and only
 *       when the input code came from byte +1); AVI packet sending switched off;
 *     - DisplayPort inputs: HDMI mode 1 and the values of the DP input record; an AVI InfoFrame is built
 *       from four format bytes of the DP record and put in place of the output's AVI payload;
 *     - any other code: a message, nothing copied.
 *  5. Clear the pending flags of the audio, extra and PPS packets of this output.
 */
void CONV2HDMITX_UpdateInterface(unsigned char port, struct hdmi_tx_channel_record *channel)
{
    unsigned char avi_packet[19];
    unsigned char input_code;
    unsigned char indirect_code;
    unsigned char hdmi20_rx, hdmi21_rx, dp_rx;
    unsigned short clock;
    unsigned int dp_word_fc;

    /* 1. Clear the packet buffers. */
    lib_memset(avi_packet, 0, AVI_PACKET_SIZE);
    unsigned char dp_format[4] = {0, 0, 0, 0};

    /* 2. Codes 0xE1 / 0xE2 carry the real input code in byte +0x17. */
    indirect_code = 0;
    if ((unsigned char)(channel->source_code - SOURCE_CODE_E1) < 2) {
        input_code = channel->input_code;
        indirect_code = 1;
    } else
        input_code = channel->source_code;

    /* 3. Receiver number of the input. */
    switch (input_code) {
    case INPUT_CODE_HDMI20_0:
        hdmi20_rx = 0;
        break;
    case INPUT_CODE_HDMI20_1:
        hdmi20_rx = 1;
        break;
    case INPUT_CODE_HDMI21_0:
        hdmi21_rx = 0;
        break;
    case INPUT_CODE_HDMI21_1:
        hdmi21_rx = 1;
        break;
    case INPUT_CODE_DP_0:
        dp_rx = 0;
        break;
    case INPUT_CODE_DP_1:
        dp_rx = 1;
        break;
    default:
        hdmi20_rx = 0;
        hdmi21_rx = 0;
        dp_rx = 0;
        break;
    }

    /* 4. Copy the input's format. */
    switch (input_code) {
    case INPUT_CODE_HDMI20_0:
    case INPUT_CODE_HDMI20_1:
        channel->hdmi_mode = hdmi_get_saved_reg30_bit4(hdmi20_rx);
        channel->color_depth = hdmi_get_saved_color_depth(hdmi20_rx);
        channel->hsync_positive = hdmi_get_saved_reg55_bit0(hdmi20_rx);
        channel->vsync_positive = hdmi_get_saved_reg55_bit1(hdmi20_rx);
        clock = hdmi_get_saved_pixel_clock(hdmi20_rx);
        channel->pixel_clock = clock;
        hdmi_tx_enable_avi_packet(port, 0);
        break;
    case INPUT_CODE_HDMI21_0:
    case INPUT_CODE_HDMI21_1:
        channel->hdmi_mode = hdmi_rx21_get_hdmi_mode(hdmi21_rx);
        channel->color_depth = hdmi_rx21_get_color_depth(hdmi21_rx);
        channel->hsync_positive = hdmi_rx21_get_mode_byte_2f(hdmi21_rx);
        channel->vsync_positive = hdmi_rx21_get_mode_byte_30(hdmi21_rx);
        /* The clock is kept as it was when the input code came from byte +0x17. */
        if (!indirect_code) {
            clock = hdmi_rx21_get_pixel_clock(hdmi21_rx) / 10;
            channel->pixel_clock = clock;
        }
        hdmi_tx_enable_avi_packet(port, 0);
        break;
    case INPUT_CODE_DP_0:
    case INPUT_CODE_DP_1:
        channel->hdmi_mode = 1;
        channel->color_depth = dp_get_port_record_byte_f6(dp_rx);
        channel->hsync_positive = dp_get_port_record_byte_f7(dp_rx);
        channel->vsync_positive = dp_get_port_record_byte_f8(dp_rx);
        dp_word_fc = dp_get_port_record_word_fc(dp_rx);
        channel->pixel_clock = dp_word_fc * dp_get_port_record_byte_f6(dp_rx) >> 3;
        /* Build the output's AVI InfoFrame from four format bytes of the DP record. */
        dp_format[0] = dp_get_port_record_byte_f2(dp_rx);
        dp_format[1] = dp_get_port_record_byte_f3(dp_rx);
        dp_format[2] = dp_get_port_record_byte_f4(dp_rx);
        dp_format[3] = dp_get_port_record_byte_f5(dp_rx);
        hdmi_tx_build_avi_infoframe(dp_get_port_record_word_fc(dp_rx), dp_format, avi_packet);
        hdmi_tx_update_avi_payload(port, avi_packet);
        break;
    default:
        dbg_print_string("CONV2HDMITX_UpdateInterface NOT support this input!!!\r");
        break;
    }

    /* 5. Clear the pending flags of three packets of this output. */
    hdmi_tx_packet_state.output[port].audio.pending = 0;
    hdmi_tx_packet_state.output[port].extra.pending = 0;
    hdmi_tx_packet_state.output[port].pps.pending = 0;
}
