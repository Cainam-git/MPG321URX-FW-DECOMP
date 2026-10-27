/* leon2m FUN_a00b9c68 @ 0xa00b9c68-0xa00b9f30 (178 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00ba184.
 * From three signed shorts r, g, b: max and min of the three, d = max - min. Returns 0xffff when d <= 3.
 * Otherwise h = (g - b) * 100 / d % 600 when max is r, (b - r) * 100 / d + 200 when max is g, (r - g) * 100 / d
 * + 400 when max is b; then h = (short)(h * 60) / 100. A negative h with a nonzero remainder modulo 360 becomes
 * h % 360 + 360. Returns h as an unsigned short. All intermediate values are signed shorts.
 */
unsigned short FUN_a00b9c68(short r, short g, short b)
{
    short max, min, d, h = 0;

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
    d = max - min;
    if (d <= 3)
        return 0xffff;
    if (d != 0) {
        if (max == r)
            h = (g - b) * 100 / d % 600;
        else if (max == g)
            h = (b - r) * 100 / d + 200;
        else if (max == b)
            h = (r - g) * 100 / d + 400;
        h = h * 60;
        h = h / 100;
    }
    if (h < 0) {
        if (h % 360 != 0)
            h = h % 360 + 360;
    }
    return h;
}
