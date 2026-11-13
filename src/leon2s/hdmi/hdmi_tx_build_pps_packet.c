/* hdmi_tx_build_pps_packet  (FUN_a0092db8)
 *
 * Build the 161-byte compression parameter (PPS) packet of an HDMI TX port and write it to bank 2.
 *   port: HDMI TX port 0/1
 * Note: Six groups with header 7F: bytes 06 00 01 00 02 00 88, the 96 parameter bytes of dsc_enc_pps_words
 *   plus 32 zeros, and 8 timing bytes from dsc_encoder_record.
 * Name basis: derived - packet filled from dsc_enc_pps_words and dsc_encoder_record; only caller is the DSC
 *   step of hdmi_tx_run_step; the enable routine's caller prints 'PPS Packet Enable'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0092db8 @ 0xa0092db8-0xa0093034 (159 words), flags -mcpu=v8 -Os -g.
 * Source form: pps_half_14 / 3 is computed right after pps_bytes is filled; the independent byte and halfword
 * stores into packet and timing are written in the order the firmware schedules them (not in packet order).
 */
/* The part of the compression encoder record (dsc_encoder_record) read here. */
struct dsc_encoder_rec {
    unsigned char bytes_0x0[8];
    unsigned short half_0x8;
    unsigned short width;           /* +0xA */
    unsigned short half_0xc;
    unsigned short half_0xe;
};
extern struct dsc_encoder_rec dsc_encoder_record;
extern unsigned int dsc_enc_pps_words[];   /* filled by sys_dsc_enc_compute_pps */
extern void hdmi_tx_write_pps_packet(unsigned char port, unsigned char *packet);

#define PPS_WORDS           0x18    /* parameter words copied: 24 words = 96 bytes */
#define PPS_BYTES           0x80    /* 128 parameter bytes in the packet; 96..127 are zero */

/* Every 31-byte group of the packet starts with these three bytes: GROUP_MARK, a flag byte and the group
   number 0..5. */
#define GROUP_MARK          0x7f
#define GROUP_FIRST         0x80
#define GROUP_LAST          0x40

/*
 * Build the 161-byte packet that TX_STEP_DSC of hdmi_tx_run_step sends (before hdmi_tx_dsc_setup) and hand it
 * to hdmi_tx_write_pps_packet, which writes it to bank 2 of the TX port.
 *
 *   port   HDMI TX port 0 or 1
 *
 * The packet is six groups of 31 bytes (the last one cut to 6 bytes):
 *   group 0: 7F 80 00, then 06 00 01 00 02 00 88 and parameter bytes 0..20
 *   group 1: 7F 00 01, parameter bytes 21..48
 *   group 2: 7F 00 02, parameter bytes 49..76
 *   group 3: 7F 00 03, parameter bytes 77..104
 *   group 4: 7F 00 04, parameter bytes 105..127, then five timing bytes
 *   group 5: 7F 40 05, then three more timing bytes
 * The parameter bytes are the 24 words of dsc_enc_pps_words, most significant byte first, followed by 32
 * zero bytes. The eight timing bytes are three halfwords and one value, each low byte first:
 *   half_0x8 - width - half_0xc - half_0xe, then half_0xc and half_0xe of the encoder record, then parameter
 *   bytes 14..15 (read high byte first) divided by 3.
 * 0x88 (136) in group 0 equals the number of parameter and timing bytes (128 + 8).
 */
void hdmi_tx_build_pps_packet(unsigned char port)
{
    unsigned char pps_bytes[PPS_BYTES];
    unsigned short timing[3];
    unsigned char packet[168];
    unsigned char i;
    unsigned short pps_half_14;
    unsigned short pps_half_14_div3;

    for (i = 0; i < PPS_WORDS; i++) {
        pps_bytes[i * 4] = dsc_enc_pps_words[i] >> 24;
        pps_bytes[i * 4 + 1] = dsc_enc_pps_words[i] >> 16;
        pps_bytes[i * 4 + 2] = dsc_enc_pps_words[i] >> 8;
        pps_bytes[i * 4 + 3] = dsc_enc_pps_words[i];
    }
    for (i = 0x60; i < PPS_BYTES; i++)
        pps_bytes[i] = 0;
    pps_half_14 = (pps_bytes[14] << 8) + pps_bytes[15];
    pps_half_14_div3 = pps_half_14 / 3;

    /* Group 0 header and the fixed bytes after it. */
    packet[2] = 0;
    timing[0] = dsc_encoder_record.half_0x8 - dsc_encoder_record.width - dsc_encoder_record.half_0xc - dsc_encoder_record.half_0xe;
    packet[0] = GROUP_MARK;
    packet[4] = 0;
    packet[1] = GROUP_FIRST;
    packet[3] = 6;
    timing[1] = dsc_encoder_record.half_0xc;
    timing[2] = dsc_encoder_record.half_0xe;
    packet[6] = 0;
    packet[8] = 0;
    packet[5] = 1;
    packet[7] = 2;
    packet[9] = 0x88;
    for (i = 0; i < 21; i++)
        packet[10 + i] = pps_bytes[i];

    /* Groups 1..4: 28 parameter bytes each (23 in group 4). */
    packet[31] = GROUP_MARK;
    packet[33] = 1;
    packet[32] = 0;
    for (i = 0; i < 28; i++)
        packet[34 + i] = pps_bytes[21 + i];
    packet[62] = GROUP_MARK;
    packet[64] = 2;
    packet[63] = 0;
    for (i = 0; i < 28; i++)
        packet[65 + i] = pps_bytes[49 + i];
    packet[93] = GROUP_MARK;
    packet[95] = 3;
    packet[94] = 0;
    for (i = 0; i < 28; i++)
        packet[96 + i] = pps_bytes[77 + i];
    packet[124] = GROUP_MARK;
    packet[126] = 4;
    packet[125] = 0;
    for (i = 0; i < 23; i++)
        packet[127 + i] = pps_bytes[105 + i];

    /* The timing bytes, split by the header of group 5 after the fifth. */
    packet[150] = timing[0];
    packet[151] = timing[0] >> 8;
    packet[155] = GROUP_MARK;
    packet[152] = timing[1];
    packet[153] = timing[1] >> 8;
    packet[156] = GROUP_LAST;
    packet[154] = timing[2];
    packet[159] = pps_half_14_div3;
    packet[157] = 5;
    packet[158] = timing[2] >> 8;
    packet[160] = pps_half_14_div3 >> 8;
    hdmi_tx_write_pps_packet(port, packet);
}
