/* FUN_a0088c5c (leon2s 0xa0088c5c-0xa0088ea0, 580 bytes), flags -mcpu=v8 -Os -g.
 * unsigned char (u8 all, buf, mask). Walks port = lo..hi, with lo/hi = DAT_a80761c0/DAT_a80761bf when all is
 * non-zero, else 0..0. Ports where FUN_a0088af0(port) is 0 are skipped; otherwise lanes = FUN_a00a78b4(port, 3)
 * & 0x1f and FUN_a0086e58(port, buf). With bit 7 of buf[0] clear, bit port of *mask is cleared and port 0 sets
 * fail. With it set: func_0x9f1cc078(buf[3]) when FUN_a00866a4() is non-zero and port is 0; fail with the print
 * "DPTX(%d) Training Lost\r\n" when FUN_a0087364(lanes, buf) != 5; fail when bit 0 of buf[6] is clear; when
 * FUN_a0086bd8() is non-zero and port is 0, r = FUN_a00858f0(port) gives v = FUN_a00a6bb8(0, 0x80) (r == 0x71
 * and FUN_a00ad27c(port) == 1) or FUN_a00a6bb8(1, 0x80) (r == 0x81), else 0xff, and for v != 0xff a
 * FUN_a00a78b4(port, 2) value other than 6, 10, 0x14 or 0x1e for v & 3 = 0..3 sets fail. Returns 1 as soon
 * as a port sets fail, 0 after the range.
 * Source form: bit 7 of buf[0] is a 1-bit bit-field; the v & 3 checks are one '||' condition of four
 * '(m == k && FUN_a00a78b4(port, 2) != X)' terms; the clear-bit path is 'if (port != 0) continue; fail = 1;'.
 * Compiler aid: '__builtin_expect(fail, 1)' on the per-port exit test emits no instructions (block order).
 * Compiler aid: the second 'lo = hi;' repeats the value lo already holds and emits no instruction; GCC keeps it
 * as a register copy (of fail's register after copy propagation) instead of a clear, as the firmware's
 * 'mov %l2,%o0' for the all == 0 path.
 */
extern unsigned char DAT_a80761bf;
extern unsigned char DAT_a80761c0;
extern unsigned char FUN_a0088af0(unsigned char);
extern unsigned char FUN_a00a78b4(unsigned char, unsigned short);
extern void FUN_a0086e58(unsigned char, unsigned char *);
extern unsigned char FUN_a00866a4(void);
extern void func_0x9f1cc078(unsigned char);
extern unsigned char FUN_a0087364(unsigned char, unsigned char *);
extern int FUN_a0073044(const char *, ...);
extern unsigned char FUN_a0086bd8(void);
extern unsigned char FUN_a00858f0(unsigned char);
extern unsigned char FUN_a00ad27c(unsigned char);
extern unsigned char FUN_a00a6bb8(unsigned char, unsigned short);

struct b0 { unsigned char ok : 1; unsigned char rest : 7; };

unsigned char FUN_a0088c5c(unsigned char all, unsigned char *buf, unsigned char *mask)
{
    unsigned char fail;
    unsigned char lo;
    unsigned char hi;
    unsigned char port;
    unsigned char lanes;
    unsigned char r;
    unsigned char v;
    unsigned int m;

    lo = hi = fail = 0;
    lo = hi;
    if (all) {
        lo = DAT_a80761c0;
        hi = DAT_a80761bf;
    }
    for (port = lo; port <= hi; port++) {
        if (FUN_a0088af0(port) == 0)
            continue;
        lanes = FUN_a00a78b4(port, 3) & 0x1f;
        FUN_a0086e58(port, buf);
        if (!((struct b0 *)buf)->ok) {
            *mask &= ~(1 << port);
            if (port != 0)
                continue;
            fail = 1;
        } else {
            if (FUN_a00866a4() && port == 0)
                func_0x9f1cc078(buf[3]);
            if (FUN_a0087364(lanes & 0x1f, buf) != 5) {
                FUN_a0073044("DPTX(%d) Training Lost\r\n", port);
                fail = 1;
            }
            if (!(buf[6] & 1))
                fail = 1;
            if (FUN_a0086bd8() && port == 0) {
                r = FUN_a00858f0(port);
                v = 0xff;
                if (r == 0x71) {
                    if (FUN_a00ad27c(port) == 1)
                        v = FUN_a00a6bb8(0, 0x80);
                } else if (r == 0x81)
                    v = FUN_a00a6bb8(1, 0x80);
                if (v != 0xff) {
                    m = v & 3;
                    if ((m == 0 && FUN_a00a78b4(port, 2) != 6) ||
                        (m == 1 && FUN_a00a78b4(port, 2) != 10) ||
                        (m == 2 && FUN_a00a78b4(port, 2) != 0x14) ||
                        (m == 3 && FUN_a00a78b4(port, 2) != 0x1e))
                        fail = 1;
                }
            }
        }
        if (__builtin_expect(fail, 1))
            return 1;
    }
    return 0;
}
