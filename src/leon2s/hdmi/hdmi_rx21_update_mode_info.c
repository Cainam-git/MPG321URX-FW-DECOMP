/* hdmi_rx21_update_mode_info  (H_Total)
 *
 * Fill the mode info of an HDMI 2.1 input from its timing registers and check it.
 *   port: HDMI 2.1 receiver 0/1
 *   info: mode info block
 *   compressed: 1 = compressed timing
 * Returns: 1 when valid
 * Name basis: proven - prints 'Update ModeInfo HDMI Mode, Color Depth, H_Total, V_Total, DE, DE_Line, P/I',
 *   'Invalid Value of H_Total'
 *
 * Matching notes
 * --------------
 * H_Total (leon2s 0xa009e00c-0xa009e368, 860 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the record's colour depth is read through the mode_info member of the receiver record
 *    (hdmi_rx21_input_records[p].mode_info.color_depth), the same struct type as `info`; with that the compiler proves
 *    the field does not overlap the stores through `info`, as in the firmware's schedule;
 *  - the htotal sum of the compressed path is written plainly in field order; the tail stores are direct;
 *  - the record's byte +0x19 is read (not info->color_depth) for the vtotal call and the final copy.
 */

#define HDMI_MSG_MODEDET_FLOW   0x04    /* dbg_hdmi_message_flags bit 2: '[MODEDET]' lines */
#define MODE_COMPRESSED         1       /* the caller passes 1 when the input has a CVTEM */

/* Register block addresses of an HDMI 2.1 receiver (13 words, hdmi_rx21_reg_blocks). Used here: block 0, block 8
   (+0x20) and block 11 (+0x2C). */
struct rx21_reg_blocks {
    volatile unsigned int *block0;
    unsigned int blocks_1_to_7[7];
    volatile unsigned int *block8;
    unsigned int blocks_9_to_10[2];
    volatile unsigned int *block11;
    unsigned int block12;
};

/* Mode info of an HDMI 2.1 receiver, at +0x18 of its record (record offsets in the comments). */
struct rx21_mode_info {
    unsigned char hdmi_mode;            /* +0x18 'HDMI Mode' */
    unsigned char color_depth;          /* +0x19 'Color Depth' (bits per colour) */
    unsigned short htotal;              /* +0x1A 'H_Total' */
    unsigned short vtotal;              /* +0x1C 'V_Total' */
    unsigned short hactive;             /* +0x1E 'DE' */
    unsigned short vactive;             /* +0x20 'DE_Line' */
    unsigned char interlaced;           /* +0x22 'P/I' */
    unsigned char byte_0x23;
    unsigned short hsync_width;         /* +0x24 */
    unsigned short vsync_width;         /* +0x26 */
    unsigned short hfront_porch;        /* +0x28 */
    unsigned short vback_porch;         /* +0x2A */
    unsigned char byte_0x2c;
    unsigned char cvtem_present;        /* +0x2D */
    unsigned char pixel_repetition;     /* +0x2E: hdmi_rx21_calc_tmds_clock multiplies by this + 1 */
    unsigned char bytes_0x2f[5];        /* +0x2F..+0x33 (pixel clock at +0x32) */
    unsigned short mode_word_34;        /* +0x34 (hdmi_rx21_get_mode_word_34) */
};

/* The record of one HDMI 2.1 receiver (400 bytes, hdmi_rx21_input_records); only the mode info is used here. */
struct rx21_record {
    unsigned char bytes_0x0[0x18];
    struct rx21_mode_info mode_info;
    unsigned char rest[0x190 - 0x18 - sizeof(struct rx21_mode_info)];
};
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern struct rx21_record hdmi_rx21_input_records[];
extern unsigned char hdmi_rx21_two_port_mode_flags[];     /* timing shift (pixels per clock) of each receiver */
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);
extern unsigned char hdmi_rx21_status30_bit4(unsigned char);
extern unsigned short hdmi_rx21_calc_reg50_ratio(unsigned char);
extern unsigned short hdmi_rx21_read_vtotal(unsigned char, unsigned char);
extern unsigned char hdmi_rx21_is_interlaced(unsigned char);

/*
 * Fill the mode info `info` of HDMI 2.1 receiver `port` from its timing registers and check it. Called by
 * DRV_HDMI_ModeDetect_FSM_Complete with info = the mode info of the port's own record (+0x18) and
 * compressed = 1 when hdmi_rx21_has_cvtem reported a CVTEM; that caller goes back to the standby state on 0.
 *
 * hdmi_mode = bit 4 of status word 0x30. Then the timing, from one of two register sets:
 *   compressed  hactive / vactive from block 11 words 3 / 4, hsync width and front porch from block 11 words
 *               0x21 / 0x22, vsync width from block 0 words 0x18 / 0x19, vback porch from
 *               hdmi_rx21_calc_reg50_ratio, htotal = hactive + hsync width + front porch + the 16 bits in
 *               block 11 words 0x22 / 0x23, vtotal from hdmi_rx21_read_vtotal (with the record's colour
 *               depth); cvtem_present = 1.
 *   otherwise   all from block 0 (words 0x0E..0x19); the horizontal values are shifted left by the
 *               receiver's timing shift (hdmi_rx21_two_port_mode_flags); the front porch is the register field + 1;
 *               cvtem_present = 0.
 * Both: interlaced from hdmi_rx21_is_interlaced, mode_word_34 = block 8 word 0x15 >> 2 (shifted),
 * pixel_repetition = bits 6..7 of block 0 word 2, colour depth copied from the record.
 *
 * Returns 0 when htotal, vtotal, hactive or vactive is 0 (with the 'Invalid Value' print), when vtotal is 1,
 * or when a compressed input has vback porch 0; else 1.
 */
int hdmi_rx21_update_mode_info(unsigned int port, struct rx21_mode_info *info, unsigned char compressed)
{
    unsigned char p = port;

    info->hdmi_mode = hdmi_rx21_status30_bit4(p);
    if (compressed == MODE_COMPRESSED) {
        info->hactive = ((hdmi_rx21_reg_blocks[p].block11[3] >> 24) << 8) + (hdmi_rx21_reg_blocks[p].block11[4] & 0xff);
        info->vactive = (((hdmi_rx21_reg_blocks[p].block11[3] >> 8) & 0xff) << 8) + ((hdmi_rx21_reg_blocks[p].block11[3] >> 16) & 0xff);
        info->hsync_width = (((hdmi_rx21_reg_blocks[p].block11[0x22] >> 16) & 0xff) << 8) + ((hdmi_rx21_reg_blocks[p].block11[0x22] >> 8) & 0xff);
        info->hfront_porch = ((hdmi_rx21_reg_blocks[p].block11[0x22] & 0xff) << 8) + (hdmi_rx21_reg_blocks[p].block11[0x21] >> 24);
        info->vsync_width = ((hdmi_rx21_reg_blocks[p].block0[0x19] & 3) << 8) | (hdmi_rx21_reg_blocks[p].block0[0x18] >> 24);
        info->vback_porch = hdmi_rx21_calc_reg50_ratio(p);
        info->htotal = info->hactive + info->hsync_width + info->hfront_porch + (((hdmi_rx21_reg_blocks[p].block11[0x23] & 0xff) << 8) + (hdmi_rx21_reg_blocks[p].block11[0x22] >> 24));

        info->vtotal = hdmi_rx21_read_vtotal(p, hdmi_rx21_input_records[p].mode_info.color_depth);
        info->cvtem_present = 1;
    } else {
        info->htotal = (hdmi_rx21_reg_blocks[p].block0[0xe] >> 16) << hdmi_rx21_two_port_mode_flags[p];
        info->vtotal = hdmi_rx21_reg_blocks[p].block0[0xf];
        info->hactive = (hdmi_rx21_reg_blocks[p].block0[0x13] >> 16) << hdmi_rx21_two_port_mode_flags[p];
        info->vactive = hdmi_rx21_reg_blocks[p].block0[0x14];
        info->hsync_width = (((hdmi_rx21_reg_blocks[p].block0[0x17] & 3) << 8) | (hdmi_rx21_reg_blocks[p].block0[0x16] >> 24)) << hdmi_rx21_two_port_mode_flags[p];
        info->vsync_width = ((hdmi_rx21_reg_blocks[p].block0[0x19] & 3) << 8) | (hdmi_rx21_reg_blocks[p].block0[0x18] >> 24);
        info->hfront_porch = (((hdmi_rx21_reg_blocks[p].block0[0x16] >> 8) & 0x3ff) + 1) << hdmi_rx21_two_port_mode_flags[p];
        info->vback_porch = ((hdmi_rx21_reg_blocks[p].block0[0x18] >> 8) & 0x300) | ((hdmi_rx21_reg_blocks[p].block0[0x18] >> 8) & 0xff);
        info->cvtem_present = 0;
    }
    info->interlaced = hdmi_rx21_is_interlaced(p);
    info->mode_word_34 = (hdmi_rx21_reg_blocks[p].block8[0x15] >> 2) << hdmi_rx21_two_port_mode_flags[p];
    info->pixel_repetition = (hdmi_rx21_reg_blocks[p].block0[2] & 0xc0) >> 6;
    info->color_depth = hdmi_rx21_input_records[p].mode_info.color_depth;
    if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
        dbg_printf("[MODEDET]: Port%c Update ModeInfo HDMI Mode = %d, Color Depth = %d, H_Total = %d, V_Total = %d, DE = %d, DE_Line = %d, P/I = %d\n",
                     (char)(port + 'A'), info->hdmi_mode, info->color_depth, info->htotal, info->vtotal, info->hactive, info->vactive, info->interlaced);
    if (info->htotal == 0 || info->vtotal == 0 || info->hactive == 0 || info->vactive == 0) {
        if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
            dbg_print_string("[MODEDET]: There Is Invalid Value of H_Total/V_Total/DE/DE_Line!!");
        return 0;
    }
    if (info->vtotal == 1)
        return 0;
    if (info->vback_porch == 0 && compressed == MODE_COMPRESSED)
        return 0;
    return 1;
}
