/* leon2m FUN_a0029cdc @ 0xa0029cdc, flags -mcpu=v8 -O3 -g -msoft-float.
 * Twin of src/leon2m/FUN_a0029bc4.c with bit 0x10 / status 0x9f02007c / mask 0x9f020044 / hook table
 * 0xa802b170 + 0x100, 7 sources: FUN_a002c268(0x9f000090, 0, 0x10); FUN_a002c268(0x9f020028, 0x10, 0x10);
 * t1 = FUN_a002c250(0x9f02007c); t2 = FUN_a002c250(0x9f020044); pending = t1 & ~t2 & 0xffff; l2 = t2 >> 16;
 * for i = 0..6 with bit = 1 << i set in pending and a non-zero hook at 0xa802b170 + 0x100 + 4*i: bit set in l2 ->
 * hook() then ack FUN_a002c25c(0x9f02007c, bit); else ack first, then hook(). Then FUN_a002c25c(0x9f020034, 0x10),
 * FUN_a002c25c(0x9f00009c, 0x10), FUN_a002c268(0x9f020028, 0, 0x10), and returns the result of the tail call
 * FUN_a002c268(0x9f000090, 0x10, 0x10). Aids: none.
 */
extern unsigned int FUN_a002c250(unsigned int addr);
extern void FUN_a002c25c(unsigned int addr, unsigned int value);
extern unsigned int FUN_a002c268(unsigned int addr, unsigned int value, unsigned int count);

unsigned int FUN_a0029cdc(void)
{
    unsigned int t1, t2, l0, l2;
    unsigned int *table;
    unsigned int i1;

    FUN_a002c268(0x9f000090, 0, 0x10);
    FUN_a002c268(0x9f020028, 0x10, 0x10);

    t1 = FUN_a002c250(0x9f02007c);
    t2 = FUN_a002c250(0x9f020044);
    l0 = t1 & ~t2;
    l0 &= 0xffff;
    l2 = (t2 >> 16) & 0xffff;

    table = (unsigned int *)0xa802b170;
    i1 = 0;
    do {
        unsigned int mask = 1 << i1;
        if ((mask & l0) != 0) {
            if (table[i1 + 0x40] != 0) {
                if ((mask & l2) != 0) {
                    ((void (*)(void))table[i1 + 0x40])();
                    FUN_a002c25c(0x9f02007c, mask);
                } else {
                    FUN_a002c25c(0x9f02007c, mask);
                    ((void (*)(void))table[i1 + 0x40])();
                }
            }
        }
        i1++;
    } while (i1 <= 6);

    FUN_a002c25c(0x9f020034, 0x10);
    FUN_a002c25c(0x9f00009c, 0x10);
    FUN_a002c268(0x9f020028, 0, 0x10);
    return FUN_a002c268(0x9f000090, 0x10, 0x10);
}
