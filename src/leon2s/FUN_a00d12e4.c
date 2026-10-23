/*
 * FUN_a00d12e4 (leon2s, 0xa00d12e4-0xa00d17a8, 1220 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Works on the 24-byte record DAT_a8078bb0[port] (layout of FUN_a00c7a4c: word 0 bit-fields
 * f31, f30, f28, cnt = bits 24..27, st = bits 16..17; byte +2 = x; word +0x10) and two 3-byte stack arrays
 * prev and flag, both cleared on entry.
 * - Condition: port != 2 ? func_0xa0fa1bac(port) == 0 : func_0xa0f98ea0(0) != 0 && func_0xa0f98f28(0) == 1.
 *   When it holds: x & 0x10: x <= 0x11 returns; x > 0x14 sets flag[port]; x == 0x18 with flag[port] == 1
 *   clears it, calls FUN_a00ccad4(port), FUN_a00c7a4c(port, 0) and returns. x & 0x40: x <= 0x4e returns;
 *   x == 0x4f calls FUN_a00ccad4(port) and FUN_a00c7a4c(port, 0).
 * - f31 == 0 returns.
 * - port <= 1, f30 == 0, x > 0x43: with f28 and x == 0x4f: FUN_a00cbb50(port), then st == 3 sets st = 1,
 *   st == 1 sets x = 0x4a, st == 0 calls FUN_a00c7a4c(port, 0), and FUN_a00d0d78(port); otherwise
 *   FUN_a00cc9f8(port) != 0 prints s_9f1c21a8 with func_0xa0f83044 and calls FUN_a00c7a4c(port, 0).
 * - port == 2 and bit 2 of func_0xa0f93710(0): when f30 == 0 or x > 0x4a: with f28 and x > 0x4a the same
 *   st handling around FUN_a00cef6c(port), else FUN_a00cf9e8(0) != 0 calls FUN_a00c7a4c(port, 0).
 * - prev[port] = x when different; port 2: FUN_a00d0968(port) when DAT_a8078c5a != 0; port <= 1:
 *   FUN_a00d03a0(port).
 * - f30 set: when (st == 3 and FUN_a00cfb20(port + 0xb) == 0) or cnt == 0: st = 0, and st = 2 when
 *   x == 0x4d and word +0x10 != 0xffffff.
 * - f30 == 0 and cnt == 0: cnt = 10, st = 0. Ends with FUN_a00d0d78(port).
 * Source forms: the first condition is one ?: expression; each st dispatch reads st into its own block-local
 * int and compares (unsigned char)st with 3 and 1, the 0 test reads the field again; every record access
 * indexes with the variable port.
 */
struct Rec18 {
    unsigned int f31 : 1;
    unsigned int f30 : 1;
    unsigned int f29 : 1;
    unsigned int f28 : 1;
    unsigned int cnt : 4;
    unsigned int b23 : 1;
    unsigned int b22 : 1;
    unsigned int b21 : 1;
    unsigned int b20 : 1;
    unsigned int b19 : 1;
    unsigned int b18 : 1;
    unsigned int st : 2;
    unsigned char x;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char b8;
    unsigned char b9;
    unsigned char pad_a[2];
    unsigned int wc;
    unsigned int w10;
    unsigned char b14;
    unsigned char pad_15;
    unsigned short h16;
};
extern struct Rec18 DAT_a8078bb0[];
extern unsigned char DAT_a8078c5a;
extern const char s_9f1c21a8[];
extern unsigned char func_0xa0fa1bac(unsigned char);
extern unsigned char func_0xa0f98ea0(int);
extern unsigned char func_0xa0f98f28(int);
extern unsigned int func_0xa0f93710(int);
extern int func_0xa0f83044(const char *, ...);
extern void FUN_a00ccad4(unsigned char);
extern void FUN_a00c7a4c(unsigned char, unsigned char);
extern void FUN_a00cbb50(unsigned char);
extern unsigned char FUN_a00cc9f8(unsigned char);
extern void FUN_a00cef6c(unsigned char);
extern unsigned char FUN_a00cf9e8(unsigned char);
extern int FUN_a00cfb20(int);
extern void FUN_a00d0968(unsigned char);
extern void FUN_a00d03a0(unsigned char);
extern void FUN_a00d0d78(unsigned char);

void FUN_a00d12e4(unsigned char port)
{
    unsigned char prev[3] = {0, 0, 0};
    unsigned char flag[3] = {0, 0, 0};

    if (port != 2 ? func_0xa0fa1bac(port) == 0 : func_0xa0f98ea0(0) != 0 && func_0xa0f98f28(0) == 1) {
        if (DAT_a8078bb0[port].x & 0x10) {
            if (DAT_a8078bb0[port].x <= 0x11)
                return;
            if (DAT_a8078bb0[port].x > 0x14)
                flag[port] = 1;
            if (DAT_a8078bb0[port].x == 0x18 && flag[port] == 1) {
                flag[port] = 0;
                FUN_a00ccad4(port);
                FUN_a00c7a4c(port, 0);
                return;
            }
        }
        if (DAT_a8078bb0[port].x & 0x40) {
            if (DAT_a8078bb0[port].x <= 0x4e)
                return;
            if (DAT_a8078bb0[port].x == 0x4f) {
                FUN_a00ccad4(port);
                FUN_a00c7a4c(port, 0);
            }
        }
    }
    if (DAT_a8078bb0[port].f31 == 0)
        return;
    if (port <= 1 && DAT_a8078bb0[port].f30 == 0 && DAT_a8078bb0[port].x > 0x43) {
        if (DAT_a8078bb0[port].f28 && DAT_a8078bb0[port].x == 0x4f) {
            int st;

            FUN_a00cbb50(port);
            st = DAT_a8078bb0[port].st;
            if ((unsigned char)st == 3)
                DAT_a8078bb0[port].st = 1;
            else if ((unsigned char)st == 1)
                DAT_a8078bb0[port].x = 0x4a;
            else if (DAT_a8078bb0[port].st == 0)
                FUN_a00c7a4c(port, 0);
            FUN_a00d0d78(port);
        } else if (FUN_a00cc9f8(port)) {
            func_0xa0f83044(s_9f1c21a8);
            FUN_a00c7a4c(port, 0);
        }
    }
    if (port == 2 && (func_0xa0f93710(0) & 4)) {
        if (DAT_a8078bb0[port].f30 == 0 || DAT_a8078bb0[port].x > 0x4a) {
            if (DAT_a8078bb0[port].f28 && DAT_a8078bb0[port].x > 0x4a) {
                int st;

                FUN_a00cef6c(port);
                st = DAT_a8078bb0[port].st;
                if ((unsigned char)st == 3)
                    DAT_a8078bb0[port].st = 1;
                else if ((unsigned char)st == 1)
                    DAT_a8078bb0[port].x = 0x4a;
                else if (DAT_a8078bb0[port].st == 0)
                    FUN_a00c7a4c(port, 0);
                FUN_a00d0d78(port);
            } else if (FUN_a00cf9e8(0)) {
                FUN_a00c7a4c(port, 0);
            }
        }
    }
    if (prev[port] != DAT_a8078bb0[port].x)
        prev[port] = DAT_a8078bb0[port].x;
    if (port == 2) {
        if (DAT_a8078c5a)
            FUN_a00d0968(port);
    } else if (port <= 1) {
        FUN_a00d03a0(port);
    }
    if (DAT_a8078bb0[port].f30) {
        if ((DAT_a8078bb0[port].st == 3 && FUN_a00cfb20(port + 0xb) == 0) || DAT_a8078bb0[port].cnt == 0) {
            DAT_a8078bb0[port].st = 0;
            if (DAT_a8078bb0[port].x == 0x4d && DAT_a8078bb0[port].w10 != 0xffffff)
                DAT_a8078bb0[port].st = 2;
        }
    }
    if (DAT_a8078bb0[port].f30 == 0 && DAT_a8078bb0[port].cnt == 0) {
        DAT_a8078bb0[port].cnt = 10;
        DAT_a8078bb0[port].st = 0;
    }
    FUN_a00d0d78(port);
}
