/*
 * FUN_a00aef04 (leon2s, 0xa00aef04-0xa00af168, 612 bytes), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/153.
 * Code facts: for port = (u8)param_1 it reads 8 indirect registers 0x0a..0x11 of the port
 * (FUN_a00a6c00(port,0x70,0); FUN_a00a6c00(port,0x73,idx); FUN_a00a6bb8(port,0x7a)), the first two
 * results discarded. denom = r10:r11, num = r0c:r0d, hres = r0e:r0f (u16 big-endian byte pairs;
 * the draft had hres = r0f:r0e, BEHAVIOUR bug). denom 0 -> 0x3c0, hres 0 -> 0x1e0.
 * ratio = (u8)(num / denom); reg 0x481 gets 0x10/0x20/0x40 for ratio 1/2/4, else 0x80 (signed
 * case tree, root 2). Ends in a sibcall FUN_a00aee08(param_1 & 0xff, hres, ratio) (3 args, the
 * fw re-does 'and %i0,0xff' on the param, hence a separate u8 local port).
 * Aids: none. Source order denom, num, hres sets the fw schedule of the byte-pair joins.
 */
extern unsigned int FUN_a00a6bb8(unsigned int, unsigned short);
extern void FUN_a00a6c00(unsigned int, unsigned short, unsigned char);
extern void FUN_a00aee08(unsigned int, unsigned int, unsigned char);

void FUN_a00aef04(unsigned int param_1)
{
    unsigned char port = param_1;
    unsigned int r0c, r0d, r0e, r0f, r10, r11;
    unsigned short num, hres, denom;
    unsigned char ratio;

    FUN_a00a6c00(port, 0x70, 0);
    FUN_a00a6c00(port, 0x73, 0xa);
    FUN_a00a6bb8(port, 0x7a);
    FUN_a00a6c00(port, 0x70, 0);
    FUN_a00a6c00(port, 0x73, 0xb);
    FUN_a00a6bb8(port, 0x7a);
    FUN_a00a6c00(port, 0x70, 0);
    FUN_a00a6c00(port, 0x73, 0xc);
    r0c = FUN_a00a6bb8(port, 0x7a);
    FUN_a00a6c00(port, 0x70, 0);
    FUN_a00a6c00(port, 0x73, 0xd);
    r0d = FUN_a00a6bb8(port, 0x7a);
    FUN_a00a6c00(port, 0x70, 0);
    FUN_a00a6c00(port, 0x73, 0xe);
    r0e = FUN_a00a6bb8(port, 0x7a);
    FUN_a00a6c00(port, 0x70, 0);
    FUN_a00a6c00(port, 0x73, 0xf);
    r0f = FUN_a00a6bb8(port, 0x7a);
    FUN_a00a6c00(port, 0x70, 0);
    FUN_a00a6c00(port, 0x73, 0x10);
    r10 = FUN_a00a6bb8(port, 0x7a);
    FUN_a00a6c00(port, 0x70, 0);
    FUN_a00a6c00(port, 0x73, 0x11);
    r11 = FUN_a00a6bb8(port, 0x7a);

    denom = (r10 & 0xff) * 0x100 + (r11 & 0xff);
    num = (r0c & 0xff) * 0x100 + (r0d & 0xff);
    hres = (r0e & 0xff) * 0x100 + (r0f & 0xff);
    if (denom == 0)
        denom = 0x3c0;
    if (hres == 0)
        hres = 0x1e0;
    ratio = num / denom;

    switch (ratio) {
    case 2:
        FUN_a00a6c00(port, 0x481, 0x20);
        break;
    case 4:
        FUN_a00a6c00(port, 0x481, 0x40);
        break;
    case 1:
        FUN_a00a6c00(port, 0x481, 0x10);
        break;
    default:
        FUN_a00a6c00(port, 0x481, 0x80);
        break;
    }
    FUN_a00aee08(param_1 & 0xff, hres, ratio);
}
