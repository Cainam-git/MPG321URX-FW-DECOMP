/* FUN_a00d9e5c (leon2s 0xa00d9e5c-0xa00d9edc, 128 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Returns the 4-bit distance from a first byte x to a second byte y: y - x when x <= y, else 0x10 - (x - y).
 * mode 2: x = DAT_a8078800[DAT_a8078832], y = DAT_a8078808[DAT_a8078832]; mode 4: x = DAT_a80787fc,
 * y = DAT_a80787fd; any other mode returns 0.
 * Source form: a switch (cases laid out after the compare chain) with its own unsigned int variables in each
 * case; shared variables let GCC merge the two compares after the join, unsigned char variables change the
 * registers. The firmware's shared tail ('bleu; 0x10 - d') comes from cross-jumping the two cases.
 */
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8078808[];
extern unsigned char DAT_a8078800[];
extern unsigned char DAT_a80787fc;
extern unsigned char DAT_a80787fd;

unsigned char FUN_a00d9e5c(unsigned char mode)
{
    unsigned char r;
    unsigned int x, y, u, v;

    switch (mode) {
    case 2:
        y = DAT_a8078808[DAT_a8078832];
        x = DAT_a8078800[DAT_a8078832];
        if (x <= y)
            r = y - x;
        else
            r = 0x10 - (x - y);
        break;
    case 4:
        v = DAT_a80787fd;
        u = DAT_a80787fc;
        if (u <= v)
            r = v - u;
        else
            r = 0x10 - (u - v);
        break;
    default:
        r = 0;
        break;
    }
    return r;
}
