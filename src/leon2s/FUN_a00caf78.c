/*
 * FUN_a00caf78 (leon2s, 0xa00caf78-0xa00cb1d4, 604 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Works on the 24-byte record DAT_a8078bb0[port] (st = bits 16..17 of word 0). ok = 1;
 * st == 1: ok = FUN_a00ca6d4(port). While ok, the count (50) and st == 1 hold: count--,
 * func_0xa0fc1794(10), and st = 3 when the count reaches 0. Then FUN_a00c9798(port, DAT_a807d250) != 0
 * or bits 2..3 of DAT_a807d250[1] set: st = 0; ((DAT_a807d250[1] & 3) << 8) + DAT_a807d250[0] == 0:
 * st = 3; FUN_a00c8048(port, 0x74, 0x80, 0x21) or FUN_a00c81f8(port, DAT_a807ce50, 0x21) != 0: st = 0.
 * Otherwise copies DAT_a807ce50[1..32] to DAT_a807cd88[0..31], sets st = 1, and when DAT_a807d088[0..31]
 * differs from DAT_a807cd88: st = 0 and FUN_a00c79c8(port).
 * Source forms: the wait loop condition is 'ok != 0 && t != 0 && st == 1' (flag arithmetic for the first
 * two tests) with the decrement first in the body.
 */
struct Rec18 {
    unsigned int b31 : 1;
    unsigned int b30 : 1;
    unsigned int b29 : 1;
    unsigned int b28 : 1;
    unsigned int f24 : 4;
    unsigned int b23 : 1;
    unsigned int b22 : 1;
    unsigned int b21 : 1;
    unsigned int b20 : 1;
    unsigned int b19 : 1;
    unsigned int b18 : 1;
    unsigned int st : 2;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char b8;
    unsigned char b9;
    unsigned char pad_a[6];
    unsigned int w10;
    unsigned char pad_14[4];
};
extern struct Rec18 DAT_a8078bb0[];
extern unsigned char DAT_a807d250[];
extern unsigned char DAT_a807ce50[];
extern unsigned char DAT_a807cd88[];
extern unsigned char DAT_a807d088[];
extern unsigned char FUN_a00ca6d4(unsigned char);
extern unsigned char FUN_a00c9798(unsigned char, unsigned char *);
extern unsigned char FUN_a00c8048(unsigned char, unsigned char, unsigned char, unsigned char);
extern unsigned char FUN_a00c81f8(unsigned char, unsigned char *, unsigned char);
extern void FUN_a00c79c8(unsigned char);
extern void func_0xa0fc1794(unsigned int);

void FUN_a00caf78(unsigned char port)
{
    unsigned char ok = 1;
    unsigned char t = 50;
    unsigned char hi;
    unsigned short n;
    unsigned char i;

    if (DAT_a8078bb0[port].st == 1)
        ok = FUN_a00ca6d4(port);
    while (ok != 0 && t != 0 && DAT_a8078bb0[port].st == 1) {
        t--;
        func_0xa0fc1794(10);
        if (t == 0) {
            DAT_a8078bb0[port].st = 3;
            break;
        }
    }
    if (FUN_a00c9798(port, DAT_a807d250)) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    hi = DAT_a807d250[1];
    n = ((hi & 3) << 8) + DAT_a807d250[0];
    if (hi & 0xc) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    if (n == 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    if (FUN_a00c8048(port, 0x74, 0x80, 0x21) || FUN_a00c81f8(port, DAT_a807ce50, 0x21)) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    for (i = 0; i < 0x20; i++)
        DAT_a807cd88[i] = DAT_a807ce50[i + 1];
    DAT_a8078bb0[port].st = 1;
    for (i = 0; i < 0x20; i++) {
        if (DAT_a807d088[i] != DAT_a807cd88[i]) {
            DAT_a8078bb0[port].st = 0;
            FUN_a00c79c8(port);
            break;
        }
    }
}
