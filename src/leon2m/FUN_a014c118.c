/* leon2m FUN_a014c118 @ 0xa014c118-0xa014c778 (408 words), flags -mcpu=v8 -O3 -g. Callers include FUN_a014c778,
 * FUN_a014c794 and FUN_a014c7bc.
 * Selects three values v0, v1, v2 (0xff at the start) for the byte p and ends with FUN_a013b4a4(v0 + 1, v1 + 1,
 * v2 + 1) unless a path below clears the call flag. A 3-byte local buffer buf is cleared at the start.
 * When FUN_a012f134(byte 0xa802e3e8) is nonzero and (u8)(p - 15) <= 7: FUN_a010af98() is tested, then
 * FUN_a010b160(); when either returns 0, FUN_a010afc8(), FUN_a010b198(), FUN_a010afe4(0), FUN_a010b1b4(0),
 * FUN_a010afac() and FUN_a010b17c() run. Otherwise FUN_a010afc8() and FUN_a010b198() run. When (u8)(p - 15) <= 7,
 * the halfword 0xa802e3ea = (u8)FUN_a012e8c0(p). Then a switch on p (jump table 0xa0143534, 23 entries), with
 * T = the byte table at 0xa802e1f0:
 *  - 1, 4, 7: when FUN_a012f134(byte 0xa802e3e8) and FUN_a012e550(1 << (that byte & 0xf), 2 / 0x10 / 0x80, buf)
 *    are both nonzero, the values are buf[0..2]; otherwise T[6..8] / T[9..0xb] / T[0x12..0x14], first set to
 *    0xff, 0xe8, 0xbd / 0xff, 0xff, 0xff / 0xd1, 0xd6, 0xff when T[6] <= 0x7e, T[7] <= 0x73, T[8] is 0 or T[8] is
 *    0xff / any of the three is <= 0x7e / T[0x12] <= 0x67, T[0x13] <= 0x6a or T[0x14] <= 0x7e.
 *  - 5, 6, 8: T[0xc..0xe], T[0xf..0x11], T[0x15..0x17], first set to 0xf8, 0xff, 0xff / 0xf8, 0xf8, 0xff /
 *    0xf0, 0xf0, 0xff when T[0xc] <= 0x7b, T[0xd] or T[0xe] <= 0x7e / T[0xf] or T[0x10] <= 0x7b, T[0x11] <= 0x7e /
 *    T[0x15] or T[0x16] <= 0x77, T[0x17] <= 0x7e.
 *  - 9: FUN_a010afac(), FUN_a010b17c(), call flag cleared. 10, 11: T[0x1b..0x1d], T[0x1e..0x20].
 *  - 15 to 22: when FUN_a012f134(byte 0xa802e3e8) is nonzero, FUN_a012e6c0(halfword 0xa802e3ea) and the call flag
 *    is cleared; otherwise 0xff, for p = 15 T[0x21..0x23].
 *  - 0, 2, 3, 12, 13, 14: 0xff. Above 22: (x * 200 + 50) / 100 + 0x37 (unsigned) of the bytes x at 0xa802e3dc,
 *    0xa802e3dd, 0xa802e3de.
 * The same computation from 0xa802e3dc..de replaces the values when FUN_a0140058(bits 12..15 of word 0xa802df30) is
 * 1 or bit 6 is set in the first halfword of entry (bits 12..15) of the 42-byte records at 0xa802e224.
 * Source form: K&R definition (the unsigned char p is extended at each use); each 0xff case written on its own;
 * case blocks in the order 12, 14, 2, 9, 0, 1, 4, 5, 6, 7, 3, 13, 8, 10, 11, 15..22, default (this order gives the
 * register choices); the T stores in the order written.
 * Compiler aids: __builtin_expect(FUN_a012f134(..) != 0, 0) in cases 1, 4 and 7 and 'do continue; while (0);' in
 * the branch that keeps the values emit no instructions; they set branch predictions that place the blocks as in
 * the firmware.
 */
struct S3d0 {
    unsigned char pad0[0xc];
    unsigned char c;
    unsigned char d;
    unsigned char e;
    unsigned char pad0f[0x18 - 0xf];
    unsigned char b18;
    unsigned char pad19;
    unsigned short h1a;
};
struct T224 {
    unsigned short h0;
    unsigned char pad[0x28];
};
extern struct S3d0 DAT_a802e3d0;
extern unsigned char DAT_a802e1f0[];
extern struct T224 DAT_a802e224[];
extern unsigned int DAT_a802df30;
extern unsigned char FUN_a012f134(unsigned char);
extern unsigned char FUN_a012e550(unsigned short, unsigned short, unsigned char *);
extern unsigned char FUN_a010af98(void);
extern unsigned char FUN_a010b160(void);
extern void FUN_a010afc8(void);
extern void FUN_a010b198(void);
extern void FUN_a010afe4(unsigned char *);
extern void FUN_a010b1b4(unsigned char *);
extern void FUN_a010afac(void);
extern void FUN_a010b17c(void);
extern unsigned char FUN_a012e8c0(unsigned char);
extern void FUN_a012e6c0(unsigned short);
extern unsigned char FUN_a0140058(unsigned char);
extern void FUN_a013b4a4(unsigned short, unsigned short, unsigned short);

void FUN_a014c118(p)
    unsigned char p;
{
    unsigned char buf[3] = {0, 0, 0};
    unsigned int v0, v1, v2;
    unsigned char set;

    v0 = 0xff;
    v1 = 0xff;
    v2 = 0xff;
    set = 1;
    if (FUN_a012f134(DAT_a802e3d0.b18) != 0 && (unsigned char)(p - 15) <= 7) {
        if (FUN_a010af98() == 0 || FUN_a010b160() == 0) {
            FUN_a010afc8();
            FUN_a010b198();
            FUN_a010afe4(0);
            FUN_a010b1b4(0);
            FUN_a010afac();
            FUN_a010b17c();
        }
    } else {
        FUN_a010afc8();
        FUN_a010b198();
    }
    if ((unsigned char)(p - 15) <= 7)
        DAT_a802e3d0.h1a = FUN_a012e8c0(p);
    switch (p) {
    case 12:
        v0 = 0xff;
        v1 = 0xff;
        v2 = 0xff;
        break;
    case 14:
        v0 = 0xff;
        v1 = 0xff;
        v2 = 0xff;
        break;
    case 2:
        v0 = 0xff;
        v1 = 0xff;
        v2 = 0xff;
        break;
    case 9:
        FUN_a010afac();
        set = 0;
        FUN_a010b17c();
        break;
    case 0:
        v0 = 0xff;
        v1 = 0xff;
        v2 = 0xff;
        break;
    case 1:
        if (__builtin_expect(FUN_a012f134(DAT_a802e3d0.b18) != 0, 0) && FUN_a012e550(1 << (DAT_a802e3d0.b18 & 0xf), 2, buf)) {
            v0 = buf[0];
            v1 = buf[1];
            v2 = buf[2];
        } else {
            if (DAT_a802e1f0[6] <= 0x7e || DAT_a802e1f0[7] <= 0x73 || DAT_a802e1f0[8] == 0 || DAT_a802e1f0[8] == 0xff) {
                DAT_a802e1f0[6] = 0xff;
                DAT_a802e1f0[7] = 0xe8;
                DAT_a802e1f0[8] = 0xbd;
            }
            v0 = DAT_a802e1f0[6];
            v1 = DAT_a802e1f0[7];
            v2 = DAT_a802e1f0[8];
        }
        break;
    case 4:
        if (__builtin_expect(FUN_a012f134(DAT_a802e3d0.b18) != 0, 0) && FUN_a012e550(1 << (DAT_a802e3d0.b18 & 0xf), 0x10, buf)) {
            v0 = buf[0];
            v1 = buf[1];
            v2 = buf[2];
        } else {
            if (DAT_a802e1f0[9] <= 0x7e || DAT_a802e1f0[0xa] <= 0x7e || DAT_a802e1f0[0xb] <= 0x7e) {
                DAT_a802e1f0[9] = 0xff;
                DAT_a802e1f0[0xa] = 0xff;
                DAT_a802e1f0[0xb] = 0xff;
            }
            v0 = DAT_a802e1f0[9];
            v1 = DAT_a802e1f0[0xa];
            v2 = DAT_a802e1f0[0xb];
        }
        break;
    case 5:
        if (DAT_a802e1f0[0xc] <= 0x7b || DAT_a802e1f0[0xd] <= 0x7e || DAT_a802e1f0[0xe] <= 0x7e) {
            DAT_a802e1f0[0xc] = 0xf8;
            DAT_a802e1f0[0xd] = 0xff;
            DAT_a802e1f0[0xe] = 0xff;
        }
        v0 = DAT_a802e1f0[0xc];
        v1 = DAT_a802e1f0[0xd];
        v2 = DAT_a802e1f0[0xe];
        break;
    case 6:
        if (DAT_a802e1f0[0xf] <= 0x7b || DAT_a802e1f0[0x10] <= 0x7b || DAT_a802e1f0[0x11] <= 0x7e) {
            DAT_a802e1f0[0xf] = 0xf8;
            DAT_a802e1f0[0x10] = 0xf8;
            DAT_a802e1f0[0x11] = 0xff;
        }
        v0 = DAT_a802e1f0[0xf];
        v1 = DAT_a802e1f0[0x10];
        v2 = DAT_a802e1f0[0x11];
        break;
    case 7:
        if (__builtin_expect(FUN_a012f134(DAT_a802e3d0.b18) != 0, 0) && FUN_a012e550(1 << (DAT_a802e3d0.b18 & 0xf), 0x80, buf)) {
            v0 = buf[0];
            v1 = buf[1];
            v2 = buf[2];
        } else {
            if (DAT_a802e1f0[0x12] <= 0x67 || DAT_a802e1f0[0x13] <= 0x6a || DAT_a802e1f0[0x14] <= 0x7e) {
                DAT_a802e1f0[0x12] = 0xd1;
                DAT_a802e1f0[0x13] = 0xd6;
                DAT_a802e1f0[0x14] = 0xff;
            }
            v0 = DAT_a802e1f0[0x12];
            v1 = DAT_a802e1f0[0x13];
            v2 = DAT_a802e1f0[0x14];
        }
        break;
    case 3:
        v0 = 0xff;
        v1 = 0xff;
        v2 = 0xff;
        break;
    case 13:
        v0 = 0xff;
        v1 = 0xff;
        v2 = 0xff;
        break;
    case 8:
        if (DAT_a802e1f0[0x15] <= 0x77 || DAT_a802e1f0[0x16] <= 0x77 || DAT_a802e1f0[0x17] <= 0x7e) {
            DAT_a802e1f0[0x15] = 0xf0;
            DAT_a802e1f0[0x16] = 0xf0;
            DAT_a802e1f0[0x17] = 0xff;
        }
        v0 = DAT_a802e1f0[0x15];
        v1 = DAT_a802e1f0[0x16];
        v2 = DAT_a802e1f0[0x17];
        break;
    case 10:
        v0 = DAT_a802e1f0[0x1b];
        v1 = DAT_a802e1f0[0x1c];
        v2 = DAT_a802e1f0[0x1d];
        break;
    case 11:
        v0 = DAT_a802e1f0[0x1e];
        v1 = DAT_a802e1f0[0x1f];
        v2 = DAT_a802e1f0[0x20];
        break;
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
        if (FUN_a012f134(DAT_a802e3d0.b18)) {
            FUN_a012e6c0(DAT_a802e3d0.h1a);
            set = 0;
        } else {
            v0 = 0xff;
            v1 = 0xff;
            v2 = 0xff;
            if (p == 15) {
                v0 = DAT_a802e1f0[0x21];
                v1 = DAT_a802e1f0[0x22];
                v2 = DAT_a802e1f0[0x23];
            }
        }
        break;
    default:
        v0 = (DAT_a802e3d0.c * 200u + 50) / 100 + 0x37;
        v1 = (DAT_a802e3d0.d * 200u + 50) / 100 + 0x37;
        v2 = (DAT_a802e3d0.e * 200u + 50) / 100 + 0x37;
        break;
    }
    if (FUN_a0140058((DAT_a802df30 >> 12) & 0xf) != 1 && !(DAT_a802e224[(DAT_a802df30 >> 12) & 0xf].h0 & 0x40))
        do continue; while (0);
    else {
        v0 = (DAT_a802e3d0.c * 200u + 50) / 100 + 0x37;
        v1 = (DAT_a802e3d0.d * 200u + 50) / 100 + 0x37;
        v2 = (DAT_a802e3d0.e * 200u + 50) / 100 + 0x37;
    }
    if (set)
        FUN_a013b4a4(v0 + 1, v1 + 1, v2 + 1);
}
