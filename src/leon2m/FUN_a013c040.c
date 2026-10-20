/* leon2m FUN_a013c040 @ 0xa013c040-0xa013c144 (260 bytes)  re-apply the output timing on port 0 (writes record +0x68)
 * (hand; BYTE-EXACT at -mcpu=v8 -O3 -g).
 * Only port 0. Copies the 0x3C-byte timing block at record +6 (FUN_a013c910 = memcpy) and calls FUN_a01086fc(0, &copy, w, h, il, 0, 0).
 * Interlace case (DAT_a802e3d0 bit 25, record +0x70 bit 31 and FUN_a0121258(0) == 1): h = record +0x18, il = 1, and record byte +0x68
 * (top byte of word +0x68) = 0. Always: word +0x68 bits 22 and 21 cleared, then FUN_a00f9880().
 * Declaration order t2, t1 gives the firmware stack slots (fp-136 / fp-72).
 */
struct Timing { unsigned char d[0x3c]; };
struct Out {
    union {
        struct { unsigned char pad0[6]; struct Timing t; } a;
        struct { unsigned char pad0[0x18]; unsigned short h18; } b;
    } u;
    unsigned char pad42[0x26];
    union { unsigned int w; unsigned char b[4]; } r68;
    unsigned int w6c;
    int w70;
};
extern unsigned int DAT_a802e3d0;
extern struct Out *FUN_a013cd4c(unsigned char port);
extern void *FUN_a013c910(void *dst, const void *src, int n);
extern unsigned char FUN_a0121258(unsigned char port);
extern void FUN_a01086fc(unsigned char a, struct Timing *t, unsigned short w, unsigned short h, unsigned char il, unsigned char x, unsigned char y);
extern void FUN_a00f9880(void);

void FUN_a013c040(unsigned char port, unsigned short w, unsigned short h)
{
    struct Out *o;
    struct Timing t2;
    struct Timing t1;

    o = FUN_a013cd4c(port);
    if (port != 0)
        return;
    if ((DAT_a802e3d0 & 0x2000000) && o->w70 < 0 && FUN_a0121258(0) == 1) {
        FUN_a013c910(&t2, &o->u.a.t, 0x3c);
        FUN_a01086fc(0, &t2, w, o->u.b.h18, 1, 0, 0);
        o->r68.b[0] = 0;
    } else {
        FUN_a013c910(&t1, &o->u.a.t, 0x3c);
        FUN_a01086fc(0, &t1, w, h, 0, 0, 0);
    }
    o->r68.w &= ~0x400000;
    o->r68.w &= ~0x200000;
    FUN_a00f9880();
}
