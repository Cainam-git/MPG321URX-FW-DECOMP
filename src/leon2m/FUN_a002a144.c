/* leon2m FUN_a002a144 @ 0xa002a144  MATCH (-mcpu=v8 -O2 -g)
 * Calls FUN_a002c268(0x9F000090, 0, 0x100) and FUN_a002c268(0x9F020028, 0x100, 0x100), then reads the words at
 * 0x9F02008C (t1) and 0x9F020054 (t2) through FUN_a002c250. For bits n = 0 and 1 of (t1 & ~t2) & 0xFFFF: when the
 * handler word table[0x80 + n] at 0xA802B170 is non-zero, the handler is called and bit n is written to 0x9F02008C
 * through FUN_a002c25c; the handler runs first when bit n is also set in t2 >> 16, after the write otherwise. Ends
 * with FUN_a002c25c(0x9F020034, 0x100), FUN_a002c25c(0x9F00009C, 0x100), FUN_a002c268(0x9F020028, 0, 0x100) and
 * FUN_a002c268(0x9F000090, 0x100, 0x100), whose result is returned.
 */
extern unsigned int FUN_a002c250(unsigned int addr);
extern void FUN_a002c25c(unsigned int addr, unsigned int value);
extern unsigned int FUN_a002c268(unsigned int addr, unsigned int value, unsigned int count);

unsigned int FUN_a002a144(void)
{
    unsigned int t1, t2, l0, l2;
    unsigned int *table;
    unsigned int i1;

    FUN_a002c268(0x9f000090, 0, 0x100);
    FUN_a002c268(0x9f020028, 0x100, 0x100);

    t1 = FUN_a002c250(0x9f02008c);
    t2 = FUN_a002c250(0x9f020054);
    l0 = t1 & ~t2;
    l0 &= 0xffff;
    l2 = (t2 >> 16) & 0xffff;

    table = (unsigned int *)0xa802b170;
    i1 = 0;
    do {
        unsigned int mask = 1 << i1;
        if ((mask & l0) != 0) {
            if (table[i1 + 0x80] != 0) {
                if ((mask & l2) != 0) {
                    ((void (*)(void))table[i1 + 0x80])();
                    FUN_a002c25c(0x9f02008c, mask);
                } else {
                    FUN_a002c25c(0x9f02008c, mask);
                    ((void (*)(void))table[i1 + 0x80])();
                }
            }
        }
        i1++;
    } while (i1 <= 1);

    FUN_a002c25c(0x9f020034, 0x100);
    FUN_a002c25c(0x9f00009c, 0x100);
    FUN_a002c268(0x9f020028, 0, 0x100);
    return FUN_a002c268(0x9f000090, 0x100, 0x100);
}
