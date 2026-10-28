/* FUN_a0061578 (leon2s 0xa0061578-0xa00615ac, 52 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Byte write into a word: reads the aligned word at addr & ~3, replaces the byte at bit offset (addr & 3) * 8 with
 * the low byte of v and writes the word back. Byte-write counterpart of FUN_a006155c; nothing in the image calls it
 * directly. The word is accessed through a volatile word pointer as in the neighbouring register helpers
 * FUN_a0061528, FUN_a0061534 and FUN_a0061540 (the store stays before retl).
 * Source form: the word read into a local, updated in one expression and written back.
 */
void FUN_a0061578(unsigned int addr, unsigned int v)
{
    volatile unsigned int *p = (volatile unsigned int *)(addr & ~3);
    unsigned int sh = (addr & 3) << 3;
    unsigned int w = *p;

    w = (w & ~(0xff << sh)) | ((v & 0xff) << sh);
    *p = w;
}
