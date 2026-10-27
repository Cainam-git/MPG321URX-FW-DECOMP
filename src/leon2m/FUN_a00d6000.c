/* FUN_a00d6000 (leon2m 0xa00d6000-0xa00d601c, 28 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Calls FUN_a014931c(1, DAT_a802d2e0) as a tail call, DAT_a802d2e0 a byte global; the nop after it is the -g line
 * nop. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a00d5fe4 and FUN_a00d601c.
 */
extern unsigned char DAT_a802d2e0;
extern void FUN_a014931c(unsigned char, unsigned char);

void FUN_a00d6000(void)
{
    FUN_a014931c(1, DAT_a802d2e0);
}
