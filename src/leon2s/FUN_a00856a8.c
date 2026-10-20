/* leon2s FUN_a00856a8 @ 0xa00856a8 (-mcpu=v8 -Os -g)
 * Tail-calls FUN_a00a7614(FUN_a0083ed0(param_1 & 0xFF) & 0xFF, param_2, param_3, param_4, param_5, param_6) with
 * param_2 truncated to 16 bits and param_3 to 8 bits.
 */
extern int FUN_a0083ed0();
extern int FUN_a00a7614();

int FUN_a00856a8(unsigned int param_1, unsigned short param_2, unsigned char param_3,
                 unsigned int param_4, unsigned int param_5, unsigned int param_6)
{
    unsigned int t = FUN_a0083ed0(param_1 & 0xff) & 0xff;
    return FUN_a00a7614(t, param_2, param_3, param_4, param_5, param_6);
}
