/* FUN_a012adac (leon2m 0xa012adac-0xa012add8, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the byte (a << 3) | (b << 2) | (c << 1) | d. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a012ad80 and FUN_a012add8.
 */
unsigned char FUN_a012adac(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    return (a << 3) | (b << 2) | (c << 1) | d;
}
