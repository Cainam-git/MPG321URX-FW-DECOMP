/* leon2m FUN_a00e03b0 @ 0xa00e03b0-0xa00e0514 (89 words), flags -mcpu=v8 -O3.
 * Writes val to register addr of register block phy (0..2): page = bits 8..11 of addr and a = addr & 0xff are
 * taken first; phy > 2 calls FUN_a00df80c, FUN_a00e0bd8 and prints string 0x199430 with phy, then continues.
 * The block bases 0xcf022800 / 0xcf022c00 / 0xcf023000 are a local 3-word table filled by phy_tab;
 * b = base[phy]. a == 0xfe: when the cached page byte DAT_a8025d10[phy] differs from val, val is written to the
 * word at b + 0x3f8 and stored into the cache byte. Otherwise, when the cache byte differs from page, page is
 * written to the word at b + 0x3f8, the table is filled again and page is stored into the cache byte; then val is
 * written to the word at b + a * 4. When DAT_a802b550 is non-zero, that word is read again (cache byte read
 * first, table filled, page written when the cache byte differs) and string 0x199410 is printed with
 * (phy, addr, value).
 * Source form: the table re-fill after the page-register write is the one the firmware executes at
 * 0xa00e0418-0xa00e0420; in the DAT_a802b550 path the same re-fill sits before the page-register write and its
 * stores are removed by the compiler as repeats of the stored values (as in FUN_a00e02ec / FUN_a00e0514).
 * Compiler aid: __builtin_expect on the page test of the write path (no code).
 * The register accesses are 'volatile unsigned long'. Built without -g (no nop after the last call).
 */
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a00df80c(void);
extern void FUN_a00e0bd8(void);
extern unsigned char DAT_a8025d10[];
extern unsigned int DAT_a802b550;
extern const char s_00199410[], s_00199430[];

static void phy_tab(unsigned int *t)
{
    t[0] = 0xcf022800;
    t[1] = 0xcf022c00;
    t[2] = 0xcf023000;
}

void FUN_a00e03b0(int phy, unsigned int addr, unsigned int val)
{
    unsigned int b;
    unsigned int page = (addr >> 8) & 0xf;
    unsigned int a = addr & 0xff;
    unsigned char cur;
    unsigned int v;
    unsigned int off;
    unsigned int base[3];

    if (phy > 2) {
        FUN_a00df80c();
        FUN_a00e0bd8();
        FUN_a00df170(s_00199430, phy);
    }
    phy_tab(base);
    b = base[phy];
    off = a * 4;
    if (a == 0xfe) {
        if (DAT_a8025d10[phy] != val) {
            *(volatile unsigned long *)(b + 0x3f8) = val;
            DAT_a8025d10[phy] = val;
        }
    } else {
        if (__builtin_expect(DAT_a8025d10[phy] != page, 1)) {
            *(volatile unsigned long *)(b + 0x3f8) = page;
            phy_tab(base);
            DAT_a8025d10[phy] = page;
        }
        *(volatile unsigned long *)(b + off) = val;
    }
    if (DAT_a802b550 != 0) {
        off = (addr & 0xff) * 4;
        cur = DAT_a8025d10[phy];
        phy_tab(base);
        b = base[phy];
        if (cur != page) {
            phy_tab(base);
            b = base[phy];
            *(volatile unsigned long *)(b + 0x3f8) = page;
            DAT_a8025d10[phy] = page;
        }
        v = *(volatile unsigned long *)(b + off);
        FUN_a00df170(s_00199410, phy, addr, v);
    }
}
