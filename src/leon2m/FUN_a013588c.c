/* leon2m FUN_a013588c @ 0xa013588c-0xa0135ae4 (604 bytes) -mcpu=v8 -O3 -g -msoft-float. Callers: FUN_a01405d0 (two
 * calls), FUN_a0140e74.
 * Sends len bytes from p as message type 7 with the low nibble of addr in byte 1 of each header word; chunk
 * indexes start at addr >> 4. First it calls FUN_a01350dc while len is above 16 * (free ring entries).
 * The message goes through the 37-entry ring DAT_a802da6c (20-byte entries; write index byte DAT_a802cb97, wraps
 * after 0x24; read index DAT_a802cb96) that FUN_a01350dc drains: per 16-byte chunk (index c from the start value)
 * the bytes are packed big-endian into four words w[0..3] and an entry is written: word 0 = (c << 24) +
 * (chunk length << 16) + ((addr & 0xf) << 8) + 7, words 1..4 = w[0..3]. Afterwards it waits until the ring is
 * empty and until the four mailbox words at portal 0 offsets 0x10, 0x24, 0x38, 0x4C (MailBox_Read func_0x4008c4d0) are all zero (the
 * mode 3 body of FUN_a01356fc, a static helper inlined at -O3).
 * Source form: the free-entry count is a static helper (the mode 1 test of FUN_a01356fc) used in a while
 * condition; w is unsigned long (alias set of the ring stores); lo is an int masked to a byte at its use; the
 * packing loop compares with a limit variable nw = 4. -msoft-float decides which loop invariants are hoisted.
 */
struct Msg { unsigned int w[5]; };
extern unsigned char DAT_a802cb96, DAT_a802cb97;
extern struct Msg DAT_a802da6c[];
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

static unsigned short ring_free(void)
{
    unsigned short k;

    if (DAT_a802cb97 > DAT_a802cb96)
        k = DAT_a802cb96 - DAT_a802cb97 + 36;
    else if (DAT_a802cb97 >= DAT_a802cb96)
        k = 36;
    else
        k = DAT_a802cb96 - DAT_a802cb97 - 1;
    return k << 4;
}

void FUN_a013588c(unsigned short addr, unsigned short len, unsigned char *p)
{
    unsigned long w[4] = { 0, 0, 0, 0 };
    unsigned short off;
    unsigned char cnt = len > 15 ? 16 : len, j, nw;
    unsigned char hi = addr >> 4;
    int lo = addr & 0xf;
    unsigned char *q;
    unsigned long *d;

    while (len > ring_free())
        FUN_a01350dc();
    for (off = 0; off < len; off += 16) {
        if (len - off < 16)
            cnt = len - off;
        q = p + off;
        nw = 4;
        d = w;
        for (j = 0; j < nw; j++) {
            d[j] = q[j * 4];
            d[j] = (d[j] << 8) + q[j * 4 + 1];
            d[j] = (d[j] << 8) + q[j * 4 + 2];
            d[j] = (d[j] << 8) + q[j * 4 + 3];
        }
        DAT_a802da6c[DAT_a802cb97].w[0] = (hi << 24) + (cnt << 16) + ((unsigned char)lo << 8) + 7;
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
