/* FUN_a0100468 (leon2m 0xa0100468-0xa01004cc, 100 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * When (unsigned char)(b + 0x1f) is at most 1 (b = 0xe1 or 0xe2), calls FUN_a00f1b5c(blk, 0xab, 4, 1) for a
 * non-zero on, otherwise FUN_a00f1b5c(blk, 0xab, 4, 0), as a tail call. Nothing in the image refers to it: no call,
 * branch, sethi/or constant or address word. It lies between FUN_a0100434 and FUN_a01004cc. Source form: a separate
 * call in each arm of the if/else.
 */
extern void FUN_a00f1b5c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);

void FUN_a0100468(unsigned char blk, unsigned char b, unsigned char on)
{
    if ((unsigned char)(b + 0x1f) <= 1) {
        if (on)
            FUN_a00f1b5c(blk, 0xab, 4, 1);
        else
            FUN_a00f1b5c(blk, 0xab, 4, 0);
    }
}
