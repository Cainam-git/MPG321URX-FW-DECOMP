/* FUN_a00627a8 (leon2s 0xa00627a8-0xa00629fc, 596 bytes), flags -mcpu=v8 -Os -g. void (a, b, c, d, m).
 * Fills the record m (knee_point_x/y, num_bezier_curve_anchors = 5, bezier_curve_anchor[15]) from a, b, c, d:
 * b = max(a, b), a = (a << 10) / b, three FUN_a0062718 steps on a and (d << 10) / max(c, 1) give sum; knee point
 * x = (sum >> 8) * a >> 10, y = sum >> 8; v = ((0x400 - ky) << 20) / ((0x400 - t) * 6) / a limited to 0x3ec;
 * t = FUN_a0062718(0, FUN_a0062718(0x39a, 0x2cd, 10000, 40000, b), 0xaa, 0x400, ((v - 0xaa) << 10) / 0x356);
 * anchor[0] = v, anchor[k] (k = 1..4) = max(n, min((k + 1) * v, ((t << 10) + (0x400 - t) * n + 0x200) >> 10))
 * with n = ((k + 1) << 10) / 6; bezier_curve_anchor[k] = anchor[k] for k < 5, else ((k + 1) << 10) / 6.
 * Callee: FUN_a0062718 (same file).
 * Source form: num = 5 and lo = 0xaa in variables (fw udiv/smul by 6, udiv by 0x356, no reciprocal); the two
 * quotients passed to FUN_a0062718 computed before the preceding call ('dv = dv / (c > 1 ? c : 1);' right after
 * 'dv = d << 10', 'w1 = v - lo; w1 <<= 10; w1 /= d - lo;' before the 0x39a call); v reused for the 0x39a result and
 * for the loop-1 rounding sum; 'k = 1; t10 = t << 10;' before the loop-1 head; loop 2 as an if/else with one
 * bezier_curve_anchor store in each arm, the default written '((k + 1) << 10) / (num + 1)' (loop 1's spelling).
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
extern unsigned int FUN_a0062718(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

void FUN_a00627a8(unsigned int a, unsigned int b, unsigned int c, unsigned int d, struct HdrMeta *m)
{
    unsigned int dv, w0, w1, wt, sum, kx, ky, t, n, lim, v, num, lo, t10;
    unsigned int k;
    unsigned int anchor[16];

    if (b < a)
        b = a;
    dv = d << 10;
    d = 0x400;
    dv = dv / (c > 1 ? c : 1);
    num = 5;
    lo = 0xaa;
    a = (a << 10) / b;
    w0 = FUN_a0062718(0x133, 0x200, 0x9a, 0x400, a);
    w1 = FUN_a0062718(0, 0x200, 0x9a, 0x3f6, a);
    wt = FUN_a0062718(0x400, 0x33, 0x33, 0x200, dv);
    sum = wt * w0 + (d - wt) * w1;
    w0 = sum >> 8;
    kx = w0 * a;
    ky = kx >> 12;
    c = kx >> 10;
    if (ky > 0x3ff)
        ky = 0x3ff;
    t = sum >> 10;
    if (t > 0x3ff)
        t = 0x3ff;
    v = ((d - ky) << 20) / ((d - t) * (num + 1));
    v /= a;
    if (v > 0x3ec)
        v = 0x3ec;
    dv = v;
    w1 = v - lo;
    w1 <<= 10;
    w1 /= d - lo;
    v = FUN_a0062718(0x39a, 0x2cd, 10000, 40000, b);
    t = FUN_a0062718(0, v, 0xaa, 0x400, w1);
    k = 1;
    t10 = t << 10;
    w1 = d - t;
    anchor[0] = dv;
    for (; k < num; k++) {
        n = ((k + 1) << 10) / (num + 1);
        v = t10 + w1 * n + 0x200;
        lim = v >> 10;
        v = (k + 1) * dv;
        if (v > lim)
            v = lim;
        anchor[k] = n >= v ? n : v;
    }
    m->knee_point_x = c;
    m->knee_point_y = w0;
    m->num_bezier_curve_anchors = num;
    for (k = 0; k <= 14; k++) {
        if (k < num)
            m->bezier_curve_anchor[k] = anchor[k];
        else
            m->bezier_curve_anchor[k] = ((k + 1) << 10) / (num + 1);
    }
}
