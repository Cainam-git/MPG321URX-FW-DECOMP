/* FUN_a00c3ae8 (leon2s 0xa00c3ae8-0xa00c44ac, 2500 bytes), flags -mcpu=v8 -Os -g.
 * void. The same state machine as FUN_a00c32f4 for the records DAT_a807d5e8[i] (i = 0, 1; record and port
 * index i + 2 for FUN_a00c2758, FUN_a00c3144, DAT_a807d629 and bit i + 2 of DAT_a8078c58). Registers are read
 * with func_0xa0fb69b4(i, reg) (low byte) and written with func_0xa0fb69fc(i, reg, v); most steps write
 * through the window registers 0xa6 / 0xa4 / 0xa5 / 0xa7. Returns when bits 24..26 of word 0 are not 5. Bit 0
 * of 0xa8 clears bytes +0xd and +0xc; sel = 0 / 1 / 2 by the lowest set bit 0 / 1 / 2 of byte +4.
 * By the state (switch with jump table 0xa00c3ab0, linked at 0x9f1b3ab0):
 * 0, 1: on bit 0 of 0xa8: FUN_a00c224c(DAT_a8078620), window 0xa / 2 with indices 0xa..0x11 = DAT_a8078620[],
 *   window 8 / 0 with indices 0, 1 = 0, 0x60 to 0xa9, waits up to 3000 reads for bit 6 of 0xa9, window writes
 *   (1/0/1, func_0xa0fb6aa0(i, 0xa7, 5, 1); 9/0/0, 2), 0xff to 0xa8, 0x10 to 0xa9, state 2; sel other than 2:
 *   FUN_a00c76c0(sel, 4, 0x10, 0) and func_0xa0fb80cc(sel, 0, 0xf, 1, 0); clears bit 23.
 * 2: bit 1 of 0xa8: acknowledged, state 3, bits 31 and 30 cleared; else bit 2: acknowledged, state 4.
 * 3: bit 31 clear: bit 31 = FUN_a00c2758(i + 2) when DAT_a807d629 is 0xff or i + 2; bit 30 cleared. Bit 31 set
 *   and bit 30 clear: on bit 3 of 0xa8, acknowledged, window 9/0/0 = 4, 0x20 to 0xa4, bit 30 set. Bit 30 set:
 *   window 9 / 0x20 / 2; when bits 2..4 of 0xa7 are clear: 0x10 to 0xa8, window 0/0 = 8, 0x20 to 0xa4, state 5.
 * 4: bit 3 of 0xa8: acknowledged, window 9/0/0 = 4, 0x20 to 0xa4, state 5. 7: bit 7 of 0xa8: state 8.
 * 8: bit 0 of 0xa9: acknowledged, bits 16..20 = 1; bit i + 2 of DAT_a8078c58 set: state 9 and DAT_a8078cb0 = 0,
 *   else state 0xd and func_0xa0f83044(s_9f1b75b8, i).
 * 9: the sel step of state 0/1; bit 22 set: window 9/0/0 = 0, 0x20, 0, 0x20 to 0xa4, state 0xa.
 * 0xa, 0xd: FUN_a00c2f58(i) nonzero: func_0xa0f83044(s_9f1b75d8, i), window 0 / 1 / 8 = 8. Otherwise handles
 *   bits 0, 1, 2, 6, 5 of 0xaa and bit 7 (window writes, DAT_a8078cb0 = 1 / 0; bit 0 only while DAT_a8078cb0
 *   is 0; one extra read of 0xaa before the bit-5 test).
 * Then FUN_a00c3144(i + 2).
 * Source forms: as FUN_a00c32f4 (union word / bit-field view, state byte written before the two bit clears in
 * state 2, unsigned char result of the register read).
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
extern struct rec16 DAT_a807d5e8[];
extern unsigned char DAT_a807d629;
extern unsigned char DAT_a8078c58;
extern unsigned char DAT_a8078cb0;
extern unsigned char DAT_a8078620[];
extern const char s_9f1b75b8[];
extern const char s_9f1b75d8[];
extern int func_0xa0f83044(const char *, ...);
extern unsigned char func_0xa0fb69b4(unsigned char, unsigned short);
extern void func_0xa0fb69fc(unsigned char, unsigned short, unsigned char);
extern void func_0xa0fb6aa0(unsigned char, unsigned short, unsigned char, unsigned char);
extern void func_0xa0fb80cc(unsigned char, int, int, int, int);
extern void FUN_a00c76c0(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00c224c(unsigned char *);
extern unsigned char FUN_a00c2758(unsigned char);
extern unsigned char FUN_a00c2f58(unsigned char);
extern void FUN_a00c3144(unsigned char);

void FUN_a00c3ae8(void)
{
    unsigned char sel = 0;
    unsigned char i;
    unsigned char n;
    unsigned short k;
    struct rec16 *r;

    for (i = 0; i < 2; i++) {
        r = &DAT_a807d5e8[i];
        if ((r->u.w & 0x7000000) != 0x5000000)
            return;
        if (func_0xa0fb69b4(i, 0xa8) & 1) {
            r->bd = 0;
            r->bc = 0;
        }
        if (r->b4 & 1)
            sel = 0;
        else if (r->b4 & 2)
            sel = 1;
        else if (r->b4 & 4)
            sel = 2;
        switch (r->bd) {
        case 0:
        case 1:
            if (func_0xa0fb69b4(i, 0xa8) & 1) {
                FUN_a00c224c(DAT_a8078620);
                func_0xa0fb69fc(i, 0xa6, 0xa);
                func_0xa0fb69fc(i, 0xa4, 2);
                k = 0;
                for (n = 0; n < 8; n++) {
                    func_0xa0fb69fc(i, 0xa5, n + 0xa);
                    func_0xa0fb69fc(i, 0xa7, DAT_a8078620[n]);
                }
                func_0xa0fb69fc(i, 0xa6, 8);
                func_0xa0fb69fc(i, 0xa4, 0);
                for (n = 0; n < 2; n++) {
                    func_0xa0fb69fc(i, 0xa5, n);
                    func_0xa0fb69fc(i, 0xa7, 0);
                }
                func_0xa0fb69fc(i, 0xa9, 0x60);
                while (!(func_0xa0fb69b4(i, 0xa9) & 0x40) && k < 3000)
                    k++;
                func_0xa0fb69fc(i, 0xa6, 1);
                func_0xa0fb69fc(i, 0xa4, 0);
                func_0xa0fb69fc(i, 0xa5, 1);
                func_0xa0fb6aa0(i, 0xa7, 5, 1);
                func_0xa0fb69fc(i, 0xa6, 9);
                func_0xa0fb69fc(i, 0xa4, 0);
                func_0xa0fb69fc(i, 0xa5, 0);
                func_0xa0fb69fc(i, 0xa7, 2);
                func_0xa0fb69fc(i, 0xa8, 0xff);
                func_0xa0fb69fc(i, 0xa9, 0x10);
                r->bd = 2;
                if (sel != 2) {
                    FUN_a00c76c0(sel, 4, 0x10, 0);
                    func_0xa0fb80cc(sel, 0, 0xf, 1, 0);
                }
                r->u.f.b23 = 0;
            }
            break;
        case 2:
            if (func_0xa0fb69b4(i, 0xa8) & 2) {
                func_0xa0fb69fc(i, 0xa8, 2);
                r->bd = 3;
                r->u.f.b31 = 0;
                r->u.f.b30 = 0;
            } else if (func_0xa0fb69b4(i, 0xa8) & 4) {
                func_0xa0fb69fc(i, 0xa8, 4);
                r->bd = 4;
            }
            break;
        case 3:
            if (!r->u.f.b31) {
                if (DAT_a807d629 == 0xff || DAT_a807d629 == i + 2)
                    r->u.f.b31 = FUN_a00c2758(i + 2);
                r->u.f.b30 = 0;
            }
            if (r->u.f.b31 && !r->u.f.b30) {
                if (func_0xa0fb69b4(i, 0xa8) & 8) {
                    func_0xa0fb69fc(i, 0xa8, 8);
                    func_0xa0fb69fc(i, 0xa6, 9);
                    func_0xa0fb69fc(i, 0xa4, 0);
                    func_0xa0fb69fc(i, 0xa5, 0);
                    func_0xa0fb69fc(i, 0xa7, 4);
                    func_0xa0fb69fc(i, 0xa4, 0x20);
                    r->u.f.b30 = 1;
                }
            }
            if (r->u.w & 0x40000000) {
                func_0xa0fb69fc(i, 0xa6, 9);
                func_0xa0fb69fc(i, 0xa4, 0x20);
                func_0xa0fb69fc(i, 0xa5, 2);
                if (!(func_0xa0fb69b4(i, 0xa7) & 0x1c)) {
                    func_0xa0fb69fc(i, 0xa8, 0x10);
                    func_0xa0fb69fc(i, 0xa4, 0);
                    func_0xa0fb69fc(i, 0xa5, 0);
                    func_0xa0fb69fc(i, 0xa7, 8);
                    func_0xa0fb69fc(i, 0xa4, 0x20);
                    r->bd = 5;
                }
            }
            break;
        case 4:
            if (func_0xa0fb69b4(i, 0xa8) & 8) {
                func_0xa0fb69fc(i, 0xa8, 8);
                func_0xa0fb69fc(i, 0xa6, 9);
                func_0xa0fb69fc(i, 0xa4, 0);
                func_0xa0fb69fc(i, 0xa5, 0);
                func_0xa0fb69fc(i, 0xa7, 4);
                func_0xa0fb69fc(i, 0xa4, 0x20);
                r->bd = 5;
            }
            break;
        case 7:
            if (func_0xa0fb69b4(i, 0xa8) & 0x80) {
                func_0xa0fb69fc(i, 0xa8, 0x80);
                r->bd = 8;
            }
            break;
        case 8:
            if (func_0xa0fb69b4(i, 0xa9) & 1) {
                func_0xa0fb69fc(i, 0xa9, 1);
                r->u.f.f16 = 1;
                if ((DAT_a8078c58 >> (i + 2)) & 1) {
                    r->bd = 9;
                    DAT_a8078cb0 = 0;
                } else {
                    r->bd = 0xd;
                    func_0xa0f83044(s_9f1b75b8, i);
                }
            }
            break;
        case 9:
            if (sel != 2) {
                FUN_a00c76c0(sel, 4, 0x10, 0);
                func_0xa0fb80cc(sel, 0, 0xf, 1, 0);
            }
            if (r->u.w & 0x400000) {
                func_0xa0fb69fc(i, 0xa6, 9);
                func_0xa0fb69fc(i, 0xa4, 0);
                func_0xa0fb69fc(i, 0xa5, 0);
                func_0xa0fb69fc(i, 0xa7, 0);
                func_0xa0fb69fc(i, 0xa7, 0x20);
                func_0xa0fb69fc(i, 0xa7, 0);
                func_0xa0fb69fc(i, 0xa4, 0x20);
                r->bd = 0xa;
            }
            break;
        case 0xa:
        case 0xd:
            if (FUN_a00c2f58(i)) {
                func_0xa0f83044(s_9f1b75d8, i);
                func_0xa0fb69fc(i, 0xa4, 0);
                func_0xa0fb69fc(i, 0xa5, 1);
                func_0xa0fb69fc(i, 0xa6, 8);
                func_0xa0fb69fc(i, 0xa7, 8);
                break;
            }
            if ((func_0xa0fb69b4(i, 0xaa) & 1) && DAT_a8078cb0 == 0) {
                func_0xa0fb69fc(i, 0xaa, 1);
                func_0xa0fb69fc(i, 0xa6, 8);
                func_0xa0fb69fc(i, 0xa4, 0);
                func_0xa0fb69fc(i, 0xa5, 1);
                func_0xa0fb69fc(i, 0xa7, 4);
                func_0xa0fb69fc(i, 0xa4, 0x20);
                func_0xa0fb69fc(i, 0xa6, 9);
                func_0xa0fb69fc(i, 0xa4, 0);
                func_0xa0fb69fc(i, 0xa5, 0);
                func_0xa0fb69fc(i, 0xa7, 0x40);
                func_0xa0fb69fc(i, 0xa4, 0x20);
            }
            if (func_0xa0fb69b4(i, 0xaa) & 2) {
                func_0xa0fb69fc(i, 0xaa, 2);
                func_0xa0fb69fc(i, 0xa6, 8);
                func_0xa0fb69fc(i, 0xa4, 0);
                func_0xa0fb69fc(i, 0xa5, 1);
                func_0xa0fb69fc(i, 0xa7, 0);
                func_0xa0fb69fc(i, 0xa4, 0x20);
            }
            if (func_0xa0fb69b4(i, 0xaa) & 4)
                func_0xa0fb69fc(i, 0xaa, 4);
            if (func_0xa0fb69b4(i, 0xaa) & 0x40) {
                func_0xa0fb69fc(i, 0xaa, 0x40);
                DAT_a8078cb0 = 1;
            }
            func_0xa0fb69b4(i, 0xaa);
            if (func_0xa0fb69b4(i, 0xaa) & 0x20) {
                func_0xa0fb69fc(i, 0xaa, 0x38);
                func_0xa0fb69fc(i, 0xa6, 9);
                func_0xa0fb69fc(i, 0xa4, 0);
                func_0xa0fb69fc(i, 0xa5, 0);
                func_0xa0fb69fc(i, 0xa7, 0x80);
                func_0xa0fb69fc(i, 0xa4, 0x20);
            }
            if (func_0xa0fb69b4(i, 0xaa) & 0x80) {
                func_0xa0fb69fc(i, 0xaa, 0x80);
                DAT_a8078cb0 = 0;
            }
            break;
        }
        FUN_a00c3144(i + 2);
    }
}
