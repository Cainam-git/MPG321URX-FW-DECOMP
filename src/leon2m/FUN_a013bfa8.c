/* leon2m FUN_a013bfa8 @ 0xa013bfa8-0xa013c040 (152 bytes)  input timing record -> output timing record
 * (hand; -mcpu=v8 -O3 -g).
 * o = FUN_a013cd4c(port) (output timing record); p = port record 0xA802E224 + 0x2A*port.
 * lines = p->h18 (input line count), doubled when FUN_a0121258(port) (input register 0 bit 2, the interlace flag);
 * o->h12 = o->h16 = p->h16; o->h14 = o->h18 = lines; o->h1a/h1e = FUN_a00f88ac(port), o->h1c = FUN_a00f88cc(port),
 * o->h2c = o->h20 = FUN_a00f88cc(port), o->h2a = o->h1e.
 * Source order of the stores reproduces the firmware's scheduling; no unusual constructs.
 */
struct Out {
    unsigned char pad0[0x12];
    unsigned short h12, h14, h16, h18, h1a, h1c, h1e, h20;
    unsigned char pad22[8];
    unsigned short h2a, h2c;
};
struct Port {
    unsigned char pad0[0x16];
    unsigned short h16, h18;
    unsigned char pad1a[0x10];
};
extern struct Port DAT_a802e224[];
extern struct Out *FUN_a013cd4c(unsigned char port);
extern unsigned char FUN_a0121258(unsigned char port);
extern unsigned short FUN_a00f88ac(unsigned char port);
extern unsigned short FUN_a00f88cc(unsigned char port);

void FUN_a013bfa8(unsigned char port)
{
    struct Out *o;
    struct Port *p;
    unsigned short lines;
    unsigned short w;
    unsigned short t;

    o = FUN_a013cd4c(port);
    p = &DAT_a802e224[port];
    lines = p->h18;
    if (FUN_a0121258(port))
        lines = lines * 2;
    w = p->h16;
    o->h14 = lines;
    o->h18 = lines;
    o->h16 = w;
    o->h12 = w;
    o->h1a = FUN_a00f88ac(port);
    o->h1c = FUN_a00f88cc(port);
    o->h1e = FUN_a00f88ac(port);
    t = FUN_a00f88cc(port);
    o->h2a = o->h1e;
    o->h20 = t;
    o->h2c = t;
}
