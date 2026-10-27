/* FUN_a00d601c (leon2m 0xa00d601c-0xa00d6038, 28 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Calls FUN_a014931c(2, DAT_a802d2e1) as a tail call, DAT_a802d2e1 a byte global; the nop after it is the -g line
 * nop. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a00d6000 and FUN_a00d6038.
 */
extern unsigned char DAT_a802d2e1;
extern void FUN_a014931c(unsigned char, unsigned char);

void FUN_a00d601c(void)
{
    FUN_a014931c(2, DAT_a802d2e1);
}
