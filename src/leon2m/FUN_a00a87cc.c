/* leon2m FUN_a00a87cc @ 0xa00a87cc-0xa00a89e4 (134 words).
 * FUN_a0146b50(0x111, 0), FUN_a0146b6c(0, 0). For n 0..3 and i = 0..6 passes entry 7 * n + i of the table
 * DAT_0018d3d4 (FUN_a00a3844) to FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, entry, 0); n 4 passes entry 0x1c with row 6.
 * Ends with FUN_a00b32e4(1, 1, 0x792, 0x2d, 0x15, 2, 0x28).
 */
extern unsigned int DAT_0018d3d4[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned short, int, unsigned int, int);
extern void FUN_a00b32e4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                         unsigned int);

void FUN_a00a87cc(unsigned char n)
{
    unsigned char i;

    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    if (n == 0) {
        for (i = 0; i <= 6; i++)
            FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_0018d3d4, i), 0);
    } else if (n == 1) {
        for (i = 0; i <= 6; i++)
            FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_0018d3d4, i + 7), 0);
    } else if (n == 2) {
        for (i = 0; i <= 6; i++)
            FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_0018d3d4, i + 0xe), 0);
    } else if (n == 3) {
        for (i = 0; i <= 6; i++)
            FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_0018d3d4, i + 0x15), 0);
    } else if (n == 4) {
        FUN_a00a31a4(0, 0x2a, 6, 1, FUN_a00a3844(DAT_0018d3d4, 0x1c), 0);
    }
    FUN_a00b32e4(1, 1, 0x792, 0x2d, 0x15, 2, 0x28);
}
