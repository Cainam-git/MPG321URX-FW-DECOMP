/* FUN_a00a8508 (leon2s 0xa00a8508-0xa00a8694, 396 bytes), flags -mcpu=v8 -Os -g.
 * Updates words of the register block pk (+0x30 of the 0x34-byte record ARR_a807db00[port]) from the bytes
 * d[0..3], by sel: 0: word 0xa8 = (word & ~0xe0000000) | d[0] << 24 and word 0xac = (word & ~0x3fffff) |
 * d[1] | d[2] << 8 | d[3] << 16; 1 / 2: word 0xe8 / 0xec = (word & ~0x3fffffe0) | the little-endian word of
 * d[0..3]. Other values print s_a006c180 ("HDMI21RX2PacketSwitch WRONG selection!!!"). The values are built in
 * a zeroed local pair first.
 * Source form: the read-modify-write is an inlined helper that reads the register into a local, combines
 * '(v & ~mask) | val' into it and stores it back.
 */
struct Port34 { unsigned char pad[0x30]; volatile unsigned int *pk; };
struct Pair { unsigned int w0; unsigned int w1; };
extern struct Port34 ARR_a807db00[];
extern char s_a006c180[];
extern int FUN_a0073044(const char *, ...);

static inline void wr(volatile unsigned int *p, unsigned int mask, unsigned int val)
{
    unsigned int v = *p;

    v = (v & ~mask) | val;
    *p = v;
}

void FUN_a00a8508(unsigned char port, unsigned char sel, unsigned char *d)
{
    struct Pair s = { 0, 0 };

    switch (sel) {
    case 0:
        s.w0 = d[0] << 24;
        s.w1 = d[1] | d[2] << 8 | d[3] << 16;
        wr(&ARR_a807db00[port].pk[0xa8 / 4], 0xe0000000, s.w0);
        wr(&ARR_a807db00[port].pk[0xac / 4], 0x3fffff, s.w1);
        break;
    case 1:
        s.w0 = d[0] | d[1] << 8 | d[2] << 16 | d[3] << 24;
        wr(&ARR_a807db00[port].pk[0xe8 / 4], 0x3fffffe0, s.w0);
        break;
    case 2:
        s.w0 = d[0] | d[1] << 8 | d[2] << 16 | d[3] << 24;
        wr(&ARR_a807db00[port].pk[0xec / 4], 0x3fffffe0, s.w0);
        break;
    default:
        FUN_a0073044(s_a006c180);
        break;
    }
}
