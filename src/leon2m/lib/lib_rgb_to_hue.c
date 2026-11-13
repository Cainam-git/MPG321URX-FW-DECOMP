/* lib_rgb_to_hue  (FUN_a00b9c68)
 *
 * Return the hue angle (0..359) of an RGB colour, or 0xFFFF for grey.
 *   r: red
 *   g: green
 *   b: blue
 * Returns: hue in degrees or 0xFFFF
 * Note: Standard HSV hue formula; grey when max - min <= 3.
 * Name basis: proven - max/min of r, g, b and the 60-degree sector arithmetic
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b9c68 @ 0xa00b9c68-0xa00b9f30 (178 words), flags -mcpu=v8 -O3 -g.
 * Source form: all intermediate values are signed shorts; the hue is multiplied by 60 and divided by 100 in two
 * separate statements; max and min are found with chained comparisons.
 */
#define HUE_NONE 0xffff                 /* returned for a grey: the spread of the three colours is 3 or less */

/*
 * Compute the hue angle of an RGB colour.
 *   r, g, b: the three colour values
 * Returns the hue in whole degrees, 0..359 (red 0, green 120, blue 240), or HUE_NONE when max - min is 3 or less.
 * Caller: osd_update_crosshair_color.
 */
unsigned short lib_rgb_to_hue(short r, short g, short b)
{
    short max, min, spread, hue = 0;

    if (r >= g && r >= b)
        max = r;
    else if (g >= r && g >= b)
        max = g;
    else
        max = b;
    if (r <= g && r <= b)
        min = r;
    else if (g <= r && g <= b)
        min = g;
    else
        min = b;
    spread = max - min;
    if (spread <= 3)
        return HUE_NONE;
    if (spread != 0) {
        /* Position within a 600-wide hue circle (red 0, green 200, blue 400), then scaled to degrees. */
        if (max == r)
            hue = (g - b) * 100 / spread % 600;
        else if (max == g)
            hue = (b - r) * 100 / spread + 200;
        else if (max == b)
            hue = (r - g) * 100 / spread + 400;
        hue = hue * 60;
        hue = hue / 100;
    }
    /* A negative angle is brought into the range 0..359. */
    if (hue < 0) {
        if (hue % 360 != 0)
            hue = hue % 360 + 360;
    }
    return hue;
}
