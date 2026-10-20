/* leon2s FUN_a00aa200 @ 0xa00aa200-0xa00aa2d0 (52 words).
 * Fixed sequence of ten FUN_a00a7d04(0, reg, value, 0) calls: (0x3e, 1), (0x4a, 0xf0), (0x44, 0xf0), (0x44, 0xf),
 * (0x35, 1), (0x4a, 0xf0), (0x3c, 0x40), (0x34, 0x44), (0x33, 0x40), (0x30, 1). The function ends at 0xa00aa2d0, where
 * FUN_a00aa2d0 starts.
 */
extern void FUN_a00a7d04(unsigned int param_1, short param_2, unsigned int param_3, unsigned int param_4);

void FUN_a00aa200(void)
{
    FUN_a00a7d04(0, 0x3e, 1, 0);
    FUN_a00a7d04(0, 0x4a, 0xf0, 0);
    FUN_a00a7d04(0, 0x44, 0xf0, 0);
    FUN_a00a7d04(0, 0x44, 0xf, 0);
    FUN_a00a7d04(0, 0x35, 1, 0);
    FUN_a00a7d04(0, 0x4a, 0xf0, 0);
    FUN_a00a7d04(0, 0x3c, 0x40, 0);
    FUN_a00a7d04(0, 0x34, 0x44, 0);
    FUN_a00a7d04(0, 0x33, 0x40, 0);
    FUN_a00a7d04(0, 0x30, 1, 0);
}
