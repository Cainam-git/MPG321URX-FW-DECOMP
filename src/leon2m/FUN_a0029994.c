/* leon2m FUN_a0029994 @ 0xa0029994-0xa0029aac (70 words), flags -mcpu=v8 -O3 -g -msoft-float (with plain
 * -O3 -g, loop.c hoists the shift constant 1 into %l1, as in the twins FUN_a0029bc4 / FUN_a0029aac).
 * Code facts: twin of src/leon2m/FUN_a0029bc4.c with bit 2 / status 0x9f020070 /
 * mask 0x9f020038 / hook table 0xa802b170 + 0x40, 6 sources: FUN_a002c268(0x9f000090, 0, 2);
 * FUN_a002c268(0x9f020028, 2, 2); t1 = FUN_a002c250(0x9f020070); t2 = FUN_a002c250(0x9f020038);
 * pending = t1 & ~t2 & 0xffff; l2 = t2 >> 16; for i = 0..5 with bit = 1 << i set in pending and a non-zero hook:
 * bit set in l2 -> hook() then ack FUN_a002c25c(0x9f020070, bit); else ack first, then hook() (re-read after the
 * call). Then FUN_a002c25c(0x9f020034, 2), FUN_a002c25c(0x9f00009c, 2), FUN_a002c268(0x9f020028, 0, 2),
 * tail FUN_a002c268(0x9f000090, 2, 2).
 * Source form: the same form as the twin FUN_a0029bc4. Aids: none.
 */
extern unsigned int FUN_a002c250(unsigned int addr);
extern void FUN_a002c25c(unsigned int addr, unsigned int value);
extern void FUN_a002c268(volatile unsigned int *p, unsigned int v, unsigned int mask);

void FUN_a0029994(void)
{
    unsigned int t1, t2, l0, l2;
    unsigned int *table;
    unsigned int i1;

    FUN_a002c268((volatile unsigned int *)0x9f000090, 0, 2);
    FUN_a002c268((volatile unsigned int *)0x9f020028, 2, 2);

    t1 = FUN_a002c250(0x9f020070);
    t2 = FUN_a002c250(0x9f020038);
    l0 = t1 & ~t2;
    l0 &= 0xffff;
    l2 = (t2 >> 16) & 0xffff;

    table = (unsigned int *)0xa802b170;
    i1 = 0;
    do {
        unsigned int mask = 1 << i1;
        if ((mask & l0) != 0) {
            if (table[i1 + 0x10] != 0) {
                if ((mask & l2) != 0) {
                    ((void (*)(void))table[i1 + 0x10])();
                    FUN_a002c25c(0x9f020070, mask);
                } else {
                    FUN_a002c25c(0x9f020070, mask);
                    ((void (*)(void))table[i1 + 0x10])();
                }
            }
        }
        i1++;
    } while (i1 <= 5);

    FUN_a002c25c(0x9f020034, 2);
    FUN_a002c25c(0x9f00009c, 2);
    FUN_a002c268((volatile unsigned int *)0x9f020028, 0, 2);
    FUN_a002c268((volatile unsigned int *)0x9f000090, 2, 2);
}
