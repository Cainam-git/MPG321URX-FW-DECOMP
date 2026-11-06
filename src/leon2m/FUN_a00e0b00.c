/* leon2m FUN_a00e0b00 @ 0xa00e0b00-0xa00e0ba8 (42 words), flags -mcpu=v8 -O3 -g.
 * reg = low byte of DAT_a8026428[idx]. The block bases 0xcf022800 / 0xcf022c00 / 0xcf023000 are a local 3-word
 * table; p = base[phy] + reg * 4, b = base[phy]. When the cached page byte DAT_a8025d10[phy] is not 3, 3 is
 * written to the word at b + 0x3f8, the table is filled again by phy_tab and 3 is stored into the cache byte.
 * Returns the OR of the words at p + i * 4 shifted left by i * 8 (i = 0..7, 64-bit shift via __ashldi3 at
 * 0xa0155104).
 * Caller: FUN_a00e4f8c.
 * Source form: phy_tab is called again after the page-register write as in FUN_a00e02ec / FUN_a00e0514 (its
 * stores are removed by the compiler as repeats of the stored values); the first fill is written in place
 * (through phy_tab the block-0 schedule differs). p is computed from base[phy] directly and b = base[phy] is
 * read again after it (the fw order at 0xa00e0b3c-0xa00e0b4c: add of the table address, ldub of the cache byte,
 * sll of the offset, then ld of the base); page = 3 is a local used for the test, the write and the cache store.
 */
extern unsigned int DAT_a8026428[];
extern unsigned char DAT_a8025d10[];

static void phy_tab(unsigned int *t)
{
    t[0] = 0xcf022800;
    t[1] = 0xcf022c00;
    t[2] = 0xcf023000;
}

unsigned long long FUN_a00e0b00(int phy, int idx)
{
    unsigned char reg = DAT_a8026428[idx];
    unsigned int base[3];
    unsigned int b;
    unsigned int p;
    unsigned long long v;
    unsigned int i;
    unsigned int page;

    base[0] = 0xcf022800;
    base[1] = 0xcf022c00;
    base[2] = 0xcf023000;
    p = base[phy] + reg * 4;
    b = base[phy];
    v = 0;
    i = 0;
    page = 3;
    if (DAT_a8025d10[phy] != page) {
        *(volatile unsigned long *)(b + 0x3f8) = page;
        phy_tab(base);
        DAT_a8025d10[phy] = page;
    }
    for (; i < 8; i++)
        v |= (unsigned long long)*(volatile unsigned long *)((p + (i << 2))) << (i * 8);
    return v;
}
