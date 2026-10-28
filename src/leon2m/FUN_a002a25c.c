/* leon2m FUN_a002a25c @ 0xa002a25c-0xa002a344 (58 words), flags -mcpu=v8 -O3 -g -msoft-float. No direct callers.
 * Built like FUN_a0029994 / FUN_a002a614, for bit 0x200 and one source: FUN_a002c268(0x9f000090, 0, 0x200),
 * FUN_a002c268(0x9f020028, 0x200, 0x200); t1 = FUN_a002c250(0x9f020090), t2 = FUN_a002c250(0x9f020058);
 * pending = t1 & ~t2 & 0xffff, l2 = t2 >> 16. Source 0: with bit 1 set in pending and a non-zero hook in the word
 * table at 0xa802b170 (entry 0x90): when the bit is also set in l2 the hook runs and the bit is acknowledged with
 * FUN_a002c25c(0x9f020090, bit) afterwards, otherwise the bit is acknowledged first. Then FUN_a002c25c(0x9f020034,
 * 0x200), FUN_a002c25c(0x9f00009c, 0x200), FUN_a002c268(0x9f020028, 0, 0x200) and the tail call
 * FUN_a002c268(0x9f000090, 0x200, 0x200).
 * Source form: the siblings' loop over the sources (here one pass); the function is void and FUN_a002c268 is
 * declared with its defined prototype (void, register pointer first).
 */
extern unsigned int FUN_a002c250(unsigned int addr);
extern void FUN_a002c25c(unsigned int addr, unsigned int value);
extern void FUN_a002c268(volatile unsigned int *p, unsigned int v, unsigned int mask);

void FUN_a002a25c(void)
{
    unsigned int t1, t2, l0, l2;
    unsigned int *table;
    unsigned int i1;

    FUN_a002c268((volatile unsigned int *)0x9f000090, 0, 0x200);
    FUN_a002c268((volatile unsigned int *)0x9f020028, 0x200, 0x200);

    t1 = FUN_a002c250(0x9f020090);
    t2 = FUN_a002c250(0x9f020058);
    l0 = t1 & ~t2;
    l0 &= 0xffff;
    l2 = (t2 >> 16) & 0xffff;

    table = (unsigned int *)0xa802b170;
    i1 = 0;
    do {
        unsigned int mask = 1 << i1;
        if ((mask & l0) != 0) {
            if (table[i1 + 0x90] != 0) {
                if ((mask & l2) != 0) {
                    ((void (*)(void))table[i1 + 0x90])();
                    FUN_a002c25c(0x9f020090, mask);
                } else {
                    FUN_a002c25c(0x9f020090, mask);
                    ((void (*)(void))table[i1 + 0x90])();
                }
            }
        }
        i1++;
    } while (i1 <= 0);

    FUN_a002c25c(0x9f020034, 0x200);
    FUN_a002c25c(0x9f00009c, 0x200);
    FUN_a002c268((volatile unsigned int *)0x9f020028, 0, 0x200);
    FUN_a002c268((volatile unsigned int *)0x9f000090, 0x200, 0x200);
}
