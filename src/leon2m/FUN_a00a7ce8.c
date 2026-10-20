/* leon2m FUN_a00a7ce8 @ 0xa00a7ce8 (-mcpu=v8 -O2 -g)
 * The function performs a series of register writes through two helper functions in a loop (5 to 20 inclusive), then does one final write and a cleanup call. Ghidra types the helper parameters `undefined1`/`undefined2`; int types with the default promotions give the matching code.
 */
extern int func_0x4008e2a4(void); /* 0x4008e2a4 */
extern void FUN_a0146b20(int a, int b, int c, int d, int e, int f); /* 0xa0146b20 */
extern void FUN_a0146a80(int a, int b, int c, int d, int e); /* 0xa0146a80 */
extern void FUN_a0146c40(int a, int b, int c); /* 0xa0146c40 */

void FUN_a00a7ce8(void)
{
    unsigned char i;
    unsigned int j;

    func_0x4008e2a4();
    i = 5;
    j = 5;
    do {
        FUN_a0146b20(0, 0x13, j, 0x13, 0, 0);
        FUN_a0146a80(0x13, j, 0x13, 0x792, 0);
        i++;
        j = i & 0xff;
    } while (j <= 0x14);
    FUN_a0146b20(0, 0x1c, 0x15, 2, 0, 0);
    FUN_a0146c40(5, 0, 0);
}
