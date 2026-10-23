/* leon2m FUN_a0145808 @ 0xa0145808-0xa0145920 (70 words).
 * Channel i = ch for ch 0..3 (any other ch gives 0xff through the remap helper of FUN_a0143f0c, without the
 * range check). Stores v into a halfword of the channel record DAT_a802df30[i] (0x78 bytes) chosen by id:
 * 9 -> +0x16, 10 -> +0x18, 12 -> +0x1e, 16 -> +0x20 (other ids store nothing). For id 12 / 16 with upd == 0 it
 * passes the port field (bits 12..15 of word +0) and v to FUN_a00f8e0c / FUN_a00f8e44. When upd != 0 it ends
 * with FUN_a012f1ec(i, 2). Called by FUN_a00830f4, FUN_a00d40c8, FUN_a00d5748 and others.
 * Source form: the record pointer is taken once before the switch; the calls for id 12 / 16 sit inside the
 * switch arms (not in tail position, so they are plain calls).
 */
struct Chan {
    unsigned int w0;
    unsigned char p04[0x16 - 0x04];
    unsigned short h16, h18;
    unsigned char p1a[0x1e - 0x1a];
    unsigned short h1e, h20;
    unsigned char p22[0x78 - 0x22];
};
extern struct Chan DAT_a802df30[4];
extern void FUN_a00f8e0c(unsigned char, unsigned short);
extern void FUN_a00f8e44(unsigned char, unsigned short);
extern void FUN_a012f1ec(unsigned char ch, unsigned char m);

static int remap(int ch)
{
    switch (ch) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

void FUN_a0145808(unsigned char ch, unsigned int id, unsigned short v, unsigned char upd)
{
    unsigned char i = remap(ch);
    struct Chan *c = &DAT_a802df30[i];

    switch (id) {
    case 9:
        c->h16 = v;
        break;
    case 10:
        c->h18 = v;
        break;
    case 12:
        c->h1e = v;
        if (!upd)
            FUN_a00f8e0c((c->w0 >> 12) & 0xf, v);
        break;
    case 16:
        c->h20 = v;
        if (!upd)
            FUN_a00f8e44((c->w0 >> 12) & 0xf, v);
        break;
    }
    if (upd)
        FUN_a012f1ec(i, 2);
}
