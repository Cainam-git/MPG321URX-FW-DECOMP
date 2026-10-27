/* FUN_a00d5fc4 (leon2m 0xa00d5fc4-0xa00d5fe4, 32 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Calls FUN_a0149588 with bit 28 of the word DAT_a802d294 (0 or 1) as a tail call; the nop after it is the -g line
 * nop. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a00d5fa4 and FUN_a00d5fe4.
 */
extern unsigned int DAT_a802d294;
extern void FUN_a0149588(unsigned char);

void FUN_a00d5fc4(void)
{
    FUN_a0149588((DAT_a802d294 >> 28) & 1);
}
