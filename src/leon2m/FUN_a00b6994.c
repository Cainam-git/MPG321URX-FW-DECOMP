/* leon2m FUN_a00b6994 @ 0xa00b6994 (-mcpu=v8 -O3 -g)
 * FUN_a00a9f30(2, 0) when FUN_a00d7d48() returns non-zero, else FUN_a00a9f30(2, bit 15 of word 0xA802D404)
 * (both tail calls). FUN_a00d7d48 takes no argument.
 */
extern unsigned int _DAT_a802d404;
extern void FUN_a00a9f30(unsigned char param_1, unsigned char param_2);
extern int FUN_a00d7d48(void);

void FUN_a00b6994(void)
{
    if (FUN_a00d7d48() != 0) {
        FUN_a00a9f30(2, 0);
        return;
    }
    FUN_a00a9f30(2, (_DAT_a802d404 >> 0xf) & 1);
}
