/* leon2s FUN_a00d74ec @ 0xa00d74ec-0xa00d7638, -mcpu=v8 -Os -g.
 * (struct In *p, u8 *d), void. Packs p into the byte stream d with a u8 write index k:
 * d[0] = p->h & 0x7f, then the 16 bytes p->a, then n = p->n & 0xf; then for each of the n 20-byte entries
 * e[j] (from p + 0x12): e.b0; when bit 7 of e.b0 is clear, the top 3 bits of e.b1, e.b2, the 16 bytes e.c and
 * e.last; when it is set, only the top 2 bits of e.b1.
 * Source form: the kept bits are written as (b1 >> 5) << 5 and (b1 >> 6) << 6 (the firmware masks in a word
 * register: and 0xe0 / 0xc0, not the byte constants -32 / -64); the clear-bit arm comes first; the entry count
 * is compared unsigned.
 */
struct Ent { unsigned char b0; unsigned char b1; unsigned char b2; unsigned char c[16]; unsigned char last; };
struct In { unsigned char h; unsigned char a[16]; unsigned char n; struct Ent e[1]; };

void FUN_a00d74ec(struct In *p, unsigned char *d)
{
    unsigned char i, j, k;

    d[0] = p->h & 0x7f;
    k = 1;
    for (i = 0; i <= 0xf; i++)
        d[k++] = p->a[i];
    d[k++] = p->n & 0xf;
    for (j = 0; j < (p->n & 0xfU); j++) {
        d[k++] = p->e[j].b0;
        if ((p->e[j].b0 >> 7) == 0) {
            d[k++] = (p->e[j].b1 >> 5) << 5;
            d[k++] = p->e[j].b2;
            for (i = 0; i <= 0xf; i++)
                d[k++] = p->e[j].c[i];
            d[k++] = p->e[j].last;
        } else {
            d[k++] = (p->e[j].b1 >> 6) << 6;
        }
    }
}
