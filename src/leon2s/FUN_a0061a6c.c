/* FUN_a0061a6c (leon2s 0xa0061a6c-0xa0061adc, 112 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Bit-field write: for hi >= lo, hi <= 31 and lo <= 31 replaces bits lo..hi of *p with v << lo
 * (mask ((1 << hi) - (1 << lo)) | (1 << hi), read-modify-write as in FUN_a0061540). Returns 1 when hi < lo or
 * hi > 31, else 0 (lo > 31 skips the write but returns 0). Byte-identical to FUN_a00614b8.
 * Source form: the mask and the shifted value are computed inside the write arm 'if (!(r | e))'; sched1 then
 * moves them into the 'hi <= 31' test block (the firmware place) instead of above the 'hi >= lo' test.
 */
unsigned int FUN_a0061a6c(unsigned int *p, unsigned int hi, unsigned int lo, unsigned int v)
{
    unsigned int r = 1;
    unsigned int e = 1;
    unsigned int m;

    if (hi >= lo) {
        if (hi <= 31)
            r = 0;
        if (lo <= 31)
            e = 0;
        if (!(r | e)) {
            m = ((1u << hi) - (1u << lo)) | (1u << hi);
            *p = (*p & ~m) | ((v << lo) & m);
        }
    }
    return r;
}
