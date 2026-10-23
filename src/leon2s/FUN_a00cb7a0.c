/*
 * FUN_a00cb7a0 (leon2s, 0xa00cb7a0-0xa00cbb50, 944 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Works on the 24-byte record DAT_a8078bb0[port] (bit-fields as in FUN_a00c91f8: f28,
 * f23, st = bits 16..17; bytes +3..+8) and the buffer DAT_a807ce50. Sets st = 1; fills buffer bytes
 * i, i + 8 and i + 0x10 (i = 1..8) with i, i + 8 and i + 0x20; FUN_a00c87e8(port, 0x15, 0x8000) and writes
 * bytes 1..16 to register 0x12, FUN_a00c87e8(port, 0x11, 0x8000) and bytes 0x11..0x18 to register 1
 * (FUN_a00c7654(port, reg, v)); register 6 = 10.
 * Polls bit 3 of FUN_a00c7770(port, 6) until it reads 0, at most 255 times; when the count runs out: st = 3.
 * Otherwise: register 0xd = 0x3a when bit 2 of word 0 of the 28-byte record ARR_a807d580[port] is set,
 * else 0x76; register 0xe = 0; buffer byte 0 = 0xb; FUN_a00c87e8(port, 10, 0x8000); bytes 1..16 read with
 * FUN_a00c7770(port, 1); FUN_a00c80f0(port, DAT_a807ce50, 0x74, 0x60, 0x19). With f28 set: st = 2. With f28
 * clear: f23 = 0, FUN_a00c76c0(port, 5, 4, 1) and (port, 5, 4, 0), FUN_a00c87e8(port, 0xb, 0x8000),
 * register 1 gets 2, 0x10, 0, 0, 0, the 5 bytes of row port of DAT_a807ce38, 2, 0x10, 0, 0, 0, 0x80;
 * bytes +3, +4 = 1, +5..+8 = 0; st = 1.
 * Source forms: the poll is 'i = 0xff; while (read & 8) { i--; if (i == 0) goto fail; }' with the loop
 * counter i reused; the st = 3 and st = 2 exits are labels after the success path (firmware block order);
 * the fill loop stores bytes i, i + 8, i + 0x10 in that order.
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
    unsigned char b7;
    unsigned char b8;
    unsigned char pad[15];
};
struct Rec28 { unsigned int w0; unsigned char pad[24]; };
extern struct Rec24 DAT_a8078bb0[];
extern struct Rec28 ARR_a807d580[];
extern unsigned char DAT_a807ce50[];
extern unsigned char DAT_a807ce38[][5];
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern void FUN_a00c7654(unsigned char, unsigned short, unsigned char);
extern unsigned char FUN_a00c7770(unsigned char, unsigned short);
extern void FUN_a00c76c0(unsigned char, unsigned short, unsigned char, unsigned char);
extern int FUN_a00c80f0(unsigned char, unsigned char *, unsigned char, unsigned char, unsigned short);

void FUN_a00cb7a0(unsigned char port)
{
    unsigned char i;

    DAT_a8078bb0[port].st = 1;
    for (i = 1; i < 9; i++) {
        DAT_a807ce50[i] = i;
        DAT_a807ce50[i + 8] = i + 8;
        DAT_a807ce50[i + 0x10] = i + 0x20;
    }
    FUN_a00c87e8(port, 0x15, 0x8000);
    for (i = 0; i < 16; i++)
        FUN_a00c7654(port, 0x12, DAT_a807ce50[i + 1]);
    FUN_a00c87e8(port, 0x11, 0x8000);
    for (i = 0; i < 8; i++)
        FUN_a00c7654(port, 1, DAT_a807ce50[i + 0x11]);
    FUN_a00c7654(port, 6, 10);
    i = 0xff;
    while (FUN_a00c7770(port, 6) & 8) {
        i--;
        if (i == 0)
            goto fail;
    }
    if (ARR_a807d580[port].w0 & 4)
        FUN_a00c7654(port, 0xd, 0x3a);
    else
        FUN_a00c7654(port, 0xd, 0x76);
    FUN_a00c7654(port, 0xe, 0);
    DAT_a807ce50[0] = 0xb;
    FUN_a00c87e8(port, 10, 0x8000);
    for (i = 0; i < 16; i++)
        DAT_a807ce50[i + 1] = FUN_a00c7770(port, 1);
    FUN_a00c80f0(port, DAT_a807ce50, 0x74, 0x60, 0x19);
    if (DAT_a8078bb0[port].f28 == 0) {
        DAT_a8078bb0[port].f23 = 0;
        FUN_a00c76c0(port, 5, 4, 1);
        FUN_a00c76c0(port, 5, 4, 0);
        FUN_a00c87e8(port, 0xb, 0x8000);
        FUN_a00c7654(port, 1, 2);
        FUN_a00c7654(port, 1, 0x10);
        FUN_a00c7654(port, 1, 0);
        FUN_a00c7654(port, 1, 0);
        FUN_a00c7654(port, 1, 0);
        for (i = 0; i < 5; i++)
            FUN_a00c7654(port, 1, DAT_a807ce38[port][i]);
        FUN_a00c7654(port, 1, 2);
        FUN_a00c7654(port, 1, 0x10);
        FUN_a00c7654(port, 1, 0);
        FUN_a00c7654(port, 1, 0);
        FUN_a00c7654(port, 1, 0);
        FUN_a00c7654(port, 1, 0x80);
        DAT_a8078bb0[port].b3 = 1;
        DAT_a8078bb0[port].b4 = 1;
        DAT_a8078bb0[port].b5 = 0;
        DAT_a8078bb0[port].b6 = 0;
        DAT_a8078bb0[port].b7 = 0;
        DAT_a8078bb0[port].b8 = 0;
        DAT_a8078bb0[port].st = 1;
        return;
    }
    goto st2;
fail:
    DAT_a8078bb0[port].st = 3;
    return;
st2:
    DAT_a8078bb0[port].st = 2;
}
