/* leon2m FUN_a0138f2c @ 0xa0138f2c-0xa0138fb8 (35 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Sends the 4-byte buffer {bits, 0, 0, 0} with FUN_a01370dc(0xa3, 4, buf, 0), where bit 0..3 of bits is set when
 * a, b, c or d (in that order) is 1. The buffer is an initialised 4-byte array; the bits are ored into byte 0 after
 * the clear (the byte is read back from the stack).
 */
extern void FUN_a01370dc(int, int, unsigned char *, int);

void FUN_a0138f2c(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    unsigned char buf[4] = {0};

    buf[0] |= a == 1;
    buf[0] |= (b == 1) << 1;
    buf[0] |= (c == 1) << 2;
    buf[0] |= (d == 1) << 3;
    FUN_a01370dc(0xa3, 4, buf, 0);
}
