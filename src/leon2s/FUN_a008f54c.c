/* leon2s FUN_a008f54c @ 0xa008f54c  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical Ghidra C, finished by hand: two 176-byte records at 0xa807d3e4 (was a raw address); flags 0x6a, 0x21,
 * 0x8c set; Ghidra type names kept.
 */
extern unsigned char ARR_a807d3e4[][0xb0];
extern void FUN_a00a65c4(int, int, int);
extern void FUN_a00a67b8(int, int, int, int);
extern void FUN_a008aab0(int, int);
extern void FUN_a00b1794(int);
extern void FUN_a00a8844(int);
extern void FUN_a008f4ec(int);

void FUN_a008f54c(void)
{
    unsigned char i;
    unsigned int j, k;
    unsigned int base = 0xcf00f000;

    FUN_a00a65c4(2, 5, 0xff);
    FUN_a00a65c4(2, 5, 0x10);

    *(volatile unsigned int *)(base | 0x21c) =
        (*(volatile unsigned int *)(base | 0x21c) & ~0x18) | 0x81;

    FUN_a00a65c4(2, 0x124, 0x7c);
    FUN_a00a65c4(2, 0x121, 1);
    FUN_a00a65c4(2, 0x120, 0);
    FUN_a00b1794(1);
    FUN_a00a65c4(2, 0x120, 2);
    FUN_a00a65c4(2, 0x126, 0x40);
    FUN_a00a65c4(2, 0x127, 9);
    FUN_a00a65c4(2, 0x128, 0xe4);
    FUN_a00a65c4(2, 0x129, 0x60);
    FUN_a008aab0(2, 0x8000);
    FUN_a00a67b8(2, 0x2a7, 0x10, 1);
    FUN_a00a65c4(2, 0x2fe, 6);
    FUN_a00a67b8(2, 8, 5, 1);
    FUN_a00a67b8(2, 8, 8, 0);
    FUN_a00a65c4(2, 0x1af, 9);
    FUN_a00a65c4(2, 0x29f, 2);
    FUN_a00a65c4(2, 0x135, 6);
    FUN_a00a65c4(2, 0x2d0, 1);

    *(volatile unsigned int *)(base | 0x224) = 0x33;

    FUN_a00a67b8(2, 0x79, 0x20, 1);
    FUN_a00a67b8(2, 0x7a, 7, 1);
    FUN_a00a8844(0);
    FUN_a00a8844(1);
    FUN_a00a65c4(2, 0x41, 0);
    FUN_a008f4ec(2);

    for (i = 0; i < 2; i++) {
        ARR_a807d3e4[i][0x6a] = 1;
        ARR_a807d3e4[i][0x21] = 1;
        ARR_a807d3e4[i][0x8c] = 1;
    }
}
