/* FUN_a00d5fe4 (leon2m 0xa00d5fe4-0xa00d6000, 28 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Calls FUN_a014931c(0, DAT_a802d2df) as a tail call, DAT_a802d2df a byte global; the nop after it is the -g line
 * nop. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a00d5fc4 and FUN_a00d6000.
 */
extern unsigned char DAT_a802d2df;
extern void FUN_a014931c(unsigned char, unsigned char);

void FUN_a00d5fe4(void)
{
    FUN_a014931c(0, DAT_a802d2df);
}
