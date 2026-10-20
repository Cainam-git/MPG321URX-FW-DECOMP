/* leon2m FUN_a00eecd0 @ 0xa00eecd0-0xa00eef3c (155 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/155 mismatches.
 * Code facts: unit p, flag full. FUN_a00dffb4(2, p, -1); FUN_a00dfc50(p, 2, 4). If full != 0:
 * v = FUN_a0115584(0 / 1 / 2) for p == 0 / 1 / 2 (literal args, one shared call), a -1 result
 * becomes 0x10; any other p: FUN_a00df80c(); FUN_a00e0bc0(); log FUN_a00df170(string 0x199fc8,
 * p, 0x10) and v stays 0x10; then FUN_a00e05d8(p, 0x110, 0x1f, v); FUN_a00dffa4(1). Always:
 * e05d8 (p, 1, 0x40, 0x40), (p, 0, 2, 2); if full == 0: (p, 0x110, 0x1f, 0x10); then (0x24d, 0xff,
 * 2), (0x24c, 0xff, 0xfc), (0x243, 0x1f, 0x10), (0x240, 0x80, 0), (0x240, 0x20, 0x20);
 * FUN_a00dffa4(2); poll until bit 5 of FUN_a00e02ec(p, 0x24a); a = FUN_a00e0514(p, 0x247, 0x1f),
 * b = FUN_a00e0514(p, 0x248, 0x1f); e05d8 0x241 = a & 0xff, 0x242 = b & 0xff, 0x274 = a, 0x270 = b,
 * 0x275 = a, 0x271 = b (all & 0x1f masks), (0x240, 0x80, 0x80), (0x277, 0xc0, 0xc0),
 * (0x240, 0x20, 0). Returns 0.
 * Fixes vs the autoc draft (83.23): BEHAVIOUR: 0x241/0x274/0x275 get the 0x247 read and
 * 0x242/0x270/0x271 the 0x248 read (draft swapped them); FUN_a0115584 takes the index (its body
 * reads %i0); returns int 0. Source form: an if/else-if chain with one call per arm (crossjumped
 * in the fw); 'v = 0x10' before 'if (full != 0)' (fw fills the first be delay slot with it;
 * inside the arm gives 97.44). Aids: none.
 */
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a00df80c(void);
extern void FUN_a00dfc50(unsigned int, unsigned int, unsigned int);
extern void FUN_a00dffa4(unsigned int);
extern void FUN_a00dffb4(unsigned int, unsigned int, unsigned int);
extern unsigned int FUN_a00e02ec(unsigned int, unsigned int);
extern unsigned int FUN_a00e0514(unsigned int, unsigned int, unsigned int);
extern void FUN_a00e05d8(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e0bc0(void);
extern int FUN_a0115584(int);
extern const char s_00199fc8[];

int FUN_a00eecd0(unsigned int p, int full)
{
    int v;
    int n;
    unsigned int a, b;

    FUN_a00dffb4(2, p, 0xffffffff);
    FUN_a00dfc50(p, 2, 4);
    v = 0x10;
    if (full != 0) {
        if (p == 0)
            v = FUN_a0115584(0);
        else if (p == 1)
            v = FUN_a0115584(1);
        else if (p == 2)
            v = FUN_a0115584(2);
        else {
            FUN_a00df80c();
            FUN_a00e0bc0();
            FUN_a00df170(s_00199fc8, p, 0x10);
        }
        if (v == -1)
            v = 0x10;
        FUN_a00e05d8(p, 0x110, 0x1f, v);
        FUN_a00dffa4(1);
    }
    FUN_a00e05d8(p, 1, 0x40, 0x40);
    FUN_a00e05d8(p, 0, 2, 2);
    if (full == 0)
        FUN_a00e05d8(p, 0x110, 0x1f, 0x10);
    FUN_a00e05d8(p, 0x24d, 0xff, 2);
    FUN_a00e05d8(p, 0x24c, 0xff, 0xfc);
    FUN_a00e05d8(p, 0x243, 0x1f, 0x10);
    FUN_a00e05d8(p, 0x240, 0x80, 0);
    FUN_a00e05d8(p, 0x240, 0x20, 0x20);
    FUN_a00dffa4(2);
    while (!(FUN_a00e02ec(p, 0x24a) & 0x20))
        ;
    a = FUN_a00e0514(p, 0x247, 0x1f);
    b = FUN_a00e0514(p, 0x248, 0x1f);
    FUN_a00e05d8(p, 0x241, 0x1f, a & 0xff);
    FUN_a00e05d8(p, 0x242, 0x1f, b & 0xff);
    FUN_a00e05d8(p, 0x274, 0x1f, a & 0xff);
    FUN_a00e05d8(p, 0x270, 0x1f, b & 0xff);
    FUN_a00e05d8(p, 0x275, 0x1f, a & 0xff);
    FUN_a00e05d8(p, 0x271, 0x1f, b & 0xff);
    FUN_a00e05d8(p, 0x240, 0x80, 0x80);
    FUN_a00e05d8(p, 0x277, 0xc0, 0xc0);
    FUN_a00e05d8(p, 0x240, 0x20, 0);
    return 0;
}
