/* leon2m FUN_a00b6d58 @ 0xa00b6d58 (-mcpu=v8 -O3 -g)
 * FUN_a00a9f30(1, 0) when FUN_a00d7d48() returns non-zero, else FUN_a00a9f30(1, bit 4 of word 0xA802D3AC)
 * (both tail calls). FUN_a00d7d48 takes no argument.
 */
extern unsigned int _DAT_a802d3ac;
extern void FUN_a00a9f30(unsigned char param_1, unsigned char param_2);
extern int FUN_a00d7d48(void);

void FUN_a00b6d58(void)
{
    if (FUN_a00d7d48() != 0) {
        FUN_a00a9f30(1, 0);
        return;
    }
    FUN_a00a9f30(1, (_DAT_a802d3ac >> 4) & 1);
}
