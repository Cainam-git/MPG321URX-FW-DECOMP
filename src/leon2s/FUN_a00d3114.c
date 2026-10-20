/*
 * FUN_a00d3114 (leon2s, 0xa00d3114-0xa00d31f8, 228 bytes), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/57.
 * Code facts: a word v (stack, cleared first: fw 'clr [%fp-12]') = ROM read func_0xa0f71528(0xd0013f60);
 * field writes func_0xa0f714b8(&v, hi, lo, val): (0,0) = 1, (0x10,8) = 0, write back with
 * func_0xa0f71534(0xd0013f60, v). Then for i = 0..0x100: field (0x10,8) = i, write 0xd0013f60; for
 * i != 0x100 write the u16 DAT_a8077a08[i] to 0xd0013f68 (the draft indexed i*2: BEHAVIOUR bug);
 * for i == 0x100 read 0xd0013f6c, set field (0xf,0) = DAT_a8077a08[0x100], write it back. Returns 1.
 * The ROM read takes the register address (the draft had no argument). The '!= 0x100' arm is first.
 * Aids: none.
 */
extern unsigned int func_0xa0f71528(unsigned int);
extern void func_0xa0f71534(unsigned int, unsigned int);
extern void func_0xa0f714b8(unsigned int *, unsigned int, unsigned int, unsigned int);
extern unsigned short DAT_a8077a08[];

int FUN_a00d3114(void)
{
    unsigned int v = 0;
    unsigned int i;

    v = func_0xa0f71528(0xd0013f60);
    func_0xa0f714b8(&v, 0, 0, 1);
    func_0xa0f714b8(&v, 0x10, 8, 0);
    func_0xa0f71534(0xd0013f60, v);
    for (i = 0; i <= 0x100; i++) {
        func_0xa0f714b8(&v, 0x10, 8, i);
        func_0xa0f71534(0xd0013f60, v);
        if (i != 0x100) {
            func_0xa0f71534(0xd0013f68, DAT_a8077a08[i]);
        } else {
            v = func_0xa0f71528(0xd0013f6c);
            func_0xa0f714b8(&v, 0xf, 0, DAT_a8077a08[0x100]);
            func_0xa0f71534(0xd0013f6c, v);
        }
    }
    return 1;
}
