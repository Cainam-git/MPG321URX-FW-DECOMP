/* FUN_a006250c (leon2s 0xa006250c-0xa0062718, 524 bytes), flags -mcpu=v8 -Os -g.
 * Clears DAT_a8078a64 and DAT_a8078a6c, then walks the n = byte +7 entries of the record DAT_a8078aa0 with
 * key = halfword +0x30 + 2 * i and val = halfword +8 + 2 * i. A key of 0x32 stores val in DAT_a8078a64 and sets
 * found50; while found50 is clear, a key above 0x32 whose previous key is below 0x32 records the previous and
 * the current key/val pair. Key 0x63 does the same for DAT_a8078a6c (found99, pair recorded with have99 = 1).
 * After the walk, without a 0x32 key DAT_a8078a64 = lo + (hi - lo) * (0x32 - lokey) / max(hikey - lokey, 1)
 * (unsigned) from the recorded pair; without a 0x63 key DAT_a8078a6c is computed the same way with 0x63 when
 * have99 is set, else copied from DAT_a8076684.
 * Source form: the entry count is read into an unsigned int local n after the two clears (one register for the
 * entry test and the loop test); found99 is declared second; the global results are assigned inside the loop
 * (GCC keeps them in registers and stores them after it); the lower limit 1 is written 'd > 1 ? d : 1'.
 */
struct Tab {
    unsigned char pad0[7];
    unsigned char n;
    unsigned short val[20];
    unsigned short key[20];
};
extern struct Tab DAT_a8078aa0;
extern unsigned int DAT_a8078a64;
extern unsigned int DAT_a8078a6c;
extern unsigned int DAT_a8076684;

void FUN_a006250c(void)
{
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

    DAT_a8078a64 = 0;
    DAT_a8078a6c = 0;
    n = DAT_a8078aa0.n;
    for (i = 0; i < n; i++) {
        key = DAT_a8078aa0.key[i];
        val = DAT_a8078aa0.val[i];
        if (key == 0x32) {
            DAT_a8078a64 = val;
            found50 = 1;
        } else if (!found50 && key > 0x32 && prevkey < 0x32) {
            lo50key = prevkey;
            hi50key = key;
            lo50val = prevval;
            hi50val = val;
        }
        if (key == 0x63) {
            DAT_a8078a6c = val;
            found99 = 1;
        } else if (!found99 && key > 0x63 && prevkey < 0x63) {
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
        DAT_a8078a64 = lo50val + (hi50val - lo50val) * (0x32 - lo50key) / d;
    }
    if (!found99) {
        if (have99) {
            d = hi99key - lo99key;
            d = d > 1 ? d : 1;
            DAT_a8078a6c = lo99val + (hi99val - lo99val) * (0x63 - lo99key) / d;
        } else
            DAT_a8078a6c = DAT_a8076684;
    }
}
