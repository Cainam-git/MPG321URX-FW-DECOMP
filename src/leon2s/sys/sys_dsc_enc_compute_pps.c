/* sys_dsc_enc_compute_pps  (FUN_a00dd488)
 *
 * Compute the rate-control values and the picture parameter set of the compression encoder.
 * Name basis: proven - VESA DSC model order; from the timing record at 0xA8079538
 *
 * Matching notes
 * --------------
 * FUN_a00dd488 (leon2s 0xa00dd488-0xa00de8a8, 5152 bytes), flags -mcpu=v8 -Os -g.
 * The statements follow the order and the rounding forms of the published DSC reference model. Source forms
 * the exact build depends on:
 *  - slice_width is rounded up as 'slice_width = width / slices; if (width % slices) slice_width++;'; the
 *    doubling of bpp and the halving of work_width go through int temporaries; word6_low = word6_value is
 *    assigned right before the rate computation;
 *  - each format print is shared by its arms (the flags are set before the call);
 *  - j is initialised in its declaration (overwritten by its loop before any read), which keeps the arm stores
 *    of the format flags; is_rgb and is_simple_422 are also initialised in their declarations; k and j are two
 *    counters for the copy loop and the print loop;
 *  - groups is computed before slice_line_bytes ('line_bits = bpp * work_width; slice_line_bytes = line_bits /
 *    8; if (line_bits & 7) slice_line_bytes++;');
 *  - sum takes its terms one statement each, room is its own signed local (word5_high = 0x10000 / room is a
 *    signed division), and sum2 recomputes '0x2000 - word8_high' before adding ofs_aligned;
 *  - the ceilings are written 'q = x / y; if (x % y) q++;'; part_groups is computed before the offset chain;
 *    the shift in word8_low_full is unsigned and ofs_aligned is added in its own statement;
 *  - one unsigned int temporary tmp holds the shifted numerators of both offset ceilings, the product for
 *    word8_low_full and the divisor of word5_low;
 *  - word6_high and word5_low are computed right after that divisor; word 7 is stored before word 5, and the
 *    word 11 constant before the word10 temporary block;
 *  - the range tables are block-scope static const arrays in ROM order (rc_offsets_444, the three 4:2:2 offset
 *    rows, rc_offsets_420, then the max / min tables for 4:4:4, 4:2:2, 4:2:0); rc_offsets_444 and
 *    rc_offsets_420 are read with constant indexes and become immediates;
 *  - values shifted into the top bits are cast to unsigned int first (same code); upper halves are unsigned
 *    terms, lower halves int terms;
 *  - part_bytes * 8 is written at each use in both word 26 ceilings;
 *  - 'slice_field = slices == 16 ? 15 : slices;' (the ?: join ends the common-subexpression path), and word 26
 *    adds the shifted term first.
 */

/* The compression encoder's timing record, as in sys_dsc_enc_configure. Fields not named keep their offset. */
struct dsc_encoder_rec {
    unsigned int word_0x00;
    unsigned char bit_depth;        /* +4: 8, 10 or 12 */
    unsigned char source;           /* +5 */
    unsigned char byte_0x06;
    unsigned char format;           /* +7: DSC_FORMAT_* */
    unsigned short half[8];         /* +8 .. +0x16: [1] = width (+0xa), [5] = height (+0x12) */
    unsigned char byte_0x18;
    unsigned char slices;           /* +0x19, printed as SLICE */
    unsigned char bpp_divisor;      /* +0x1a */
    unsigned char byte_0x1b;
    unsigned int word_0x1c;
    unsigned int word_0x20;
};
extern struct dsc_encoder_rec dsc_encoder_record;
extern unsigned int dsc_enc_pps_words[27];
extern const char s_9f1cca78[];     /* "\n" */
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);
extern unsigned char sys_get_chip_revision(void);

/* Picture formats in dsc_encoder_record.format; the names are the ones this routine prints. */
#define DSC_FORMAT_RGB            0
#define DSC_FORMAT_YUV422         1
#define DSC_FORMAT_YUV420         2
#define DSC_FORMAT_YUV444         3
#define DSC_FORMAT_YUV422_SIMPLE  4

#define CHIP_REV_83               0x83  /* above it, bit 9 of encoder register 0x64 is set */

/* Encoder register at byte offset 'offset' (words 0..23 go to 0x00..0x5c, then 0x60, 0x64 and 0x9c). */
#define DSC_ENC_REGS              0xc0110000
#define DSC_ENC_REG(offset)       (*(volatile unsigned int *)(DSC_ENC_REGS | (offset)))

/* One range entry: (min << 11) + (max << 6) + offset (6 bits), from row 'row' of a min and a max table and
   from an offset row. Each of words 15..21 holds two entries: the odd one in the upper half, the even one in
   the lower half. */
#define RANGE_LOW(min_row, max_row, ofs_row, i) \
    ((min_row[i] << 11) + (max_row[i] << 6) + (ofs_row[i] & 0x3f))
#define RANGE_HIGH(min_row, max_row, ofs_row, i) \
    (((unsigned int)min_row[i] << 27) + ((unsigned int)max_row[i] << 22) + ((unsigned int)(ofs_row[i] & 0x3f) << 16))

#define RANGE_420(i)      RANGE_LOW(dsc_enc_min_qp_420[depth_row], dsc_enc_max_qp_420[depth_row], rc_offsets_420, i)
#define RANGE_422_LOW(i)  RANGE_LOW(dsc_enc_min_qp_422[row_422], dsc_enc_max_qp_422[row_422], dsc_enc_rc_offsets_422[ofs_row_422], i)
#define RANGE_422_HIGH(i) RANGE_HIGH(dsc_enc_min_qp_422[row_422], dsc_enc_max_qp_422[row_422], dsc_enc_rc_offsets_422[ofs_row_422], i)
#define RANGE_444_LOW(i)  RANGE_LOW(dsc_enc_min_qp_444[depth_row], dsc_enc_max_qp_444[depth_row], rc_offsets_444, i)
#define RANGE_444_HIGH(i) RANGE_HIGH(dsc_enc_min_qp_444[depth_row], dsc_enc_max_qp_444[depth_row], rc_offsets_444, i)

/*
 * Compute the 27 parameter words of the compression encoder from its timing record (dsc_encoder_record),
 * keep them in dsc_enc_pps_words, write them to the encoder registers at 0xC0110000 and print them.
 * Called by sys_dsc_enc_configure (mailbox command 0xA5) after it has filled the record.
 *
 * Phases:
 *   1. Read format, bit depth, width, height, slice count and bpp divisor from the record.
 *   2. Format: bits per pixel = 24 (RGB, YUV444, YUV422_SIMPLE), 16 (YUV422) or 12 (YUV420), divided by the
 *      bpp divisor; the format name is printed.
 *   3. Sizes: slice_width = width / slices rounded up; height_div10 = height / 10. For YUV422 and YUV420 bpp
 *      is doubled and the working width halved. groups = work_width / 3 rounded up; slice_line_bytes =
 *      bpp * work_width / 8 rounded up.
 *   4. Constants by bit depth (8 / 10 / 12; any other depth is treated as 8), and word8_high by bpp.
 *   5. The derived values of words 4 to 8 (formulas at each statement).
 *   6. Words 0..13: sizes, the values of phase 5, the bit-depth constants and four fixed words.
 *   7. Words 14..21: fifteen range entries, from the tables of the format: 4:2:0 for YUV420, 4:2:2 for
 *      YUV422 (row chosen by bit depth and bpp, printed as temp_idx / Ofs_422_idx), 4:4:4 for the rest.
 *   8. Words 22..26: format flags, a bit-depth constant, the group count and slice count, and the word built
 *      from the bits of height_div10 slice lines.
 *   9. Write words 0..23 to registers 0x00..0x5c, word 24 to 0x60, word 25 to 0x64 (plus bit 9 on chips above
 *      revision 0x83), word 26 to 0x9c, then print all 27 words, four per line.
 */
void sys_dsc_enc_compute_pps(void)
{
    static const signed char rc_offsets_444[15] = { 2, 0, 0, -2, -4, -6, -8, -8, -8, -10, -10, -10, -12, -12, -12 };
    static const signed char dsc_enc_rc_offsets_422[3][15] = {
        { 2, 0, 0, -2, -4, -6, -8, -8, -8, -10, -10, -10, -12, -12, -12 },
        { 6, 4, 3, 1, -1, -3, -5, -6, -7, -9, -10, -10, -12, -12, -12 },
        { 10, 8, 6, 4, 2, 0, -2, -4, -6, -8, -10, -10, -12, -12, -12 }
    };
    static const signed char rc_offsets_420[15] = { 2, 0, 0, -2, -4, -6, -8, -8, -8, -10, -10, -10, -12, -12, -12 };
    static const unsigned char dsc_enc_max_qp_444[3][15] = {
        { 2, 3, 4, 5, 6, 6, 7, 8, 8, 9, 9, 9, 9, 10, 11 },
        { 4, 6, 8, 9, 10, 10, 11, 12, 12, 13, 13, 13, 13, 14, 15 },
        { 11, 12, 13, 14, 15, 15, 15, 16, 17, 17, 18, 18, 19, 19, 21 }
    };
    static const unsigned char dsc_enc_max_qp_422[7][15] = {
        { 2, 4, 5, 6, 7, 7, 7, 8, 8, 9, 9, 9, 9, 10, 11 },
        { 1, 2, 3, 4, 5, 5, 5, 6, 6, 7, 7, 8, 8, 9, 10 },
        { 0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7 },
        { 4, 6, 7, 9, 10, 11, 11, 12, 12, 13, 13, 13, 13, 14, 15 },
        { 3, 4, 5, 7, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 14 },
        { 2, 3, 3, 5, 5, 5, 7, 7, 8, 8, 9, 9, 10, 10, 11 },
        { 6, 9, 10, 12, 14, 15, 15, 16, 16, 17, 17, 17, 17, 18, 19 }
    };
    static const unsigned char dsc_enc_max_qp_420[3][15] = {
        { 2, 4, 5, 6, 7, 7, 7, 8, 8, 9, 9, 9, 9, 10, 11 },
        { 4, 6, 8, 9, 10, 10, 11, 12, 12, 13, 13, 13, 13, 14, 15 },
        { 6, 9, 11, 12, 13, 14, 15, 16, 16, 17, 17, 17, 17, 18, 19 }
    };
    static const unsigned char dsc_enc_min_qp_444[3][15] = {
        { 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 5, 5, 5, 7, 10 },
        { 0, 2, 4, 4, 6, 6, 7, 7, 7, 7, 9, 9, 9, 11, 14 },
        { 0, 4, 8, 9, 11, 11, 11, 11, 11, 11, 13, 13, 13, 15, 20 }
    };
    static const unsigned char dsc_enc_min_qp_422[7][15] = {
        { 0, 0, 1, 2, 3, 3, 3, 3, 3, 3, 5, 5, 5, 7, 10 },
        { 0, 0, 0, 1, 2, 2, 2, 2, 2, 3, 4, 5, 5, 7, 9 },
        { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 4, 5, 5, 6 },
        { 0, 2, 3, 5, 5, 6, 6, 7, 7, 7, 8, 8, 9, 11, 14 },
        { 0, 2, 3, 4, 5, 5, 5, 6, 6, 7, 8, 8, 9, 11, 13 },
        { 0, 2, 2, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 9, 10 },
        { 0, 4, 7, 8, 10, 11, 11, 11, 11, 11, 13, 13, 13, 15, 18 }
    };
    static const unsigned char dsc_enc_min_qp_420[3][15] = {
        { 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 5, 5, 5, 7, 10 },
        { 0, 2, 3, 4, 6, 7, 7, 7, 7, 7, 9, 9, 9, 11, 14 },
        { 0, 4, 7, 8, 10, 11, 11, 11, 11, 11, 13, 13, 13, 15, 18 }
    };
    unsigned short bpp_x16;         /* bpp * 16, word 1 bits 16.. */
    unsigned short work_width;      /* slice_width, halved for YUV422 and YUV420 */
    unsigned int ofs_rem;
    unsigned char word22_value;     /* word 22 bits 16..: 12 for YUV420 when height_div10 > 7 */
    unsigned char word9_top;        /* by bit depth: 3 / 7 / 11 */
    unsigned char word5_high;
    unsigned char word9_mid;        /* by bit depth: 12 / 16 / 20 */
    unsigned short word24_low;      /* by bit depth: 2 / 8 / 0x20 */
    unsigned int word4_low;
    unsigned short bpp_recip;       /* 4096 / bpp, rounded */
    unsigned short height_div10;
    unsigned char unit_bits;        /* by bit depth: 0x30 / 0x30 / 0x40 */
    unsigned int ofs_bits;
    unsigned int ofs_aligned;
    unsigned int word7_low;
    unsigned char is_simple_422 = 0;
    unsigned int groups;
    int part_bytes;                 /* slice_line_bytes * height_div10 */
    unsigned char depth_row;        /* table row of the bit depth: 0 / 1 / 2 */
    unsigned char slice_field;
    unsigned char ofs_row_422;      /* printed as Ofs_422_idx */
    unsigned short groups_up;
    unsigned short bpp;             /* printed as BPP */
    unsigned short width;
    unsigned short word8_high;      /* chosen by bpp, 0x800..0x1800 */
    int units_up;
    unsigned char k;
    unsigned char j = 0;
    unsigned char width_mod3;
    int line_bits;
    unsigned char row_422;          /* printed as temp_idx */
    unsigned char bpp_divisor;
    unsigned char format;
    unsigned int word7_high;
    int blocks_192;
    int part_bits;
    unsigned int word25_top;
    unsigned char slices;
    unsigned int word6_low;
    unsigned char word6_value;      /* 15 when height_div10 > 7, else 0 */
    unsigned char is_420;
    unsigned char is_422_or_420;
    unsigned short height;
    unsigned short slice_width;
    unsigned short word8_low;
    unsigned short slice_line_bytes;
    unsigned char word10_a;         /* by bit depth: 11 / 15 / 19 */
    unsigned char word10_b;         /* same values */
    unsigned char is_422;
    unsigned char is_rgb = 0;
    unsigned int word8_low_full;
    unsigned char bit_depth;
    unsigned int sum;
    unsigned int groups_term;
    unsigned int part_groups;
    unsigned int sum_per_bpp;
    unsigned int sum2;
    int room;
    unsigned int word6_high;
    unsigned int word5_low;
    unsigned int word10;
    unsigned int tmp;

    /* 1. The timing record. */
    format = dsc_encoder_record.format;
    bit_depth = dsc_encoder_record.bit_depth;
    height = dsc_encoder_record.half[5];
    width = dsc_encoder_record.half[1];
    slices = dsc_encoder_record.slices;
    bpp_divisor = dsc_encoder_record.bpp_divisor;
    dbg_print_string(s_9f1cca78);
    is_420 = 0;
    is_rgb = 0;
    bpp = 0;
    word8_high = 0;
    is_422 = 0;
    ofs_row_422 = 0;
    row_422 = 0;
    is_simple_422 = 0;

    /* 2. Bits per pixel and the format flags. */
    if (format == DSC_FORMAT_RGB || format == DSC_FORMAT_YUV444 || format == DSC_FORMAT_YUV422_SIMPLE) {
        bpp = 24 / bpp_divisor;
        is_420 = 0;
        is_422 = 0;
        if (format == DSC_FORMAT_RGB) {
            is_rgb = 1;
            dbg_printf("\033[1;31mDSC_RGB\n\r\033[m");
        } else if (format == DSC_FORMAT_YUV444) {
            dbg_printf("\033[1;31mDSC_YUV444\n\r\033[m");
        } else {
            is_simple_422 = 1;
            dbg_printf("\033[1;31mDSC_YUV422_SIMPLE\n\r\033[m");
        }
    } else if (format == DSC_FORMAT_YUV422) {
        bpp = 16 / bpp_divisor;
        is_420 = 0;
        is_422 = 1;
        dbg_printf("\033[1;31mDSC_YUV422\n\r");
    } else if (format == DSC_FORMAT_YUV420) {
        bpp = 12 / bpp_divisor;
        is_420 = 1;
        is_422 = 0;
        dbg_printf("\033[1;31mDSC_YUV420\n\r\033[m");
    }

    /* 3. Sizes. */
    dbg_printf("\033[1;31mDSC_ENC_Timing_%dx%d\n\r\033[m", width, height);
    dbg_printf("\033[1;31mSLICE = %d\n\r\033[m", slices);
    slice_width = width / slices;
    if (width % slices)
        slice_width++;
    height_div10 = height / 10;
    is_422_or_420 = is_420 | is_422;
    {
        int doubled = bpp;
        if (is_422_or_420)
            doubled += doubled;
        bpp = doubled;
    }
    bpp_x16 = bpp << 4;
    dbg_printf("\033[1;31mBPP = %d\n\r\033[m", bpp);
    {
        int halved = slice_width;
        if (is_422_or_420)
            halved >>= 1;
        work_width = halved;
    }
    groups = (work_width + 2) / 3;
    line_bits = bpp * work_width;
    slice_line_bytes = line_bits / 8;
    if (line_bits & 7)
        slice_line_bytes++;
    if (height_div10 > 7) {
        word22_value = format == DSC_FORMAT_YUV420 ? 12 : 0;
        word6_value = 15;
    } else {
        word6_value = 0;
        word22_value = 0;
    }

    /* 4. Constants by bit depth; the depth is printed. */
    if (bit_depth == 8) {
        word9_top = 3; word9_mid = 12; word24_low = 2; word10_a = 11; word10_b = 11; unit_bits = 0x30; depth_row = 0;
        dbg_printf("\033[1;31m_8bit_Depth\n\r\033[m");
    } else if (bit_depth == 10) {
        word9_top = 7; word9_mid = 16; word24_low = 8; word10_a = 15; word10_b = 15; unit_bits = 0x30; depth_row = 1;
        dbg_printf("\033[1;31m_10bit_Depth\n\r\033[m");
    } else if (bit_depth == 12) {
        word9_top = 11; word9_mid = 20; word24_low = 0x20; word10_a = 19; word10_b = 19; unit_bits = 0x40; depth_row = 2;
        dbg_printf("\033[1;31m_12bit_Depth\n\r\033[m");
    } else {
        word9_top = 3; word9_mid = 12; word24_low = 2; word10_a = 11; word10_b = 11; unit_bits = 0x30; depth_row = 0;
    }

    /* word8_high by bpp (stays 0 below the lowest step). */
    if (is_422) {
        if (bpp > 15)
            word8_high = 0x800;
        else if (bpp > 13)
            word8_high = 5632 - (bpp - 14) * 1792;
        else if (bpp > 11)
            word8_high = 0x1600;
    } else {
        if (bpp > 11)
            word8_high = 0x800;
        else if (bpp > 9)
            word8_high = 5632 - (bpp - 10) * 1792;
        else if (bpp > 7)
            word8_high = 6144 - (bpp - 8) * 256;
        else if (bpp > 5)
            word8_high = 0x1800;
    }

    /* 5. Derived values. word4_low = ceil((bpp_recip * bpp + groups * word6_low + 0x2000 - word8_high) / bpp)
       - bpp_recip. */
    word6_low = word6_value;
    bpp_recip = (unsigned int)(0x2000 / bpp + 1) >> 1;
    sum = bpp_recip * bpp;
    groups_term = groups * word6_low;
    sum += groups_term;
    room = 0x2000 - word8_high;
    sum += room;
    sum_per_bpp = sum / bpp;
    if (sum % bpp)
        sum_per_bpp++;
    word4_low = sum_per_bpp - bpp_recip;
    part_bits = slice_line_bytes * height_div10 * 8;
    part_groups = groups * height_div10;
    /* word7_high = ceil((word6_low << 11) / (height_div10 - 1)) */
    tmp = word6_low << 11;
    word7_high = tmp / (height_div10 - 1);
    if (tmp % (height_div10 - 1))
        word7_high++;
    word5_high = 0x10000 / room;
    /* ofs_bits by format, then lowered so that part_bits - ofs_aligned is a multiple of unit_bits. */
    if (is_rgb)
        ofs_bits = 3 * (unit_bits + (4 * bit_depth + 4) - 2);
    else if (!is_422)
        ofs_bits = 3 * unit_bits + (4 * bit_depth + 4) + 2 * (4 * bit_depth) - 2;
    else
        ofs_bits = 4 * unit_bits + (4 * bit_depth + 4) + 3 * (4 * bit_depth) - 2;
    ofs_rem = (part_bits - ofs_bits) % unit_bits;
    ofs_aligned = ofs_bits - (unit_bits - ofs_rem);
    /* word7_low = ceil(((0x2000 - word8_high + ofs_aligned) << 11) / part_groups) */
    sum2 = 0x2000 - word8_high;
    sum2 += ofs_aligned;
    tmp = sum2 << 11;
    word7_low = tmp / part_groups;
    if (tmp % part_groups)
        word7_low++;
    /* word8_low = 0x2000 - bpp_recip * bpp + ofs_aligned (kept in 16 bits) */
    tmp = bpp << 4;
    tmp = (bpp_recip * tmp) >> 4;
    word8_low_full = 0x2000 - tmp;
    word8_low_full += ofs_aligned;
    word8_low = word8_low_full;
    /* word6_high = groups / (word5_high - 8);
       word5_low = (word8_low << 11) / ((0x10000 / (0x2000 - word8_low_full) - 9) * (word7_high + word7_low)) */
    tmp = (0x10000 / (0x2000 - word8_low_full) - 9) * (word7_high + word7_low);
    word6_high = groups / (word5_high - 8);
    word5_low = (word8_low << 11) / tmp;

    /* 6. Words 0..13. Word 0 = bit_depth * 17 + 0x12000001; word 1 holds the RGB flag (bit 28), the
       YUV422_SIMPLE flag (bit 27), bpp * 16 (bits 16..) and the height; words 2 and 3 pair width with
       height_div10 and slice_width with slice_line_bytes. */
    dsc_enc_pps_words[0] = bit_depth * 17 + 0x12000001;
    dsc_enc_pps_words[1] = ((unsigned int)is_rgb << 28) + ((unsigned int)is_simple_422 << 27) + ((unsigned int)bpp_x16 << 16) + height + 0x20000000;
    dsc_enc_pps_words[2] = ((unsigned int)width << 16) + height_div10;
    dsc_enc_pps_words[3] = ((unsigned int)slice_width << 16) + slice_line_bytes;
    dsc_enc_pps_words[4] = ((unsigned int)bpp_recip << 16) + word4_low;
    dsc_enc_pps_words[7] = (word7_high << 16) + word7_low;
    dsc_enc_pps_words[5] = (word5_high << 16) + word5_low;
    dsc_enc_pps_words[6] = (word6_high << 16) + word6_low;
    dsc_enc_pps_words[8] = ((unsigned int)word8_high << 16) + word8_low;
    dsc_enc_pps_words[9] = ((unsigned int)word9_top << 24) + (word9_mid << 16) + 0x2000;
    dsc_enc_pps_words[11] = 0x0e1c2a38;
    word10 = word10_a << 16;
    word10 += 0x6000000;
    word10 += word10_b << 8;
    word10 += 0x33;
    dsc_enc_pps_words[10] = word10;
    dsc_enc_pps_words[12] = 0x46546269;
    dsc_enc_pps_words[13] = 0x7077797b;
    dsc_enc_pps_words[14] = 0x7d7e0000;

    /* 7. The fifteen range entries: entry 0 goes into the lower half of word 14, entries 1..14 two per word
       into words 15..21. */
    if (format == DSC_FORMAT_YUV420) {
        /* For YUV420 the odd entry of each word is added without the shift into the upper half. */
        dsc_enc_pps_words[14] += (RANGE_420(0));
        dsc_enc_pps_words[15] = RANGE_420(1) + RANGE_420(2);
        dsc_enc_pps_words[16] = RANGE_420(3) + RANGE_420(4);
        dsc_enc_pps_words[17] = RANGE_420(5) + RANGE_420(6);
        dsc_enc_pps_words[18] = RANGE_420(7) + RANGE_420(8);
        dsc_enc_pps_words[19] = RANGE_420(9) + RANGE_420(10);
        dsc_enc_pps_words[20] = RANGE_420(11) + RANGE_420(12);
        dsc_enc_pps_words[21] = RANGE_420(13) + RANGE_420(14);
        is_420 = 1;
        is_422 = 0;
    } else if (format == DSC_FORMAT_YUV422) {
        /* Table rows: 8 bit -> min/max row 0..2 and offset row 0..2 for bpp 8, 9, other;
           10 bit -> min/max row 3..5, offset row 0..2 the same way; 12 bit -> rows 6 and 0. */
        if (depth_row == 0) {
            row_422 = 0; ofs_row_422 = 0;
            if (bpp != 8) {
                row_422 = 1; ofs_row_422 = 1;
                if (bpp != 9) {
                    row_422 = 2; ofs_row_422 = 2;
                }
            }
        } else if (depth_row == 1) {
            row_422 = 3; ofs_row_422 = 0;
            if (bpp != 8) {
                row_422 = 4; ofs_row_422 = 1;
                if (bpp != 9) {
                    row_422 = 5; ofs_row_422 = 2;
                }
            }
        } else if (depth_row == 2) {
            row_422 = 6; ofs_row_422 = 0;
        }
        dbg_printf("\ntemp_idx = %d, Ofs_422_idx = %d\n\n", row_422, ofs_row_422);
        dsc_enc_pps_words[14] += (RANGE_422_LOW(0));
        dsc_enc_pps_words[15] = (RANGE_422_HIGH(1)) + (RANGE_422_LOW(2));
        dsc_enc_pps_words[16] = (RANGE_422_HIGH(3)) + (RANGE_422_LOW(4));
        dsc_enc_pps_words[17] = (RANGE_422_HIGH(5)) + (RANGE_422_LOW(6));
        dsc_enc_pps_words[18] = (RANGE_422_HIGH(7)) + (RANGE_422_LOW(8));
        dsc_enc_pps_words[19] = (RANGE_422_HIGH(9)) + (RANGE_422_LOW(10));
        dsc_enc_pps_words[20] = (RANGE_422_HIGH(11)) + (RANGE_422_LOW(12));
        dsc_enc_pps_words[21] = (RANGE_422_HIGH(13)) + (RANGE_422_LOW(14));
        is_420 = 0;
        is_422 = 1;
    } else {
        /* RGB, YUV444 and YUV422_SIMPLE: the 4:4:4 tables, row by bit depth. */
        dsc_enc_pps_words[14] += (RANGE_444_LOW(0));
        dsc_enc_pps_words[15] = (RANGE_444_HIGH(1)) + (RANGE_444_LOW(2));
        dsc_enc_pps_words[16] = (RANGE_444_HIGH(3)) + (RANGE_444_LOW(4));
        dsc_enc_pps_words[17] = (RANGE_444_HIGH(5)) + (RANGE_444_LOW(6));
        dsc_enc_pps_words[18] = (RANGE_444_HIGH(7)) + (RANGE_444_LOW(8));
        dsc_enc_pps_words[19] = (RANGE_444_HIGH(9)) + (RANGE_444_LOW(10));
        dsc_enc_pps_words[20] = (RANGE_444_HIGH(11)) + (RANGE_444_LOW(12));
        dsc_enc_pps_words[21] = (RANGE_444_HIGH(13)) + (RANGE_444_LOW(14));
        is_420 = 0;
        is_422 = 0;
    }

    /* 8. Words 22..26. Word 25: work_width % 3 in bits 28..29, work_width / 3 rounded up in bits 16..26, the
       slice count (16 stored as 15) in bits 0..3. Word 26 from the bits of height_div10 slice lines, counted
       in units of 192 bits (blocks_192) and of unit_bits (units_up). */
    dsc_enc_pps_words[22] = ((unsigned int)is_420 << 25) + ((unsigned int)is_422 << 24) + (word22_value << 16);
    dsc_enc_pps_words[23] = 0;
    dsc_enc_pps_words[24] = word24_low + 0x800;
    slice_field = slices == 16 ? 15 : slices;
    groups_up = work_width / 3;
    width_mod3 = work_width % 3;
    if (width_mod3)
        groups_up++;
    part_bytes = slice_line_bytes * height_div10;
    word25_top = ((width_mod3 & 3) << 28) + 0x40000000;
    dsc_enc_pps_words[25] = word25_top + ((groups_up & 0x7ff) << 16) + (slice_field & 0xf);
    blocks_192 = part_bytes * 8 / 192 + (part_bytes * 8 % 192 != 0);
    units_up = part_bytes * 8 / unit_bits + (part_bytes * 8 % unit_bits != 0);
    dsc_enc_pps_words[26] = ((unsigned int)(blocks_192 * 4 - units_up) << 29) + (blocks_192 & 0x1fffffff);

    /* 9. Program the encoder and print the words. */
    for (k = 0; k < 24; k++)
        DSC_ENC_REG(k << 2) = dsc_enc_pps_words[k];
    DSC_ENC_REG(0x60) = dsc_enc_pps_words[24];
    DSC_ENC_REG(0x64) = dsc_enc_pps_words[25];
    if (sys_get_chip_revision() > CHIP_REV_83)
        DSC_ENC_REG(0x64) |= 0x200;
    DSC_ENC_REG(0x9c) = dsc_enc_pps_words[26];
    for (j = 0; j < 27; j++) {
        if ((j & 3) == 0)
            dbg_printf("\n ");
        dbg_printf("%08lX ", dsc_enc_pps_words[j]);
    }
    dbg_printf("\n\n ");
}
