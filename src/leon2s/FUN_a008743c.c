/* FUN_a008743c (leon2s 0xa008743c-0xa00876ec, 688 bytes), flags -mcpu=v8 -Os -g.
 * unsigned char (all, rate, bufs, mask). Ports lo..hi are 0..0, or DAT_a80761c0..DAT_a80761bf when all != 0;
 * b and a are stack bytes, both 0 at the start.
 * Pass 1, for every port with its bit set in *mask: mode = 3 when bit 5 of ARR_a807cd2e[port][0] is set,
 * otherwise 2 when its bit 6 is set and 1 when not; FUN_a00aa930(port, mode), FUN_a0086fb0(&bufs[port], *rate,
 * &b, &a); when FUN_a008642c(port, mode, *rate, b, a) returns 0 the port's bit is cleared (port 0 then returns 2).
 * Pass 2, for every port still set, with cnt = 1: FUN_a00b1794(ARR_a807cd2e[port][5]), FUN_a0086e58(port, buf),
 * cnt + 1; bit 7 of the record's byte 0 clear: port 0 returns 2, other ports go to the next port.
 * ret = FUN_a0087364(*rate, buf): 5 goes to the next port; 8 or 9 clears the port's bit, or for port 0 passes
 * "Lost CDR\r" to FUN_a00734c4 and returns ret when FUN_a0087074(0) is 1, otherwise 8; cnt above 5 clears the
 * port's bit, or for port 0 returns 9 when FUN_a0087074(0) is 1, otherwise 8. Otherwise FUN_a0086fb0(buf, *rate,
 * &b, &a) and FUN_a00aaf94(port, a, b), repeated while FUN_a0086540(port, *rate, b, a) is nonzero (ret = 2 after
 * the loop). Returns ret (initially 1).
 * Source forms the exact build depends on: lo = 0 at its declaration and 'lo = 0; hi = 0;' in the '!all' arm,
 * cnt = 0 at its declaration (lo's zero is copied from that register); mode set in both arms of the bit 5 test;
 * in the 8/9 and cnt paths the bit clear comes first ('if (port != 0) { ...; goto next; }').
 * FUN_a008642c, FUN_a0086540, FUN_a0087364 and FUN_a0087074 are declared returning unsigned char here (their
 * definitions return int / unsigned int / unsigned int / int); the firmware masks each result to 8 bits right
 * after the call, as in FUN_a0087110.
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
extern unsigned char FUN_a008642c(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern void FUN_a00b1794(int);
extern void FUN_a0086e58(unsigned char, struct Lane *);

extern void FUN_a0086fb0(struct Lane *, unsigned char, unsigned char *, unsigned char *);
extern unsigned char FUN_a0086540(unsigned char, unsigned char, unsigned char, unsigned char);
extern unsigned char FUN_a0087364(unsigned char, struct Lane *);
extern int FUN_a00734c4(const char *);
extern unsigned char FUN_a0087074(unsigned int);

unsigned char FUN_a008743c(unsigned char all, unsigned char *rate, struct Lane *bufs, unsigned char *mask)
{
    unsigned char b = 0;
    unsigned char a = 0;
    unsigned char ret = 1;
    unsigned char lo = 0;
    unsigned char hi;
    unsigned char port;
    unsigned char cnt = 0;
    unsigned char mode;
    unsigned char x;
    unsigned char t;
    unsigned char r;
    struct Lane *buf;

    if (!all) {
        lo = 0;
        hi = 0;
    } else {
        lo = DAT_a80761c0;
        hi = DAT_a80761bf;
    }
    for (port = lo; port <= hi; port++) {
        buf = &bufs[port];
        if ((*mask >> port) & 1) {
            x = ((ARR_a807cd2e[port][0] >> 6) & 1) ^ 1;
            if (ARR_a807cd2e[port][0] & 0x20)
                mode = 3;
            else
                mode = 2 - x;
            FUN_a00aa930(port, mode);
            FUN_a0086fb0(buf, *rate, &b, &a);
            if (FUN_a008642c(port, mode, *rate, b, a) == 0) {
                *mask &= ~(1 << port);
                if (port == 0)
                    return 2;
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
                cnt++;
                if (!buf->ok) {
                    if (port == 0)
                        return 2;
                    goto next;
                }
                t = *rate;
                ret = FUN_a0087364(t, buf);
                r = ret;
                if (r == 5)
                    goto next;
                if (ret == 8 || ret == 9) {
                    if (port != 0) {
                        *mask &= ~(1 << port);
                        goto next;
                    }
                    FUN_a00734c4("Lost CDR\r");
                    if (FUN_a0087074(0) == 1)
                        return r;
                    return 8;
                }
                if (cnt > 5) {
                    if (port != 0) {
                        *mask &= ~(1 << port);
                        goto next;
                    }
                    if (FUN_a0087074(0) == 1)
                        return 9;
                    return 8;
                }
                FUN_a0086fb0(buf, t, &b, &a);
                FUN_a00aaf94(port, a, b);
            } while (FUN_a0086540(port, *rate, b, a));
            ret = 2;
        }
    next:;
    }
    return ret;
}
