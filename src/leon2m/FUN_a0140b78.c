/* leon2m FUN_a0140b78 @ 0xa0140b78-0xa0140e74 (191 words), -mcpu=v8 -O3 -g.
 * For device dev (38-byte ROM record DAT_001a69fe[dev], b = its byte b0): a = row_addr(dev, DAT_a802cbdc[b].b8);
 * k = the device whose area contains the halfword DAT_a802a47a (only device 0 is tested, else 0xff), kb = its b0.
 * When DAT_a802a47a is not 0xffff and the byte DAT_a802cbd9 is non-zero, FUN_a01405d0(k) is called if b != kb, or
 * if b == kb, the area record DAT_001a6a24[b].b2 is 1 and a != DAT_a802a47a. Then, when b2 is 0: a == 0xffff ->
 * DAT_a802cbdc[b].b8 = 0, a = row_addr(dev, 0xff), FUN_a0134394(a, DAT_001a69fe[dev].b4); otherwise when b != kb
 * FUN_a0134394(a, DAT_001a69fe[dev].b4). When b2 is not 0: FUN_a0134394(a, 8) if DAT_a802a47a != a. Finally
 * DAT_a802a47a = a. row_addr is the 16-bit address helper of FUN_a01405d0 (index i, or DAT_a802cbdc[b].b8 when i is
 * 0xff; 0xffff when that is 0xff too; i * (b4 << 8) + h0 when b2 is 0, else (h0 + (b1 << 11)) & 0xf800).
 * Record layouts as in FUN_a0140360. Called by FUN_a0140e74.
 * Source form: the search is an inlined static helper as in FUN_a0140a0c; row_addr is the one-exit helper with an
 * unsigned short result variable, called first with the pre-read index byte; the FUN_a01405d0 call is written
 * twice, once per arm of 'b != kb' / 'b2 == 1 && a != DAT_a802a47a', each behind its own DAT_a802cbd9 test.
 */
struct B38 { unsigned char b0, b1; unsigned short h2; unsigned char b4; char name[33]; };
struct A36 { unsigned short h0; unsigned char b2, b3; char name[32]; };
struct D12 { unsigned short h0; unsigned short h2; int w4; unsigned char b8, b9; unsigned char pad[2]; };
extern const struct B38 DAT_001a69fe[];
extern const struct A36 DAT_001a6a24[];
extern struct D12 DAT_a802cbdc[];
extern unsigned char DAT_a802cbd9;
extern unsigned short DAT_a802a47a;
extern void FUN_a01405d0(unsigned char);
extern void FUN_a0134394(unsigned short, unsigned char);

static unsigned char find(void)
{
    unsigned char i, b;

    for (i = 0; i < 1; i++) {
        b = DAT_001a69fe[i].b0;
        if (DAT_a802cbdc[b].h0 <= DAT_a802a47a && DAT_a802a47a < DAT_a802cbdc[b].h0 + DAT_001a6a24[b].h0)
            return i;
    }
    return 0xff;
}

static unsigned short row_addr(unsigned char dev, unsigned char s)
{
    unsigned char b = DAT_001a69fe[dev].b0;
    unsigned short a;
    unsigned char t;

    if (DAT_001a6a24[b].b2 == 0) {
        t = s == 0xff ? DAT_a802cbdc[b].b8 : s;
        if (t == 0xff)
            a = -1;
        else
            a = t * (DAT_001a69fe[dev].b4 << 8) + DAT_a802cbdc[b].h0;
    } else
        a = (DAT_a802cbdc[b].h0 + (DAT_001a69fe[dev].b1 << 11)) & 0xf800;
    return a;
}

void FUN_a0140b78(unsigned char dev)
{
    unsigned char b = DAT_001a69fe[dev].b0;
    unsigned short a = row_addr(dev, DAT_a802cbdc[b].b8);
    unsigned char k = find();
    unsigned char kb = DAT_001a69fe[k].b0;

    if (DAT_a802a47a != 0xffff) {
        if (b != kb) {
            if (DAT_a802cbd9)
                FUN_a01405d0(k);
        } else if (DAT_001a6a24[b].b2 == 1 && a != DAT_a802a47a) {
            if (DAT_a802cbd9)
                FUN_a01405d0(k);
        }
    }
    if (DAT_001a6a24[b].b2 == 0) {
        if (a == 0xffff) {
            DAT_a802cbdc[b].b8 = 0;
            a = row_addr(dev, 0xff);
            FUN_a0134394(a, DAT_001a69fe[dev].b4);
        } else if (b != kb)
            FUN_a0134394(a, DAT_001a69fe[dev].b4);
    } else {
        if (DAT_a802a47a != a)
            FUN_a0134394(a, 8);
    }
    DAT_a802a47a = a;
}
