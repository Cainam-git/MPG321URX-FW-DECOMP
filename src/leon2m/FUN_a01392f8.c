/* leon2m FUN_a01392f8 @ 0xa01392f8-0xa01393bc (49 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Sends an 18-byte buffer with FUN_a01370dc(0xfe, 0x12, buf, 1): bytes 0..15 = the eight halfwords at +8..+0x16 of
 * the record r, each low byte first; byte 16 = id; byte 17 = byte +5 of r. The buffer is an initialised array.
 */
struct Rec { unsigned char pad[5]; unsigned char b5; unsigned char pad6[2]; unsigned short h[8]; };
extern void FUN_a01370dc(int, int, unsigned char *, int);

void FUN_a01392f8(unsigned char id, struct Rec *r)
{
    unsigned char buf[18] = {0};

    buf[0] = r->h[0];
    buf[1] = r->h[0] >> 8;
    buf[2] = r->h[1];
    buf[3] = r->h[1] >> 8;
    buf[4] = r->h[2];
    buf[5] = r->h[2] >> 8;
    buf[6] = r->h[3];
    buf[7] = r->h[3] >> 8;
    buf[8] = r->h[4];
    buf[9] = r->h[4] >> 8;
    buf[10] = r->h[5];
    buf[11] = r->h[5] >> 8;
    buf[12] = r->h[6];
    buf[13] = r->h[6] >> 8;
    buf[14] = r->h[7];
    buf[15] = r->h[7] >> 8;
    buf[16] = id;
    buf[17] = r->b5;
    FUN_a01370dc(0xfe, 0x12, buf, 1);
}
