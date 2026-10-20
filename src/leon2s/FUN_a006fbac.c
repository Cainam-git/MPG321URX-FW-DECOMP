/* leon2s FUN_a006fbac @ 0xa006fbac  build the 4-word mailbox descriptor of one input port
 * -Os).
 *
 * rec = port record 0xA807A824 + 20 * n. buf[0] = id | rec[0xd] << 8 | rec[0xe] << 16 (written in three steps);
 * buf[1] = rec[0xc] | (rec[0x12] & 0x1f) << 8 | rec h2 << 16; buf[2] = h4 | h6 << 16; buf[3] = h8 | ha << 16;
 * then FUN_a006fb3c(buf, 4). Caller: FUN_a00700cc (id = port id, n = id - 1), which publishes buf through
 * FUN_a006fad4 to mailbox portal 1 slot <port>, where the Big chip's FUN_a01387a4 reads it: buf[0] byte 1 = rec[0xd]
 * = the flags byte whose bit 2 is the line-rate switch (set by FUN_a006d61c from the VRR
 * detector FUN_a008f79c).
 * key: buf[1] written as 'buf[1] = buf[1] | a | b' (left to right), not 'buf[1] |= a | b'.
 */
struct PortRec { unsigned char b0, b1; unsigned short h2, h4, h6, h8, ha; unsigned char bc, bd, be, bf, b10, b11, b12, b13; };
extern struct PortRec DAT_a807a824[];
extern void FUN_a006fb3c(unsigned int *buf, unsigned char n);

void FUN_a006fbac(unsigned char id, unsigned char n, unsigned int *buf)
{
    struct PortRec *r = &DAT_a807a824[n];
    buf[0] = id;
    buf[0] |= r->bd << 8;
    buf[0] |= r->be << 16;
    buf[1] = r->bc;
    buf[1] = buf[1] | (r->b12 & 0x1f) << 8 | r->h2 << 16;
    buf[2] = r->h4 | r->h6 << 16;
    buf[3] = r->h8 | r->ha << 16;
    FUN_a006fb3c(buf, 4);
}
