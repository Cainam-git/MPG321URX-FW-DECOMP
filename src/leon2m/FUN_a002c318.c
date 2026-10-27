/* FUN_a002c318 (leon2m 0xa002c318-0xa002c338, 32 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Writes the byte v (zero-extended) to the word register at 0xcf000000 | (r << 2), r a halfword index. Nothing in
 * the image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a002c2f0 and
 * FUN_a002c338. Source form: an unsigned short index and an unsigned char value; the target is a volatile word, so
 * the store stays out of the retl delay slot.
 */
void FUN_a002c318(unsigned short r, unsigned char v)
{
    *(volatile unsigned int *)(0xcf000000 | (r << 2)) = v;
}
