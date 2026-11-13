/* hdmi_tx_build_infoframe_from_sdp  (FUN_a00a8ec4)
 *
 * Build an InfoFrame with 27 payload bytes and checksum from a DP SDP packet.
 *   src: SDP bytes
 *   dst: packet
 * Name basis: derived - header bytes 1, 4, 5 + 27 bytes, byte 3 = checksum; caller CONV2HDMITX_UpdatePacket
 *   for DP inputs
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a8ec4 (leaf), flags -mcpu=v8 -Os -g.
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
 * Build an InfoFrame of 27 payload bytes from the bytes of a DP input's packet. Bytes 1, 4 and 5 of the source
 * become the first three bytes of the InfoFrame, the 27 bytes from +6 become its payload, and byte 3 is set to
 * the negated 8-bit sum of all the other bytes. Called by CONV2HDMITX_UpdatePacket for the extra InfoFrame.
 *   src: packet bytes of the DP input
 *   dst: InfoFrame to fill
 */
void hdmi_tx_build_infoframe_from_sdp(struct dp_sdp_source *src, struct hdmi_infoframe *dst)
{
    unsigned char i;

    dst->type = src->type;
    dst->version = src->version;
    dst->length = src->length;
    dst->checksum = dst->type + dst->version + dst->length;
    for (i = 0; i < 27; i++) {
        dst->payload[i] = src->payload[i];
        dst->checksum += dst->payload[i];
    }
    dst->checksum = -dst->checksum;
}
