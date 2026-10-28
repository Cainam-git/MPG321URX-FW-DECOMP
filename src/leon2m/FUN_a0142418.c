/* leon2m FUN_a0142418 @ 0xa0142418-0xa0142518 (64 words), flags -mcpu=v8 -O3 -g.
 * FUN_a0142418(ch, mode): p = FUN_a013ce10(ch); k = 0 for ch 0, 1 for ch 1 and 3 for any other ch, which ends
 * the function. e = bits 12..15 of p->w0; when FUN_a0104c34(e) returns 0, func_0x4008e2a4() is called.
 * mode 0: FUN_a011f1c8(k, e, 0). Any other mode uses entry 'mode' of the 16-byte ROM table at 0x1a6cb4 (three
 * words a, b, c, halfword +0xc, byte +0xe): FUN_a011f364(k, a), FUN_a011f6a4(k, b, c), FUN_a011fbd8(k, +0xc),
 * FUN_a011fcac(k, +0xe), then FUN_a011f1c8(k, e, 1).
 * Source form: the channel map is an inlined static helper (r preset to 3, a switch for 0 and 1); its result is
 * masked with '& 3' after the helper. mode 0 returns right after its own FUN_a011f1c8 call; a single call with the
 * last argument chosen by mode compiles to one shared call instead of the firmware's two.
 */
struct Rec;
struct Port { unsigned int w0; };
struct Mode { struct Rec *a, *b, *c; unsigned short h0c; unsigned char b0e; };
extern const struct Mode DAT_001a6cb4[];
extern struct Port *FUN_a013ce10(unsigned char id);
extern unsigned char FUN_a0104c34(unsigned char);
extern void func_0x4008e2a4(void);
extern void FUN_a011f364(unsigned int blk, struct Rec *r);
extern void FUN_a011f6a4(unsigned int blk, struct Rec *a, struct Rec *b);
extern void FUN_a011fbd8(unsigned int blk, unsigned int v);
extern void FUN_a011fcac(unsigned int blk, unsigned char b);
extern void FUN_a011f1c8(unsigned int blk, unsigned char b2, unsigned char on);

static unsigned char rmap(unsigned char ch)
{
    unsigned char r = 3;

    switch (ch) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 1;
        break;
    }
    return r;
}

void FUN_a0142418(unsigned char ch, int mode)
{
    struct Port *p = FUN_a013ce10(ch);
    unsigned int k = rmap(ch) & 3;

    if (k == 3)
        return;
    if (!FUN_a0104c34((p->w0 >> 12) & 0xf))
        func_0x4008e2a4();
    if (mode == 0) {
        FUN_a011f1c8(k, (p->w0 >> 12) & 0xf, 0);
        return;
    }
    FUN_a011f364(k, DAT_001a6cb4[mode].a);
    FUN_a011f6a4(k, DAT_001a6cb4[mode].b, DAT_001a6cb4[mode].c);
    FUN_a011fbd8(k, DAT_001a6cb4[mode].h0c);
    FUN_a011fcac(k, DAT_001a6cb4[mode].b0e);
    FUN_a011f1c8(k, (p->w0 >> 12) & 0xf, 1);
}
