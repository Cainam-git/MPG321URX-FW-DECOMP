/* leon2m FUN_a013797c @ 0xa013797c-0xa0137a68 (59 words), flags -mcpu=v8 -O3 -g. Callers: FUN_a012b260,
 * FUN_a012b458.
 * Sends a 9-byte buffer with FUN_a01370dc(0x20, 9, buf, 1): buf[0] = id, buf[1] = p[0], buf[2] = p[1],
 * buf[3] = p[3] | p[4] << 1 | p[5] << 2 | p[6] << 3 | p[7] << 4, buf[4] = p[8],
 * buf[5] = p[9] | p[0xb] << 2 | p[0xc] << 3 | p[0xd] << 4 | p[0xe] << 5 | p[0xf] << 6 | p[0x10] << 7, buf[6] and
 * buf[7] = the halfword at p + 0x12 (low byte first), buf[8] = p[2]. Same form as FUN_a0137a68; the order of the
 * byte statements is the one that reproduces the firmware schedule.
 */
extern void FUN_a01370dc(int, int, unsigned char *, int);

void FUN_a013797c(unsigned char id, unsigned char *p)
{
    unsigned char buf[9] = {0};

    buf[0] = id;
    buf[1] = p[0];
    buf[2] = p[1];
    buf[3] = p[3] | p[4] << 1 | p[5] << 2 | p[6] << 3 | p[7] << 4;
    buf[5] = p[9] | p[0xb] << 2 | p[0xc] << 3 | p[0xd] << 4 | p[0xe] << 5 | p[0xf] << 6 | p[0x10] << 7;
    buf[4] = p[8];
    buf[6] = *(unsigned short *)(p + 0x12);
    buf[7] = *(unsigned short *)(p + 0x12) >> 8;
    buf[8] = p[2];
    FUN_a01370dc(0x20, 9, buf, 1);
}
