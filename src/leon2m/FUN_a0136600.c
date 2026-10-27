/* leon2m FUN_a0136600 @ 0xa0136600-0xa0136a10 (1040 bytes) -mcpu=v8 -O3 -g -msoft-float. Caller: FUN_a01451fc.
 * Calls FUN_a0132e1c() and FUN_a0133238(), then fills a zeroed 64-byte buffer: bytes 0..35 from the ROM table
 * DAT_001a5388 (mode 0) or DAT_001a5360 (mode 1, other modes leave them zero), bytes 36..47 from DAT_a802d9b8 and
 * 48..59 from DAT_a802da60. It calls FUN_a01350dc while 48 is above 16 * (free ring entries) (mode 1 body of
 * FUN_a01356fc) and sends the 60 bytes as message type 8; before each chunk, when FUN_a00dd614(0x20) returns
 * non-zero, the chunk's bytes 0..7 and 8..15 are printed with "data : %02X ..." (two separate tests).
 * The message goes through the 37-entry ring DAT_a802da6c (20-byte entries; write index byte DAT_a802cb97, wraps
 * after 0x24; read index DAT_a802cb96) that FUN_a01350dc drains: per 16-byte chunk (index c from the start value)
 * the bytes are packed big-endian into four words w[0..3] and an entry is written: word 0 = (c << 24) +
 * (chunk length << 16) + 8, words 1..4 = w[0..3]. Afterwards it waits until the ring is empty and until the
 * four mailbox words at portal 0 offsets 0x10, 0x24, 0x38, 0x4C (MailBox_Read func_0x4008c4d0) are all zero (the
 * mode 3 body of FUN_a01356fc, a static helper inlined at -O3).
 * Source form: as FUN_a0136384 (buffer declared before w, w unsigned long, unsigned chunk test).
 */
struct Msg { unsigned int w[5]; };
extern unsigned char DAT_a802cb96, DAT_a802cb97;
extern struct Msg DAT_a802da6c[];
extern const unsigned char DAT_001a5388[], DAT_001a5360[];
extern unsigned char DAT_a802d9b8[], DAT_a802da60[];
extern void FUN_a0132e1c(void);
extern void FUN_a0133238(void);
extern unsigned char FUN_a00dd614(unsigned int level);
extern int FUN_a00df170(const char *fmt, ...);
extern const char s_001a5550[];
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

void FUN_a0136600(unsigned char mode)
{
    unsigned char buf[64] = { 0 };
    unsigned long w[4] = { 0, 0, 0, 0 };
    unsigned short i, off;
    unsigned char cnt = 16, hi = 0, j, nw;
    unsigned char *q;
    unsigned long *d;

    FUN_a0132e1c();
    FUN_a0133238();
    if (mode == 0) {
        for (i = 0; i < 36; i++)
            buf[i] = DAT_001a5388[i];
    } else if (mode == 1) {
        for (i = 0; i < 36; i++)
            buf[i] = DAT_001a5360[i];
    }
    for (i = 0; i < 12; i++)
        buf[36 + i] = DAT_a802d9b8[i];
    for (i = 0; i < 12; i++)
        buf[48 + i] = DAT_a802da60[i];
    wait_ring(1, 48);
    for (off = 0; off < 60; off += 16) {
        if ((unsigned int)(60 - off) < 16)
            cnt = 60 - off;
        if (FUN_a00dd614(0x20))
            FUN_a00df170(s_001a5550, buf[off], buf[off + 1], buf[off + 2], buf[off + 3], buf[off + 4], buf[off + 5],
                         buf[off + 6], buf[off + 7]);
        if (FUN_a00dd614(0x20))
            FUN_a00df170(s_001a5550, buf[off + 8], buf[off + 9], buf[off + 10], buf[off + 11], buf[off + 12],
                         buf[off + 13], buf[off + 14], buf[off + 15]);
        q = buf + off;
        nw = 4;
        d = w;
        for (j = 0; j < nw; j++) {
            d[j] = q[j * 4];
            d[j] = (d[j] << 8) + q[j * 4 + 1];
            d[j] = (d[j] << 8) + q[j * 4 + 2];
            d[j] = (d[j] << 8) + q[j * 4 + 3];
        }
        DAT_a802da6c[DAT_a802cb97].w[0] = (hi << 24) + (cnt << 16) + 8;
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
