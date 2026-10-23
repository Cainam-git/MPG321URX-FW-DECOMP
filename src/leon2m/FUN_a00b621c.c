/* leon2m FUN_a00b621c @ 0xa00b621c (-mcpu=v8 -O2 -g)
 * Calls FUN_a00a8c88(), FUN_a0146b50(0x111, 0) and FUN_a0146b6c(0, 0), then for i = 0 .. 3 calls FUN_a00a31a4(0,
 * 0x2a, i * 2 + 6, 1, FUN_a00a3844(0x196b24, i), 0). 0x196B24 holds a table of word addresses.
 * Source form: Ghidra's type and symbol names are kept.
 */
extern void FUN_a00a8c88(void); /* 0xa00a8c88 */
extern void FUN_a0146b50(unsigned int, unsigned int); /* 0xa0146b50 */
extern void FUN_a0146b6c(unsigned int, unsigned int); /* 0xa0146b6c */
extern unsigned int FUN_a00a3844(const char *, unsigned int); /* 0xa00a3844 */
extern void FUN_a00a31a4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int); /* 0xa00a31a4 */

void FUN_a00b621c(void)
{
    unsigned char counter;
    unsigned int index;
    unsigned int ret;

    FUN_a00a8c88();
    counter = 0;
    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    index = 0;
    do {
        ret = FUN_a00a3844((const char *)0x196b24, index);
        FUN_a00a31a4(0, 0x2a, index * 2 + 6, 1, ret, 0), counter++;
        index = counter & 0xff;
    } while (index <= 3);
}
