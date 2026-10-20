/* leon2m FUN_a0138fb8 @ 0xa0138fb8-0xa0139040 (34 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a00dd5b8.
 * Sends the three words a, b and c, each as four bytes with the lowest byte first, in a 12-byte buffer with
 * FUN_a01370dc(0xa6, 12, buf, 0). The buffer is an initialised 12-byte array (std + st of zero first).
 */
extern void FUN_a01370dc(int, int, unsigned char *, int);

void FUN_a0138fb8(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned char buf[12] = {0};

    buf[0] = a;
    buf[1] = a >> 8;
    buf[2] = a >> 16;
    buf[3] = a >> 24;
    buf[4] = b;
    buf[5] = b >> 8;
    buf[6] = b >> 16;
    buf[7] = b >> 24;
    buf[8] = c;
    buf[9] = c >> 8;
    buf[10] = c >> 16;
    buf[11] = c >> 24;
    FUN_a01370dc(0xa6, 12, buf, 0);
}
