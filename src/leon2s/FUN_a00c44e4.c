/* FUN_a00c44e4 (leon2s 0xa00c44e4-0xa00c4e4c, 2408 bytes), flags -mcpu=v8 -Os -g.
 * void. The same state machine as FUN_a00c32f4 / FUN_a00c3ae8 for the 16-byte records DAT_a807d608[i]
 * (i = 0, 1; record and port index i + 4 for FUN_a00c2758, FUN_a00c3144, DAT_a807d62b and bit i + 4 of
 * DAT_a8078c58). Registers are read with func_0xa0fb6bb8(i, reg) and written with func_0xa0fb6c00(i, reg, v)
 * and func_0xa0fb6c98(i, reg, mask, on). Returns when bits 24..26 of word 0 are not 5. Bit 0 of 0x408 clears
 * bytes +0xd and +0xc. By the state byte +0xd (switch with jump table 0xa00c44ac, linked at 0x9f1b44ac):
 * 0, 1: on bit 0 of 0x408: clears bit 22 and f[4], FUN_a00c224c(DAT_a8078610), 3 to 0x400, 0 to 0x403, the
 *   8 bytes DAT_a8078610[] to 0x401, 1 to 0x408, 7 then 1 to 0x404 around func_0xa0fc160c(1), state 2,
 *   clears bit 23.
 * 2: bit 2 of 0x408: 6 to 0x408, state 3, bits 31 and 30 cleared; else bit 3: 0xa to 0x408, state 4.
 * 3: bit 31 clear: bit 31 = FUN_a00c2758(i + 4) when DAT_a807d62b is 0xff or i + 4; bit 30 cleared. Bit 31
 *   set and bit 30 clear: on bit 4 of 0x408, acknowledged, bit 30 set, state 6. Bit 30 set: on bit 5 of
 *   0x408, acknowledged, state 6.
 * 4: bit 4 of 0x408: acknowledged, state 6. 5, 6: bit 6 of 0x408: acknowledged, state 7. 7: bit 7 of 0x408:
 *   acknowledged, state 8.
 * 8: bit 0 of 0x409: acknowledged; bit i + 4 of DAT_a8078c58 set: state 9, else bit 23 set, state 0xd and
 *   func_0xa0f83044(s_9f1b75f0, i).
 * 9: bit 22 set and f[4] clear: mask 0x10 of 0x405 written 0, 1, 0; state 0xa.
 * 0xa, 0xd: bits 1, 2, 6, 3 and 4 of 0x409 (bit 6: state 1; bit 3: f[4] = 1, a read sequence over 0x401
 *   into b[0..2], byte 3 of word 0 and bit 21, written back through 0x403 / 0x401; bit 4: f[4] = 0).
 * Then FUN_a00c3144(i + 4).
 * Source forms: word 0 is a union of the word, a bit-field view and its bytes; the record pointer is built
 * in a block-local pointer (t = DAT_a807d608; t += i; r = t;), which keeps the first load of each pass as
 * ld [r] instead of a register-plus-register address.
 */
struct bits {
    unsigned int b31 : 1;
    unsigned int b30 : 1;
    unsigned int _29 : 6;
    unsigned int b23 : 1;
    unsigned int b22 : 1;
    unsigned int b21 : 1;
    unsigned int _0 : 21;
};
struct rec16 {
    union { unsigned int w; struct bits f; unsigned char b[4]; } u;
    unsigned char _4[0xc - 4];
    unsigned char bc;
    unsigned char bd;
    unsigned char _e[2];
};
extern struct rec16 DAT_a807d608[];
extern unsigned char DAT_a807d62b;
extern unsigned char DAT_a8078c58;
extern unsigned char DAT_a8078610[];
extern const char s_9f1b75f0[];
extern int func_0xa0f83044(const char *, ...);
extern unsigned int func_0xa0fb6bb8(unsigned char, unsigned short);
extern void func_0xa0fb6c00(unsigned char, unsigned short, unsigned char);
extern void func_0xa0fb6c98(unsigned char, unsigned short, unsigned char, unsigned char);
extern void func_0xa0fc160c(unsigned int);
extern void FUN_a00c224c(unsigned char *);
extern unsigned char FUN_a00c2758(unsigned char);
extern void FUN_a00c3144(unsigned char);

void FUN_a00c44e4(void)
{
    unsigned char f[5] = { 0 };
    unsigned char b[3] = { 0 };
    unsigned char i;
    unsigned int t, k;
    unsigned short n;
    struct rec16 *r;

    for (i = 0; i < 2; i++) {
        {
            struct rec16 *t = DAT_a807d608;

            t += i;
            r = t;
        }
        if ((r->u.w & 0x7000000) != 0x5000000)
            return;
        if (func_0xa0fb6bb8(i, 0x408) & 1) {
            r->bd = 0;
            r->bc = 0;
        }
        switch (r->bd) {
        case 0:
        case 1:
            if (func_0xa0fb6bb8(i, 0x408) & 1) {
                r->u.f.b22 = 0;
                f[4] = 0;
                FUN_a00c224c(DAT_a8078610);
                func_0xa0fb6c98(i, 0, 0x20, 0);
                func_0xa0fb6c00(i, 0x400, 3);
                func_0xa0fb6c98(i, 0x402, 0x80, 1);
                func_0xa0fb6c00(i, 0x403, 0);
                for (n = 0; n < 8; n++)
                    func_0xa0fb6c00(i, 0x401, DAT_a8078610[n]);
                func_0xa0fb6c00(i, 0x408, 1);
                func_0xa0fb6c00(i, 0x404, 7);
                func_0xa0fc160c(1);
                func_0xa0fb6c00(i, 0x404, 1);
                r->bd = 2;
                func_0xa0fb6c98(i, 0, 0x20, 0);
                r->u.f.b23 = 0;
            }
            break;
        case 2:
            if (func_0xa0fb6bb8(i, 0x408) & 4) {
                func_0xa0fb6c00(i, 0x408, 6);
                r->bd = 3;
                r->u.f.b31 = 0;
                r->u.f.b30 = 0;
            } else if (func_0xa0fb6bb8(i, 0x408) & 8) {
                func_0xa0fb6c00(i, 0x408, 0xa);
                r->bd = 4;
            }
            break;
        case 3:
            if (!r->u.f.b31) {
                if (DAT_a807d62b == 0xff || DAT_a807d62b == i + 4)
                    r->u.f.b31 = FUN_a00c2758(i + 4);
                r->u.f.b30 = 0;
            }
            if (r->u.f.b31 && !r->u.f.b30) {
                if (func_0xa0fb6bb8(i, 0x408) & 0x10) {
                    func_0xa0fb6c00(i, 0x408, 0x10);
                    r->u.f.b30 = 1;
                    r->bd = 6;
                }
            }
            if (r->u.w & 0x40000000) {
                if (func_0xa0fb6bb8(i, 0x408) & 0x20) {
                    func_0xa0fb6c00(i, 0x408, 0x20);
                    r->bd = 6;
                    func_0xa0fb6c98(i, 0, 0x20, 0);
                }
            }
            break;
        case 4:
            if (func_0xa0fb6bb8(i, 0x408) & 0x10) {
                func_0xa0fb6c00(i, 0x408, 0x10);
                r->bd = 6;
                func_0xa0fb6c98(i, 0, 0x20, 0);
            }
            break;
        case 5:
        case 6:
            if (func_0xa0fb6bb8(i, 0x408) & 0x40) {
                func_0xa0fb6c98(i, 0, 0x20, 0);
                func_0xa0fb6c00(i, 0x408, 0x40);
                r->bd = 7;
            }
            break;
        case 7:
            if (func_0xa0fb6bb8(i, 0x408) & 0x80) {
                func_0xa0fb6c00(i, 0x408, 0x80);
                r->bd = 8;
            }
            break;
        case 8:
            if (func_0xa0fb6bb8(i, 0x409) & 1) {
                func_0xa0fb6c00(i, 0x409, 1);
                if ((DAT_a8078c58 >> (i + 4)) & 1) {
                    r->bd = 9;
                } else {
                    r->u.f.b23 = 1;
                    r->bd = 0xd;
                    func_0xa0f83044(s_9f1b75f0, i);
                }
            }
            break;
        case 9:
            if ((r->u.w & 0x400000) && f[4] == 0) {
                func_0xa0fb6c98(i, 0, 0x20, 0);
                func_0xa0fb6c98(i, 0x405, 0x10, 0);
                func_0xa0fb6c98(i, 0x405, 0x10, 1);
                func_0xa0fb6c98(i, 0x405, 0x10, 0);
                r->bd = 0xa;
            }
            break;
        case 0xa:
        case 0xd:
            if (func_0xa0fb6bb8(i, 0x409) & 2)
                func_0xa0fb6c00(i, 0x409, 2);
            if (func_0xa0fb6bb8(i, 0x409) & 4)
                func_0xa0fb6c00(i, 0x409, 4);
            if (func_0xa0fb6bb8(i, 0x409) & 0x40) {
                func_0xa0fb6c00(i, 0x409, 0x40);
                func_0xa0fb6c98(i, 0x40e, 0x80, 1);
                r->bd = 1;
            }
            if (func_0xa0fb6bb8(i, 0x409) & 8) {
                func_0xa0fb6c00(i, 0x409, 8);
                f[4] = 1;
                func_0xa0fb6c00(i, 0x406, 0x90);
                while (func_0xa0fb6bb8(i, 0x406) & 0x80)
                    ;
                func_0xa0fb6c00(i, 0x400, 0xd);
                func_0xa0fb6c00(i, 0x402, 0x80);
                func_0xa0fb6c00(i, 0x403, 0);
                b[0] = func_0xa0fb6bb8(i, 0x401);
                b[1] = func_0xa0fb6bb8(i, 0x401);
                b[2] = func_0xa0fb6bb8(i, 0x401);
                func_0xa0fb6bb8(i, 0x401);
                t = func_0xa0fb6bb8(i, 0x401);
                r->u.b[3] = t;
                k = t * 2;
                r->u.f.b21 = func_0xa0fb6bb8(i, 0x401);
                r->u.f.b21 = func_0xa0fb6bb8(i, 0x401);
                func_0xa0fb6c98(i, 0x40e, 0x20, 1);
                while (func_0xa0fb6bb8(i, 0x40e) & 0x20)
                    ;
                func_0xa0fb6c00(i, 0x402, 0x90);
                func_0xa0fb6c00(i, 0x403, 0);
                func_0xa0fb6c00(i, 0x401, b[0]);
                func_0xa0fb6c00(i, 0x403, 1);
                func_0xa0fb6c00(i, 0x401, b[1]);
                func_0xa0fb6c00(i, 0x403, 2);
                func_0xa0fb6c00(i, 0x401, b[2]);
                func_0xa0fb6c00(i, 0x403, 4);
                func_0xa0fb6c00(i, 0x401, r->u.b[3]);
                func_0xa0fb6c00(i, 0x403, 6);
                func_0xa0fb6c00(i, 0x401, r->u.f.b21);
                func_0xa0fb6c00(i, 0x403, k + 5);
                func_0xa0fb6c00(i, 0x401, b[0]);
                func_0xa0fb6c00(i, 0x403, k + 6);
                func_0xa0fb6c00(i, 0x401, b[1]);
                func_0xa0fb6c00(i, 0x403, k + 7);
                func_0xa0fb6c00(i, 0x401, b[2]);
                func_0xa0fb6c00(i, 0x403, k + 8);
                func_0xa0fb6c00(i, 0x401, 0x80);
                func_0xa0fb6c00(i, 0x402, 0);
                func_0xa0fb6c98(i, 0x405, 1, 1);
                func_0xa0fb6c00(i, 0x40a, 1);
                func_0xa0fb6c98(i, 0x405, 0x20, 1);
                func_0xa0fb6c98(i, 0x405, 0x20, 0);
                r->u.f.b23 = 1;
                func_0xa0fb6c00(i, 0x400, 0x12);
                func_0xa0fb6c00(i, 0x402, 0x90);
                func_0xa0fb6c00(i, 0x403, 8);
                func_0xa0fb6c00(i, 0x401, r->u.f.b21);
                func_0xa0fb6c00(i, 0x403, 9);
                func_0xa0fb6c00(i, 0x401, r->u.f.b21);
                func_0xa0fb6c00(i, 0x403, 0xa);
                func_0xa0fb6c00(i, 0x401, r->u.f.b21);
                func_0xa0fb6c00(i, 0x400, 0);
            }
            if (func_0xa0fb6bb8(i, 0x409) & 0x10) {
                func_0xa0fb6c00(i, 0x409, 0x10);
                f[4] = 0;
            }
            break;
        }
        FUN_a00c3144(i + 4);
    }
}
