/* hdr_build_guided_curve  (FUN_a00627a8)
 *
 * Compute a guided knee point and Bezier anchors from scene and panel brightness.
 * Name basis: derived - fills knee_point_x/y and 5 bezier anchors (dump prints them as 'Guided
 *   bezier_curve_anchor')
 *
 * Matching notes
 * --------------
 * FUN_a00627a8 (leon2s 0xa00627a8-0xa00629fc, 596 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the anchor count 5 and the first-anchor anchor_floor 0xaa are held in variables (the firmware divides and multiplies
 *    by 6 and divides by 0x356 at run time, with no reciprocal);
 *  - the two quotients are computed before the call that follows them: 'ratio50 = ratio50 / (p99 > 1 ? p99 : 1)'
 *    straight after 'ratio50 = p50 << 10', and 'w_b = v - anchor_floor; w_b <<= 10; w_b /= one - anchor_floor' before the 0x39a
 *    call;
 *  - v is reused for the result of the 0x39a call and for the rounding sum of the first loop;
 *    'k = 1; bend_shifted = bend << 10;' stand before the head of the first loop;
 *  - the second loop is an if/else with one anchor store in each arm; its default is written
 *    '((k + 1) << 10) / (anchor_count + 1)', the same spelling as in the first loop;
 *  - the parameters p99 and p50 are reused as temporaries (knee x, the constant 0x400).
 */
struct HdrMeta {
    unsigned char _0[2];
    unsigned short knee_point_x;
    unsigned short knee_point_y;
    unsigned char _6[0x58 - 6];
    unsigned char num_bezier_curve_anchors;
    unsigned char _59;
    unsigned short bezier_curve_anchor[15];
};
extern unsigned int lib_interpolate_clamped(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

/*
 * Fill the curve description in *m: the knee point (knee_point_x, knee_point_y) and 5 Bezier anchors
 * (num_bezier_curve_anchors = 5; the other 10 entries of the 15-entry array get an even default spacing).
 * All brightness values are on a 0..0x400 scale (1 << 10 = full).
 *   panel_peak:      brightness the panel can show (the caller passes its panel peak x 10)
 *   scene_luminance: brightness of the scene (the caller passes the 99th percentile, or the scene maximum, x 10)
 *   p99, p50:        99th and 50th percentile brightness of the scene
 *   m:               the HDR10+ metadata record that receives the result
 * Order of work:
 *  1. ratio = panel_peak / max(panel_peak, scene_luminance) on the 0x400 scale, and ratio50 = p50 / max(p99, 1).
 *  2. Three lib_interpolate_clamped steps turn the ratio (twice) and ratio50 (once) into weights; their mix
 *     sum = blend * weight_a + (0x400 - blend) * weight_b gives the knee point: y = sum >> 8,
 *     x = (y * ratio) >> 10.
 *  3. The first anchor is v = ((0x400 - knee_low) << 20) / ((0x400 - bend) * 6) / ratio, limited to 0x3ec. Here
 *     knee_low is knee x >> 2 and bend is sum >> 10, each limited to 0x3ff.
 *  4. The bend is recomputed: v is interpolated from scene_luminance (0x39a at 10000 down to 0x2cd at 40000) and
 *     bend runs from 0 to v as w = ((first anchor - 0xaa) << 10) / (0x400 - 0xaa) goes from 0xaa to 0x400.
 *  5. Anchors 1..4: the even position ((k + 1) << 10) / 6 or, when larger, the smaller of (k + 1) times the first
 *     anchor and the bend-weighted mix of 0x400 and that even position.
 */
void hdr_build_guided_curve(unsigned int panel_peak, unsigned int scene_luminance, unsigned int p99, unsigned int p50, struct HdrMeta *m)
{
    unsigned int ratio50, weight_a, weight_b, blend, sum, knee_scaled, knee_low, bend, even, limit, v, anchor_count, anchor_floor, bend_shifted;
    unsigned int k;
    unsigned int anchor[16];

    /* The scene is taken as at least as bright as the panel peak, so the ratio below is at most 1 << 10. */
    if (scene_luminance < panel_peak)
        scene_luminance = panel_peak;
    ratio50 = p50 << 10;
    p50 = 0x400;                        /* p50 is reused as the constant 1 << 10 from here on */
    ratio50 = ratio50 / (p99 > 1 ? p99 : 1);
    anchor_count = 5;
    anchor_floor = 0xaa;                /* start of the first anchor's range in the bend interpolation below */
    panel_peak = (panel_peak << 10) / scene_luminance;          /* panel_peak is now the ratio */
    weight_a = lib_interpolate_clamped(0x133, 0x200, 0x9a, 0x400, panel_peak);
    weight_b = lib_interpolate_clamped(0, 0x200, 0x9a, 0x3f6, panel_peak);
    blend = lib_interpolate_clamped(0x400, 0x33, 0x33, 0x200, ratio50);
    sum = blend * weight_a + (p50 - blend) * weight_b;
    weight_a = sum >> 8;                /* knee y */
    knee_scaled = weight_a * panel_peak;
    knee_low = knee_scaled >> 12;
    p99 = knee_scaled >> 10;            /* knee x; p99 is reused */
    if (knee_low > 0x3ff)
        knee_low = 0x3ff;
    bend = sum >> 10;
    if (bend > 0x3ff)
        bend = 0x3ff;
    v = ((p50 - knee_low) << 20) / ((p50 - bend) * (anchor_count + 1));
    v /= panel_peak;
    if (v > 0x3ec)
        v = 0x3ec;
    ratio50 = v;                        /* ratio50 is reused: the first anchor */
    weight_b = v - anchor_floor;
    weight_b <<= 10;
    weight_b /= p50 - anchor_floor;
    v = lib_interpolate_clamped(0x39a, 0x2cd, 10000, 40000, scene_luminance);
    bend = lib_interpolate_clamped(0, v, 0xaa, 0x400, weight_b);
    k = 1;
    bend_shifted = bend << 10;
    weight_b = p50 - bend;
    anchor[0] = ratio50;
    for (; k < anchor_count; k++) {
        even = ((k + 1) << 10) / (anchor_count + 1);
        v = bend_shifted + weight_b * even + 0x200;
        limit = v >> 10;
        v = (k + 1) * ratio50;
        if (v > limit)
            v = limit;
        anchor[k] = even >= v ? even : v;
    }
    m->knee_point_x = p99;
    m->knee_point_y = weight_a;
    m->num_bezier_curve_anchors = anchor_count;
    for (k = 0; k <= 14; k++) {
        if (k < anchor_count)
            m->bezier_curve_anchor[k] = anchor[k];
        else
            m->bezier_curve_anchor[k] = ((k + 1) << 10) / (anchor_count + 1);   /* unused entries: even spacing */
    }
}
