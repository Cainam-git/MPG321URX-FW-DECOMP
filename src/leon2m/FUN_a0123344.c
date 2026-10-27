/* FUN_a0123344 (leon2m 0xa0123344-0xa0123384, 64 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Calls FUN_a00f2ca8(blk, 0x9c, 4, 1) when on is 1, otherwise FUN_a00f2ca8(blk, 0x9c, 4, 0), as a tail call.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a0123304 and FUN_a0123384. Source form: a separate call in each arm of the if/else.
 */
extern void FUN_a00f2ca8(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);

void FUN_a0123344(unsigned char blk, unsigned char on)
{
    if (on == 1)
        FUN_a00f2ca8(blk, 0x9c, 4, 1);
    else
        FUN_a00f2ca8(blk, 0x9c, 4, 0);
}
