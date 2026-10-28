/* leon2m FUN_a0029df4 @ 0xa0029df4-0xa0029f14 (72 words).
 * Built like FUN_a002a4c4, for bit 0x20. FUN_a002c268(0x9f000090, 0, 0x20) and FUN_a002c268(0x9f020028, 0x20, 0x20)
 * first; then pending = status 0x9f020080 & ~mask 0x9f020048 (low 16 bits), and l2 = the mask's upper 16 bits. For
 * sources 0..15 with their bit set in pending and a non-zero hook in the word table at 0xa802b170 (entries
 * 0x50..0x5f): when the bit is also set in l2 the hook runs and the bit is acknowledged with
 * FUN_a002c25c(0x9f020080, bit) afterwards, otherwise the bit is acknowledged first. Then
 * FUN_a002c25c(0x9f020034, 0x20), FUN_a002c25c(0x9f00009c, 0x20), FUN_a002c268(0x9f020028, 0, 0x20) and the tail
 * call FUN_a002c268(0x9f000090, 0x20, 0x20). Compiled with -msoft-float like FUN_a002a4c4.
 */
extern unsigned int FUN_a002c250(unsigned int addr);
extern void FUN_a002c25c(unsigned int addr, unsigned int value);
extern void FUN_a002c268(volatile unsigned int *p, unsigned int v, unsigned int mask);

void FUN_a0029df4(void)
{
    unsigned int t1, t2, l0, l2;
    unsigned int *table;
    unsigned int i1;

    FUN_a002c268((volatile unsigned int *)0x9f000090, 0, 0x20);
    FUN_a002c268((volatile unsigned int *)0x9f020028, 0x20, 0x20);

    t1 = FUN_a002c250(0x9f020080);
    t2 = FUN_a002c250(0x9f020048);
    l0 = t1 & ~t2;
    l0 &= 0xffff;
    l2 = (t2 >> 16) & 0xffff;

    table = (unsigned int *)0xa802b170;
    i1 = 0;
    do {
        unsigned int mask = 1 << i1;
        if ((mask & l0) != 0) {
            if (table[i1 + 0x50] != 0) {
                if ((mask & l2) != 0) {
                    ((void (*)(void))table[i1 + 0x50])();
                    FUN_a002c25c(0x9f020080, mask);
                } else {
                    FUN_a002c25c(0x9f020080, mask);
                    ((void (*)(void))table[i1 + 0x50])();
                }
            }
        }
        i1++;
    } while (i1 <= 15);

    FUN_a002c25c(0x9f020034, 0x20);
    FUN_a002c25c(0x9f00009c, 0x20);
    FUN_a002c268((volatile unsigned int *)0x9f020028, 0, 0x20);
    FUN_a002c268((volatile unsigned int *)0x9f000090, 0x20, 0x20);
}
