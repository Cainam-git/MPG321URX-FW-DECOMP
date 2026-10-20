/* leon2m FUN_a00deea4 @ 0xa00deea4-0xa00deef0 (19 words).
 * Takes one byte from the 128-byte ring buffer at 0xa802b0ec: returns 0 when the write index (byte +0x80)
 * equals the read index (byte +0x81); otherwise stores buffer[read index] through out, advances the read index
 * (wrapping to 0 at 0x80) and returns 1.
 */
struct Ring {
    unsigned char buf[0x80];
    unsigned char b80;
    unsigned char b81;
};
extern struct Ring DAT_a802b0ec;

int FUN_a00deea4(unsigned char *out)
{
    unsigned char n;

    if (DAT_a802b0ec.b80 == DAT_a802b0ec.b81)
        return 0;
    *out = DAT_a802b0ec.buf[DAT_a802b0ec.b81];
    n = DAT_a802b0ec.b81 + 1;
    if (n & 0x80)
        DAT_a802b0ec.b81 = 0;
    else
        DAT_a802b0ec.b81 = n;
    return 1;
}
