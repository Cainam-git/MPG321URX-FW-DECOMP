/* FUN_a00d6038 (leon2m 0xa00d6038-0xa00d6054, 28 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Calls FUN_a014931c(3, DAT_a802d2e2) as a tail call, DAT_a802d2e2 a byte global; the nop after it is the -g line
 * nop. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a00d601c and FUN_a00d6054.
 */
extern unsigned char DAT_a802d2e2;
extern void FUN_a014931c(unsigned char, unsigned char);

void FUN_a00d6038(void)
{
    FUN_a014931c(3, DAT_a802d2e2);
}
