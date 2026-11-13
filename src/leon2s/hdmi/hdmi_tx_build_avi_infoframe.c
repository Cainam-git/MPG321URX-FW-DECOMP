/* hdmi_tx_build_avi_infoframe  (FUN_a00a9020)
 *
 * Build an AVI InfoFrame for an HDMI output from the colour format of a DP input.
 *   dp_word_fc: DP record word +0xFC; byte 8 low bits are 1 when it is below 0x1A
 *   dp_format: 4 format bytes
 *   avi_packet: 9-byte packet
 * Name basis: proven - header 0x82 / 2 / 0x0D with checksum; colour fields from four DP format bytes; caller
 *   CONV2HDMITX_UpdateInterface
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a9020 @ 0xa00a9020-0xa00a9380 (864 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the six values live in a local struct of ints that is first cleared with lib_memset;
 *  - case 0 is listed with the same body as the default (jump table from 0); the case order 0, 8, 0xa, 0xc,
 *    0x1a, 0x1c, 2, 4, 0x12, 0x14, 0x18 and the store order inside the cases (cross-jumped tails);
 *  - dp_format[2] read into an unsigned char, copied to an int for the high-nibble tests, and the second switch
 *    on an unsigned char low nibble (gives the firmware's separate 'and 0xff' copy);
 *  - the checksum seed loaded from avi_packet[3] in the for initialiser.
 * Jump tables at 0xa00a8f8c (8 entries) and 0xa00a8fac (29 entries).
 */
extern void *lib_memset(void *, int, unsigned int);

/* Field values, named by the texts of the receiver's AVI value/text lists (hdmi_rx21_avi_*_names). */
enum {
    AVI_COLOR_RGB      = 0,             /* color_format */
    AVI_COLOR_YCBCR422 = 1,
    AVI_COLOR_YCBCR444 = 2,
    AVI_COLOR_YCBCR420 = 3
};
enum {
    AVI_COLORIMETRY_NO_DATA  = 0,       /* colorimetry */
    AVI_COLORIMETRY_ITU601   = 1,
    AVI_COLORIMETRY_ITU709   = 2,
    AVI_COLORIMETRY_EC_VALID = 3        /* ext_colorimetry holds the value */
};
enum {
    AVI_EXT_XVYCC601    = 0,            /* ext_colorimetry */
    AVI_EXT_XVYCC709    = 1,
    AVI_EXT_SYCC601     = 2,
    AVI_EXT_ADOBEYCC601 = 3,
    AVI_EXT_ADOBERGB    = 4,
    AVI_EXT_BT2020CYCC  = 5,
    AVI_EXT_BT2020      = 6,            /* 'BT2020RGB or BT2020YCC' */
    AVI_EXT_UNKNOWN     = 7             /* the list's last entry, 'Unknown' */
};
enum {
    AVI_RGB_RANGE_DEFAULT = 0,          /* rgb_range */
    AVI_RGB_RANGE_LIMITED = 1,
    AVI_RGB_RANGE_FULL    = 2
};
enum {
    AVI_YCC_RANGE_LIMITED = 0,          /* ycc_range */
    AVI_YCC_RANGE_FULL    = 1
};

#define AVI_TYPE_CODE     0x82          /* avi_packet[0..2]: the header the receiver side tests */
#define AVI_PACKET_BYTE1  2             /* the value with which the receiver also decodes its second set of fields */
#define AVI_PACKET_BYTE2  0x0d
#define DP_WORD_FC_LIMIT  0x1a          /* byte8_low = 1 below it */

/* in[] bits that the choice depends on. */
#define DP_FORMAT1_BIT6   0x40          /* dp_format[1]: choose by dp_format[2] instead of dp_format[0] */
#define DP_FORMAT1_BIT7   0x80          /* dp_format[1]: without bit 6, keep the cleared colour fields */
#define DP_FORMAT0_FIELD  0x1e          /* dp_format[0] bits 1..4 */

struct avi_fields {
    int color_format;                   /* avi_packet[4] bits 5..6 */
    int colorimetry;                    /* avi_packet[5] bits 6..7 */
    int ext_colorimetry;                /* avi_packet[6] bits 4..6 */
    int rgb_range;                      /* avi_packet[6] bits 2..3 */
    int ycc_range;                      /* avi_packet[8] bits 6..7 */
    int byte8_low;                      /* avi_packet[8] bits 0..5 (0 or 1 here) */
};

/*
 * Build the AVI packet that an HDMI output sends for a DisplayPort input, from four format bytes of the DP
 * input's record.
 *
 *   dp_word_fc   the DP record word +0xFC (CONV2HDMITX_UpdateInterface also takes it, times the colour depth
 *                / 8, as the pixel clock of the output)
 *   dp_format    DP record bytes +0xF2..+0xF5
 *   avi_packet   9 bytes out: header 0..2, checksum 3, fields 4..8
 *
 * Called by CONV2HDMITX_UpdateInterface for a DisplayPort input, which passes the packet on to
 * hdmi_tx_update_avi_payload. avi_packet[7] is not written here; that caller clears the buffer first.
 *
 * The packet is laid out like the receiver's registers that hdmi_rx21_read_avi_infoframe decodes: bytes 0..3
 * = the header word, 4..7 = data word 0, 8 = the low byte of data word 1; each field sits where the receiver
 * reads the field of the same name.
 *
 * Phases:
 *   1. Clear the fields.
 *   2. dp_format[1] bit 6 clear: rgb_range Full, ycc_range Limited; unless dp_format[1] bit 7 is set, colour
 *      format, colorimetry and extended colorimetry come from dp_format[0] bits 1..4.
 *   3. dp_format[1] bit 6 set, by the high nibble of dp_format[2]:
 *        0           RGB with extended colorimetry from the low nibble; rgb_range Full when dp_format[3]
 *                    bit 7 is clear, else Limited;
 *        1 / 2 / 3   YCbCr444 / YCbCr422 / YCbCr420; colorimetry from the low nibble; ycc_range Full when
 *                    dp_format[3] bit 7 is clear, else Limited;
 *        above 3     RGB, AdobeRGB.
 *   4. byte8_low = 1 when dp_word_fc is below 0x1A.
 *   5. Write the header and the fields, then the checksum: the nine bytes add up to 0 (modulo 256).
 */
void hdmi_tx_build_avi_infoframe(unsigned int dp_word_fc, unsigned char *dp_format, unsigned char *avi_packet)
{
    struct avi_fields s;
    int in2, in2_high;
    unsigned char i;
    unsigned char sum;
    unsigned char in2_byte, in2_low;

    /* Phase 1. */
    lib_memset(&s, 0, sizeof s);
    if (!(dp_format[1] & DP_FORMAT1_BIT6)) {
        /* Phase 2. */
        s.rgb_range = AVI_RGB_RANGE_FULL;
        s.ycc_range = AVI_YCC_RANGE_LIMITED;
        if (!(dp_format[1] & DP_FORMAT1_BIT7)) {
            switch (dp_format[0] & DP_FORMAT0_FIELD) {
            case 0:
                s.colorimetry = AVI_COLORIMETRY_NO_DATA;
                s.ext_colorimetry = AVI_EXT_XVYCC601;
                s.color_format = AVI_COLOR_RGB;
                break;
            case 8:
                s.rgb_range = AVI_RGB_RANGE_LIMITED;
                s.colorimetry = AVI_COLORIMETRY_NO_DATA;
                s.ext_colorimetry = AVI_EXT_XVYCC601;
                s.color_format = AVI_COLOR_RGB;
                break;
            case 0xa:
                s.colorimetry = AVI_COLORIMETRY_ITU601;
                s.color_format = AVI_COLOR_YCBCR422;
                s.ext_colorimetry = AVI_EXT_XVYCC601;
                break;
            case 0xc:
                s.colorimetry = AVI_COLORIMETRY_ITU601;
                s.color_format = AVI_COLOR_YCBCR444;
                s.ext_colorimetry = AVI_EXT_XVYCC601;
                break;
            case 0x1a:
                s.colorimetry = AVI_COLORIMETRY_ITU709;
                s.color_format = AVI_COLOR_YCBCR422;
                s.ext_colorimetry = AVI_EXT_XVYCC601;
                break;
            case 0x1c:
                s.colorimetry = AVI_COLORIMETRY_ITU709;
                s.color_format = AVI_COLOR_YCBCR444;
                s.ext_colorimetry = AVI_EXT_XVYCC601;
                break;
            case 2:
                s.colorimetry = AVI_COLORIMETRY_EC_VALID;
                s.color_format = AVI_COLOR_YCBCR422;
                s.ext_colorimetry = AVI_EXT_XVYCC601;
                break;
            case 4:
                s.colorimetry = AVI_COLORIMETRY_EC_VALID;
                s.color_format = AVI_COLOR_YCBCR444;
                s.ext_colorimetry = AVI_EXT_XVYCC601;
                break;
            case 0x12:
                s.colorimetry = AVI_COLORIMETRY_EC_VALID;
                s.ext_colorimetry = AVI_EXT_XVYCC709;
                s.color_format = AVI_COLOR_YCBCR422;
                break;
            case 0x14:
                s.colorimetry = AVI_COLORIMETRY_EC_VALID;
                s.ext_colorimetry = AVI_EXT_XVYCC709;
                s.color_format = AVI_COLOR_YCBCR444;
                break;
            case 0x18:
                s.colorimetry = AVI_COLORIMETRY_EC_VALID;
                s.ext_colorimetry = AVI_EXT_ADOBERGB;
                s.color_format = AVI_COLOR_RGB;
                break;
            default:
                s.colorimetry = AVI_COLORIMETRY_NO_DATA;
                s.ext_colorimetry = AVI_EXT_XVYCC601;
                s.color_format = AVI_COLOR_RGB;
                break;
            }
        }
    } else {
        /* Phase 3. */
        in2_byte = dp_format[2];
        in2 = in2_byte;
        in2_high = in2 & 0xf0;
        if (in2_high == 0) {
            /* RGB; the low nibble picks the extended colorimetry. */
            s.color_format = AVI_COLOR_RGB;
            switch (in2 & 0xf) {
            case 3:
                s.colorimetry = AVI_COLORIMETRY_EC_VALID;
                s.ext_colorimetry = AVI_EXT_ADOBERGB;
                break;
            case 4:
                s.colorimetry = AVI_COLORIMETRY_EC_VALID;
                s.ext_colorimetry = AVI_EXT_UNKNOWN;
                break;
            case 6:
                s.colorimetry = AVI_COLORIMETRY_EC_VALID;
                s.ext_colorimetry = AVI_EXT_BT2020;
                break;
            default:
                s.colorimetry = AVI_COLORIMETRY_EC_VALID;
                s.ext_colorimetry = AVI_EXT_ADOBERGB;
                break;
            }
            s.rgb_range = ((signed char)dp_format[3] >= 0) ? AVI_RGB_RANGE_FULL : AVI_RGB_RANGE_LIMITED;
            s.ycc_range = AVI_YCC_RANGE_LIMITED;
        } else if (in2_high >= 0x10 && in2_high <= 0x30) {
            /* YCbCr; the low nibble picks the colorimetry. */
            switch (in2_high) {
            case 0x10:
                s.color_format = AVI_COLOR_YCBCR444;
                break;
            case 0x20:
                s.color_format = AVI_COLOR_YCBCR422;
                break;
            case 0x30:
                s.color_format = AVI_COLOR_YCBCR420;
                break;
            default:
                s.color_format = AVI_COLOR_YCBCR444;
                break;
            }
            in2_low = in2_byte & 0xf;
            switch (in2_low) {
            case 0:
                s.colorimetry = AVI_COLORIMETRY_ITU601;
                s.ext_colorimetry = AVI_EXT_XVYCC601;
                break;
            case 1:
                s.colorimetry = AVI_COLORIMETRY_ITU709;
                s.ext_colorimetry = AVI_EXT_XVYCC601;
                break;
            case 2:
                s.colorimetry = AVI_COLORIMETRY_EC_VALID;
                s.ext_colorimetry = AVI_EXT_XVYCC601;
                break;
            case 3:
                s.colorimetry = AVI_COLORIMETRY_EC_VALID;
                s.ext_colorimetry = AVI_EXT_XVYCC709;
                break;
            case 4:
                s.colorimetry = AVI_COLORIMETRY_EC_VALID;
                s.ext_colorimetry = AVI_EXT_SYCC601;
                break;
            case 5:
                s.colorimetry = AVI_COLORIMETRY_EC_VALID;
                s.ext_colorimetry = AVI_EXT_ADOBEYCC601;
                break;
            case 6:
                s.colorimetry = AVI_COLORIMETRY_EC_VALID;
                s.ext_colorimetry = AVI_EXT_BT2020CYCC;
                break;
            case 7:
                s.colorimetry = AVI_COLORIMETRY_EC_VALID;
                s.ext_colorimetry = AVI_EXT_BT2020;
                break;
            default:
                s.colorimetry = AVI_COLORIMETRY_ITU601;
                s.ext_colorimetry = AVI_EXT_XVYCC601;
                break;
            }
            s.ycc_range = (signed char)dp_format[3] >= 0;      /* bit 7 clear: AVI_YCC_RANGE_FULL */
            s.rgb_range = AVI_RGB_RANGE_DEFAULT;
        } else {
            s.colorimetry = AVI_COLORIMETRY_EC_VALID;
            s.ext_colorimetry = AVI_EXT_ADOBERGB;
            s.color_format = AVI_COLOR_RGB;
            s.rgb_range = AVI_RGB_RANGE_DEFAULT;
            s.ycc_range = AVI_YCC_RANGE_LIMITED;
        }
    }

    /* Phase 4. */
    if (dp_word_fc < DP_WORD_FC_LIMIT)
        s.byte8_low = 1;
    else
        s.byte8_low = 0;

    /* Phase 5: header, fields, checksum. */
    avi_packet[0] = AVI_TYPE_CODE;
    avi_packet[1] = AVI_PACKET_BYTE1;
    avi_packet[2] = AVI_PACKET_BYTE2;
    avi_packet[4] = s.color_format << 5;
    avi_packet[5] = s.colorimetry << 6;
    avi_packet[6] = (s.ext_colorimetry << 4) | (s.rgb_range << 2);
    avi_packet[8] = (s.ycc_range << 6) | s.byte8_low;
    avi_packet[3] = AVI_TYPE_CODE + AVI_PACKET_BYTE1 + AVI_PACKET_BYTE2;
    for (i = 0, sum = avi_packet[3]; i < 5; i++)
        sum += avi_packet[4 + i];
    avi_packet[3] = -sum;
}
