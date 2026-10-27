/* FUN_a0147cac (leon2m 0xa0147cac-0xa0147d0c, 96 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the index of the first zero byte in p[0..0x2c], or 0x2c when there is none. Nothing in the image refers
 * to it: no call, branch, sethi/or constant or address word. It lies between FUN_a0147c94 and FUN_a0147d0c. Source
 * form: the loop sets r = i on a zero byte (break) and on the last index.
 */
unsigned char FUN_a0147cac(const unsigned char *p)
{
    unsigned char i, r = 0;

    for (i = 0; i < 45; i++) {
        if (p[i] == 0) {
            r = i;
            break;
        }
        if (i == 44)
            r = i;
    }
    return r;
}
