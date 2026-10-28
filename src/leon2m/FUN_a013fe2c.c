/* leon2m FUN_a013fe2c @ 0xa013fe2c-0xa013ffb0 (97 words), -mcpu=v8 -O3 -g.
 * p = FUN_a013cd4c(port). Returns at once when FUN_a0142e8c(port) is 5. Otherwise searches the 36-byte ROM rows
 * DAT_001a5a16 (the list ends at a row whose halfword +2 is 0xffff) for the first row i whose halfword +0x22 equals v;
 * returns when there is none or i is 0xff. For a match it copies that row into the record FUN_a013cd4c(port) with
 * FUN_a013f284(port, i), inlined here as a static copy (row halfwords to record fields +0xe..+0x2c, +0x26 = 0x20,
 * +0x3a = 0, +0x3c = row +0x22, five fields scaled by row byte 0 when it is non-zero), then calls
 * FUN_a01542c4(p + 6) when FUN_a01541ec(p + 6) is 0. No caller refers to it directly.
 * Source form: i is initialised in its declaration; the search loop sets i = 0xff at the end row and breaks, and the
 * single 'i == 0xff' test after the loop covers both outcomes.
 */
struct Row {
    unsigned char k;
    unsigned char pad1;
    unsigned short h2;
    unsigned char pad4[6];
    unsigned short ha, hc, he, h10, h12, h14, h16, h18, h1a, h1c, h1e, h20, h22;
};
struct Rec {
    unsigned char pad0[0xe];
    unsigned short he, h10, h12, h14, h16, h18, h1a, h1c, h1e, h20;
    unsigned char pad22[4];
    unsigned char b26, b27;
    unsigned short h28, h2a, h2c;
    unsigned char pad2e[0xc];
    unsigned char b3a, b3b;
    unsigned short h3c;
};
extern const struct Row DAT_001a5a16[];
extern struct Rec *FUN_a013cd4c(unsigned char port);
extern unsigned char FUN_a0142e8c(unsigned int);
extern void FUN_a01542c4(void *m);
extern unsigned char FUN_a01541ec(void *m);

static void FUN_a013f284(unsigned char port, unsigned char idx)
{
    struct Rec *o = FUN_a013cd4c(port);
    const struct Row *tab = DAT_001a5a16;
    const struct Row *t = tab + idx;

    o->h12 = t->he;
    o->h14 = t->h10;
    o->h16 = t->h12;
    o->h18 = t->h14;
    o->he = t->ha;
    o->h1e = t->h1a;
    o->h20 = t->h1c;
    o->h1a = t->h16;
    o->h1c = t->h18;
    o->h28 = t->ha;
    o->h2a = t->h16;
    o->h2c = t->h18;
    o->b26 = 0x20;
    o->b3a = 0;
    o->h3c = t->h22;
    if (tab[idx].k) {
        o->h16 *= tab[idx].k;
        o->he *= tab[idx].k;
        o->h1e *= tab[idx].k;
        o->h28 *= tab[idx].k;
        o->h2a *= tab[idx].k;
    }
}

void FUN_a013fe2c(unsigned char port, unsigned short v)
{
    struct Rec *p = FUN_a013cd4c(port);
    unsigned char i = 0;

    if (FUN_a0142e8c(port) == 5)
        return;
    for (; ; i++) {
        if (DAT_001a5a16[i].h2 == 0xffff) {
            i = 0xff;
            break;
        }
        if (DAT_001a5a16[i].h22 == v)
            break;
    }
    if (i == 0xff)
        return;
    FUN_a013f284(port, i);
    if (FUN_a01541ec((unsigned char *)p + 6) == 0)
        FUN_a01542c4((unsigned char *)p + 6);
}
