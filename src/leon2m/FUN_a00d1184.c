/* FUN_a00d1184 (leon2m 0xa00d1184-0xa00d1220, 156 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Sets p[7] from req[7]: bit 14 of the word DAT_a802d290 (req[7] = 0), the byte DAT_a802d465 (1), DAT_a802d466 (2)
 * or 0xe4 (other); then stores to p[8] the XOR of 0x50 with the (p[1] & 0x7f) + 2 bytes at p (the FUN_a00d0f68
 * checksum). Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a00d1110 and FUN_a00d1220. Source form: an if/else chain on req[7]; the FUN_a00d0f68 checksum is a static
 * helper inlined here.
 */
extern unsigned int DAT_a802d290;
extern unsigned char DAT_a802d465, DAT_a802d466;
static unsigned char csum(const unsigned char *p, unsigned char x)
{
    unsigned int n = (p[1] & 0x7f) + 2;
    unsigned char i;
    for (i = 0; i < n; i++)
        x ^= p[i];
    return x;
}
void FUN_a00d1184(const unsigned char *req, unsigned char *p)
{
    if (req[7] == 0)
        p[7] = (DAT_a802d290 >> 14) & 1;
    else if (req[7] == 1)
        p[7] = DAT_a802d465;
    else if (req[7] == 2)
        p[7] = DAT_a802d466;
    else
        p[7] = 0xe4;
    p[8] = csum(p, 0x50);
}
