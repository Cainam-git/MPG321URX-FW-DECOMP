/* hdr_evaluate_bezier  (FUN_a0062a34)
 *
 * Evaluate the Bezier tone curve at one input level from the anchor weights.
 *   level: input level
 * Returns: curve value
 * Name basis: derived - weighted sum of a 65-column coefficient table by the anchors from the knee point on
 *
 * Matching notes
 * --------------
 * FUN_a0062a34 (leon2s 0xa0062a34-0xa0062b64, 304 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: the interpolated value is a separate local; the table index is written as (x >> 9) >> 12 before
 * x itself is shifted by 9.
 */
/* The part of the HDR10+ metadata record that this routine reads. */
struct bezier_part {
    unsigned short byte_0x00_pair;              /* +0x00 */
    unsigned short knee_point_x;                /* +0x02 */
    unsigned char pad_0x04[0x54];
    unsigned char num_bezier_curve_anchors;     /* +0x58 */
    unsigned char byte_0x59;
    unsigned short bezier_curve_anchor[8];      /* +0x5A */
};
extern struct bezier_part hdr10plus_metadata;
extern unsigned int hdr_curve_bezier_scale;
extern unsigned short (*hdr_bezier_weights_ptr)[65];

#define WEIGHT_COLUMNS      65                  /* columns of a weight row */
#define WEIGHT_MIRROR_FROM  0x3f                /* above this index the table is read mirrored */
#define FRACTION_ONE        0x1000              /* the interpolation fraction has 12 bits */

/*
 * Evaluate the Bezier part of the HDR10+ tone curve at one input level.
 *   level: input level
 * Returns the curve value.
 *
 * The position in the weight table is x = (level - knee_point_x) * hdr_curve_bezier_scale: its bits above 21
 * are the column index and its bits 9..20 the fraction between that column and the next. For
 * i = 1 .. n (n = num_bezier_curve_anchors + 1) a weight is interpolated between two columns of row i of
 * the table hdr_bezier_weights_ptr, multiplied by bezier_curve_anchor[i - 1] and summed. For a column
 * index above 0x3f the table is read mirrored: row n - i and columns 128 - index and 127 - index.
 * The sum is returned divided by 256.
 */
unsigned int hdr_evaluate_bezier(unsigned int level)
{
    unsigned int x;
    unsigned int column;
    unsigned int fraction;
    unsigned int n;
    unsigned int i;
    unsigned int sum = 0;
    unsigned int weight;
    x = (level - hdr10plus_metadata.knee_point_x) * hdr_curve_bezier_scale;
    n = hdr10plus_metadata.num_bezier_curve_anchors + 1;
    column = (x >> 9) >> 12;
    x >>= 9;
    fraction = x & 0xfff;
    if (column > WEIGHT_MIRROR_FROM) {
        for (i = 1; i <= n; i++) {
            weight = (hdr_bezier_weights_ptr[n - i][128 - column] * (FRACTION_ONE - fraction) + hdr_bezier_weights_ptr[n - i][127 - column] * fraction) >> 6;
            sum += weight * hdr10plus_metadata.bezier_curve_anchor[i - 1]  >> 4;
        }
    } else {
        for (i = 1; i <= n; i++) {
            weight = (hdr_bezier_weights_ptr[i][column] * (FRACTION_ONE - fraction) + hdr_bezier_weights_ptr[i][column + 1] * fraction) >> 6;
            sum += weight * hdr10plus_metadata.bezier_curve_anchor[i - 1] >> 4;
        }
    }
    return sum >> 8;
}
