/* leon2m FUN_a013832c @ 0xa013832c-0xa013844c (72 words), flags -mcpu=v8 -O3 -g. Called from FUN_a012bc08.
 * Packs a record into a 24-byte buffer and passes it to FUN_a01370dc(0x50, 0x18, buf, 0): buf[0] = id;
 * buf[1] = bits 25, 27, 28, 29, 30, 31 of word 0 as bits 5..0; buf[2], buf[3] = bytes 1 and 2 of the record;
 * buf[4], buf[5] = low two bytes of the signed word at +0x14; buf[6], buf[7] = bytes +0x18, +0x19; buf[8..23] = the
 * eight halfwords at +4..+0x12, low byte first. The single bits of word 0 are bit-fields of an unsigned int, which
 * gives the one word load with shifts.
 */
struct Rec {
    unsigned int f31 : 1, f30 : 1, f29 : 1, f28 : 1, f27 : 1, f26 : 1, f25 : 1, f24 : 1, rest : 24;
    unsigned short h4, h6, h8, ha, hc, he, h10, h12;
    int w14;
    unsigned char b18, b19;
};
extern void FUN_a01370dc(int, int, unsigned char *, int);

void FUN_a013832c(unsigned char id, struct Rec *r)
{
    unsigned char buf[24];

    buf[0] = id;
    buf[1] = (r->f25 << 5) | (r->f27 << 4) | (r->f28 << 3) | (r->f29 << 2) | (r->f30 << 1) | r->f31;
    buf[2] = ((unsigned char *)r)[1];
    buf[3] = ((unsigned char *)r)[2];
    buf[4] = r->w14;
    buf[5] = r->w14 >> 8;
    buf[6] = r->b18;
    buf[7] = r->b19;
    buf[8] = r->h4;
    buf[9] = r->h4 >> 8;
    buf[10] = r->h6;
    buf[11] = r->h6 >> 8;
    buf[12] = r->h8;
    buf[13] = r->h8 >> 8;
    buf[14] = r->ha;
    buf[15] = r->ha >> 8;
    buf[16] = r->hc;
    buf[17] = r->hc >> 8;
    buf[18] = r->he;
    buf[19] = r->he >> 8;
    buf[20] = r->h10;
    buf[21] = r->h10 >> 8;
    buf[22] = r->h12;
    buf[23] = r->h12 >> 8;
    FUN_a01370dc(0x50, 0x18, buf, 0);
}
