/* CONV2HDMITX_UpdatePacket  (CONV2HDMITX_UpdatePacket)
 *
 * Update and send or clear the data packets of an HDMI output from its input.
 *   port: HDMI TX port
 *   input_code
 * Name basis: proven - original name printed ('CONV2HDMITX_UpdatePacket NOT support this input!!!'); DP inputs
 *   converted from SDPs
 *
 * Matching notes
 * --------------
 * CONV2HDMITX_UpdatePacket (leon2s, 0xa00a9870-0xa00a9c4c, 988 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on: dp_rx is set by its own two-case switch before the input-code
 * switch; the three buffers are cleared with 0x1F, 0x0E and 0x0E bytes; the PPS packet test is the last arm of
 * the audio packet's if/else chain.
 */

/* Input codes: which input feeds an HDMI output. */
enum {
    INPUT_CODE_HDMI20_0 = 0x31,     /* HDMI 2.0 receiver 0 */
    INPUT_CODE_HDMI20_1 = 0x41,     /* HDMI 2.0 receiver 1 */
    INPUT_CODE_HDMI21_0 = 0x51,     /* HDMI 2.1 receiver 0 */
    INPUT_CODE_HDMI21_1 = 0x61,     /* HDMI 2.1 receiver 1 */
    INPUT_CODE_DP_0     = 0x71,     /* DisplayPort receiver 0 */
    INPUT_CODE_DP_1     = 0x81      /* DisplayPort receiver 1 */
};

#define EXTRA_PACKET_SIZE 0x1f          /* bytes cleared in each buffer */
#define AUDIO_PACKET_SIZE 0x0e
#define VTEM_PACKET_SIZE  0x0e

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
extern void *lib_memset(unsigned char *, unsigned char, int);
extern void dbg_print_string(const char *);
extern void hdmi_tx_enable_audio_infoframe(unsigned char, unsigned char);
extern void hdmi_tx_enable_extra_infoframe(unsigned char, unsigned char);
extern void hdmi_tx_enable_pps_packet(unsigned char, unsigned char);
extern void hdmi_tx_enable_vtem_packet(unsigned char, unsigned char);
extern void hdmi_tx_update_extra_infoframe(unsigned char, unsigned char *);
extern void hdmi_tx_update_audio_infoframe(unsigned char, unsigned char *);
extern void hdmi_tx_update_vtem_packet(unsigned char, unsigned char *);
extern void hdmi_tx_build_infoframe_from_sdp(void *, unsigned char *);
extern void hdmi_tx_build_audio_infoframe_from_sdp(void *, unsigned char *);
extern void hdmi_tx_fill_packet_defaults(unsigned char, unsigned char *);
extern void *dp_get_port_record_block_b8(unsigned int);
extern void *dp_get_port_record_block_df(unsigned int);
extern unsigned char dp_get_port_record_byte_127(unsigned int);
extern unsigned char dp_get_port_record_byte_f0(unsigned int);
extern unsigned char dp_get_port_record_byte_ef(unsigned int);
extern unsigned char dp_get_port_record_byte_f1(unsigned int);
extern unsigned char dp_get_port_record_byte_dd(unsigned int);
extern unsigned char dp_get_port_record_byte_dc(unsigned int);
extern unsigned char dp_get_port_record_byte_de(unsigned int);
extern unsigned char dp_get_port_record_byte_b6(unsigned int);
extern unsigned char dp_get_port_record_byte_b5(unsigned int);
extern unsigned char dp_get_port_record_byte_b7(unsigned int);

/*
 * Bring the data packets an HDMI output sends in line with its input.
 *
 *   port        HDMI TX port 0/1
 *   input_code  the input that feeds the output (INPUT_CODE_*)
 *
 * Called by hdmi_tx_run_setup_steps at its end, with byte +0x17 of the TX channel record, when bit 29 of that
 * record's word 0 is set.
 *
 * Phases:
 *  1. Clear the three packet buffers and pick DP receiver 0 or 1.
 *  2. HDMI inputs: switch off the audio, extra and PPS packets of the output. Done.
 *  3. DP inputs: copy the packet bytes of the DP input record into the output's four packet groups (the state
 *     and byte_2 bytes are replaced, the pending byte is ORed in).
 *  4. Extra InfoFrame: state 1 and pending: build it from the DP record block +0xB8 and send it; state 0:
 *     switch it off.
 *  5. Audio InfoFrame: the same from the DP record block +0xDF. Only when neither case applies is the PPS
 *     packet looked at: state 0 switches it off.
 *  6. VTEM packet, the other way round: state 1 and pending switches it off; state 0 fills it with the
 *     fixed values for DP record byte +0x127 and sends it.
 * Every action needs byte_2 of its group to be 0 and clears the group's pending byte.
 */
void CONV2HDMITX_UpdatePacket(unsigned char port, unsigned char input_code)
{
    unsigned char extra_packet[32];
    unsigned char audio_packet[16];
    unsigned char vtem_packet[16];
    unsigned char dp_rx;

    /* 1. Clear the buffers; pick the DP receiver. */
    lib_memset(extra_packet, 0, EXTRA_PACKET_SIZE);
    lib_memset(audio_packet, 0, AUDIO_PACKET_SIZE);
    lib_memset(vtem_packet, 0, VTEM_PACKET_SIZE);
    dp_rx = 0;
    switch (input_code) {
    case INPUT_CODE_DP_0:
        dp_rx = 0;
        break;
    case INPUT_CODE_DP_1:
        dp_rx = 1;
        break;
    }
    switch (input_code) {
    case INPUT_CODE_HDMI20_0:
    case INPUT_CODE_HDMI20_1:
    case INPUT_CODE_HDMI21_0:
    case INPUT_CODE_HDMI21_1:
        /* 2. HDMI inputs: these three packets are not sent. */
        hdmi_tx_enable_audio_infoframe(port, 0);
        hdmi_tx_enable_extra_infoframe(port, 0);
        hdmi_tx_enable_pps_packet(port, 0);
        break;
    case INPUT_CODE_DP_0:
    case INPUT_CODE_DP_1:
        /* 3. Take over the packet bytes of the DP input record. */
        hdmi_tx_packet_state.output[port].audio.pending |= dp_get_port_record_byte_f0(dp_rx);
        hdmi_tx_packet_state.output[port].audio.state = dp_get_port_record_byte_ef(dp_rx);
        hdmi_tx_packet_state.output[port].audio.byte_2 = dp_get_port_record_byte_f1(dp_rx);
        hdmi_tx_packet_state.output[port].extra.pending |= dp_get_port_record_byte_dd(dp_rx);
        hdmi_tx_packet_state.output[port].extra.state = dp_get_port_record_byte_dc(dp_rx);
        hdmi_tx_packet_state.output[port].extra.byte_2 = dp_get_port_record_byte_de(dp_rx);
        hdmi_tx_packet_state.output[port].pps.pending |= dp_get_port_record_byte_b6(dp_rx);
        hdmi_tx_packet_state.output[port].pps.state = dp_get_port_record_byte_b5(dp_rx);
        hdmi_tx_packet_state.output[port].pps.byte_2 = dp_get_port_record_byte_b7(dp_rx);

        /* 4. Extra InfoFrame. */
        if (hdmi_tx_packet_state.output[port].extra.byte_2 == 0 && hdmi_tx_packet_state.output[port].extra.state == 1 && hdmi_tx_packet_state.output[port].extra.pending == 1) {
            hdmi_tx_build_infoframe_from_sdp(dp_get_port_record_block_b8(dp_rx), extra_packet);
            hdmi_tx_update_extra_infoframe(port, extra_packet);
            hdmi_tx_packet_state.output[port].extra.pending = 0;
        } else if (hdmi_tx_packet_state.output[port].extra.byte_2 == 0 && hdmi_tx_packet_state.output[port].extra.state == 0) {
            hdmi_tx_enable_extra_infoframe(port, 0);
            hdmi_tx_packet_state.output[port].extra.pending = 0;
        }

        /* 5. Audio InfoFrame, then the PPS packet. */
        if (hdmi_tx_packet_state.output[port].audio.byte_2 == 0 && hdmi_tx_packet_state.output[port].audio.state == 1 && hdmi_tx_packet_state.output[port].audio.pending == 1) {
            hdmi_tx_build_audio_infoframe_from_sdp(dp_get_port_record_block_df(dp_rx), audio_packet);
            hdmi_tx_update_audio_infoframe(port, audio_packet);
            hdmi_tx_packet_state.output[port].audio.pending = 0;
        } else if (hdmi_tx_packet_state.output[port].audio.byte_2 == 0 && hdmi_tx_packet_state.output[port].audio.state == 0) {
            hdmi_tx_enable_audio_infoframe(port, 0);
            hdmi_tx_packet_state.output[port].audio.pending = 0;
        } else if (hdmi_tx_packet_state.output[port].pps.byte_2 == 0 && hdmi_tx_packet_state.output[port].pps.state == 0) {
            hdmi_tx_enable_pps_packet(port, 0);
            hdmi_tx_packet_state.output[port].pps.pending = 0;
        }

        /* 6. VTEM packet: state 1 switches it off, state 0 sends it. */
        if (hdmi_tx_packet_state.output[port].vtem.byte_2 == 0 && hdmi_tx_packet_state.output[port].vtem.state == 1 && hdmi_tx_packet_state.output[port].vtem.pending == 1) {
            hdmi_tx_enable_vtem_packet(port, 0);
            hdmi_tx_packet_state.output[port].vtem.pending = 0;
        } else if (hdmi_tx_packet_state.output[port].vtem.byte_2 == 0 && hdmi_tx_packet_state.output[port].vtem.state == 0) {
            hdmi_tx_fill_packet_defaults(dp_get_port_record_byte_127(dp_rx & 1), vtem_packet);
            hdmi_tx_update_vtem_packet(port, vtem_packet);
            hdmi_tx_packet_state.output[port].vtem.pending = 0;
        }
        break;
    default:
        dbg_print_string("CONV2HDMITX_UpdatePacket NOT support this input!!!\r");
        break;
    }
}
