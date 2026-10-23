/* leon2m FUN_a012ec24 @ 0xa012ec24-0xa012eeb0 (-mcpu=v8 -O3 -g).
 * Unpacks 10-bit values from s: s[0] holds the low 2-bit groups of the first value, s[1] its high byte; from i = 2 on,
 * every byte at an index divisible by 5 supplies the low 2-bit groups of the next four values (value =
 * ((s[i] << 2) + low 2 bits) << 4). For each new value b the four points (k * b + (4 - k) * a) >> 2, k = 0..3, from
 * the previous value a are written as 8 bytes (point << 2, point >> 6) with FUN_a010ae8c(ch, idx, 8, buf), idx += 4.
 * The last value (s[0x13f], + 0xf) gives eight points (k * b + (8 - k) * a) >> 3 with the last point b, written as
 * 16 bytes with FUN_a010ae8c(ch, idx, 16, buf).
 * Source form: the first byte is read into an unsigned char and then shifted in the 16-bit variable as two
 * statements ('lo = c; lo >>= 2;'), which gives the firmware's srl / and 0x3f.
 */
extern void FUN_a010ae8c(int, int, int, unsigned char *);

void FUN_a012ec24(unsigned char ch, const unsigned char *s)
{
    unsigned char buf[16];
    unsigned short tmp[8];
    unsigned short i, k, idx, lo;
    unsigned int a, b;

    {
        unsigned char c = s[0];

        a = ((s[1] << 2) + (c & 3)) << 4;
        lo = c;
        lo >>= 2;
    }
    idx = 0;    for (i = 2; i < 0x13f; i++) {
        if (i % 5 == 0) {
            lo = s[i];
            i++;
        }
        b = ((s[i] << 2) + (lo & 3)) << 4;
        lo >>= 2;
        for (k = 0; k < 4; k++)
            tmp[k] = (k * b + (4 - k) * a) >> 2;
        buf[0] = tmp[0] << 2;
        buf[1] = tmp[0] >> 6;
        buf[2] = tmp[1] << 2;
        buf[3] = tmp[1] >> 6;
        buf[4] = tmp[2] << 2;
        buf[5] = tmp[2] >> 6;
        buf[6] = tmp[3] << 2;
        buf[7] = tmp[3] >> 6;
        FUN_a010ae8c(ch, idx, 8, buf);
        a = b;
        idx += 4;
    }
    b = (((s[0x13f] << 2) + (lo & 3)) << 4) + 0xf;
    for (k = 0; k < 8; k++)
        tmp[k] = (k * b + (8 - k) * a) >> 3;
    tmp[7] = b;
    buf[0] = tmp[0] << 2;
    buf[1] = tmp[0] >> 6;
    buf[2] = tmp[1] << 2;
    buf[3] = tmp[1] >> 6;
    buf[4] = tmp[2] << 2;
    buf[5] = tmp[2] >> 6;
    buf[6] = tmp[3] << 2;
    buf[7] = tmp[3] >> 6;
    buf[8] = tmp[4] << 2;
    buf[9] = tmp[4] >> 6;
    buf[10] = tmp[5] << 2;
    buf[11] = tmp[5] >> 6;
    buf[12] = tmp[6] << 2;
    buf[13] = tmp[6] >> 6;
    buf[14] = tmp[7] << 2;
    buf[15] = tmp[7] >> 6;
    FUN_a010ae8c(ch, idx, 16, buf);
}
