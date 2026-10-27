/* leon2m FUN_a0133b54 @ 0xa0133b54-0xa0133cbc (360 bytes), flags -mcpu=v8 -O3 -g -msoft-float. Caller: FUN_a01486a8.
 * Queues len bytes from p as message type 4 in the ring DAT_a802da6c (20-byte entries, write index byte DAT_a802cb97,
 * wraps after 0x24) that FUN_a01350dc drains; no waits. Per 16-byte chunk c (from 0) the bytes are packed big-endian
 * into four words and an entry is written: word 0 = (c << 24) + (chunk length << 16) + (cmd << 8) + 4 + (last << 4),
 * last = 1 for the final chunk (len - off <= 16) and 2 before it; words 1..4 = the packed words.
 * Source form: as the ring senders FUN_a0136384 / FUN_a013588c (w unsigned long, packing loop limit in nw); the
 * type is a variable so the constant stays ahead of (last << 4) in the sum.
 */
struct Msg { unsigned int w[5]; };
extern unsigned char DAT_a802cb97;
extern struct Msg DAT_a802da6c[];

void FUN_a0133b54(unsigned char cmd, unsigned short len, unsigned char *p)
{
    unsigned long w[4] = { 0, 0, 0, 0 };
    unsigned short off;
    unsigned char type = 4, last = 2, cnt = 16, hi = 0, j, nw;
    unsigned char *q;
    unsigned long *d;

    for (off = 0; off < len; off += 16) {
        if (len - off <= 16) {
            cnt = len - off;
            last = 1;
        }
        q = p + off;
        nw = 4;
        d = w;
        for (j = 0; j < nw; j++) {
            d[j] = q[j * 4];
            d[j] = (d[j] << 8) + q[j * 4 + 1];
            d[j] = (d[j] << 8) + q[j * 4 + 2];
            d[j] = (d[j] << 8) + q[j * 4 + 3];
        }
        DAT_a802da6c[DAT_a802cb97].w[0] = (hi << 24) + (cnt << 16) + (cmd << 8) + type + (last << 4);
        DAT_a802da6c[DAT_a802cb97].w[1] = w[0];
        DAT_a802da6c[DAT_a802cb97].w[2] = w[1];
        DAT_a802da6c[DAT_a802cb97].w[3] = w[2];
        DAT_a802da6c[DAT_a802cb97].w[4] = w[3];
        if (++DAT_a802cb97 > 0x24)
            DAT_a802cb97 = 0;
        hi++;
    }
}
