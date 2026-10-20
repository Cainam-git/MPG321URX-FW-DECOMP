/* leon2m FUN_a00b3708 @ 0xa00b3708-0xa00b37a4 (39 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a0146b50(0x6f, 0); FUN_a0146b6c(2, 0); FUN_a01577f4(buf[8] at %fp-16, 0x1981d0, v) (number to
 * text); i = index of the first 0 byte in buf[0..3] (4 if none; the scan reads buf itself); buf[0] = i - 1 (length
 * prefix, set on both exits of the scan); FUN_a00a31a4(0, x & 0xff, y & 0xff, 3, buf, 0). 3 params, void.
 * Source form: u8/void prototypes.
 * Compiler aids: none.
 */
extern void FUN_a0146b50(unsigned int, unsigned char);
extern void FUN_a0146b6c(unsigned int, unsigned int);
extern void FUN_a01577f4(unsigned char *, unsigned int, unsigned char);
extern void FUN_a00a31a4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *, unsigned int);

void FUN_a00b3708(unsigned int x, unsigned int y, unsigned char v)
{
    unsigned char buf[8];
    unsigned char i;

    FUN_a0146b50(0x6f, 0);
    FUN_a0146b6c(2, 0);
    FUN_a01577f4(buf, 0x1981d0, v);
    for (i = 0; i <= 3; i++)
        if (buf[i] == 0)
            break;
    buf[0] = i - 1;
    FUN_a00a31a4(0, x & 0xff, y & 0xff, 3, buf, 0);
}
