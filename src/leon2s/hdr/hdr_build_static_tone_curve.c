/* hdr_build_static_tone_curve  (FUN_a0062bac)
 *
 * Build the 257-point tone curve for static HDR from content and panel peak brightness.
 *   panel_peak
 *   content_peak
 *   out: 257-entry curve
 * Name basis: derived - interpolates the curve rows by content/panel ratio, fills the record and 257 curve
 *   values; caller uses mastering luminance
 *
 * Matching notes
 * --------------
 * FUN_a0062bac (leon2s 0xa0062bac-0xa0062f3c, 912 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the interpolation is a static inline helper used twice (once for the knee x value, once per f value);
 *    the knee block reads the two y values first, then the two x values;
 *  - the search limit is the variable k (set to 6) and is reused later for the last index of the second curve
 *    loop; k = 0 is set before n;
 *  - the knee slope divides with signed ints, and the knee-slope branch tests knee_point_x == 0.
 */
/* One row of hdr_static_curve_rows: 22 bytes. x is the content/panel ratio (times 500) the row belongs to. */
struct Row {
    unsigned short x;
    unsigned short y;
    unsigned short f[9];
};
/* The HDR10+ metadata record, as far as this routine uses it (fields as in struct hdr10plus_metadata_record). */
struct Cal {
    unsigned short h0;
    unsigned short knee_point_x;
    unsigned short knee_point_y;
    unsigned char pad6[0x52];
    unsigned char num_bezier_curve_anchors;
    unsigned char pad59;
    unsigned short bezier_curve_anchor[20];
};
extern unsigned char hdr_curve_rows_reload_flag;
extern struct Row hdr_static_curve_rows[];
extern const struct Row hdr_static_curve_rows_override[];
extern struct Cal hdr10plus_metadata;
extern unsigned short (*hdr_bezier_weights_ptr)[65];
extern unsigned short hdr_bezier_weights_order10[][65];
extern int hdr_curve_bezier_scale;
extern int hdr_curve_knee_slope;
extern void *lib_memcpy(void *, const void *, unsigned int);
extern unsigned int hdr_evaluate_tone_curve(unsigned int);

/* Linear interpolation of from..to at position ratio between x_low and x_high; from when the two positions are equal. */
static __inline__ unsigned int interp(unsigned int from, unsigned int to, unsigned int ratio, unsigned int x_low, unsigned int x_high)
{
    if (x_high == x_low)
        return from;
    if (to > from)
        return (to - from) * (ratio - x_low) / (x_high - x_low) + from;
    return from - (from - to) * (ratio - x_low) / (x_high - x_low);
}

/*
 * Build the tone curve for a static-HDR source and describe it in hdr10plus_metadata (the record that also
 * holds the HDR10+ knee point and Bezier anchors).
 *   panel_peak:   the panel's peak luminance (hdr_peak_luminance)
 *   content_peak: the mastering luminance of the source; the caller uses this routine only when it is above
 *                 the panel peak
 *   out:          receives the 257 curve entries (hdr_tone_curve)
 * Order of work:
 *  1. ratio = content_peak * 500 / panel_peak. When hdr_curve_rows_reload_flag is 1, the 7 rows of
 *     hdr_static_curve_rows are first replaced by the override rows.
 *  2. The row pair that encloses the ratio is found (the last pair when the ratio is beyond the table) and the
 *     row values are interpolated at the ratio: y gives knee_point_x, and the 9 f values give the 9 Bezier
 *     anchors (entries 9..19 are set to 0x400). knee_point_y = knee_point_x * content_peak / panel_peak.
 *  3. The Bezier weights of order 10 are selected, hdr_curve_bezier_scale = 0x10000000 / (0x1000 - knee_point_x)
 *     and hdr_curve_knee_slope = (knee_point_y << 10) / knee_point_x (knee_point_y << 10 when knee_point_x is 0).
 *  4. Curve entries: out[1 .. n + 1] (n = knee_point_x >> 4) hold the knee slope, out[0] too, or
 *     hdr_evaluate_tone_curve(8) >> 11 when n is 0; each later entry i up to 0xff is
 *     (hdr_evaluate_tone_curve(i * 16) >> 12) / i; out[0x100] = 0x400.
 */
void hdr_build_static_tone_curve(unsigned int panel_peak, unsigned int content_peak, unsigned short *out)
{
    unsigned int ratio;
    unsigned int i;
    unsigned int row_index;
    unsigned int x_low, x_high, from, to, knee_x;
    unsigned short n, k;

    ratio = content_peak * 500 / panel_peak;
    row_index = 5;
    k = 6;
    if (hdr_curve_rows_reload_flag == 1)
        lib_memcpy(hdr_static_curve_rows, hdr_static_curve_rows_override, 0x9a);
    /* First row whose successor lies above the ratio; rows 0..5 are tried, 5 is used when none matches. */
    for (i = 0; i < k; i++) {
        if (ratio < hdr_static_curve_rows[i + 1].x) {
            row_index = i;
            break;
        }
    }
    from = hdr_static_curve_rows[row_index].y;
    to = hdr_static_curve_rows[row_index + 1].y;
    x_low = hdr_static_curve_rows[row_index].x;
    x_high = hdr_static_curve_rows[row_index + 1].x;
    knee_x = interp(from, to, ratio, x_low, x_high);
    hdr_bezier_weights_ptr = hdr_bezier_weights_order10;
    hdr10plus_metadata.num_bezier_curve_anchors = 9;
    hdr10plus_metadata.knee_point_x = knee_x;
    hdr10plus_metadata.knee_point_y = knee_x * content_peak / panel_peak;
    for (i = 0; i < hdr10plus_metadata.num_bezier_curve_anchors; i++)
        hdr10plus_metadata.bezier_curve_anchor[i] = interp(hdr_static_curve_rows[row_index].f[i], hdr_static_curve_rows[row_index + 1].f[i], ratio, x_low, x_high);
    for (; i < 20; i++)
        hdr10plus_metadata.bezier_curve_anchor[i] = 0x400;
    hdr_curve_bezier_scale = 0x10000000 / (int)(0x1000 - hdr10plus_metadata.knee_point_x);
    if (hdr10plus_metadata.knee_point_x == 0)
        hdr_curve_knee_slope = hdr10plus_metadata.knee_point_y << 10;
    else
        hdr_curve_knee_slope = (int)(hdr10plus_metadata.knee_point_y << 10) / (int)hdr10plus_metadata.knee_point_x;
    k = 0;
    n = hdr10plus_metadata.knee_point_x >> 4;
    if (n == 0)
        out[0] = hdr_evaluate_tone_curve(8) >> 11;
    else
        out[0] = hdr_curve_knee_slope;
    /* Below the knee the entries are the constant knee slope. */
    for (i = 1; i <= n + 1; i++)
        out[i] = hdr_curve_knee_slope;
    for (i = n + 1; i <= 0xff; i++) {
        out[i] = (hdr_evaluate_tone_curve(i * 16) >> 12) / i;
        k = i;
    }
    /* Runs only when the loop above did not (n + 1 > 0xff): k is then 0, so entries 1..0xff are all computed here. */
    for (i = k + 1; i <= 0xff; i++)
        out[i] = (unsigned short)(hdr_evaluate_tone_curve(i * 16) >> 12) / i;
    out[0x100] = 0x400;
}
