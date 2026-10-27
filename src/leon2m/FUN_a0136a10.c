/* leon2m FUN_a0136a10 @ 0xa0136a10 (-mcpu=v8 -O3 -g). Called by FUN_a012c188 and FUN_a012c80c.
 * Parameters (addr, len, p). First calls FUN_a01350dc while len is above 16 * (free ring entries) (mode 1 body of
 * FUN_a01356fc). Then for each 16-byte chunk at offset off < len (chunk length cnt = 16, or len - off for the last):
 * when FUN_a00dd614(0x20) returns non-zero, prints "ofst_u %x\n" with hi (byte, (addr >> 4) + chunk number), "len_u %x "
 * with cnt and "data : %02X ..." with the chunk's bytes 0..7 (three separate tests); packs the 16 bytes big-endian
 * into the words w[0..3]; writes the entry DAT_a802da6c[DAT_a802cb97]: word 0 = (hi << 24) + (cnt << 16) + 1,
 * words 1..4 = w[0..3]; advances DAT_a802cb97 (back to 0 after 0x24) and runs the mode 3 body of FUN_a01356fc
 * (drain the ring, then wait until the mailbox words at portal 0 offsets 0x10, 0x24, 0x38, 0x4C are all zero).
 * Source form: FUN_a01356fc is a static helper inlined at -O3; p is a byte pointer and the chunk address is kept as
 * an unsigned int (q = (unsigned int)p + off) and cast at each byte read, so every partial word of the packing is
 * stored to w[j]; w is unsigned long.
 */
struct Msg { unsigned int w[5]; };
extern unsigned char DAT_a802cb96, DAT_a802cb97;
extern struct Msg DAT_a802da6c[];
extern void FUN_a01350dc(void);
extern unsigned char FUN_a00dd614(unsigned int level);
extern int FUN_a00df170(const char *fmt, ...);
extern const char s_001a5550[], s_001a5588[], s_001a5598[];
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

void FUN_a0136a10(unsigned short addr, unsigned short len, unsigned char * p)
{
    unsigned long w[4] = { 0, 0, 0, 0 };
    unsigned short off;
    unsigned char cnt, hi, j, nw;
    unsigned int q;
    unsigned long *d;

    wait_ring(1, len);
    hi = addr >> 4;
    cnt = 16;
    for (off = 0; off < len; off += 16) {
        if (len - off < 16)
            cnt = len - off;
        if (FUN_a00dd614(0x20))
            FUN_a00df170(s_001a5598, hi);
        if (FUN_a00dd614(0x20))
            FUN_a00df170(s_001a5588, cnt);
        q = (unsigned int)p + off;
        if (FUN_a00dd614(0x20))
            FUN_a00df170(s_001a5550, ((unsigned char *)q)[0], ((unsigned char *)q)[1], ((unsigned char *)q)[2], ((unsigned char *)q)[3], ((unsigned char *)q)[4], ((unsigned char *)q)[5], ((unsigned char *)q)[6], ((unsigned char *)q)[7]);
        nw = 4;
        d = w;
        for (j = 0; j < nw; j++) {
            d[j] = ((unsigned char *)q)[j * 4 + 0];
            d[j] = (d[j] << 8) + ((unsigned char *)q)[j * 4 + 1];
            d[j] = (d[j] << 8) + ((unsigned char *)q)[j * 4 + 2];
            d[j] = (d[j] << 8) + ((unsigned char *)q)[j * 4 + 3];
        }
        DAT_a802da6c[DAT_a802cb97].w[0] = (hi << 24) + (cnt << 16) + 1;
        DAT_a802da6c[DAT_a802cb97].w[1] = w[0];
        DAT_a802da6c[DAT_a802cb97].w[2] = w[1];
        DAT_a802da6c[DAT_a802cb97].w[3] = w[2];
        DAT_a802da6c[DAT_a802cb97].w[4] = w[3];
        if (++DAT_a802cb97 > 0x24)
            DAT_a802cb97 = 0;
        hi++;
        wait_ring(3, 0);
    }
}
