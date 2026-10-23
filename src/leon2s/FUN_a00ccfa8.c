/*
 * FUN_a00ccfa8 (leon2s, 0xa00ccfa8-0xa00cd2f0, 840 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Works on the 24-byte record DAT_a8078bb0[port] (bit-fields as in FUN_a00c91f8: f28,
 * st = bits 16..17). Sets st = 1; reads byte h with func_0xa0f96400(0, 0x90, 0x68028, 0, &h): a zero
 * result sets st = 3, bit 0 of h clear sets st = 0 (both return). Bit 1 of h: f28 = 1 and bit 0 of
 * register 0xcf018d54 set, else both cleared; b[0] = that bit, written back with
 * func_0xa0f963d4(0, 0x80, 0x6803b, 0, b); prints s_9f1c2180.
 * For i = 0..4: up to four reads of byte 0x68000 + i into b[i] until one returns non-zero; b[i] is
 * written to the register word 0xcf000000 | ((0x6350 + i) << 2) and the read-back low halfword is printed
 * (s_9f1cca30). The set bits of b[0..4] are counted; a count other than 20 sets st = 0.
 * Otherwise sets bit 5 of register 0xcf018d00 and waits until it reads 0, calling func_0xa0fc1794(1)
 * between reads; after 101 delays st = 0. When it clears: b[0..7] = low bytes of the register words
 * 0x6341..0x6348, func_0xa0f963d4(0, 0x80, 0x6800c, 7, b); b[0..4] = register words 0x6349..0x634d,
 * func_0xa0f963d4(0, 0x80, 0x68007, 4, b).
 * Source forms: the retry loop is 'do { ...; if (v) break; } while (--j != 0xff);'; two u8 counters
 * i and j are shared by the loops; the wait loop leaves through 'goto fail' to the st = 0 block of the
 * count test (firmware block order).
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
extern struct Rec24 DAT_a8078bb0[];
extern const char s_9f1c2180[];
extern const char s_9f1cca30[];
extern unsigned char func_0xa0f96400(int, int, int, int, unsigned char *);
extern int func_0xa0f963d4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern int func_0xa0f83044(const char *, ...);
extern void func_0xa0fc1794(unsigned int);

#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00ccfa8(unsigned char port)
{
    unsigned char b[8];
    unsigned char h;
    unsigned char i;
    unsigned char j;
    unsigned char v;
    unsigned char cnt;

    DAT_a8078bb0[port].st = 1;
    if (func_0xa0f96400(0, 0x90, 0x68028, 0, &h) == 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    if ((h & 1) == 0) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    if (h & 2) {
        DAT_a8078bb0[port].f28 = 1;
        R(0xcf018d54) |= 1;
        b[0] = 1;
        func_0xa0f963d4(0, 0x80, 0x6803b, 0, b);
    } else {
        DAT_a8078bb0[port].f28 = 0;
        R(0xcf018d54) &= ~1;
        b[0] = 0;
        func_0xa0f963d4(0, 0x80, 0x6803b, 0, b);
    }
    func_0xa0f83044(s_9f1c2180);
    for (i = 0; i < 5; i++) {
        j = 3;
        do {
            v = func_0xa0f96400(0, 0x90, 0x68000 + i, 0, &b[i]);
            if (v)
                break;
        } while (--j != 0xff);
        R(0xcf000000 | ((i + 0x6350) << 2)) = b[i];
        func_0xa0f83044(s_9f1cca30, (unsigned short)R(0xcf000000 | ((i + 0x6350) << 2)));
    }
    cnt = 0;
    for (j = 0; j < 5; j++) {
        v = b[j];
        for (i = 0; i < 8; i++) {
            if (v & 1)
                cnt++;
            v >>= 1;
        }
    }
    if (cnt != 0x14) {
fail:
        DAT_a8078bb0[port].st = 0;
        return;
    }
    R(0xcf018d00) |= 0x20;
    j = 0;
    while (R(0xcf018d00) & 0x20) {
        func_0xa0fc1794(1);
        j++;
        if (j > 0x64)
            goto fail;
    }
    for (j = 0; j < 8; j++)
        b[j] = R(0xcf000000 | ((j + 0x6341) << 2));
    func_0xa0f963d4(0, 0x80, 0x6800c, 7, b);
    for (j = 0; j < 5; j++)
        b[j] = R(0xcf000000 | ((j + 0x6349) << 2));
    func_0xa0f963d4(0, 0x80, 0x68007, 4, b);
}
