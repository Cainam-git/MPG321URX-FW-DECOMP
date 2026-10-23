/*
 * FUN_a00c9398 (leon2s, 0xa00c9398-0xa00c966c, 724 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Works on the 24-byte record DAT_a8078bb0[port] (bit-fields as in FUN_a00c91f8: f28,
 * cnt = bits 24..27, st = bits 16..17). Sets st = 1; sel = 1 when byte +1 of the 28-byte record
 * ARR_a807d580[port] is 0x41 or 0x61, else 0.
 * - (u8)FUN_a00c9368(port) == 1 and FUN_a00c9370(port) == 0: FUN_a00c89b8(port, 1); with f28 clear:
 *   FUN_a00c7bf8(port) != 0 sets st = 3 and calls FUN_a00c89b8(port, 0); FUN_a00c82dc(port, h) != 0 calls
 *   FUN_a00c89b8(port, 0) and sets st = 3 (both return); bit 4 of h[1] calls
 *   func_0xa0fb80cc(port, 0, 0x12f, 1, 1). Then FUN_a00c8a1c(port, 1) and registers 0x71..0x73 = 0xff
 *   (func_0xa0fb8054(port, 0, reg, 0xff)).
 * - otherwise, FUN_a00c9368(port) == 0: when FUN_a00c9370(port) == 1, FUN_a00c8a1c(port, 0) and
 *   FUN_a00c89b8(port, 0); return.
 * - then bit 1 of func_0xa0fb657c(sel, 0x71) sets st = 3 and returns; bits 4..7 of
 *   func_0xa0fb7fd8(port, 0, 0x73) set: registers 0x71..0x73 = 0xff, cnt--, st = 3,
 *   func_0xa0fb657c(sel, 0x2e).
 * Source forms: the sel switch carries a case 0x31 with the default action (see FUN_a00c8c64: it only
 * shapes the compare tree, its compare is removed); cnt-- is written before st = 3 (one read-modify-write).
 */
struct Rec24 {
    unsigned int a : 3;
    unsigned int f28 : 1;
    unsigned int cnt : 4;
    unsigned int f23 : 1;
    unsigned int mid : 5;
    unsigned int st : 2;
    unsigned int x : 8;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char pad[17];
};
struct Rec28 { unsigned char b0; unsigned char b1; unsigned char pad[26]; };
extern struct Rec24 DAT_a8078bb0[];
extern struct Rec28 ARR_a807d580[];
extern unsigned char FUN_a00c9368(unsigned char);
extern unsigned char FUN_a00c9370(unsigned char);
extern void FUN_a00c89b8(unsigned char, unsigned char);
extern void FUN_a00c8a1c(unsigned char, unsigned char);
extern unsigned char FUN_a00c7bf8(unsigned char);
extern unsigned char FUN_a00c82dc(unsigned char, unsigned char *);
extern void func_0xa0fb80cc(unsigned char, int, int, int, int);
extern void func_0xa0fb8054(unsigned char, int, int, unsigned char);
extern unsigned int func_0xa0fb657c(unsigned char, unsigned short);
extern unsigned char func_0xa0fb7fd8(unsigned char, int, unsigned short);

void FUN_a00c9398(unsigned char port)
{
    unsigned char h[2];
    unsigned char sel;

    sel = 0;
    DAT_a8078bb0[port].st = 1;
    switch (ARR_a807d580[port].b1) {
    case 0x31:
        sel = 0;
        break;
    case 0x41:
        sel = 1;
        break;
    case 0x51:
        sel = 0;
        break;
    case 0x61:
        sel = 1;
        break;
    }
    if (FUN_a00c9368(port) == 1 && FUN_a00c9370(port) == 0) {
        FUN_a00c89b8(port, 1);
        if (DAT_a8078bb0[port].f28 == 0) {
            if (FUN_a00c7bf8(port)) {
                DAT_a8078bb0[port].st = 3;
                FUN_a00c89b8(port, 0);
                return;
            }
            if (FUN_a00c82dc(port, h)) {
                FUN_a00c89b8(port, 0);
                DAT_a8078bb0[port].st = 3;
                return;
            }
            if (h[1] & 0x10)
                func_0xa0fb80cc(port, 0, 0x12f, 1, 1);
        }
        FUN_a00c8a1c(port, 1);
        func_0xa0fb8054(port, 0, 0x71, 0xff);
        func_0xa0fb8054(port, 0, 0x72, 0xff);
        func_0xa0fb8054(port, 0, 0x73, 0xff);
    } else if (FUN_a00c9368(port) == 0) {
        if (FUN_a00c9370(port) == 1) {
            FUN_a00c8a1c(port, 0);
            FUN_a00c89b8(port, 0);
        }
        return;
    }
    if (func_0xa0fb657c(sel, 0x71) & 2) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    if (func_0xa0fb7fd8(port, 0, 0x73) & 0xf0) {
        func_0xa0fb8054(port, 0, 0x71, 0xff);
        func_0xa0fb8054(port, 0, 0x72, 0xff);
        func_0xa0fb8054(port, 0, 0x73, 0xff);
        DAT_a8078bb0[port].cnt--;
        DAT_a8078bb0[port].st = 3;
        func_0xa0fb657c(sel, 0x2e);
    }
}
