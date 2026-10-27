/* FUN_a002c338 (leon2m 0xa002c338-0xa002c364, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes the byte v (zero-extended) to the word register at 0xcf000000 | ((r + k) << 2), r a halfword and k a byte
 * index. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a002c318 and FUN_a002c364. Source form: the target is a volatile word, so the store stays out of the retl
 * delay slot.
 */
void FUN_a002c338(unsigned short r, unsigned char k, unsigned char v)
{
    *(volatile unsigned int *)(0xcf000000 | ((r + k) << 2)) = v;
}
