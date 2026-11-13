/* hdr_read_hdr10plus_metadata  (FUN_a0061d60)
 *
 * Read the 27 HDR10+ infoframe bytes from the receiver and unpack them into the metadata record.
 * Note: Reads through the receiver selected by hdr_select_metadata_receiver.
 * Name basis: proven - fields knee_point_x/y, num_bezier_curve_anchors, bezier_curve_anchor, targeted
 *   luminance named by the dump prints
 *
 * Matching notes
 * --------------
 * FUN_a0061d60 (leon2s 0xa0061d60-0xa0061eb4, 340 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the record fields are written in ascending order of the source bytes.
 */
/*
 * The HDR10+ metadata record (0x8A bytes), as far as this routine fills it. Field names are the ones the firmware
 * prints when it dumps the record.
 */
struct hdr10plus_metadata_record {
    unsigned char byte_0x00;
    unsigned char tone_mapping_flag;            /* +0x01 */
    unsigned short knee_point_x;                /* +0x02 */
    unsigned short knee_point_y;                /* +0x04 */
    unsigned char byte_0x06;                    /* +0x06 */
    unsigned char percentile_count;             /* +0x07: not set here */
    unsigned short percentile_value[20];        /* +0x08 */
    unsigned short percentile_key[20];          /* +0x30: not set here */
    unsigned char num_bezier_curve_anchors;     /* +0x58 */
    unsigned char byte_0x59;                    /* +0x59 */
    unsigned short bezier_curve_anchor[15];     /* +0x5A */
    unsigned char pad_0x78[0x88 - 0x78];        /* +0x78: scene_max_0..2 at +0x82 are not set here */
    unsigned short targeted_system_display_maximum_luminance;  /* +0x88 */
};
extern struct hdr10plus_metadata_record hdr10plus_metadata;
extern unsigned char hdr10plus_packet_bytes[];
extern unsigned char hdr_meta_receiver_index;
extern unsigned short hdr_meta_reg_byte0;
extern unsigned char (*hdr_meta_reg_read_fn)(unsigned char, unsigned short);

#define HDR10PLUS_PACKET_BYTES 0x1b             /* 27 bytes are read */
#define HDR10PLUS_ANCHORS_READ 9                /* bezier anchors taken from the packet (packet bytes 0x12..0x1a) */

/*
 * Read the 27 HDR10+ packet bytes from the receiver and unpack them into hdr10plus_metadata.
 *
 * The bytes are read one by one with hdr_meta_reg_read_fn from receiver hdr_meta_receiver_index, starting at the
 * register hdr_meta_reg_byte0, and kept in hdr10plus_packet_bytes. Then, with b = hdr10plus_packet_bytes:
 *   targeted display maximum luminance = (b[4] & 0x3e) << 4
 *   percentile values 0..8             = b[6..0xe] << 4 (b[8], value 2, is not shifted)
 *   num_bezier_curve_anchors           = b[0xf] >> 4
 *   knee_point_x                       = (b[0xf] & 0xf) << 6 | (b[0x10] & 0xfc)
 *   knee_point_y                       = ((b[0x10] & 3) << 6 | b[0x11]) << 2
 *   bezier anchors 0..8                = b[0x12..0x1a] << 2
 *   tone_mapping_flag                  = 0
 * The percentile count and keys, the scene maxima and the other bytes of the record are left as they were.
 */
void hdr_read_hdr10plus_metadata(void)
{
    unsigned char i;
    for (i = 0; i < HDR10PLUS_PACKET_BYTES; i++)
        hdr10plus_packet_bytes[i] = hdr_meta_reg_read_fn(hdr_meta_receiver_index, hdr_meta_reg_byte0 + i);
    hdr10plus_metadata.targeted_system_display_maximum_luminance = (hdr10plus_packet_bytes[4] & 0x3e) << 4;
    hdr10plus_metadata.percentile_value[0] = hdr10plus_packet_bytes[6] << 4;
    hdr10plus_metadata.percentile_value[1] = hdr10plus_packet_bytes[7] << 4;
    hdr10plus_metadata.percentile_value[2] = hdr10plus_packet_bytes[8];
    hdr10plus_metadata.percentile_value[3] = hdr10plus_packet_bytes[9] << 4;
    hdr10plus_metadata.percentile_value[4] = hdr10plus_packet_bytes[0xa] << 4;
    hdr10plus_metadata.percentile_value[5] = hdr10plus_packet_bytes[0xb] << 4;
    hdr10plus_metadata.percentile_value[6] = hdr10plus_packet_bytes[0xc] << 4;
    hdr10plus_metadata.percentile_value[7] = hdr10plus_packet_bytes[0xd] << 4;
    hdr10plus_metadata.percentile_value[8] = hdr10plus_packet_bytes[0xe] << 4;
    hdr10plus_metadata.num_bezier_curve_anchors = hdr10plus_packet_bytes[0xf] >> 4;
    hdr10plus_metadata.knee_point_x = (hdr10plus_packet_bytes[0xf] & 0xf) << 6 | (hdr10plus_packet_bytes[0x10] & 0xfc);
    hdr10plus_metadata.knee_point_y = ((hdr10plus_packet_bytes[0x10] & 3) << 6 | hdr10plus_packet_bytes[0x11]) << 2;
    for (i = 0; i < HDR10PLUS_ANCHORS_READ; i++)
        hdr10plus_metadata.bezier_curve_anchor[i] = hdr10plus_packet_bytes[0x12 + i] << 2;
    hdr10plus_metadata.tone_mapping_flag = 0;
}
