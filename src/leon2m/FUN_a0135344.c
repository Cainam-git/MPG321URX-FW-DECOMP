/* leon2m FUN_a0135344 @ 0xa0135344 (-mcpu=v8 -O3 -g). No direct callers found.
 * Parameters (cmd, b1, b2, p, len). Runs the body of FUN_a013358c with cmd | 0x80: since bit 7 is then always set,
 * hi = len (low byte) and len = 0, so one entry with the 2 bytes b1, b2 (packed big-endian into the words w[0..3]
 * from a zeroed 16-byte local buffer) is written to the 37-entry ring DAT_a802da6c (20-byte entries; write index
 * byte DAT_a802cb97, back to 0 after 0x24): word 0 = (hi << 24) + (2 << 16) + ((cmd | 0x80) << 8) + 2 + (1 << 4), words
 * 1..4 = w[0..3]. Then calls FUN_a01350dc() and FUN_a0134de0() until the body of FUN_a0132b8c(p) returns non-zero
 * (when byte 0xa802cb93 is 1: copies byte 0xa802cb92 bytes of 0xa802de40 to p, clears 0xa802cb93, returns 1).
 * Source form: FUN_a013358c (as send(), with its packing helper) and FUN_a0132b8c are static copies inlined at -O3;
 * the sender is called with 'cmd | 0x80'; w is unsigned long.
 * Compiler aid: 'for (;;) break;' after 'c = cnt << 16;' emits no instructions; its loop notes end the scheduling
 * region there, so the shift is placed before the ring index load of the entry stores.
 */
struct Msg { unsigned int w[5]; };
extern unsigned char DAT_a802cb97;
extern struct Msg DAT_a802da6c[];
extern void FUN_a01350dc(void);
extern void FUN_a0134de0(void);
extern unsigned char DAT_a802cb92, DAT_a802cb93;
extern unsigned char DAT_a802de40[];

static unsigned char FUN_a0132b8c(unsigned char *dst)
{
    unsigned char r = 0;
    unsigned char i;

    if (DAT_a802cb93 == 1) {
        for (i = 0; i < DAT_a802cb92; i++)
            dst[i] = DAT_a802de40[i];
        DAT_a802cb93 = 0;
        r = 1;
    }
    return r & 1;
}

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

static void send(unsigned char cmd, unsigned char b1, unsigned char b2, unsigned char *p, unsigned short len)
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

void FUN_a0135344(unsigned char cmd, unsigned char b1, unsigned char b2, unsigned char *p, unsigned short len)
{
    send(cmd | 0x80, b1, b2, p, len);
    while (!FUN_a0132b8c(p)) {
        FUN_a01350dc();
        FUN_a0134de0();
    }
}
