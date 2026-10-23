/* FUN_a00d714c (leon2s 0xa00d714c-0xa00d7210, 196 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Reads a byte record at src: t = (src[0] >> 4) - 1, off = t / 2 rounded up for odd t (signed division).
 * Copies the low 7 bits of src[off + 3] into the low 7 bits of dst byte 0, the high nibble of src[off + 4] into
 * the high nibble of dst byte 1, the low 7 bits of src[off + 5] into the low 7 bits of dst byte 2, the count
 * src[off + 6] into dst byte 3, and then that many bytes from src[off + 7] onwards to dst byte 4 onwards.
 * Source form: the bytes 0..2 of dst are bit-fields (high bits first); the copy loop compares against dst->n.
 */
struct dsc {
    unsigned char a : 1;
    unsigned char b : 7;
    unsigned char c : 4;
    unsigned char d : 4;
    unsigned char e : 1;
    unsigned char f : 7;
    unsigned char n;
    unsigned char data[];
};

void FUN_a00d714c(struct dsc *dst, unsigned char *src)
{
    int t;
    unsigned char off;
    unsigned char i;

    t = (src[0] >> 4) - 1;
    off = t / 2;
    if (t & 1)
        off = t / 2 + 1;
    dst->b = src[off + 3];
    dst->c = src[off + 4] >> 4;
    dst->f = src[off + 5];
    dst->n = src[off + 6];
    for (i = 0; i < dst->n; i++)
        dst->data[i] = src[off + i + 7];
}
