/* FUN_a00d5fa4 (leon2m 0xa00d5fa4-0xa00d5fc4, 32 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Calls FUN_a014a0d8 with bit 29 of the word DAT_a802d294 (0 or 1) as a tail call; the nop after it is the -g line
 * nop. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a00d5f9c and FUN_a00d5fc4.
 */
extern unsigned int DAT_a802d294;
extern void FUN_a014a0d8(unsigned int);

void FUN_a00d5fa4(void)
{
    FUN_a014a0d8((DAT_a802d294 >> 29) & 1);
}
