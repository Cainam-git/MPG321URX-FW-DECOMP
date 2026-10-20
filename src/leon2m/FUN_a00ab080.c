/* leon2m FUN_a00ab080 @ 0xa00ab080  MATCH (-mcpu=v8 -O2 -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern void func_0x4008e2a4(void); /* 0x4008e2a4 */
extern void FUN_a0146a80(int a0, int a1, int a2, int a3, int a4); /* 0xa0146a80 */
extern void FUN_a0146b20(int a0, int a1, int a2, int a3, int a4, int a5); /* 0xa0146b20 */

void FUN_a00ab080(void)
{
    unsigned char l1;
    unsigned int l0;

    func_0x4008e2a4();
    l1 = 5;
    l0 = 5;
    do {
        FUN_a0146a80(1, l0, 0x11, 0x792, 0);
        FUN_a0146b20(0, 1, l0, 0x11, 0, 0);
        l1++;
        l0 = l1 & 0xff;
    } while (l0 <= 0x15);
}
