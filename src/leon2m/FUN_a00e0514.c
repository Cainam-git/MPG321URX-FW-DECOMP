/* leon2m FUN_a00e0514 @ 0xa00e0514-0xa00e05d8 (49 words), flags -mcpu=v8 -O3.
 * Reads register addr of register block phy (0..2) and returns it ANDed with mask: page = bits 8..11 of addr and
 * a = addr & 0xff are taken first; phy > 2 calls FUN_a00df80c, FUN_a00e0bd8 and prints string 0x199478 with phy,
 * then continues. The block bases 0xcf022800 / 0xcf022c00 / 0xcf023000 are a local 3-word table filled by
 * phy_tab; b = base[phy]. When the cached page byte DAT_a8025d10[phy] differs from page, page is written to the
 * word at b + 0x3f8 and stored into the cache byte. v = word at b + a * 4 & mask; when DAT_a802b550 is non-zero,
 * string 0x199450 is printed with (phy, addr, v). Same form as FUN_a00e02ec.
 * Source form: phy_tab is called again after the page-register write; in this function its stores are removed by
 * the compiler as repeats of the stored values. The same re-stores of the three bases are executed by the
 * firmware in FUN_a00e03b0 (0xa00e0418-0xa00e0420) and FUN_a00e05d8 (0xa00e068c, 0xa00e06e8, 0xa00e06f0).
 * The register accesses are 'volatile unsigned long'; the offset a * 4 is computed before the cache test.
 * Built without -g (no nop after the last call).
 */
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a00df80c(void);
extern void FUN_a00e0bd8(void);
extern unsigned char DAT_a8025d10[];
extern unsigned int DAT_a802b550;
extern const char s_00199450[], s_00199478[];

static void phy_tab(unsigned int *t)
{
    t[0] = 0xcf022800;
    t[1] = 0xcf022c00;
    t[2] = 0xcf023000;
}

unsigned int FUN_a00e0514(int phy, unsigned int addr, unsigned int mask)
{
    unsigned int b;
    unsigned int page = (addr >> 8) & 0xf;
    unsigned int a = addr & 0xff;
    unsigned int v;
    unsigned int off;

    if (phy > 2) {
        FUN_a00df80c();
        FUN_a00e0bd8();
        FUN_a00df170(s_00199478, phy);
    }
    {
        unsigned int base[3];

        phy_tab(base);
        b = base[phy];
        off = a * 4;
        if (DAT_a8025d10[phy] != page) {
            *(volatile unsigned long *)(b + 0x3f8) = page;
            phy_tab(base);
            DAT_a8025d10[phy] = page;
        }
        v = *(volatile unsigned long *)(b + off) & mask;
    }
    if (DAT_a802b550 != 0)
        FUN_a00df170(s_00199450, phy, addr, v);
    return v;
}
