/* leon2m FUN_a013358c @ 0xa013358c (-mcpu=v8 -O3 -g -msoft-float). No direct callers found.
 * Parameters (cmd, b1, b2, p, len). When bit 7 of cmd is set: hi = len (low byte) and len = 0, else hi = 0.
 * Sends the len + 2 bytes b1, b2, p[0..len-1] in 16-byte chunks through the 37-entry ring DAT_a802da6c (20-byte
 * entries; write index byte DAT_a802cb97, back to 0 after 0x24): chunk 0 is built in a zeroed 16-byte local buffer
 * (b1, b2, then p[0..cnt-3]), later chunks are read from p + off - 2. The chunk bytes are packed big-endian into the
 * words w[0..3] (static helper inlined twice) and the entry gets word 0 = (hi << 24) + (cnt << 16) + (cmd << 8) + 2 +
 * (last << 4) (cnt = 16, or the remaining length with last = 1 instead of 2 for the final short chunk), words 1..4 =
 * w[0..3]; hi increments per chunk. FUN_a0135ae8 is the same body followed by a wait for the ring.
 * Source form: w is unsigned long.
 * Compiler aid: 'for (;;) break;' after 'c = cnt << 16;' emits no instructions; its loop notes end the scheduling
 * region there, so the shift is placed before the ring index load of the entry stores.
 */
struct Msg { unsigned int w[5]; };
extern unsigned char DAT_a802cb97;
extern struct Msg DAT_a802da6c[];

static void pack(unsigned long *d, unsigned char *q)
{
    unsigned char j, nw = 4;

    for (j = 0; j < nw; j++) {
        d[j] = q[j * 4];
        d[j] = (d[j] << 8) + q[j * 4 + 1];
        d[j] = (d[j] << 8) + q[j * 4 + 2];
        d[j] = (d[j] << 8) + q[j * 4 + 3];
    }
}

void FUN_a013358c(unsigned char cmd, unsigned char b1, unsigned char b2, unsigned char *p, unsigned short len)
{
    unsigned long w[4] = { 0, 0, 0, 0 };
    unsigned char tmp[16] = { 0 };
    unsigned short off;
    unsigned int c;
    unsigned char type = 2, last = 2, cnt = 16, hi = 0, k;

    if (cmd & 0x80) {
        hi = len;
        len = 0;
    }
    for (off = 0; off < len + 2; off += 16) {
        if (len - off + 2 < 16) {
            cnt = len - off + 2;
            last = 1;
        }
        if (off == 0) {
            tmp[0] = b1;
            tmp[1] = b2;
            for (k = 0; k < cnt - 2; k++)
                tmp[k + 2] = p[k];
            pack(w, tmp);
        } else
            pack(w, p + off - 2);
        c = cnt << 16;
        for (;;)
            break;
        DAT_a802da6c[DAT_a802cb97].w[0] = (hi << 24) + c + (cmd << 8) + type + (last << 4);
        DAT_a802da6c[DAT_a802cb97].w[1] = w[0];
        DAT_a802da6c[DAT_a802cb97].w[2] = w[1];
        DAT_a802da6c[DAT_a802cb97].w[3] = w[2];
        DAT_a802da6c[DAT_a802cb97].w[4] = w[3];
        if (++DAT_a802cb97 > 0x24)
            DAT_a802cb97 = 0;
        hi++;
    }
}
