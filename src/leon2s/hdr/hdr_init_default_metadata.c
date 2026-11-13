/* hdr_init_default_metadata  (FUN_a0062308)
 *
 * Fill the HDR10+ metadata record with default values.
 * Name basis: derived - constant halfwords into the record whose fields the dump prints; anchor count 9
 *
 * Matching notes
 * --------------
 * FUN_a0062308 (leon2s, 0xa0062308-0xa0062434, 75 words, leaf). Flags -mcpu=v8 -Os -g.
 * The 16-bit stores follow the firmware's order (not the order of the offsets). The byte +0x58 and the halfword
 * +0x06 take one register holding 9 (firmware 'mov 9,%o3', then stb and sth).
 * Source form: the chained assignment 'byte +0x58 = halfword +0x06 = 9' (separate statements or a u8 temporary
 * give two 'mov 9' and a longer schedule).
 */
extern unsigned char hdr10plus_metadata[];

/*
 * Load default values into the HDR10+ metadata record (hdr10plus_metadata, 0x8A bytes; field offsets as in
 * struct hdr10plus_metadata_record). Called by hdr_init_hdr10plus.
 *
 * It sets the knee point, nine Bezier anchors (their count is 9), a percentile list of nine entries (keys
 * 1, 5, 10, 25, 50, 75, 90, 95, 99) and three scene maximum values. The halfword array h is indexed in 16-bit
 * steps from the start of the record; the offset of each store is given in the comment.
 */
void hdr_init_default_metadata(void)
{
    unsigned short *h = (unsigned short *)&hdr10plus_metadata[0];

    /* scene_max_0..2 */
    h[0x41] = 0xffff;           /* +0x82 */
    h[0x42] = 0xe218;           /* +0x84 */
    h[0x43] = 0xec86;           /* +0x86 */
    /* percentile_key[0..8] */
    h[0x18] = 1;                /* +0x30 */
    h[0x19] = 5;                /* +0x32 */
    h[0x1a] = 10;               /* +0x34 */
    h[0x1b] = 0x19;             /* +0x36 */
    h[0x1c] = 0x32;             /* +0x38 */
    h[0x1d] = 0x4b;             /* +0x3a */
    h[0x1e] = 0x5a;             /* +0x3c */
    h[0x1f] = 0x5f;             /* +0x3e */
    h[0x20] = 0x63;             /* +0x40 */
    /* percentile_value[0..7] */
    h[0x04] = 4;                /* +0x08 */
    h[0x05] = 6;                /* +0x0a */
    h[0x06] = 7;                /* +0x0c */
    h[0x07] = 0x0e;             /* +0x0e */
    h[0x08] = 0x3a;             /* +0x10 */
    h[0x09] = 0x106;            /* +0x12 */
    h[0x0a] = 0x324;            /* +0x14 */
    h[0x0b] = 0x66a;            /* +0x16 */
    /* knee_point_x, knee_point_y */
    h[0x01] = 0x2a9;            /* +0x02 */
    h[0x02] = 0x468;            /* +0x04 */
    /* bezier_curve_anchor[0..6] */
    h[0x2d] = 0xb3;             /* +0x5a */
    h[0x2e] = 0x153;            /* +0x5c */
    h[0x2f] = 0x1df;            /* +0x5e */
    h[0x30] = 0x2c4;            /* +0x60 */
    h[0x31] = 0x31e;            /* +0x62 */
    h[0x32] = 0x369;            /* +0x64 */
    h[0x33] = 0x3a7;            /* +0x66 */
    /* percentile_value[8] and the entry after it (beyond the count of 9) */
    h[0x0c] = 0x19e1;           /* +0x18 */
    h[0x0d] = 0x19e2;           /* +0x1a */
    /* The halfword at +0x06 holds byte_0x06 = 0 and percentile_count = 9 (+0x07); the byte at +0x58 is
     * num_bezier_curve_anchors = 9. */
    ((unsigned char *)h)[0x58] = h[0x03] = 9;   /* +0x06, +0x58 */
    /* bezier_curve_anchor[7..8] */
    h[0x34] = 0x3d9;            /* +0x68 */
    h[0x35] = 0x3ff;            /* +0x6a */
}
