/* leon2m FUN_a0137b1c @ 0xa0137b1c-0xa0137b5c (16 words).
 * Builds a 4-byte buffer {a, b, 0, 0} and, unless a is 0xff, passes it to FUN_a01370dc(0x15, 4, buffer, 1).
 * Source form: the buffer starts cleared, the test a != 0xff is computed into a flag before the two byte stores.
 */
extern int FUN_a01370dc();

void FUN_a0137b1c(unsigned char a, unsigned char b)
{
    unsigned char buf[4] = { 0 };
    int valid = a != 0xff;

    buf[0] = a;
    buf[1] = b;
    if (valid)
        FUN_a01370dc(0x15, 4, buf, 1);
}
