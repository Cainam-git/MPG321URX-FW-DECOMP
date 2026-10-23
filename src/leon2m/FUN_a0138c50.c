/* leon2m FUN_a0138c50 @ 0xa0138c50-0xa0138e28 (118 words).
 * Builds a 24-byte message (zeroed first) and sends it with FUN_a01370dc(0xa5, 0x18, buf, 0): byte 0 = id, bytes
 * 1..3 = bytes 5, 7 and 4 of the record p, bytes 4..19 = its eight halfwords at +8..+0x16 (low byte first), and
 * for p->b5 = 0 / 2 / 3 bytes 20..23 from hardware registers: two bits of 0xcf014740 (bits 6..7 / 2..3 / 0..1)
 * ORed with register 0xcf012894 / 0xcf012914 / 0xcf012954, then the registers 0x10 / 0xc / 8 below it.
 * No direct callers (reached through a pointer). volatile: hardware registers only.
 * Source form: an if/else-if chain on p->b5 (a switch gives a compare tree).
 */
#define R(a) (*(volatile unsigned int *)(a))

struct Info { unsigned char b0, b1, b2, b3, b4, b5, b6, b7; unsigned short h[8]; };
extern void FUN_a01370dc(int, int, unsigned char *, int);

void FUN_a0138c50(unsigned char id, struct Info *p)
{
    unsigned char buf[24] = { 0 };

    buf[0] = id;
    buf[1] = p->b5;
    buf[2] = p->b7;
    buf[3] = p->b4;
    buf[4] = p->h[0];
    buf[5] = p->h[0] >> 8;
    buf[6] = p->h[1];
    buf[7] = p->h[1] >> 8;
    buf[8] = p->h[2];
    buf[9] = p->h[2] >> 8;
    buf[10] = p->h[3];
    buf[11] = p->h[3] >> 8;
    buf[12] = p->h[4];
    buf[13] = p->h[4] >> 8;
    buf[14] = p->h[5];
    buf[15] = p->h[5] >> 8;
    buf[16] = p->h[6];
    buf[17] = p->h[6] >> 8;
    buf[18] = p->h[7];
    buf[19] = p->h[7] >> 8;
    if (p->b5 == 0) {
            buf[20] = (R(0xcf014740) >> 6) & 3;
            buf[20] |= R(0xcf012894);
            buf[21] = R(0xcf012884);
            buf[22] = R(0xcf012888);
            buf[23] = R(0xcf01288c);
    } else if (p->b5 == 2) {
            buf[20] = (R(0xcf014740) >> 2) & 3;
            buf[20] |= R(0xcf012914);
            buf[21] = R(0xcf012904);
            buf[22] = R(0xcf012908);
            buf[23] = R(0xcf01290c);
    } else if (p->b5 == 3) {
            buf[20] = R(0xcf014740) & 3;
            buf[20] |= R(0xcf012954);
            buf[21] = R(0xcf012944);
            buf[22] = R(0xcf012948);
            buf[23] = R(0xcf01294c);
    }
    FUN_a01370dc(0xa5, 0x18, buf, 0);
}
