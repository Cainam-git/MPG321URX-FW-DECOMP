/* leon2m FUN_a0029cdc @ 0xa0029cdc (-mcpu=v8 -O2 -g)
 * This function initializes two hardware register blocks, reads two interrupt status registers, then scans a 6-bit mask (bits 0–5) against two 16-bit masks derived from those registers. For each set bit, it checks a callback table at 0xa802b170+0x100 and conditionally invokes the callback and/or writes an acknowledge register depending on the second mask. After the loop, it clears the status registers and performs a final tail-call write sequence. The main uncertainty is the exact loop bound (7 iterations vs 6) and whether the final call's return value is actually used (the tail-call pattern sug
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
