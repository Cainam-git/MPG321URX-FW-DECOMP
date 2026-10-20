/* leon2m FUN_a0029bc4 @ 0xa0029bc4-0xa0029cdc (70 words), flags -mcpu=v8 -O3 -g -msoft-float (plain -O3 -g: 83.10,
 * loop.c hoists the shift constant 1 into %l1; -O2 -g: 43.66). BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 70 words (with -msoft-float).
 * Code facts: interrupt dispatcher, twin of src/leon2m/FUN_a0029cdc.c with 8/0x78/0x40 and 4 sources:
 * FUN_a002c268(0x9f000090, 0, 8); FUN_a002c268(0x9f020028, 8, 8); t1 = FUN_a002c250(0x9f020078);
 * t2 = FUN_a002c250(0x9f020040); pending = t1 & ~t2 & 0xffff; l2 = t2 >> 16; for i = 0..3 with bit = 1 << i
 * set in pending and a non-zero hook at 0xa802b170 + 0xc0 + 4*i: bit set in l2 -> hook() then ack
 * FUN_a002c25c(0x9f020078, bit); else ack first, then hook(). Then FUN_a002c25c(0x9f020034, 8),
 * FUN_a002c25c(0x9f00009c, 8), FUN_a002c268(0x9f020028, 0, 8), tail FUN_a002c268(0x9f000090, 8, 8).
 * Fix vs the autoc draft (78.57): BEHAVIOUR - FUN_a002c250 takes the register address (fw %o0 = 0x9f020078 /
 * 0x9f020040; the draft passed nothing), and the two hook/ack arms were swapped (fw: l2 bit set -> hook first).
 * Aids: none.
 */
extern unsigned int FUN_a002c250(unsigned int addr);
extern void FUN_a002c25c(unsigned int addr, unsigned int value);
extern unsigned int FUN_a002c268(unsigned int addr, unsigned int value, unsigned int count);

unsigned int FUN_a0029bc4(void)
{
    unsigned int t1, t2, l0, l2;
    unsigned int *table;
    unsigned int i1;

    FUN_a002c268(0x9f000090, 0, 8);
    FUN_a002c268(0x9f020028, 8, 8);

    t1 = FUN_a002c250(0x9f020078);
    t2 = FUN_a002c250(0x9f020040);
    l0 = t1 & ~t2;
    l0 &= 0xffff;
    l2 = (t2 >> 16) & 0xffff;

    table = (unsigned int *)0xa802b170;
    i1 = 0;
    do {
        unsigned int mask = 1 << i1;
        if ((mask & l0) != 0) {
            if (table[i1 + 0x30] != 0) {
                if ((mask & l2) != 0) {
                    ((void (*)(void))table[i1 + 0x30])();
                    FUN_a002c25c(0x9f020078, mask);
                } else {
                    FUN_a002c25c(0x9f020078, mask);
                    ((void (*)(void))table[i1 + 0x30])();
                }
            }
        }
        i1++;
    } while (i1 <= 3);

    FUN_a002c25c(0x9f020034, 8);
    FUN_a002c25c(0x9f00009c, 8);
    FUN_a002c268(0x9f020028, 0, 8);
    return FUN_a002c268(0x9f000090, 8, 8);
}
