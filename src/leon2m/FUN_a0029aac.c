/* leon2m FUN_a0029aac @ 0xa0029aac-0xa0029bc4 (70 words), flags -mcpu=v8 -O3 -g -msoft-float (with plain
 * -O3 -g, loop.c hoists the shift constant 1 into %l1, as in the twin FUN_a0029bc4).
 * Code facts: interrupt dispatcher, twin of src/leon2m/FUN_a0029bc4.c with 4/0x74/0x3c/table +0x80:
 * FUN_a002c268(0x9f000090, 0, 4); FUN_a002c268(0x9f020028, 4, 4); t1 = FUN_a002c250(0x9f020074);
 * t2 = FUN_a002c250(0x9f02003c); pending = t1 & ~t2 & 0xffff; l2 = t2 >> 16; for i = 0..3 (4 hooks) with
 * bit = 1 << i set in pending and a non-zero hook at 0xa802b170 + 0x80 + 4*i: bit set in l2 -> hook() then ack
 * FUN_a002c25c(0x9f020074, bit); else ack first, then hook() (re-read after the ack call). Then
 * FUN_a002c25c(0x9f020034, 4), FUN_a002c25c(0x9f00009c, 4), FUN_a002c268(0x9f020028, 0, 4),
 * tail FUN_a002c268(0x9f000090, 4, 4).
 * Source form: the hook table pointer is a constant, as in the twin. Aids: none.
 */
extern unsigned int FUN_a002c250(unsigned int addr);
extern void FUN_a002c25c(unsigned int addr, unsigned int value);
extern unsigned int FUN_a002c268(unsigned int addr, unsigned int value, unsigned int count);

unsigned int FUN_a0029aac(void)
{
    unsigned int t1, t2, l0, l2;
    unsigned int *table;
    unsigned int i1;

    FUN_a002c268(0x9f000090, 0, 4);
    FUN_a002c268(0x9f020028, 4, 4);

    t1 = FUN_a002c250(0x9f020074);
    t2 = FUN_a002c250(0x9f02003c);
    l0 = t1 & ~t2;
    l0 &= 0xffff;
    l2 = (t2 >> 16) & 0xffff;

    table = (unsigned int *)0xa802b170;
    i1 = 0;
    do {
        unsigned int mask = 1 << i1;
        if ((mask & l0) != 0) {
            if (table[i1 + 0x20] != 0) {
                if ((mask & l2) != 0) {
                    ((void (*)(void))table[i1 + 0x20])();
                    FUN_a002c25c(0x9f020074, mask);
                } else {
                    FUN_a002c25c(0x9f020074, mask);
                    ((void (*)(void))table[i1 + 0x20])();
                }
            }
        }
        i1++;
    } while (i1 <= 3);

    FUN_a002c25c(0x9f020034, 4);
    FUN_a002c25c(0x9f00009c, 4);
    FUN_a002c268(0x9f020028, 0, 4);
    return FUN_a002c268(0x9f000090, 4, 4);
}
