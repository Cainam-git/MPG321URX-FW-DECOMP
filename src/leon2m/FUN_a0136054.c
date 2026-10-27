/* leon2m FUN_a0136054 @ 0xa0136054-0xa0136384 (816 bytes) -mcpu=v8 -O3 -g. Caller: FUN_a01451fc.
 * idx = FUN_a01250c4(), printed with "port_idx %d\n"; idx 0xff ends the function. Otherwise
 * FUN_a014226c(FUN_a01421c4(FUN_a0142218(idx))), FUN_a0124b88(idx, v) fills two words v, and a 10-byte message is
 * built in a zeroed 14-byte buffer: 0xf2 | k << 2 (k = 0 for idx 6, else 1), 0x60 | bit 11 of v[0], 0xff, 1, 2, 1,
 * 0xff, 1, 1, bits 8..9 of v[0]. It is sent as message type 0xb, each chunk's first 8 bytes printed with
 * "data : %02X ..." first.
 * The message is sent through the 37-entry ring DAT_a802da6c (20-byte entries; write index byte DAT_a802cb97, wraps
 * after 0x24; read index DAT_a802cb96) that FUN_a01350dc drains: first wait while 16 * (free ring entries) < len
 * (FUN_a01350dc in between); then per 16-byte chunk (index c from 0) the bytes are packed big-endian into four words
 * w[0..3] and an entry is written: word 0 = (c << 24) + (chunk length << 16) + 0xb, words 1..4 = w[0..3]; then wait
 * until the ring is empty and until the four mailbox words at portal 0 offsets 0x10, 0x24, 0x38, 0x4C (MailBox_Read
 * func_0x4008c4d0) are all zero. The two waits are the mode 1 and mode 3 bodies of FUN_a01356fc, written as a
 * static helper inlined at -O3.
 * Source form: as FUN_a0136384 (buffer declared before w, w unsigned long); k = 1 at its declaration and
 * 'if (idx != 5) k = idx != 6;'; v is a two-word array (8-byte stack slot); declaration order idx, k, cnt, hi.
 */
struct Msg { unsigned int w[5]; };
extern unsigned char DAT_a802cb96, DAT_a802cb97;
extern struct Msg DAT_a802da6c[];
extern unsigned char FUN_a01250c4(void);
extern unsigned char FUN_a0142218(unsigned char);
extern unsigned char FUN_a01421c4(unsigned char);
extern unsigned char FUN_a014226c(unsigned char);
extern void FUN_a0124b88(unsigned char, unsigned int *);
extern int FUN_a00df170(const char *fmt, ...);
extern const char s_001a5540[], s_001a5550[];
extern void FUN_a01350dc(void);
extern void func_0x4008c4d0(unsigned char, unsigned char, unsigned int *, unsigned char);

static void wait_ring(unsigned char mode, unsigned short n)
{
    unsigned int w = 0;
    unsigned int acc;
    unsigned char i;
    unsigned short k;

    switch (mode) {
    case 1:
        for (;;) {
            if (DAT_a802cb97 > DAT_a802cb96)
                k = DAT_a802cb96 - DAT_a802cb97 + 36;
            else if (DAT_a802cb97 >= DAT_a802cb96)
                k = 36;
            else
                k = DAT_a802cb96 - DAT_a802cb97 - 1;
            if (n <= (unsigned short)(k << 4))
                break;
            FUN_a01350dc();
        }
        break;
    case 2:
        while (DAT_a802cb97 != DAT_a802cb96)
            FUN_a01350dc();
        break;
    case 3:
        while (DAT_a802cb97 != DAT_a802cb96)
            FUN_a01350dc();
        do {
            acc = 0;
            for (i = 0; i * 20 + 16 <= 0x50; i++) {
                func_0x4008c4d0(0, i * 20 + 16, &w, 1);
                acc |= w;
            }
        } while (acc != 0);
        break;
    }
}

void FUN_a0136054(void)
{
    unsigned char buf[14] = { 0 };
    unsigned long w[4] = { 0, 0, 0, 0 };
    unsigned short off;
    unsigned char idx, k = 1, cnt = 16, hi = 0, j, nw;
    unsigned int v[2];
    unsigned char *q;
    unsigned long *d;

    idx = FUN_a01250c4();
    FUN_a00df170(s_001a5540, idx);
    if (idx == 0xff)
        return;
    FUN_a014226c(FUN_a01421c4(FUN_a0142218(idx)));
    FUN_a0124b88(idx, v);
    if (idx != 5)
        k = idx != 6;
    buf[0] = (k << 2) | 0xf2;
    buf[1] = ((v[0] >> 11) & 1) | 0x60;
    buf[2] = 0xff;
    buf[3] = 1;
    buf[4] = 2;
    buf[5] = 1;
    buf[6] = 0xff;
    buf[7] = 1;
    buf[8] = 1;
    buf[9] = (v[0] >> 8) & 3;
    wait_ring(1, 10);
    for (off = 0; off < 10; off += 16) {
        if (10 - off < 16)
            cnt = 10 - off;
        FUN_a00df170(s_001a5550, buf[off], buf[off + 1], buf[off + 2], buf[off + 3], buf[off + 4], buf[off + 5],
                     buf[off + 6], buf[off + 7]);
        q = buf + off;
        nw = 4;
        d = w;
        for (j = 0; j < nw; j++) {
            d[j] = q[j * 4];
            d[j] = (d[j] << 8) + q[j * 4 + 1];
            d[j] = (d[j] << 8) + q[j * 4 + 2];
            d[j] = (d[j] << 8) + q[j * 4 + 3];
        }
        DAT_a802da6c[DAT_a802cb97].w[0] = (hi << 24) + (cnt << 16) + 0xb;
        DAT_a802da6c[DAT_a802cb97].w[1] = w[0];
        DAT_a802da6c[DAT_a802cb97].w[2] = w[1];
        DAT_a802da6c[DAT_a802cb97].w[3] = w[2];
        DAT_a802da6c[DAT_a802cb97].w[4] = w[3];
        if (++DAT_a802cb97 > 0x24)
            DAT_a802cb97 = 0;
        hi++;
    }
    wait_ring(3, 0);
}
