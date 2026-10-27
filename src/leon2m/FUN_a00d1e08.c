/* FUN_a00d1e08 (leon2m 0xa00d1e08-0xa00d1e3c, 52 bytes, leaf), flags -mcpu=v8 -O3.
 * Stores 0 to the byte DAT_a802b09d when p[7] is 1, stores 1 when p[7] is 0, leaves it otherwise; returns 0xe0.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a00d1d34 and FUN_a00d1e3c.
 */
extern unsigned char DAT_a802b09d;

unsigned char FUN_a00d1e08(unsigned char *p)
{
    if (p[7] == 1)
        DAT_a802b09d = 0;
    else if (p[7] == 0)
        DAT_a802b09d = 1;
    return 0xe0;
}
