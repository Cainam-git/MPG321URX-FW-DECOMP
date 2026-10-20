/* FUN_a008fea8 (leon2s 0xa008fea8-0xa008ff08, 96 bytes), flags -mcpu=v8 -Os -g.
 * Returns 1 when bit 1 of FUN_a00a657c(port, 0x134) is set, the low byte of FUN_a00a657c(port, 0x140) is 0x82
 * and FUN_a008fb5c(port) returns non-zero; else 0. Source form: a result byte set to 1 or 0 in an if/else and
 * returned as r & 1.
 */
extern unsigned int FUN_a00a657c(unsigned char, unsigned short);
extern unsigned char FUN_a008fb5c(unsigned char);

unsigned char FUN_a008fea8(unsigned char port)
{
    unsigned char r;

    if ((FUN_a00a657c(port, 0x134) & 2) && (unsigned char)FUN_a00a657c(port, 0x140) == 0x82 &&
        FUN_a008fb5c(port) != 0)
        r = 1;
    else
        r = 0;
    return r & 1;
}
