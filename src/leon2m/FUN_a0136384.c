/* leon2m FUN_a0136384 @ 0xa0136384-0xa0136600 (636 bytes) -mcpu=v8 -O3 -g. Caller: FUN_a01451fc.
 * Calls FUN_a0133384(), copies the 18 bytes DAT_a802d9a0[0..17] into a zeroed 22-byte local buffer and sends them as
 * message type 10.
 * The message is sent through the 37-entry ring DAT_a802da6c (20-byte entries; write index byte DAT_a802cb97, wraps
 * after 0x24; read index DAT_a802cb96) that FUN_a01350dc drains: first wait while 16 * (free ring entries) < len
 * (FUN_a01350dc in between); then per 16-byte chunk (index c from 0) the bytes are packed big-endian into
 * four words w[0..3] and an entry is written: word 0 = (c << 24) + (chunk length << 16) + 10, words 1..4 = w[0..3];
 * then wait until the ring is empty and until the four mailbox words at portal 0 offsets 0x10, 0x24, 0x38, 0x4C
 * (MailBox_Read func_0x4008c4d0) are all zero. The two waits are the mode 1 and mode 3 bodies of FUN_a01356fc,
 * written as a static helper inlined at -O3.
 * Source form: the buffer is declared before w (stack order); w and its packing pointer are unsigned long (alias set
 * of the ring stores, decides the store schedule); the chunk test is an unsigned compare ((unsigned int)(18 - off)
 * < 16); the packing loop compares with a limit variable nw = 4 (cmp 4; bcs).
 */
struct Msg { unsigned int w[5]; };
extern unsigned char DAT_a802cb96, DAT_a802cb97;
extern struct Msg DAT_a802da6c[];
extern unsigned char DAT_a802d9a0[];
extern void FUN_a0133384(void);
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

void FUN_a0136384(void)
{
    unsigned char buf[22] = { 0 };
    unsigned long w[4] = { 0, 0, 0, 0 };
    unsigned short i, off;
    unsigned char cnt = 16, hi = 0, j, nw;
    unsigned char *q;
    unsigned long *d;

    FUN_a0133384();
    for (i = 0; i < 18; i++)
        buf[i] = DAT_a802d9a0[i];
    wait_ring(1, 18);
    for (off = 0; off < 18; off += 16) {
        if ((unsigned int)(18 - off) < 16)
            cnt = 18 - off;
        q = buf + off;
        nw = 4;
        d = w;
        for (j = 0; j < nw; j++) {
            d[j] = q[j * 4];
            d[j] = (d[j] << 8) + q[j * 4 + 1];
            d[j] = (d[j] << 8) + q[j * 4 + 2];
            d[j] = (d[j] << 8) + q[j * 4 + 3];
        }
        DAT_a802da6c[DAT_a802cb97].w[0] = (hi << 24) + (cnt << 16) + 10;
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
