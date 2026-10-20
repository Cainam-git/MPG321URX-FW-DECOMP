/* leon2m FUN_a0137a68 @ 0xa0137a68-0xa0137aec (33 words), flags -mcpu=v8 -O3 -g. Callers: FUN_a012add8,
 * FUN_a012af40, FUN_a012b078, FUN_a012b164.
 * Sends a 9-byte buffer with FUN_a01370dc(0x21, 9, buf, 1): buf[0] = id, buf[1] = p[0], buf[2] = p[1],
 * buf[3] = p[3] | p[4] << 1 | p[5] << 2 | p[6] << 3 | p[7] << 4, buf[8] = p[2], the other bytes 0.
 * The buffer is an initialised 9-byte array (std of the first 8 bytes; the clear of byte 8 is dropped because it
 * is stored later).
 */
extern void FUN_a01370dc(int, int, unsigned char *, int);

void FUN_a0137a68(unsigned char id, unsigned char *p)
{
    unsigned char buf[9] = {0};

    buf[0] = id;
    buf[3] = p[3] | p[4] << 1 | p[5] << 2 | p[6] << 3 | p[7] << 4;
    buf[1] = p[0];
    buf[2] = p[1];
    buf[8] = p[2];
    FUN_a01370dc(0x21, 9, buf, 1);
}
