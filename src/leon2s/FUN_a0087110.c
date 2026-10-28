/* FUN_a0087110 (leon2s 0xa0087110-0xa0087364, 596 bytes), flags -mcpu=v8 -Os -g.
 * unsigned char (all, rate, bufs, mask). Ports lo..hi are 0..0, or DAT_a80761c0..DAT_a80761bf when all != 0.
 * Pass 1, for every port with its bit set in *mask: FUN_a00aa930(port, 0), FUN_a00aaf94(port, 0, a); when
 * FUN_a008642c(port, 0, *rate, 0, 0) returns 0 the bit is cleared (port 0 then returns 8).
 * Pass 2, for every port still set: repeats FUN_a00b1794(ARR_a807cd2e[port][5]), FUN_a0086e58(port, &bufs[port])
 * and, when bit 7 of the record's byte 0 is set and FUN_a00870a4(*rate, buf) is not 4, FUN_a0086fb0(buf, *rate,
 * &b, &a) and FUN_a00aaf94(port, a, b), while FUN_a0086540(port, *rate, b, a) is nonzero (result 2 after the
 * loop). A clear bit 7, a round counter above 5 (set back to 1 when b changes) or a previous b > 2 clears the
 * port's mask bit (port 0 then returns 2 or 8);
 * FUN_a00870a4 == 4 gives result 4. Returns the result (initially 1).
 * Source forms the exact build depends on: lo initialised to 0 at its declaration and assigned again in the
 * '!all' arm as 'hi = 0; lo = 0;' (the firmware's 'mov %l6,%l4' copy of prev's zero register).
 */
struct Lane {
    unsigned char ok : 1;
    unsigned char f0 : 7;
    unsigned char b[15];
};
extern unsigned char DAT_a80761bf;
extern unsigned char DAT_a80761c0;
extern unsigned char ARR_a807cd2e[][6];
extern void FUN_a00aa930(unsigned char, unsigned char);
extern void FUN_a00aaf94(unsigned char, unsigned char, unsigned char);
extern unsigned char FUN_a008642c(unsigned int, unsigned int, unsigned int, unsigned char, unsigned char);
extern void FUN_a00b1794(int);
extern void FUN_a0086e58(unsigned char, struct Lane *);
extern unsigned char FUN_a00870a4(unsigned int, struct Lane *);
extern void FUN_a0086fb0(struct Lane *, unsigned char, unsigned char *, unsigned char *);
extern unsigned char FUN_a0086540(unsigned int, unsigned int, unsigned char, unsigned char);

unsigned char FUN_a0087110(unsigned char all, unsigned char *rate, struct Lane *bufs, unsigned char *mask)
{
    unsigned char prev = 0;
    unsigned char a = 0;
    unsigned char b = 0;
    unsigned char ret = 1;
    unsigned char lo = 0;
    unsigned char hi;
    unsigned char port;
    unsigned char cnt;
    struct Lane *buf;
    unsigned char t;

    if (!all) {
        hi = 0;
        lo = 0;
    } else {
        lo = DAT_a80761c0;
        hi = DAT_a80761bf;
    }
    for (port = lo; port <= hi; port++) {
        if ((*mask >> port) & 1) {
            FUN_a00aa930(port, 0);
            FUN_a00aaf94(port, 0, a);
            if (FUN_a008642c(port, 0, *rate, 0, 0) == 0) {
                *mask &= ~(1 << port);
                if (port == 0)
                    return 8;
            }
        }
    }
    for (port = lo; port <= hi; port++) {
        if ((*mask >> port) & 1) {
            buf = &bufs[port];
            cnt = 1;
            do {
                FUN_a00b1794(ARR_a807cd2e[port][5]);
                FUN_a0086e58(port, buf);
                if (!buf->ok) {
                    *mask &= ~(1 << port);
                    if (port == 0)
                        return 2;
                    goto next;
                }
                t = *rate;
                if (FUN_a00870a4(t, buf) == 4) {
                    ret = 4;
                    goto next;
                }
                FUN_a0086fb0(buf, t, &b, &a);
                t = b;
                if (t != prev)
                    cnt = 1;
                cnt++;
                if (cnt > 5 || prev > 2) {
                    *mask &= ~(1 << port);
                    if (port == 0)
                        return 8;
                    goto next;
                }
                prev = b;
                FUN_a00aaf94(port, a, t);
            } while (FUN_a0086540(port, *rate, t, a));
            ret = 2;
        }
    next:;
    }
    return ret;
}
