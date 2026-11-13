/* hdr_find_percentile_luminance  (FUN_a006250c)
 *
 * Find or interpolate the 50th and 99th percentile brightness from the HDR10+ percentile list.
 * Name basis: derived - keys 0x32 (50) and 0x63 (99) looked up in the percentile list of the metadata record
 *
 * Matching notes
 * --------------
 * FUN_a006250c (leon2s 0xa006250c-0xa0062718, 524 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the entry count is read into an unsigned int local after the two clears (one register serves the entry test
 *    and the loop test);
 *  - found99 is declared second;
 *  - the two results are assigned inside the loop (GCC keeps them in registers and stores them after it);
 *  - the lower limit 1 of the divisor is written 'd > 1 ? d : 1'.
 */
/* The part of the HDR10+ metadata record that holds the percentile list: n pairs, value i at +8 + 2 * i, its
 * percentile key at +0x30 + 2 * i. */
struct Tab {
    unsigned char pad0[7];
    unsigned char n;                /* number of entries */
    unsigned short val[20];         /* brightness at the percentile */
    unsigned short key[20];         /* percentile: 0x32 = 50, 0x63 = 99 */
};
#define PERCENTILE_50 0x32
#define PERCENTILE_99 0x63
extern struct Tab hdr10plus_metadata;
extern unsigned int hdr10plus_percentile_50;
extern unsigned int hdr10plus_percentile_99;
extern unsigned int hdr10plus_scene_max;

/*
 * Work out the 50th and the 99th percentile brightness of the scene from the HDR10+ percentile list in the
 * metadata record. Results: hdr10plus_percentile_50 and hdr10plus_percentile_99.
 * Walks the list in order. An entry with key 0x32 (or 0x63) gives that percentile directly. Without such an
 * entry the result is interpolated linearly between the entry just below and the entry just above the key
 * (the pair where the key steps over it; before the first entry the "previous" key and value are 0; the divisor
 * is at least 1). For the 99th percentile with no
 * entry above the key, the result is hdr10plus_scene_max instead. The 50th percentile stays 0 when the list has
 * no entry above 0x32.
 */
void hdr_find_percentile_luminance(void)
{
    /* For each percentile: the pair of list entries just below and just above it (lo.. / hi..), kept for the
     * interpolation when the list has no entry with exactly that key. */
    unsigned char found50 = 0;
    unsigned char found99 = 0;
    unsigned char have99 = 0;
    unsigned int lo50val = 0;
    unsigned int lo99val = 0;
    unsigned int lo50key = 0;
    unsigned int hi50val = 0;
    unsigned int hi50key = 0;
    unsigned int lo99key = 0;
    unsigned int hi99val = 0;
    unsigned int hi99key = 0;
    unsigned int key, val, d;
    unsigned int prevkey = 0;
    unsigned int prevval = 0;
    unsigned char i;
    unsigned int n;

    hdr10plus_percentile_50 = 0;
    hdr10plus_percentile_99 = 0;
    n = hdr10plus_metadata.n;
    for (i = 0; i < n; i++) {
        /* Exact hit, or remember the pair that straddles the percentile (only until an exact hit is found). */
        key = hdr10plus_metadata.key[i];
        val = hdr10plus_metadata.val[i];
        if (key == PERCENTILE_50) {
            hdr10plus_percentile_50 = val;
            found50 = 1;
        } else if (!found50 && key > PERCENTILE_50 && prevkey < PERCENTILE_50) {
            lo50key = prevkey;
            hi50key = key;
            lo50val = prevval;
            hi50val = val;
        }
        if (key == PERCENTILE_99) {
            hdr10plus_percentile_99 = val;
            found99 = 1;
        } else if (!found99 && key > PERCENTILE_99 && prevkey < PERCENTILE_99) {
            lo99key = prevkey;
            lo99val = prevval;
            hi99key = key;
            hi99val = val;
            have99 = 1;
        }
        prevkey = key;
        prevval = val;
    }
    if (!found50) {
        d = hi50key - lo50key;
        d = d > 1 ? d : 1;
        hdr10plus_percentile_50 = lo50val + (hi50val - lo50val) * (PERCENTILE_50 - lo50key) / d;
    }
    if (!found99) {
        if (have99) {
            d = hi99key - lo99key;
            d = d > 1 ? d : 1;
            hdr10plus_percentile_99 = lo99val + (hi99val - lo99val) * (PERCENTILE_99 - lo99key) / d;
        } else
            hdr10plus_percentile_99 = hdr10plus_scene_max;
    }
}
