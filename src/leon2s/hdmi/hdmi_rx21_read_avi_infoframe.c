/* hdmi_rx21_read_avi_infoframe  (FUN_a009f738)
 *
 * Read and decode the AVI InfoFrame of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 *   d: 0x58-byte block
 * Returns: 0 when read, 1 when absent
 * Name basis: proven - packet type 0x82 (AVI) checked; result 1 makes FSM_Complete print 'No AVI Info'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009f738 @ 0xa009f738-0xa009facc (916 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - K&R definition (unsigned char port);
 *  - the ten field indexes are declared in a block opened inside the success arm, and the four halfword
 *    values in a block of their own after the if;
 *  - the high bytes of half_0x3c / half_0x40 are written '(data & 0xff000000) >> 24' while the byte stores use
 *    'data >> 24';
 *  - the byte stores and field reads are in the order of this file (the RGB range store comes after the read of
 *    word 0x48).
 */

/* Table of register block addresses, one 0x34-byte row per HDMI 2.1 receiver (filled by
   hdmi_rx21_init_register_pointers): block k of receiver n is at 0xCE009000 + n * 0x1000 + k * 0x100.
   This routine reads block 1 only. */
struct rx21_reg_blocks {
    unsigned int block0;
    volatile unsigned int *block1;
    unsigned char blocks_2_to_12[0x34 - 8];
};

/* One entry of the firmware's value/text lists: a field value and the address of its printable name. */
struct value_text { unsigned int value; unsigned int text; };

/* The decoded AVI data: 0x58 bytes at +0x4C of the receiver's record (hdmi_rx21_input_records). The names of the fields
   decoded through a value/text list are those of the list; their texts are given with each field. */
struct avi_info {
    unsigned char packet_byte1;         /* bits 8..15 of the header word; 2 = the second set of fields is decoded */
    unsigned char _1[3];
    unsigned int color_format;          /* RGB, YCbCr422, YCbCr444, YCbCr420 */
    unsigned int format_info;           /* No Data, Valid: 1 = active_format below is filled */
    unsigned int bar_info;              /* Not Valid, V Valid, H Valid, HV Valid */
    unsigned int scan;                  /* No Data, Over Scan, Under Scan, Future */
    unsigned int colorimetry;           /* No Data, ITU601, ITU709, EC Valid: 3 = ext_colorimetry is filled */
    unsigned int aspect;                /* No Data, 4:3, 16:9, Future */
    unsigned int active_format;         /* 16 entries: reserved_0 .. shoot_and_protect_4_by_3 */
    unsigned int it_content;            /* No Data, IT Content (second set) */
    unsigned int ext_colorimetry;       /* xvYCC601 .. BT2020RGB or BT2020YCC (second set) */
    unsigned int rgb_range;             /* Default, Limited Range, Full Range, Reserved (second set) */
    unsigned int scaling;               /* No Scaling, H Scaling, V Scaling, HV Scaling */
    unsigned char byte_0x30;            /* bits 24..30 of data word 0 (second set) */
    unsigned char _31[3];
    unsigned int ycc_range;             /* Limited Range, Full Range, Reserved2, Reserved3 (second set) */
    unsigned char byte_0x38;            /* bits 0..3 of data word 1 (second set) */
    unsigned char _39;
    unsigned short half_0x3a, half_0x3c, half_0x3e, half_0x40;     /* bytes 1..8 of data words 1..3, in pairs */
    /* The received bytes as they are: the header word, then data words 0..2 and the low two bytes of word 3. */
    unsigned char raw_0x42, raw_0x43, raw_0x44, raw_0x45, raw_0x46, raw_0x47, raw_0x48, raw_0x49, raw_0x4a,
                  raw_0x4b, raw_0x4c, raw_0x4d, raw_0x4e, raw_0x4f, raw_0x50, raw_0x51, raw_0x52, raw_0x53;
    unsigned char _54[4];               /* +0x55..+0x57 are status bytes kept by the callers */
};

#define AVI_TYPE_CODE   0x82            /* low byte of the header word when the receiver holds AVI data */
#define AVI_INFO_SIZE   0x58

/* Word offsets of the AVI data in register block 1. */
#define AVI_REG_HEADER  (0x40 / 4)      /* bits 0..7 type code, 8..15 packet_byte1, 16..23 must be non-zero */
#define AVI_REG_DATA0   (0x44 / 4)
#define AVI_REG_DATA1   (0x48 / 4)
#define AVI_REG_DATA2   (0x4c / 4)
#define AVI_REG_DATA3   (0x50 / 4)

extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern const struct value_text hdmi_rx21_avi_color_format_names[], hdmi_rx21_avi_format_info_names[], hdmi_rx21_avi_bar_info_names[], hdmi_rx21_avi_scan_names[], hdmi_rx21_avi_colorimetry_names[];
extern const struct value_text hdmi_rx21_avi_aspect_names[], hdmi_rx21_avi_active_format_names[], hdmi_rx21_avi_scaling_names[], hdmi_rx21_avi_it_content_names[], hdmi_rx21_avi_ext_colorimetry_names[];
extern const struct value_text hdmi_rx21_avi_rgb_range_names[], hdmi_rx21_avi_ycc_range_names[];
extern void *lib_memset(void *, int, unsigned int);

/*
 * Read the AVI data that HDMI 2.1 receiver `port` (0 or 1) holds in register block 1 and decode it into `avi`.
 *
 *   port  HDMI 2.1 receiver 0 or 1
 *   avi   the receiver's AVI record (receiver record +0x4C)
 *
 * Returns 0 when the data was read, 1 when the block holds no AVI data (`avi` is then cleared).
 *
 * Called by DRV_HDMI_ModeDetect_FSM_Complete, which prints 'No AVI Info' on 1, and by
 * hdmi_rx21_service_packet_events, which compares color_format and byte_0x30 with their previous values.
 *
 * Phases:
 *   1. Header word: keep its bytes; without type code 0x82 and a non-zero byte 2 clear the record and stop.
 *   2. Data word 0: keep its bytes and look up the first set of fields (colour format .. scaling).
 *   3. Only when packet_byte1 is 2: the second set (IT content, extended colorimetry, the two ranges,
 *      byte_0x30, byte_0x38), partly from data word 1.
 *   4. Data words 1..3: keep their bytes and build the four halfwords half_0x3a .. half_0x40.
 *
 * Every field is looked up in its value/text list with the bits as index. The lists hold the index itself as
 * value, so the fields store the bits unchanged. Each index except the active format's is limited to the
 * list's last entry ('Unknown'); for the widths read here the limit never changes an index.
 */
unsigned char hdmi_rx21_read_avi_infoframe(port, avi)
    unsigned char port;
    struct avi_info *avi;
{
    unsigned int header, data;
    unsigned char ycc_range_index;

    /* Phase 1: header word. */
    header = hdmi_rx21_reg_blocks[port].block1[AVI_REG_HEADER];
    avi->raw_0x42 = header;
    avi->raw_0x44 = header >> 16;
    if ((header & 0xff) == AVI_TYPE_CODE && ((header >> 16) & 0xff) != 0) {
    unsigned char color_format_index, format_info_index, bar_info_index, scan_index, colorimetry_index, aspect_index, scaling_index, it_content_index, ext_colorimetry_index, rgb_range_index;

    /* Phase 2: data word 0 and the first set of fields. */
    data = hdmi_rx21_reg_blocks[port].block1[AVI_REG_DATA0];
    avi->raw_0x46 = data;
    avi->packet_byte1 = header >> 8;
    avi->raw_0x47 = data >> 8;
    avi->raw_0x48 = data >> 16;
    avi->raw_0x49 = data >> 24;
    avi->raw_0x43 = header >> 8;
    avi->raw_0x45 = header >> 24;
    color_format_index = (data & 0x60) >> 5;
    if (color_format_index > 3)
        color_format_index = 4;
    avi->color_format = hdmi_rx21_avi_color_format_names[color_format_index].value;
    format_info_index = (data & 0x10) >> 4;
    if (format_info_index > 1)
        format_info_index = 2;
    avi->format_info = hdmi_rx21_avi_format_info_names[format_info_index].value;
    bar_info_index = (data & 0xc) >> 2;
    if (bar_info_index > 3)
        bar_info_index = 4;
    avi->bar_info = hdmi_rx21_avi_bar_info_names[bar_info_index].value;
    scan_index = data & 3;
    if (scan_index > 3)
        scan_index = 4;
    avi->scan = hdmi_rx21_avi_scan_names[scan_index].value;
    colorimetry_index = (data >> 14) & 3;
    if (colorimetry_index > 3)
        colorimetry_index = 4;
    avi->colorimetry = hdmi_rx21_avi_colorimetry_names[colorimetry_index].value;
    aspect_index = (data >> 12) & 3;
    if (aspect_index > 3)
        aspect_index = 4;
    avi->aspect = hdmi_rx21_avi_aspect_names[aspect_index].value;
    /* The active format (bits 8..11) counts only when format_info says 'Valid'. */
    if (avi->format_info == 1)
        avi->active_format = hdmi_rx21_avi_active_format_names[(data & 0xf00) >> 8].value;
    else
        avi->active_format = 0;
    scaling_index = (data & 0x30000) >> 16;
    if (scaling_index > 3)
        scaling_index = 4;
    avi->scaling = hdmi_rx21_avi_scaling_names[scaling_index].value;

    /* Phase 3: the second set of fields, only when packet_byte1 is 2. */
    if (avi->packet_byte1 == 2) {
        it_content_index = (data >> 23) & 1;
        if (it_content_index > 1)
            it_content_index = 2;
        avi->it_content = hdmi_rx21_avi_it_content_names[it_content_index].value;
        /* Extended colorimetry (bits 20..22) counts only when colorimetry says 'EC Valid'. */
        if (avi->colorimetry == 3) {
            ext_colorimetry_index = (data >> 20) & 7;
            if (ext_colorimetry_index > 6)
                ext_colorimetry_index = 7;
            avi->ext_colorimetry = hdmi_rx21_avi_ext_colorimetry_names[ext_colorimetry_index].value;
        }
        rgb_range_index = (data >> 18) & 3;
        if (rgb_range_index > 3)
            rgb_range_index = 4;
        avi->byte_0x30 = (data & 0x7f000000) >> 24;
        data = hdmi_rx21_reg_blocks[port].block1[AVI_REG_DATA1];
        avi->rgb_range = hdmi_rx21_avi_rgb_range_names[rgb_range_index].value;
        ycc_range_index = (data & 0xc0) >> 6;
        if (ycc_range_index > 3)
            ycc_range_index = 4;
        avi->ycc_range = hdmi_rx21_avi_ycc_range_names[ycc_range_index].value;
        avi->byte_0x38 = data & 0xf;
    }
    } else {
        lib_memset(avi, 0, AVI_INFO_SIZE);
        return 1;
    }

    /* Phase 4: data words 1..3. Each halfword takes two neighbouring bytes, the lower byte first. */
    {
    unsigned int half_0x3a;
    unsigned int half_0x3c;
    unsigned int half_0x3e;
    unsigned int half_0x40;
    data = hdmi_rx21_reg_blocks[port].block1[AVI_REG_DATA1];
    half_0x3a = (data & 0xffff00) >> 8;
    avi->raw_0x4b = data >> 8;
    avi->raw_0x4c = data >> 16;
    avi->raw_0x4d = data >> 24;
    avi->raw_0x4a = data;
    half_0x3c = (data & 0xff000000) >> 24;
    data = hdmi_rx21_reg_blocks[port].block1[AVI_REG_DATA2];
    avi->raw_0x4f = data >> 8;
    avi->raw_0x50 = data >> 16;
    avi->raw_0x51 = data >> 24;
    avi->raw_0x4e = data;
    half_0x3c |= (data & 0xff) << 8;
    half_0x3e = (data & 0xffff00) >> 8;
    half_0x40 = (data & 0xff000000) >> 24;
    data = hdmi_rx21_reg_blocks[port].block1[AVI_REG_DATA3];
    half_0x40 |= (data & 0xff) << 8;
    avi->half_0x3a = half_0x3a;
    avi->half_0x3c = half_0x3c;
    avi->half_0x3e = half_0x3e;
    avi->raw_0x53 = data >> 8;
    avi->raw_0x52 = data;
    avi->half_0x40 = half_0x40;
    }
    return 0;
}
