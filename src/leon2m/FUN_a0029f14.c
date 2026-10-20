/* leon2m FUN_a0029f14 @ 0xa0029f14-0xa002a02c (70 words), flags -mcpu=v8 -O3 -g -msoft-float (plain -O3 -g: loop.c hoists the shift constant
 * 1 into %l1, as in the twins FUN_a0029bc4 / FUN_a0029aac). BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 70 words (with -msoft-float).
 * Code facts: interrupt dispatcher, twin of src/leon2m/FUN_a0029bc4.c with bit 0x40 / status 0x9f020084 / mask 0x9f02004c /
 * hook table 0xa802b170 + 0x180, 7 sources: FUN_a002c268(0x9f000090, 0, 0x40); FUN_a002c268(0x9f020028, 0x40, 0x40);
 * t1 = FUN_a002c250(0x9f020084); t2 = FUN_a002c250(0x9f02004c); pending = t1 & ~t2 & 0xffff; l2 = t2 >> 16; for i = 0..6
 * with bit = 1 << i set in pending and a non-zero hook: bit set in l2 -> hook() then ack FUN_a002c25c(0x9f020084, bit);
 * else ack first, then hook() (re-read after the call). Then FUN_a002c25c(0x9f020034, 0x40),
 * FUN_a002c25c(0x9f00009c, 0x40), FUN_a002c268(0x9f020028, 0, 0x40), tail FUN_a002c268(0x9f000090, 0x40, 0x40).
 * Fix vs the autoc draft: written from the accepted twin's form (BEHAVIOUR in the draft family: status
 * addresses, masks and loop bounds). Aids: none.
 */
extern unsigned int FUN_a002c250(unsigned int addr);
extern void FUN_a002c25c(unsigned int addr, unsigned int value);
extern unsigned int FUN_a002c268(unsigned int addr, unsigned int value, unsigned int count);

unsigned int FUN_a0029f14(void)
{
    unsigned int t1, t2, l0, l2;
    unsigned int *table;
    unsigned int i1;

    FUN_a002c268(0x9f000090, 0, 0x40);
    FUN_a002c268(0x9f020028, 0x40, 0x40);

    t1 = FUN_a002c250(0x9f020084);
    t2 = FUN_a002c250(0x9f02004c);
    l0 = t1 & ~t2;
    l0 &= 0xffff;
    l2 = (t2 >> 16) & 0xffff;

    table = (unsigned int *)0xa802b170;
    i1 = 0;
    do {
        unsigned int mask = 1 << i1;
        if ((mask & l0) != 0) {
            if (table[i1 + 0x60] != 0) {
                if ((mask & l2) != 0) {
                    ((void (*)(void))table[i1 + 0x60])();
                    FUN_a002c25c(0x9f020084, mask);
                } else {
                    FUN_a002c25c(0x9f020084, mask);
                    ((void (*)(void))table[i1 + 0x60])();
                }
            }
        }
        i1++;
    } while (i1 <= 6);

    FUN_a002c25c(0x9f020034, 0x40);
    FUN_a002c25c(0x9f00009c, 0x40);
    FUN_a002c268(0x9f020028, 0, 0x40);
    return FUN_a002c268(0x9f000090, 0x40, 0x40);
}
