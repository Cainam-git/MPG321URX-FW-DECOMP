/* leon2m FUN_a002a344 @ 0xa002a344-0xa002a45c (70 words).
 * Built like FUN_a0029994, for bit 0x400. FUN_a002c268(0x9f000090, 0, 0x400) and
 * FUN_a002c268(0x9f020028, 0x400, 0x400) first; then pending = status 0x9f020094 & ~mask 0x9f02005c (low 16 bits),
 * and l2 = the mask's upper 16 bits. For sources 0 and 1 with their bit set in pending and a non-zero hook in the
 * word table at 0xa802b170 (entries 0xa0 and 0xa1): when the bit is also set in l2 the hook runs and the bit is
 * acknowledged with FUN_a002c25c(0x9f020094, bit) afterwards, otherwise the bit is acknowledged first. Then
 * FUN_a002c25c(0x9f020034, 0x400), FUN_a002c25c(0x9f00009c, 0x400), FUN_a002c268(0x9f020028, 0, 0x400) and the tail
 * call FUN_a002c268(0x9f000090, 0x400, 0x400). Compiled with -msoft-float like FUN_a0029994 (plain -O3 -g hoists the
 * shift constant).
 */
extern unsigned int FUN_a002c250(unsigned int addr);
extern void FUN_a002c25c(unsigned int addr, unsigned int value);
extern unsigned int FUN_a002c268(unsigned int addr, unsigned int value, unsigned int count);

unsigned int FUN_a002a344(void)
{
    unsigned int t1, t2, l0, l2;
    unsigned int *table;
    unsigned int i1;

    FUN_a002c268(0x9f000090, 0, 0x400);
    FUN_a002c268(0x9f020028, 0x400, 0x400);

    t1 = FUN_a002c250(0x9f020094);
    t2 = FUN_a002c250(0x9f02005c);
    l0 = t1 & ~t2;
    l0 &= 0xffff;
    l2 = (t2 >> 16) & 0xffff;

    table = (unsigned int *)0xa802b170;
    i1 = 0;
    do {
        unsigned int mask = 1 << i1;
        if ((mask & l0) != 0) {
            if (table[i1 + 0xa0] != 0) {
                if ((mask & l2) != 0) {
                    ((void (*)(void))table[i1 + 0xa0])();
                    FUN_a002c25c(0x9f020094, mask);
                } else {
                    FUN_a002c25c(0x9f020094, mask);
                    ((void (*)(void))table[i1 + 0xa0])();
                }
            }
        }
        i1++;
    } while (i1 <= 1);

    FUN_a002c25c(0x9f020034, 0x400);
    FUN_a002c25c(0x9f00009c, 0x400);
    FUN_a002c268(0x9f020028, 0, 0x400);
    return FUN_a002c268(0x9f000090, 0x400, 0x400);
}
