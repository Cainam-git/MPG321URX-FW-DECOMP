/* leon2m FUN_a013f284 @ 0xa013f284-0xa013f370 (59 words), flags -mcpu=v8 -O3 -g. No direct callers (reached through
 * a table). Copies row idx of the 36-byte ROM records at 0x1a5a16 into the record o = FUN_a013cd4c(port) (halfword
 * fields): o->h12..h18 = t->he..h14, o->he = t->ha, o->h1e = t->h1a, o->h20 = t->h1c, o->h1a = t->h16, o->h1c =
 * t->h18, o->h28 = t->ha, o->h2a = t->h16, byte o->b26 = 0x20, o->h2c = t->h18, byte o->b3a = 0, o->h3c = t->h22.
 * When the row's first byte k is not 0, o->h16, o->he, o->h1e, o->h28 and o->h2a are multiplied by k.
 * Exact form: the table is read through a local pointer tab; the row is t = tab + idx, but k is read as tab[idx].k
 * (ldub [tab + offset] operand order) and o->h2c is written before o->b26.
 */
struct Row {
    unsigned char k;
    unsigned char pad1[9];
    unsigned short ha, hc, he, h10, h12, h14, h16, h18, h1a, h1c, h1e, h20, h22;
};
struct Out {
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
extern struct Out *FUN_a013cd4c(unsigned char port);

void FUN_a013f284(unsigned char port, unsigned char idx)
{
    struct Out *o = FUN_a013cd4c(port);
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
