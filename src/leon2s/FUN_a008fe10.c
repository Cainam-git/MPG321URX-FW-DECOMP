/* leon2s FUN_a008fe10 @ 0xa008fe10 (-mcpu=v8 -Os -g)
 * Reads register 0x45 with FUN_a00a657c(param_1 & 0xFF, 0x45) and returns 1 when bits 2..0 of the result are not
 * 4, else 0. The comparison result is materialized branch-free with addx.
 */
extern unsigned int FUN_a00a657c(unsigned int param_1, unsigned short param_2);

unsigned int FUN_a008fe10(unsigned int param_1)
{
    unsigned int x = FUN_a00a657c(param_1 & 0xff, 0x45);
    return (x & 7) != 4;
}
