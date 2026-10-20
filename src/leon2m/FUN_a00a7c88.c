/* leon2m FUN_a00a7c88 @ 0xa00a7c88  MATCH (-mcpu=v8 -O2 -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern int func_0x4008e2a4(void); /* 0x4008e2a4 */
extern void FUN_a0146b20(int a, int b, int c, int d, int e, int f); /* 0xa0146b20 */
extern void FUN_a0146a80(int a, int b, int c, int d, int e); /* 0xa0146a80 */

void FUN_a00a7c88(void)
{
    unsigned char i;
    unsigned int j;

    func_0x4008e2a4();
    i = 4;
    j = 4;
    do {
        FUN_a0146b20(0, 3, j, 0x10, 0, 0);
        FUN_a0146a80(3, j, 0x10, 0x792, 0);
        i++;
        j = i & 0xff;
    } while (j <= 0xb);
}
