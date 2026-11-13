/* hdr_evaluate_tone_curve  (FUN_a0062b64)
 *
 * Return one tone-curve point mixed from the knee and the Bezier part.
 *   level: input level
 * Returns: curve value
 * Name basis: derived - (h << 18) + (0x1000 - h) * bezier / 4 with h from the metadata record
 *
 * Matching notes
 * --------------
 * FUN_a0062b64 (leon2s 0xa0062b64-0xa0062b94, 48 bytes), flags -mcpu=v8 -Os -g.
 * hdr_evaluate_bezier takes the level and returns an unsigned word; the product and the sum are unsigned 32-bit.
 */
extern unsigned short hdr10plus_metadata_knee_y;
extern unsigned int hdr_evaluate_bezier(unsigned int);

/*
 * Return one point of the tone curve: knee_point_y of the HDR10+ metadata record (field +4,
 * hdr10plus_metadata_knee_y) times 2^18, plus (0x1000 - knee_point_y) times a quarter of the Bezier value of
 * the same level.
 *   level: input level
 */
unsigned int hdr_evaluate_tone_curve(unsigned int level)
{
    unsigned int knee_y = hdr10plus_metadata_knee_y;
    return (knee_y << 18) + (0x1000 - knee_y) * (hdr_evaluate_bezier(level) >> 2);
}
