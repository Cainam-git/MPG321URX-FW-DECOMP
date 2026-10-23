/* FUN_a00c2758 (leon2s 0xa00c2758-0xa00c2de4, 1676 bytes), flags -mcpu=v8 -Os -g.
 * Three-step state machine for port 0..5 on the 16-byte record DAT_a807d5c8[port] (word 0 bit 27, state byte
 * +0xc). Ports 0-1 store port in DAT_a807d5c6 (index i = port, kind 0x20, selector 0), ports 2-3 in
 * DAT_a807d629 (i = port - 2, kind 0x21, selector 1), others in DAT_a807d62b (i = port - 4, kind 0, selector 2).
 * Below, W(r, v) = func_0xa0fb65c4 / func_0xa0fb69fc / func_0xa0fb6c00(i, r, v) for kind 0x20 / 0x21 / 0,
 * M(r, m, b) = func_0xa0fb6c98(i, r, m, b), R6(r) = func_0xa0fb6bb8(i, r).
 * - state 0: fills DAT_a8078d38[0..127]: kind 0x20: W(0x310, 0x24), then func_0xa0fb657c(i, 0x312) per byte,
 *   stored from index 127 down; kind 0x21: W(0xa6, 3), W(0xa4, 0x20), then per byte n W(0xa5, n) and
 *   func_0xa0fb69b4(i, 0xa7), stored from index 127 down; kind 0: W(0x403, 0), M(0x402, 0x80, 1), W(0x400, 4),
 *   then R6(0x401) per byte in order. Then FUN_a00c22a0(selector), state = 1.
 * - state 1: while bit 27 is 0 it is set to bit 0 of FUN_a00c2488(selector, DAT_a8078eb8); when it is 1, it
 *   is cleared and state = 2.
 * - state 2: FUN_a00c255c(selector), then sends DAT_a8078cb8[1..16]: kind 0x20: W(0x310, 0x34), bytes 16..1 with
 *   W(0x312, b), then W(0x312, 1); kind 0x21: W(0xa6, 0x21), W(0xa4, 0), for n = 16..1 W(0xa5, 16 - n) and
 *   W(0xa7, byte n), then W(0xa5, 16), W(0xa7, 1); kind 0: W(0x400, 0xf), M(0x402, 0x80, 1), W(0x403, 0),
 *   bytes 1..16 with W(0x401, b), M(0, 0x20, 0), M(0x405, 1, 0), then W(0x406, 8 / 9 / 0xc0), each followed by
 *   polling R6(0x406) while bit 3 (bit 7 after 0xc0) is set, at most 256 times, func_0xa0fc160c(1) between
 *   polls; M(0x30, 0x40, 1); polling R6(0x408) until bit 4 is set, at most 1001 times, func_0xa0fc1794(1)
 *   between polls; if the u16 counter is not 0 after that: W(0x406, 0xb), polling R6(0x406) while bit 3 is set
 *   (at most 256 times, no delay), M(0x30, 0x40, 1); last M(0x405, 1, 1). Then state = 0, the first of
 *   DAT_a807d5c6 / DAT_a807d629 / DAT_a807d62b that equals port is set to 0xff, and the result is 1.
 * Returns r & 1 (r = 0 except at the end of state 2).
 * Source forms: the index is an unsigned short (an int index is merged with port and changes the register
 * allocation); word 0 is a union of the plain word (bit 27 tests) and a bit-field view (bit 27 writes); in
 * state 1 the bit is cleared before the state byte is written.
 */
struct Rec16 {
    union {
        unsigned int w;
        struct {
            unsigned int f31:4;
            unsigned int f27:1;
            unsigned int low:27;
        } f;
    } u;
    unsigned char pad4[8];
    unsigned char state;
    unsigned char pad13[3];
};
extern struct Rec16 DAT_a807d5c8[];
extern unsigned char DAT_a807d5c6;
extern unsigned char DAT_a807d629;
extern unsigned char DAT_a807d62b;
extern unsigned char DAT_a8078d38[];
extern unsigned char DAT_a8078cb8[];
extern unsigned char DAT_a8078eb8[];
extern unsigned char FUN_a00c2488(unsigned char, unsigned char *);
extern void FUN_a00c255c(unsigned char);
extern void FUN_a00c22a0(unsigned char);
extern void func_0xa0fb65c4(unsigned char, unsigned short, unsigned char);
extern unsigned int func_0xa0fb657c(unsigned char, unsigned short);
extern void func_0xa0fb69fc(unsigned char, unsigned short, unsigned char);
extern unsigned int func_0xa0fb69b4(unsigned char, unsigned short);
extern void func_0xa0fb6c00(unsigned char, unsigned short, unsigned char);
extern void func_0xa0fb6c98(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned char func_0xa0fb6bb8(unsigned char, unsigned short);
extern void func_0xa0fc160c(unsigned int);
extern void func_0xa0fc1794(unsigned int);

unsigned char FUN_a00c2758(unsigned char port)
{
    struct Rec16 *rec = &DAT_a807d5c8[port];
    unsigned char r = 0;
    unsigned short idx;
    unsigned char kind;
    unsigned char sel;
    unsigned short i;
    unsigned short n;

    if (port < 2) {
        DAT_a807d5c6 = port;
        idx = port;
        kind = 0x20;
        sel = 0;
    } else if (port < 4) {
        DAT_a807d629 = port;
        idx = port - 2;
        kind = 0x21;
        sel = 1;
    } else {
        DAT_a807d62b = port;
        idx = port - 4;
        kind = 0;
        sel = 2;
    }
    switch (rec->state) {
    case 0:
        if (kind == 0x20) {
            func_0xa0fb65c4(idx, 0x310, 0x24);
            for (i = 0; i < 0x80; i++)
                DAT_a8078d38[0x7f - i] = func_0xa0fb657c(idx, 0x312);
        } else if (kind == 0x21) {
            func_0xa0fb69fc(idx, 0xa6, 3);
            func_0xa0fb69fc(idx, 0xa4, 0x20);
            for (i = 0; i < 0x80; i++) {
                func_0xa0fb69fc(idx, 0xa5, i);
                DAT_a8078d38[0x7f - i] = func_0xa0fb69b4(idx, 0xa7);
            }
        } else {
            func_0xa0fb6c00(idx, 0x403, 0);
            func_0xa0fb6c98(idx, 0x402, 0x80, 1);
            func_0xa0fb6c00(idx, 0x400, 4);
            for (i = 0; i < 0x80; i++)
                DAT_a8078d38[i] = func_0xa0fb6bb8(idx, 0x401);
        }
        FUN_a00c22a0(sel);
        rec->state = 1;
        break;
    case 1:
        if ((rec->u.w & 0x8000000) == 0)
            rec->u.f.f27 = FUN_a00c2488(sel, DAT_a8078eb8);
        if (rec->u.w & 0x8000000) {
            rec->u.f.f27 = 0;
            rec->state = 2;
        }
        break;
    case 2:
        FUN_a00c255c(sel);
        if (kind == 0x20) {
            func_0xa0fb65c4(idx, 0x310, 0x34);
            for (i = 0x10; i != 0; i--)
                func_0xa0fb65c4(idx, 0x312, DAT_a8078cb8[i]);
            func_0xa0fb65c4(idx, 0x312, 1);
        } else if (kind == 0x21) {
            func_0xa0fb69fc(idx, 0xa6, 0x21);
            func_0xa0fb69fc(idx, 0xa4, 0);
            for (i = 0x10; i != 0; i--) {
                func_0xa0fb69fc(idx, 0xa5, 0x10 - i);
                func_0xa0fb69fc(idx, 0xa7, DAT_a8078cb8[i]);
            }
            func_0xa0fb69fc(idx, 0xa5, 0x10);
            func_0xa0fb69fc(idx, 0xa7, 1);
        } else {
            func_0xa0fb6c00(idx, 0x400, 0xf);
            func_0xa0fb6c98(idx, 0x402, 0x80, 1);
            func_0xa0fb6c00(idx, 0x403, 0);
            for (i = 0; i < 0x10; i++)
                func_0xa0fb6c00(idx, 0x401, DAT_a8078cb8[i + 1]);
            func_0xa0fb6c98(idx, 0, 0x20, 0);
            func_0xa0fb6c98(idx, 0x405, 1, 0);
            func_0xa0fb6c00(idx, 0x406, 8);
            n = 0xff;
            while ((func_0xa0fb6bb8(idx, 0x406) & 8) && n--)
                func_0xa0fc160c(1);
            func_0xa0fb6c00(idx, 0x406, 9);
            n = 0xff;
            while ((func_0xa0fb6bb8(idx, 0x406) & 8) && n--)
                func_0xa0fc160c(1);
            func_0xa0fb6c00(idx, 0x406, 0xc0);
            n = 0xff;
            while ((func_0xa0fb6bb8(idx, 0x406) & 0x80) && n--)
                func_0xa0fc160c(1);
            func_0xa0fb6c98(idx, 0x30, 0x40, 1);
            n = 1000;
            while (!(func_0xa0fb6bb8(idx, 0x408) & 0x10) && n--)
                func_0xa0fc1794(1);
            if (n != 0) {
                func_0xa0fb6c00(idx, 0x406, 0xb);
                n = 0xff;
                while ((func_0xa0fb6bb8(idx, 0x406) & 8) && n--)
                    ;
                func_0xa0fb6c98(idx, 0x30, 0x40, 1);
            }
            func_0xa0fb6c98(idx, 0x405, 1, 1);
        }
        rec->state = 0;
        r = 1;
        if (DAT_a807d5c6 == port)
            DAT_a807d5c6 = 0xff;
        else if (DAT_a807d629 == port)
            DAT_a807d629 = 0xff;
        else if (DAT_a807d62b == port)
            DAT_a807d62b = 0xff;
        break;
    }
    return r & 1;
}
