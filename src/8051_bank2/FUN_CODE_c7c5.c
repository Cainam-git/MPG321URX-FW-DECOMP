/* FUN_CODE_c7c5, 8051_bank2 (helper chip updater), range 0xC7C5..0xC89E (217 B).
 * Options: OPTIMIZE(8,SPEED) LARGE.
 * Code facts: k stays in R7 (no call, so the LARGE parameter is never stored). Locals: h 0x090D, n 0x090E, off 0x090F,
 * i 0x0910, v (ulong) 0x0911..0x0914; t is register-only. Walks a record list in XDATA 0x015C: each record starts
 * with a header byte whose high nibble h and low nibble n are lengths; a record is h + n + 1 bytes. It skips k
 * records, then returns the h bytes after the header and the n bytes, little-endian: v += (ulong)byte << (i * 8)
 * (?C?LSHL). Twin of FUN_CODE_c89e (same walk; c89e returns the n-byte field).
 * Shape levers: the step is written into t again ('t = ((t & 0xf0) >> 4) + (t & 0x0f) + 1; off += t;' keeps it in
 * R6), and the header after the walk is named twice ('n = DAT_EXTMEM_015c[off] & 0x0f; h = (DAT_EXTMEM_015c[off] &
 * 0xf0) >> 4;'): Keil reads it once into R6. Reusing t there gives t a memory slot, a block-local copy
 * is 45.9 %. The index is a uchar sum (unsigned char)(off + n + i).
 * Callers: FUN_CODE_140d (0x14F8), FUN_CODE_1e55 (0x2315), FUN_CODE_9235 (0x93DF), all in the af07 updater module
 * (FUN_CODE_a17e); c7c5 itself has no common-entry block, so it stands alone. No aids.
 */
extern unsigned char xdata DAT_EXTMEM_015c[];
extern unsigned char xdata DAT_EXTMEM_015d[];
unsigned long FUN_CODE_c7c5(unsigned char k)
{
    unsigned char h;
    unsigned char n;
    unsigned char off;
    unsigned char i;
    unsigned long v;
    unsigned char t;
    off = 0;
    for (i = 0; i < k; i++) {
        t = DAT_EXTMEM_015c[off];
        t = ((t & 0xf0) >> 4) + (t & 0x0f) + 1;
        off += t;
    }
    n = DAT_EXTMEM_015c[off] & 0x0f;
    h = (DAT_EXTMEM_015c[off] & 0xf0) >> 4;
    v = 0;
    for (i = 0; i < h; i++)
        v += (unsigned long)DAT_EXTMEM_015d[(unsigned char)(off + n + i)] << (i * 8);
    return v;
}
