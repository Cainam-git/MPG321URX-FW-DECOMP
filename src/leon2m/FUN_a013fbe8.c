/* leon2m FUN_a013fbe8 @ 0xa013fbe8-0xa013fe2c (145 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * p = FUN_a013cd4c(port); returns when FUN_a0142e8c(port) is 5. Searches the 36-byte ROM records at 0x1a5a16
 * (ended by halfword 2 == 0xffff) for the first row i whose halfword 0x22 equals halfword 0x3c of the record
 * FUN_a013cd4c(port). When one is found, the rows after i are searched, wrapping to row 0 at the end: a row whose
 * halfword 0x22 equals that value again gives no result, the first row whose halfword 0x22 has the same high byte
 * is selected. For a selected row, FUN_a013f284(port, row) copies it into the record (defined here, inlined) and
 * FUN_a01542c4(p + 6) is tail-called.
 * Source form: the selected row is an unsigned int compared through an unsigned char cast; the found flag is
 * tested 'found == 1' (block order); the comparisons put the record value first.
 */
struct Row {
    unsigned char k;
    unsigned char pad1;
    unsigned short h2;
    unsigned char pad4[6];
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
extern unsigned char FUN_a0142e8c(unsigned int);
extern void FUN_a01542c4(void *m);

static void FUN_a013f284(unsigned char port, unsigned char idx)
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

void FUN_a013fbe8(unsigned char port)
{
    struct Out *p = FUN_a013cd4c(port);
    struct Out *q;
    unsigned char i, j, found;
    unsigned int idx;

    if (FUN_a0142e8c(port) == 5)
        return;
    q = FUN_a013cd4c(port);
    found = 0;
    for (i = 0; DAT_001a5a16[i].h2 != 0xffff; i++)
        if (q->h3c == DAT_001a5a16[i].h22) {
            found = 1;
            break;
        }
    if (found == 1) {
        for (j = i + 1; ; j++) {
            if (DAT_001a5a16[j].h2 == 0xffff)
                j = 0;
            if (q->h3c == DAT_001a5a16[j].h22) {
                idx = 0xff;
                break;
            }
            if (q->h3c >> 8 == DAT_001a5a16[j].h22 >> 8) {
                idx = j;
                break;
            }
        }
    } else
        idx = 0xff;
    if ((unsigned char)idx == 0xff)
        return;
    FUN_a013f284(port, idx);
    FUN_a01542c4((unsigned char *)p + 6);
}
