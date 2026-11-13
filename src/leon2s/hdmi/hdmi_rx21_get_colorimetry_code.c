/* hdmi_rx21_get_colorimetry_code  (FUN_a00a1e28)
 *
 * Return a colour-space code from the colour format and colorimetry of an HDMI 2.1 input.
 *   port: receiver
 * Returns: colour-space code
 * Name basis: derived - combines colour format (+0x50), AVI colorimetry (+0x60, 3 = extended) and extended
 *   colorimetry 5/6 (BT.2020)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a1e28 @ 0xa00a1e28-0xa00a1f84, flags -mcpu=v8 -Os -g (leaf).
 * Source forms the exact build depends on:
 *  - the color_format != RGB arm comes first;
 *  - in the RGB arm 'code = rgb_range != 1; code += 0x1a;' as two statements (one expression folds to
 *    mov 0x1b / addx);
 *  - the BT.2020 test is the unsigned 'ext_colorimetry - 5 < 2'.
 */

/* The record of one HDMI 2.1 receiver (400 bytes, hdmi_rx21_input_records): the fields used here. +0x50..+0x80 are
   fields of the decoded AVI data at +0x4C (struct avi_info of hdmi_rx21_read_avi_infoframe); each holds the
   index of its value/text list, whose texts are given below. */
struct rx21_record {
    unsigned char _00[0x18];
    unsigned char hdmi_mode;            /* +0x18 */
    unsigned char _19[0x50 - 0x19];
    unsigned int color_format;          /* +0x50 = AVI +0x04 */
    unsigned char _54[0x60 - 0x54];
    unsigned int colorimetry;           /* +0x60 = AVI +0x14 */
    unsigned char _64[0x70 - 0x64];
    unsigned int ext_colorimetry;       /* +0x70 = AVI +0x24 */
    unsigned int rgb_range;             /* +0x74 = AVI +0x28 */
    unsigned char _78[4];
    unsigned char avi_byte_0x30;        /* +0x7C = AVI +0x30: bits 24..30 of AVI data word 0 */
    unsigned char _7d[3];
    unsigned int ycc_range;             /* +0x80 = AVI +0x34 */
    unsigned char _84[0x185 - 0x84];
    unsigned char cvtem_bit27;          /* +0x185: bit 27 of block 11 word 2, stored by hdmi_rx21_read_cvtem */
    unsigned char _186[0x190 - 0x186];
};
extern struct rx21_record hdmi_rx21_input_records[];

/* List indexes compared here (texts of the firmware's AVI value/text lists). */
#define COLOR_FORMAT_RGB        0       /* 'RGB' */
#define COLOR_FORMAT_YCBCR422   1       /* 'YCbCr422' */
#define COLOR_FORMAT_YCBCR420   3       /* 'YCbCr420' */
#define COLORIMETRY_ITU709      2       /* 'ITU709' */
#define COLORIMETRY_EC_VALID    3       /* 'EC Valid': ext_colorimetry applies */
#define EXT_XVYCC709            1       /* 'xvYCC709' */
#define EXT_BT2020_CYCC         5       /* 'BT2020cYCC' */
#define EXT_BT2020_RGB_YCC      6       /* 'BT2020RGB or BT2020YCC' */
#define RGB_RANGE_DEFAULT       0       /* 'Default' */
#define RGB_RANGE_LIMITED       1       /* 'Limited Range' */
#define YCC_RANGE_LIMITED       0       /* 'Limited Range' */

/*
 * Build the colour code of HDMI 2.1 receiver `port` from its decoded AVI data.
 *
 *   port  HDMI 2.1 receiver 0 or 1
 *
 * Returns the code that hdmi_rx21_run_link_state stores as the port record's colour_space when the link
 * becomes READY; a later difference in READY stores the new code and sends the link to STANDBY. It is built like
 * hdmi_get_color_format_code of the HDMI 2.0 receivers, from the AVI fields instead of the AVI registers:
 *
 *   hdmi_mode 0:                 1
 *   RGB:                         (rgb_range is not Limited ? 1 : 0), plus 0x1A for BT.2020 (ext 5 or 6)
 *   YCbCr, base by colorimetry:  EC Valid: 0x14 xvYCC709, 0x1C BT2020cYCC, 0x22 BT2020RGB/YCC, else 0xE;
 *                                ITU709: 8; anything else: 2
 *     + 1  when ycc_range is not Limited; with ycc_range Limited, when rgb_range is neither Limited nor
 *          Default, or is Default with AVI byte_0x30 equal to 1
 *     + 2  for YCbCr422 with cvtem_bit27 clear
 *     + 4  for YCbCr420
 */
unsigned char hdmi_rx21_get_colorimetry_code(unsigned char port)
{
    unsigned char code = 1;

    if (hdmi_rx21_input_records[port].hdmi_mode != 0) {
        if (hdmi_rx21_input_records[port].color_format != COLOR_FORMAT_RGB) {
            code = 2;
            if (hdmi_rx21_input_records[port].colorimetry == COLORIMETRY_EC_VALID) {
                code = 0xe;
                if (hdmi_rx21_input_records[port].ext_colorimetry == EXT_XVYCC709)
                    code = 0x14;
                else if (hdmi_rx21_input_records[port].ext_colorimetry == EXT_BT2020_CYCC)
                    code = 0x1c;
                else if (hdmi_rx21_input_records[port].ext_colorimetry == EXT_BT2020_RGB_YCC)
                    code = 0x22;
            } else if (hdmi_rx21_input_records[port].colorimetry == COLORIMETRY_ITU709) {
                code = 8;
            }
            if (hdmi_rx21_input_records[port].ycc_range == YCC_RANGE_LIMITED) {
                if (hdmi_rx21_input_records[port].rgb_range != RGB_RANGE_LIMITED) {
                    if (hdmi_rx21_input_records[port].rgb_range == RGB_RANGE_DEFAULT) {
                        if (hdmi_rx21_input_records[port].avi_byte_0x30 == 1)
                            code++;
                    } else {
                        code++;
                    }
                }
            } else {
                code++;
            }
            if (hdmi_rx21_input_records[port].color_format == COLOR_FORMAT_YCBCR422 && hdmi_rx21_input_records[port].cvtem_bit27 == 0)
                code += 2;
            if (hdmi_rx21_input_records[port].color_format == COLOR_FORMAT_YCBCR420)
                code += 4;
        } else {
            /* RGB: BT.2020 is ext_colorimetry 5 or 6. */
            if (hdmi_rx21_input_records[port].ext_colorimetry - EXT_BT2020_CYCC < 2)
            {
                code = hdmi_rx21_input_records[port].rgb_range != RGB_RANGE_LIMITED;
                code += 0x1a;
            }
            else
                code = hdmi_rx21_input_records[port].rgb_range != RGB_RANGE_LIMITED;
        }
    }
    return code;
}
