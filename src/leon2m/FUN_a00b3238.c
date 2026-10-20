/* leon2m FUN_a00b3238 @ 0xa00b3238 (-mcpu=v8 -O2 -g)
 * Calls FUN_a00a8c88, FUN_a0146b50(0x111, 0) and FUN_a0146b6c(0, 0), then for index 0..2 passes
 * FUN_a00a3844(0x18F52C, index) to FUN_a00a31a4(0, 0x2A, index * 2 + 6, 1, value, 0). The loop counter is an
 * unsigned char that is incremented and masked with 0xFF before the comparison; the address is written as
 * 0x18f400 + 0x12c.
 */
extern void FUN_a00a8c88(void); /* 0xa00a8c88 */
extern void FUN_a0146b50(unsigned int, unsigned int); /* 0xa0146b50 */
extern void FUN_a0146b6c(unsigned int, unsigned int); /* 0xa0146b6c */
extern unsigned int FUN_a00a3844(int, unsigned short); /* 0xa00a3844 */
extern void FUN_a00a31a4(int, int, int, int, unsigned int, int); /* 0xa00a31a4 */

void FUN_a00b3238(void)
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
        ret = FUN_a00a3844(0x18f400 + 0x12c, index);
        FUN_a00a31a4(0, 0x2a, index * 2 + 6, 1, ret, 0), counter++;
        index = counter & 0xff;
    } while (index <= 2);
}
