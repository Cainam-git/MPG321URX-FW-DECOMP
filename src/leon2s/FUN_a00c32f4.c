/* FUN_a00c32f4 (leon2s 0xa00c32f4-0xa00c3ab0, 1980 bytes), flags -mcpu=v8 -Os -g.
 * void. For i = 0, 1 over the 16-byte records DAT_a807d5c8[i] (word 0, byte +4, bytes +0xc and +0xd = state):
 * sel = 0 / 1 / 2 by the lowest set bit 0 / 1 / 2 of byte +4 (kept when none is set). Returns when bits 24..26
 * of word 0 are not 5. Registers of port i are read with func_0xa0fb657c(i, reg) (low byte) and written with
 * func_0xa0fb65c4(i, reg, v) and func_0xa0fb67b8(i, reg, mask, on). Register 0x319 bit 4: clears bit 7 of 0x31f
 * when set, sets bit 2 of 0x305 when bit 1 of 0x71 is set, writes 0x10 to 0x319; bit 1: sets bit 7 of 0x31f
 * when clear, writes 2 to 0x319. Bit 0 of 0x318 clears bytes +0xd and +0xc and writes 3 to 0x305. Then by the
 * state (switch with jump table 0xa00c32bc, linked at 0x9f1b32bc):
 * 0, 1: on bit 0 of 0x318: FUN_a00c224c(DAT_a8078620), 0x2d to 0x310, the 8 bytes DAT_a8078620[] to 0x312,
 *   0 to 0x303 / 0x304, 0x60 to 0x319, waits up to 3000 reads for bit 6 of 0x319, sets bit 7 of 0x31f and bit 1
 *   of 0x308, 0xff to 0x318, state 2; when byte +4 is nonzero: sel 2 clears bit 1 of register 0xcf018d00,
 *   other sel call FUN_a00c76c0(sel, 4, 0x10, 0) and func_0xa0fb80cc(sel, 0, 0xf, 1, 0); clears bit 23.
 * 2: bit 1 of 0x318: acknowledged, state 3, bits 31 and 30 cleared; else bit 2: acknowledged, state 4.
 * 3: bit 31 clear: bit 31 = FUN_a00c2758(i) when DAT_a807d5c6 is 0xff or i; bit 30 cleared. Bit 31 set and
 *   bit 30 clear: on bit 3 of 0x318, acknowledged, bit 2 of 0x308 set, bit 30 set. Bit 30 set and bits 4..6
 *   of 0x30a clear: 0x10 to 0x318, bit 3 of 0x308 set, state 5.
 * 4: bit 3 of 0x318: acknowledged, bit 2 of 0x308 set, state 5. 7: bit 7 of 0x318: acknowledged, state 8.
 * 8: bit 0 of 0x319: acknowledged, bits 16..20 = 1; bit i of DAT_a8078c58 set: state 9 and DAT_a8078cb0 = 0,
 *   else state 0xd and func_0xa0f83044(s_9f1b7598, i).
 * 9: the sel step of state 0/1 (FUN_a00c76c0(sel, 0xf, 1, 0) as second call), bit 22 set: bit 5 of 0x308
 *   written 0, 1, 0; state 0xa.
 * 0xa, 0xd: FUN_a00c2de4(i) nonzero or bit 3 of 0x303 set: sets bit 3 of 0x303. Otherwise handles bits 0, 1,
 *   2, 6, 5 of 0x31a and bit 7 of 0x319 (acknowledge writes, bits of 0x303 / 0x308, DAT_a8078cb0 = 1 / 0;
 *   bit 0 only while DAT_a8078cb0 is 0; one extra read of 0x31a before the bit-5 test).
 * Then FUN_a00c3144(i).
 * Source forms: word 0 is a union of the word and a bit-field view (mask tests on the word, single bits
 * written as fields); in state 2 the state byte is written before the two bit clears; the register reads are
 * declared with an unsigned char result (the callee returns the low byte).
 */
struct bits {
    unsigned int b31 : 1;
    unsigned int b30 : 1;
    unsigned int _29 : 5;
    unsigned int b24 : 1;
    unsigned int b23 : 1;
    unsigned int b22 : 1;
    unsigned int _21 : 1;
    unsigned int f16 : 5;
    unsigned int _0 : 16;
};
struct rec16 {
    union { unsigned int w; struct bits f; } u;
    unsigned char b4;
    unsigned char _5[7];
    unsigned char bc;
    unsigned char bd;
    unsigned char _e[2];
};
extern struct rec16 DAT_a807d5c8[];
extern unsigned char DAT_a807d5c6;
extern unsigned char DAT_a8078c58;
extern unsigned char DAT_a8078cb0;
extern unsigned char DAT_a8078620[];
extern const char s_9f1b7598[];
#define REG_8D00 (*(volatile unsigned int *)0xcf018d00)
extern int func_0xa0f83044(const char *, ...);
extern unsigned char func_0xa0fb657c(unsigned char, unsigned short);
extern void func_0xa0fb65c4(unsigned char, unsigned short, unsigned char);
extern void func_0xa0fb67b8(unsigned char, unsigned short, unsigned int, unsigned char);
extern void func_0xa0fb80cc(unsigned char, int, int, int, int);
extern void FUN_a00c76c0(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00c224c(unsigned char *);
extern unsigned char FUN_a00c2758(unsigned char);
extern unsigned char FUN_a00c2de4(unsigned char);
extern void FUN_a00c3144(unsigned char);

void FUN_a00c32f4(void)
{
    unsigned char sel = 0;
    unsigned char i;
    unsigned short n, k;
    struct rec16 *r;

    for (i = 0; i < 2; i++) {
        r = &DAT_a807d5c8[i];
        if (r->b4 & 1)
            sel = 0;
        else if (r->b4 & 2)
            sel = 1;
        else if (r->b4 & 4)
            sel = 2;
        if ((r->u.w & 0x7000000) != 0x5000000)
            return;
        if (func_0xa0fb657c(i, 0x319) & 0x10) {
            if (func_0xa0fb657c(i, 0x31f) & 0x80)
                func_0xa0fb67b8(i, 0x31f, 0x80, 0);
            if (func_0xa0fb657c(i, 0x71) & 2)
                func_0xa0fb67b8(i, 0x305, 4, 1);
            func_0xa0fb65c4(i, 0x319, 0x10);
        }
        if (func_0xa0fb657c(i, 0x319) & 2) {
            if (!(func_0xa0fb657c(i, 0x31f) & 0x80))
                func_0xa0fb67b8(i, 0x31f, 0x80, 1);
            func_0xa0fb65c4(i, 0x319, 2);
        }
        if (func_0xa0fb657c(i, 0x318) & 1) {
            r->bd = 0;
            r->bc = 0;
            func_0xa0fb65c4(i, 0x305, 3);
        }
        switch (r->bd) {
        case 0:
        case 1:
            if (func_0xa0fb657c(i, 0x318) & 1) {
                FUN_a00c224c(DAT_a8078620);
                func_0xa0fb65c4(i, 0x310, 0x2d);
                k = 0;
                for (n = 0; n < 8; n++)
                    func_0xa0fb65c4(i, 0x312, DAT_a8078620[n]);
                func_0xa0fb65c4(i, 0x303, 0);
                func_0xa0fb65c4(i, 0x304, 0);
                func_0xa0fb65c4(i, 0x319, 0x60);
                while (!(func_0xa0fb657c(i, 0x319) & 0x40) && k < 3000)
                    k++;
                func_0xa0fb67b8(i, 0x31f, 0x80, 1);
                func_0xa0fb67b8(i, 0x308, 2, 1);
                func_0xa0fb65c4(i, 0x318, 0xff);
                r->bd = 2;
                if (r->b4 != 0) {
                    if (sel != 2) {
                        FUN_a00c76c0(sel, 4, 0x10, 0);
                        func_0xa0fb80cc(sel, 0, 0xf, 1, 0);
                    } else {
                        REG_8D00 &= ~2;
                    }
                }
                r->u.f.b23 = 0;
            }
            break;
        case 2:
            if (func_0xa0fb657c(i, 0x318) & 2) {
                func_0xa0fb65c4(i, 0x318, 2);
                r->bd = 3;
                r->u.f.b31 = 0;
                r->u.f.b30 = 0;
            } else if (func_0xa0fb657c(i, 0x318) & 4) {
                func_0xa0fb65c4(i, 0x318, 4);
                r->bd = 4;
            }
            break;
        case 3:
            if (!r->u.f.b31) {
                if (DAT_a807d5c6 == 0xff || DAT_a807d5c6 == i)
                    r->u.f.b31 = FUN_a00c2758(i);
                r->u.f.b30 = 0;
            }
            if (r->u.f.b31 && !r->u.f.b30) {
                if (func_0xa0fb657c(i, 0x318) & 8) {
                    func_0xa0fb65c4(i, 0x318, 8);
                    func_0xa0fb67b8(i, 0x308, 4, 1);
                    r->u.f.b30 = 1;
                }
            }
            if (r->u.w & 0x40000000) {
                if (!(func_0xa0fb657c(i, 0x30a) & 0x70)) {
                    func_0xa0fb65c4(i, 0x318, 0x10);
                    func_0xa0fb67b8(i, 0x308, 8, 1);
                    r->bd = 5;
                }
            }
            break;
        case 4:
            if (func_0xa0fb657c(i, 0x318) & 8) {
                func_0xa0fb65c4(i, 0x318, 8);
                func_0xa0fb67b8(i, 0x308, 4, 1);
                r->bd = 5;
            }
            break;
        case 7:
            if (func_0xa0fb657c(i, 0x318) & 0x80) {
                func_0xa0fb65c4(i, 0x318, 0x80);
                r->bd = 8;
            }
            break;
        case 8:
            if (func_0xa0fb657c(i, 0x319) & 1) {
                func_0xa0fb65c4(i, 0x319, 1);
                r->u.f.f16 = 1;
                if ((DAT_a8078c58 >> i) & 1) {
                    r->bd = 9;
                    DAT_a8078cb0 = 0;
                } else {
                    r->bd = 0xd;
                    func_0xa0f83044(s_9f1b7598, i);
                }
            }
            break;
        case 9:
            if (sel != 2) {
                FUN_a00c76c0(sel, 4, 0x10, 0);
                FUN_a00c76c0(sel, 0xf, 1, 0);
            } else {
                REG_8D00 &= ~2;
            }
            if (r->u.w & 0x400000) {
                func_0xa0fb67b8(i, 0x308, 0x20, 0);
                func_0xa0fb67b8(i, 0x308, 0x20, 1);
                func_0xa0fb67b8(i, 0x308, 0x20, 0);
            }
            r->bd = 0xa;
            break;
        case 0xa:
        case 0xd:
            if (FUN_a00c2de4(i) || (func_0xa0fb657c(i, 0x303) & 8)) {
                func_0xa0fb67b8(i, 0x303, 8, 1);
                break;
            }
            if ((func_0xa0fb657c(i, 0x31a) & 1) && DAT_a8078cb0 == 0) {
                func_0xa0fb65c4(i, 0x31a, 1);
                func_0xa0fb67b8(i, 0x303, 4, 1);
                func_0xa0fb67b8(i, 0x308, 0x40, 1);
            }
            if (func_0xa0fb657c(i, 0x31a) & 2) {
                func_0xa0fb65c4(i, 0x31a, 2);
                func_0xa0fb67b8(i, 0x303, 4, 0);
            }
            if (func_0xa0fb657c(i, 0x31a) & 4)
                func_0xa0fb65c4(i, 0x31a, 4);
            if (func_0xa0fb657c(i, 0x31a) & 0x40) {
                func_0xa0fb65c4(i, 0x31a, 0x40);
                DAT_a8078cb0 = 1;
            }
            func_0xa0fb657c(i, 0x31a);
            if (func_0xa0fb657c(i, 0x31a) & 0x20) {
                func_0xa0fb65c4(i, 0x31a, 0x38);
                func_0xa0fb67b8(i, 0x308, 0x80, 1);
            }
            if (func_0xa0fb657c(i, 0x319) & 0x80) {
                func_0xa0fb65c4(i, 0x319, 0x80);
                DAT_a8078cb0 = 0;
            }
            break;
        }
        FUN_a00c3144(i);
    }
}
