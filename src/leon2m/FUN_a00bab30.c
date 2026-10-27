/* FUN_a00bab30 (leon2m 0xa00bab30-0xa00bab80, 80 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns byte b of DAT_a802d040 (a = 2), DAT_a802d098 (a = 3) or DAT_a802d0d0 (any other a). Nothing in the image
 * refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00baa6c and FUN_a00bab80.
 * Source form: an if/else chain assigning an unsigned char result.
 */
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
unsigned char FUN_a00bab30(unsigned char a, unsigned char b)
{
    unsigned char r;
    if (a == 2)
        r = DAT_a802d040[b];
    else if (a == 3)
        r = DAT_a802d098[b];
    else
        r = DAT_a802d0d0[b];
    return r;
}
