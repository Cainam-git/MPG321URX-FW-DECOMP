/* leon2m FUN_a0135dc0 @ 0xa0135dc0-0xa0136054 (660 bytes) -mcpu=v8 -O3 -g. Caller: FUN_a01451fc.
 * Copies the 48 bytes at DAT_001a53ac into a local buffer (FUN_a013c910 = memcpy), sets all 48 bytes to 0xff, gets
 * len = FUN_a0152e28(buffer) and sends len bytes of the buffer as message type 9.
 * The message is sent through the 37-entry ring DAT_a802da6c (20-byte entries; write index byte DAT_a802cb97, wraps
 * after 0x24; read index DAT_a802cb96) that FUN_a01350dc drains: first wait while 16 * (free ring entries) < len
 * (FUN_a01350dc in between); then per 16-byte chunk (index c from 0) the bytes are packed big-endian into
 * four words w[0..3] and an entry is written: word 0 = (c << 24) + (chunk length << 16) + 9, words 1..4 = w[0..3];
 * then wait until the ring is empty and until the four mailbox words at portal 0 offsets 0x10, 0x24, 0x38, 0x4C
 * (MailBox_Read func_0x4008c4d0) are all zero. The two waits are the mode 1 and mode 3 bodies of FUN_a01356fc,
 * written as a static helper inlined at -O3.
 * Source form: as FUN_a0136384; w is declared in a block after the copy call (its zeroing follows the call); the
 * chunk test is the signed len - off < 16.
 */
struct Msg { unsigned int w[5]; };
extern unsigned char DAT_a802cb96, DAT_a802cb97;
extern struct Msg DAT_a802da6c[];
extern const unsigned char DAT_001a53ac[];
extern void *FUN_a013c910(void *dst, const void *src, unsigned int n);
extern unsigned char FUN_a0152e28(unsigned int x);
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

void FUN_a0135dc0(void)
{
    unsigned char buf[48];

    FUN_a013c910(buf, DAT_001a53ac, 0x30);
    {
        unsigned long w[4] = { 0, 0, 0, 0 };
        unsigned short i, off;
        unsigned char len;
        unsigned char cnt = 16, hi = 0, j, nw;
        unsigned char *q;
        unsigned long *d;

        for (i = 0; i < 48; i++)
            buf[i] = 0xff;
        len = FUN_a0152e28((unsigned int)buf);
        wait_ring(1, len);
        for (off = 0; off < len; off += 16) {
            if (len - off < 16)
                cnt = len - off;
            q = buf + off;
            nw = 4;
            d = w;
            for (j = 0; j < nw; j++) {
                d[j] = q[j * 4];
                d[j] = (d[j] << 8) + q[j * 4 + 1];
                d[j] = (d[j] << 8) + q[j * 4 + 2];
                d[j] = (d[j] << 8) + q[j * 4 + 3];
            }
            DAT_a802da6c[DAT_a802cb97].w[0] = (hi << 24) + (cnt << 16) + 9;
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
}
