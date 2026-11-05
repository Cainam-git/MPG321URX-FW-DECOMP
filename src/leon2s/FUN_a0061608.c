/* leon2s FUN_a0061608 @ 0xa0061608 (-mcpu=v8 -Os -g)
 * Copies n bytes from address s to address d using only aligned word accesses (d, s, n are plain integers).
 * Phase 1: while d is not word aligned, one byte is moved: the source byte is extracted from the word at
 * (s & ~3) with shift (s & 3) * 8, and the destination word at (d & ~3) is rewritten with that byte at shift
 * (d & 3) * 8 (read-modify-write); returns when n reaches 0.
 * Phase 2: (n >> 2) whole words are written to d. The source alignment (s & 3) selects the merge:
 * 0 plain word copy, 1 (w0 >> 8) + (w1 << 24), 2 halfword at w0 + (w1 << 16), 3 byte at w0 + (w1 << 8),
 * where w0, w1 are consecutive source words from (s & ~3); s then points past the copied data.
 * Phase 3: the remaining (n & 3) bytes are moved one at a time as in phase 1.
 * Source form: phase 1 is written out with the function-scope temporaries w, sh and b, which are reused as
 * the word-loop counter (w) and the word count (sh) in phase 2; phase 3 calls the static helper copy_byte()
 * with its own locals. Byte-moving statements: shift first, then the word read, then the masked merge.
 */
static void copy_byte(unsigned int d, unsigned int s)
{
    unsigned int w, sh, b;

    sh = (s & 3) << 3;
    w = *(unsigned int *)(s & ~3);
    b = (w >> sh) & 0xff;
    sh = (d & 3) << 3;
    w = *(unsigned int *)(d & ~3);
    w = (w & ~(0xff << sh)) | (b << sh);
    *(unsigned int *)(d & ~3) = w;
}

void FUN_a0061608(unsigned int d, unsigned int s, unsigned int n)
{
    unsigned int *sw;
    unsigned int w, sh, b;

    if (d & 3) {
        do {
            sh = (s & 3) << 3;
            w = *(unsigned int *)(s & ~3);
            b = (w >> sh) & 0xff;
            sh = (d & 3) << 3;
            w = *(unsigned int *)(d & ~3);
            w = (w & ~(0xff << sh)) | (b << sh);
            *(unsigned int *)(d & ~3) = w;
            d++;
            s++;
            if (--n == 0)
                return;
        } while (d & 3);
    }
    sh = n >> 2;
    sw = (unsigned int *)(s & ~3);
    switch (s & 3) {
    case 0:
        for (w = 0; w < sh; w++) {
            *(unsigned int *)d = *sw++;
            d += 4;
        }
        s = (unsigned int)sw;
        break;
    case 1:
        for (w = 0; w < sh; w++) {
            *(unsigned int *)d = (sw[0] >> 8) + (sw[1] << 24);
            d += 4;
            sw++;
        }
        s = (unsigned int)sw + 1;
        break;
    case 2:
        for (w = 0; w < sh; w++) {
            *(unsigned int *)d = *(unsigned short *)sw + (sw[1] << 16);
            d += 4;
            sw++;
        }
        s = (unsigned int)sw + 2;
        break;
    case 3:
        for (w = 0; w < sh; w++) {
            *(unsigned int *)d = *(unsigned char *)sw + (sw[1] << 8);
            d += 4;
            sw++;
        }
        s = (unsigned int)sw + 3;
        break;
    }
    while (n & 3) {
        copy_byte(d, s);
        n--;
        s++;
        d++;
    }
}
