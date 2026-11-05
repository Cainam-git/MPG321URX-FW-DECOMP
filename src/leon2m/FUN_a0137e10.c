/* FUN_a0137e10 (leon2m 0xa0137e10-0xa0137fa0, 400 bytes), flags -mcpu=v8 -O3 -g.
 * Builds a 32-byte message in a stack buffer from the record p and sends it with FUN_a01370dc(0x42, 0x20, buf, 0).
 * buf[0] = id, buf[1] = byte +3, buf[2] / buf[3] = low / high byte of halfword +4, buf[5] = byte +7,
 * buf[8] = byte +8, buf[9] = byte +0xb, buf[11..13] = bytes +0xc..+0xe, buf[14] = 0, buf[18] = byte +0xf,
 * buf[6] = byte +0xa << 4 | byte +9. Bit bytes from halfword +0 (bits a15..a0) and halfword +2 (bits c15..c12):
 * buf[4] = a13 << 7 | a11 << 6 | a10 << 5 | byte +6; buf[7] = a12, a9, a8, a14, a5, a4, a3 at bits 0..6 and
 * c12 at bit 7; buf[10] = a7, a6, a2, a1, a0 at bits 0..4 and c15, c14, c13 at bits 5..7. The other buffer
 * bytes are not written. No direct callers found.
 * Source form: stores in ascending buffer order; byte +3 is a separate unsigned char member after the 8 bits of
 * halfword +2; the c15 term is written '(unsigned char)p->c15 << 5' (the bit is masked with 'and 0xff' before
 * the shift, as in the code).
 */
struct Rec {
    unsigned short a15:1, a14:1, a13:1, a12:1, a11:1, a10:1, a9:1, a8:1,
                   a7:1, a6:1, a5:1, a4:1, a3:1, a2:1, a1:1, a0:1;
    unsigned short c15:1, c14:1, c13:1, c12:1, c_r:4;
    unsigned char lo;
    unsigned short h4;
    unsigned char b6, b7, b8, b9, ba, bb, bc, bd, be, bf;
};
extern void FUN_a01370dc(unsigned int cmd, unsigned char len, unsigned char *p, unsigned char wait);

void FUN_a0137e10(unsigned char id, struct Rec *p)
{
    unsigned char buf[32];

    buf[0] = id;
    buf[1] = p->lo;
    buf[2] = p->h4;
    buf[3] = p->h4 >> 8;
    buf[4] = p->a13 << 7 | p->a11 << 6 | p->a10 << 5 | p->b6;
    buf[5] = p->b7;
    buf[6] = p->ba << 4 | p->b9;
    buf[7] = p->a12 | p->a9 << 1 | p->a8 << 2 | p->a14 << 3 | p->a5 << 4 | p->a4 << 5 | p->a3 << 6 | p->c12 << 7;
    buf[8] = p->b8;
    buf[9] = p->bb;
    buf[10] = p->a7 | p->a6 << 1 | p->a2 << 2 | p->a1 << 3 | p->a0 << 4 | (unsigned char)p->c15 << 5 | p->c14 << 6 | p->c13 << 7;
    buf[11] = p->bc;
    buf[12] = p->bd;
    buf[13] = p->be;
    buf[14] = 0;
    buf[18] = p->bf;
    FUN_a01370dc(0x42, 0x20, buf, 0);
}
