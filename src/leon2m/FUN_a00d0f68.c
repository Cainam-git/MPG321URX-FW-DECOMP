/* FUN_a00d0f68 (leon2m 0xa00d0f68-0xa00d0fa0, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * XORs x with the bytes p[0 .. (p[1] & 0x7f) + 1] and returns the low byte of the result. Nothing in the image
 * refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00d0e48 and FUN_a00d0fa0.
 * Source form: an unsigned int count and an unsigned char loop counter.
 */
unsigned char FUN_a00d0f68(const unsigned char *p, unsigned char x)
{
    unsigned int n = (p[1] & 0x7f) + 2;
    unsigned char i;

    for (i = 0; i < n; i++)
        x ^= p[i];
    return x;
}
