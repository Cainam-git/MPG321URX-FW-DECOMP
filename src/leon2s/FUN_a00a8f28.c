/* FUN_a00a8f28 (leon2s 0xa00a8f28-0xa00a8f8c, 100 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Copies the bytes src+1, src+4 and src+5 to dst bytes 0..2 and the 10 bytes src+6.. to dst+4..; dst byte 3
 * becomes minus the 8-bit sum of dst bytes 0..2 and the 10 copied bytes.
 * Source form: both sides are structs, so the payload stores and the checksum accesses are separate fields
 * that GCC may reorder (the firmware loads the checksum before the payload store).
 */
struct if_src {
    unsigned char b0;
    unsigned char type;
    unsigned char b2;
    unsigned char b3;
    unsigned char ver;
    unsigned char len;
    unsigned char data[27];
};
struct if_pkt {
    unsigned char type;
    unsigned char ver;
    unsigned char len;
    unsigned char sum;
    unsigned char data[27];
};

void FUN_a00a8f28(struct if_src *src, struct if_pkt *dst)
{
    unsigned char i;

    dst->type = src->type;
    dst->ver = src->ver;
    dst->len = src->len;
    dst->sum = dst->type + dst->ver + dst->len;
    for (i = 0; i < 10; i++) {
        dst->data[i] = src->data[i];
        dst->sum += dst->data[i];
    }
    dst->sum = -dst->sum;
}
