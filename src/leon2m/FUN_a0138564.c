/* leon2m FUN_a0138564 @ 0xa0138564-0xa0138610 (43 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a014f6f4.
 * Sends the 4-byte buffer {p[0] with its bit order reversed, p[2], p[1] >> 6, (p[1] >> 4) & 3} with
 * FUN_a01370dc(0x90, 4, buf, 0). The buffer is an initialised 4-byte array. p[0] is read into an unsigned char
 * and copied into an unsigned int for the shifts (and 0xff after the load); bit 0 is taken from the byte.
 */
extern void FUN_a01370dc(int, int, unsigned char *, int);

void FUN_a0138564(unsigned char *p)
{
    unsigned char buf[4] = {0};
    unsigned char c = p[0];
    unsigned int x = c;

    buf[0] = (x >> 7) | ((x >> 5) & 2) | ((x >> 3) & 4) | ((x >> 1) & 8) | ((x << 1) & 0x10) | ((x << 3) & 0x20) |
             ((x << 5) & 0x40) | ((c & 1) << 7);
    buf[1] = p[2];
    buf[2] = p[1] >> 6;
    buf[3] = (p[1] >> 4) & 3;
    FUN_a01370dc(0x90, 4, buf, 0);
}
