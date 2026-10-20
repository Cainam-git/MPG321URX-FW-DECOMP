/* FUN_a00d6e94 (leon2s 0xa00d6e94-0xa00d6f70, 220 bytes), flags -mcpu=v8 -Os -g.
 * h = (src[0] >> 4) - 1 (int); k = h / 2, plus 1 when h is odd; p = src + k. Fills the output o: bits 24..30
 * of word 0 = p[3] & 0x7f, bits 20..23 = p[4] >> 4 (two read-modify-writes of word 0), word 1 =
 * (p[4] & 0xf) << 16 | p[5] << 8 | p[6], byte 8 = n = p[7], then bytes 9.. = src[k + 8 .. k + 8 + n - 1].
 * Source forms: big-endian bit-fields for word 0 (first field = most significant bit); the copy loop reads
 * o->n as its limit and indexes src with k + i + 8.
 */
struct out {
    unsigned int b31 : 1, f24 : 7, f20 : 4, rest : 20;
    unsigned int w1;
    unsigned char n;
    unsigned char d[];
};

void FUN_a00d6e94(struct out *o, unsigned char *src)
{
    int h = (src[0] >> 4) - 1;
    unsigned char k = h / 2;
    unsigned char *p;
    unsigned char i;

    if (h & 1)
        k = h / 2 + 1;
    p = src + k;
    o->f24 = p[3] & 0x7f;
    o->f20 = p[4] >> 4;
    o->w1 = ((p[4] & 0xf) << 16) | (p[5] << 8) | p[6];
    o->n = p[7];
    for (i = 0; i < o->n; i++)
        o->d[i] = src[k + i + 8];
}
