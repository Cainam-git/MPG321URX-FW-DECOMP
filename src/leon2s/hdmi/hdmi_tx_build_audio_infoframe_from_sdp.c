/* hdmi_tx_build_audio_infoframe_from_sdp  (FUN_a00a8f28)
 *
 * Build an InfoFrame with 10 payload bytes (audio size) from a DP SDP packet.
 *   src: SDP bytes
 *   dst: packet
 * Name basis: derived - header bytes 1, 4, 5 + 10 bytes (the audio InfoFrame length), byte 3 = checksum;
 *   caller CONV2HDMITX_UpdatePacket
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a8f28 (leaf), flags -mcpu=v8 -Os -g.
 * Source form: both sides are structs, so the payload stores and the checksum accesses are separate fields
 * that GCC may reorder (the firmware loads the checksum before the payload store).
 */
struct dp_sdp_source {
    unsigned char byte_0;
    unsigned char type;                 /* +1 */
    unsigned char byte_2;
    unsigned char byte_3;
    unsigned char version;              /* +4 */
    unsigned char length;               /* +5 */
    unsigned char payload[27];          /* +6 */
};
struct hdmi_infoframe {
    unsigned char type;
    unsigned char version;
    unsigned char length;
    unsigned char checksum;
    unsigned char payload[27];
};

/*
 * Same as hdmi_tx_build_infoframe_from_sdp, but only 10 payload bytes are copied and summed. Called by
 * CONV2HDMITX_UpdatePacket for the audio InfoFrame.
 *   src: packet bytes of the DP input
 *   dst: InfoFrame to fill
 */
void hdmi_tx_build_audio_infoframe_from_sdp(struct dp_sdp_source *src, struct hdmi_infoframe *dst)
{
    unsigned char i;

    dst->type = src->type;
    dst->version = src->version;
    dst->length = src->length;
    dst->checksum = dst->type + dst->version + dst->length;
    for (i = 0; i < 10; i++) {
        dst->payload[i] = src->payload[i];
        dst->checksum += dst->payload[i];
    }
    dst->checksum = -dst->checksum;
}
