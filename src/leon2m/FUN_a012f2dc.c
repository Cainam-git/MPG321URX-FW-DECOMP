/* FUN_a012f2dc (leon2m 0xa012f2dc-0xa012f31c, 64 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the index (0..3) of the first byte of the four-byte table DAT_001a5238 that equals c, or 0xff when none
 * does. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a012f1ec and FUN_a012f31c. Source form: the table byte is read into a local before the compare.
 */
extern const unsigned char DAT_001a5238[];
unsigned char FUN_a012f2dc(unsigned char c)
{
    unsigned char i;
    for (i = 0; i < 4; i++) {
        unsigned char v = DAT_001a5238[i];
        if (c == v)
            return i;
    }
    return 0xff;
}
